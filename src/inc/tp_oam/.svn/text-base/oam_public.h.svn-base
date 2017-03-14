/******************************************************************************

	Copyright (C), 2002-2010, Wuhan FiberHome Tech. Co., Ltd.

 ******************************************************************************
  文 件 名   : oam_public.h
  版 本 号   : 初稿
  作    者   : 丁浩
  生成日期   : 2015年3月30日
  功能描述   : oam各模块公共宏定义和结构体定义
  修改历史   :
  1.日    期   : 2015年3月30日
    作    者   : 丁浩   
    修改内容   : 创建文件

******************************************************************************/
#ifndef __OAM_PUBLIC_H_
#define __OAM_PUBLIC_H_

#include "tp_cfg.h"
#include "bmuInclude.h"

//#include "bmu_bep.h"


//#define OAM_DEBUG

/*按照最新的FPGA文件新增宏*/
#define CFM 6
#define CFM_UP 7
#define CFM_DOWN 8

#define TP_OAM 5
#define TP_OAM_VP 1
#define TP_OAM_VC 2
#define TP_OAM_VS 3
#define TP_OAM_WRAPPING 4

/*区别TP和CFM*/
#define TP_OAM_TYPE 1
#define CFM_OAM_TYPE 2


#define FRAME_TYPE_FDI 1
#define FRAME_TYPE_CV_APS_CSF 2
#define FRAME_TYPE_LB 3
#define FRAME_TYPE_TST 4
#define FRAME_TYPE_LCK 5
#define FRAME_TYPE_LMM 6
#define FRAME_TYPE_LMR 7
#define FRAME_TYPE_DMM 8
#define FRAME_TYPE_DMR 9

/*
发帧层次，
   其中3'b000为8847+TUNL+PW+ACH
   3'b001为8092
   3'b010为8100+vlan+8902
   3'b011为8100+vlan+8100+vlan+8902
   3'b100为8100+vlan+XXXX+vlan+      
            8100+ vlan+8902；
*/
#define FRAME_TP_OAM 0 
#define FRAME_CFM_NO_VLAN 1
#define FRAME_CFM_ONE_VLAN 2
#define FRAME_CFM_TWO_VLAN 3
#define FRAME_CFM_THREE_VLAN 4


/*公共宏定义*/
#define SUCCESS 0
#define ERROR -1

/*OAM创建标志位*/
#define OAM_UN_CREATE 0
#define OAM_CREATE_SUCCESS 1
#define OAM_CREATE_TRAFFIC_FAIL 2  
#define OAM_CREATE_GROUP_FAIL  3
#define OAM_CREATE_MEP_FAIL 4

/*OAM删除标志位*/
#define OAM_DELETE_OK 5
#define OAM_DELETE_MEP_FAIL 6
#define OAM_DELETE_GROUP_FAIL 7


#define OAM_LEVEL_VS        0
#define OAM_LEVEL_VP        1 
#define OAM_LEVEL_VC        2
#define OAM_LEVEL_OTHER     3

#define MAX_GLOBAL_OAM_NUM (1024 * 16)  /*当前网元支持oam id的最大*/
#define MAX_FPGA_ITEM_NUM 2047
#define MAX_ON_DEMAND_ID    16
#define MAX_SLOT_NUM_U60 64

#define MAX_DRV_GROUP_ID_NUM 8000


/*不同业务类型宏定义，用于oam查找业务信息*/
#define OAM_MEP_VP_TRAFFIC 1
#define OAM_MEP_VC_TRAFFIC 2
#define OAM_MIP_LSR_TRAFFIC 3
#define OAM_MIP_MSPW_TRAFFIC 4

