/******************************************************************************

	Copyright (C), 2002-2010, Wuhan FiberHome Tech. Co., Ltd.

 ******************************************************************************
  �� �� ��   : oam_fpga_drv.h
  �� �� ��   : ����
  ��    ��   : ����
  ��������   : 2014��11��12��
  ��������   : oam_fpga_drv.c��ͷ�ļ�
  �޸���ʷ   :
  1.��    ��   : 2015��1��6��
    ��    ��   : ����   
    �޸�����   : �����ļ�
    
  2.��    ��   : 2015��10��3��
    ��    ��   : ����   
    �޸�����   : ����CFM�������ݣ��Ժ��ͷ�ļ�ΪTP_OAM��CFM����

******************************************************************************/
#ifndef __OAM_FPGA_DRV_H__
#define __OAM_FPGA_DRV_H__

#include "oam_public.h"


/**STRUCT+********************************************************************/
/*Description: �������ֺ궨��                                                */
/*                                                                           */
/* Added by dinghao, 2015/10/1                                               */
/*****************************************************************************/
#define OAM_RESET_LB_ADDR  (0x3)
#define OAM_SEND_CONTROL_ADDR (0x9)
#define OAM_CAPTURE_FRAME_ADDR (0xb)
#define PTN_APS_GLOBAL_BASE_ADDR (0x3)
#define PTN_APS_GLOBAL_5S_ADDR (0x7)


/*ȫ��GAL����*/
#define TP_OAM_GAL_BASE_ADDR   (0x0004)

/*ȫ��ACH����*/
#define TP_OAM_ACH_BASE_ADDR   (0x0006)

/*ȫ��ACH����*/
#define TP_OAM_TX_CTRL_ADDR   (0x000a)


/*����LB/TEST/LCK֡ģ�����ַ*/
#define DEMAND_OAM_MODULE_OFFSET (0X9000)

/*����LM/DM֡ģ�����ַ*/
#define DEMAND_OAM_MODULE_LM_DM_OFFSET (0X8000)


/*����oam��ʱ���޼Ĵ���*/
#define OAM_LB_TIME_THRESHOLD 0x19
#define OAM_LB_TIME_50_MS 1
#define OAM_LB_TIME_350_MS 7
#define OAM_LB_TIME_3_5_S   70

/**STRUCT+********************************************************************/
/*Description: ����OAM ITMHͷ�Ĵ�����ַƫ��                                  */
/*                                                                           */
/* Added by dinghao, 2015/10/3 ��OAM_ADAPTERģ��������                       */
/*****************************************************************************/
#define OAM_ACTIVE_ITMH_ADDR                 (0x3000)


/**STRUCT+********************************************************************/
/*Description: ����OAM ���ͱ�ǩ�Ĵ�����ַƫ��                                */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/

/*CSF/APS/CCM���ͱ�ǩ����*/
#define OAM_NO_FDI_TX_LABEL_VLAN_ADDR (0x11000)

/*FDI or AIS���ͱ�ǩ����*/
#define OAM_FDI_TX_LABEL_VLAN_ADDR (0x13000)


/**STRUCT+********************************************************************/
/*Description: ����OAM ���ձ�ǩ�Ĵ�����ַƫ��                                */
/*                                                                           */
/* Added by dinghao, 2015/10/3  ֱ�����ö�������FPGA�Ĵ���                   */
/*****************************************************************************/


/**STRUCT+********************************************************************/
/*Description: ����OAM COUNT ID�Ĵ�����ַ                                    */
/*                                                                           */
/* Added by dinghao, 2016/1/20                                               */
/*****************************************************************************/

#define OAM_COUNT_ID_ACTIVE_ADDR (0x5000)


/**STRUCT+********************************************************************/
/*Description: ����OAM���üĴ�����ַƫ��                                     */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/

/*CV����ʹ�ܼĴ���*/
#define CV_TX_ENABLE_OFFSET          (0xa800)

/*CV����mel�Ĵ���*/
#define CV_TX_MEL_OFFSET               (0xb000)

/*CV����MEP�Ĵ���*/
#define CV_TX_MEP_OFFSET               (0xb800)

/*CV����MEG�Ĵ���*/
#define CV_TX_MEG_OFFSET               (0xc000)

/*CV�������ڼĴ���*/
#define CV_EXPECT_PRIOD_OFFSET     (0x17800)

/*CV����MEP�Ĵ���*/
#define CV_EXPECT_MEP_OFFSET     (0x17000)

