/******************************************************************************

	Copyright (C), 2002-2010, Wuhan FiberHome Tech. Co., Ltd.

 ******************************************************************************
  文 件 名   : oam_alm_pm.h
  版 本 号   : 初稿
  作    者   : 丁浩
  生成日期   : 2014年11月12日
  功能描述   : oam_alm_pm.c的头文件
  修改历史   :
  1.日    期   : 2014年11月12日
    作    者   : 丁浩   
    修改内容   : 创建文件

******************************************************************************/
#ifndef __OAM_ALM_PM_H__
#define __OAM_ALM_PM_H__

#include "oam_public.h"

/**STRUCT+********************************************************************/
/*Description: 公共部分宏定义                                                */
/*                                                                           */
/* Added by dinghao, 2015/10/1                                               */
/*****************************************************************************/
#define MAX_ON_DEMAND_ID_NUM 16
#define MAX_ON_DEMAND_ID    16

/*控制命令相关宏*/
#define CMD_WRONG  -1
#define CMD_RIGHT    0
#define MAX_PTN_GLOBAL_CFG  1   /*目前只有一个*/

/*状态监视查询*/
#define QUERY_SUCCESS 1
#define QUERY_FAIL 0

#define LB_QUERY_CODE 63
#define LCK_QUERY_CODE 64
#define TST_QUERY_CODE 65
#define LM_QUERY_CODE 66
#define DM_QUERY_CODE 67
#define LB_TST_LCK_QUERY_CODE 0x3e



/**STRUCT+********************************************************************/
/*Description: OAM告警寄存器                                                 */
/*                                                                           */
/* Added by dinghao, 2015/10/9                                               */
/*****************************************************************************/
#define OAM_ALARM_OFFSET_READ (0x1800)
#define OAM_LCK_ALARM_OFFSET (0x001b)
#define OAM_LBLOS_ALARM_OFFSET (0x001a)

/*SD告警*/
#define SD_OVERRIDE_OAM (0x4a000) 


/**STRUCT+********************************************************************/
/*Description: OAM性能寄存器                                                 */
/*                                                                           */
/* Added by dinghao, 2015/10/10                                              */
/*****************************************************************************/

/*按需帧LB TST LCK计数*/
#define ON_DEMAND_FRAME_ADDR_OFFSET 0x1


/**STRUCT+********************************************************************/
/*Description: OAM性能告警相关结构体定义                                     */
/*                                                                           */
/* Added by dinghao, 2015/10/10                                              */
/*****************************************************************************/
typedef struct oam_on_demand_cnt
{
    unsigned short lbm_tx_count;
    unsigned short lbm_rx_count;
    unsigned short lbr_tx_count;
    unsigned short lbr_rx_count;
    unsigned short tst_tx_count;
    unsigned short tst_rx_count;
    unsigned short lck_tx_count;
    unsigned short lck_rx_count;
}__attribute__((packed))OAM_ON_DEMAND_CNT;

typedef unsigned char (*oam_phy_port_rlos_func)(unsigned int);


typedef struct oam_alm_report
{
    unsigned char oam_loc_alm;
    unsigned char oam_rdi_alm;
    unsigned char oam_mmg_alm;
    unsigned char oam_unm_alm;
    unsigned char oam_unp_alm;
    unsigned char oam_csf_alm;
    unsigned char oam_ais_alm;
    unsigned char oam_lb_los_alm;
    unsigned char oam_lck_alm;
}__attribute__((packed))OAM_ALM_REPORT;

typedef struct oam_pm_report
{
    unsigned int oam_rx_cv;
    unsigned int oam_tx_cv;
    float oam_pkt_loss_near;
    float oam_pkt_loss_far;
    unsigned int oam_time_delay_ns;
    unsigned int oam_time_delay_var_ns;
}__attribute__((packed))OAM_PM_REPORT;


/**STRUCT+********************************************************************/
/*Description: OAM性能告警函数声明                                           */
/*                                                                           */
/* Added by dinghao, 2015/10/10                                              */
/*****************************************************************************/
int oam_alm_pm_loc(unsigned short item, unsigned char mip_mep,
    unsigned short oam_id, unsigned char *oam_loc_alm);
int oam_alm_pm_rdi(unsigned short item, unsigned char mip_mep,
    unsigned short oam_id, unsigned char *oam_rdi_alm);
int oam_alm_pm_mmg(unsigned short item, unsigned short oam_id, unsigned char *oam_mmg_alm);
int oam_alm_pm_unm(unsigned short item, unsigned short oam_id,unsigned char *oam_unm_alm);
int oam_alm_pm_unp(unsigned short item, unsigned short oam_id, unsigned char *oam_unp_alm);
int oam_alm_pm_csf(unsigned short item, unsigned short oam_id, unsigned char *oam_csf_alm);
int oam_alm_pm_ais(unsigned short item, unsigned short oam_id, unsigned char *oam_ais_alm);
int oam_alm_pm_lb_los(unsigned short oam_id, unsigned char* oam_lb_los_alm);
int oam_alm_pm_lck(unsigned short oam_id, unsigned char* oam_lck);
int oam_alm_pm_pkt_loss_near(unsigned short oam_id, float* oam_pkt_loss_near);
int oam_alm_pm_pkt_loss_far(unsigned short oam_id, float* oam_pkt_loss_far);
int oam_alm_pm_time_delay_ns(unsigned short oam_id, unsigned int* oam_time_delay_ns);
int oam_alm_pm_time_delay_var_ns(unsigned short oam_id, unsigned int* oam_time_delay_var_ns);

int oam_proc_lb_cmd(unsigned char oam_sub_cmd_type);
int oam_proc_tst_cmd(unsigned char oam_sub_cmd_type);
int oam_proc_lck_cmd(unsigned char oam_sub_cmd_type);
int oam_proc_lm_cmd(unsigned char oam_sub_cmd_type);
int oam_proc_dm_cmd(unsigned char oam_sub_cmd_type);
int oam_proc_lb_tst_lck_cmd(unsigned char oam_sub_cmd_type);
int oam_active_proc_mac_dynamic(unsigned short item, unsigned char *smac, unsigned char *dmac);
int oam_on_demand_proc_mac_dynamic(unsigned short item, unsigned char *smac, unsigned char *dmac);


#endif