/*单盘代码枚举，区分单盘,公用*/
#define  POTS_BOARD_NULL              0     /*POTS_BOARD_NULL*/
#define  POTS_BOARD_4TN2              1     /*POTS_BOARD_4TN2*/
#define  POTS_BOARD_10TP2            2     /*POTS_BOARD_10TP2*/
#define  POTS_BOARD_20TP2            3     /*POTS_BOARD_20TP2*/
#define  POTS_BOARD_16TN1T          4     /*POTS_BOARD_16TN1T*/
#define  POTS_BOARD_1TN4             5     /*POTS_BOARD_1TN4*/
#define  POTS_BOARD_2TN3             6     /*POTS_BOARD_2TN3*/
#define  POTS_BOARD_2TN4             7     /*POTS_BOARD_2TN4*/
#define  POTS_BOARD_4TN2A           8     /*POTS_BOARD_4TN2A*/
#define  POTS_BOARD_8TN1             9     /*POTS_BOARD_8TN1*/
#define  POTS_BOARD_12TN2           10   /*POTS_BOARD_12TN2*/
#define  POTS_BOARD_16TN1A         11   /*POTS_BOARD_16TN1A*/
#define  POTS_BOARD_1TN3             12   /*POTS_BOARD_1TN3*/
#define  POTS_BOARD_12LN2           13   /*POTS_BOARD_12LN2*/
#define  POTS_BOARD_8TP2             14   /*POTS_BOARD_8TP2*/
#define  POTS_BOARD_10TN2           15   /*POTS_BOARD_10TN2*/
#define  POTS_BOARD_8TN2             16   /*POTS_BOARD_8TN2*/
#define  POTS_BOARD_4LN2             17   /*POTS_BOARD_4LN2*/ 
#define  POTS_BOARD_1LN4             18   /*POTS_BOARD_1LN4*/ 
#define  POTS_BOARD_2LN4             19   /*POTS_BOARD_2LN4*/ 
#define  POTS_BOARD_20TN2           20   /*POTS_BOARD_20TN2*/
#define  POTS_BOARD_10IL2            21   /*POTS_BOARD_10IL2*/
#define  POTS_BOARD_16TN1           22   /*16TN1（pmc版）测试用*/
#define  POTS_BOARD_5TN3             23   /*new add 2015年10月13日*/

#define FRAME_U10 4  /*U10同C400*/
#define FRAME_U20 2  
#define FRAME_U30 6
#define FRAME_U40 0
#define FRAME_U60 7  /*U60同C700*/

#define STRING_LEN (30)
#define TP_OAM_LOG_DIR     "../log/tpoam.log"
#define TP_OAM_ERROR_MSG_LEN 300

#define PVE_MODE_OAM 1
#define PHY_MODE_OAM 2

/*公共结构体定义*/
typedef struct  rx_label_cfg
{
    unsigned int uiLspRxLabel;  /*兼Lsp和tunnel标签*/
    unsigned int uiPwRxLabel;   /*兼Pw和GAL标签*/    
}__attribute__((packed))RX_LABEL_CFG;




typedef struct  tx_label_cfg
{
    unsigned int uiLspTxLabel;
    unsigned char ucLspTc;
    unsigned char ucLspS;
    unsigned char ucLspTtl;

    unsigned int uiPwTxLabel;
    unsigned char ucPwTc;
    unsigned char ucPwS;
    unsigned char ucPwTtl;

}__attribute__((packed))TX_LABEL_CFG;


typedef struct  oam_drv_info
{
    unsigned int group_id;
    unsigned int level;
    unsigned short  mep_id;/*group内唯一，系统概念*/
    unsigned int remote_mep_id;/*group内唯一*/
    unsigned int tx_sys_port;
    unsigned char ccm_period;/*1-3.33ms,2-10ms,3-100ms,4-1s,5-10s 6-1m,7-10m*/
    unsigned int ttl;
    unsigned int exp;
    unsigned int rx_info;/*20150106 add zzl tp oam rx属性，for vc oam 输入lif，for tp oam 输入pop-id*/
    unsigned int tx_info;/*20150106 add zzl tp oam tx属性，for vc oam输入业务的tunnel-eep指针,for vp目前是固定值不可见*/
    unsigned char oam_type;/*20141230 add zzl 0:ETH /1:LSP/2:pwe*/
    unsigned int mep_index;/*芯片用于识别创建的mep，芯片本地ID资源概念，驱动返回给应用层用来删mep*/
    unsigned char is_pro;

}__attribute__((packed))OAM_DRV_INFO;


