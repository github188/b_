/******************************************************************************
 *  文 件 名    : bmuOsHdrs.h
 *  负 责 人    : zhaojzh
 *  创建日期 : 2013年6月25日星期二
 *  版 本 号    : V1.0
 *  文件描述 : bmulib os api总控头文件
 *  版权说明 : Copyright (c) 2000-2020   烽火通信科技股份有限公司
 *  其    他	        : 无
 *  修改日志 :
 ******************************************************************************/
#ifndef __BMUOSHDRS_H__
#define __BMUOSHDRS_H__

#ifdef __cplusplus
extern "C" {
#endif  /*__cplusplus*/

#define BMU_ERROR                                        -1
#define BMU_OK                                          0
typedef int (*BMU_PFUNC)(void *);

#include "bmuOsComm.h"

/*linux os*/
#if     defined(USING_LINUX_OS)
#include "bmuLinuxOsLib.h"

/*************** linux os api通用宏定义 ***************/
#define BMU_SYS_V_SEM_CREATE								0
#define BMU_SYS_V_SEM_OPEN								1
#define BMU_SEM_DEFAULT_MUTEX                           0x80
#define BMU_SEM_Q_PRIORITY                              1
#define BMU_SEM_Q_FIFO                                  0
#define BMU_SEM_DELETE_SAFE                             4
#define BMU_SEM_INVERSION_SAFE                  8
#define BMU_SEM_EVENTSEND_ERR_NOTIFY            0x10
#define BMU_SEM_EMPTY                                   0
#define BMU_SEM_FULL                                    1
#define BMU_NO_WAIT                             IPC_NOWAIT
#define BMU_WAIT_FOREVER                                0
#define BMU_MSG_PRI_NORMAL                              0
#define BMU_MSG_PRI_URGENT                              1
#define BMU_MSG_Q_FIFO                                  0
#define BMU_MSG_Q_PRIORITY                              1
#define BMU_MSG_Q_EVENTSEND_ERR_NOTIFY          2

#define BMU_INVALID_TASK_ID                     -1
#define BMU_INVALID_SEM_ID                              NULL
#define BMU_INVALID_MUTEX_ID                    NULL
#define BMU_INVALID_WDOG_ID                     NULL
#define BMU_INVALID_MSG_ID                              -1
#define BMU_INVALID_UDP_ID                              NULL
#define BMU_DEFAULT_WDOG_TICK                           0

/*************** linux os api通用数据类型 ***************/
typedef pthread_t BMU_TASK_ID;
typedef sem_t *BMU_SEM_ID;
typedef struct BMU_OS_SEM_NODE *BMU_OS_SEM_ID;
typedef struct BMU_OS_SEM_NODE *BMU_BIN_SEM_ID;
typedef int BMU_SYS_V_SEM_ID;
typedef pthread_mutex_t *BMU_MUTEX_ID;
typedef pthread_rwlock_t *BMU_RWLOCK_ID;
typedef struct BMU_WDOG_TIMER_NODE *BMU_WDOG_ID;
typedef int BMU_MSG_Q_ID;
typedef struct BMU_UDP_IPC_INFO *BMU_UDP_ID;

//typedef int (*FUNCPTR)();

/*vxworks os*/
#elif defined(USING_VXWORKS_OS)
#include "bmuVxWorksOsLib.h"

/*************** vxworks os api通用宏定义 ***************/
#define BMU_SEM_DEFAULT_MUTEX                           0x80
#define BMU_SEM_Q_PRIORITY                              SEM_Q_PRIORITY
#define BMU_SEM_Q_FIFO                                  SEM_Q_FIFO
#define BMU_SEM_DELETE_SAFE                             SEM_DELETE_SAFE
#define BMU_SEM_INVERSION_SAFE                  SEM_INVERSION_SAFE
#define BMU_SEM_EVENTSEND_ERR_NOTIFY            SEM_EVENTSEND_ERR_NOTIFY
#define BMU_SEM_EMPTY                                   SEM_EMPTY
#define BMU_SEM_FULL                                    SEM_FULL
#define BMU_NO_WAIT                             NO_WAIT
#define BMU_WAIT_FOREVER                                WAIT_FOREVER
#define BMU_MSG_PRI_NORMAL                              MSG_PRI_NORMAL
#define BMU_MSG_PRI_URGENT                              MSG_PRI_URGENT
#define BMU_MSG_Q_FIFO                                  MSG_Q_FIFO
#define BMU_MSG_Q_PRIORITY                              MSG_Q_MSG_Q_PRIORITY
#define BMU_MSG_Q_EVENTSEND_ERR_NOTIFY          MSG_Q_EVENTSEND_ERR_NOTIFY

#define BMU_INVALID_TASK_ID                     -1
#define BMU_INVALID_SEM_ID                              NULL
#define BMU_INVALID_MUTEX_ID                    NULL
#define BMU_INVALID_WDOG_ID                     NULL
#define BMU_INVALID_MSG_ID                              NULL

/*************** vxworks os api通用数据类型 ***************/
typedef int BMU_TASK_ID;
typedef SEM_ID BMU_SEM_ID;
typedef SEM_ID BMU_MUTEX_ID;
typedef WDOG_ID BMU_WDOG_ID;
typedef MSG_Q_ID BMU_MSG_Q_ID;
#endif

/*linux专用接口*/
#ifdef USING_LINUX_OS

/*****************************************************************************
* 函 数 名      : BmuPthreadExit
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib线程退出
* 输入参数  : int iRet  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuPthreadExit(int iRet);

/*****************************************************************************
* 函 数 名      : BmuAllPthreadBlockWait
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib线程阻塞等待
* 输入参数  : void  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern void BmuAllPthreadBlockWait(void);

/*****************************************************************************
* 函 数 名      : BmuAllTaskDelete
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib删除所有线程
* 输入参数  : void  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern void BmuAllTaskDelete(void);

/*****************************************************************************
* 函 数 名      : BmuTaskShow
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib根据线程id显示线程属性
* 输入参数  : BMU_TASK_ID taskId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuTaskShow(BMU_TASK_ID taskId);

/*****************************************************************************
* 函 数 名      : BmuAllTaskShow
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib显示所有线程属性
* 输入参数  : void  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern void BmuAllTaskShow(void);

/*****************************************************************************
* 函 数 名      : BmuSystem
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib系统调用，用于启动脚本与shell命令
* 输入参数  : const char *pCmd  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuSystem(const char *pCmd);

/*****************************************************************************
* 函 数 名      : BmuSetPthreadSigBlock
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib设置线程阻塞接收指定信号
* 输入参数  : int iSignal  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuSetPthreadSigBlock(int iSignal);

/*****************************************************************************
* 函 数 名      : BmuGetPidByName
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib通过可执行文件名获取进程id
* 输入参数  : const char *pDirFileName  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuGetPidByName(const char *pDirFileName);

/*****************************************************************************
* 函 数 名      : BmuLoadAppFile
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib加载进程运行
* 输入参数  : const char *pDirFileName  
*                           const char *pArgvName     
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuLoadAppFile(const char *pDirFileName, const char *pArgvName);

/*****************************************************************************
* 函 数 名      : BmuUnLoadAppFile
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib卸载进程
* 输入参数  : const char *pDirFileName  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuUnLoadAppFile(const char *pDirFileName);

/*****************************************************************************
* 函 数 名      : BmuTranslatePriority
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib 将vxworks任务优先级转换成linux线程优先级
* 输入参数  : int v2pthread_priority  
*                           int sched_policy        
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuTranslatePriority(int v2pthread_priority, int sched_policy);

/*****************************************************************************
* 函 数 名      : BmuEthDevShow
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib显示网卡信息
* 输入参数  : void  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuEthDevShow(void);

/*****************************************************************************
* 函 数 名      : BmuTaskTestPoint
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib线程测试点
* 输入参数  : void  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuTaskTestPoint(void);

/*****************************************************************************
* 函 数 名      : BmuSaftBoot
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib安全启动接口
* 输入参数  : void  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuSaftBoot(void);

/*二进制信号量实现同步*/
/*****************************************************************************
* 函 数 名      : BmuOSSemCreate
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib系统信号量创建
* 输入参数  : int iInitCount  
*                           int iMaxCount   
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern BMU_OS_SEM_ID BmuOSSemCreate(int iInitCount, int iMaxCount);

/*****************************************************************************
* 函 数 名      : BmuOSSemTake
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib系统信号量获取操作
* 输入参数  : BMU_OS_SEM_ID semId  
*                           int iTicks           
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuOSSemTake(BMU_OS_SEM_ID semId, int iTicks);

/*****************************************************************************
* 函 数 名      : BmuOSSemGive
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib系统信号量释放操作
* 输入参数  : BMU_OS_SEM_ID semId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuOSSemGive(BMU_OS_SEM_ID semId);

/*****************************************************************************
* 函 数 名      : BmuOSSemDelete
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib系统信号量删除操作
* 输入参数  : BMU_OS_SEM_ID semId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuOSSemDelete(BMU_OS_SEM_ID semId);

/*************** bmulib二进制信号量宏定义 ***************/
#define BmuBinSemCreate(iCount)         BmuOSSemCreate(iCount, 1)
#define BmuBinSemTake(semId, iTicks)    BmuOSSemTake(semId, iTicks)
#define BmuBinSemGive(semId)            BmuOSSemGive(semId)
#define BmuBinSemDelete(semId)          BmuOSSemDelete(semId)

/*进程间Sye信号量*/

/*****************************************************************************
* 函 数 名      : BmuSysVSemCreate
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib system v信号量创建
* 输入参数  : int iHandleType  
*                           int iKeyNum      
*                           int iCount       
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern BMU_SYS_V_SEM_ID BmuSysVSemCreate(int iHandleType, int iKeyNum, int iCount);

/*****************************************************************************
* 函 数 名      : BmuSysVSemTake
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib system v信号量获取接口
* 输入参数  : BMU_SYS_V_SEM_ID semId  
*                           int iTicks              
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuSysVSemTake(BMU_SYS_V_SEM_ID semId, int iTicks);

/*****************************************************************************
* 函 数 名      : BmuSysVSemGive
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib system v信号量释放接口
* 输入参数  : BMU_SYS_V_SEM_ID semId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuSysVSemGive(BMU_SYS_V_SEM_ID semId);

/*****************************************************************************
* 函 数 名      : BmuSysVSemDelete
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib system v信号量删除接口
* 输入参数  : BMU_SYS_V_SEM_ID semId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuSysVSemDelete(BMU_SYS_V_SEM_ID semId);

/*读写锁*/

/*****************************************************************************
* 函 数 名      : BmuRWLockCreate
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib 读写锁创建
* 输入参数  : int iOptions  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern BMU_RWLOCK_ID BmuRWLockCreate(int iOptions);

/*****************************************************************************
* 函 数 名      : BmuWrLock
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib 写锁获取操作
* 输入参数  : BMU_RWLOCK_ID rwlockId  
*                           int iTicks              
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuWrLock(BMU_RWLOCK_ID rwlockId, int iTicks);

/*****************************************************************************
* 函 数 名      : BmuRdLock
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib 读锁获取操作
* 输入参数  : BMU_RWLOCK_ID rwlockId  
*                           int iTicks              
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuRdLock(BMU_RWLOCK_ID rwlockId, int iTicks);

/*****************************************************************************
* 函 数 名      : BmuUnlock
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib 解锁操作
* 输入参数  : BMU_RWLOCK_ID rwlockId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuUnlock(BMU_RWLOCK_ID rwlockId);

/*****************************************************************************
* 函 数 名      : BmuRWLockDelete
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib读写锁删除操作
* 输入参数  : BMU_RWLOCK_ID rwlockId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuRWLockDelete(BMU_RWLOCK_ID rwlockId);

/*进程间UDP通信*/
/*****************************************************************************
* 函 数 名      : BmuUdpServerCreate
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib udp服务器创建
* 输入参数  : int iPort  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern BMU_UDP_ID BmuUdpServerCreate(int iPort);

/*****************************************************************************
* 函 数 名      : BmuUdpClientCreate
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib udp客户端创建
* 输入参数  : int iPort  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern BMU_UDP_ID BmuUdpClientCreate(int iPort);

/*****************************************************************************
* 函 数 名      : BmuUdpSend
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib udp发送函数
* 输入参数  : BMU_UDP_ID udpId    
*                           char *pBuffer       
*                           unsigned int uiLen  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuUdpSend(BMU_UDP_ID udpId, char *pBuffer, unsigned int uiLen);
extern int BmuUdpRecv(BMU_UDP_ID udpId, char *pBuffer, unsigned int uiLen, int iTimeOut);
extern int BmuUdpDelete(BMU_UDP_ID udpId);

/*posix消息队列*/
/*****************************************************************************
* 函 数 名      : BmuQueueCreate
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib posix消息队列创建
* 输入参数  : const char *pQName  
*                           int iMaxMsgs        
*                           int iMaxMsgLength   
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern BMU_MSG_Q_ID BmuQueueCreate(const char *pQName, int iMaxMsgs, int iMaxMsgLength);

/*****************************************************************************
* 函 数 名      : BmuQueueSend
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib posix消息队列发送
* 输入参数  : BMU_MSG_Q_ID msgQId  
*                           char *pBuffer        
*                           unsigned int uiLen   
*                           int iTimeOut         
*                           int iPriority        
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuQueueSend(BMU_MSG_Q_ID msgQId, char *pBuffer, unsigned int uiLen, int iTimeOut, int iPriority);

/*****************************************************************************
* 函 数 名      : BmuQueueRecv
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib posix消息队列接收
* 输入参数  : BMU_MSG_Q_ID msgQId  
*                           char *pBuffer        
*                           unsigned int uiLen   
*                           int iTimeOut         
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuQueueRecv(BMU_MSG_Q_ID msgQId, char *pBuffer, unsigned int uiLen, int iTimeOut);

/*****************************************************************************
* 函 数 名      : BmuQueueDelete
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib posix消息队列删除
* 输入参数  : BMU_MSG_Q_ID msgQId  
*                           const char *pQName   
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuQueueDelete(BMU_MSG_Q_ID msgQId, const char *pQName);

/*****************************************************************************
* 函 数 名      : BmuQueueNum
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib获取posix消息队列中消息个数
* 输入参数  : BMU_MSG_Q_ID msgQId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuQueueNum(BMU_MSG_Q_ID msgQId);

/*终端重定向接口*/
/*****************************************************************************
* 函 数 名      : BmuRedirectConsole
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib标志输入、输出及出错重定向
* 输入参数  : int *piConsoleFd  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuRedirectConsole(int *piConsoleFd);

/*****************************************************************************
* 函 数 名      : BmuRestoreConsole
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib标志输入、输出及出错取消重定向
* 输入参数  : int iConsoleFd  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuRestoreConsole(int iConsoleFd);

/*****************************************************************************
* 函 数 名      : BmuCd
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib切换进程目录
* 输入参数  : const char *path  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuCd(const char *path);

/*****************************************************************************
* 函 数 名      : BmuGetcwd
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib获取当前工作目录
* 输入参数  : char *buf    
*                           size_t size  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern char *BmuGetcwd(char *buf, size_t size);

/*****************************************************************************
* 函 数 名      : BmuGetExePath
* 负 责 人      : zhaojzh
* 创建日期  : 2013年11月11日星期二
* 函数功能  : bmulib获取当前执行程序所在目录
* 输入参数  : char *buf    
*                           size_t size  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
char *BmuGetExePath(char *buf, size_t size);


/*****************************************************************************
* 函 数 名      : BmuRename
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib文件重命名
* 输入参数  : const char *f_old  
*                           const char *f_new  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuRename(const char *f_old, const char *f_new);

/*****************************************************************************
* 函 数 名      : BmuMkdir
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib创建目录
* 输入参数  : const char *path  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuMkdir(const char *path);

/*****************************************************************************
* 函 数 名      : BmuRmdir
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib删除目录
* 输入参数  : const char *path  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuRmdir(const char *path);

/*****************************************************************************
* 函 数 名      : BmuRemove
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib删除文件
* 输入参数  : const char *path  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuRemove(const char *path);

/*****************************************************************************
* 函 数 名      : BmuCp
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib文件复制
* 输入参数  : const char *src   
*                           const char *dest  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuCp(const char *src, const char *dest);

/*****************************************************************************
* 函 数 名      : BmuMv
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib文件剪切
* 输入参数  : const char *src   
*                           const char *dest  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuMv(const char *src, const char *dest);

/*****************************************************************************
* 函 数 名      : BmuRm
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib文件删除
* 输入参数  : const char *path  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuRm(const char *path);

/*****************************************************************************
* 函 数 名      : BmuGetSysPhyInfo
* 负 责 人      : qhxiong
* 创建日期  : 2013年8月24日星期六
* 函数功能  : 获取系统基础状态信息，包括CPU/MEM/DISK占用率
* 输入参数  : char *pcCpuInfo   
*                           char *pcMemInfo   
*                           char *pcDiskInfo  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuGetSysPhyInfo(char *pcCpuInfo, char *pcMemInfo, char *pcDiskInfo);

#endif

/*任务接口*/
/*****************************************************************************
* 函 数 名      : BmuOsLibInit
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib os lib初始化
* 输入参数  : void  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuOsLibInit(void);

/*****************************************************************************
* 函 数 名      : BmuTaskCreate
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib线程创建
* 输入参数  : const char *pName          
*                           int iPrio                  
*                           int iSize                  
*                           int (*pTaskEntry)(void *)  
*                           void *pArg                 
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern BMU_TASK_ID BmuTaskCreate(const char *pName, int iPrio, int iSize, int (*pTaskEntry)(void *), void *pArg);

/*****************************************************************************
* 函 数 名      : BmuTaskDelete
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib线程删除
* 输入参数  : BMU_TASK_ID taskId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuTaskDelete(BMU_TASK_ID taskId);

/*****************************************************************************
* 函 数 名      : BmuTaskNameToId
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib通过线程名查找线程id
* 输入参数  : const char *pName  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuTaskNameToId(const char *pName);

/*****************************************************************************
* 函 数 名      : BmuTaskPriorityGet
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib获取线程优先级
* 输入参数  : BMU_TASK_ID tid  
*                           int *pPriority   
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuTaskPriorityGet(BMU_TASK_ID tid, int *pPriority);

/*****************************************************************************
* 函 数 名      : BmuTaskPrioritySet
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib设置线程优先级
* 输入参数  : BMU_TASK_ID tid  
*                           int newPriority  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuTaskPrioritySet(BMU_TASK_ID tid, int newPriority);

/*****************************************************************************
* 函 数 名      : BmuTaskLock
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib线程上锁
* 输入参数  : void  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuTaskLock(void);

/*****************************************************************************
* 函 数 名      : BmuTaskUnlock
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib线程解锁
* 输入参数  : void  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuTaskUnlock(void);

/*****************************************************************************
* 函 数 名      : BmuTaskDelay
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib线程延时
* 输入参数  : int ticks  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuTaskDelay(int ticks);

/*****************************************************************************
* 函 数 名      : BmuTaskSuspend
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib线程挂起
* 输入参数  : BMU_TASK_ID tid  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuTaskSuspend(BMU_TASK_ID tid);

/*****************************************************************************
* 函 数 名      : BmuTaskResume
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib线程恢复运行
* 输入参数  : BMU_TASK_ID tid  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuTaskResume(BMU_TASK_ID tid);

/*同步信号量*/
/*计数型信号量实现同步*/

/*****************************************************************************
* 函 数 名      : BmuSemCreate
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib计数型信号量创建
* 输入参数  : int iCount  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern BMU_SEM_ID BmuSemCreate(int iCount);

/*****************************************************************************
* 函 数 名      : BmuSemTake
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib计数型信号量获取操作
* 输入参数  : BMU_SEM_ID semId  
*                           int iTicks        
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuSemTake(BMU_SEM_ID semId, int iTicks);

/*****************************************************************************
* 函 数 名      : BmuSemGive
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib计数型信号量释放操作
* 输入参数  : BMU_SEM_ID semId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuSemGive(BMU_SEM_ID semId);

/*****************************************************************************
* 函 数 名      : BmuSemDelete
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib计数型信号量删除操作
* 输入参数  : BMU_SEM_ID semId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuSemDelete(BMU_SEM_ID semId);

/*互斥信号量*/
/*****************************************************************************
* 函 数 名      : BmuMutexCreate
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib互斥锁创建
* 输入参数  : int iOptions  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern BMU_MUTEX_ID BmuMutexCreate(int iOptions);

/*****************************************************************************
* 函 数 名      : BmuMutexTake
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib互斥锁获取
* 输入参数  : BMU_MUTEX_ID mutexId  
*                           int iTicks            
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuMutexTake(BMU_MUTEX_ID mutexId, int iTicks);

/*****************************************************************************
* 函 数 名      : BmuMutexGive
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib互斥锁释放
* 输入参数  : BMU_MUTEX_ID mutexId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuMutexGive(BMU_MUTEX_ID mutexId);

/*****************************************************************************
* 函 数 名      : BmuMutexDelete
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib互斥锁删除
* 输入参数  : BMU_MUTEX_ID mutexId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuMutexDelete(BMU_MUTEX_ID mutexId);

/*看门狗定时器*/
/*****************************************************************************
* 函 数 名      : BmuWdCreate
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib看门狗定时器创建
* 输入参数  : void  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern BMU_WDOG_ID BmuWdCreate(void);

/*****************************************************************************
* 函 数 名      : BmuWdStart
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib看门狗定时器启动
* 输入参数  : BMU_WDOG_ID wdId   
*                           int iDelay         
*                           int (*pFunc)(int)  
*                           int iParam         
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuWdStart(BMU_WDOG_ID wdId, int iDelay, int (*pFunc)(int), int iParam);

/*****************************************************************************
* 函 数 名      : BmuWdCancel
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib看门狗定时器取消
* 输入参数  : BMU_WDOG_ID wdId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuWdCancel(BMU_WDOG_ID wdId);

/*****************************************************************************
* 函 数 名      : BmuWdDelete
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib看门狗定时器删除
* 输入参数  : BMU_WDOG_ID wdId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuWdDelete(BMU_WDOG_ID wdId);

#ifdef USING_LINUX_OS

/*****************************************************************************
* 函 数 名      : BmuWdAlterTick
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib看门狗定时器定时精度修改
* 输入参数  : int usec  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuWdAlterTick(int usec);

/*****************************************************************************
* 函 数 名      : BmuWd5MSTickBase
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib看门狗定时器5毫秒定时基准
* 输入参数  : int tick  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuWd5MSTickBase(int tick);
#endif

/*消息队列*/
/*****************************************************************************
* 函 数 名      : BmuMsgQCreate
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib system v消息队列创建
* 输入参数  : int iKeyNum        
*                           int iMaxMsgs       
*                           int iMaxMsgLength  
*                           int iOption        
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern BMU_MSG_Q_ID BmuMsgQCreate(int iKeyNum, int iMaxMsgs, int iMaxMsgLength, int iOption);

#ifdef USING_LINUX_OS

/*****************************************************************************
* 函 数 名      : BmuMsgQSendEx
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib system v消息队列发送
* 输入参数  : BMU_MSG_Q_ID msgQId  
*                           long lMsgType        
*                           char *pBuffer        
*                           unsigned int uiLen   
*                           int iTimeOut         
*                           int iPriority        
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuMsgQSendEx(BMU_MSG_Q_ID msgQId,
    long lMsgType,
    char *pBuffer,
    unsigned int uiLen,
    int iTimeOut,
    int iPriority);

/*****************************************************************************
* 函 数 名      : BmuMsgQRecvEx
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib system v消息队列接收
* 输入参数  : BMU_MSG_Q_ID msgQId  
*                           long lMsgType        
*                           long *pRcvMsgType    
*                           char *pBuffer        
*                           unsigned int uiLen   
*                           int iTimeOut         
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuMsgQRecvEx(BMU_MSG_Q_ID msgQId,
    long lMsgType,
    long *pRcvMsgType,
    char *pBuffer,
    unsigned int uiLen,
    int iTimeOut);

/*************** bmulib system v消息队列宏定义 ***************/
#define BmuMsgQSend(msgQId, pBuffer, uiLen, iTimeOut, iPriority) \
    BmuMsgQSendEx(msgQId, BMU_MSG_Q_TYPE, pBuffer, uiLen, iTimeOut, iPriority) 
#define BmuMsgQRecv(msgQId, pBuffer, uiLen, iTimeOut) \
    BmuMsgQRecvEx(msgQId, BMU_MSG_Q_TYPE, NULL, pBuffer, uiLen, iTimeOut)
#else

/*****************************************************************************
* 函 数 名      : BmuMsgQSend
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib消息队列发送
* 输入参数  : BMU_MSG_Q_ID msgQId  
*                           char *pBuffer        
*                           unsigned int uiLen   
*                           int iTimeOut         
*                           int iPriority        
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuMsgQSend(BMU_MSG_Q_ID msgQId, char *pBuffer, unsigned int uiLen, int iTimeOut, int iPriority);

/*****************************************************************************
* 函 数 名      : BmuMsgQRecv
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib消息队列接收
* 输入参数  : BMU_MSG_Q_ID msgQId  
*                           char *pBuffer        
*                           unsigned int uiLen   
*                           int iTimeOut         
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuMsgQRecv(BMU_MSG_Q_ID msgQId, char *pBuffer, unsigned int uiLen, int iTimeOut);
#endif

/*****************************************************************************
* 函 数 名      : BmuMsgQDelete
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib消息队列删除
* 输入参数  : BMU_MSG_Q_ID msgQId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuMsgQDelete(BMU_MSG_Q_ID msgQId);

/*****************************************************************************
* 函 数 名      : BmuMsgQNumMsgs
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib消息队列中消息个数获取
* 输入参数  : BMU_MSG_Q_ID msgQId  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuMsgQNumMsgs(BMU_MSG_Q_ID msgQId);

/*时钟相关*/

/*****************************************************************************
* 函 数 名      : BmuSysClkRateGet
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib系统时钟节拍数
* 输入参数  : void  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int BmuSysClkRateGet(void);

/*****************************************************************************
* 函 数 名      : BmuTickSet
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib时钟节拍设置
* 输入参数  : unsigned long ticks  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern void BmuTickSet(unsigned long ticks);

/*****************************************************************************
* 函 数 名      : BmuTickGet
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib时钟节拍获取
* 输入参数  : void  
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern unsigned long BmuTickGet(void);

extern struct BMU_MMAP_NODE *BmuMMapInit(const char *pcDevName, unsigned int uiOffset, unsigned int uiLen);
extern int BmuMMapDelete(struct BMU_MMAP_NODE * *ppstuMMap);
extern int BmuMMapWrite8(struct BMU_MMAP_NODE *pstuMMap, unsigned int uiAddr, unsigned char ucValue);
extern int BmuMMapWrite16(struct BMU_MMAP_NODE *pstuMMap, unsigned int uiAddr, unsigned short usValue);
extern int BmuMMapWrite32(struct BMU_MMAP_NODE *pstuMMap, unsigned int uiAddr, unsigned int uiValue);
extern int BmuMMapRead8(struct BMU_MMAP_NODE *pstuMMap, unsigned int uiAddr, unsigned char *pucValue);
extern int BmuMMapRead16(struct BMU_MMAP_NODE *pstuMMap, unsigned int uiAddr, unsigned short *pusValue);
extern int BmuMMapRead32(struct BMU_MMAP_NODE *pstuMMap, unsigned int uiAddr, unsigned int *puiValue);
extern int BmuMMapBulkWrite8(struct BMU_MMAP_NODE *pstuMMap, unsigned int uiAddr, unsigned char *pucValue, unsigned int uiLen);
extern int BmuMMapBulkWrite16(struct BMU_MMAP_NODE *pstuMMap, unsigned int uiAddr, unsigned short *pusValue, unsigned int uiLen);
extern int BmuMMapBulkWrite32(struct BMU_MMAP_NODE *pstuMMap, unsigned int uiAddr, unsigned short *puiValue, unsigned int uiLen);
extern int BmuMMapBulkRead8(struct BMU_MMAP_NODE *pstuMMap, unsigned int uiAddr, unsigned char *pucValue, unsigned int uiLen);
extern int BmuMMapBulkRead16(struct BMU_MMAP_NODE *pstuMMap, unsigned int uiAddr, unsigned short *pusValue, unsigned int uiLen);
extern int BmuMMapBulkRead32(struct BMU_MMAP_NODE *pstuMMap, unsigned int uiAddr, unsigned short *puiValue, unsigned int uiLen);

#ifdef __cplusplus
}
#endif  /*__cplusplus*/

#endif

