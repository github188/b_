/***********************************************************************************

 * �� �� ��   : bfd_state.c
 * �� �� ��   : jiangbo,����
 * ��������   : 2016��10��14��
 * �� �� ��   : 
 * �ļ�����   : BFD״̬��
 * ��Ȩ˵��   : Copyright (C) 2000-2016   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 

***********************************************************************************/

#include "bfd.h"


RESULT_BFDCFG bfd_run_all_state_machine()
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
    {
        ret = bfd_traverse_cfg_database(bfd_run_state_machine_by_cfg_data);
    } while ( 0 ); /* ѭ��ֱ��0������ */

    return ret;
}

RESULT_BFDCFG bfd_run_state_machine_by_cfg_data(IN BFD_CFG_DATABASE* cfg_data)
{
    RESULT_BFDCFG ret = CFG_OK;
    do /* ��ʼѭ�� */
    {
        if (NULL == cfg_data)
        {
            BFD_LOG(BMU_ERR, "cfg_data is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        /* ����FPGA�ɹ� */  //TODO:��BFD_CFG_DATABASE���ݽṹ�洢�˷���ֵ������ĳ��жϷ���ֵ
        if(DRV_USHORT_INVALID != cfg_data->fpga_index)
        {
            ret = bfd_run_state_machine(cfg_data->fpga_index);
        }
    } while ( 0 ); /* ѭ��ֱ��0������ */

    return ret;
}

RESULT_BFDCFG bfd_run_state_machine(IN unsigned short index)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_FPGA_INFO fpga_info;
    BFD_STATE_TRANSFER new_state;
    EN_BFD_RECV_ACTION recv_action = BFD_ACTION_NONE;

    do /* ��ʼѭ�� */
    {
        /* ������� */
        BFD_CHECK_PARAM_MAX(BMU_ERR, index, BFD_MAX_SESNUM, "%u", "%u", ret);

        /* ��ʼ�� */
        OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
        OS_MEMSET(&new_state, 0, sizeof(new_state));

        /* ��ȡFPGA��Ϣ */
        ret = bfd_get_specify_array_info(index, &fpga_info);
        BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_get_specify_array_info, ret);

        /* ��ȡFPGA�Ķ��� */
        ret = bfd_get_fpga_recv_action(index, &(fpga_info.session_info.diag_state), &(fpga_info.send_cfg.state),
            &recv_action);
        BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_get_fpga_recv_action, ret);

        /* ����״̬�� */
        ret = bfd_finite_state_machine_transfer(&(fpga_info.send_cfg.state), recv_action, &new_state);
        BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_finite_state_machine_transfer, ret);

        /* ״̬Ǩ���˲���Ҫ�������ĸı�FPGA�ʹ洢���� */
        if(TRUE == new_state.transfer_flag)
        {
            /* �����澯 */
            ret = bfd_produce_alarm(fpga_info.send_cfg.discr.my_id, &(fpga_info.send_cfg.state),
                &(new_state.state));
            BFD_CHECK_FUNC_RETURN_NO_BREAK(BMU_NOTICE, bfd_produce_alarm, ret);

            /* ��¼״̬Ǩ��ʱ�� */
            ret = bfd_record_state_change_event(fpga_info.send_cfg.discr.my_id, index,
                &(fpga_info.send_cfg.state), recv_action, &(new_state.state));
            BFD_CHECK_FUNC_RETURN_NO_BREAK(BMU_NOTICE, bfd_record_state_change_event, ret);
                        
            /* �޸�FPGA�������� */
            ret = bfd_fsm_modify_fpga(index, &fpga_info, &new_state);
            BFD_CHECK_FUNC_RETURN_NO_BREAK(BMU_NOTICE, bfd_fsm_modify_fpga, ret);
            
            /* �洢��ǰFPGA�Ự״̬ */
            ret = bfd_set_specify_fpga_specify_member_database(index,
                NBB_OFFSETOF(BFD_FPGA_INFO, send_cfg.state),
                &(new_state.state), sizeof(new_state.state));
            BFD_CHECK_FUNC_RETURN_NO_BREAK(BMU_NOTICE, bfd_set_specify_fpga_specify_member_database, ret);
        }
    } while ( 0 ); /* ѭ��ֱ��0������ */

    return ret;
}

