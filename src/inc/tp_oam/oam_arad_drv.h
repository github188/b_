/******************************************************************************

	Copyright (C), 2002-2010, Wuhan FiberHome Tech. Co., Ltd.

 ******************************************************************************
  �� �� ��   : oam_arad_drv.h
  �� �� ��   : ����
  ��    ��   : ����
  ��������   : 2015��9��23��
  ��������   : oam_arad_drv.c��ͷ�ļ�
  �޸���ʷ   :
  1.��    ��   : 2015��9��23��
    ��    ��   : ����   
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef _OAM_ARAD_DRV_H_
#define _OAM_ARAD_DRV_H_

#include "oam_public.h"
#define MAX_PTN_GLOBAL_CFG  1   /*Ŀǰֻ��һ��*/

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

