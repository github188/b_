/******************************************************************************

 * Copyright (C),2015														*

 * WuHan Fiberhome Technologies Co.,Ltd										*

 * All right reserved.                                                      *

 * File name	: tp_cfg.h													*

 * Author		: zhangyh													*

 * Version      : V0.1														*

 * Create Date : 2015.6.30													*

 * Description :  0.处理配置数据的接口                                      *
                  1.定义对外接口数据结构
 *                2.声明对外接口函数				                                        *

 *******************************************************************************/
#ifndef _TP_CFG
#define _TP_CFG

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "bmuV2lib.h"

//#include "bmuOsComm.h"
//#include "bmuType.h"

#include "bmuOsHdrs.h"

#define PORT_MAX 32
#define ENTRY_NUM_8K_TPCFG         8192

typedef unsigned long U32;
typedef unsigned short U16;
typedef unsigned char U8;

//BMU_BIN_SEM_ID	SEM_ID;

//typedef SEM_ID BMU_MUTEX_ID;

/*********************
   ptn业务使用的配置块如下：
   1、 PTN物理端口配置
   3、 PTN点到点业务虚拟接口ID配置
   4、 VPLS业务虚拟接口ID配置
   6、 虚拟子接口映射
   8、 VPWS (此配置只有在LSP条目存在时才处理)
   9、 VPLS
   10、TE-LSP(RX)（此配置先于VPWS、VPLS下发）
   11、TE-LSP(TX，) 【此配置先于VPWS、VPLS下发】

 ********************/
#pragma pack (1)

/********************
   PTN 物理端口配置
********************/

//基本配置 al
typedef struct port_base_conf_t
{
    unsigned char port_en_mode;   /*bit0:端口开关,  bit1:工作模式,  bit2:接入模式,  bit3:MPLS转发使能,bit7:MCC开关*/
    unsigned short mtu;                        /*MTU*/
    unsigned short tpid;                   /*外层TPID*/
    unsigned short pvid;                   /*端口PVID*/
    unsigned char port_priority;  /*端口优先级*/
    unsigned char flow_ctrl;      /*802.3流控：0/1=不使能/使能（不显示）*/
    unsigned char local_mac[6];   /*本端MAC地址*/
    unsigned char tag_rule;     /*	字节16：tag输出规则=0/1=untagged/tagged*/
    unsigned short tag_type;                /*字节17-字节18：tagtype=0/1=0x8100/0x88a8;*/
    unsigned char res[3];           /*字节19-21：备用	*/
    unsigned char port_rate;
    unsigned char port_mode;
    unsigned char relation_set;
    unsigned char port_type; /*字节25：端口类型：0/1=光接口/电接口*/
    unsigned char port_tpmode; /*字节26：端口TP模式：0/1=否/是（TP模式，关闭MAC检查）(网管不显示)*/
    unsigned char res2[7]; /*字节27-：33：备用*/

} PORT_BASE_CONF;    /*基本配置*/

/*
   高级配置
 */
typedef struct port_advanced_conf_t
{
    unsigned char inport_dscp_map_preference;     /*入口DSCP映射优先*/
    unsigned char export_phb28021p_dscp;                      /*出口PHB到802.1P/DSCP映射*/
    unsigned char export_acl_enable;                          /*出口ACL使能*/
    unsigned char mac_loopback_enable;                        /*MAC环回使能*/
    unsigned char export_speed_limit_enable;          /*出口限速开关*/
    unsigned int export_speed_limit_bandwidth;   /*出口限速流量*/
    unsigned char inport_speed_limit_enable;          /*入口限速开关*/
    unsigned int inport_speed_limit_bandwidth;   /*入口限速流量*/
    unsigned char inport_phb_policy;
    unsigned char inport_phb_select;
    unsigned char res[4];
} PORT_ADVANCED_CONF;    /*高级配置*/

/*
   速率抑制
 */
typedef struct port_inhibit_conf_t
{
    unsigned char broadcast_inhibit;         /*广播包抑制开关*/
    unsigned int broadcast_bandwidth;   /*广播包抑制流量*/

    unsigned char multicast_inhibit;         /*组播包抑制开关*/
    unsigned int multicast_bandwidth;   /*组播包流量*/

    unsigned char flood_inhibit;         /*洪泛包抑制开关*/
    unsigned int flood_bandwidth;       /*洪泛包流量*/
} PORT_INHIBIT;    /*速率抑制*/

/*
   出口队列调度策略
 */
typedef struct export_queue_schedule_t
{
    unsigned char mode;             /* 模式: 0/1 = SP/WFQ */
    unsigned char weight;   /* 权重: 1-127 */
} EXPORT_QUEUE_SCHEDULE;    /*出口队列调度策略*/

/*
   出口队列拥塞策略
 */
typedef struct export_queue_congestion_t
{
    unsigned char mode;                                     /* 模式: 0/1 = 队尾丢弃/WRED        */
    unsigned char green_start_thres;        /* 绿色START门限(%)  : 0-50-100    */
    unsigned char green_end_thres;          /* 绿色END门限(%)  : 0-100                  */
    unsigned char yellow_start_thres;   /* 黄色START门限(%)  : 0-50-100    */
    unsigned char yellow_end_thres;         /* 黄色END门限(%)  : 0-100                  */
    unsigned char red_start_thres;          /* 红色START门限(%)  : 0-50-100    */
    unsigned char red_end_thres;                    /* 红色END门限(%)  : 0-100                  */
    unsigned char drop_limit;
    unsigned char res[2];
} EXPORT_QUEUE_CONGESTION;    /*出口队列拥塞策略*/

/*
   802.1p到PHB映射表al
 */
typedef struct t_8021p_2_phb
{
    unsigned char phb;      /*Phb: 0/1/2/3/4/5/6/7= BE/AF1/AF2/AF3/AF4/EF/CS6/CS7*/
    unsigned char color;   /*Color: 0/1/2= green/yellow/red*/
} T_8021P_TO_PHB;    /*802.1p到PHB映射表*/

/*
   Dscp到PHB映射表 al
 */
typedef struct t_dscp_2_phb
{
    unsigned char phb;     /*Phb: 0/1/2/3/4/5/6/7= BE/AF1/AF2/AF3/AF4/EF/CS6/CS7*/
    unsigned char color;   /*Color: 0/1/2= green/yellow/red*/
} T_DSCP_TO_PHB;    /*Dscp到PHB映射表*/

/*
   Phb到802.1p映射表al
 */
typedef struct phb_2_8021p_t
{
    unsigned char ieee8021p;   /*8021P: 0/1/.../7*/
} PHB_TO_8021P;    /*Phb到802.1p映射表*/

/*
   Phb到dscp映射表
 */
typedef struct phb_2_dscp_t
{
    unsigned char dscp;   /*DSCP: 0/1/.../63*/
} PHB_TO_DSCP;    /*Phb到dscp映射表*/

/*
   TC到PHB映射表
 */
typedef struct tc_2_phb_t
{
    unsigned char phb;     /*Phb: 0/1/2/3/4/5/6/7= BE/AF1/AF2/AF3/AF4/EF/CS6/CS7*/
    unsigned char color;   /*Color: 0/1/2= green/yellow/red*/
} TC_TO_PHB;    /*TC到PHB映射表*/

/*
   Phb到tc映射表
 */
typedef struct phb_2_tc_t
{
    unsigned char tc;   /*tc: 0/1/.../255*/
} PHB_TO_TC;    /*Phb到tc映射表*/

/*
   染色到802.1P映射
 */
typedef struct color_2_8021p_t
{
    unsigned char green_pkt;
    unsigned char yellow_pkt;   /*tc: 0/1/.../255*/
    unsigned char res[3];
} COLOR_2_8021P;    /*染色到802.1P映射*/

/*
   QOS策略

   字节1-2：端口流量整形QOS动作模板  0~4K （0为默认）
    字节3-4：出口队列调度策略模板    0~4K  （0为默认）
    字节5-6：出口队列拥塞策略模板   0~4K
    字节7-10：备用
 */
typedef struct qos_strategy_t
{
    unsigned short port_flow_qos;
    unsigned short export_queue_scheduling;   /*tc: 0/1/.../255*/
    unsigned short export_queue_congestion;
    unsigned char res[4];
} QOS_STRATEGY_T;    /* QOS策略*/

/*
   端口信息al
 */
typedef struct port_cfg_t
{
    PORT_BASE_CONF base_cfg;              /* 基本配置 */
    PORT_ADVANCED_CONF advanced_cfg;          /* 高级配置 */
    PORT_INHIBIT inhibit;               /* 速率抑制 */
    EXPORT_QUEUE_SCHEDULE queue_sche[8];         /* 出口队列调度策略 */
    EXPORT_QUEUE_CONGESTION queue_congestion[8];   /* 出口队列拥塞策略 */
    T_8021P_TO_PHB ieee8021p2phb[8];      /* 802.1P 到 PHB 映射表 */
    T_DSCP_TO_PHB dscp2phb[64];          /* DSCP   到 PHB 映射表 */
    PHB_TO_8021P phb28021p[8];          /* PHB 到 802.1P 映射表 */
    PHB_TO_DSCP phb2dscp[8];           /* PHB 到 DSCP   映射表 */
    COLOR_2_8021P color_8021p;           /* 染色报文到 802.1P 映射*/
    QOS_STRATEGY_T qos_strategy_p;

} PORT_CFG_T;    /*端口信息*/