RESULT_BFDCFG bfd_finite_state_machine_transfer(IN BFD_STATE *last_state,
    IN EN_BFD_RECV_ACTION recv_action,
    OUT BFD_STATE_TRANSFER *new_state)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
    {
        if (NULL == last_state)
        {
            BFD_LOG(BMU_ERR, "new_state is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        if (NULL == new_state)
        {
            BFD_LOG(BMU_ERR, "new_state is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        if(last_state->state >= BFD_STA_BUTT)
        {
            BFD_LOG(BMU_ERR, "last_state:%u is too big, max is %u\n", last_state->state, BFD_STA_BUTT);
            ret = PARAM_ERROR;
            break;
        }

        if(recv_action > BFD_ACTION_NONE)
        {
            BFD_LOG(BMU_ERR, "recv_action:%u is too big, max is %u\n", recv_action, BFD_ACTION_NONE);
            ret = PARAM_ERROR;
            break;
        }
    
        switch ( last_state->state ) /* �ж�ƥ������last_state->state */
        {
            case BFD_ADMINDOWN :
                
                /* ��ǰΪadmindown���κ�״̬������ */
                new_state->state.diag = last_state->diag;
                new_state->state.state = last_state->state;
                new_state->transfer_flag = FALSE;
                break;
            case BFD_DOWN :
                switch ( recv_action ) /* �ж�ƥ������rev_action */
                {
                    case BFD_ACTION_ADMINDOWN :
                        new_state->state.diag = bfd_diag_admin_down;
                        new_state->state.state = BFD_ADMINDOWN;
                        new_state->transfer_flag = TRUE;
                        break;
                    case BFD_ACTION_DOWN :
                        new_state->state.diag = bfd_diag_no_diag;
                        new_state->state.state = BFD_INIT;
                        new_state->transfer_flag = TRUE;
                        break;
                    case BFD_ACTION_INIT :

                        /* ͬ�յ�BFD UP�������ܰ�RFC��״̬������BFDΪdownʱ���յ�UP����Ҳ��ҪUP����Ϊ˫���ػ����£�
                           ���̺�������ʱ�򣬿��ܳ������������������Ҫ�����̵�״̬��һ�£�������UP״̬ */
                    case BFD_ACTION_UP :
                        new_state->state.diag = bfd_diag_no_diag;
                        new_state->state.state = BFD_UP;
                        new_state->transfer_flag = TRUE;
                        break;
                    case BFD_ACTION_TIME_OUT :

                        /* ������ */
                        new_state->state.diag = last_state->diag;
                        new_state->state.state = last_state->state;
                        new_state->transfer_flag = FALSE;
                        break;
                    default:
                        
                        /* ������ */
                        new_state->state.diag = last_state->diag;
                        new_state->state.state = last_state->state;
                        new_state->transfer_flag = FALSE;
                }
                break;
            case BFD_INIT :
                switch ( recv_action ) /* �ж�ƥ������rev_action */
                {
                    case BFD_ACTION_ADMINDOWN :
                        new_state->state.diag = bfd_diag_admin_down;
                        new_state->state.state = BFD_ADMINDOWN;
                        new_state->transfer_flag = TRUE;
                        break;
                    case BFD_ACTION_DOWN :
                        
                        /* ������ */
                        new_state->state.diag = last_state->diag;
                        new_state->state.state = last_state->state;
                        new_state->transfer_flag = FALSE;
                        break;
                    case BFD_ACTION_INIT :
                    
                        /* ͬ�յ�BFD UP�� */
                    case BFD_ACTION_UP :
                        new_state->state.diag = bfd_diag_no_diag;
                        new_state->state.state = BFD_UP;
                        new_state->transfer_flag = TRUE;
                        break;
                    case BFD_ACTION_TIME_OUT :
                        new_state->state.diag = bfd_diag_ctrl_detect_exp;
                        new_state->state.state = BFD_DOWN;
                        new_state->transfer_flag = TRUE;
                        break;
                    default:
                        
                        /* ������ */
                        new_state->state.diag = last_state->diag;
                        new_state->state.state = last_state->state;
                        new_state->transfer_flag = FALSE;
                }
                break;
            case BFD_UP :
                switch ( recv_action ) /* �ж�ƥ������rev_action */
                {
                    case BFD_ACTION_ADMINDOWN :
                        new_state->state.diag = bfd_diag_admin_down;
                        new_state->state.state = BFD_ADMINDOWN;
                        new_state->transfer_flag = TRUE;
                        break;
                    case BFD_ACTION_DOWN :
                        new_state->state.diag = bfd_diag_nbr_session_down;
                        new_state->state.state = BFD_DOWN;
                        new_state->transfer_flag = TRUE;
                        break;
                    case BFD_ACTION_INIT :
                        
                        /* ͬ�յ�UP���������� */
                    case BFD_ACTION_UP :
                        
                        /* ������ */
                        new_state->state.diag = last_state->diag;
                        new_state->state.state = last_state->state;
                        new_state->transfer_flag = FALSE;
                        break;
                    case BFD_ACTION_TIME_OUT :
                        new_state->state.diag = bfd_diag_ctrl_detect_exp;
                        new_state->state.state = BFD_DOWN;
                        new_state->transfer_flag = TRUE;
                        break;
                    default:
                        
                        /* ������ */
                        new_state->state.diag = last_state->diag;
                        new_state->state.state = last_state->state;
                        new_state->transfer_flag = FALSE;
                }
                break;
            default:
                
                /* ������ */
                new_state->state.diag = last_state->diag;
                new_state->state.state = last_state->state;
                new_state->transfer_flag = FALSE;
                break;
        }

        ret = CFG_OK;
    } while ( 0 ); /* ѭ��ֱ��0������ */

    return ret;
}

RESULT_BFDCFG bfd_fsm_modify_fpga(IN unsigned short index, IN BFD_FPGA_INFO *fpga_info,
    IN BFD_STATE_TRANSFER *new_state)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_INTERVAL interval;

    do /* ��ʼѭ�� */
    {
        if (NULL == fpga_info)
        {
            BFD_LOG(BMU_ERR, "fpga_info is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        if (NULL == new_state)
        {
            BFD_LOG(BMU_ERR, "new_state is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        /* ״̬û���䣬����Ҫ�Ĳ��� */
        if(FALSE == new_state->transfer_flag)
        {
            ret = CFG_OK;
            break;
        }

        OS_MEMSET(&interval, 0, sizeof(interval));

        switch ( new_state->state.state ) /* �ж�ƥ������new_state->state.state */
        {
            case BFD_ADMINDOWN :
                
                /* ͬ down */
            case BFD_DOWN:
                interval.desired_min_tx_interval = BFD_1000MS;      /* down��֮���� */
                interval.required_min_rx_interval = BFD_1000MS;     /* down��֮���� */
                interval.detect_mult = fpga_info->send_cfg.interval.detect_mult;
                ret = bfd_set_fpga_state_interval(index, &(new_state->state), &interval, FALSE);

                /* �ر�FPGA���UP��DOWN�澯���� */
                ret = bfd_set_fpga_session_up_to_down_sta(index, FALSE);

                /* �رշ����� */
                ret = bfd_set_fpga_session_anti_attack(index, fpga_info->send_cfg.discr.peer_id, FALSE);
                break;
            case BFD_INIT :
                interval.desired_min_tx_interval = BFD_1000MS;
                interval.required_min_rx_interval = BFD_1000MS;
                interval.detect_mult = fpga_info->send_cfg.interval.detect_mult;
                ret = bfd_set_fpga_state_interval(index, &(new_state->state), &interval, FALSE);                
                break;
            case BFD_UP :
                interval.desired_min_tx_interval = fpga_info->send_cfg.interval.desired_min_tx_interval;
                interval.required_min_rx_interval = fpga_info->send_cfg.interval.required_min_rx_interval;
                interval.detect_mult = fpga_info->send_cfg.interval.detect_mult;
                ret = bfd_set_fpga_state_interval(index, &(new_state->state), &interval, FALSE);

                /* ��FPGA���UP��DOWN�澯���� */
                ret = bfd_set_fpga_session_up_to_down_sta(index, TRUE);

                /* �򿪷����� */
                ret = bfd_set_fpga_session_anti_attack(index, fpga_info->send_cfg.discr.peer_id, TRUE);
                break;
            default:
                break;
        }
    } while ( 0 ); /* ѭ��ֱ��0������ */

    return ret;
}

RESULT_BFDCFG bfd_get_fpga_recv_action(IN unsigned short index,
    IN BFD_FPGA_REG_DIAG_STATE *last_session_state,
    IN BFD_STATE *last_state,
    OUT EN_BFD_RECV_ACTION *recv_action)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_FPGA_REG_DIAG_STATE current_session_state;
    SPM_BFD_UP_TO_DOWN_STA up_to_down_state;
    
    do /* ��ʼѭ�� */
    {
        /* ������� */
        BFD_CHECK_PARAM_MAX(BMU_ERR, index, BFD_MAX_SESNUM, "%u", "%u", ret);
        BFD_CHECK_PARAM_POINT(BMU_ERR, last_session_state, ret);
        BFD_CHECK_PARAM_POINT(BMU_ERR, last_state, ret);
        BFD_CHECK_PARAM_POINT(BMU_ERR, recv_action, ret);

        OS_MEMSET(&current_session_state, 0, sizeof(current_session_state));
        OS_MEMSET(&up_to_down_state, 0, sizeof(up_to_down_state));
        *recv_action = BFD_ACTION_NONE;     /* ��ʼ��Ϊ״̬���� */

        /* ��ȡ��ǰFPGA�ĻỰ״̬ */
        ret = bfd_get_fpga_session_state(index, &current_session_state);
        BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_get_fpga_session_state, ret);
        
        if(TRUE == current_session_state.timer_alarm)
        {
            *recv_action = BFD_ACTION_TIME_OUT;            
        }
        else
        {
            if (last_session_state->count != current_session_state.count)
            {
                /* �洢�µļ��� */
                ret = bfd_set_specify_fpga_specify_member_database(index,
                    NBB_OFFSETOF(BFD_FPGA_INFO, session_info.diag_state),
                    &current_session_state, sizeof(current_session_state));

                *recv_action = current_session_state.packet_state;
                
                /* UP��down��״̬��FPGA��ⲢֵΪdown,�������ͬ��״̬�����ϱ��澯 */
                if (BFD_UP == last_state->state)
                {
                    ret = bfd_get_fpga_session_up_to_down_sta(index, &up_to_down_state);
                    BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_get_fpga_session_up_to_down_sta, ret);
                    
                    if ((TRUE == up_to_down_state.enable) && (bfd_diag_nbr_session_down == up_to_down_state.dig))
                    {
                        *recv_action = BFD_ACTION_DOWN;
                    }
                }                
            }
            
        }

        ret = CFG_OK;
    } while ( 0 ); /* ѭ��ֱ��0������ */

    return ret;
}
