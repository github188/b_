/******************************************************************************

	Copyright (C), 2002-2010, Wuhan FiberHome Tech. Co., Ltd.

 ******************************************************************************
  �� �� ��   : oam_public.h
  �� �� ��   : ����
  ��    ��   : ����
  ��������   : 2015��3��30��
  ��������   : oam��ģ�鹫���궨��ͽṹ�嶨��
  �޸���ʷ   :
  1.��    ��   : 2015��3��30��
    ��    ��   : ����   
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __OAM_PUBLIC_H_
#define __OAM_PUBLIC_H_

#include "tp_cfg.h"
#include "bmuInclude.h"

//#include "bmu_bep.h"


//#define OAM_DEBUG

/*�������µ�FPGA�ļ�������*/
#define CFM 6
#define CFM_UP 7
#define CFM_DOWN 8

#define TP_OAM 5
#define TP_OAM_VP 1
#define TP_OAM_VC 2
#define TP_OAM_VS 3
#define TP_OAM_WRAPPING 4

/*����TP��CFM*/
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
��֡��Σ�
   ����3'b000Ϊ8847+TUNL+PW+ACH
   3'b001Ϊ8092
   3'b010Ϊ8100+vlan+8902
   3'b011Ϊ8100+vlan+8100+vlan+8902
   3'b100Ϊ8100+vlan+XXXX+vlan+      
            8100+ vlan+8902��
*/
#define FRAME_TP_OAM 0 
#define FRAME_CFM_NO_VLAN 1
#define FRAME_CFM_ONE_VLAN 2
#define FRAME_CFM_TWO_VLAN 3
#define FRAME_CFM_THREE_VLAN 4


/*�����궨��*/
#define SUCCESS 0
#define ERROR -1

/*OAM������־λ*/
#define OAM_UN_CREATE 0
#define OAM_CREATE_SUCCESS 1
#define OAM_CREATE_TRAFFIC_FAIL 2  
#define OAM_CREATE_GROUP_FAIL  3
#define OAM_CREATE_MEP_FAIL 4

/*OAMɾ����־λ*/
#define OAM_DELETE_OK 5
#define OAM_DELETE_MEP_FAIL 6
#define OAM_DELETE_GROUP_FAIL 7


#define OAM_LEVEL_VS        0
#define OAM_LEVEL_VP        1 
#define OAM_LEVEL_VC        2
#define OAM_LEVEL_OTHER     3

#define MAX_GLOBAL_OAM_NUM (1024 * 16)  /*��ǰ��Ԫ֧��oam id�����*/
#define MAX_FPGA_ITEM_NUM 2047
#define MAX_ON_DEMAND_ID    16
#define MAX_SLOT_NUM_U60 64

#define MAX_DRV_GROUP_ID_NUM 8000


/*��ͬҵ�����ͺ궨�壬����oam����ҵ����Ϣ*/
#define OAM_MEP_VP_TRAFFIC 1
#define OAM_MEP_VC_TRAFFIC 2
#define OAM_MIP_LSR_TRAFFIC 3
#define OAM_MIP_MSPW_TRAFFIC 4

/*���̴���ö�٣����ֵ���,����*/
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
#define  POTS_BOARD_16TN1           22   /*16TN1��pmc�棩������*/
#define  POTS_BOARD_5TN3             23   /*new add 2015��10��13��*/

#define FRAME_U10 4  /*U10ͬC400*/
#define FRAME_U20 2  
#define FRAME_U30 6
#define FRAME_U40 0
#define FRAME_U60 7  /*U60ͬC700*/

#define STRING_LEN (30)
#define TP_OAM_LOG_DIR     "../log/tpoam.log"
#define TP_OAM_ERROR_MSG_LEN 300

#define PVE_MODE_OAM 1
#define PHY_MODE_OAM 2

