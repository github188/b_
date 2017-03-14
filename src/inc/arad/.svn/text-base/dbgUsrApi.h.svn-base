/*****************************************************************************
*  Copyright (C), 2002-2015, Wuhan FiberHome Tech. Co., Ltd.
*  File name      :   dbgUsrApi.h   
*  Author         :  张珠玲      
*  Version        :  v1.1    
*  Date           :  2012.02.27
*  Description    :  PP应用层接口头文件
*                         
*  Others         :   
*  History         : 修改历史记录列表
*	1. Date:    2014.05.1
*	   Author:  张珠玲
*	   Modification: first in
*	2. ...
*
******************************************************************************/

#ifndef DBG_USR_API_H
#define DBG_USR_API_H

#define NEW_SERVICE_MODE   /*151109  hmliu*/
#define MCC_LSR_INTF_ID			2040    /*160308 hmliu*/
#include "ppUsrApi.h"
/*
   作者:张珠玲

   时间:20121112
   修改记录:1112添加is_disable_learning 、 is_hub、is_lag、lag_id成员；
   20121129 增加hash的类别；20121129增加api_pp_prog_trap_DA_set

 */
#define MAX_SYS_PORT_1_CARD     168
#define ABOVE_LAG_SYS_PORT     49152
#define VLAN_2_LAYER
#define TUNNEL_2_LAYER
#define VPLS_MAX_LIF_NUM    20
#define P2P_MAX_LIF_NUM      3 /*有保护时为3，一般为2*/
#define  VPLS_SERVICE_TYPE              0
#define  VPWS_SERVICE_TYPE              1
#define  LSR_SERVICE_TYPE               2   /*交换tunnel*/
#define  LSR_SERVICE_SWAP_TUL_PWE_TYPE       3  /*20141008 add zzl 交换tunnel和pwe*/
#define  ETH_P2P_SERVICE                4   /* AC到AC 纯以太网业务 使用新的建半边业务模型*/
#define  ETH_P2MP_SERVICE               5   /* 纯AC的点到多点业务 */
#define	VC_P2P_SERVICE						 6	  /* VC的点到点业务 */

#define VPN_NUM 0x4000 /*检测vpn_lif_chain_info_s数组是否越界*/
#define FPGA_PORT 164

/*20121112 zzl*/
#define HASH_PWE_DMAC    0
#define HASH_PWE_SMAC    1
#define HASH_PWE_DMAC_SMAC   2
#define HASH_AC_DMAC   3
#define HASH_AC_SMAC 4
#define HASH_AC_DMAC_SMAC   5
#define HASH_PWE_LABEL 6
#define HASH_IPV4_SIP 7
#define HASH_IPV4_DIP 8


#define  MIN_LIF_ID        1
#define  MAX_LIF_ID        0x4000/*0X4000 0xa000 20140911 modify ETH 1:1 需要4k个保护组zzl*/   /*0X2000  120927  zzl*/
#define LIF_ID_IN_USE 1
#define VPN_IN_USE 2
#define CREATE_ERROR 3
#define QOS_PROFILE 15
#define MIRROR_ID_BASE 0x3C000000
#define MIRROR_ID_MAX 7/*mirror 资源上应为1-15，因bcm_oam_init占用了10-15，故最大只有9*/



#define TUNNEL_EEP_BASE 0x4000a000 /*0x40005000 *//*0x40007000 20140729 zzl 配合测试8k条业务为临时版本 tunnel-eep暂与pwe关联，改为0x5000 */
#define LL_EEP 0x40007000 /* 0x40004000*/ /*0x40009000*/

#define PWE_PRO_BASE /**/0x18000400
#define AC_PRO_BASE 0x44000400/*20140910 add zzl*/
#define EGRESS_IF_BASE 0x20000400



/***********************************************************************************************/



#define SELF_CFG_FEC_BASE	 0x20000400
#define GLOBAL_CFG_FEC_BASE	 0x20002400

#define VIRTUAL_PWE_BASE 		0x18000000
#define VIRTUAL_ACE_BASE 		0x44000000    /*hmliu 160624*/




#define AC_LIF_BASE 			0x44801000
#define TUNNEL_INTF_ENCAP_BASE 	0x40004000   /*0x40000x5000 20160920 hl *//*0x40003000 160510 160411 hl  
                                                0x40004000 hmliu 160329  *//* 0x40003000 150901  hmliu*/  