typedef struct dm_send_para
{
    unsigned char send_en;/*0--->invalid 1---->valid*/
    unsigned char dm_tx_period;
    unsigned int mep_index;
    unsigned int packet_len;
    unsigned int sys_port;
    unsigned char* pkt_point;
}__attribute__((packed))DM_SEND_PARA;

typedef struct lm_send_para
{
    unsigned char send_en;/*0--->invalid 1---->valid*/
    unsigned char lm_tx_period;
    unsigned int mep_index;
    unsigned int packet_len;
    unsigned int sys_port;
    unsigned char* pkt_point;
}__attribute__((packed))LM_SEND_PARA;

typedef struct oam_traffic_info
{
    unsigned short oam_active_id;
    unsigned char  level;
    unsigned int  in_lsp_label;
    unsigned int out_lsp_label;
    unsigned int in_pw_label;
    unsigned int out_pw_label;
    unsigned int rx_tunnel_eep;          //接收的tunnel_eep
    unsigned int tx_tunnel_eep;          //发送的tunnel_eep
    unsigned int rx_sys_port_id;            //接收系统口id ,暂不需要
    unsigned int tx_sys_port_id;          //发送系统口id
    unsigned short  lsp_id;                //从属的lsp ,暂不需要
    unsigned short  is_protect;           //是否是保护,0/1=不是/是
    unsigned char   in_slot;               //入槽位,暂不需要
    unsigned char   out_slot;              //出槽位,暂不需要
    unsigned char   in_port;               //入端口,暂不需要
    unsigned char   out_port;              //出端口,暂不需要
    unsigned int    TxSysLifId;           //发送系统口lif
    unsigned char   uni_is_lag;           //uni是否是lag
    unsigned char   lag_id;               //网管下发的lag_id

    unsigned char slot_west;            //西向槽位
    unsigned char port_west;            //西向端口
    unsigned char slot_east;            //东向槽位
    unsigned char port_east;            //东向端口
    unsigned short sysport_id_west;       //西向系统口id
    unsigned short sysport_id_east;       //东向系统口id
    unsigned int lsp_lable_west_rx; //西向tunnel 标签
    unsigned int pw_lable_west_rx; //西向pw 标签
    unsigned int lsp_lable_east_rx; //东向tunnel 标签
    unsigned int pw_lable_east_rx; //东向pw 标签

    unsigned int lsp_lable_west_tx; //西向tunnel 标签
    unsigned int pw_lable_west_tx; //西向pw 标签
    unsigned int lsp_lable_east_tx; //东向tunnel 标签
    unsigned int pw_lable_east_tx; //东向pw 标签

    unsigned char des_mac_nni[6]; /*nni侧目的mac地址*/
    unsigned char src_mac_nni[6];  /*nni侧源的mac地址*/

    unsigned char pve_flag;
    unsigned int pve_id_or_phy_index;

    unsigned char pve_flag_west;
    unsigned int pve_id_or_phy_index_west;

    unsigned char pve_flag_east;
    unsigned int pve_id_or_phy_index_east;

    unsigned char des_mac_nni_west[6]; /*nni侧目的mac地址*/
    unsigned char src_mac_nni_west[6];  /*nni侧源的mac地址*/

    unsigned char des_mac_nni_east[6]; /*nni侧目的mac地址*/
    unsigned char src_mac_nni_east[6];  /*nni侧源的mac地址*/

    unsigned char global_mac[6];
}__attribute__((packed))OAM_TRAFFIC_INFO;



