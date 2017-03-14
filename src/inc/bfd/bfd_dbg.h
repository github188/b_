/***********************************************************************************

 * �� �� ��   : bfd_dbg.h
 * �� �� ��   : jiangbo,����
 * ��������   : 2016��10��19��
 * �� �� ��   : 
 * �ļ�����   : bfd_dbg.c ��ͷ�ļ�
 * ��Ȩ˵��   : Copyright (C) 2000-2016   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 

***********************************************************************************/

#ifndef __BFD_DBG_H__
#define __BFD_DBG_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */

#define BFD_PRT_FPGA_INDEX_LEN  5               /* FPGA�����±��ӡ���� */
#define BFD_PRT_FUC_NAME_LEN   85               /* �������ƴ�ӡ���� */
#define BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN   38  /* FPGA��ַƫ�����ƴ�ӡ���� */
#define BFD_PRT_FPGA_ADDR_OFFSET_LEN   10       /* FPGA��ַƫ�ƴ�ӡ���� */
#define BFD_PRT_FPGA_INFO_HEAD_NAME_LEN   10    /* FPGA��Ϣ�������ƴ�ӡ���� */
#define BFD_PRT_FPGA_INFO_NAME_LEN   12         /* FPGA��Ϣ��Ա���ƴ�ӡ���� */
#define BFD_PRT_FPGA_INFO_DATA_LEN   41         /* FPGA��Ϣ��Ա���ݴ�ӡ����(��󳤶ȼ������ո�) */
#define BFD_PRT_BFD_ID_LEN           10         /* BFD��������ӡ���� */
#define BFD_PRT_FPGA_COUNT_DATA_LEN  5          /* FPGA���շ���������ӡ���� */
#define BFD_PRT_CFG_NAME_LEN         27         /* BFD���õ����ƴ�ӡ���� */
#define BFD_PRT_STATE_LEN            10         /* BFD״̬��ӡ���� */
#define BFD_PRT_ACTION_LEN           7          /* BFD������ӡ���� */
#define BFD_PRT_DIAG_LEN             5          /* BFD downԭ���ӡ���� */
#define BFD_PRT_PKT_COUNT            6          /* BFD��������ӡ���� */

extern RESULT_BFDCFG bfd_analyze_bfd_cfg(IN BFD_CFG *cfg, IN int level);
extern NBB_VOID bfd_dbg_help(NBB_VOID);
extern NBB_VOID bfd_fpga_help();
extern NBB_VOID bfd_help();
extern RESULT_BFDCFG bfd_print_alarm_data(BFD_ALARM_DATABASE *alarm_data);
extern void bfd_print_alarm_head();
extern void bfd_print_bfd_adapt_fpga(IN unsigned long offset, IN unsigned int num);
extern void bfd_print_bfd_model_fpga(IN unsigned long offset, IN unsigned int num);
extern RESULT_BFDCFG bfd_print_cfg(BFD_CFG_DATABASE* cfg);
extern void bfd_print_fpga_ipv4(IN BFD_IP_HEAD *ip_head_local, IN BFD_IP_HEAD *ip_head_fpga);
extern void bfd_print_fpga_ipv6(IN BFD_IP_HEAD *ip_head_local, IN BFD_IP_HEAD *ip_head_fpga);
extern void bfd_set_fpga_capture_packet(unsigned char directon);
extern void bfd_set_fpga_loop(NBB_BOOL flag);
extern NBB_VOID bfd_set_help();
extern void bfd_show_alarm(IN unsigned long bfd_sid);
extern void bfd_show_all_alarm();
extern void bfd_show_all_cfg();
extern void bfd_show_anti_attack_info_by_index(IN unsigned short start_index, IN unsigned short end_index);
extern void bfd_show_anti_attack_info_by_myid(IN unsigned long bfd_sid);
extern void bfd_show_cfg(IN unsigned long my_sid);
extern NBB_VOID bfd_show_counter_by_index(IN unsigned short start_index, IN unsigned short end_index);
extern void bfd_show_counter_by_myid(IN unsigned long bfd_sid);
extern void bfd_show_fpga_by_index(IN unsigned short index);
extern void bfd_show_fpga_by_myid(IN unsigned long bfd_sid);
extern void bfd_show_fpga_capture_packet();
extern void bfd_show_fpga_discr_by_index(IN unsigned short index, IN NBB_BOOL not_need_head );
extern void bfd_show_fpga_discr_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head);
extern void bfd_show_fpga_function_by_index(IN unsigned short index, IN NBB_BOOL not_need_head );
extern void bfd_show_fpga_function_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head);
extern void bfd_show_fpga_head_by_index(IN unsigned short index, IN char *head_name, IN NBB_BOOL not_need_head);
extern void bfd_show_fpga_ip_by_index(IN unsigned short index, IN NBB_BOOL not_need_head );
extern void bfd_show_fpga_ip_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head);
extern void bfd_show_fpga_label_by_index(IN unsigned short index, IN NBB_BOOL not_need_head);
extern void bfd_show_fpga_label_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head);
extern void bfd_show_fpga_mac_by_index(IN unsigned short index, IN NBB_BOOL not_need_head);
extern void bfd_show_fpga_mac_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head);
extern void bfd_show_fpga_state_interval_by_index(IN unsigned short index, IN NBB_BOOL not_need_head );
extern void bfd_show_fpga_state_interval_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head);
extern void bfd_show_fpga_sysport_by_index(IN unsigned short index, IN NBB_BOOL not_need_head );
extern void bfd_show_fpga_sysport_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head);
extern void bfd_show_fpga_udp_by_index(IN unsigned short index, IN NBB_BOOL not_need_head );
extern void bfd_show_fpga_udp_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head);
extern void bfd_show_oam_bfd_cfg_info (IN unsigned long my_sid);
extern void bfd_show_oam_cfg_info (IN unsigned long my_sid, IN unsigned char bfd_frame_type);
extern void bfd_show_state_by_index(IN unsigned short start_index, IN unsigned short end_index);
extern void bfd_show_state_by_myid(IN unsigned long bfd_sid);
extern void bfd_version();
extern NBB_VOID bfd_wlog();
extern int bfd_write_bfd_adapt_fpga(IN unsigned long offset, IN unsigned short data);
extern int bfd_write_bfd_model_fpga(IN unsigned long offset, IN unsigned short data);
extern RESULT_BFDCFG hw_print_fpga(IN unsigned long base_offset, IN unsigned long offset, IN unsigned int num);
extern void hw_print_fpga_base_offset_addr(IN unsigned char level);
extern RESULT_BFDCFG hw_write_fpga(IN unsigned long base_offset, IN unsigned long offset, IN unsigned short data);
extern RESULT_BFDCFG hw_write_fpga_batch(IN unsigned long base_offset,
             IN unsigned long addr,
             IN unsigned long addr_off,
             IN unsigned short data,
             IN unsigned short date_off,
             IN unsigned short num);
extern RESULT_BFDCFG bfd_analyze_bfd_set_arad(IN drv_udf_key_t *key, 
    IN drv_udf_action_t *action, 
    IN int level);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BFD_DBG_H__ */

