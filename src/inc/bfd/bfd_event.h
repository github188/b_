/***********************************************************************************

 * �� �� ��   : bfd_event.h
 * �� �� ��   : jiangbo,����
 * ��������   : 2016��12��14��
 * �� �� ��   : 
 * �ļ�����   : bfd_event.c ��ͷ�ļ�
 * ��Ȩ˵��   : Copyright (C) 2000-2016   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 

***********************************************************************************/

#ifndef __BFD_EVENT_H__
#define __BFD_EVENT_H__


#ifdef __cplusplus
#if __cplusplus
{
extern "C"
#endif
#endif /* __cplusplus */


/*�¼��ṹ��*/
typedef struct bfd_event_info
{
    unsigned long  my_sid;              /* BFD���������� */
    unsigned short fpga_index;          /* FPGA�����±� */
    BFD_STATE last_state;               /* �ϴ�BFD״̬ */
    BFD_STATE current_state;            /* ��ǰBFD״̬ */
    EN_BFD_RECV_ACTION action;          /* ����״̬����ת���� */
    unsigned short tx_counter;          /* �������� */
    unsigned short rx_counter;          /* �հ����� */
}BFD_EVENT_INFO;

/* BFD�¼���¼ */
typedef struct bfd_event_log_info
{
    NBB_LQE list;                   /* ˫��ѭ������ */
    struct SYSTIME time;            /* ʱ�䣬��ȷ��5ms */
    BFD_EVENT_INFO event_info;      /* BFD�¼���Ϣ */
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
