/***********************************************************************************

 * 文 件 名   : bfd_alarm.c
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年10月14日
 * 版 本 号   : 
 * 文件描述   : BFD告警
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#include "bfd.h"

/*****************************************************************************
 * 函 数 名  : bfd_get_all_alm
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 获取指定BFD MYID的告警信息
 * 输入参数  : unsigned long bfd_id         BFD MYid
 * 输出参数  : BFD_ALM_REPORT* bfd_all_alm  BFD告警信息
 * 返 回 值  : int                          错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
int bfd_get_all_alm(IN unsigned long bfd_id, OUT BFD_ALM_REPORT* bfd_all_alm)
{
    int ret = 0;
    RESULT_BFDCFG result = CFG_OK;
    BFD_ALARM_DATABASE *alarm_data = NULL;
    
    do /* 开始循环 */
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

        /* 初始化为没有告警 */
        OS_MEMSET(bfd_all_alm, 0, sizeof(*bfd_all_alm));

        result = bfd_find_alarm_database(bfd_id, &alarm_data);
        if(CFG_OK != result)
        {
            ret = 0;    /* 没有在告警列表里，可能是第一次配置，没有产生过UP或DOWN的告警，需要返回没有告警的成功消息 */
            break;
        }
        if(alarm_data == NULL)
        {
            ret = 0;    /* 没有在告警列表里，可能是第一次配置，没有产生过UP或DOWN的告警，需要返回没有告警的成功消息 */
            break;
        }

        OS_MEMCPY(bfd_all_alm, &(alarm_data->alarm), sizeof(*bfd_all_alm));
         
        ret = 0;
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}

RESULT_BFDCFG bfd_alarm_transfer(IN BFD_STATE *last_state, IN BFD_STATE *new_state, OUT BFD_ALM_TRANSFER* alm_action)
{
    RESULT_BFDCFG ret = CFG_OK;
    
    do /* 开始循环 */
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

        /* 初始化为没有告警，没有跳变 */
        OS_MEMSET(alm_action, 0, sizeof(*alm_action));
        alm_action->change_flag = FALSE;

        if((BFD_UP == last_state->state) && (BFD_DOWN == new_state->state))
        {
            switch ( new_state->diag ) /* 判断匹配条件new_state->diag */
            {
                case bfd_diag_ctrl_detect_exp :
                    alm_action->alarm.down = 1;         /* 产生BFD down告警 */
                    alm_action->change_flag = TRUE;
                    break;
                case bfd_diag_nbr_session_down :
                    alm_action->alarm.remote_down = 1;  /* 产生BFD远端down告警 */
                    alm_action->change_flag = TRUE;
                    break;
                case bfd_diag_admin_down :
                    
                    /* 不产生告警 */
                    alm_action->change_flag = FALSE;
                    break;
                default:

                    /* 不产生告警 */
                    alm_action->change_flag = FALSE;
            }
        }
        else if((BFD_UP != last_state->state) && (BFD_UP == new_state->state))   /* 所有状态跳变进入UP的，都清空告警 */
        {
            OS_MEMSET(&(alm_action->alarm), 0, sizeof(alm_action->alarm));    /* 清空告警 */
            alm_action->change_flag = TRUE;
        }

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}


RESULT_BFDCFG bfd_produce_alarm(IN unsigned long my_sid, IN BFD_STATE *last_state, IN BFD_STATE *new_state)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_ALM_TRANSFER alarm_action;
    BFD_ALARM_DATABASE *alarm_data = NULL;
    
    do /* 开始循环 */
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
            if(CFG_OK != ret)   /* 添加 */
            {
                ret = bfd_add_alarm_database(my_sid, &(alarm_action.alarm));
            }
            else    /* 修改 */
            {
                ret = bfd_modify_alarm_database(my_sid, &(alarm_action.alarm));
            }
        }
        
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}