/*�����ṹ�嶨��*/
typedef struct  rx_label_cfg
{
    unsigned int uiLspRxLabel;  /*��Lsp��tunnel��ǩ*/
    unsigned int uiPwRxLabel;   /*��Pw��GAL��ǩ*/    
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
    unsigned short  mep_id;/*group��Ψһ��ϵͳ����*/
    unsigned int remote_mep_id;/*group��Ψһ*/
    unsigned int tx_sys_port;
    unsigned char ccm_period;/*1-3.33ms,2-10ms,3-100ms,4-1s,5-10s 6-1m,7-10m*/
    unsigned int ttl;
    unsigned int exp;
    unsigned int rx_info;/*20150106 add zzl tp oam rx���ԣ�for vc oam ����lif��for tp oam ����pop-id*/
    unsigned int tx_info;/*20150106 add zzl tp oam tx���ԣ�for vc oam����ҵ���tunnel-eepָ��,for vpĿǰ�ǹ̶�ֵ���ɼ�*/
    unsigned char oam_type;/*20141230 add zzl 0:ETH /1:LSP/2:pwe*/
    unsigned int mep_index;/*оƬ����ʶ�𴴽���mep��оƬ����ID��Դ����������ظ�Ӧ�ò�����ɾmep*/
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
    unsigned int rx_tunnel_eep;          //���յ�tunnel_eep
    unsigned int tx_tunnel_eep;          //���͵�tunnel_eep
    unsigned int rx_sys_port_id;            //����ϵͳ��id ,�ݲ���Ҫ
    unsigned int tx_sys_port_id;          //����ϵͳ��id
    unsigned short  lsp_id;                //������lsp ,�ݲ���Ҫ
    unsigned short  is_protect;           //�Ƿ��Ǳ���,0/1=����/��
    unsigned char   in_slot;               //���λ,�ݲ���Ҫ
    unsigned char   out_slot;              //����λ,�ݲ���Ҫ
    unsigned char   in_port;               //��˿�,�ݲ���Ҫ
    unsigned char   out_port;              //���˿�,�ݲ���Ҫ
    unsigned int    TxSysLifId;           //����ϵͳ��lif
    unsigned char   uni_is_lag;           //uni�Ƿ���lag
    unsigned char   lag_id;               //�����·���lag_id

    unsigned char slot_west;            //�����λ
    unsigned char port_west;            //����˿�
    unsigned char slot_east;            //�����λ
    unsigned char port_east;            //����˿�
    unsigned short sysport_id_west;       //����ϵͳ��id
    unsigned short sysport_id_east;       //����ϵͳ��id
    unsigned int lsp_lable_west_rx; //����tunnel ��ǩ
    unsigned int pw_lable_west_rx; //����pw ��ǩ
    unsigned int lsp_lable_east_rx; //����tunnel ��ǩ
    unsigned int pw_lable_east_rx; //����pw ��ǩ

    unsigned int lsp_lable_west_tx; //����tunnel ��ǩ
    unsigned int pw_lable_west_tx; //����pw ��ǩ
    unsigned int lsp_lable_east_tx; //����tunnel ��ǩ
    unsigned int pw_lable_east_tx; //����pw ��ǩ

    unsigned char des_mac_nni[6]; /*nni��Ŀ��mac��ַ*/
    unsigned char src_mac_nni[6];  /*nni��Դ��mac��ַ*/

    unsigned char pve_flag;
    unsigned int pve_id_or_phy_index;

    unsigned char pve_flag_west;
    unsigned int pve_id_or_phy_index_west;

    unsigned char pve_flag_east;
    unsigned int pve_id_or_phy_index_east;

    unsigned char des_mac_nni_west[6]; /*nni��Ŀ��mac��ַ*/
    unsigned char src_mac_nni_west[6];  /*nni��Դ��mac��ַ*/

    unsigned char des_mac_nni_east[6]; /*nni��Ŀ��mac��ַ*/
    unsigned char src_mac_nni_east[6];  /*nni��Դ��mac��ַ*/

    unsigned char global_mac[6];
}__attribute__((packed))OAM_TRAFFIC_INFO;



