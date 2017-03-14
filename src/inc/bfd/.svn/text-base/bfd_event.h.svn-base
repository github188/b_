/***********************************************************************************

 * 文 件 名   : bfd_event.h
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年12月14日
 * 版 本 号   : 
 * 文件描述   : bfd_event.c 的头文件
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#ifndef __BFD_EVENT_H__
#define __BFD_EVENT_H__


#ifdef __cplusplus
#if __cplusplus
{
extern "C"
#endif
#endif /* __cplusplus */


/*事件结构体*/
typedef struct bfd_event_info
{
    unsigned long  my_sid;              /* BFD本地描述符 */
    unsigned short fpga_index;          /* FPGA数组下标 */
    BFD_STATE last_state;               /* 上次BFD状态 */
    BFD_STATE current_state;            /* 当前BFD状态 */
    EN_BFD_RECV_ACTION action;          /* 触发状态机运转动作 */
    unsigned short tx_counter;          /* 发包计数 */
    unsigned short rx_counter;          /* 收包计数 */
}BFD_EVENT_INFO;

/* BFD事件记录 */
typedef struct bfd_event_log_info
{
    NBB_LQE list;                   /* 双向循环链表 */
    struct SYSTIME time;            /* 时间，精确到5ms */
    BFD_EVENT_INFO event_info;      /* BFD事件信息 */
}BFD_EVENT_LOG_INFO;

extern RESULT_BFDCFG bfd_analyze_event(IN BFD_EVENT_LOG_INFO *event_log, IN int level);
extern RESULT_BFDCFG bfd_analyze_event_head(IN int level);
extern NBB_BOOL bfd_compare_event_myid(IN BFD_EVENT_LOG_INFO *event_log, IN void* myid);
extern RESULT_BFDCFG bfd_record_state_change_event(IN unsigned long my_sid,
             IN unsigned short fpga_index,
             IN BFD_STATE *last_state,
             IN EN_BFD_RECV_ACTION action,
             IN BFD_STATE *new_state);
extern RESULT_BFDCFG bfd_show_event(IN unsigned int show_num);
extern RESULT_BFDCFG bfd_show_event_by_myid(IN unsigned long my_id, IN unsigned int show_num);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BFD_EVENT_H__ */
