/******************************************************************************
 *  �� �� ��    : bmuOsHdrs.h
 *  �� �� ��    : zhaojzh
 *  �������� : 2013��6��25�����ڶ�
 *  �� �� ��    : V1.0
 *  �ļ����� : bmulib os api�ܿ�ͷ�ļ�
 *  ��Ȩ˵�� : Copyright (c) 2000-2020   ���ͨ�ſƼ��ɷ����޹�˾
 *  ��    ��	        : ��
 *  �޸���־ :
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

/*************** linux os apiͨ�ú궨�� ***************/
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

/*************** linux os apiͨ���������� ***************/
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

/*************** vxworks os apiͨ�ú궨�� ***************/
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

/*************** vxworks os apiͨ���������� ***************/
typedef int BMU_TASK_ID;
typedef SEM_ID BMU_SEM_ID;
typedef SEM_ID BMU_MUTEX_ID;
typedef WDOG_ID BMU_WDOG_ID;
typedef MSG_Q_ID BMU_MSG_Q_ID;
#endif

/*linuxר�ýӿ�*/
#ifdef USING_LINUX_OS

/*****************************************************************************
* �� �� ��      : BmuPthreadExit
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�߳��˳�
* �������  : int iRet  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuPthreadExit(int iRet);

/*****************************************************************************
* �� �� ��      : BmuAllPthreadBlockWait
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�߳������ȴ�
* �������  : void  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern void BmuAllPthreadBlockWait(void);

/*****************************************************************************
* �� �� ��      : BmuAllTaskDelete
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibɾ�������߳�
* �������  : void  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern void BmuAllTaskDelete(void);

/*****************************************************************************
* �� �� ��      : BmuTaskShow
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�����߳�id��ʾ�߳�����
* �������  : BMU_TASK_ID taskId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuTaskShow(BMU_TASK_ID taskId);

/*****************************************************************************
* �� �� ��      : BmuAllTaskShow
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��ʾ�����߳�����
* �������  : void  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern void BmuAllTaskShow(void);

/*****************************************************************************
* �� �� ��      : BmuSystem
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibϵͳ���ã����������ű���shell����
* �������  : const char *pCmd  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuSystem(const char *pCmd);

/*****************************************************************************
* �� �� ��      : BmuSetPthreadSigBlock
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�����߳���������ָ���ź�
* �������  : int iSignal  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuSetPthreadSigBlock(int iSignal);

/*****************************************************************************
* �� �� ��      : BmuGetPidByName
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibͨ����ִ���ļ�����ȡ����id
* �������  : const char *pDirFileName  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuGetPidByName(const char *pDirFileName);

/*****************************************************************************
* �� �� ��      : BmuLoadAppFile
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib���ؽ�������
* �������  : const char *pDirFileName  
*                           const char *pArgvName     
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuLoadAppFile(const char *pDirFileName, const char *pArgvName);

/*****************************************************************************
* �� �� ��      : BmuUnLoadAppFile
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibж�ؽ���
* �������  : const char *pDirFileName  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuUnLoadAppFile(const char *pDirFileName);

/*****************************************************************************
* �� �� ��      : BmuTranslatePriority
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib ��vxworks�������ȼ�ת����linux�߳����ȼ�
* �������  : int v2pthread_priority  
*                           int sched_policy        
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuTranslatePriority(int v2pthread_priority, int sched_policy);

/*****************************************************************************
* �� �� ��      : BmuEthDevShow
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��ʾ������Ϣ
* �������  : void  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuEthDevShow(void);

/*****************************************************************************
* �� �� ��      : BmuTaskTestPoint
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�̲߳��Ե�
* �������  : void  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuTaskTestPoint(void);

/*****************************************************************************
* �� �� ��      : BmuSaftBoot
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��ȫ�����ӿ�
* �������  : void  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuSaftBoot(void);

/*�������ź���ʵ��ͬ��*/
/*****************************************************************************
* �� �� ��      : BmuOSSemCreate
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibϵͳ�ź�������
* �������  : int iInitCount  
*                           int iMaxCount   
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern BMU_OS_SEM_ID BmuOSSemCreate(int iInitCount, int iMaxCount);

/*****************************************************************************
* �� �� ��      : BmuOSSemTake
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibϵͳ�ź�����ȡ����
* �������  : BMU_OS_SEM_ID semId  
*                           int iTicks           
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuOSSemTake(BMU_OS_SEM_ID semId, int iTicks);

/*****************************************************************************
* �� �� ��      : BmuOSSemGive
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibϵͳ�ź����ͷŲ���
* �������  : BMU_OS_SEM_ID semId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuOSSemGive(BMU_OS_SEM_ID semId);

/*****************************************************************************
* �� �� ��      : BmuOSSemDelete
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibϵͳ�ź���ɾ������
* �������  : BMU_OS_SEM_ID semId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuOSSemDelete(BMU_OS_SEM_ID semId);

/*************** bmulib�������ź����궨�� ***************/
#define BmuBinSemCreate(iCount)         BmuOSSemCreate(iCount, 1)
#define BmuBinSemTake(semId, iTicks)    BmuOSSemTake(semId, iTicks)
#define BmuBinSemGive(semId)            BmuOSSemGive(semId)
#define BmuBinSemDelete(semId)          BmuOSSemDelete(semId)

