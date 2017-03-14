/***********************************************************************************

 * 文 件 名   : bfd_event.c
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年12月14日
 * 版 本 号   : 
 * 文件描述   : BFD通用代码
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#include "bfd.h"

RESULT_BFDCFG bfd_record_state_change_event(IN unsigned long my_sid,
    IN unsigned short fpga_index,
    IN BFD_STATE *last_state,
    IN EN_BFD_RECV_ACTION action,
    IN BFD_STATE *new_state)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_EVENT_LOG_INFO *bfd_event = NULL;

    do /* 开始循环 */
    {
        /* 参数检查 */
        BFD_CHECK_PARAM_MAX(BMU_ERR, fpga_index, BFD_MAX_SESNUM, "%u", "%u", ret);
        BFD_CHECK_PARAM_POINT(BMU_ERR, last_state, ret);
        BFD_CHECK_PARAM_POINT(BMU_ERR, new_state, ret);

        if(!bfd_is_event_full_database())
        {
            /* 分配内存 */
            bfd_event = (BFD_EVENT_LOG_INFO*)calloc(1, sizeof(BFD_EVENT_LOG_INFO));
            BFD_CHECK_NULL_FUNC_NO_BREAK(BMU_NOTICE, calloc, bfd_event);

            if(NULL == bfd_event)   /* 内存分配不成功则修改第一条数据 */
            {
                /* 获取第一条数据 */
                ret = bfd_get_fisrt_event_database(&bfd_event);
                BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_get_fisrt_event_database, ret);
                BFD_CHECK_NULL_FUNC_BREAK(BMU_WARNING, bfd_get_fisrt_event_database, bfd_event, ret);
                
                /* 从双向链表中摘除，后续再重新插回到最后一条 */
                ret = bfd_remove_event_database(bfd_event);
                BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_remove_event_database, ret);
            }
        }
        else
        {
            /* 获取第一条数据 */
            ret = bfd_get_fisrt_event_database(&bfd_event);
            BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_get_fisrt_event_database, ret);
            BFD_CHECK_NULL_FUNC_BREAK(BMU_WARNING, bfd_get_fisrt_event_database, bfd_event, ret);
            
            /* 从双向链表中摘除，后续再重新插回到最后一条 */
            ret = bfd_remove_event_database(bfd_event);
            BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_remove_event_database, ret);
        }


        /* 获取系统时间 */
        GetSysClock(&(bfd_event->time));

        /* 获取BFD发包计数 */
        bfd_get_fpga_send_count(fpga_index, &(bfd_event->event_info.tx_counter));
        
        /* 获取BFD收包计数 */
        bfd_get_fpga_session_recv_count(fpga_index, &(bfd_event->event_info.rx_counter));

        /* 赋值上次状态、当前状态、触发动作等 */
        OS_MEMCPY(&(bfd_event->event_info.last_state), last_state, sizeof(bfd_event->event_info.last_state));
        OS_MEMCPY(&(bfd_event->event_info.current_state), new_state, sizeof((bfd_event->event_info.current_state)));
        bfd_event->event_info.action = action;
        bfd_event->event_info.my_sid = my_sid;
        bfd_event->event_info.fpga_index = fpga_index;

        /* 插入双向链表 */
        bfd_insert_event_database(bfd_event);            
        BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_insert_event_database, ret);

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */

    if(NULL == bfd_event)
    {
        free(bfd_event);
    }

    return ret;
}

RESULT_BFDCFG bfd_analyze_event_head(IN int level)
{
    BFD_LOG(level, "-----------+-----+-------------------------------------------+---------------+"
        "-----------------------\n");
    BFD_LOG(level, "           |     |           State transfer process          |     Packet    |"
        "           time        \n");
    BFD_LOG(level, "   MyDrim  |Index|-------------------------------------------+---------------+"
        "-----------------------\n");
    BFD_LOG(level, "           |     | LastState--( action )-->CurretState| diag |  Send |  Recv |"
        " yy-mm-dd hh:mm:ss.ms  \n");   
    BFD_LOG(level, "-----------+-----+------------(________)-->-----------+------+-------+-------+"
        "-----------------------\n");

    return CFG_OK;
}

RESULT_BFDCFG bfd_analyze_event(IN BFD_EVENT_LOG_INFO *event_log, IN int level)
{
    RESULT_BFDCFG ret = CFG_OK;
    
    do
    {
        BFD_CHECK_PARAM_POINT(BMU_ERR, event_log, ret);
        BFD_CHECK_PARAM_OPEN_MAX(BMU_ERR, event_log->event_info.last_state.state, BFD_STA_BUTT, "%u", "%u", ret);
        BFD_CHECK_PARAM_OPEN_MAX(BMU_ERR, event_log->event_info.current_state.state, BFD_STA_BUTT, "%u", "%u", ret);
        
        BFD_LOG(level, "%*lu |%*u|%*s--(%*s )-->%-*s |%*u |%*u |%*u |%u-%u-%u %u:%u:%u.%u\n",
            BFD_PRT_BFD_ID_LEN, event_log->event_info.my_sid,
            BFD_PRT_FPGA_INDEX_LEN, event_log->event_info.fpga_index,
            BFD_PRT_STATE_LEN, g_bfd_state_str[event_log->event_info.last_state.state],
            BFD_PRT_ACTION_LEN, g_bfd_action_str[event_log->event_info.action],
            BFD_PRT_STATE_LEN, g_bfd_state_str[event_log->event_info.current_state.state],
            BFD_PRT_DIAG_LEN, event_log->event_info.current_state.diag,
            BFD_PRT_PKT_COUNT, event_log->event_info.tx_counter,
            BFD_PRT_PKT_COUNT, event_log->event_info.rx_counter,
            event_log->time.usYear, event_log->time.ucMonth,event_log->time.ucDate,
            event_log->time.ucHour, event_log->time.ucMinute, event_log->time.ucSecond, event_log->time.us5Ms * 5);

        ret = CFG_OK;
    }while(0);

    return ret;
}

NBB_BOOL bfd_compare_event_myid(IN BFD_EVENT_LOG_INFO *event_log, IN void* myid)
{
    NBB_BOOL ret = FALSE;
    
    do
    {
        BFD_CHECK_PARAM_POINT(BMU_ERR, event_log, ret);
        BFD_CHECK_PARAM_POINT(BMU_ERR, myid, ret);

        if(event_log->event_info.my_sid == *(unsigned long*)myid)
        {
            ret = TRUE;
        }
        else
        {
            ret = FALSE;
        }
    }while(0);

    return ret;
}


RESULT_BFDCFG bfd_show_event(IN unsigned int show_num)
{
    RESULT_BFDCFG ret = CFG_OK;
    
    ret = bfd_analyze_event_head(BFD_SHELL_INFO);

    ret = bfd_traverse_event_database(bfd_analyze_event, NULL, NULL, show_num, BFD_SHELL_INFO);

    return ret;
}

RESULT_BFDCFG bfd_show_event_by_myid(IN unsigned long my_id, IN unsigned int show_num)
{
    RESULT_BFDCFG ret = CFG_OK;

    ret = bfd_analyze_event_head(BFD_SHELL_INFO);
    ret = bfd_traverse_event_database(bfd_analyze_event, bfd_compare_event_myid, &my_id, show_num, BFD_SHELL_INFO);
    
    return ret;
}

