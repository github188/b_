/***********************************************************************************

 * 文 件 名   : bfd_get_extern_info.h
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年11月1日
 * 版 本 号   : 
 * 文件描述   : bfd_get_extern_info.c 的头文件
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#ifndef __BFD_GET_EXTERN_INFO_H__
#define __BFD_GET_EXTERN_INFO_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */


typedef struct bfd_lsp_cfg_info
{
    
}BFD_LSP_CFG_INFO;

extern unsigned char reg_block_by_external_module(unsigned char blockid, unsigned char ken_len, 
    unsigned long size_of_element, unsigned long max_elment_num, int (*func)(unsigned char **, unsigned char));


extern unsigned int bfd_get_fapid(IN unsigned char slot);
extern RESULT_BFDCFG bfd_get_vc_traffic_info(IN unsigned long bfd_id, OUT BFD_LSP_CFG_INFO* lsp_cfg);
extern RESULT_BFDCFG bfd_init_get_extern_info();
extern int oam_get_traffic_info(unsigned long bfd_myid, unsigned char type, TP_OAM_LSP_CFG *LspRxCfg);
extern int oam_traffic_info_print(TP_OAM_LSP_CFG *oam_traffic_info, IN int level);
extern int tp_oam_get_traffic_plus(unsigned long bfd_myid, unsigned char type, TP_OAM_LSP_CFG *LspRxCfg);
extern int tp_oam_get_vc_traffic_info(unsigned long bfd_myid, TP_OAM_LSP_CFG *LspRxCfg);
extern int tp_oam_get_vp_traffic_info(unsigned long bfd_myid, TP_OAM_LSP_CFG *LspRxCfg);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BFD_GET_EXTERN_INFO_H__ */
