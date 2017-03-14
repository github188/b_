/***********************************************************************************

 * 文 件 名   : bfd_common.c
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年12月2日
 * 版 本 号   : 
 * 文件描述   : BFD通用代码
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#include "bfd.h"


/* BFD模块错误码解析 */
const char * const result_str[] = {
    "CFG_OK",                 /* 增加或删除条目操作成功 */
    "PARAM_ERROR",            /* 参数错误 */
    "KEY_NOT_EQUAL_MYID",     /* key值错误，与本地描述符不相等 */
    "KEY_NOT_EXIST",          /* KEY值不存在 */
    "SET_DRIVE_ERROR",        /* 写驱动失败 */
    "ALLOC_ERROR",            /* 申请内存空间时失败 */
    "ADD_KEY_EXIST",          /* 该key已存在 */
    "CFG_FULL",               /* 配置已满 */
    "FUC_NULL",               /* 回调函数未注册 */
    "INSERT_ERR",             /* 配置树中增加节点失败 */
    "FORCED_END",             /* 强制终结，一般调试用，不执行函数实现，直接返回 */
    "FRAME_TYPE_ERR",         /* 发帧类型错误或不支持 */
    "SET_ARAD",               /* 写ARAD错误 */
    "FPGA_STORT_NULL",        /* 未分配存储FPGA的数据空间 */
    "KEY_NOT_MATCH",          /* KEY值不匹配 */
    "FPGA_MYID_TREE",         /* 操作FPGA使用的二叉树失败 */
    "IP_TYPE_ERR",            /* IP类型错误 */
    "FUNC_RET_ERR",           /* 调用其他接口返回错误 */
    "LIST_NULL",              /* 链表为空 */
    "CFG_RESULT_MAX"};

const char * const g_bfd_state_str[BFD_STA_BUTT] = {"Admin", "Down", "Init", "Up"};
const char * const g_bfd_interval_str[BFD_TIME_BUTT] = {"None",      /* 收发包技术的记录从1开始，此处定义忽略0号位 */
                                "3.3ms", "10ms", "20ms", "30ms", "40ms", "50ms", "60ms", "70ms", "80ms", "90ms", "100ms",
                                "200ms", "300ms", "400ms", "500ms", "150ms", "250ms", "350ms", "450ms", "1000ms"};
const char * const g_bfd_action_str[BFD_ACTION_NONE + 1] = {"ADMIN", "DOWN", "INIT", "UP", "TIMEOUT", "NONE"};