/*OAM主动帧结构体定义*/
typedef struct oam_active_cfg
{
    unsigned short usOamId;
    unsigned char ucLevel; //0/1/2=VS/VP/VC,缺省没有VS
    unsigned char ucMipMep;
    unsigned char ucMegIcc[6];
    unsigned char ucMegUmc[6];
    unsigned short usSouceMepId;
    unsigned short usPeerMepId;
    unsigned char ucLspExp;
    unsigned char ucPwExp;
    unsigned char ucMel;
    unsigned char ucApsEnable;
    unsigned char ucCvSendEnable;
    unsigned char ucCvSendPeriod;
    unsigned char ucCsfSendEnable;
    unsigned char ucFdiEnable;
    unsigned char gal_exp;
    unsigned char lsp_ttl;
    unsigned char pw_ttl;
    unsigned char gal_ttl;
    unsigned char vs_next_slot;
    unsigned char vs_next_port;
    unsigned char wrapping_ring_id;
    unsigned char wrapping_orient;   
    unsigned char ucPad[9];
}__attribute__((packed))OAM_ACTIVE_CFG;

/*OAM按需帧基本配置结构体定义*/
typedef struct oam_on_demand_base_cfg
{
    unsigned short usOamId;
    unsigned short usMplsTpOamId;
    unsigned char  ucLoopBackCfg;
    unsigned short usLoopBackLen;
    unsigned char  ucLoopBackValue;
    unsigned char  ucTstCfg;
    unsigned short usTstLen;
    unsigned char  ucLckSendEn;
    unsigned char  ucLmCfg;
    unsigned char  ucDmCfg;
    unsigned short usDmLength;
    unsigned char  ucDmValue;
    unsigned char  lsp_exp;
    unsigned char  pw_exp;
    unsigned char  gal_exp;
    unsigned char  lsp_ttl;
    unsigned char  pw_ttl;
    unsigned char  gal_ttl;
    unsigned char  mel;
    unsigned char  ucPad[16];    
}__attribute__((packed))OAM_ON_DEMAND_BASE_CFG;

/*OAM按需帧MIP配置结构体定义*/
typedef struct oam_on_demand_mip_cfg
{
    unsigned char  ucTargetTlv;
    unsigned char  MipIcc[6];
    unsigned int   uiNodeId;
    unsigned int   uiIFNum;
    unsigned short usCC;
    unsigned short usMepIDExpect;
    unsigned char  ucHopDetect;
    unsigned char  ucOptTLV;
    unsigned char request_mep_en;
    unsigned short mip_id;
    unsigned char  ucPad[11];
    
}__attribute__((packed))OAM_ON_DEMAND_MIP_CFG;

/*OAM按需帧结构体定义*/
typedef struct oam_on_demand_cfg
{
    OAM_ON_DEMAND_BASE_CFG stOamOnDemandBaseCfg;
    unsigned char ucPad[3];/*ucPad存储MIP子配置类型和长度,便于比较*/
    OAM_ON_DEMAND_MIP_CFG  stOamOnDemandMipCfg;
       
}__attribute__((packed))OAM_ON_DEMAND_CFG;


/*PTN全局基本配置结构体定义*/
typedef struct ptn_global_base_cfg
{
    unsigned int   uiMacAgeingTime;
    unsigned int   uiLabelStartValue; 
    unsigned char  ucGloablMac[6];
    unsigned short usCrcThreshold;
    unsigned short usDropThreshold;
    unsigned short usBadPktThreshold;
    unsigned short usAlignmentErrorThreshold;
    unsigned char  pad[28];     
}__attribute__((packed))PTN_GLOBAL_BASE_CFG;

/*CFM OAM全局基本配置结构体定义*/
typedef struct cfm_oam_global_base_cfg
{
    unsigned char ucCfmOamEn;
    unsigned char ucMDLevel;  
    unsigned char pad[8]; 
}__attribute__((packed))CFM_OAM_GLOBAL_BASE_CFG;

/*EFM OAM全局基本配置结构体定义*/
typedef struct efm_oam_global_base_cfg
{
    unsigned char ucEFMOamEn;
    unsigned char ucPad[9];
}__attribute__((packed))EFM_OAM_GLOBAL_BASE_CFG;

