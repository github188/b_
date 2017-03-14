/******************************************************************************

	Copyright (C), 2002-2010, Wuhan FiberHome Tech. Co., Ltd.

 ******************************************************************************
  文 件 名   : oam_arad_drv.h
  版 本 号   : 初稿
  作    者   : 丁浩
  生成日期   : 2015年9月23日
  功能描述   : oam_arad_drv.c的头文件
  修改历史   :
  1.日    期   : 2015年9月23日
    作    者   : 丁浩   
    修改内容   : 创建文件

******************************************************************************/
#ifndef _OAM_ARAD_DRV_H_
#define _OAM_ARAD_DRV_H_

#include "oam_public.h"
#define MAX_PTN_GLOBAL_CFG  1   /*目前只有一个*/

extern int oam_create_group(int unit,int group_id,unsigned char *meg_id);
extern int oam_create_mep(int unit, struct mep_info_s *mep_info);
extern int oam_delete_group(int unit,int group_id);
extern int oam_delete_mep(int unit,int mep_index);
extern int oam_get_traffic_info(unsigned short tpoam_id, unsigned char type, TP_OAM_LSP_CFG *LspRxCfg);
extern int oam_age_timer_set(int ageTime);
extern int oam_cfg_term_tunnel_range(int min_temp, int max_temp);
extern int oam_get_frame_type(void);
extern unsigned int oam_fpga_addr_get(void);
extern int oam_get_lag_member_info(unsigned char key_lag_id, unsigned char *slot, unsigned char *port);

#endif

