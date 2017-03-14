
/****************************************************************
** 文 件 名：bmuV2Pm.h
** 简    叙: bmu公共库性能接口

** 作　  者：yuanf
** 日　  期：2012.3.14
** 修改说明：创建

****************************************************************/
#ifndef	INC_BMUV2PM_H
#define	INC_BMUV2PM_H
#include "bmuType.h"
/********************************************/
/*        来源于用户层的性能数据结构        */
/********************************************/
struct PM
{
    UINT8 ucPmCode;              /*性能代码*/
    union INT_SHORT uValue;         /*性能值*/
    UINT8 ucFlag;                               /*性能算法标志
                                                                0：性能为整数值，历史性能值按时间点直接上报
                                                                1：性能为整数值，累计性能值为每15分钟采集的值直接相加。
                                                                2：性能为整数值，历史性能上报15分钟时间段内的最大最小值，此性能不支持0x93扩展
                                                                3：性能为单精度浮点数，历史性能值按时间点直接上报，此性能不支持0x93扩展
                                                                4：性能为单精度浮点数，历史性能上报15分钟时间段内的最大最小值，此性能不支持0x93扩展
                                                                other：备用
                                                                注：BMU公共库只处理采用NMU_BMU通信协议的累计性能、24小时历史性能和15分钟历史性能。
                                                                    不处理EMU_BCT通信协议的累计性能、24小时历史性能。
                                                 */
};