#define PWE_LIF_BASE 			0x18802000 		/* 151204 0x1880a000  hl*/
#define L3_LL_ENCAP_BASE 		0x40006000		/*0x40004000 20160920 hl *//* 160329 0x40008000  hl*/ /* 151204 0x40005000  hl*/
#define POP_LIF_OUT_BASE 		0x4c00e000   /*0x4c00e000*/
#define TUNNEL_OAM_ENCAP_BASE 	0x4000  /*0x5000 20160920 hl *//*0x3000 160518 160411 hl 0x4000  hmliu 160329*/


#define SET_ENCAP_FLAG 		0x30000000
#define SET_FEC_FLAG 		0x98000000
#define SET_FEC_FLAG 		0x98000000

#define MASK_MAX_ID 		0xffff

#define POP_LIF_INNER_BASE 0x4c00e000/*0x4c00f000*/

#define PWE_LIF_LM_COUNTER_ID_BASE 		0X800  /*151221  hmliu */

#define LSP_LIF_LM_COUNTER_ID_BASE 		0X1000  /*151221  hmliu */

#define AC_LIF_LM_COUNTER_ID_BASE 	 	0x0

#define UINT32_BIT_WIDTH    32  /*sizeof int*/
#define UINT16_BIT_WIDTH    16  /*sizeof int*/

#define API_MEP_NUM         8000 
#define API_PORT_NUM       100
#define EPNI_MPLS_PUSH_FORMAT_M 1223
#define IHB_FWD_ACT_PROFILE_M 2671  /*160222 tp ccm*/
#define OAM_FAP_NUM_LIMIT       13

/***********************************************************************************************/


#define MAX_LAG_GROUP	512			/*160422 hmliu*/
#define MAX_LAG_MEM	20			/*161012 hl*/









#define VPWS_VPN_ID 0x4000
#define VPLS_VPN_ID 0x1000
#define MEP_ID_MAX	0x1000
#define PROTECT_MC_BASE   0    /*160509 0x2000 151213  hmliu*/


#define MATCH_PORT_VLAN 1
#define MATCH_PORT_2_VLAN 2
#define MATCH_PVID 3

#define LMM_TX_OFFSET 22
#define LMM_RX_OFFSET 26
#define LMR_TX_OFFSET 30

#define IDM_TX_OFFSET 22
#define IDM_RX_OFFSET 34
#define DMM_TX_OFFSET 22
#define DMM_RX_OFFSET 34
#define DMR_TX_OFFSET 38
#define DMR_RX_OFFSET 50

#define OAM_ETH_PDU_OPCODE_APS39 39 
#define OAM_ETH_PDU_OPCODE_AIS 33
#define OAM_ETH_PDU_OPCODE_LCK 35
#define OAM_ETH_PDU_OPCODE_CCM 1
#define OAM_ETH_PDU_OPCODE_LBR 2
#define OAM_ETH_PDU_OPCODE_LBM 3
#define OAM_ETH_PDU_OPCODE_LTR 4
#define OAM_ETH_PDU_OPCODE_LTM 5
#define OAM_ETH_PDU_OPCODE_AIS 33
#define OAM_ETH_PDU_OPCODE_TST 37
#define OAM_ETH_PDU_OPCODE_APS40 40
#define OAM_ETH_PDU_OPCODE_MCC 41
#define OAM_ETH_PDU_OPCODE_LMR 42
#define OAM_ETH_PDU_OPCODE_LMM 43
#define OAM_ETH_PDU_OPCODE_1DM 45
#define OAM_ETH_PDU_OPCODE_DMR 46
#define OAM_ETH_PDU_OPCODE_DMM 47

#define MAX_MEP_ID	1000
#define OAM_MISMATCH_TASK_PRI 255
#define OAM_MISMATCH_TASK_STACK_SIZE 6000

#if 0
#define MPLS_EG_MAP_ID 0x20040000/*0x20040001*/
#define INGRESS_MAP_ID 0x10020000/*0x10020001*/
#define L2_EG_MAP_ID 0x20010000/*0x20010004*/
#define MPLS_INGRESS_MAP_ID 0x10020015/*0x10020009*/
#endif 

#define REG_VAL_SIZE 20

