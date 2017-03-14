/***********************************************************************************

 * 文 件 名   : bfd_cfg_proc.h
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年11月8日
 * 版 本 号   : 
 * 文件描述   : bfd_cfg_proc.c 的头文件
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#ifndef __BFD_CFG_PROC_H__
#define __BFD_CFG_PROC_H__


#ifdef __cplusplus
#if __cplusplus
{
extern "C"
#endif
#endif /* __cplusplus */

extern int bfd_active_cfg_process(IN unsigned char **cfg_data, IN unsigned char mes_type);
extern RESULT_BFDCFG bfd_add_cfg(IN BFD_BASIC_DATA *cfg, OUT unsigned short *fpga_index, OUT int *arad_index);
extern RESULT_BFDCFG bfd_add_lsp_cfg(IN BFD_BASIC_DATA *cfg, OUT unsigned short *fpga_index, OUT int *arad_index);
extern RESULT_BFDCFG bfd_add_pw_cfg(IN BFD_BASIC_DATA *cfg, OUT unsigned short *fpga_index, OUT int *arad_index);
extern RESULT_BFDCFG bfd_cfg_pro(IN BFD_CFG *cfg);
extern int bfd_decode_cfg(IN unsigned char **cfg_data, OUT BFD_CFG *cfg);
extern RESULT_BFDCFG bfd_del_all_cfg(IN BFD_CFG_DATABASE* cfg_database);
extern RESULT_BFDCFG bfd_del_arad(IN int index);
extern RESULT_BFDCFG bfd_del_cfg(IN unsigned long key, IN unsigned short fpga_index, IN int arad_index);
extern RESULT_BFDCFG bfd_find_cfg_tab(IN BFD_CFG_DATABASE* cfg_database);
extern NBB_INT bfd_init();
extern RESULT_BFDCFG bfd_modify_cfg(IN BFD_CFG *cfg, 
             IN BFD_CFG_DATABASE * cfg_data, 
             INOUT unsigned short fpga_index, 
             INOUT int arad_index);
extern RESULT_BFDCFG bfd_set_arad(IN unsigned char bfd_type, IN TP_OAM_LSP_CFG* oam_traffic_info, OUT int *arad_index);



#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BFD_CFG_PROC_H__ */