/*���̼�Sye�ź���*/

/*****************************************************************************
* �� �� ��      : BmuSysVSemCreate
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib system v�ź�������
* �������  : int iHandleType  
*                           int iKeyNum      
*                           int iCount       
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern BMU_SYS_V_SEM_ID BmuSysVSemCreate(int iHandleType, int iKeyNum, int iCount);

/*****************************************************************************
* �� �� ��      : BmuSysVSemTake
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib system v�ź�����ȡ�ӿ�
* �������  : BMU_SYS_V_SEM_ID semId  
*                           int iTicks              
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuSysVSemTake(BMU_SYS_V_SEM_ID semId, int iTicks);

/*****************************************************************************
* �� �� ��      : BmuSysVSemGive
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib system v�ź����ͷŽӿ�
* �������  : BMU_SYS_V_SEM_ID semId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuSysVSemGive(BMU_SYS_V_SEM_ID semId);

/*****************************************************************************
* �� �� ��      : BmuSysVSemDelete
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib system v�ź���ɾ���ӿ�
* �������  : BMU_SYS_V_SEM_ID semId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuSysVSemDelete(BMU_SYS_V_SEM_ID semId);

/*��д��*/

/*****************************************************************************
* �� �� ��      : BmuRWLockCreate
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib ��д������
* �������  : int iOptions  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern BMU_RWLOCK_ID BmuRWLockCreate(int iOptions);

/*****************************************************************************
* �� �� ��      : BmuWrLock
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib д����ȡ����
* �������  : BMU_RWLOCK_ID rwlockId  
*                           int iTicks              
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuWrLock(BMU_RWLOCK_ID rwlockId, int iTicks);

/*****************************************************************************
* �� �� ��      : BmuRdLock
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib ������ȡ����
* �������  : BMU_RWLOCK_ID rwlockId  
*                           int iTicks              
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuRdLock(BMU_RWLOCK_ID rwlockId, int iTicks);

/*****************************************************************************
* �� �� ��      : BmuUnlock
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib ��������
* �������  : BMU_RWLOCK_ID rwlockId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuUnlock(BMU_RWLOCK_ID rwlockId);

/*****************************************************************************
* �� �� ��      : BmuRWLockDelete
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��д��ɾ������
* �������  : BMU_RWLOCK_ID rwlockId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuRWLockDelete(BMU_RWLOCK_ID rwlockId);

/*���̼�UDPͨ��*/
/*****************************************************************************
* �� �� ��      : BmuUdpServerCreate
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib udp����������
* �������  : int iPort  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern BMU_UDP_ID BmuUdpServerCreate(int iPort);

/*****************************************************************************
* �� �� ��      : BmuUdpClientCreate
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib udp�ͻ��˴���
* �������  : int iPort  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern BMU_UDP_ID BmuUdpClientCreate(int iPort);

/*****************************************************************************
* �� �� ��      : BmuUdpSend
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib udp���ͺ���
* �������  : BMU_UDP_ID udpId    
*                           char *pBuffer       
*                           unsigned int uiLen  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuUdpSend(BMU_UDP_ID udpId, char *pBuffer, unsigned int uiLen);
extern int BmuUdpRecv(BMU_UDP_ID udpId, char *pBuffer, unsigned int uiLen, int iTimeOut);
extern int BmuUdpDelete(BMU_UDP_ID udpId);

/*posix��Ϣ����*/
/*****************************************************************************
* �� �� ��      : BmuQueueCreate
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib posix��Ϣ���д���
* �������  : const char *pQName  
*                           int iMaxMsgs        
*                           int iMaxMsgLength   
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern BMU_MSG_Q_ID BmuQueueCreate(const char *pQName, int iMaxMsgs, int iMaxMsgLength);

/*****************************************************************************
* �� �� ��      : BmuQueueSend
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib posix��Ϣ���з���
* �������  : BMU_MSG_Q_ID msgQId  
*                           char *pBuffer        
*                           unsigned int uiLen   
*                           int iTimeOut         
*                           int iPriority        
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuQueueSend(BMU_MSG_Q_ID msgQId, char *pBuffer, unsigned int uiLen, int iTimeOut, int iPriority);

/*****************************************************************************
* �� �� ��      : BmuQueueRecv
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib posix��Ϣ���н���
* �������  : BMU_MSG_Q_ID msgQId  
*                           char *pBuffer        
*                           unsigned int uiLen   
*                           int iTimeOut         
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuQueueRecv(BMU_MSG_Q_ID msgQId, char *pBuffer, unsigned int uiLen, int iTimeOut);

/*****************************************************************************
* �� �� ��      : BmuQueueDelete
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib posix��Ϣ����ɾ��
* �������  : BMU_MSG_Q_ID msgQId  
*                           const char *pQName   
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuQueueDelete(BMU_MSG_Q_ID msgQId, const char *pQName);

/*****************************************************************************
* �� �� ��      : BmuQueueNum
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��ȡposix��Ϣ��������Ϣ����
* �������  : BMU_MSG_Q_ID msgQId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuQueueNum(BMU_MSG_Q_ID msgQId);

/*�ն��ض���ӿ�*/
/*****************************************************************************
* �� �� ��      : BmuRedirectConsole
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��־���롢����������ض���
* �������  : int *piConsoleFd  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuRedirectConsole(int *piConsoleFd);

/*****************************************************************************
* �� �� ��      : BmuRestoreConsole
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��־���롢���������ȡ���ض���
* �������  : int iConsoleFd  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuRestoreConsole(int iConsoleFd);

/*****************************************************************************
* �� �� ��      : BmuCd
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�л�����Ŀ¼
* �������  : const char *path  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuCd(const char *path);

/*****************************************************************************
* �� �� ��      : BmuGetcwd
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��ȡ��ǰ����Ŀ¼
* �������  : char *buf    
*                           size_t size  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern char *BmuGetcwd(char *buf, size_t size);

/*****************************************************************************
* �� �� ��      : BmuGetExePath
* �� �� ��      : zhaojzh
* ��������  : 2013��11��11�����ڶ�
* ��������  : bmulib��ȡ��ǰִ�г�������Ŀ¼
* �������  : char *buf    
*                           size_t size  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
char *BmuGetExePath(char *buf, size_t size);


/*****************************************************************************
* �� �� ��      : BmuRename
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�ļ�������
* �������  : const char *f_old  
*                           const char *f_new  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuRename(const char *f_old, const char *f_new);

/*****************************************************************************
* �� �� ��      : BmuMkdir
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib����Ŀ¼
* �������  : const char *path  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuMkdir(const char *path);

/*****************************************************************************
* �� �� ��      : BmuRmdir
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibɾ��Ŀ¼
* �������  : const char *path  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuRmdir(const char *path);

/*****************************************************************************
* �� �� ��      : BmuRemove
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibɾ���ļ�
* �������  : const char *path  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuRemove(const char *path);

/*****************************************************************************
* �� �� ��      : BmuCp
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�ļ�����
* �������  : const char *src   
*                           const char *dest  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuCp(const char *src, const char *dest);

/*****************************************************************************
* �� �� ��      : BmuMv
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�ļ�����
* �������  : const char *src   
*                           const char *dest  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuMv(const char *src, const char *dest);

/*****************************************************************************
* �� �� ��      : BmuRm
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�ļ�ɾ��
* �������  : const char *path  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuRm(const char *path);

/*****************************************************************************
* �� �� ��      : BmuGetSysPhyInfo
* �� �� ��      : qhxiong
* ��������  : 2013��8��24��������
* ��������  : ��ȡϵͳ����״̬��Ϣ������CPU/MEM/DISKռ����
* �������  : char *pcCpuInfo   
*                           char *pcMemInfo   
*                           char *pcDiskInfo  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuGetSysPhyInfo(char *pcCpuInfo, char *pcMemInfo, char *pcDiskInfo);

#endif

/*����ӿ�*/
/*****************************************************************************
* �� �� ��      : BmuOsLibInit
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib os lib��ʼ��
* �������  : void  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuOsLibInit(void);

/*****************************************************************************
* �� �� ��      : BmuTaskCreate
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�̴߳���
* �������  : const char *pName          
*                           int iPrio                  
*                           int iSize                  
*                           int (*pTaskEntry)(void *)  
*                           void *pArg                 
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern BMU_TASK_ID BmuTaskCreate(const char *pName, int iPrio, int iSize, int (*pTaskEntry)(void *), void *pArg);

/*****************************************************************************
* �� �� ��      : BmuTaskDelete
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�߳�ɾ��
* �������  : BMU_TASK_ID taskId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuTaskDelete(BMU_TASK_ID taskId);

/*****************************************************************************
* �� �� ��      : BmuTaskNameToId
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibͨ���߳��������߳�id
* �������  : const char *pName  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuTaskNameToId(const char *pName);

/*****************************************************************************
* �� �� ��      : BmuTaskPriorityGet
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��ȡ�߳����ȼ�
* �������  : BMU_TASK_ID tid  
*                           int *pPriority   
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuTaskPriorityGet(BMU_TASK_ID tid, int *pPriority);

/*****************************************************************************
* �� �� ��      : BmuTaskPrioritySet
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�����߳����ȼ�
* �������  : BMU_TASK_ID tid  
*                           int newPriority  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuTaskPrioritySet(BMU_TASK_ID tid, int newPriority);

/*****************************************************************************
* �� �� ��      : BmuTaskLock
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�߳�����
* �������  : void  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuTaskLock(void);

/*****************************************************************************
* �� �� ��      : BmuTaskUnlock
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�߳̽���
* �������  : void  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuTaskUnlock(void);

/*****************************************************************************
* �� �� ��      : BmuTaskDelay
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�߳���ʱ
* �������  : int ticks  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuTaskDelay(int ticks);

/*****************************************************************************
* �� �� ��      : BmuTaskSuspend
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�̹߳���
* �������  : BMU_TASK_ID tid  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuTaskSuspend(BMU_TASK_ID tid);

/*****************************************************************************
* �� �� ��      : BmuTaskResume
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�ָ̻߳�����
* �������  : BMU_TASK_ID tid  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuTaskResume(BMU_TASK_ID tid);

/*ͬ���ź���*/
/*�������ź���ʵ��ͬ��*/