/**************list*******************/
typedef struct port_cfg_node
{
    unsigned char port_slot;
    unsigned char port_port;
    unsigned char cfg_flag;
    int cfg_length;
    PORT_CFG_T port_cfg;
    struct  port_cfg_node *cfg_next;

} PORT_CFG_NODE;    /*端口信息*/

//extern PORT_CFG_NODE *g_port_cfg_node_head = (PORT_CFG_NODE *)NULL; /**物理口到sys口链表头**/

/*********************************/

/********************
   ID:3 PTN点到点业务虚拟接口ID配置
********************/

//al
typedef struct port_virtual_cfg_t
{
    unsigned int virtual_inter1; //虚拟子接口1：
    unsigned int virtual_inter2; //虚拟子接口2
    unsigned int protect_virtual; //保护虚拟子接口
    unsigned short groupid; //GROUP_ID
    unsigned char res[6]; //备用
} PTN_VIRTUAL_ID_CFG_T;    /*端口信息*/

//定义单链表结构体
typedef struct _ptn_virtual_id_node
{
    unsigned short key_vpws_id;
    unsigned char cfg_flag;
    unsigned int len;
    PTN_VIRTUAL_ID_CFG_T ptn_virtual_cfg;
    struct _ptn_virtual_id_node *cfg_next;
} PTN_VIRTUAL_ID_NODE;

/********************
   VPLS业务虚拟接口ID配置
********************/

/*
   vpls nni虚拟子接口设置
 */
typedef struct vpls_nni_lif_id_conf_t
{
    unsigned short nni_virtual_port_num;
    int nni_virtual_port_id[64];
} VPLS_NNI_LIF_ID_CONF;    /*vpls nni虚拟子接口设置*/

/*
   vpls nni虚拟子接口id
 */
typedef struct vpls_uni_lif_id_conf_t
{
    unsigned short uni_virtual_port_num;
    int uni_virtual_port_id[16];
} VPLS_UNI_LIF_ID_CONF;    /*vpls nni虚拟子接口id*/

/*
   vpls 虚拟子接口配置
 */
typedef struct vpls_lif_id_conf_t
{
    VPLS_NNI_LIF_ID_CONF nni_v_port_id_cfg;
    VPLS_UNI_LIF_ID_CONF uni_v_port_id_cfg;
} VPLS_LIF_ID_CONF;    /*vpls 虚拟子接口配置*/

//定义单链表结构体
typedef struct _vpls_virtual_id_node
{
    unsigned short vpls_id;
    unsigned char cfg_flag;
    unsigned int len;
    VPLS_LIF_ID_CONF vpls_virtual_cfg;
    struct _vpls_virtual_id_node *cfg_next;
} VPLS_VIRTUAL_ID_NODE;

/********************
   虚拟子接口映射
********************/

/*
   nni虚拟子接口配置 mpls
 */

typedef struct nni_virtual_port_conf_t
{

    unsigned short sysport_id;
    unsigned char slot;
    unsigned char port;
    unsigned char relation_setting;
    int tuunel_label;
    int pw_label;
    unsigned char res[2];
} NNI_VIRTUAL_PORT_CONF;    /*nni虚拟子接口配置*/
typedef struct nni_virtual_port_conf_t_protect
{

    unsigned short sysport_id;
    unsigned char slot;
    unsigned char port;
    unsigned char relation_setting;
    int tuunel_label;
    int pw_label;
    int label;
    unsigned char live_time;
    unsigned char exp;
    unsigned char lsp_type;
    int ingress;
    int egress;
    int tunnelid;
    int lsp_id;
    unsigned char alm_monitor;
    unsigned short alm_id;
    unsigned char rcv_tag_recognise;
    unsigned char send_tag_action;
    unsigned short add_vlan_id;
    unsigned char add_vlan_pri;
    unsigned char res[16];

} NNI_VIRTUAL_PORT_CONF_PROTECT;    /*nni虚拟子接口配置*/

/*
   vlan配置
 */
typedef struct vlan_cfg_t
{
    unsigned char rcv_tag_recognise;   /*接收 TAG 识别：0/1=不识别/识别*/
    unsigned char send_tag_action;     /*发送 TAG 行为：0/1/2=NOP/增加/删除*/
    unsigned short add_vlan_id;                 /*发送增加 VLAN ID ：1-2-4095*/
    unsigned char add_vlan_pri;                /*发送增加 VLAN PRI：0-7*/
} VLAN_CFG;    /*vlan配置*/

/* 流配置 */
typedef struct flow_conf_t
{
    unsigned char flow_id;                                   /* 流 ID */
    unsigned char policer_mode;              /* 策略模式  0/1/2 = 不使能/ MEF trTCM /RFC2698 trTCM */
    unsigned short cir;
    unsigned short pir;
    unsigned int cbs;
    unsigned int pbs;
    unsigned char cm_mode;                   /* 0/1=色盲/色感知 */
    unsigned char flow_phb_select_policer;   /* 流PHB选择策略：0/1=指配PHB/基于用户优先级到PHB映射 */
    unsigned char flow_select_phb;           /* 指配 PHB：0/1/2/3/4/5/6/7=BE/AF1/AF2/AF3/AF4/EF/CS6/CS7 */
    unsigned char relation_set;              /* 关联设置 */
    unsigned char res[2];
    unsigned short ovlan;
    unsigned short ivlan;
    unsigned char smac[6];                   /* 源   MAC 地址 */
    unsigned char dmac[6];                   /* 目的 MAC 地址 */
    unsigned char _8021p;
    unsigned char sip[4];                    /* 源   IP 地址 */
    unsigned char dip[4];                    /* 目的 IP 地址 */
    unsigned char dscp;

    unsigned int port_index;
    unsigned char _res[450];
} FLOW_CONF;    /* 流配置 */

/*
   uni虚拟子接口配置al
 */
typedef struct uni_virtual_port_conf
{
    unsigned char uni_type;          /* 0/1 = normal/vlan_bridge */
    unsigned char uni_id;            /* UNI ID */
    unsigned char uni_attribute;     /* 接口属性：0/1/2=物理端口/LAG/L2VPORT*/
    unsigned short sysport_id;
    unsigned char slot;              /* 槽位号 */
    unsigned char port;              /* 端口号 , Loacl Port */
    unsigned char mac_learn_en;      /* MAC地址学习 */
    unsigned char split_horizon_enable; /* 水平分割 */
    VLAN_CFG svlan;
    VLAN_CFG cvlan;
    unsigned char policer_mode;      /* 策略模式 */
    unsigned short cir;
    unsigned short pir;
    unsigned int cbs;
    unsigned int pbs;
    unsigned char cmmode;            /* CM模式: 0/1 色盲 / 色感 */
    unsigned char flow_en;           /* 流使能 */
    unsigned char flow_type;         /* 流类型：0/1/2 = 基于端口/基于VLAN/基于QINQ */
    unsigned char flow_num;
    FLOW_CONF flow; //[10];              /* 流配置 单盘只支持一个流*/
} UNI_VIRTUAL_PORT_CONF;    /*uni虚拟子接口配置*/

typedef struct virtual_port_map_cfg
{
    NNI_VIRTUAL_PORT_CONF nni_virtual_port_cfg;
    UNI_VIRTUAL_PORT_CONF uni_virtual_port_cfg;
    NNI_VIRTUAL_PORT_CONF_PROTECT nni_protect_virtual_port_cfg;
} VIRTUAL_PORT_MAP_CFG;    /*uni虚拟子接口配置*/

//定义单链表结构体
typedef struct _virtual_port_map_cfg_node
{
    unsigned short virtual_port_id; //Virtual Port ID
    unsigned char cfg_flag;
    unsigned int len;
    VIRTUAL_PORT_MAP_CFG virtual_port_map_cfg;
    struct _virtual_port_map_cfg_node *cfg_next;
} VIRTUAL_PORT_MAP_CFG_NODE;

/********************
   VPWS
********************/

/* 基本配置 */
typedef struct vpws_base_conf_t
{
    unsigned char busitype;                   /*业务类型：0/1/2=UNI-UNI/UNI-NNI/NNI-NNI*/
    unsigned short vpls_id;
    unsigned short lsp_protect_group_id;   /*lsp 保护组id*/
    unsigned short qos_table_id;           /*qos配置表id*/
    unsigned char protect_level;          /*0/1/2/3/4=无/vs/vp/vc/vp+vc*/
    unsigned short pw_protect_group_id;    /*pw 保护组id*/
    unsigned char protect_type; /*pw 保护组id*/
    unsigned short vc_num; /*pw 保护组id*/
    unsigned char res[7];
} VPWS_BASE_CONF;    /*基本配置*/

//NEXTHOP 下一跳配置
typedef struct next_hop_conf
{
    unsigned int ip_address;                            /*IP地址*/
    unsigned char slot;
    unsigned char portnum;

    //unsigned short des_sysport;
    unsigned short vlan_id;                                       /*VLAN ID：0-4095*/
}NEXTHOP;

