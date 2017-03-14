/******************************************************************************
 *  文 件 名    : bmuLinuxOsLib.h
 *  负 责 人    : qhxiong
 *  创建日期 : 2013年6月25日星期二
 *  版 本 号    : V1.0
 *  文件描述 : bmulib os api头文件
 *  版权说明 : Copyright (c) 2000-2020   烽火通信科技股份有限公司
 *  其    他	        : 无
 *  修改日志 :
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

/*************** bmulib os api通用宏定义 ***************/
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

#define MAX_FILE_NAME_LEN                       40                              /*模块最大文件名长度*/
#define FILE_NAME_BUFFER_LEN                    MAX_FILE_NAME_LEN + 1

#define MAX_DIR_LEN                     100                              /*模块最大目录加文件名长度*/
#define MAX_DIR_BUFFER_LEN                      MAX_DIR_LEN + 1

#define ARGV_MAX_NUM                8               /* 模块启动参数最大数量 */
#define ARGV_MAX_LENGTH                 10              /* 模块每个启动参数最大长度 */
#define ARGV_MAX_BUFFER_LENGTH        (ARGV_MAX_NUM * ARGV_MAX_LENGTH)

#define MIN_V2PT_PRIORITY                       255
#define MAX_V2PT_PRIORITY                       0


/*************** bmulib os api宏定义 ***************/
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
/*			结构体，bmulib线程同步信息描述       		*/
/******************************************************************************/
struct BMU_PTHREAD_SYNC_INFO
{
	pthread_mutex_t tSynMutex;		/*线程同步互斥锁*/
    pthread_cond_t tSynCond;		/*线程同步条件变量*/
	int iSynFlag;					/*线程同步变量标志*/
};

/******************************************************************************/
/*			结构体，bmulib线程信息描述       		*/
/******************************************************************************/
struct BMU_PTHREAD_LIST_NODE
{
	char cName[50];							/*线程名称*/
	pid_t tPId;							/*进程id*/
	pid_t tLwpId;							/*线程id*/
	pthread_t tPthrId;					/*线程id*/
	pthread_attr_t tAttr;					/*线程属性*/
	int (*pEntryPoint)(void*);				/*线程入口函数*/
	void *pArg;							/*线程入口函数输入参数*/
	sem_t tSynSem; 						/*信号量*/
	struct BMU_PTHREAD_SYNC_INFO stuSynCond;	/*线程同步结构体*/
    struct BMU_PTHREAD_LIST_NODE *pstuNext;		/*单向链表，下一节点指针*/
};

/******************************************************************************/
/*			结构体，bmulib看门狗定时器信息描述       		*/
/******************************************************************************/
struct BMU_WDOG_TIMER_NODE
{
	pthread_mutex_t tWdogLock;				/*看门狗定时器互斥锁*/
	int iTicks;							/*超时时钟节拍数*/
	int (*pTimerFunc)(int);					/*定时器超时，执行的处理函数*/
	int iTimerParam;						/*定时处理函数输入参数*/
	struct BMU_WDOG_TIMER_NODE *pstuNext;		/*单向链表，下一节点指针*/
};

/******************************************************************************/
/*			结构体，bmulib信号量信息描述       		*/
/******************************************************************************/
struct BMU_OS_SEM_NODE
{
	pthread_mutex_t tSemMutex;				/*信号量互斥锁*/
    pthread_cond_t tSemCond;				/*信号量条件变量*/
	int iMaxValue;							/*信号量最大值*/
	int iCurrentValue;						/*信号量当前值*/
	struct BMU_OS_SEM_NODE *pstuNext;			/*单向链表，下一节点指针*/
};

/******************************************************************************/
/*			结构体，bmulib消息队列信息描述       		*/
/******************************************************************************/
struct BMU_MSG_Q_BUF
{
    long mtype;                          /* message type, must be > 0 */
    char mtext[BMU_MSG_Q_MAX_LEN];           /* message data */
};

/******************************************************************************/
/*			结构体，bmulib udp进程通信信息描述      		*/
/******************************************************************************/
struct BMU_UDP_IPC_INFO
{
    int iSocketId;     					/*udp通信socket id*/                     
	struct sockaddr_in stuAddress;			/*udp通信socket地址*/
};

/******************************************************************************/
/*			联合体，bmulib system v信号量信息描述     		*/
/******************************************************************************/
union semun
{
    int val;                          
	struct semid_ds *buf;
	unsigned short *array;
};

/******************************************************************************/
/*			结构体，bmulib消息队列信息描述       		*/
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
/*			结构体，bmulib消息队列信息描述       		*/
/******************************************************************************/
struct BMU_MMAP_NODE
{
	pthread_rwlock_t tRWLock;	
	int iFd;
    void *pMMapBase;
	unsigned int uiLen;
};

/*****************************************************************************
 * 函 数 名  : CfgCoreDumpFunc
 * 负 责 人  : zhaojzh
 * 创建日期  : 2015年5月12日
 * 函数功能  : 打开coredump
 * 输入参数  : unsigned char ucValid  是否有效
 				固定写1打开
               char *pcSize           coredump文件大小
               固定写"unlimited"
               char *pcPath           coredump文件路径
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
int CfgCoreDumpFunc(unsigned char ucValid, char *pcSize, char *pcPath);

#ifdef  __cplusplus
}
#endif  /* __cplusplus */

#endif