struct vpn_protect_info_s/*20140612 add zzl*/
{
	unsigned int mc_modport_primary;
    unsigned int mc_modport_backup;
    unsigned int mc_encapid_primary;
    unsigned int mc_encapid_backup;
	unsigned int failover_id;
	unsigned int lif_tbl_info_primary;/*20140616 add zzl*/
	unsigned int lif_tbl_info_backup;
};




/*****************************************************************************
   枚 举 名  : api_error_e
   功能描述  : 函数返回错误类型定义
*****************************************************************************/    
typedef enum api_error_e
{
    API_E_NONE = 0,    /*正常*/
    API_E_INTERNAL = -1001, /*INTERNAL*/
    API_E_MEMORY = -1002, /*MEMORY*/
    API_E_UNIT = -1003, /*UNIT*/
    API_E_PARAM = -1004, /*参数错误*/
    API_E_EMPTY = -1005, /*空*/
    API_E_FULL = -1006, /*已满*/
    API_E_NOT_FOUND = -1007, /*未找到*/
    API_E_EXISTS = -1008, /*已存在*/
    API_E_TIMEOUT = -1009, /*超时*/
    API_E_BUSY = -1010, /*忙*/
    API_E_FAIL = -1011, /*失败*/
    API_E_DISABLED = -1012, /*未使能*/
    API_E_BADID = -1013, /*错误ID*/
    API_E_RESOURCE = -1014, /*RESOURCE*/
    API_E_CONFIG = -1015, /*CONFIG*/
    API_E_UNAVAIL = -1016, /*UNAVAIL*/
    API_E_INIT = -1017, /*未初始化*/
    API_E_PORT = -1018, /*PORT*/
    API_E_LIMIT = -1019    /* Must come last */
    
}API_ERROR_E;

struct business_info_note
{
	int vpn_create;
	int service;
	int ac_lif_create;
	int ac_lif_id;
	int ac_del;
	int pwe_lif_create;
	int pwe_lif_id;
	int pwe_del;
	int fail_flag;
};


/*vpn lif 信息*/
struct vpn_lif_chain_info_s
{
    struct vpn_lif_info_s *p_port_info;
    int num;
    unsigned char is_created;

    /*unsigned int mc_modport_primary;
    unsigned int mc_modport_backup;
    unsigned int mc_encapid_primary;
    unsigned int mc_encapid_backup;20140612 dele zzl*/

    struct vpn_protect_info_s *protect_info;/*20140612 add zzl*/
    unsigned int failover_id;
    unsigned int lsp_1plus1_backup_0;
    unsigned int lsp_1plus1_backup_1;
    unsigned int lsp_1plus1_primary_0;
    unsigned int lsp_1plus1_primary_1;

    unsigned int sncp_1plus1_key_tunnel_primary;
    unsigned int sncp_1plus1_key_tunnel_backup;
    unsigned int sncp_1plus1_encap_tunnel;
    unsigned int sncp_1plus1_no_protect_egress_id;

    // unsigned int sncp_1plus1_mc_id;

    /*unsigned int uni_lif_info[16][3];20121220 zzl*/
    unsigned char create_fail;

};

/*vswitch 信息*/
struct vswitch_info_s
{
    int p1; /* phy port */
    int p1_out_vid; /* outer vlan */
    int p1_in_vid;  /* inner vlan */

    int p2;   /* phy port */
    int p2_out_vid; /* outer vlan */
    int p2_in_vid;  /* inner vlan */
};

/*tpid 信息*/
struct port_tpid_info_s
{
    int port;
    int outer_tpids[2];
    int nof_outers; /*0, 1,2*/
    int inner_tpids[2];
    int nof_inners; /*0, 1 */
    int discard_frames; /* BCM_PORT_DISCARD_NONE/ALL/UNTAG/TAG */
};

/*mpls 信息*/
struct mpls_lsr_info_s
{
    int in_port;   /* phy port */

    /* ingress interface attributes */
    int vid; /* outer vlan */
    uint8 my_mac[6];
    int in_label; /* incomming */

    /* egress -attributes */
    int eg_port;   /* phy port */
    int eg_label; /* egress label */
    int eg_vid;
    bcm_mac_t next_hop_mac;
    int out_to_tunnel; /* If enable, gets out to Tunnel */
};

/*Vswitch_vpls 的信息*/
struct vswitch_vpls_info_s
{

