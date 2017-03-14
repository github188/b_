/***********************************************************************************

 * 文 件 名   : bfd_state.c
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年10月14日
 * 版 本 号   : 
 * 文件描述   : BFD状态机
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#include "bfd.h"


RESULT_BFDCFG bfd_run_all_state_machine()
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        ret = bfd_traverse_cfg_database(bfd_run_state_machine_by_cfg_data);
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}

RESULT_BFDCFG bfd_run_state_machine_by_cfg_data(IN BFD_CFG_DATABASE* cfg_data)
{
    RESULT_BFDCFG ret = CFG_OK;
    do /* 开始循环 */
    {
        if (NULL == cfg_data)
        {
            BFD_LOG(BMU_ERR, "cfg_data is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        /* 配置FPGA成功 */  //TODO:当BFD_CFG_DATABASE数据结构存储了返回值，这里改成判断返回值
        if(DRV_USHORT_INVALID != cfg_data->fpga_index)
        {
            ret = bfd_run_state_machine(cfg_data->fpga_index);
        }
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}

RESULT_BFDCFG bfd_run_state_machine(IN unsigned short index)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_FPGA_INFO fpga_info;
    BFD_STATE_TRANSFER new_state;
    EN_BFD_RECV_ACTION recv_action = BFD_ACTION_NONE;

    do /* 开始循环 */
    {
        /* 参数检查 */
        BFD_CHECK_PARAM_MAX(BMU_ERR, index, BFD_MAX_SESNUM, "%u", "%u", ret);

        /* 初始化 */
        OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
        OS_MEMSET(&new_state, 0, sizeof(new_state));

        /* 获取FPGA信息 */
        ret = bfd_get_specify_array_info(index, &fpga_info);
        BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_get_specify_array_info, ret);

        /* 获取FPGA的动作 */
        ret = bfd_get_fpga_recv_action(index, &(fpga_info.session_info.diag_state), &(fpga_info.send_cfg.state),
            &recv_action);
        BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_get_fpga_recv_action, ret);

        /* 运行状态机 */
        ret = bfd_finite_state_machine_transfer(&(fpga_info.send_cfg.state), recv_action, &new_state);
        BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_finite_state_machine_transfer, ret);

        /* 状态迁移了才需要做后续的改变FPGA和存储操作 */
        if(TRUE == new_state.transfer_flag)
        {
            /* 产生告警 */
            ret = bfd_produce_alarm(fpga_info.send_cfg.discr.my_id, &(fpga_info.send_cfg.state),
                &(new_state.state));
            BFD_CHECK_FUNC_RETURN_NO_BREAK(BMU_NOTICE, bfd_produce_alarm, ret);

            /* 记录状态迁移时间 */
            ret = bfd_record_state_change_event(fpga_info.send_cfg.discr.my_id, index,
                &(fpga_info.send_cfg.state), recv_action, &(new_state.state));
            BFD_CHECK_FUNC_RETURN_NO_BREAK(BMU_NOTICE, bfd_record_state_change_event, ret);
                        
            /* 修改FPGA发包参数 */
            ret = bfd_fsm_modify_fpga(index, &fpga_info, &new_state);
            BFD_CHECK_FUNC_RETURN_NO_BREAK(BMU_NOTICE, bfd_fsm_modify_fpga, ret);
            
            /* 存储当前FPGA会话状态 */
            ret = bfd_set_specify_fpga_specify_member_database(index,
                NBB_OFFSETOF(BFD_FPGA_INFO, send_cfg.state),
                &(new_state.state), sizeof(new_state.state));
            BFD_CHECK_FUNC_RETURN_NO_BREAK(BMU_NOTICE, bfd_set_specify_fpga_specify_member_database, ret);
        }
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}

