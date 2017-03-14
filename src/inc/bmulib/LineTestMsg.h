
/****************************************************************
** 文 件 名：TestMsg.h
** 简    叙: Test消息

** 作　  者：yuanf
** 日　  期：2012.9.17
** 修改说明：创建

****************************************************************/
#ifndef	INC_TESTMSG_H
#define	INC_TESTMSG_H
#include "bmuType.h"
#define	MAX_LINE_CODE_LEN	16

#ifdef	__cplusplus
extern  "C"{
#endif	/* __cplusplus */

/********************************************/
/*            线路Test数据结构              */
/********************************************/
struct LineTest
{
	/*线路号信息*/
	unsigned char lineCode[MAX_LINE_CODE_LEN];		/*线路号*/
	unsigned char lineLen;							/*线路号长度*/
	
	/*控制平面设置的TEST消息信息*/
	unsigned char ucSetTestValid;					/*设置的TEST消息有效标志 0/1 = 无效/有效*/
	unsigned char ucEnable;							/*TEST 消息使能标志 0/1 = 不使能/使能*/
	unsigned char ucSetTestLen;						/*设置的TEST消息长度 16/64字节*/
	unsigned char ucSetTestMsg[64];					/*设置的TEST消息存放地址*/

	/*单盘上报的TEST消息信息*/
	unsigned char ucReportFlag;						/*主动上报TEST消息标志 0/1 = 不上报/上报*/
	unsigned char ucReportTestValid;				/*当前Test是否有效1：有效 0：无效*/	
	unsigned char ucReportTestLen;					/*上报的TEST消息长度 16/64字节*/
	unsigned char ucReportTestMsg[64];				/*上报的Test消息存放地址*/

	unsigned char ucCheckTest[3][64];				/*校验Test消息*/
	unsigned char ucSendTestMsg[64];				/*上报的TEST消息*/
};

/*****************************************************
函数名：TestMsgInit()

功 能：	Test消息处理模块初始化函数

输 入：	无
		
输 出：	OK

描 述：	Test消息处理模块初始化。

作 者：	yuanf
			
修 改：	创建

时 间：	2012.9.17	
*****************************************************/ 
extern int TestMsgInit(void);

/*****************************************************
函数名：RegTestMsgSetFunc()

功 能：	注册设置Test消息的函数

输 入：	func	注册的函数地址
		
输 出：	OK

描 述：	注册的函数在testmsg任务中被调用，此函数功能用于设置接收的Test消息。
		func函数原型：
		int func(void)
		{
		
			return OK;
		}

作 者：	yuanf
			
修 改：	创建

时 间：	2012.9.17	
*****************************************************/ 
extern int RegTestMsgSetFunc(FUNCPTR func);

/*****************************************************
函数名：RegTestMsgGetFunc()

功 能：	注册获取Test消息的函数

输 入：	func	注册的函数地址
		
输 出：	OK

描 述：	注册的函数在testmsg任务中被调用，此函数功能用于读从芯片接收的Test消息，并将Test消息赋值到Test消息数据结构中。
		func函数原型：
		int func(void)
		{
		
			return OK;
		}。

作 者：	yuanf
			
修 改：	创建

时 间：	2012.9.17	
*****************************************************/ 
extern int RegTestMsgGetFunc(FUNCPTR func);

/*****************************************************
函数名：RegLineTest()

功 能：	注册一条线路Test消息数据结构

输 入：	pstuTest	Test消息数据结构
		
输 出：	OK:		注册成功
		ERROR:	注册失败
		
描 述：	注册一条线路Test消息数据结构

作 者：	yuanf
			
修 改：	创建

时 间：	2012.9.17		
*****************************************************/ 
extern STATUS RegLineTest(struct LineTest *pstuTest);

/*****************************************************
函数名：DeleteLineTest()

功 能：	删除注册的Test消息

输 入：	无
		
输 出：	OK

描 述：	删除注册的Test消息。

作 者：	yuanf
			
修 改：	创建

时 间：	2012.9.17	
*****************************************************/ 
extern int DeleteLineTest(struct LineTest *pstuTest);

/*****************************************************
函数名：SetTestMsgLoopWaitTime()

功 能：	设置TEST消息处理任务轮询一次等待的时间，默认等待10ms

输 入：	ms		TEST消息任务轮询等待的时间，单位ms，必须是最小10ms，必须是10倍数
		
输 出：	OK

描 述：	这个函数修改任务testmsg中taskDelay的时间，最小10ms，必须是10的倍数。
		默认是10ms。

作 者：	yuanf
			
修 改：	创建

时 间：	2014.11.12	
*****************************************************/ 
extern int SetTestMsgLoopWaitTime(unsigned int ms);

/*****************************************************
函数名：PrintTest() 

功 能：	打印线路Test链表信息

输 入：	detail	0	显示Test消息概要信息
				1	显示Test消息详细信息
		
输 出：	OK

描 述：	调试时可通过这个函数查看单盘线路Test链表的信息。

作 者：	yuanf
	
修 改：	创建

时 间：2012.9.17
*****************************************************/
int PrintTest(int detail);

#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif	/*INC_TestMsg_H*/

/***************************************************************/
/*************************End Testmsg.h*************************/
/***************************************************************/