//注释al
typedef struct vpws_vpls_nni_conf
{
    unsigned int vc_id;                                 /*VC ID*/
    unsigned int peer_ip;                                       /*PEER IP*/
    unsigned int send_pw_label;                 /*发送PW标签*/
    unsigned char ttl;                                           /*生存时间TTL：1-255*/
    unsigned char exp;                                   /*EXP：0-7*/
    unsigned char lsp_label_mode;                /*LSP标签封装方式：0/1/2=不封装/TE-LSP/LDP-LSP*/
    unsigned int ingress;                                       /*入口IP*/
    unsigned int egress;                                /*出口IP*/
    unsigned int lsp_id;                                /*LSP  条目号*/
    unsigned char alm_detect_mode;               /*告警检测方式：0/1=MPLS-TP/BFD*/
    unsigned short alm_detect_instance_id; /*告警检测实例ID：1-2047*/
    unsigned int rcv_pw_label;                  /*接收PW标签：16-1048575*/
    unsigned short pw_index;
    unsigned char protect_type;
    unsigned int logic_id_peer_id;
    unsigned int diff_sercid;
    unsigned int nodeindex;
    unsigned int qos_policy_index;
    unsigned int flow_qos_policy_index;
    unsigned char work_slot;
    unsigned char back_slot;
    unsigned int back_lif_id;
    unsigned short main_sysport;
    unsigned char mpid[6];
    unsigned short cfm_oamid;
    unsigned char res_1[6];
}VPWS_VPLS_NNI;

/* NNI [1-2] 接口配置 al*/
typedef struct vpws_nni_conf_t
{
    unsigned char phb2exp_policer;       /*PHB到EXP映射策略：0/1=指配EXP/基于PHB到EXP映射表*/
    unsigned char select_exp;            /*指配EXP：0-7*/
    unsigned char phb2exp_id;            /*PHB2EXP_ID：1-15*/
    unsigned char exp2phb_policer;       /*EXP到PHB映射策略：0/1=指配PHB/基于EXP到PHB映射表*/
    unsigned char select_phb;            /*指配PHB：0/1/2/3/4/5/6/7=BE/AF1/AF2/AF3/AF4/EF/CS6/CS7*/
    unsigned char exp2phb_id;            /*EXP2PHB_ID：1-15*/
    unsigned char rcv_tag_recognise;     /*接收TAG识别：0/1=不识别/识别*/
    unsigned char send_tag_action;       /*发送TAG行为：0/1/2=NOP/增加/删除*/
    unsigned short add_vlan_id;           /*发送增加VLAN ID：1-2-4095*/
    unsigned char add_vlan_pri;          /*发送增加VLAN PRI：0-7*/
    unsigned char control_word_enable;   /*控制字使能：0/1=不使能/使能*/

    NEXTHOP next_hop;              /*下一跳配置（不封装LSP LABEL时用）*/
    unsigned char nni_lag_id;
    unsigned char return_type;
    unsigned char wait_time;
    unsigned short delay_time;
    unsigned char protect_type;          /*保护类型：0/1=无保护/有保护*/
    unsigned short nni_lag_id_nni;
    unsigned short nni_pve_id;
    unsigned short pw_protect_id;
    unsigned short nni_pve_index;
    unsigned char res[2];

    VPWS_VPLS_NNI main;                  /*主用配置*/
    VPWS_VPLS_NNI back;                  /*备用配置*/
} VPWS_NNI_CONF;    /*NNI [1-2] 接口配置*/

/*
   uni虚拟子接口
 */
typedef struct uni_virtual_id_t
{
    int uni_virtual_id;   /*uni虚拟子接口id*/
    unsigned char uni_id;
    unsigned int port_logic_index;
    unsigned char svlan_recv_tag;
    unsigned char svlan_tx_tag;
    unsigned short svlan_tx_add_vlan_id;
    unsigned char svlan_tx_add_vlan_pri;
    unsigned char cvlan_recv_tag;
    unsigned char cvlan_tx_tag;
    unsigned short cvlan_tx_add_vlan_id;
    unsigned char cvlan_tx_add_vlan_pri;
    unsigned char slot;
    unsigned short lag_id;
    unsigned short sysport;
    unsigned char res[6];
} UNI_VIRTUAL_ID;

/* VPWS 配置块 */
typedef struct vpwsconf_t
{
    VPWS_BASE_CONF base;     /* 基本配置 */
    VPWS_NNI_CONF nni[2]; //[2];      /* NNI 配置 , PTN业务使用 */
    UNI_VIRTUAL_ID uni_id[3]; /* VPWS 对应的虚拟 UNI 配置 */

} VPWS_CONF_DATA;    /* VPWS 配置块 */

/* VPWS 配置块 */

//定义单链表结构体

typedef struct _vpws_cfg_node
{
    unsigned short vpws_id;     /* 基本配置 */
    unsigned char cfg_flag;
    unsigned int len;
    VPWS_CONF_DATA vpws_cfg_data;      /* NNI 配置 , PTN业务使用 */
    struct _vpws_cfg_node *cfg_next;

} VPWS_CFG_NODE;    /* VPWS 配置块 */

/********************
   VPLS
********************/

//基本配置
typedef struct vpls_base_conf_t
{
    unsigned short mac_learn_capacity;      /*MAC学习容量限制：1-65535*/
    unsigned char type;              /*业务类型*/
    unsigned short nni_member_num;          /*NNI成员端口数：0/1-64（0表示无）*/
    unsigned char uni_member_num;          /*UNI成员端口数：0/1-10（0表示无）*/
    unsigned char igmp_enble;
    unsigned short vsi_id;              /*暂时无用*/
    unsigned char mac_learn_capacity_h;
    unsigned short mac_learn_capacity_l;
    unsigned char unknow_frame_policy;  /*未知桢处理策略: 0/1 = 组播/丢弃*/
    unsigned char res[2];
} VPLS_BASE_CONF;    /*基本配置*/

//NNI [1-64] 接口配置
typedef struct vpls_nni_conf_t
{
    unsigned char phb2exp_policer;        /*PHB到EXP映射策略：0/1=指配EXP/基于PHB到EXP映射表*/
    unsigned char select_exp;             /*指配EXP：0-7*/
    unsigned char phb2exp_id;             /*PHB2EXP_ID：1-15*/
    unsigned char exp2phb_policer;        /*EXP到PHB映射策略：0/1=指配PHB/基于EXP到PHB映射表*/
    unsigned char select_phb;             /*指配PHB：0/1/2/3/4/5/6/7=BE/AF1/AF2/AF3/AF4/EF/CS6/CS7*/
    unsigned char exp2phb_id;             /*EXP2PHB_ID：1-15*/
    VLAN_CFG svlan;
    unsigned char control_word_enable;        /*控制字使能：0/1=不使能/使能*/
    unsigned char mac_learn_enable;           /*MAC学习开关：0/1=开/关*/
    unsigned char split_horizon_enable;   /*水平分割开关：0/1=开/关*/
    NEXTHOP next_hop;                               /*下一跳配置（不封装LSP LABEL时用）*/
    unsigned char nni_lag_id_np; //网管不显示
    unsigned char return_type;
    unsigned char wait_time;
    unsigned short protect_time; //保护拖延时间
    unsigned char protect_type;                       /*保护类型：0/1=无保护/有保护*/
    unsigned short nni_lag_id;
    unsigned short nni_pve_id;
    unsigned short pw_protect_id;
    unsigned short nni_pve_index;
    unsigned char res[2];

    VPWS_VPLS_NNI main;                                       /*主用配置*/
    VPWS_VPLS_NNI back;                                       /*备用配置*/
} VPLS_NNI_CONF;    /*NNI [1-64] 接口配置*/

/*
   vpls配置
 */
typedef struct vpls_conf_data_t
{
    VPLS_BASE_CONF base;
    VPLS_NNI_CONF nni[64];
    UNI_VIRTUAL_ID uni_id[16];
} VPLS_CONF_DATA;    /*vpls配置*/

//定义单链表结构体
typedef struct _vpls_cfg_node
{
    unsigned short vpls_id;
    unsigned char cfg_flag;
    unsigned int len;
    VPLS_CONF_DATA vpls_cfg_data;
    struct _vpls_cfg_node *cfg_next;
}VPLS_CFG_NODE;

/********************
   TE-LSP(RX)（此配置先于VPWS、VPLS下发）
********************/

/********************
   TE-LSP(TX，)(此配置先于VPWS、VPLS下发)
********************/

//lsp标签
typedef struct lsp_label_t
{
    unsigned int label;   /*标签值*/
    unsigned char ttl;     /*生存时间*/
    unsigned char exp;     /*优先级*/
} LSP_LABEL;    /*lsp标签*/

//lsp标签
typedef struct lsp_base_sub_cfg
{
    unsigned int fec_id;
    unsigned int encap_id;
    unsigned short nni_lag_id;
    unsigned short nni_pve_id;
} LSP_BASE_SUB_CFG;    /*lsp标签*/