    int in_vc_label; /* incomming VC label */
    int eg_vc_label; /* egress VC label */
    int ac_in_port;  /* accesss port: physical port connect to customer */
    int pwe_in_port; /* network port: physical port connect to MPLs network*/

    bcm_vpn_t vpn_id; /* VPN id to open */

    /* tunnels info */
    int in_tunnel_label;
    int out_tunnel_label;

    int encap_in_tunnel_label;
    int encap_out_tunnel_label;

    int ac_port1_outer_vlan;
    int ac_port1_inner_vlan;
    int ac_port2_outer_vlan;
    int ac_port2_inner_vlan;
    int encap_ac_outer_vlan;
    int encap_ac_inner_vlan;
    int encap_pipe_exp;

};

/*存放vpn 及egress intf*/
struct vswitch_vpls_shared_info_s
{

    /* don't modify used by script*/
    int egress_intf;
    int egress_intf2;
    uint16 vpn;
    uint16 vpn_2;

};

/*20150209 add zzl 分组倒换增加*/
typedef struct tagPRO_FAILOVER_INFO
{
    unsigned int fec;
	unsigned int sysport;
	unsigned int tunnel_label;
	unsigned int failover_group_id;
	unsigned int failover_single_id;
	
}PRO_FAILOVER_INFO;

/* 陈舸增加 移动集采测试 1+1 保护 保存sysport到lifid的关系 */
typedef struct sysport_2_lif
{
	int sysport;
	bcm_port_t lifid;
}sysport_2_lif_t;

typedef struct vpn_2_sysport
{
	int vpn;
	int sysport;
}vpn_2_sysport_t;

typedef struct vpn_2_lifBaseId
{
	int vpn;
	int lifBaseId;
}vpn_2_lifBaseId_t;

/* end 陈舸添加  2015.6.30 */

/* tunnel引用计数结构体 陈舸 2015.12.29 */
typedef struct tunnel_ref_count
{
	//long long tunnel_label;    /* tunnel 标签值 */
	int refence_count;         /* 引用计数 */
}tunnel_ref_count_t;

extern int isCwAdd;                             /* comment */
extern int protect_pwe_eep;                     /* 保护pwe eep */
extern unsigned char is_disable_learning_temp;  /* 去使能学习 */

extern int l2_ingress_id_map;       /*l2 ingress*/
extern int mpls_ingress_id_map;     /*mpls/tunnel ingress*/
extern int l2_engress_id_map;       /*l2 engress*/
extern int mpls_engress_id_map;     /*mpls/tunnel engress*/
extern int lsr_ingress_id_map;      /*lsr ingress*/
extern int lsr_engress_id_map;      /*lsr engress*/


extern int open_ingress_mc_group(int unit, int mc_group_id);

extern int multicast_mpls_port_add(int unit, int mc_group_id, int sys_port, int gport);
extern void setPortVlanDomain(int unit,int start , int end, int share_vlan_domain);
extern int mpls_add_pop_entry(int unit, int in_label, int label_index, int tunnel_eep); /*20130520 zzl 增加labelindex*/

extern int32 dbg_qos_set_pcp_ingress(int unit,unsigned char profile);
extern int32 dbg_qos_set_pcp_egress(int unit,unsigned char profile);
extern int32 dbg_qos_set_exp_ingress(int unit,unsigned char profile);
extern int32 dbg_qos_set_exp_egress(int unit,unsigned char profile);
extern void fap_oam_reg_mis(void);

void save_vpn_to_sysport(int vpn, int sysport);
void save_lifid_to_sysport(bcm_gport_t lifid, int sysport);
int find_lifid_with_sysport(int sysport, int *index);
int find_sysport_with_vpn(int vpn);

/* 新增增加时延的应用层接口 */
int init_set_test_delay_port_lb_5tn4(void); /* 配置业务前调用 */
int show_test_sysport_pair(void);  /* 调试函数, 查看面板的5个端口所对应的环回口的sysport */
int set_test_delay_enable(int enable);  /* 设1为开启增加时延的测试 0为关闭 */

struct local_port_cfg_t
{
    bcm_gport_t ingress_mirror_dst_port;
    bcm_gport_t egress_mirror_dst_port;
    bcm_gport_t ingress_mirror_dst_id;
    bcm_gport_t egress_mirror_dst_id;
};

