/***********************************************************************************

 * �� �� ��   : bfd_alarm.c
 * �� �� ��   : jiangbo,����
 * ��������   : 2016��10��14��
 * �� �� ��   : 
 * �ļ�����   : BFD�澯
 * ��Ȩ˵��   : Copyright (C) 2000-2016   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 

***********************************************************************************/

#include "bfd.h"

/*****************************************************************************
 * �� �� ��  : bfd_get_all_alm
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ȡָ��BFD MYID�ĸ澯��Ϣ
 * �������  : unsigned long bfd_id         BFD MYid
 * �������  : BFD_ALM_REPORT* bfd_all_alm  BFD�澯��Ϣ
 * �� �� ֵ  : int                          ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
int bfd_get_all_alm(IN unsigned long bfd_id, OUT BFD_ALM_REPORT* bfd_all_alm)
{
    int ret = 0;
    RESULT_BFDCFG result = CFG_OK;
    BFD_ALARM_DATABASE *alarm_data = NULL;
    
    do /* ��ʼѭ�� */
    {
        if(bfd_id > BFD_MAX_ALL_SESNUM)
        {
            BFD_LOG(BMU_ERR, "bfd_id:%lu is too big\n", bfd_id);
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == bfd_all_alm)
        {
            BFD_LOG(BMU_ERR, "bfd_all_alm is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        /* ��ʼ��Ϊû�и澯 */
        OS_MEMSET(bfd_all_alm, 0, sizeof(*bfd_all_alm));

        result = bfd_find_alarm_database(bfd_id, &alarm_data);
        if(CFG_OK != result)
        {
            ret = 0;    /* û���ڸ澯�б�������ǵ�һ�����ã�û�в�����UP��DOWN�ĸ澯����Ҫ����û�и澯�ĳɹ���Ϣ */
            break;
        }
        if(alarm_data == NULL)
        {
            ret = 0;    /* û���ڸ澯�б�������ǵ�һ�����ã�û�в�����UP��DOWN�ĸ澯����Ҫ����û�и澯�ĳɹ���Ϣ */
            break;
        }

        OS_MEMCPY(bfd_all_alm, &(alarm_data->alarm), sizeof(*bfd_all_alm));
         
        ret = 0;
    } while ( 0 ); /* ѭ��ֱ��0������ */

    return ret;
}

RESULT_BFDCFG bfd_alarm_transfer(IN BFD_STATE *last_state, IN BFD_STATE *new_state, OUT BFD_ALM_TRANSFER* alm_action)
{
    RESULT_BFDCFG ret = CFG_OK;
    
    do /* ��ʼѭ�� */
    {        
        if(NULL == last_state)
        {
            BFD_LOG(BMU_ERR, "last_state is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == new_state)
        {
            BFD_LOG(BMU_ERR, "new_state is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == alm_action)
        {
            BFD_LOG(BMU_ERR, "alm_action is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        /* ��ʼ��Ϊû�и澯��û������ */
        OS_MEMSET(alm_action, 0, sizeof(*alm_action));
        alm_action->change_flag = FALSE;

        if((BFD_UP == last_state->state) && (BFD_DOWN == new_state->state))
        {
            switch ( new_state->diag ) /* �ж�ƥ������new_state->diag */
            {
                case bfd_diag_ctrl_detect_exp :
                    alm_action->alarm.down = 1;         /* ����BFD down�澯 */
                    alm_action->change_flag = TRUE;
                    break;
                case bfd_diag_nbr_session_down :
                    alm_action->alarm.remote_down = 1;  /* ����BFDԶ��down�澯 */
                    alm_action->change_flag = TRUE;
                    break;
                case bfd_diag_admin_down :
                    
                    /* �������澯 */
                    alm_action->change_flag = FALSE;
                    break;
                default:

                    /* �������澯 */
                    alm_action->change_flag = FALSE;
            }
        }
        else if((BFD_UP != last_state->state) && (BFD_UP == new_state->state))   /* ����״̬�������UP�ģ�����ո澯 */
        {
            OS_MEMSET(&(alm_action->alarm), 0, sizeof(alm_action->alarm));    /* ��ո澯 */
            alm_action->change_flag = TRUE;
        }

        ret = CFG_OK;
    } while ( 0 ); /* ѭ��ֱ��0������ */

    return ret;
}


RESULT_BFDCFG bfd_produce_alarm(IN unsigned long my_sid, IN BFD_STATE *last_state, IN BFD_STATE *new_state)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_ALM_TRANSFER alarm_action;
    BFD_ALARM_DATABASE *alarm_data = NULL;
    
    do /* ��ʼѭ�� */
    {        
        if(NULL == last_state)
        {
            BFD_LOG(BMU_ERR, "last_state is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == new_state)
        {
            BFD_LOG(BMU_ERR, "new_state is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        OS_MEMSET(&alarm_action, 0, sizeof(alarm_action));

        ret = bfd_alarm_transfer(last_state, new_state, &alarm_action);

        if(TRUE == alarm_action.change_flag)
        {
            ret = bfd_find_alarm_database(my_sid, &alarm_data);
            if(CFG_OK != ret)   /* ��� */
            {
                ret = bfd_add_alarm_database(my_sid, &(alarm_action.alarm));
            }
            else    /* �޸� */
            {
                ret = bfd_modify_alarm_database(my_sid, &(alarm_action.alarm));
            }
        }
        
    } while ( 0 ); /* ѭ��ֱ��0������ */

    return ret;
}

