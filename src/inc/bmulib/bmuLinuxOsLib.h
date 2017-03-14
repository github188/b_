/******************************************************************************
 *  �� �� ��    : bmuLinuxOsLib.h
 *  �� �� ��    : qhxiong
 *  �������� : 2013��6��25�����ڶ�
 *  �� �� ��    : V1.0
 *  �ļ����� : bmulib os apiͷ�ļ�
 *  ��Ȩ˵�� : Copyright (c) 2000-2020   ���ͨ�ſƼ��ɷ����޹�˾
 *  ��    ��	        : ��
 *  �޸���־ :
 ******************************************************************************/
#ifndef __BMULINUXOSLIB_H__
#define __BMULINUXOSLIB_H__

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <sys/ioctl.h>
#include <time.h>
#include <sys/time.h>
#include <sys/times.h>
#include <netdb.h>
#include <fcntl.h>
#include <netinet/tcp.h>
#include <sys/wait.h>
#include <termios.h>
#include <dlfcn.h>
#include <semaphore.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>
#include <dirent.h>
#include <sys/syscall.h>
#include <mqueue.h>
#include <pty.h>
#include <execinfo.h> 
#include <mtd/mtd-user.h>
#include <sys/vfs.h>
#include <mntent.h>
#include <sys/mman.h>
#include <sys/stat.h>

