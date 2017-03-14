/******************************************************************************

	Copyright (C), 2002-2010, Wuhan FiberHome Tech. Co., Ltd.

 ******************************************************************************
  文 件 名   : oam_fpga_drv.h
  版 本 号   : 初稿
  作    者   : 丁浩
  生成日期   : 2014年11月12日
  功能描述   : oam_fpga_drv.c的头文件
  修改历史   :
  1.日    期   : 2015年1月6日
    作    者   : 丁浩   
    修改内容   : 创建文件
    
  2.日    期   : 2015年10月3日
    作    者   : 丁浩   
    修改内容   : 增加CFM部分内容，以后该头文件为TP_OAM与CFM公用

******************************************************************************/
#ifndef __OAM_FPGA_DRV_H__
#define __OAM_FPGA_DRV_H__

#include "oam_public.h"


/**STRUCT+********************************************************************/
/*Description: 公共部分宏定义                                                */
/*                                                                           */
/* Added by dinghao, 2015/10/1                                               */
/*****************************************************************************/
#define OAM_RESET_LB_ADDR  (0x3)
#define OAM_SEND_CONTROL_ADDR (0x9)
#define OAM_CAPTURE_FRAME_ADDR (0xb)
#define PTN_APS_GLOBAL_BASE_ADDR (0x3)
#define PTN_APS_GLOBAL_5S_ADDR (0x7)


/*全局GAL配置*/
#define TP_OAM_GAL_BASE_ADDR   (0x0004)

/*全局ACH配置*/
#define TP_OAM_ACH_BASE_ADDR   (0x0006)

/*全局ACH配置*/
#define TP_OAM_TX_CTRL_ADDR   (0x000a)


/*按需LB/TEST/LCK帧模块基地址*/
#define DEMAND_OAM_MODULE_OFFSET (0X9000)

/*按需LM/DM帧模块基地址*/
#define DEMAND_OAM_MODULE_LM_DM_OFFSET (0X8000)


/*按需oam超时门限寄存器*/
#define OAM_LB_TIME_THRESHOLD 0x19
#define OAM_LB_TIME_50_MS 1
#define OAM_LB_TIME_350_MS 7
#define OAM_LB_TIME_3_5_S   70

/**STRUCT+********************************************************************/
/*Description: 主动OAM ITMH头寄存器地址偏移                                  */
/*                                                                           */
/* Added by dinghao, 2015/10/3 在OAM_ADAPTER模块中配置                       */
/*****************************************************************************/
#define OAM_ACTIVE_ITMH_ADDR                 (0x3000)


/**STRUCT+********************************************************************/
/*Description: 主动OAM 发送标签寄存器地址偏移                                */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/

/*CSF/APS/CCM发送标签配置*/
#define OAM_NO_FDI_TX_LABEL_VLAN_ADDR (0x11000)

/*FDI or AIS发送标签配置*/
#define OAM_FDI_TX_LABEL_VLAN_ADDR (0x13000)


/**STRUCT+********************************************************************/
/*Description: 主动OAM 接收标签寄存器地址偏移                                */
/*                                                                           */
/* Added by dinghao, 2015/10/3  直接配置二叉树的FPGA寄存器                   */
/*****************************************************************************/


/**STRUCT+********************************************************************/
/*Description: 主动OAM COUNT ID寄存器地址                                    */
/*                                                                           */
/* Added by dinghao, 2016/1/20                                               */
/*****************************************************************************/

#define OAM_COUNT_ID_ACTIVE_ADDR (0x5000)


/**STRUCT+********************************************************************/
/*Description: 主动OAM配置寄存器地址偏移                                     */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/

/*CV发送使能寄存器*/
#define CV_TX_ENABLE_OFFSET          (0xa800)

/*CV发送mel寄存器*/
#define CV_TX_MEL_OFFSET               (0xb000)

/*CV发送MEP寄存器*/
#define CV_TX_MEP_OFFSET               (0xb800)

/*CV发送MEG寄存器*/
#define CV_TX_MEG_OFFSET               (0xc000)

/*CV期望周期寄存器*/
#define CV_EXPECT_PRIOD_OFFSET     (0x17800)

/*CV期望MEP寄存器*/
#define CV_EXPECT_MEP_OFFSET     (0x17000)

#define CV_DUAL_ENDED_LM_READ_TIME (0x11)
#define CV_DUAL_ENDED_LM_COUNT (0x1b000)

/*FDI成帧标签使能配置*/
#define FDI_TX_CFG_OFFSET (0Xa000)

/*APS背板与CCU通信方向寄存器配置
item --> oamid*/
#define APS_ITEM_TO_OAM_ID (0x3000)

/*oamid --> item*/
#define APS_OAM_ID_TO_ITEM  (0x10000)

#define APS_PORT_RX_RELATE (0x18000)

/**STRUCT+********************************************************************/
/*Description: 主动OAM MAC地址寄存器地址偏移                                 */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/

#define OAM_FDI_MAC_ADDR (0x5000)
#define OAM_CV_APS_CSF_MAC_ADDR (0x2000)



/**STRUCT+********************************************************************/
/*Description: 主动OAM MAC重定义寄存器地址偏移                               */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/
#define OAM_SMAC_ADAPT_ACTIVE_ADDR (0x1000)



