/***********************************************************************************

 * �� �� ��   : bfd_database.h
 * �� �� ��   : jiangbo,����
 * ��������   : 2016��11��3��
 * �� �� ��   : 
 * �ļ�����   : bfd_database.c ��ͷ�ļ�
 * ��Ȩ˵��   : Copyright (C) 2000-2016   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 

***********************************************************************************/

#ifndef __BFD_DATABASE_H__
#define __BFD_DATABASE_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */

typedef struct bfd_array_data
{
    unsigned long key;          /* BFD MYID */
    BFD_FPGA_INFO *fpga_info;
}BFD_ARRAY_DATA;

typedef struct bfd_array
{
    BFD_ARRAY_DATA data[BFD_MAX_SESNUM];
    #if 0   /* �ȶ���һ��Ч�ʵڶ� */
    unsigned short null_index;
    unsigned short max_index;
    #endif
}BFD_ARRAY;

typedef struct bfd_cfg_database
{
    AVLL_NODE cfg_node;
    unsigned long   my_sid;           /* KEYֵ��BFD�ı��������� */
    BFD_CFG  cfg_data;                /* �����·����������� */
    
    unsigned short fpga_index;        /* FPGA�������±� */
    int arad_index;                   /* ARAD�������±� */
    unsigned int tab;                 /*��BFD���ý��б��*/
}BFD_CFG_DATABASE;

typedef struct bfd_alarm_database
{
    AVLL_NODE alarm_node;
    unsigned long my_sid;       /* KEYֵ��BFD�ı��������� */
    BFD_ALM_REPORT alarm;       /* �澯��Ϣ */
}BFD_ALARM_DATABASE;

#define BFD_EVENT_RECORD_MAX_NUM    4096        /* BFD UP/DOWN�¼��洢������������� */
typedef struct bfd_event_database
{
    unsigned long count;    /* �������������� */
    NBB_LQE   event;        /* BFD UP/DOWN�¼���Ϣ */
}BFD_EVENT_DATABASE;

typedef struct bfd_database
{
    BFD_ARRAY fpga_info;        /* FPGA������� */
    AVLL_TREE cfg;              /* ���� */
    AVLL_TREE alarm;            /* �澯��Ϣ */
    BFD_EVENT_DATABASE event;   /* BFD UP/DOWN�¼���Ϣ */
}BFD_DATABASE;

typedef int(*BFD_COMPARE)(void *, void *);
typedef RESULT_BFDCFG(*BFD_TRAVERSE_CFG_CALLBACK)(BFD_CFG_DATABASE*);   /* BFD���ÿ�����Ļص����� */
typedef RESULT_BFDCFG(*BFD_TRAVERSE_ALARM_CALLBACK)(BFD_ALARM_DATABASE*);   /* BFD�澯���ݱ����Ļص����� */
typedef RESULT_BFDCFG(*BFD_TRAVERSE_EVENT_CALLBACK)(BFD_EVENT_LOG_INFO*, int); /* BFD�¼����ݱ����Ļص����� */
typedef NBB_BOOL(*BFD_COMPARE_EVENT_CALLBACK)(BFD_EVENT_LOG_INFO*, void*);  /* BFD�¼����ݱȽϵĻص����� */

extern RESULT_BFDCFG bfd_add_alarm_database(IN unsigned long my_sid, IN BFD_ALM_REPORT *alarm);
extern RESULT_BFDCFG bfd_add_cfg_database(IN unsigned long my_sid,
             IN BFD_CFG *cfg,
             IN unsigned short fpga_index,
             IN int arad_index);
extern RESULT_BFDCFG bfd_add_fpga_database(IN BFD_FPGA_INFO *info, OUT unsigned short *add_index);
extern RESULT_BFDCFG bfd_add_specify_fpga_database(IN unsigned short index, IN BFD_FPGA_INFO *info);
extern unsigned long bfd_compare_fpga_database(IN unsigned long key, IN unsigned long node_key);
extern int bfd_compare_ulong(void *aa, void *bb);
extern RESULT_BFDCFG bfd_del_alarm_database(IN unsigned long my_sid);
extern RESULT_BFDCFG bfd_del_cfg_database(IN unsigned long my_sid);
extern RESULT_BFDCFG bfd_del_fpga_database(IN unsigned long key);
extern RESULT_BFDCFG bfd_del_specify_fpga_database(IN unsigned short index);
extern RESULT_BFDCFG bfd_find_alarm_database(IN unsigned long my_sid, OUT BFD_ALARM_DATABASE * *data);
extern RESULT_BFDCFG bfd_find_array(IN unsigned long key, OUT unsigned short *index);
extern RESULT_BFDCFG bfd_find_cfg_database(IN unsigned long my_sid, OUT BFD_CFG_DATABASE * *data);
extern RESULT_BFDCFG bfd_get_array_info(IN unsigned long key, OUT BFD_FPGA_INFO *fpga_info);
extern RESULT_BFDCFG bfd_get_fisrt_event_database(OUT BFD_EVENT_LOG_INFO **event_log);
extern RESULT_BFDCFG bfd_get_null_array_index(OUT unsigned short *index);
extern RESULT_BFDCFG bfd_get_specify_array_info(IN unsigned short index, OUT BFD_FPGA_INFO *fpga_info);
extern RESULT_BFDCFG bfd_get_specify_fpga_database_key(IN unsigned short index, OUT unsigned long *key);
extern RESULT_BFDCFG bfd_init_alarm_database();
extern RESULT_BFDCFG bfd_init_cfg_database();
extern RESULT_BFDCFG bfd_init_database();
extern RESULT_BFDCFG bfd_init_event_database();
extern RESULT_BFDCFG bfd_insert_array(IN unsigned long key, OUT unsigned short *index);
extern RESULT_BFDCFG bfd_insert_event_database(IN BFD_EVENT_LOG_INFO *event_log);
extern RESULT_BFDCFG bfd_insert_specify_array(IN unsigned short index, IN unsigned long key);
extern NBB_BOOL bfd_is_event_full_database();
extern RESULT_BFDCFG bfd_modify_alarm_database(IN unsigned long my_sid, IN BFD_ALM_REPORT *alarm);
extern RESULT_BFDCFG bfd_modify_cfg_database(IN unsigned long my_sid,
             IN BFD_CFG *cfg,
             IN unsigned short fpga_index,
             IN int arad_index);
extern RESULT_BFDCFG bfd_remove_event_database(IN BFD_EVENT_LOG_INFO *event_log);
extern RESULT_BFDCFG bfd_set_specify_fpga_database(IN unsigned short index, IN BFD_FPGA_INFO *info);
extern RESULT_BFDCFG bfd_set_specify_fpga_specify_member_database(IN unsigned short index,
             IN unsigned long offset,
             IN void *data,
             IN unsigned long data_length);
extern RESULT_BFDCFG bfd_traverse_alarm_database(BFD_TRAVERSE_ALARM_CALLBACK func);
extern RESULT_BFDCFG bfd_traverse_cfg_database(BFD_TRAVERSE_CFG_CALLBACK func);
extern RESULT_BFDCFG bfd_traverse_event_database(IN BFD_TRAVERSE_EVENT_CALLBACK func,
             IN BFD_COMPARE_EVENT_CALLBACK compare_func, IN void* compare_data, IN unsigned int limit_num, IN int level);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BFD_DATABASE_H__ */
