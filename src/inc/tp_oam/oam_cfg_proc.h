/******************************************************************************

	Copyright (C), 2002-2010, Wuhan FiberHome Tech. Co., Ltd.

 ******************************************************************************
  �� �� ��   : oam_cfg_proc.h
  �� �� ��   : ����
  ��    ��   : ����
  ��������   : 2014��10��25��
  ��������   : oam_cfg_proc.c��ͷ�ļ�
  �޸���ʷ   :
  1.��    ��   : 2014��10��25��
    ��    ��   : ����   
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __OAM_CFG_PROC_H__
#define __OAM_CFG_PROC_H__

#include "oam_public.h"

/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/


 /*----------------------------------------------*
 * �궨��                                       *
 *----------------------------------------------*/
#define MAX_ON_DEMAND_ID    16
#define MAX_OAM_VS_ID       20      /*��Ŀ����,�ж��ٸ�����ڣ����ж���vs id*/
#define MAX_PTN_GLOBAL_CFG  1   /*Ŀǰֻ��һ��*/

#define KEY_OAM_ACTIVE    2
#define KEY_PTN_GLOBAL    1
#define KEY_OAM_ON_DEMAND 1     /*�����϶���KEY_OAM_ON_DEMAND�µ�ʱ��Ϊ1��������������ȷ�������ֽ�*/
#define KEY_OAM_VS        2


#define CHARACTER_LEN 1
#define SEQ_LEN 4
#define CONFIG_LEN 4
#define SUB_CFG_TYPE 1
#define SUB_CFG_LEN  2
#define FROM_CHARACTER_TO_SUB_CFG_LEN 12

#define OAM_ACTIVE_CFG_LEVEL     1  
#define OAM_ON_DEMAND_CFG_LEVEL  2
#define OAM_GLOBAL_CFG_LEVEL     3

#define OAM_CFG_FLAG_2 2
#define OAM_CFG_FLAG_1 1
#define OAM_CFG_FLAG_0 0

#define SUB_CFG_LEN_VALUE 35

#define SUB_CFG_LEN_ACTIVE 45

#define SUB_CFG_LEN_ON_DEMAND_BASE   40
#define SUB_CFG_LEN_ON_DEMAND_MIP    35
#define SUB_CFG_LEN_ON_VS            45
#define SUB_CFG_LEN_PTN_GLOBAL_BASE  50

#define SUB_CFG_LEN_CFM_OAM 10
#define SUB_CFG_LEN_EFM_OAM 10
#define SUB_CFG_LEN_MPLS_TP_OAM      38 


#define MAX_PKT_LEN   100
#define MAX_ON_DEMAND_ID_NUM 16

#define OAM_CREATE_MODE_MEP 1
#define OAM_CREATE_MODE_ACL 2

extern int oam_create_lmm_packet(unsigned char level,unsigned short on_demand_id,TX_LABEL_CFG *tx_label_cfg);
extern int oam_create_dmm_packet(unsigned char level,unsigned short on_demand_id,TX_LABEL_CFG *tx_label_cfg);
extern int oam_lm_dm_init(void);
extern int oam_alloc_local_oam_id(unsigned short global_oam_id,unsigned short* local_oam_id);
extern int oam_dealloc_local_oam_id(unsigned short local_oam_id);
extern int oam_almpm_init(void);
extern int oam_create_acl(int unit, unsigned int pw_lif, unsigned int pw,
    unsigned int ach, unsigned short sysport, int *entry_oam_id);
extern int oam_delete_acl(int unit, int entry_oam_id);
extern int oam_get_sysport_count(int unit, int fpga_sysport, int oam_type, char* create_pmf_flag);


#endif