/**STRUCT+********************************************************************/
/*Description: 按需LB/TEST/DM/LCK帧ITMH寄存器地址偏移                        */
/*                                                                           */
/* Added by dinghao, 2015/10/3  在OAM_ADAPTER模块中配置                      */
/*****************************************************************************/
#define OAM_ON_DEMAND_ITMH_ADDR                            (0x8000)


/**STRUCT+********************************************************************/
/*Description: 按需LB/TEST/DM/LCK帧发送标签寄存器地址偏移                    */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/

/*发送TMPLS标签寄存器*/
#define  OAM_LB_TMPLS_TX_ADDR     (0x0080)
#define  OAM_TST_TMPLS_TX_ADDR   (0x0880)
#define  OAM_LCK_TMPLS_TX_ADDR   (0x0c80)

/*发送PW or GAL字节寄存器*/
#define  OAM_LB_PW_GAL_TX_ADDR    (0x00c0) 
#define  OAM_TST_PW_GAL_TX_ADDR  (0x08c0)
#define  OAM_LCK_PW_GAL_TX_ADDR  (0x0cc0)

/*LMM --> 0xa09*/
#define OAM_LMM_TX_LABEL_VLAN (0xa09)
#define OAM_DMM_TX_LABEL_VLAN (0x409)
#define OAM_LMR_TX_LABEL_VLAN (0xc06)
#define OAM_DMR_TX_LABEL_VLAN (0x606)

/**STRUCT+********************************************************************/
/*Description: 按需LB/TEST/DM/LCK帧接收标签寄存器地址偏移                    */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/

/* LB/TST/LCK模块 */
#define OAM_LB_TST_LCK_RX_OFFSET (0xd0)

/* LM/DM模块 */
#define OAM_LM_DM_RX_OFFSET        (0xa0)


/**STRUCT+********************************************************************/
/*Description: 按需LB/TEST/LM/DM/LCK帧头信息寄存器地址偏移                      */
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
/*Description: 按需LB/TEST/LM/DM/LCK发送数据寄存器地址偏移                      */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/
#define    OAM_LB_DATA_TX_ADDR                         (0x00e0)

/**STRUCT+********************************************************************/
/*Description: 按需LB/TEST/DM/LCK MEP/MEG寄存器地址偏移                      */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/
#define MEP_MEG_BASE (0X0100)

/*MEG*/
#define    OAM_ON_DEMAND_MEG_ADDR                              (0x0a)

/*ICC*/
#define    OAM_ON_DEMAND_ICC_ADDR                              (0x01)

/*目的node_id*/
#define    OAM_ON_DEMAND_PEER_NODE_ID_ADDR             (0x04)

/*IF_NUM*/
#define    OAM_ON_DEMAND_IF_NUM_ADDR                        (0x06)

/*CC*/
#define    OAM_ON_DEMAND_CC_ADDR                        (0x08)

/*源node_id*/
#define    OAM_ON_DEMAND_SRC_NODE_ID_ADDR             (0x120)

/*源端MEP*/
#define    OAM_ON_DEMAND_SRC_MEP_ADDR                       (0x09)

/*对端MEP*/
#define    OAM_ON_DEMAND_PEER_MEP_ADDR                      (0x00)


/**STRUCT+********************************************************************/
/*Description: 按需LB/TEST/LM/DM/LCK MAC地址寄存器地址偏移                   */
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
/*Description: 按需LB/TEST/LM/DM/LCK MAC重定义寄存器地址偏移                 */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/
#define OAM_SMAC_ADAPT_ON_DEMAND_ADDR (0x7000)

/**STRUCT+********************************************************************/
/*Description: 按需LM/DM MAC count id寄存器地址偏移                 */
/*                                                                           */
/* Added by dinghao, 2015/12/24                                               */
/*****************************************************************************/
#define OAM_COUNT_ID_ON_DEMAND_ADDR (0x9000)





/**STRUCT+********************************************************************/
/*Description: LM/DM 计数戳地址                                              */
/*                                                                           */
/* Added by dinghao, 2015/10/3                                               */
/*****************************************************************************/

/*TxTimeStampf计数寄存器*/
#define TX_TIMESTPF_OFFSET           (0X0804)

/*RxTimeStampf计数寄存器*/
#define RX_TIMESTPF_OFFSET           (0X0808)

/*TxStampb计数寄存器*/
#define TX_STAMPB_OFFSET              (0x080c)

/*RxStampb计数寄存器*/
#define RX_STAMPB_OFFSET              (0x0800)


/*LMRxPCl寄存器*/
#define LMR_RX_OFFSET                   (0x0e00)

/*LMTxPC_f寄存器*/
#define LMM_TX_OFFSET                 (0x0e02)

/*LMRxPC_f寄存器*/
#define LMM_RX_OFFSET                 (0x0e04)

/*LMTxPC_b寄存器*/
#define LMR_TX_OFFSET                 (0x0e06)


/*按需dm模块*/
#define DEMAND_LM_DM_READ_TIME_OFFSET (0X003)

/*按需帧TST/LCK/LB计数*/
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