/*MPLS-TP OAM全局基本配置结构体定义*/
typedef struct mpls_tp_oam_global_base_cfg
{
    unsigned char  ucSourceMac[6];
    unsigned char  ucVpFDISendEn;
    unsigned char  ucVpFDIMel;
    unsigned char  ucVcFDISendEn;
    unsigned char  ucVcFDIMel;
    unsigned char  ucLoopBackTimeout;
    unsigned short usVsSigDegradeThreshold;
    unsigned short usVsSigFailThreshold;
    unsigned short usChannelType;

    unsigned short usVsDropRatioNear;
    unsigned short usVsDropRatioFar;
    unsigned short usVsTimeDelayUs;
    unsigned char  usVsTimedelayVarUs;

    unsigned short usVpDropRatioNear;
    unsigned short usVpDropRatioFar;
    unsigned short usVpTimeDelayUs;
    unsigned char  usVpTimedelayVarUs;

    unsigned short usVcDropRatioNear;
    unsigned short usVcDropRatioFar;
    unsigned short usVcTimeDelayUs;
    unsigned char  usVcTimedelayVarUs;   
}__attribute__((packed))MPLS_TP_OAM_GLOBAL_BASE_CFG;

/*PTN全局配置结构体定义*/
typedef struct ptn_global_cfg
{
    PTN_GLOBAL_BASE_CFG stPtnGlobalBaseCfg;
    unsigned char ucPadFront[3];
    CFM_OAM_GLOBAL_BASE_CFG stCfmOamGlobalBase;
    unsigned char ucPadMid[3];
    EFM_OAM_GLOBAL_BASE_CFG stEfmOamGlobalBase;
    unsigned char ucPadTail[3];
    MPLS_TP_OAM_GLOBAL_BASE_CFG  stMplsTpOamGlobalBase;
}__attribute__((packed))PTN_GLOBAL_CFG;

/*OAM VS帧结构体定义*/
typedef struct oam_vs_cfg
{
    unsigned char  ucMegIcc[6];
    unsigned char  ucMegUmc[6];
    unsigned short usSrcMepId;
    unsigned short usPeerMepId;
    unsigned char  ucMel;
    unsigned char  ucFrontPad[2];
    unsigned char  ucCvLckEn;
    unsigned char  ucLoopBackCfg;
    unsigned short usLoopBackLen;
    unsigned char  ucLoopBackValue;
    unsigned char  ucTstCfg;
    unsigned short usTstLen;
    unsigned char  ucTstPad;
    unsigned char  ucMidPad;
    unsigned char  ucLMCfg;
    unsigned char  ucDMCfg;
    unsigned short usDMLen;
    unsigned char  ucDMValue;
    unsigned char  ucTailPad[11];
        
}__attribute__((packed))OAM_VS_CFG;


typedef struct on_demand_map_active_oam
{
    unsigned short oamid;
    unsigned char  level; 
    unsigned char mep_mip;
    int tst_oam_entry_id;
    int tst_l2vpn_entry_id;
    int lb_entry_id;
    unsigned short item;

    float oam_lm_far_los;
    float oam_lm_near_los;
    unsigned int oam_dm_delay_ns;
    unsigned int oam_dm_delay_var_ns;
}__attribute__((packed))ON_DEMAND_MAP_ACTIVE_OAM;

typedef struct active_oam_map_on_demand
{
    unsigned short on_demand_id;
    unsigned short oam_time_delay_last;/*上一次oam时延值，用于计算时延变化量*/
    unsigned char vp_vc_level;
    unsigned short item;
    unsigned short mip_ais_en;
    BMU_WDOG_ID fdi_wdog_id;/*add by dinghao 用于起ais时的定时器*/
    unsigned short sys_port_rx;/*ais监测的本盘sysport，不应该是其它单盘sysport*/
    unsigned char uni_fapid;
    unsigned char nni_fapid;
    
}__attribute__((packed))ACTIVE_OAM_MAP_ON_DEMAND;