//基本配置
typedef struct lsp_tx_base_conf_t
{
    unsigned int rec_label;         /*发送标签：16-1048575*/
    unsigned char protection_mode;   /*保护模式：0/1=无/TE_FRR(FRR GROUP ID等于OUTPORT)*/
    unsigned char label_action;      /*标签动作：0/1/2/3/4= SWAP/PHP/SWAP+PUSH/IPOP*/
    unsigned short sysport_id;        /*LSP入口配置*/
    unsigned short in_vlanid;         /*LSP入口配置:VLANID*/
    NEXTHOP next_hop;          /*下一跳配置 2222 */
    unsigned char exp2phb_policer;   /*EXP到PHB映射策略：0/1=指配PHB/基于EXP到PHB映射表*/
    unsigned char select_phb;        /*指配PHB：0/1/2/3/4/5/6/7=BE/AF1/AF2/AF3/AF4/EF/CS6/CS7*/
    unsigned char exp2phb_id;        /*EXP2PHB_ID：1-15*/
    unsigned short vrf_id;            /*VRF序号*/
    unsigned short line_no;           /*线路号*/
    unsigned char res[1];            /*保留*/
    unsigned short tp_oamId;
    unsigned char label_num;         /*标签个数*/
    LSP_LABEL lsp_label[5];         /*标签列表*/ /*适配层下发一层标签*/
    unsigned int vpws_id;
    unsigned short logic_sub_id; //逻辑子接口
    unsigned short dst_vpid;
    unsigned int global_id;
    unsigned char protect_type;
    unsigned short protect_groupId;
    unsigned short src_vpid;
    unsigned int diff_servid;
    LSP_BASE_SUB_CFG inputcfg;
    LSP_BASE_SUB_CFG outputcfg;
	unsigned int bfd_localid;

    /*unsigned int fec_id;
       unsigned int encap_id;
       unsigned short nni_lag_id;
       unsigned short nni_pve_id;*/
} LSP_TX_BASE_CONF;    /*lsp_tx基本配置*/

//保护配置暂对pots无意义，不接收存储2015.7

//带宽控制
typedef struct lsp_tx_bw_conf_t
{
    unsigned char enable;
    unsigned short cir;
    unsigned short pir;
    unsigned int cbs;
    unsigned int pbs;
    unsigned char cm_color;
} LSP_TX_BW_CONF;    /*带宽控制*/

//4）WRAPPING保护配置
typedef struct lsp_tx_wrap_protect_conf_t
{
    unsigned short dst_logic_id;
    unsigned short src_logic_id;
    unsigned char det_node_id;
    unsigned char res[3];
} LSP_TX_WRAP_CONF;      /*WRAPPING保护配置*/

/*
   lsp_tx配置
 */
typedef struct tx_lsp_cfg_t
{
    LSP_TX_BASE_CONF tx_las_base;
    LSP_TX_BW_CONF tx_lsp_bw_conf;
    LSP_TX_WRAP_CONF tx_lsp_wrap;
} TX_LSP_CFG;    /*lsp_Tx配置*/

//创建单链表结构体
typedef struct _tx_lsp_cfg_node
{
    unsigned int ingress;
    unsigned int egress;
    unsigned int lsp_id;
    unsigned char cfg_flag;
    unsigned int len;
    TX_LSP_CFG lsp_tx_cfg_data;
    struct _tx_lsp_cfg_node *cfg_next;
}TX_LSP_CFG_NODE;

/*
   PTN QOS映射模板
 */
typedef struct ptn_qos_base
{
    unsigned char slot;
    unsigned char res[14];

}PTN_QOS_BASE;

/*
   字节3：DSCP到PHB映射表配置索引ID: 0 ~ 16（0表示不选择）（网管界面不显示）
   字节4：8021p到PHB映射表配置索引ID: 0 ~ 16
   字节5：EXP到PHB映射表索引ID: 0 ~ 16
   字节6：PHB到DSCP映射表配置索引ID: 0 ~ 16（网管界面不显示）
   字节7：PHB到8021p映射表索引ID: 0 ~ 16
   字节8：PHB到EXP映射表索引ID: 0 ~ 16
   字节9 ~ 20：备用
 */
typedef struct qos_template
{
    unsigned short table_id;
    unsigned char dscp_phb_id;
    unsigned char p8021_phb_id;
    unsigned char exp_phb_id;
    unsigned char phb_dscp_id;
    unsigned char phb_8021p_id;
    unsigned char phb_exp_id;
    unsigned char res[12];

}QOS_TEMPLATE;

typedef struct ptn_qos_map
{
    PTN_QOS_BASE base_cfg;
    QOS_TEMPLATE usr_qos_map;
}PTN_QOS_MAP;
typedef struct ptn_qos_map_node
{
    unsigned char slot;
    unsigned short tableid;
    unsigned char cfg_flag;
    unsigned int len;
    PTN_QOS_MAP ptn_qos_map_data;
    struct ptn_qos_map_node *cfg_next;
}PTN_QOS_MAP_NODE;

//extern PTN_QOS_MAP_NODE *g_ptn_qos_map_cfg_node_head = (PTN_QOS_MAP_NODE *)NULL; //list

/*
   1）基本配置
   字节0：子配置类型值（Type）：固定为0x11
   字节1~2：子配置长度（Length）：2736

 */

/*     隧道保护配置   */
typedef struct _tunnel_protect_lsp
{
    unsigned char protect_type;
    unsigned int ingress;
    unsigned int egress;
    unsigned int lsp_id;

}TUUNEL_PROTECT_LSP;
typedef struct _tunnel_protect_base
{
    TUUNEL_PROTECT_LSP main_lsp;
    TUUNEL_PROTECT_LSP back_lsp;
    unsigned char return_type;
    unsigned char wait_time;
    unsigned short protect_delay_time;
    unsigned char main_slot;
    unsigned char back_slot;
    unsigned short main_oam_id;
    unsigned short back_oam_id;
    unsigned char res;
}TUNNEL_PROTECT_BASE;

typedef struct _tunnel_protect_node
{
    unsigned short protect_id;
    unsigned char cfg_flag;
    unsigned int len;
    TUNNEL_PROTECT_BASE tunnel_protect_cfg_data;
    struct _tunnel_protect_node *cfg_next;
}TUNNEL_PROTECT_NODE;

/*
   ID 19、MPLS-TP OAM 主动
 */

typedef struct _mpls_tp_base
{
    unsigned short oamid;
    unsigned char oam_level;
    unsigned char vp_mip_mep;
    unsigned char meg_icc[6];
    unsigned char meg_umc[6];
    unsigned short src_mep_id;
    unsigned short equal_mep_id;
    unsigned char lsp_exp;
    unsigned char pw_exp;
    unsigned char mel;
    unsigned char aps_enable;
    unsigned char cv_tx_enable;
    unsigned char cv_tx_time;
    unsigned char csf_tc_enable;
    unsigned char fdi_enable;
    unsigned char gal_exp;
    unsigned char lsp_ttl;
    unsigned char pw_ttl;
    unsigned char gal_ttl;
    unsigned char vs_next_slot;
    unsigned char vs_next_port;
    unsigned char wrapping_id;
    unsigned char wrapping_driect;
    unsigned char slot;
    unsigned char res[8];

}MPLS_TP_OAM_BASE;

typedef struct _mpls_tp_oam_node
{
    unsigned short oam_id;
    unsigned char cfg_flag;
    unsigned int len;
    MPLS_TP_OAM_BASE mpls_tp_oam_cfg_data;
    struct _mpls_tp_oam_node *cfg_next;
}MPLS_TP_OAM_NODE;

/*
   ID67、接口物理配置（条目数5000）
 */
typedef struct _exit_queue_schedule
{

    unsigned char mode;
    unsigned char weight;
    unsigned char res[2];
}EXIT_QUEUE_SCHEDULE;

//67.69 gongyong
typedef struct _exit_queue_congest
{

    unsigned char mode;
    unsigned char green;
    unsigned char yellow;
    unsigned char red;
    unsigned char res[4];
}EXIT_QUEUE_CONGEST;

typedef struct _base_cfg_if_phy
{
    unsigned char iftype;
    unsigned char ifpoperty;
    unsigned char ifspeed;
    unsigned char boxid;
    unsigned char slot;
    unsigned char sub_boardid;
    unsigned char portnum;
    unsigned char au4no;
    unsigned char tug3no;
    unsigned char tug2no;
    unsigned char tu12no;
    unsigned char tdmtype;
    unsigned int index;
    unsigned short sysport;
}BASE_CFG_IF_PHY;

/*字节1：工作模式：0/1=非自协商/自协商

   字节37~40：MCC VLAN_ID:2-4093-4095				//MCC开有效*/

typedef struct _eth_cfg_if_phy
{
    unsigned char work_type;
    unsigned char port_switch;
    unsigned char res[3];
    unsigned char phy_addr_len;
    unsigned char phy_addr[14];
    unsigned short mtu;
    unsigned char band[3];
    unsigned short stpid;
    unsigned char res1;
    unsigned char efm_oam;
    unsigned char res2;
    unsigned char mccswitch;
    unsigned char port_tp;
    unsigned char port_toec;
    unsigned char speed;
    unsigned char port_priority;
    unsigned char res3;
    unsigned int mcc_vlan_id;

}ETH_CFG_IF_PHY;

//以太网出口队列调度策略

/*
   字节1~4：队列0
        字节1：Mode模式：0/1=SP/WFQ
        字节2：Weight权重：1-127
   字节3~4：备用
        ……
   字节31~32：队列7
        字节1：Mode模式：0/1=SP/WFQ
        字节2：Weight权重：1-127
   字节3~4：备用

 */
typedef struct _eth_ex_queue_scheduling
{
    EXIT_QUEUE_SCHEDULE queue_schedule[8];

}ETH_EX_QUEUE_SCHEDULING;

