/***********************************************************************************

 * �� �� ��   : bfd_stub.h
 * �� �� ��   : jiangbo,����
 * ��������   : 2016��11��25��
 * �� �� ��   : 
 * �ļ�����   : bfd_stub.c ��ͷ�ļ�
 * ��Ȩ˵��   : Copyright (C) 2000-2016   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 

***********************************************************************************/

#ifndef __BFD_STUB_H__
#define __BFD_STUB_H__


#ifdef __cplusplus
#if __cplusplus
{
extern "C"
#endif
#endif /* __cplusplus */

#ifdef X86_UINT_TEST

extern int oam_get_traffic_info_stub(unsigned long bfd_myid, unsigned char type, TP_OAM_LSP_CFG *LspRxCfg);

#define BFD_STUB_FPGA_MAC_ADDR BFD_FPGA_BFD_ETH_ANALYSER_BASE

#define oam_get_traffic_info oam_get_traffic_info_stub

#ifndef USE_BMU_LIB
#define BmuGetBoardAddr BmuGetBoardAddr_stub
#define BmuLog BmuLog_stub
#define GetSysClock GetSysClock_stub
#endif

extern UINT16 BmuGetBoardAddr_stub(void);
extern int BmuLog_stub(const char *file, const char *fun, const int line, int level, const char *logfile, const char *fmt, ...);
extern int fhdrv_fap_udf_entry_create(int unit, drv_udf_key_t* key, drv_udf_action_t* action);
extern int fhdrv_fap_udf_entry_destroy(int unit,int entry);
extern void GetSysClock_stub(struct SYSTIME *pstuClock);
extern char get_frame_type();
extern int malloc_fpga_base_addr();
extern int oam_get_traffic_info_stub(unsigned long bfd_myid, unsigned char type, TP_OAM_LSP_CFG *LspRxCfg);
extern unsigned int ptn_fpga_base_addr_get();
extern unsigned char reg_block_by_external_module(unsigned char blockid, unsigned char ken_len, 
    unsigned long size_of_element, unsigned long max_elment_num, int (*func)(unsigned char **, unsigned char));


#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BFD_STUB_H__ */
