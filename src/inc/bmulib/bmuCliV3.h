/******************************************************************************
*  文 件 名    : bmuCliV3.h
*  负 责 人    : qhxiong
*  创建日期 : 2013年6月25日星期二
*  版 本 号    : V1.0
*  文件描述 : bmulib公共库shell命令行调试接口头文件
*  版权说明 : Copyright (c) 2000-2020   烽火通信科技股份有限公司
*  其    他	        : 无
*  修改日志 :
******************************************************************************/
#ifndef __BMUCLIV3_H__
#define __BMUCLIV3_H__

#ifdef  __cplusplus
extern  "C" {
#endif  /* __cplusplus */

/*****************************************************************************
* 函 数 名      : CliCmdInit
* 负 责 人      : qhxiong
* 创建日期  : 2013年4月22日星期一
* 函数功能  : 调试命令行初始化
* 输入参数  : const char *pProcessName  进程名字符串
*                           const char *pDev      telnet服务端绑定网卡设备名
*                           int iPort       telnet服务端绑定端口号
                        9000 - 母卡
                        9001 - 子卡1
                        9002 - 子卡2
* 输出参数  : 无
* 返 回 值      :
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int CliCmdInit(const char *pProcessName, const char *pDev, int iPort);

#ifdef  __cplusplus
}
#endif  /* __cplusplus */

#endif
