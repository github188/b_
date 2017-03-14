/*****************************************************************************
* �� �� ��      : ifndef __BMUVXWADAPT_H__
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib������vxworks os�����ͷ�ļ�
* �������  : ��
* �������  : ��
* �� �� ֵ      : 
* ���ù�ϵ  : 
* �� ��            :
*****************************************************************************/
#ifndef __BMUVXWADAPT_H__
#define __BMUVXWADAPT_H__
#include "bmuOsHdrs.h"
#ifdef __cplusplus
extern "C" {
#endif  /*__cplusplus*/

#if	defined(USING_LINUX_OS)

/*************** vxworks os apiͨ�ú궨�� ***************/
#define SEM_DEFAULT_MUTEX			BMU_SEM_DEFAULT_MUTEX
#define SEM_Q_PRIORITY          		BMU_SEM_Q_PRIORITY
#define SEM_Q_FIFO              	BMU_SEM_Q_FIFO
#define SEM_DELETE_SAFE 				BMU_SEM_DELETE_SAFE
#define SEM_INVERSION_SAFE      		BMU_SEM_INVERSION_SAFE
#define SEM_EVENTSEND_ERR_NOTIFY		BMU_SEM_EVENTSEND_ERR_NOTIFY
#define SEM_EMPTY       			BMU_SEM_EMPTY
#define SEM_FULL        			BMU_SEM_FULL
#define NO_WAIT 					BMU_NO_WAIT
#define WAIT_FOREVER    			BMU_WAIT_FOREVER
#define MSG_PRI_NORMAL  				BMU_MSG_PRI_NORMAL
#define MSG_PRI_URGENT  				BMU_MSG_PRI_URGENT
#define MSG_Q_FIFO      			BMU_MSG_Q_FIFO
#define MSG_Q_MSG_Q_PRIORITY    		BMU_MSG_Q_PRIORITY
#define MSG_Q_EVENTSEND_ERR_NOTIFY		BMU_MSG_Q_EVENTSEND_ERR_NOTIFY
	
typedef BMU_OS_SEM_ID					SEM_B_ID; 					
typedef BMU_MUTEX_ID SEM_M_ID;					
typedef BMU_WDOG_ID					WDOG_ID; 					
typedef BMU_MSG_Q_ID				MSG_Q_ID;					
typedef BMU_BIN_SEM_ID				SEM_ID;
/*BMU alloc and free memory funcation*/
#define BMU_DEC_MALLOC  malloc
#define BMU_DEC_FREE    free

/*************** vxworks������ؽӿں궨��***************/
#define taskSpawn(                                                           \
        name, priority, options, stackSize, entryPt, arg1, arg2, arg3, arg4, \
        arg5, arg6, arg7, arg8, arg9, arg10                                  \
        )                                                                    \
    BmuTaskCreate(name, BmuTranslatePriority(priority, SCHED_RR), 0, (int (*)(void *))entryPt, arg1)

#define taskDelete(tid)                     BmuTaskDelete(tid)
#define taskDelay(ticks)                     BmuTaskDelay(ticks)
#define taskNameToId(pName)                 	BmuTaskNameToId(pName)
#define taskPriorityGet(tid, priority)  		BmuTaskPriorityGet(tid, priority)
#define taskPrioritySet(tid, priority)  		BmuTaskPrioritySet(tid, priority)
#define taskLock()                          BmuTaskLock()
#define taskUnlock()                        BmuTaskUnlock()
#define taskSuspend(tid)						BmuTaskSuspend(tid)
#define taskResume(tid)						BmuTaskResume(tid)

/*vxworks�������ź�����ؽӿں궨��*/
/*semBCreate(SEM_Q_FIFO, SEM_EMPTY)*/
#define semBCreate(options, initialState)       BmuOSSemCreate(initialState, 1)
#define semBTake(semId, timeout)               BmuOSSemTake(semId, timeout)
#define semBGive(semId)                      BmuOSSemGive(semId)
#define semBDelete(semId)                     BmuOSSemDelete(semId)

/*vxworks�����ź�����ؽӿں궨��*/
/*semBCreate(SEM_Q_FIFO, SEM_FULL) )		semMCreate(SEM_DEFAULT_MUTEX)*/
/*semMCreate(SEM_Q_FIFO | SEM_DELETE_SAFE) ) */
/*semMCreate(SEM_Q_PRIORITY | BMU_SEM_INVERSION_SAFE) ) */
#define semMCreate(options)                   BmuMutexCreate(options)
#define semMTake(semId, timeout)                BmuMutexTake(semId, timeout)
#define semMGive(semId)                       BmuMutexGive(semId)
#define semMDelete(semId)                     BmuMutexDelete(semId)

/*vxworks���Ź���ʱ����ؽӿں궨��*/
#define wdCreate()       						BmuWdCreate()
#define wdStart(wdId, delay, pRoutine, parameter)     BmuWdStart(wdId, delay, (int (*)(int))pRoutine, parameter)
#define wdCancel(wdId)                      		BmuWdCancel(wdId)
#define wdDelete(wdId)                     		BmuWdDelete(wdId)

/*vxworksʱ����ؽӿں궨��*/
#define sysClkRateGet()                     	BmuSysClkRateGet()
#define tickSet(ticks)                     	BmuTickSet(ticks)
#define tickGet()                     		BmuTickGet()

/*vxworks��Ϣ������ؽӿں궨��*/
#define msgQCreate(pQName, iMaxMsgs, iMaxMsgLength, iOption)	BmuQueueCreate(pQName, iMaxMsgs, iMaxMsgLength)
#define msgQSend(msgQId, pBuffer, uiLen, iTimeOut, iPriority)	BmuQueueSend(msgQId, pBuffer, uiLen, iTimeOut, iPriority)
#define msgQReceive(msgQId, pBuffer, uiLen, iTimeOut)			BmuQueueRecv(msgQId, pBuffer, uiLen, iTimeOut)
#define msgQDelete(msgQId, pQName)							BmuQueueDelete(msgQId, pQName)
#define msgQNumMsgs(msgQId)								BmuQueueNum(msgQId)

#endif

#ifdef __cplusplus
}
#endif  /*__cplusplus*/

#endif