/*OAM����֡�ṹ�嶨��*/
typedef struct oam_active_cfg
{
    unsigned short usOamId;
    unsigned char ucLevel; //0/1/2=VS/VP/VC,ȱʡû��VS
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

/*OAM����֡�������ýṹ�嶨��*/
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

/*OAM����֡MIP���ýṹ�嶨��*/
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

/*OAM����֡�ṹ�嶨��*/
typedef struct oam_on_demand_cfg
{
    OAM_ON_DEMAND_BASE_CFG stOamOnDemandBaseCfg;
    unsigned char ucPad[3];/*ucPad�洢MIP���������ͺͳ���,���ڱȽ�*/
    OAM_ON_DEMAND_MIP_CFG  stOamOnDemandMipCfg;
       
}__attribute__((packed))OAM_ON_DEMAND_CFG;


/*PTNȫ�ֻ������ýṹ�嶨��*/
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

/*CFM OAMȫ�ֻ������ýṹ�嶨��*/
typedef struct cfm_oam_global_base_cfg
{
    unsigned char ucCfmOamEn;
    unsigned char ucMDLevel;  
    unsigned char pad[8]; 
}__attribute__((packed))CFM_OAM_GLOBAL_BASE_CFG;

/*EFM OAMȫ�ֻ������ýṹ�嶨��*/
typedef struct efm_oam_global_base_cfg
{
    unsigned char ucEFMOamEn;
    unsigned char ucPad[9];
}__attribute__((packed))EFM_OAM_GLOBAL_BASE_CFG;

/*MPLS-TP OAMȫ�ֻ������ýṹ�嶨��*/
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

/*PTNȫ�����ýṹ�嶨��*/
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

/*OAM VS֡�ṹ�嶨��*/
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
    unsigned short oam_time_delay_last;/*��һ��oamʱ��ֵ�����ڼ���ʱ�ӱ仯��*/
    unsigned char vp_vc_level;
    unsigned short item;
    unsigned short mip_ais_en;
    BMU_WDOG_ID fdi_wdog_id;/*add by dinghao ������aisʱ�Ķ�ʱ��*/
    unsigned short sys_port_rx;/*ais���ı���sysport����Ӧ������������sysport*/
    unsigned char uni_fapid;
    unsigned char nni_fapid;
    
}__attribute__((packed))ACTIVE_OAM_MAP_ON_DEMAND;


/*�������µ�FPGA�ļ������ṹ��*/
typedef struct oam_fpga_item_info
{
    unsigned char item_type;/*tp_oam or cfm*/
    unsigned char item_valid;/*��Ŀ�Ƿ����*/
    unsigned short oamid_mepid;/*��Ŀ��Ӧ��oam_id ���� mep_id*/    
}__attribute__((packed))OAM_FPGA_ITEM_INFO;


typedef struct oam_dmac_adapt_info
{
    unsigned char section_type;/*��ʾ�㼶���ֱ�ȡֵΪ0/1/2/3����ʾVC/VP/VS/CFM*/
    unsigned char mep_type;/*��ʾMEPģʽ���ֱ�ȡֵΪ0/1����ʾDOWN/UP MEP*/
    unsigned char active_type;/*��ʾ����/����ģʽ���ֱ�ȡֵΪ0/1����ʾ����/����*/
    unsigned char oam_type;/*��ʾOAM���ͣ��ֱ�ȡֵΪ0/1/2/3����ʾ����/LM/DM/CCM(��˫��LM����)������ȡֵԤ��*/
    unsigned char vlan_no;/*VLAN����*/
    unsigned char oam_no;/*OAM��Ŀ��*/    
}__attribute__((packed))OAM_DMAC_ADAPT_INFO;



/*���FPGA���üĴ����д�����bitΪ��λ�������õ�����*/

