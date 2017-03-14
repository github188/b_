
/****************************************************************
** 文 件 名：bmuReportAlmPmToEmu.h
** 简    叙: bmu公共库中向EMU上报告警和性能的数据结构及相关的函数声明

** 作　  者：yuanf
** 日　  期：2007.05.09

** 版    本：1.0

** 函数列表：RegReportAlm()
			 SetReportAlmValid()
			 PrintReportAlm()
			 RegReportPm()
			 SetReportPmValid()
			 PrintReportPm()			 
****************************************************************/
#ifndef	INC_BMUREPORTALMPMTOEMU_H
#define	INC_BMUREPORTALMPMTOEMU_H

#ifdef	__cplusplus
extern  "C"{
#endif	/* __cplusplus */


/********************************************/
/*        来源于用户层的告警数据结构        */
/********************************************/
struct ALM
{
	UINT8	ucAlmCode;	/*告警代码*/
	UINT8	ucAlmType;	/*告警类型
						0：主要告警
						2：紧急告警
						4：次要告警
						8：提示告警
						*/
	UINT8	ucPri;		/*告警优先级
						bit7: 0 这个告警影响子线路告警
							  1 这个告警不影响本线路的告警且不影响子线路告警
							 
						bit6－bit0：告警优先级1－127，同一线路高优先级告警屏蔽低优先级告警
									1为高优先级127为低优先级；父线路告警屏蔽子线路告警。
						ucPri = 0表示这个告警不参加告警优先级比较
						*/
						
	UINT8	ucState;	/*告警状态1：告警  0：告警消失(参与告警抖动抑制) 
									2：告警消失(不参与告警抖动抑制)*/
};


/*****************************************************
函数名：RegReportAlm()

功 能：	注册一个需要上报给EMU的告警
	
输 入：	usLineCode		告警的线路号
		pstuAlm			告警的数据结构指针
			
输 出：	OK:		注册成功
		ERROR:	注册失败

描 述：	这个函数注册一个上报给EMU的告警，这类告警通常是影响DCC通道连接状态的告警。
		EMU通过这类告警判断DCC通道是否正常，是否需要切换到其它端口上去。注册的告警
		在告警发生变化时，通过命令10 13 00上报给EMU,同时，如果单盘接收到EMU获取告警
		的命令时，也会通过命令10 13 00上报给EMU.默认情况下通过此函数注册的告警都是有
		效的，可以通过函数SetReportAlmValid()修改其有效标志。通过函数PrintReportAlm()
		可以查看此函数注册的告警。

作 者：	yuanf	
修 改：	创建	
时 间：	2008.8.5			
*****************************************************/
extern int RegReportAlm(UINT16 usLineCode,	struct ALM *pstuAlm);

/*****************************************************
函数名：SetReportAlmValid()

功 能：	设置注册的上报给EMU的告警是否有效

输 入：	usLineCode	需要设置的告警的线路号
		ucAlmCode	需要设置的告警的告警代码
		ucValidFlag 告警有效标志
					 0 告警无效
					 1 告警有效		
输 出：	OK:		设置注册的告警有效标志成功
		ERROR:	设置注册的告警有效标志失败

描 述：	如果注册的上报给EMU的告警无效，单盘将不会将此告警上报给EMU。

作 者：	yuanf	
修 改：	创建	
时 间：	2008.8.5			
*****************************************************/
extern int SetReportAlmValid(unsigned short usLineCode, unsigned char ucAlmCode,unsigned char ucValidFlag);

/*****************************************************
函数名：PrintReportAlm()

功 能：	显示注册的上报给EMU的告警
	
输 入：	无

输 出：	OK:		

描 述：	显示注册的上报给EMU的告警，在调试时使用这个函数参看注册的上报给EMU的告警。

作 者：	yuanf	
修 改：	创建	
时 间：	2008.8.5			
*****************************************************/
extern int PrintReportAlm(void);

/*****************************************************
函数名：RegReportPm()

功 能：	注册一个需要上报给EMU的性能
	
输 入：	usLineCode		性能的线路号
		pstuPm			性能的数据结构指针
				
输 出：	OK:		注册成功
		ERROR:	注册失败

描 述：	这个函数注册一个上报给EMU的性能，这类性能通常是EMU需要知道的性能，比如单盘工作温度。
		如果注册的性能有效，在单盘接收到EMU获取告警的命令时，通过命令10 13 00将性能上报给EMU.
		默认情况下通过此函数注册的性能都是有效的，可以通过函数SetReportPmValid()修改其有效标志。
		通过函数PrintReportPm()可以查看此函数注册的性能。
		上报给EMU的单盘温度，性能代码固定为0x13，上报的数据格式为float
		上报给EMU的单盘温度下限，性能代码固定为0x14，上报的数据格式为float
		上报给EMU的单盘温度上限，性能代码固定为0x15，上报的数据格式为float
		
		例：
		温度上报
		fValue = 15.5;
		g_stuTemperature.ucPmCode = 0x13;
		g_stuTemperature.ucFlag = 3;
		g_stuTemperature.uValue.fvalue = fValue;
		RegReportPm(0x0001,&g_stuTemperature);

		温度下限
		fValue = 45.5;
		g_stuTemperatureDownLimit.ucPmCode = 0x14;
		g_stuTemperatureDownLimit.ucFlag = 3;
		g_stuTemperatureDownLimit.uValue.fvalue = fValue;
		RegReportPm(0x0001,&g_stuTemperatureDownLimit);

		温度上限
		fValue = 65.5;
		g_stuTemperatureUpLimit.ucPmCode = 0x15;
		g_stuTemperatureUpLimit.ucFlag = 3;
		g_stuTemperatureUpLimit.uValue.fvalue = fValue;
		RegReportPm(0x0001,&g_stuTemperatureUpLimit);
		
作 者：	yuanf	
修 改：	创建	
时 间：	2008.8.5			
*****************************************************/
extern int RegReportPm(UINT16 usLineCode,	struct PM *pstuPm);

/*****************************************************
函数名：SetReportPmValid()

功 能：	设置注册的上报给EMU的性能是否有效

输 入：	usLineCode	需要设置的性能的线路号
		ucPmCode	需要设置的性能的告警代码
		ucValidFlag 告警有效标志
					 0 性能无效
					 1 性能有效	
					 				
输 出：	OK:		设置注册的性能有效标志成功
		ERROR:	设置注册的性能有效标志失败

描 述：	如果注册的上报给EMU的性能无效，单盘将不会将此性能上报给EMU。

作 者：	yuanf	
修 改：	创建	
时 间：	2008.8.5			
*****************************************************/
extern int SetReportPmValid(unsigned short usLineCode, unsigned char ucPmCode,unsigned char ucValidFlag);

/*****************************************************
函数名：PrintReportPm()

功 能：	显示注册的上报给EMU的性能

输 入：	无
	
输 出：	OK:		

描 述：	显示注册的上报给EMU的性能，在调试时使用这个函数参看注册的上报给EMU的性能。

作 者：	yuanf	
修 改：	创建	
时 间：	2008.8.5			
*****************************************************/
extern int PrintReportPm(void);


#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif	/*INC_BMUREPORTALMPMTOEMU_H*/

/***************************************************************/
/*******************End bmuReportAlmPmToEmu.h*******************/
/***************************************************************/

