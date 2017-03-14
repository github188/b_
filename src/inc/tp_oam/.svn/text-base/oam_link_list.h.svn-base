/******************************************************************************

	Copyright (C), 2002-2010, Wuhan FiberHome Tech. Co., Ltd.

 ******************************************************************************
  文 件 名   : oam_link_list.h
  版 本 号   : 初稿
  作    者   : 丁浩
  生成日期   : 2015年6月29日
  功能描述   : oam_link_list.c头文件,提供外部调用
  修改历史   :
  1.日    期   : 2015年6月29日
    作    者   : 丁浩   
    修改内容   : 创建文件
                

******************************************************************************/
#ifndef  _OAM_LINK_LIST_H_
#define  _OAM_LINK_LIST_H_

#include "oam_public.h"
#include "bmuInclude.h"

/*OAM配置块内容*/
typedef struct oam_active_cfg_info
{
    OAM_ACTIVE_CFG oam_active_cfg;
    OAM_TRAFFIC_INFO oam_traffic_info;
    OAM_DRV_INFO oam_drv_info;
    TX_LABEL_CFG oam_tx_label_cfg;
    RX_LABEL_CFG oam_rx_label_cfg;
    unsigned short oam_id;
    unsigned short item;
    unsigned short oam_ondemand_id;
    unsigned char create_del_flag;
    unsigned char aps_type; /*线性或环网保护*/
    unsigned int mep_index;/*芯片用于识别创建的mep，芯片本地ID资源概念*/
    unsigned int group_id;/*芯片用于删除group的group_id*/
    unsigned int count_id;
    int entry_oam_id;
    unsigned char oam_create_mode_flag;
    
}__attribute__((packed))OAM_ACTIVE_CFG_INFO;


/*定义链表节点*/
typedef struct oam_cfg_node
{
    OAM_ACTIVE_CFG_INFO oam_active_cfg_info;
    struct oam_cfg_node *oam_cfg_node_next;
}__attribute__((packed))OAM_CFG_NODE;


extern OAM_CFG_NODE *oam_link_list_create(void);
extern OAM_CFG_NODE *oam_link_list_node_search(OAM_CFG_NODE *oam_head_node,unsigned short oam_id);
extern int oam_link_list_node_add(OAM_CFG_NODE *oam_head_node,OAM_CFG_NODE *oam_new_node);
extern int oam_link_list_node_delete(OAM_CFG_NODE *oam_head_node,unsigned short oam_id);
extern int oam_link_list_destroy(OAM_CFG_NODE *oam_head_node);
extern int oam_link_list_len_print(OAM_CFG_NODE *oam_head_node);
extern int oam_link_list_node_print(OAM_CFG_NODE *oam_head_node);

#endif