/* ֡���ͱ�ǩʹ�� */
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
/* Description  : ��ӦFPGA��FDI֡��֡ʹ��λ��ַ��2���ֽ�                     */
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
/* Description  : ��ӦFPGA��APS֡�Ķ˿ڣ�opcode��mel��2���ֽ�����            */
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
    unsigned char Slot_West;            //�����λ
    unsigned char Port_West;            //����˿�
    unsigned char Slot_East;            //�����λ
    unsigned char Port_East;            //����˿�
    unsigned short SysPortId_West;       //����ϵͳ��id
    unsigned short SysPortId_East;       //����ϵͳ��id
    unsigned int LspLable_West_Rx; //����tunnel ��ǩ
    unsigned int PwLable_West_Rx; //����pw ��ǩ
    unsigned int LspLable_East_Rx; //����tunnel ��ǩ
    unsigned int PwLable_East_Rx; //����pw ��ǩ

    unsigned int LspLable_West_Tx; //����tunnel ��ǩ
    unsigned int PwLable_West_Tx; //����pw ��ǩ
    unsigned int LspLable_East_Tx; //����tunnel ��ǩ
    unsigned int PwLable_East_Tx; //����pw ��ǩ
    unsigned short LspId; //lsp_id(����Ҫ,ȥ�����߱�������)
    unsigned short is_protect; //�Ƿ񱣻�(����Ҫ,ȥ�����߱�������)
    unsigned char InSlot; //���λ����Ҫ��VP �� VC��
    unsigned char InPort; //��˿ڣ���Ҫ��VP �� VC��
    unsigned char OutSlot; //����λ����Ҫ��VP �� VC��
    unsigned char OutPort; //���˿ڣ���Ҫ��VP �� VC��
    unsigned int InLspLable; //��tunnel ��ǩ(��Ҫ����VP)
    unsigned int OutLspLable; //��tunnel ��ǩ(��Ҫ����VP)

    unsigned int InPwLable; //��pw ��ǩ(���ã�VP��ʱ��0x13��VC��ʱ����pw ��ǩ)
    unsigned int OutPwLable; //��pw ��ǩ(���ã�VP��ʱ��0x13��VC��ʱ���pw ��ǩ)

    unsigned int SysPortId; //����ϵͳ��id(����Ҫ��ȥ�����߱�������)
    unsigned int TxSysLifId; //����ϵͳ��lif(��Ҫ����VC)
    unsigned int TxSysPortId; //����ϵͳ��id(��Ҫ��VP/VC����Ҫ)

    unsigned int RxTunnelEep; //���յ�tunnel_eep(��Ҫ����VP��VC����)
    unsigned int TxTunnelEep; //���͵�tunnel_eep(��Ҫ����VP��VC����)

    unsigned char uni_is_lag; //uni�Ƿ���lag(��Ҫ����VC��VP����)
    unsigned char lag_id; //�����·���lag_id(��Ҫ����VC��VP����)
    
    unsigned char des_mac_nni[6]; /*nni��Ŀ��mac��ַ*/
    unsigned char src_mac_nni[6];  /*nni��Դ��mac��ַ*/
    unsigned char pve_flag;
    unsigned int pve_id_or_phy_index;

    unsigned char pve_flag_west;
    unsigned int pve_id_or_phy_index_west;

    unsigned char pve_flag_east;
    unsigned int pve_id_or_phy_index_east;

    unsigned char des_mac_nni_west[6]; /*nni��Ŀ��mac��ַ*/
    unsigned char src_mac_nni_west[6];  /*nni��Դ��mac��ַ*/

    unsigned char des_mac_nni_east[6]; /*nni��Ŀ��mac��ַ*/
    unsigned char src_mac_nni_east[6];  /*nni��Դ��mac��ַ*/

    unsigned char global_mac[6];
    
}TP_OAM_LSP_CFG;


/*�����ⲿ��������*/
extern unsigned short oam_fpga_16bits_read(unsigned long fpga_base_addr, unsigned long fpga_offset);
extern int oam_fpga_16bits_write(unsigned long fpga_base_addr, unsigned long fpga_offset, unsigned short data);

#endif

