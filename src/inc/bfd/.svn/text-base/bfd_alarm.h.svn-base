/***********************************************************************************

 * 文 件 名   : bfd_alarm.h
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年11月7日
 * 版 本 号   : 
 * 文件描述   : bfd_alarm.c 的头文件
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#ifndef __BFD_ALARM_H__
#define __BFD_ALARM_H__


#ifdef __cplusplus
#if __cplusplus
{
extern "C"
#endif
#endif /* __cplusplus */

/* BFD告警信息 */
typedef struct bfd_alm_report
{
    unsigned char down;          /* BFD本地DOWN */
    unsigned char remote_down;   /* BFD远端DOWN */
}BFD_ALM_REPORT;

typedef struct bfd_alm_transfer
{
    NBB_BOOL change_flag;    /* 告警产生结束标记，有跳变赋值为TRUE，否则为FALSE */
    BFD_ALM_REPORT alarm;
}BFD_ALM_TRANSFER;


extern RESULT_BFDCFG bfd_alarm_transfer(IN BFD_STATE *last_state, IN BFD_STATE *new_state, OUT BFD_ALM_TRANSFER* alm_action);
extern int bfd_get_all_alm(IN unsigned long bfd_id, OUT BFD_ALM_REPORT* bfd_all_alm);
extern RESULT_BFDCFG bfd_produce_alarm(IN unsigned long my_sid, IN BFD_STATE *last_state, IN BFD_STATE *new_state);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BFD_ALARM_H__ */