typedef struct local_port_cfg_t PORT_CFG_T;



//记录port 属性
struct fap_port_info_s
{
    uint16 outer_tpid;
    uint16 inner_tpid;
    uint16 pvid;
    uint16 class_id;
	 uint8 smac[6];
	 uint8 dmac[6];
	 uint8 lag_id;
	 uint8 is_nni;
    uint16 ignore_incoming_tag;
    uint16 untag_default_action;
    uint16 ctag_default_action;
    uint16 stag_default_action;
    uint16 sctag_default_action;
	 uint8 tunnel_intf[0x1000];
};

struct oam_mep_info_s
{
	MEP_INFO_S tMep[API_MEP_NUM + 1];
	uint32 usedFlag[API_MEP_NUM / 32 + 1];       /*使用标志位*/
	uint32 vpGroupUsedFlag[API_MEP_NUM / 32 + 1];       /*使用标志位*/
	uint32 vcGroupUsedFlag[API_MEP_NUM / 32 + 1];       /*使用标志位*/
	uint32 vpPortUsedFlag[API_MEP_NUM / 32 + 1];       /*使用标志位*/
	uint32 vcPortUsedFlag[API_MEP_NUM / 32 + 1];       /*使用标志位*/
	uint32 vpPort[API_MEP_NUM + 1];
	uint32 vcPort[API_MEP_NUM + 1];
	uint32 portUsedTotal; 
    uint32 usedTotal;     
    uint32 gMepId[API_MEP_NUM + 1];                     /*使用总数*/
}PACKED;
typedef struct oam_mep_info_s OAM_MEP_INFO_S;

/* Specific operations */
/* 设置/获取/清除l2/l3软表占用情况bitmap*/
#define API_C3_SHR_BITGET(_a, _b)    (_a[(_b) / UINT32_BIT_WIDTH] & (1U << ((_b) % UINT32_BIT_WIDTH)))      
#define API_C3_SHR_BITSET(_a, _b)    (_a[(_b) / UINT32_BIT_WIDTH] |= (1U << ((_b) % UINT32_BIT_WIDTH)))     
#define API_C3_SHR_BITCLR(_a, _b)    (_a[(_b) / UINT32_BIT_WIDTH] &= ~(1U << ((_b) % UINT32_BIT_WIDTH)))   
#define API_C3_SHR_BITCKA(_a, _b)    (_a[(_b) / UINT32_BIT_WIDTH] | ((1U << ((_b) % UINT32_BIT_WIDTH)) - 1))
#define API_C3_SHR_BITCKB(_a, _b)    (_a[(_b) / UINT32_BIT_WIDTH] \
	| ~(0xffffffff >> (UINT32_BIT_WIDTH - 1 - (_b) % UINT32_BIT_WIDTH)))

//强制要求id必须为有符号数
/*查找l2/l3软表中可用id*/
/*
   *a:bitmap地址
   *b:返回可用bit位置
   *start:查找起始位置
   *end:查找接收位置
 */
#define API_C3_SHR_POSFIND(_a, _b, _start, _end)     \
    if ((_start) <= (_end))                          \
    {                                                \
        if (API_C3_SHR_BITCKA(_a, _b) == 0xffffffff) \
        {                                            \
            (_b) = 32 * ((_b) / 32 + 1);             \
        }                                            \
        while (((_b) < (_end))                       \
            && (_a[(_b) / 32] == 0xffffffff))     \
        {                                            \
            (_b) += 32;                              \
        }                                            \
        while ((API_C3_SHR_BITGET(_a, (_b)))         \
            && ((_b) < (_end)))                   \
        {                                            \
            (_b)++;                                  \
        }                                            \
    }                                                \
    else                                             \
    {                                                \
        if (API_C3_SHR_BITCKB(_a, _b) == 0xffffffff) \
        {                                            \
            (_b) = (32 * ((_b) / 32) - 1);           \
        }                                            \
        while (((_b) >= (_end))                      \
            && (_a[(_b) / 32] == 0xffffffff))     \
        {                                            \
            (_b) -= 32;                              \
        }                                            \
        while ((API_C3_SHR_BITGET(_a, (_b)))         \
            && ((_b) >= (_end)))                  \
        {                                            \
            (_b)--;                                  \
        }                                            \
    }



#endif