/*****************************************************************************
* �� �� ��      : BmuSemCreate
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�������ź�������
* �������  : int iCount  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern BMU_SEM_ID BmuSemCreate(int iCount);

/*****************************************************************************
* �� �� ��      : BmuSemTake
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�������ź�����ȡ����
* �������  : BMU_SEM_ID semId  
*                           int iTicks        
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuSemTake(BMU_SEM_ID semId, int iTicks);

/*****************************************************************************
* �� �� ��      : BmuSemGive
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�������ź����ͷŲ���
* �������  : BMU_SEM_ID semId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuSemGive(BMU_SEM_ID semId);

/*****************************************************************************
* �� �� ��      : BmuSemDelete
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�������ź���ɾ������
* �������  : BMU_SEM_ID semId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuSemDelete(BMU_SEM_ID semId);

/*�����ź���*/
/*****************************************************************************
* �� �� ��      : BmuMutexCreate
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib����������
* �������  : int iOptions  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern BMU_MUTEX_ID BmuMutexCreate(int iOptions);

/*****************************************************************************
* �� �� ��      : BmuMutexTake
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��������ȡ
* �������  : BMU_MUTEX_ID mutexId  
*                           int iTicks            
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuMutexTake(BMU_MUTEX_ID mutexId, int iTicks);

/*****************************************************************************
* �� �� ��      : BmuMutexGive
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib�������ͷ�
* �������  : BMU_MUTEX_ID mutexId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuMutexGive(BMU_MUTEX_ID mutexId);

/*****************************************************************************
* �� �� ��      : BmuMutexDelete
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib������ɾ��
* �������  : BMU_MUTEX_ID mutexId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuMutexDelete(BMU_MUTEX_ID mutexId);

/*���Ź���ʱ��*/
/*****************************************************************************
* �� �� ��      : BmuWdCreate
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib���Ź���ʱ������
* �������  : void  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern BMU_WDOG_ID BmuWdCreate(void);

/*****************************************************************************
* �� �� ��      : BmuWdStart
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib���Ź���ʱ������
* �������  : BMU_WDOG_ID wdId   
*                           int iDelay         
*                           int (*pFunc)(int)  
*                           int iParam         
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuWdStart(BMU_WDOG_ID wdId, int iDelay, int (*pFunc)(int), int iParam);

/*****************************************************************************
* �� �� ��      : BmuWdCancel
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib���Ź���ʱ��ȡ��
* �������  : BMU_WDOG_ID wdId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuWdCancel(BMU_WDOG_ID wdId);

/*****************************************************************************
* �� �� ��      : BmuWdDelete
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib���Ź���ʱ��ɾ��
* �������  : BMU_WDOG_ID wdId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuWdDelete(BMU_WDOG_ID wdId);

#ifdef USING_LINUX_OS

/*****************************************************************************
* �� �� ��      : BmuWdAlterTick
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib���Ź���ʱ����ʱ�����޸�
* �������  : int usec  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuWdAlterTick(int usec);

/*****************************************************************************
* �� �� ��      : BmuWd5MSTickBase
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib���Ź���ʱ��5���붨ʱ��׼
* �������  : int tick  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuWd5MSTickBase(int tick);
#endif

/*��Ϣ����*/
/*****************************************************************************
* �� �� ��      : BmuMsgQCreate
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib system v��Ϣ���д���
* �������  : int iKeyNum        
*                           int iMaxMsgs       
*                           int iMaxMsgLength  
*                           int iOption        
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern BMU_MSG_Q_ID BmuMsgQCreate(int iKeyNum, int iMaxMsgs, int iMaxMsgLength, int iOption);

#ifdef USING_LINUX_OS

/*****************************************************************************
* �� �� ��      : BmuMsgQSendEx
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib system v��Ϣ���з���
* �������  : BMU_MSG_Q_ID msgQId  
*                           long lMsgType        
*                           char *pBuffer        
*                           unsigned int uiLen   
*                           int iTimeOut         
*                           int iPriority        
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuMsgQSendEx(BMU_MSG_Q_ID msgQId,
    long lMsgType,
    char *pBuffer,
    unsigned int uiLen,
    int iTimeOut,
    int iPriority);

/*****************************************************************************
* �� �� ��      : BmuMsgQRecvEx
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib system v��Ϣ���н���
* �������  : BMU_MSG_Q_ID msgQId  
*                           long lMsgType        
*                           long *pRcvMsgType    
*                           char *pBuffer        
*                           unsigned int uiLen   
*                           int iTimeOut         
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuMsgQRecvEx(BMU_MSG_Q_ID msgQId,
    long lMsgType,
    long *pRcvMsgType,
    char *pBuffer,
    unsigned int uiLen,
    int iTimeOut);

/*************** bmulib system v��Ϣ���к궨�� ***************/
#define BmuMsgQSend(msgQId, pBuffer, uiLen, iTimeOut, iPriority) \
    BmuMsgQSendEx(msgQId, BMU_MSG_Q_TYPE, pBuffer, uiLen, iTimeOut, iPriority) 