//以太网出口队列拥塞策略
typedef struct _eth_ex_queue_congestion
{
    EXIT_QUEUE_CONGEST queue_congest[8];

}ETH_EX_QUEUE_CONGESTION;

//POVE

/*
   16）POVE
   字节1~2：子配置类型值（Type）：固定为0x12
   字节3~4：子配置长度（Length）：40
   子配置内容（Value）：
   字节1~4：PVE-ID:
   字节5-字节40：备用

 */
typedef struct _pove_cfg_if_phy
{
    unsigned int pveid;
    unsigned char res[36];
}POVE_CFG_IF_PHY;

typedef struct _interface_phy_base
{
    BASE_CFG_IF_PHY base_cfg;
    ETH_CFG_IF_PHY eth_cfg;
    ETH_EX_QUEUE_SCHEDULING eth_queue_schedule;
    ETH_EX_QUEUE_CONGESTION eth_queue_congest;
    POVE_CFG_IF_PHY pve_cfg;

}INTERFACE_PHY_BASE;

typedef struct _interface_phy_node
{
    unsigned int index;
    unsigned char cfg_flag;
    unsigned int len;
    INTERFACE_PHY_BASE interface_phy_cfg_data;
    struct _interface_phy_node *cfg_next;
}INTERFACE_PHY_NODE;

/*
   ID 69、PVE接口配置
 */

typedef struct _pve_interface_base
{
    unsigned int pveid;
    unsigned short pve_groupid;
    unsigned char mpls_tp_pack_type;
    unsigned char exit_band[3];
    unsigned char res[8];
    unsigned short sysport;
    unsigned char phy_port;
    EXIT_QUEUE_SCHEDULE queue_schedule[8];
    EXIT_QUEUE_CONGEST queue_congest[8];
    unsigned short back_sysport;
    unsigned char back_port;
    unsigned char mac_dress[6];
    unsigned char res1[34];

}PVE_INTERFACE_BASE;

typedef struct _pve_interface_node
{
    unsigned int pve_id;
    unsigned char cfg_flag;
    unsigned int len;
    PVE_INTERFACE_BASE pve_interface_cfg_data;
    struct _pve_interface_node *cfg_next;
}PVE_INTERFACE_NODE;

/*
   ID 68、端口逻辑配置（条目数32000）
 */

/*
   1）基本配置
 */
typedef struct _port_logic_base
{
    unsigned char port_index;
    unsigned char port_sub_type;
    unsigned char port_route;
    unsigned char sub_lf_type;
    unsigned short vlan_sub_id;
    unsigned char res[2];
}PORT_LOGIC_BASE;

/*2)*/
typedef struct _phy_cfg_port_logic
{
    unsigned int port_index;
    unsigned int lag_id;
    unsigned short ve_group_id;
    unsigned char res[2];
}PHY_CFG_PORT_LOGIC;

/*
   4）逻辑配置L2
 */
typedef struct _logic_cfg_l2
{
    unsigned char vlan[5];
    unsigned char rx_act;
    unsigned char tx_tag_act;
    unsigned short tx_add_vlan_id;
    unsigned char tx_add_vlan_pri;
    unsigned char igmp_snooping_enable;
    unsigned short tag_type;
    unsigned char mac_switch;
    unsigned char split_horizon;
    unsigned char res[2];
}LOGIC_CFG_L2;

/*5）流相关配置L2
   字节1~2：子配置类型值（Type）：固定为0x55
   字节3~4：子配置长度（Length）：16
   子配置内容（Value）：
   字节1-16：备用*/
typedef struct _flow_cfg_l2
{
    unsigned char res[16];
}FLOW_CFG_L2;

/*
   12）Diff-Serv配置(网管不显示)
 */
typedef struct _diff_serv_cfg
{
    unsigned short svlan_id;
    unsigned short cvlan_id;
    unsigned int diff_serv_index;
}DIFF_SERV_CFG;

/*
   15）上话用户QOS策略配置
 */
typedef struct _qos_strategy_cfg
{
    unsigned short svlan_id;
    unsigned short clvan_id;
    unsigned int usr_qos_strategy_index;
    unsigned int cir;
    unsigned int pir;
    unsigned short cbs;
    unsigned short pbs;
    unsigned char cm_color;
    unsigned char mode;
}QOS_STRATEGY_CFG;

/*
   21）VLAN属性（单层双层VLAN复用，不会层次混合下发；单层时CVLAN数值为0）

 */
typedef struct _vlan_property_cfg
{
    unsigned short svlan_id;
    unsigned short clvan_id;
}VLAN_PROPERTY_CFG;

typedef struct _port_logic_cfg_base
{

    PORT_LOGIC_BASE port_logic_base_data;
    PHY_CFG_PORT_LOGIC port_cfg_port_logic_data;
    LOGIC_CFG_L2 logic_cfg_l2_data;
    FLOW_CFG_L2 flow_cfg_l2_data;
    DIFF_SERV_CFG diff_serv_cfg_data;
    QOS_STRATEGY_CFG qos_strategy_cfg_data;
    VLAN_PROPERTY_CFG vlan_property_data;
}PORT_LOGIC_CFG_BASE;

typedef struct _port_logic_cfg_node
{
    unsigned int index;
    unsigned char cfg_flag;
    unsigned int len;
    PORT_LOGIC_CFG_BASE port_logic_cfg_data;
    struct _port_logic_cfg_node *cfg_next;
}PORT_LOGIC_CFG_NODE;

/*
   2、 端口聚合
 */

typedef struct _group_cfg_base
{
    unsigned char lacp_switch;
    unsigned short priority;
    unsigned char res[7];
}GROUP_CFG_BASE;

//2）LAG配置

typedef struct _lag_cfg_member
{

    unsigned char slot;
    unsigned char port;
}LAG_CFG_MEMBER;

typedef struct _lag_cfg_base
{
    unsigned char lagid;
    unsigned char mode;
    unsigned char share_arith;
    unsigned char return_mode;
    unsigned char wslot;
    unsigned char wport;
    unsigned char pslot;
    unsigned char pport;
    unsigned char wait_time;
    LAG_CFG_MEMBER memeber[20];
    unsigned char l2_l3;
    unsigned char mac_ip[6];
    unsigned char aggre_member1_8;
    unsigned char aggre_member9_16;
    unsigned char aggr_emember17_20;
    unsigned char aggre_slot;
    unsigned char dual_slot;
    unsigned char dual_port;
    unsigned short lag_id;
    unsigned char local_port[20];
    unsigned char res[16];
    LAG_CFG_MEMBER aggr_memeber[20];

}LAG_CFG_BASE;

typedef struct _port_aggregate_cfg_base
{
    GROUP_CFG_BASE group_cfg_data;
    LAG_CFG_BASE lag_cfg_data;
}PORT_AGGREGATE_CFG_BASE;

typedef struct _port_aggregate_cfg_node
{
    unsigned short lagid;
    unsigned char cfg_flag;
    unsigned int len;
    PORT_AGGREGATE_CFG_BASE port_agg_cfg_data;
    struct _port_aggregate_cfg_node *cfg_next;
}PORT_AGGREGATE_CFG_NODE;

/*
   21、MPLS-TP OAM 按需ONDEMAND OAM_ID
 */
typedef struct _ondemand_oam_base_cfg
{
    unsigned short ondemand_oamid;
    unsigned short mpls_tp_oamid;
    unsigned char loop_cfg;
    unsigned short tlv_len;
    unsigned char tlv_content;
    unsigned char tst_cfg;
    unsigned short tlv_len1;
    unsigned char lck_tx_enable;
    unsigned char lm_cfg;
    unsigned char dm_cfg;
    unsigned short dm_len;
    unsigned char tlv_conent1;
    unsigned char lsp_exp;
    unsigned char pw_exp;
    unsigned char gal_exp;
    unsigned char lsp_ttl;
    unsigned char pw_ttl;
    unsigned char gal_ttl;
    unsigned char mel;
    unsigned char res[16];
}ONDEMAND_OAM_BASE_CFG;

typedef struct _ondemand_oam_mip_cfg
{
    unsigned char tlv_mode;
    unsigned char mip_icc[6];
    unsigned int node_id;
    unsigned int if_num;
    unsigned short cc;
    unsigned short mep_id;
    unsigned char detect;
    unsigned char chose_tlv;
    unsigned char request_mep_id;
    unsigned short mip_id;
    unsigned char res[11];
}ONDEMAND_OAM_MIP_CFG;

typedef struct _ondemand_oam_cfg_base
{
    ONDEMAND_OAM_BASE_CFG ondemand_oam_cfg_data;
    ONDEMAND_OAM_MIP_CFG ondemand_oam_mip_cfg_data;

}ONDEMAND_OAM_CFG_BASE;

typedef struct _ondemand_oam_cfg_node
{
    unsigned char oamid;
    unsigned char cfg_flag;
    unsigned int len;
    ONDEMAND_OAM_CFG_BASE ondemand_oam_cfg_data;
    struct _ondemand_oam_cfg_node *cfg_next;
}ONDEMAND_OAM_CFG_NODE;

/*
   28、PTN全局配置
 */
typedef struct _ptn_group_base_cfg
{
    unsigned int mac_time;
    unsigned int lable_init_value;
    unsigned char mac_addr[6];
    unsigned short crc_thr;
    unsigned short pac_drop_thr;
    unsigned short rx_err_pac_thr;
    unsigned short align_err_thr;
    unsigned char unknown;
    unsigned char res[27];
}PTN_GROUP_BASE_CFG;

