/***********************************************************************************

 * 文 件 名   : bfd_database.h
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年11月3日
 * 版 本 号   : 
 * 文件描述   : bfd_database.c 的头文件
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

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
    #if 0   /* 稳定第一，效率第二 */
    unsigned short null_index;
    unsigned short max_index;
    #endif
}BFD_ARRAY;

typedef struct bfd_cfg_database
{
    AVLL_NODE cfg_node;
    unsigned long   my_sid;           /* KEY值，BFD的本地描述符 */
    BFD_CFG  cfg_data;                /* 主控下发的配置数据 */
    
    unsigned short fpga_index;        /* FPGA的数组下标 */
    int arad_index;                   /* ARAD的数组下标 */
    unsigned int tab;                 /*对BFD配置进行标记*/
}BFD_CFG_DATABASE;

typedef struct bfd_alarm_database
{
    AVLL_NODE alarm_node;
    unsigned long my_sid;       /* KEY值，BFD的本地描述符 */
    BFD_ALM_REPORT alarm;       /* 告警信息 */
}BFD_ALARM_DATABASE;

#define BFD_EVENT_RECORD_MAX_NUM    4096        /* BFD UP/DOWN事件存储的最大数量限制 */
typedef struct bfd_event_database
{
    unsigned long count;    /* 链表中数据数量 */
    NBB_LQE   event;        /* BFD UP/DOWN事件信息 */
}BFD_EVENT_DATABASE;

typedef struct bfd_database
{
    BFD_ARRAY fpga_info;        /* FPGA相关数据 */
    AVLL_TREE cfg;              /* 配置 */
    AVLL_TREE alarm;            /* 告警信息 */
    BFD_EVENT_DATABASE event;   /* BFD UP/DOWN事件信息 */
}BFD_DATABASE;

typedef int(*BFD_COMPARE)(void *, void *);
typedef RESULT_BFDCFG(*BFD_TRAVERSE_CFG_CALLBACK)(BFD_CFG_DATABASE*);   /* BFD配置块遍历的回调函数 */
typedef RESULT_BFDCFG(*BFD_TRAVERSE_ALARM_CALLBACK)(BFD_ALARM_DATABASE*);   /* BFD告警数据遍历的回调函数 */
typedef RESULT_BFDCFG(*BFD_TRAVERSE_EVENT_CALLBACK)(BFD_EVENT_LOG_INFO*, int); /* BFD事件数据遍历的回调函数 */
typedef NBB_BOOL(*BFD_COMPARE_EVENT_CALLBACK)(BFD_EVENT_LOG_INFO*, void*);  /* BFD事件数据比较的回调函数 */

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