#ifdef  __cplusplus
extern  "C" {
#endif  /* __cplusplus */

/*************** bmulib os apiͨ�ú궨�� ***************/
#ifndef OK
#define OK      0
#endif

#ifndef ERROR
#define ERROR   -1
#endif

#ifndef TRUE
#define TRUE            1
#endif

#ifndef FALSE
#define FALSE   0
#endif

#ifndef FOREVER
#define FOREVER while (1)
#endif

#ifndef STATUS
#define STATUS  int
#endif

#ifndef LOCAL
#define LOCAL   static
#endif

#define MAX_FILE_NAME_LEN                       40                              /*ģ������ļ�������*/
#define FILE_NAME_BUFFER_LEN                    MAX_FILE_NAME_LEN + 1

#define MAX_DIR_LEN                     100                              /*ģ�����Ŀ¼���ļ�������*/
#define MAX_DIR_BUFFER_LEN                      MAX_DIR_LEN + 1

#define ARGV_MAX_NUM                8               /* ģ����������������� */
#define ARGV_MAX_LENGTH                 10              /* ģ��ÿ������������󳤶� */
#define ARGV_MAX_BUFFER_LENGTH        (ARGV_MAX_NUM * ARGV_MAX_LENGTH)

#define MIN_V2PT_PRIORITY                       255
#define MAX_V2PT_PRIORITY                       0


/*************** bmulib os api�궨�� ***************/
#define	BMU_UDP_IPC_PORT			10000
#define	BMU_USER_TASK_MAX_PRIO		50
#define 	BMU_EXC_TASK_PRIO 			20
#define 	BMU_EXC_TASK_STACK_SIZE 		0
#define 	TICKS_PER_SEC 				200			
#define	BMU_TICK_TIME				(1000L/TICKS_PER_SEC)
#define	BMU_MSG_Q_MAX_LEN			2048
#define	BMU_SYS_MSG_Q_MAX_BYTES		16384
#define	BMU_MSG_Q_TYPE				1
#define 	BMU_SIGRTMIN_USR    			32

/******************************************************************************/
/*			�ṹ�壬bmulib�߳�ͬ����Ϣ����       		*/
/******************************************************************************/
struct BMU_PTHREAD_SYNC_INFO
{
	pthread_mutex_t tSynMutex;		/*�߳�ͬ��������*/
    pthread_cond_t tSynCond;		/*�߳�ͬ����������*/
	int iSynFlag;					/*�߳�ͬ��������־*/
};

/******************************************************************************/
/*			�ṹ�壬bmulib�߳���Ϣ����       		*/
/******************************************************************************/
struct BMU_PTHREAD_LIST_NODE
{
	char cName[50];							/*�߳�����*/
	pid_t tPId;							/*����id*/
	pid_t tLwpId;							/*�߳�id*/
	pthread_t tPthrId;					/*�߳�id*/
	pthread_attr_t tAttr;					/*�߳�����*/
	int (*pEntryPoint)(void*);				/*�߳���ں���*/
	void *pArg;							/*�߳���ں����������*/
	sem_t tSynSem; 						/*�ź���*/
	struct BMU_PTHREAD_SYNC_INFO stuSynCond;	/*�߳�ͬ���ṹ��*/
    struct BMU_PTHREAD_LIST_NODE *pstuNext;		/*����������һ�ڵ�ָ��*/
};

/******************************************************************************/
/*			�ṹ�壬bmulib���Ź���ʱ����Ϣ����       		*/
/******************************************************************************/
struct BMU_WDOG_TIMER_NODE
{
	pthread_mutex_t tWdogLock;				/*���Ź���ʱ��������*/
	int iTicks;							/*��ʱʱ�ӽ�����*/
	int (*pTimerFunc)(int);					/*��ʱ����ʱ��ִ�еĴ�����*/
	int iTimerParam;						/*��ʱ�������������*/
	struct BMU_WDOG_TIMER_NODE *pstuNext;		/*����������һ�ڵ�ָ��*/
};

/******************************************************************************/
/*			�ṹ�壬bmulib�ź�����Ϣ����       		*/
/******************************************************************************/
struct BMU_OS_SEM_NODE
{
	pthread_mutex_t tSemMutex;				/*�ź���������*/
    pthread_cond_t tSemCond;				/*�ź�����������*/
	int iMaxValue;							/*�ź������ֵ*/
	int iCurrentValue;						/*�ź�����ǰֵ*/
	struct BMU_OS_SEM_NODE *pstuNext;			/*����������һ�ڵ�ָ��*/
};

/******************************************************************************/
/*			�ṹ�壬bmulib��Ϣ������Ϣ����       		*/
/******************************************************************************/
struct BMU_MSG_Q_BUF
{
    long mtype;                          /* message type, must be > 0 */
    char mtext[BMU_MSG_Q_MAX_LEN];           /* message data */
};

/******************************************************************************/
/*			�ṹ�壬bmulib udp����ͨ����Ϣ����      		*/
/******************************************************************************/
struct BMU_UDP_IPC_INFO
{
    int iSocketId;     					/*udpͨ��socket id*/                     
	struct sockaddr_in stuAddress;			/*udpͨ��socket��ַ*/
};

/******************************************************************************/
/*			�����壬bmulib system v�ź�����Ϣ����     		*/
/******************************************************************************/
union semun
{
    int val;                          
	struct semid_ds *buf;
	unsigned short *array;
};

/******************************************************************************/
/*			�ṹ�壬bmulib��Ϣ������Ϣ����       		*/
/******************************************************************************/
struct BMU_TIME_DIAG
{
    unsigned long ulCycles;
    long long llMin;
    long long llMax;
    long long llAct;
    double dAvg;
    struct timespec stuTime;
    pid_t tLwpId;
    unsigned char ucFlag;
};

/******************************************************************************/
/*			�ṹ�壬bmulib��Ϣ������Ϣ����       		*/
/******************************************************************************/
struct BMU_MMAP_NODE
{
	pthread_rwlock_t tRWLock;	
	int iFd;
    void *pMMapBase;
	unsigned int uiLen;
};

/*****************************************************************************
 * �� �� ��  : CfgCoreDumpFunc
 * �� �� ��  : zhaojzh
 * ��������  : 2015��5��12��
 * ��������  : ��coredump
 * �������  : unsigned char ucValid  �Ƿ���Ч
 				�̶�д1��
               char *pcSize           coredump�ļ���С
               �̶�д"unlimited"
               char *pcPath           coredump�ļ�·��
 * �������  : ��
 * �� �� ֵ  : 
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
int CfgCoreDumpFunc(unsigned char ucValid, char *pcSize, char *pcPath);

#ifdef  __cplusplus
}
#endif  /* __cplusplus */

#endif