#define BmuMsgQRecv(msgQId, pBuffer, uiLen, iTimeOut) \
    BmuMsgQRecvEx(msgQId, BMU_MSG_Q_TYPE, NULL, pBuffer, uiLen, iTimeOut)
#else

/*****************************************************************************
* �� �� ��      : BmuMsgQSend
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��Ϣ���з���
* �������  : BMU_MSG_Q_ID msgQId  
*                           char *pBuffer        
*                           unsigned int uiLen   
*                           int iTimeOut         
*                           int iPriority        
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuMsgQSend(BMU_MSG_Q_ID msgQId, char *pBuffer, unsigned int uiLen, int iTimeOut, int iPriority);

/*****************************************************************************
* �� �� ��      : BmuMsgQRecv
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��Ϣ���н���
* �������  : BMU_MSG_Q_ID msgQId  
*                           char *pBuffer        
*                           unsigned int uiLen   
*                           int iTimeOut         
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuMsgQRecv(BMU_MSG_Q_ID msgQId, char *pBuffer, unsigned int uiLen, int iTimeOut);
#endif

/*****************************************************************************
* �� �� ��      : BmuMsgQDelete
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��Ϣ����ɾ��
* �������  : BMU_MSG_Q_ID msgQId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuMsgQDelete(BMU_MSG_Q_ID msgQId);

/*****************************************************************************
* �� �� ��      : BmuMsgQNumMsgs
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��Ϣ��������Ϣ������ȡ
* �������  : BMU_MSG_Q_ID msgQId  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuMsgQNumMsgs(BMU_MSG_Q_ID msgQId);

/*ʱ�����*/

/*****************************************************************************
* �� �� ��      : BmuSysClkRateGet
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibϵͳʱ�ӽ�����
* �������  : void  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern int BmuSysClkRateGet(void);

/*****************************************************************************
* �� �� ��      : BmuTickSet
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibʱ�ӽ�������
* �������  : unsigned long ticks  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
extern void BmuTickSet(unsigned long ticks);

/*****************************************************************************
* �� �� ��      : BmuTickGet
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulibʱ�ӽ��Ļ�ȡ
* �������  : void  
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  : 
* �� ��            :
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