RESULT_BFDCFG bfd_finite_state_machine_transfer(IN BFD_STATE *last_state,
    IN EN_BFD_RECV_ACTION recv_action,
    OUT BFD_STATE_TRANSFER *new_state)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
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
    
        switch ( last_state->state ) /* 判断匹配条件last_state->state */
        {
            case BFD_ADMINDOWN :
                
                /* 当前为admindown，任何状态不处理 */
                new_state->state.diag = last_state->diag;
                new_state->state.state = last_state->state;
                new_state->transfer_flag = FALSE;
                break;
            case BFD_DOWN :
                switch ( recv_action ) /* 判断匹配条件rev_action */
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

                        /* 同收到BFD UP包，不能按RFC的状态机，当BFD为down时，收到UP包，也需要UP，因为双主控环境下，
                           备盘后启动的时候，可能出现这种情况，备盘需要和主盘的状态机一致，都处于UP状态 */
                    case BFD_ACTION_UP :
                        new_state->state.diag = bfd_diag_no_diag;
                        new_state->state.state = BFD_UP;
                        new_state->transfer_flag = TRUE;
                        break;
                    case BFD_ACTION_TIME_OUT :

                        /* 不处理 */
                        new_state->state.diag = last_state->diag;
                        new_state->state.state = last_state->state;
                        new_state->transfer_flag = FALSE;
                        break;
                    default:
                        
                        /* 不处理 */
                        new_state->state.diag = last_state->diag;
                        new_state->state.state = last_state->state;
                        new_state->transfer_flag = FALSE;
                }
                break;
            case BFD_INIT :
                switch ( recv_action ) /* 判断匹配条件rev_action */
                {
                    case BFD_ACTION_ADMINDOWN :
                        new_state->state.diag = bfd_diag_admin_down;
                        new_state->state.state = BFD_ADMINDOWN;
                        new_state->transfer_flag = TRUE;
                        break;
                    case BFD_ACTION_DOWN :
                        
                        /* 不处理 */
                        new_state->state.diag = last_state->diag;
                        new_state->state.state = last_state->state;
                        new_state->transfer_flag = FALSE;
                        break;
                    case BFD_ACTION_INIT :
                    
                        /* 同收到BFD UP包 */
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
                        
                        /* 不处理 */
                        new_state->state.diag = last_state->diag;
                        new_state->state.state = last_state->state;
                        new_state->transfer_flag = FALSE;
                }
                break;
            case BFD_UP :
                switch ( recv_action ) /* 判断匹配条件rev_action */
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
                        
                        /* 同收到UP包，不处理 */
                    case BFD_ACTION_UP :
                        
                        /* 不处理 */
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
                        
                        /* 不处理 */
                        new_state->state.diag = last_state->diag;
                        new_state->state.state = last_state->state;
                        new_state->transfer_flag = FALSE;
                }
                break;
            default:
                
                /* 不处理 */
                new_state->state.diag = last_state->diag;
                new_state->state.state = last_state->state;
                new_state->transfer_flag = FALSE;
                break;
        }

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}

RESULT_BFDCFG bfd_fsm_modify_fpga(IN unsigned short index, IN BFD_FPGA_INFO *fpga_info,
    IN BFD_STATE_TRANSFER *new_state)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_INTERVAL interval;

    do /* 开始循环 */
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

        /* 状态没跳变，不需要改参数 */
        if(FALSE == new_state->transfer_flag)
        {
            ret = CFG_OK;
            break;
        }

        OS_MEMSET(&interval, 0, sizeof(interval));

        switch ( new_state->state.state ) /* 判断匹配条件new_state->state.state */
        {
            case BFD_ADMINDOWN :
                
                /* 同 down */
            case BFD_DOWN:
                interval.desired_min_tx_interval = BFD_1000MS;      /* down了之后降速 */
                interval.required_min_rx_interval = BFD_1000MS;     /* down了之后降速 */
                interval.detect_mult = fpga_info->send_cfg.interval.detect_mult;
                ret = bfd_set_fpga_state_interval(index, &(new_state->state), &interval, FALSE);

                /* 关闭FPGA检查UP到DOWN告警开关 */
                ret = bfd_set_fpga_session_up_to_down_sta(index, FALSE);

                /* 关闭防攻击 */
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

                /* 打开FPGA检查UP到DOWN告警开关 */
                ret = bfd_set_fpga_session_up_to_down_sta(index, TRUE);

                /* 打开防攻击 */
                ret = bfd_set_fpga_session_anti_attack(index, fpga_info->send_cfg.discr.peer_id, TRUE);
                break;
            default:
                break;
        }
    } while ( 0 ); /* 循环直到0不成立 */

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
    
    do /* 开始循环 */
    {
        /* 参数检查 */
        BFD_CHECK_PARAM_MAX(BMU_ERR, index, BFD_MAX_SESNUM, "%u", "%u", ret);
        BFD_CHECK_PARAM_POINT(BMU_ERR, last_session_state, ret);
        BFD_CHECK_PARAM_POINT(BMU_ERR, last_state, ret);
        BFD_CHECK_PARAM_POINT(BMU_ERR, recv_action, ret);

        OS_MEMSET(&current_session_state, 0, sizeof(current_session_state));
        OS_MEMSET(&up_to_down_state, 0, sizeof(up_to_down_state));
        *recv_action = BFD_ACTION_NONE;     /* 初始化为状态不变 */

        /* 获取当前FPGA的会话状态 */
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
                /* 存储新的计数 */
                ret = bfd_set_specify_fpga_specify_member_database(index,
                    NBB_OFFSETOF(BFD_FPGA_INFO, session_info.diag_state),
                    &current_session_state, sizeof(current_session_state));

                *recv_action = current_session_state.packet_state;
                
                /* UP到down的状态由FPGA检测并值为down,软件仅需同步状态机并上报告警 */
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
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}