#define CV_DUAL_ENDED_LM_READ_TIME (0x11)
#define CV_DUAL_ENDED_LM_COUNT (0x1b000)

/*FDI��֡��ǩʹ������*/
#define FDI_TX_CFG_OFFSET (0Xa000)

/*APS������CCUͨ�ŷ���Ĵ�������
item --> oamid*/
#define APS_ITEM_TO_OAM_ID (0x3000)

/*oamid --> item*/
#define APS_OAM_ID_TO_ITEM  (0x10000)

#define APS_PORT_RX_RELATE (0x18000)

/**STRUCT+********************************************************************/
/*Description: ����OAM MAC��ַ�Ĵ�����ַƫ��                                 */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/

#define OAM_FDI_MAC_ADDR (0x5000)
#define OAM_CV_APS_CSF_MAC_ADDR (0x2000)



/**STRUCT+********************************************************************/
/*Description: ����OAM MAC�ض���Ĵ�����ַƫ��                               */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/
#define OAM_SMAC_ADAPT_ACTIVE_ADDR (0x1000)



/**STRUCT+********************************************************************/
/*Description: ����LB/TEST/DM/LCK֡ITMH�Ĵ�����ַƫ��                        */
/*                                                                           */
/* Added by dinghao, 2015/10/3  ��OAM_ADAPTERģ��������                      */
/*****************************************************************************/
#define OAM_ON_DEMAND_ITMH_ADDR                            (0x8000)


/**STRUCT+********************************************************************/
/*Description: ����LB/TEST/DM/LCK֡���ͱ�ǩ�Ĵ�����ַƫ��                    */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/

/*����TMPLS��ǩ�Ĵ���*/
#define  OAM_LB_TMPLS_TX_ADDR     (0x0080)
#define  OAM_TST_TMPLS_TX_ADDR   (0x0880)
#define  OAM_LCK_TMPLS_TX_ADDR   (0x0c80)

/*����PW or GAL�ֽڼĴ���*/
#define  OAM_LB_PW_GAL_TX_ADDR    (0x00c0) 
#define  OAM_TST_PW_GAL_TX_ADDR  (0x08c0)
#define  OAM_LCK_PW_GAL_TX_ADDR  (0x0cc0)

/*LMM --> 0xa09*/
#define OAM_LMM_TX_LABEL_VLAN (0xa09)
#define OAM_DMM_TX_LABEL_VLAN (0x409)
#define OAM_LMR_TX_LABEL_VLAN (0xc06)
#define OAM_DMR_TX_LABEL_VLAN (0x606)

/**STRUCT+********************************************************************/
/*Description: ����LB/TEST/DM/LCK֡���ձ�ǩ�Ĵ�����ַƫ��                    */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/

/* LB/TST/LCKģ�� */
#define OAM_LB_TST_LCK_RX_OFFSET (0xd0)

/* LM/DMģ�� */
#define OAM_LM_DM_RX_OFFSET        (0xa0)


/**STRUCT+********************************************************************/
/*Description: ����LB/TEST/LM/DM/LCK֡ͷ��Ϣ�Ĵ�����ַƫ��                      */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/

#define    OAM_LB_FRAME_HEAD_ADDR                  (0x0000)
#define    OAM_TST_FRAME_HEAD_ADDR                  (0x0800)
#define    OAM_LCK_FRAME_HEAD_ADDR                  (0x0c00)

#define    OAM_LB_LEN_TX_ADDR                           (0x07)
#define   OAM_TST_LEN_TX_ADDR                           (0x07)

#define OAM_DMM_HEADER_ADDR (0x400)
#define OAM_DMM_TLV_TYPE (0x401)
#define OAM_DMM_TLV_LEN (0x402)


#define OAM_LMM_HEADER_ADDR (0xa00)
#define OAM_LMM_TLV_TYPE (0xa01)
#define OAM_LMM_TLV_LEN (0xa02)



/**STRUCT+********************************************************************/
/*Description: ����LB/TEST/LM/DM/LCK�������ݼĴ�����ַƫ��                      */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/
#define    OAM_LB_DATA_TX_ADDR                         (0x00e0)

/**STRUCT+********************************************************************/
/*Description: ����LB/TEST/DM/LCK MEP/MEG�Ĵ�����ַƫ��                      */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/
#define MEP_MEG_BASE (0X0100)

/*MEG*/
#define    OAM_ON_DEMAND_MEG_ADDR                              (0x0a)