/*按照最新的FPGA文件新增结构体*/
typedef struct oam_fpga_item_info
{
    unsigned char item_type;/*tp_oam or cfm*/
    unsigned char item_valid;/*条目是否分配*/
    unsigned short oamid_mepid;/*条目对应的oam_id 或者 mep_id*/    
}__attribute__((packed))OAM_FPGA_ITEM_INFO;


typedef struct oam_dmac_adapt_info
{
    unsigned char section_type;/*表示层级，分别取值为0/1/2/3，表示VC/VP/VS/CFM*/
    unsigned char mep_type;/*表示MEP模式，分别取值为0/1，表示DOWN/UP MEP*/
    unsigned char active_type;/*表示主动/按需模式，分别取值为0/1，表示主动/按需*/
    unsigned char oam_type;/*表示OAM类型，分别取值为0/1/2/3，表示其他/LM/DM/CCM(带双端LM功能)，其他取值预留*/
    unsigned char vlan_no;/*VLAN层数*/
    unsigned char oam_no;/*OAM条目号*/    
}__attribute__((packed))OAM_DMAC_ADAPT_INFO;



/*解决FPGA配置寄存器中大量以bit为单位进行配置的问题*/

/* 帧发送标签使能 */
typedef struct fram_tx_label_enable
{
    unsigned short backup2: 2;
    unsigned short csfPort: 6;
    unsigned short backup1: 1;
    unsigned short cycle: 3;
    unsigned short csfQuickEn: 1;
    unsigned short PwCsfEnable: 1;
    unsigned short LspApsEnable: 1;
    unsigned short CvEnable: 1;
} FRAM_TX_ENABLE1;

/***STRUCT********************************************************************/
/* Description  : 对应FPGA中FDI帧发帧使能位地址的2个字节                     */
/*  1.Date         : 2014/11/14                                              */
/*    Author       : huxi                                                    */
/*                                                                           */
/*****************************************************************************/
typedef struct fdi_tx_enable
{
    unsigned short backup1: 1;
    unsigned short mel: 3;
    unsigned short backup2: 1;
    unsigned short losRelated: 1;
    unsigned short fdiPort: 6;
    unsigned short cycle: 3;
    unsigned short enable: 1;
} FDI_TX_ENABLE;

/***STRUCT********************************************************************/
/* Description  : 对应FPGA中APS帧的端口，opcode和mel的2个字节内容            */
/*  1.Date         : 2014/11/14                                              */
/*    Author       : huxi                                                    */
/*                                                                           */
/*****************************************************************************/
typedef struct fram_tx_enable2
{
    unsigned short apsSource: 1;
    unsigned short backup1: 1;
    unsigned short apsPort: 6;
    unsigned short insertSd: 1;
    unsigned short csfType: 3;
    unsigned short apsOpcode: 1;
    unsigned short mel: 3;
} FRAM_TX_ENABLE2;

typedef struct tp_oam_lsp_cfg
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
    
    unsigned char des_mac_nni[6]; /*nni侧目的mac地址*/
    unsigned char src_mac_nni[6];  /*nni侧源的mac地址*/
    unsigned char pve_flag;
    unsigned int pve_id_or_phy_index;

    unsigned char pve_flag_west;
    unsigned int pve_id_or_phy_index_west;

    unsigned char pve_flag_east;
    unsigned int pve_id_or_phy_index_east;

    unsigned char des_mac_nni_west[6]; /*nni侧目的mac地址*/
    unsigned char src_mac_nni_west[6];  /*nni侧源的mac地址*/

    unsigned char des_mac_nni_east[6]; /*nni侧目的mac地址*/
    unsigned char src_mac_nni_east[6];  /*nni侧源的mac地址*/

    unsigned char global_mac[6];
    
}TP_OAM_LSP_CFG;


/*公共外部函数定义*/
extern unsigned short oam_fpga_16bits_read(unsigned long fpga_base_addr, unsigned long fpga_offset);
extern int oam_fpga_16bits_write(unsigned long fpga_base_addr, unsigned long fpga_offset, unsigned short data);

#endif