/*
   MPLS-TP OAM相关配置
 */

typedef struct _ptn_group_cfg_oam
{
    unsigned char src_mac[6];
    unsigned char vp_fdi_tx_enable;
    unsigned char vp_fdi_mel;
    unsigned char vc_fdi_tx_enable;
    unsigned char vc_fdi_mel1;
    unsigned char loop_out_time; //字节11:环回帧超时时间:1-100 (单位:50ms)
    unsigned short vs_channel_thr; //字节12－字节13: VS通道信号劣化门限(20秒)(0-65535)
    unsigned short vs_channel_sigle; //字节14－字节15: VS通道信号失效门限(20秒)(0-65535)
    unsigned short channel_type; //字节16-字节17：Channel Type = 0x7FFA (0-0xffff)
    unsigned short vs_near_pack_loss; //字节18-19：近端丢包率（0－1000）
    unsigned short vs_far_pack_loss; //字节20-21：远端丢包率（0－1000）
    unsigned short vs_tm_us; //字节22－字节23：时延微妙（0－65535）
    unsigned char vs_tm_change_us; //字节24：时延变化量微妙（0－255）
    unsigned short vp_near_pack_loss; //字节25-26：近端丢包率（0－1000）
    unsigned short vp_far_pack_loss; //字节27-28：远端丢包率（0－1000）
    unsigned short vp_tm_us; //字节29－字节30：时延微妙（0－65535）
    unsigned char vp_tm_change_us; //字节31：时延变化量微妙（0－255）
    unsigned short vc_near_pack_loss; //字节25-26：近端丢包率（0－1000）
    unsigned short vc_far_pack_loss; //字节27-28：远端丢包率（0－1000）
    unsigned short vc_tm_us; //字节29－字节30：时延微妙（0－65535）
    unsigned char vc_tm_change_us; //字节31：时延变化量微妙（0－255）
}PTN_GROUP_CFG_OAM;

typedef struct _ptn_group_cfg_base
{
    PTN_GROUP_BASE_CFG ptn_group_cfg_base_data;
    PTN_GROUP_CFG_OAM ptn_group_cfg_oam_data;

}PTN_GROUP_CFG_BASE;

typedef struct _ptn_group_cfg_node
{
    unsigned char oamid;
    unsigned char cfg_flag;
    unsigned int len;
    PTN_GROUP_CFG_BASE ptn_group_cfg_data;
    struct _ptn_group_cfg_node *cfg_next;
}PTN_GROUP_CFG_NODE;

/**********************************
   对外接口函数结构体
**********************************/

/*

 */

/*

 */
typedef struct tTPOAMLSPCFG
{
    unsigned char Slot_West;            //西向槽位
    unsigned char Port_West;            //西向端口
    unsigned char Slot_East;            //东向槽位
    unsigned char Port_East;            //东向端口
    unsigned short SysPortId_West;       //西向系统口id
    unsigned short SysPortId_East;       //东向系统口id
    unsigned int LspLable_West_Rx; //西向tunnel 标签
    unsigned int PwLable_West_Rx; //西向pw 标签
    unsigned int LspLable_East_Rx; //东向tunnel 标签
    unsigned int PwLable_East_Rx; //东向pw 标签

    unsigned int LspLable_West_Tx; //西向tunnel 标签
    unsigned int PwLable_West_Tx; //西向pw 标签
    unsigned int LspLable_East_Tx; //东向tunnel 标签
    unsigned int PwLable_East_Tx; //东向pw 标签
    unsigned short LspId; //lsp_id(不需要,去掉或者保留不填)
    unsigned short is_protect; //是否保护(不需要,去掉或者保留不填)
    unsigned char InSlot; //入槽位，需要（VP 和 VC）
    unsigned char InPort; //入端口，需要（VP 和 VC）
    unsigned char OutSlot; //出槽位，需要（VP 和 VC）
    unsigned char OutPort; //出端口，需要（VP 和 VC）
    unsigned int InLspLable; //入tunnel 标签(需要，仅VP)
    unsigned int OutLspLable; //出tunnel 标签(需要，仅VP)

    unsigned int InPwLable; //入pw 标签(复用，VP层时填0x13，VC层时填入pw 标签)
    unsigned int OutPwLable; //出pw 标签(复用，VP层时填0x13，VC层时填出pw 标签)

    unsigned int SysPortId; //接收系统口id(不需要，去掉或者保留不填)
    unsigned int TxSysLifId; //发送系统口lif(需要，仅VC)
    unsigned int TxSysPortId; //发送系统口id(需要，VP/VC均需要)

    unsigned int RxTunnelEep; //接收的tunnel_eep(需要，仅VP，VC不填)
    unsigned int TxTunnelEep; //发送的tunnel_eep(需要，仅VP，VC不填)

    unsigned char uni_is_lag; //uni是否是lag(需要，仅VC，VP不填)
    unsigned char lag_id; //网管下发的lag_id(需要，仅VC，VP不填)
}TPOAMLSPCFG;

/***********************
   QOS
 *********************/
struct qos_port_flow_info //链表数据节点参考结构体
{
    unsigned char slot;        /* 槽位 */
    unsigned char port;        /* Local port */
    unsigned char res[2];        /* 保留 */
};
typedef struct qos_port_flow_info QOS_PORT_FLOW_INFO;

struct qos_port_flow_info_head //链表头参考结构体
{
    QOS_PORT_FLOW_INFO *head;    /* 表头 */
    QOS_PORT_FLOW_INFO *tail;    /* 表尾 */
    unsigned long length;       /* 表长 */
};
typedef struct qos_port_flow_info_head QOS_PORT_FLOW_INFO_HEAD;

// 查询物理端口下面所有业务的出口的：
typedef struct igmp_cfg
{
    unsigned short uni_num;                  /*uni侧成员数*/
    unsigned char uni_slot[16];              /*uni侧槽位信息*/
    unsigned char uni_port[16];              /*uni侧端口信息*/
    int uni_virtual_port_id[16];   /*uni侧逻辑接口信息*/

    unsigned short nni_num;                   /*nni侧成员数*/
    unsigned char nni_slot[64];              /*nni侧槽位信息*/
    unsigned char nni_port[64];              /*nni侧端口信息*/
    int nni_virtual_port_id[64];   /*nni侧逻辑接口信息*/
    int tuunel_label[64];          /*nni侧lsp标签信息*/
    int pw_label[64];              /*nni侧pw标签信息*/

}IGMPCFG;

/*****************
   oam 新增2015.9.11 dinghao
 ***************/

/*业务接口所提供的结构体*/
typedef struct service_info
{
    unsigned int VPN_ID;
    unsigned char type; /*1 VPWS 0 VPLS*/
    unsigned int v_port_id;
} SERVICE_INFO;

typedef struct vpls_service_info
{
    unsigned int VPN_ID; /*IP地址*/ //==VPLS_ID
    unsigned char type; //字节3：业务类型：0/1/2/3 =UNI-UNI/UNI-NNI/NNI-NNI/CES-NNI
    unsigned int v_port_id[20]; /*VLAN ID：0-4095*/ // nni[1-10]
} VPLS_SERVICE_INFO;

/*业务接口所提供的结构体*/
typedef struct vpws_info_t
{
    unsigned char type; /*0 表示UNI-UNI业务 1表示UNI-NNI业务*/
    unsigned char ctrl_word_en; /*0:不使能 1:使能*/ //2222

    //unsigned int label; /*不包括EXP TTL*/ //NNI使用[0]label是lsp//字节30~33：LSP_LABEL：16-1048575 lsp tx
    unsigned int pw; /*不包括EXP TTL*/ //字节435~438：发送PW标签：16-1048575
    unsigned short nni_sysportid; //虚拟子接口
    unsigned short uni_sysportid; //虚拟子接口
} VPWS_INFO_T;

typedef struct vpls_info_t
{
    unsigned char type; /*0 表示UNI-UNI业务 1表示UNI-NNI业务*/
    unsigned char ctrl_word_en; /*0:不使能 1:使能*/ //2222先赋 0

    //unsigned int label; /*不包括EXP TTL*/
    unsigned int pw; /*不包括EXP TTL*/ //字节435~438：发送PW标签：16-1048575
    unsigned short nni_sysportid; //取第一个
    unsigned short uni_sysportid[20]; //vpls 虚拟子接口 10个
} VPLS_INFO_T;