/*ICC*/
#define    OAM_ON_DEMAND_ICC_ADDR                              (0x01)

/*Ŀ��node_id*/
#define    OAM_ON_DEMAND_PEER_NODE_ID_ADDR             (0x04)

/*IF_NUM*/
#define    OAM_ON_DEMAND_IF_NUM_ADDR                        (0x06)

/*CC*/
#define    OAM_ON_DEMAND_CC_ADDR                        (0x08)

/*Դnode_id*/
#define    OAM_ON_DEMAND_SRC_NODE_ID_ADDR             (0x120)

/*Դ��MEP*/
#define    OAM_ON_DEMAND_SRC_MEP_ADDR                       (0x09)

/*�Զ�MEP*/
#define    OAM_ON_DEMAND_PEER_MEP_ADDR                      (0x00)


/**STRUCT+********************************************************************/
/*Description: ����LB/TEST/LM/DM/LCK MAC��ַ�Ĵ�����ַƫ��                   */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/
#define OAM_DST_MAC_ADDR                  (0x01)
#define OAM_SRC_MAC_ADDR                  (0x04)

#define OAM_LMM_DST_MAC_ADDR  (0xa03)
#define OAM_LMM_SRC_MAC_ADDR  (0xa06)
#define OAM_LMR_DST_MAC_ADDR  (0xc00)
#define OAM_LMR_SRC_MAC_ADDR  (0xc03)

#define OAM_DMM_DST_MAC_ADDR (0x403)
#define OAM_DMM_SRC_MAC_ADDR (0x406)
#define OAM_DMR_DST_MAC_ADDR (0x600)
#define OAM_DMR_SRC_MAC_ADDR (0x603)



/**STRUCT+********************************************************************/
/*Description: ����LB/TEST/LM/DM/LCK MAC�ض���Ĵ�����ַƫ��                 */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/
#define OAM_SMAC_ADAPT_ON_DEMAND_ADDR (0x7000)

/**STRUCT+********************************************************************/
/*Description: ����LM/DM MAC count id�Ĵ�����ַƫ��                 */
/*                                                                           */
/* Added by dinghao, 2015/12/24                                               */
/*****************************************************************************/
#define OAM_COUNT_ID_ON_DEMAND_ADDR (0x9000)





/**STRUCT+********************************************************************/
/*Description: LM/DM ��������ַ                                              */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/

/*TxTimeStampf�����Ĵ���*/
#define TX_TIMESTPF_OFFSET           (0X0804)

/*RxTimeStampf�����Ĵ���*/
#define RX_TIMESTPF_OFFSET           (0X0808)

/*TxStampb�����Ĵ���*/
#define TX_STAMPB_OFFSET              (0x080c)

/*RxStampb�����Ĵ���*/
#define RX_STAMPB_OFFSET              (0x0800)


/*LMRxPCl�Ĵ���*/
#define LMR_RX_OFFSET                   (0x0e00)

/*LMTxPC_f�Ĵ���*/
#define LMM_TX_OFFSET                 (0x0e02)

/*LMRxPC_f�Ĵ���*/
#define LMM_RX_OFFSET                 (0x0e04)

/*LMTxPC_b�Ĵ���*/
#define LMR_TX_OFFSET                 (0x0e06)


/*����dmģ��*/
#define DEMAND_LM_DM_READ_TIME_OFFSET (0X003)

/*����֡TST/LCK/LB����*/
#define LBM_TX_CNT_ADDR 0x100
#define LBR_TX_CNT_ADDR  0x110
#define TST_TX_CNT_ADDR   0x120
#define LCK_TX_CNT_ADDR  0x130

#define LBM_RX_CNT_ADDR 0x140
#define LBR_RX_CNT_ADDR  0x150
#define TST_RX_CNT_ADDR  0x160
#define LCK_RX_CNT_ADDR  0x170
#define LBR_DATA_TLV_ERROR 0x180
#define LBR_TRANS_ID_ERROR 0x190
#define LBR_ALL_ONE_ERROR 0x1a0
#define LBR_ALL_ZERO_ERROR 0x1b0
#define LBR_PSEU_RANDOM_ERROR 0x1c0
#define TST_ALL_ONE_ERROR 0x1d0
#define TST_ALL_ZERO_ERROR 0x1e0
#define TST_PSEU_RANDOM_ERROR 0x1f0
#define CV_TX_CNT 0x0800
#define CV_RX_CNT 0x1000

#define ON_DEMAND_FRAME_ADDR_OFFSET 0x1

#endif
