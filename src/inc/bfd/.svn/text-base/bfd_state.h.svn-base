/***********************************************************************************

 * 文 件 名   : bfd_state.h
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年11月17日
 * 版 本 号   : 
 * 文件描述   : bfd_state.c 的头文件
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#ifndef __BFD_STATE_H__
#define __BFD_STATE_H__


#ifdef __cplusplus
#if __cplusplus
{
extern "C"
#endif
#endif /* __cplusplus */

typedef struct bfd_state_transfer
{
    NBB_BOOL transfer_flag;    /* 状态迁移标记，有跳变赋值为TRUE，否则为FALSE */
    BFD_STATE state;
}BFD_STATE_TRANSFER;

extern RESULT_BFDCFG bfd_fsm_modify_fpga(IN unsigned short index, IN BFD_FPGA_INFO *fpga_info,
             IN BFD_STATE_TRANSFER *new_state);
extern RESULT_BFDCFG bfd_finite_state_machine_transfer(IN BFD_STATE *last_state,
             IN EN_BFD_RECV_ACTION recv_action,
             OUT BFD_STATE_TRANSFER *new_state);
extern RESULT_BFDCFG bfd_get_fpga_recv_action(IN unsigned short index,
             IN BFD_FPGA_REG_DIAG_STATE *last_session_state,
             IN BFD_STATE *last_state,
             OUT EN_BFD_RECV_ACTION *recv_action);
extern RESULT_BFDCFG bfd_run_all_state_machine();
extern RESULT_BFDCFG bfd_run_state_machine(IN unsigned short index);
extern RESULT_BFDCFG bfd_run_state_machine_by_cfg_data(IN BFD_CFG_DATABASE* cfg_data);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BFD_STATE_H__ */