#pragma pack ()
#ifdef  __cplusplus
extern  "C"
{
#endif

/*****************************************************************************
   函 数 名  : del_vpws_cfg_list

   功能描述  : 删除配置时删除结点信息

   输入参数  : 无

   输出参数  : 无

   日    期   : 2015.7

   作    者   : zhangyh

   审 核 人   : #
   修改内容   : 新生成函数
 ******************************************************************************/
int del_vpws_cfg_list(unsigned short vpws_id);

/*****************************************************************************
   函 数 名  : del_port_aggr_cfg_list

   功能描述  : 删除配置时删除结点信息

   输入参数  : 无

   输出参数  : 无

   日    期   : 2015.7

   作    者   : zhangyh

   审 核 人   : #
   修改内容   : 新生成函数
 ******************************************************************************/
int del_port_aggr_cfg_list(unsigned short lagid);

int take_vpws_sem(void);
int give_vpws_sem(void);

int take_port_aggr_sem(void);
int give_port_aggr_sem(void);

int take_vpls_sem(void);
int give_vpls_sem(void);

int take_pve_sem(void);
int give_pve_sem(void);

int take_tx_lsp_sem(void);
int give_tx_lsp_sem(void);

int take_rx_lsp_sem(void);
int give_rx_lsp_sem(void);

int take_mpls_tp_oam_sem(void);
int give_mpls_tp_oam_sem(void);

int take_tunnel_protect_sem(void);
int give_tunnel_protect_sem(void);

int take_interface_phy_sem(void);
int give_interface_phy_sem(void);

extern PORT_CFG_NODE *g_port_cfg_node_head; /** ID 1物理口到sys口链表头**/
extern PTN_VIRTUAL_ID_NODE *g_ptn_virtual_node_head; /**ID 3物理口到sys口链表头**/
extern VPLS_VIRTUAL_ID_NODE *g_vpls_virtual_node_head; /**ID 4物理口到sys口链表头**/
extern VIRTUAL_PORT_MAP_CFG_NODE *g_virtual_port_map_node_head; /**ID 6物理口到sys口链表头**/
extern VPWS_CFG_NODE *g_vpws_cfg_node_head; // ID 8list
extern VPLS_CFG_NODE *g_vpls_cfg_node_head; //ID 9list
extern TX_LSP_CFG_NODE *g_tx_lsp_cfg_node_head; // ID 11list
extern TX_LSP_CFG_NODE *g_rx_lsp_cfg_node_head; //ID 10 list
extern PTN_QOS_MAP_NODE *g_ptn_qos_map_cfg_node_head; //list
extern MPLS_TP_OAM_NODE *g_mpls_tp_oam_node_head; //ID 19//list
extern INTERFACE_PHY_NODE *g_interface_phy_node_head; //ID 67list
extern PVE_INTERFACE_NODE *g_pve_interface_node_head; //ID 69list
extern PORT_LOGIC_CFG_NODE *g_port_logic_cfg_node_head; //ID 68 LIST
extern TUNNEL_PROTECT_NODE *g_tunnel_protect_cfg_node_head; //ID 29 LIST
extern PORT_AGGREGATE_CFG_NODE *g_port_aggr_cfg_node_head; //ID 2 list
extern ONDEMAND_OAM_CFG_NODE *g_ondemand_oam_cfg_node_head; //ID 21 list
extern PTN_GROUP_CFG_NODE *g_ptn_group_cfg_node_head; //ID 28 list

/******************************************************************************
** 函 数 名 ：find_key_list_vpws_cfg()
** 功能描述 ：查找链表，获取key值所在链表位置
** 输    入 ：key值
** 输    出 ：结构体指针
** 返    回 ：操作是否成功
** 作　  者 ：zhangyh
** 日　  期 ：2015.7
** 修　  改 ：首次创建
** 日　  期 ：2015.7
** 修改说明 ：无
** 备    注 : 无
** 版    本 ：1.0
*******************************************************************************/
VPWS_CFG_NODE *find_key_list_vpws_cfg(unsigned short vpws_id);

/******************************************************************************
** 函 数 名 ：find_key_list_virtual_port_map_cfg()
** 功能描述 ：查找链表，获取key值所在链表位置
** 输    入 ：key值
** 输    出 ：结构体指针
** 返    回 ：操作是否成功
** 作　  者 ：zhangyh
** 日　  期 ：2015.7
** 修　  改 ：首次创建
** 日　  期 ：2015.7
** 修改说明 ：无
** 备    注 : 无
** 版    本 ：1.0
*******************************************************************************/
VIRTUAL_PORT_MAP_CFG_NODE *find_key_list_virtual_port_map_cfg(unsigned short virtual_port_id);

/******************************************************************************
** 函 数 名 ：find_key_list_port_cfg()
** 功能描述 ：查找链表，获取key值所在链表位置
** 输    入 ：key值
** 输    出 ：结构体指针
** 返    回 ：操作是否成功
** 作　  者 ：zhangyh
** 日　  期 ：2015.7
** 修　  改 ：首次创建
** 日　  期 ：2015.7
** 修改说明 ：无
** 备    注 : 无
** 版    本 ：1.0
*******************************************************************************/
PTN_VIRTUAL_ID_NODE *find_key_list_lif_id_cfg(unsigned short vpws_id);

/******************************************************************************
** 函 数 名 ：find_key_list_ptn_qos_map_cfg()
** 功能描述 ：查找链表，获取key值所在链表位置
** 输    入 ：key值
** 输    出 ：结构体指针
** 返    回 ：操作是否成功
** 作　  者 ：zhangyh
** 日　  期 ：2015.7
** 修　  改 ：首次创建
** 日　  期 ：2015.7
** 修改说明 ：无
** 备    注 : 无
** 版    本 ：1.0
*******************************************************************************/
PTN_QOS_MAP_NODE *find_key_list_ptn_qos_map_cfg(unsigned char slot, unsigned short table_id);

/******************************************************************************
** 函 数 名 ：find_key_list_rx_lsp_cfg()
** 功能描述 ：查找链表，获取key值所在链表位置
** 输    入 ：key值
** 输    出 ：结构体指针
** 返    回 ：操作是否成功
** 作　  者 ：zhangyh
** 日　  期 ：2015.7
** 修　  改 ：首次创建
** 日　  期 ：2015.7
** 修改说明 ：无
** 备    注 : 无
** 版    本 ：1.0
*******************************************************************************/
TX_LSP_CFG_NODE *find_key_list_rx_lsp_cfg(unsigned int ingress, unsigned int egress, unsigned int lspid);

/******************************************************************************
** 函 数 名 ：find_key_list_vpls_cfg()
** 功能描述 ：查找链表，获取key值所在链表位置
** 输    入 ：key值
** 输    出 ：结构体指针
** 返    回 ：操作是否成功
** 作　  者 ：zhangyh
** 日　  期 ：2015.7
** 修　  改 ：首次创建
** 日　  期 ：2015.7
** 修改说明 ：无
** 备    注 : 无
** 版    本 ：1.0
*******************************************************************************/
VPLS_CFG_NODE *find_key_list_vpls_cfg(unsigned short vpls_id);

/******************************************************************************
** 函 数 名 ：find_key_list_rx_lsp_cfg()
** 功能描述 ：查找链表，获取key值所在链表位置
** 输    入 ：key值
** 输    出 ：结构体指针
** 返    回 ：操作是否成功
** 作　  者 ：zhangyh
** 日　  期 ：2015.7
** 修　  改 ：首次创建
** 日　  期 ：2015.7
** 修改说明 ：无
** 备    注 : 无
** 版    本 ：1.0
*******************************************************************************/
TX_LSP_CFG_NODE *find_key_list_rx_lsp_cfg(unsigned int ingress, unsigned int egress, unsigned int lspid);

/******************************************************************************
** 函 数 名 ：find_key_list_vpls_cfg()
** 功能描述 ：查找链表，获取key值所在链表位置
** 输    入 ：key值
** 输    出 ：结构体指针
** 返    回 ：操作是否成功
** 作　  者 ：zhangyh
** 日　  期 ：2015.7
** 修　  改 ：首次创建
** 日　  期 ：2015.7
** 修改说明 ：无
** 备    注 : 无
** 版    本 ：1.0
*******************************************************************************/
TX_LSP_CFG_NODE *find_key_list_tx_lsp_cfg(unsigned int ingress, unsigned int egress, unsigned int lspid);

/*******************************************************************************
   函数名：init_tp_cfg_module()
   功 能： 配置分发模块初始化函数
   输 入： mod = 0,上电初始化，resinfo可为NULL，mod=1时为升级，resinfo为保存数据buffer
   输 出： 无
   描 述： 完成模块变量初始化及链表创建
   例：
   作 者： zhangyh
   修 改： 创建
   时 间： 2015.6.30
*******************************************************************************/
int init_tp_cfg_module(int mod, unsigned char *resinfo);

/********************************
* 与升级不断业务相关的接口定义
   start
********************************/
int del_tp_cfg_task();

/********************************
* 与升级不断业务相关的接口定义
   start
********************************/

//升级不断业务接口函数
int free_tp_cfg_info(unsigned char *ptr, unsigned int *reslenth);

/************************************
   tpoam 接口

 **********************************/

/*****************************************************************************
   函 数 名  : oam_l2vpn_aps_info
   功能描述  : 根据oam_id返回l2vpn模块配置是否下发标志位信息
   输入参数  : oam_id 和 与该oam_id对应的aps信息(线性 或 环网)保存TPOAM_ID 对应的APS 类型，
   输出参数  : -1:查询失败，0/1 = 线性/环网
   返 回 值  :
   调用函数  :
   被调函数  :

   修改历史	   :
   1.日	  期   : 2015年6月30日
        作	  者   : zhangyh
        修改内容   : 新生成函数
        说	  明   :

*****************************************************************************/
extern int oam_l2vpn_aps_info(unsigned short oam_id);

/*************************************************************************
* 函数名         ：tp_oam_get_traffic
* 负责人         ：
* 创建日期：
* 函数功能：获取tpoam 需要的业务信息
* 输入参数：tpoam_id:网管下发的id
                     type:0/1/2/3=无/vs/vp/vc
* 输出参数：*LspRxCfg: 业务的相关信息
* 返回值         ：0/非0 =成功/不成功
* 调用关系：供tpoam模块调用
* 其   它        ：1，可查普通业务,也可查带保护的业务。
                     2，仅限vpws 业务类型。
                     3，保护目前只支持lsp1:1和pw1:1保护
*************************************************************************/
int tp_oam_get_traffic(unsigned short tpoam_id, unsigned char type, TPOAMLSPCFG *LspRxCfg);

/*************************************************************************
* 函数名         ：tpoam_get_service_info
* 负责人         ：
* 创建日期：
* 函数功能：获取tpoam     需要的业务信息
* 输入参数：lsp_id: 应用层分配的lsp_id,取值1 ~ MAX_LSP_NUM
* 输出参数：*cfg: tpoam 需要的配置
* 返回值         ：0/非0: 成功/不成功
* 调用关系：
* 其   它        ：
*************************************************************************/

//int tpoam_get_service_info(unsigned int lsp_id, TPOAMINFO *cfg);

/*************************************************************************
* 函数名         ：tpoam_get_service_info_plus
* 负责人         ：
* 创建日期：
* 函数功能：获取tpoam     需要的业务信息
* 输入参数：vc_id: 应用层分配的vc_id,取值1 ~ MAX_VC_NUM
* 输出参数：*cfg: tpoam 需要的配置
* 返回值         ：0/非0: 成功/不成功
* 调用关系：
* 其   它        ：
*************************************************************************/

//int tpoam_get_service_info_plus(unsigned int vc_id, TPOAMINFO *cfg);
void get_tpoam_sysport_id(unsigned char slot, unsigned char port, unsigned short vlan, unsigned short *sysportid);

//portnum= 0-;sysport:支路盘盘为该物理端口对应的sysportid，线路盘为该物理端口查找到的第一条业务的sysport
//int get_sysport_from_portnum(unsigned char portnum,unsigned short &sysport);

/*************************************

   QOS 接口

*************************************/

/*
        查询KEY值：port
   *qos_behavior_id: QOS动作模板ID
   *shedule_temp_id: 队列调度模板ID
   *congestion_temp_id: 拥塞策略模板ID
 */
int qos_get_port_cfg(unsigned char port,
    unsigned short *qos_behavior_id,
    unsigned short *shedule_temp_id,
    unsigned short *congestion_temp_id);

/*
   查询KEY值：lif id
   *is_uni_lif：UNI or NNI标识
   *qos_behavior_temp_id：QOS动作模板ID

 */

//int qos_flow_cfg_process(unsigned short lif_id, unsigned char *is_uni_lif, unsigned short *qos_behavior_temp_id);
int qos_get_flow_cfg(unsigned short lif_id, unsigned char *is_uni_lif, unsigned short *qos_behavior_temp_id);

/*
   查询KEY值：temp_id
   *map_id_out: 结果输出结构体
   QOS_MAP_TEMPLATE参考后面结构体定义

 */

//int qos_get_map_id_from_template_id(unsigned short temp_id, QOS_MAP_TEMPLATE_CFG *map_id_out);
int vpls_get_igmp_cfg(unsigned short vpls_id, unsigned char *enable, IGMPCFG *vpls_cfg);

/*
   由配置分发维护数据链表，存储端口下所有PTN业务的出口 slot & port。数据结构体参考后面代码
   QOS_PORT_FLOW_INFO_HEAD &
   QOS_PORT_FLOW_INFO 参考后面结构体定义
 */
extern QOS_PORT_FLOW_INFO_HEAD g_qos_port_flow_info[PORT_MAX];

/*************************************************************************
* 函数功能：vpws虚拟子接口映射配置处理函数
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：无
*************************************************************************/
int tp_lif_id_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/*************************************************************************
* 函数功能：物理端口配置处理函数
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：无
*************************************************************************/
int tp_port_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/*************************************************************************
* 函数功能：vpls虚拟子接口映射配置处理函数
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：无
*************************************************************************/
int tp_vpls_lif_id_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/*************************************************************************
* 函数功能：虚拟子接口配置处理函数
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：无
*************************************************************************/
int tp_virtual_port_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/*************************************************************************
* 函数功能：vpws业务配置处理函数
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：无
*************************************************************************/
int tp_vpws_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/*************************************************************************
* 函数功能：vpws业务配置处理函数
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：无
*************************************************************************/
int tp_vpls_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/*************************************************************************
* 函数功能：后向lsp配置处理函数
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：暂不使用
*************************************************************************/
int tp_lsp_rx_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/*************************************************************************
* 函数功能：前向lsp配置处理函数
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：暂不使用
*************************************************************************/
int tp_lsp_tx_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/*38*/
int usr_qos_template_process(unsigned char * *ucConfData, unsigned char message);

/******************************************************************************
** 函 数 名 ：find_key_list_interface_phy_cfg()
** 功能描述 ：查找链表，获取key值所在链表位置
** 输    入 ：key值
** 输    出 ：结构体指针
** 返    回 ：操作是否成功
** 作　  者 ：zhangyh
** 日　  期 ：2015.7
** 修　  改 ：首次创建
** 日　  期 ：2015.7
** 修改说明 ：无
** 备    注 : 无
** 版    本 ：1.0
*******************************************************************************/
INTERFACE_PHY_NODE *find_key_list_interface_phy_cfg(unsigned int index);

/*************************************************************************
* 函数功能：接口物理配置处理函数 ID 67
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：暂不使用
*************************************************************************/
int tp_interface_phy_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/******************************************************************************
** 函 数 名 ：find_key_list_port_aggr_cfg()
** 功能描述 ：查找链表，获取key值所在链表位置
** 输    入 ：key值
** 输    出 ：结构体指针
** 返    回 ：操作是否成功
** 作　  者 ：zhangyh
** 日　  期 ：2015.7
** 修　  改 ：首次创建
** 日　  期 ：2015.7
** 修改说明 ：无
** 备    注 : 无
** 版    本 ：1.0
*******************************************************************************/
PORT_AGGREGATE_CFG_NODE *find_key_list_port_aggr_cfg(unsigned short lagid);

/*************************************************************************
* 函数功能：接口物理配置处理函数 ID 2
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：暂不使用
*************************************************************************/
int tp_port_aggr_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/******************************************************************************
** 函 数 名 ：find_key_list_pve_interface_cfg()
** 功能描述 ：查找链表，获取key值所在链表位置
** 输    入 ：key值
** 输    出 ：结构体指针
** 返    回 ：操作是否成功g_mpls_tp_oam_node_head
** 作　  者 ：zhangyh
** 日　  期 ：2015.7
** 修　  改 ：首次创建
** 日　  期 ：2015.7
** 修改说明 ：无
** 备    注 : 无
** 版    本 ：1.0
*******************************************************************************/
PVE_INTERFACE_NODE *find_key_list_pve_interface_cfg(unsigned int pve_id);

/*************************************************************************
* 函数功能：接口物理配置处理函数 ID 69
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：暂不使用
*************************************************************************/
int tp_pve_interface_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/******************************************************************************
** 函 数 名 ：find_key_list_mpls_tp_oam_cfg()
** 功能描述 ：查找链表，获取key值所在链表位置
** 输    入 ：key值
** 输    出 ：结构体指针
** 返    回 ：操作是否成功g_mpls_tp_oam_node_head
** 作　  者 ：zhangyh
** 日　  期 ：2015.7
** 修　  改 ：首次创建
** 日　  期 ：2015.7
** 修改说明 ：无
** 备    注 : 无
** 版    本 ：1.0
*******************************************************************************/
MPLS_TP_OAM_NODE *find_key_list_mpls_tp_oam_cfg(unsigned short oam_id);

/*************************************************************************
* 函数功能：接口物理配置处理函数 ID 19
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：暂不使用
*************************************************************************/
int tp_mpls_tp_oam_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/******************************************************************************
** 函 数 名 ：find_key_list_port_logic_cfg()
** 功能描述 ：查找链表，获取key值所在链表位置
** 输    入 ：key值
** 输    出 ：结构体指针
** 返    回 ：操作是否成功
** 作　  者 ：zhangyh
** 日　  期 ：2015.7
** 修　  改 ：首次创建
** 日　  期 ：2015.7
** 修改说明 ：无
** 备    注 : 无
** 版    本 ：1.0
*******************************************************************************/
PORT_LOGIC_CFG_NODE *find_key_list_port_logic_cfg(unsigned int index);

/*************************************************************************
* 函数功能：接口物理配置处理函数 ID 68
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：暂不使用
*************************************************************************/
int tp_port_logic_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/*************************************************************************
* 函数功能：接口物理配置处理函数 ID 29
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：暂不使用
*************************************************************************/
int tp_tunnel_protect_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/*************************************************************************
* 函数功能：接口物理配置处理函数 ID 28
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：暂不使用
*************************************************************************/

int tp_ptn_group_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

/*************************************************************************
* 函数功能：接口物理配置处理函数 ID 21
* 参         数：无
* 返　　回：无
* 使用说明：和cfg_process配合使用
* 注意事项：暂不使用
*************************************************************************/
int tp_ondemand_oam_cfg_process(unsigned char * *ucConfData, unsigned char msgType);

#ifdef  __cplusplus
}
#endif

#endif