#ifdef	__cplusplus
extern  "C"{
#endif	/* __cplusplus */

/*****************************************************
函数名：RegPmCode()

功 能：	注册性能代码。

输 入：	uiPmCode		性能从属的线路索引
		ucPmType		性能类型 	0：普通性能
									1：累计性能
									2：计算最大最小值性能
		ucValueType		性能值类型	0：2字节整数
									1：4字节整数
									2: 8字节整数
									3：4字节浮点数
									4: 8字节浮点数
		pmName			性能名

输 出：	无

返回值：性能代码索引

描 述：	输入一个性能

作 者： yuanf
	
修 改：创建

时 间：2012。05.29				
*****************************************************/ 
extern int RegPmCode(unsigned int uiPmCode,unsigned char ucPmType,unsigned char ucValueype,char *pmName);


/*****************************************************
函数名：SetPm()

功 能：	设置性能。

输 入：	lineIndex	性能从属的线路索引
		pmIndex		性能代码索引
		pmValue		性能值存放地址

输 出：	无

返回值：OK

描 述：	设置单盘指定性能的值

作 者： yuanf
	
修 改：创建

时 间：2012。05.29			
*****************************************************/ 
extern int SetPm(unsigned int lineIndex,unsigned int pmIndex,unsigned char *pmValue);

/*****************************************************
函数名：MaskPmCode()

功 能：	设置性能代码屏蔽。

输 入：	uiPmCode		性能代码
		maskState		屏蔽标志	0：不屏蔽
									1：屏蔽

输 出：	无

返回值：OK

描 述：	按代码进行性能屏蔽

作 者： yuanf
	
修 改：创建

时 间：2012.05.29			
*****************************************************/ 
extern int MaskPmCode(unsigned int uiPmCode,unsigned int maskState);

/*****************************************************
函数名：MaskLinePm()

功 能：	设置线路性能屏蔽。

输 入：	lineIndex		线路索引号
		pmIndex			性能代码索引号
		maskState		屏蔽标志	0：不屏蔽
									1：屏蔽

输 出：	无

返回值：OK

描 述：	按线路和性能代码进行性能屏蔽

作 者： yuanf
	
修 改：创建

时 间：2012.05.29			
*****************************************************/ 
extern int MaskLinePm(unsigned int lineIndex,unsigned int pmIndex,unsigned int maskState);

/*****************************************************
函数名：RegQuarterFunc()

功 能：	注册性能清零处理函数

输 入：	func	性能清零处理函数
		
输 出：	OK			

描 述：	注册的性能清零处理函数在收到网管的性能清零命令后执行一次。

作 者：	yuanf
	
修 改：创建

时 间：2012.05.08			
*****************************************************/
extern int RegQuarterFunc(FUNCPTR func);

/*****************************************************
函数名：RegClearPmFunc()

功 能：	注册性能清零处理函数

输 入：	func	性能清零处理函数
		
输 出：	OK			

描 述：	注册的性能清零处理函数在收到网管的性能清零命令后执行一次。

作 者：	yuanf
	
修 改：创建

时 间：2012.05.08			
*****************************************************/
extern int RegClearPmFunc(FUNCPTR func);


/*****************************************************
   函数名：StartRealPmWd()

   功 能：	启动实时性能看门狗定时器

   输 入：	ticks	看门狗定时器定时时间

   输 出：	OK		操作成功
                ERROR	操作失败

   描 述：	此函数调用wdStart()启动实时性能看门狗定时器。

   作 者：	yuanf
   修 改：	创建
   时 间：	2009.4.21
*****************************************************/
extern int StartRealPmWd(int ticks);

/*****************************************************
   函数名：RegKeyRealPm()

   功 能：	注册需要处理的实时性能数据结构

   输 入：	uiLineLen	实时性能的线路号长度
                lineValue	实时性能的线路存放地址
                pstuPm		性能数据结构

   输 出：	OK		注册成功
                ERROR	注册失败
                                原因：	1 pstuPm为空指针
                                                2 内存空间不足

   描 述：	此函数向公共库输入一个性能数据结构，公共库对这个性能进行
                实时性能处理，每隔一段时间记录一次性能值。并响应网管对实
                时性能的查询。

                注：1 在注册实时性能时没有按线路排序，因此应将同线路的实时性能进行连续注册
                        2 在注册时没有检查实时性能是否重复，应避免同一个性能多次注册
                        3 如果一个实时性能有扩展性能代码0x93，则0x93也需要注册

                例：
                        struct PM g_stuPmIop;
                        struct PM g_stuExtBBE;
                        struct PM g_stuPmBBE;
                        char LineCode[7];

                        g_stuPmIop.ucPmCode = 0x01;
                        g_stuPmIop.ucFlag = 3;
                        g_stuPmIop.uValue.fvalue = 0;
                        LineCode[0] = 0;
                        LineCode[1] = 1;
                        LineCode[2] = 0;
                        LineCode[3] = 1;
                        LineCode[4] = 2;
                        LineCode[5] = 1;
                        LineCode[6] = 1;
                        RegKeyRealPm(7,LineCode,&g_stuPmIop);

                        g_stuExtBBE.ucPmCode = 0x93;
                        g_stuExtBBE.ucFlag = 1;
                        g_stuExtBBE.uValue.uint = 0;
                        RegKeyRealPm(7,LineCode,&g_stuExtBBE);

                        g_stuPmBBE.ucPmCode = 0x01;
                        g_stuPmBBE.ucFlag = 1;
                        g_stuPmBBE.uValue.uint = 0;
                        RegKeyRealPm(7,LineCode,&g_stuPmBBE);

   作 者：	yuanf
   修 改：	创建
   时 间：	2009.4.21
*****************************************************/
int RegKeyRealPm(unsigned int uiLineLen, char *lineValue, struct PM *pstuPm);

/*****************************************************
   函数名：RegRealPmGather()

   功 能：	注册实时性能采集函数

   输 入：	pRealPmGather		实时性能采集函数

   输 出：	OK

   描 述：	此函数注册的函数被实时任务周期调用，当实时性能值
                不太准确时，可以将采集实时性能的函数放到实时性能
                任务中调用。

   作 者：	yuanf
   修 改：	创建
   时 间：	2009.4.21
*****************************************************/
STATUS RegRealPmGather(FUNCPTR pRealPmGather);


/*****************************************************
   函数名：DeleteRegKeyRealPm()

   功 能：	按线路删除注册的实时性能

   输 入：	uiLineLen	实时性能的线路号长度
                lineValue	实时性能的线路存放地址


   输 出：	OK		删除成功

   描 述：	按线路删除已经注册的实时性能

   作 者：	yuanf
   修 改：	创建
   时 间：	2013.10.15
*****************************************************/
int DeleteRegKeyRealPm(unsigned int uiLineLen, char *lineValue);

/*****************************************************
   函数名：DeleteReportKetRealPm()

   功 能：	按线路删除正在采集的实时性能

   输 入：	uiLineLen	实时性能的线路号长度
                lineValue	实时性能的线路存放地址


   输 出：	OK		删除成功

   描 述：	按线路删除正在采集的实时性能

   作 者：	yuanf
   修 改：	创建
   时 间：	2013.10.15
*****************************************************/
int DeleteReportKetRealPm(unsigned int uiLineLen, char *lineValue);

/*****************************************************
函数名：showPmCode()

功 能：	查看注册的性能代码

输 入：	无
		
输 出：	OK			

描 述：	查看注册的性能代码。

作 者：	yuanf
	
修 改：创建

时 间：2012.05.08			
*****************************************************/
extern int showPmCode(void);

#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif	/*INC_BMUV2PM_H*/

/***************************************************************/
/************************End bmuV2Pm.h*************************/
/***************************************************************/
