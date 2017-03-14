/****************************************************************
** 文 件 名：uasLibV2.h
** 简    叙: UAS计算程序V2版本。
** 作　  者：yuanf

** 修 改 人：yuanf
** 日　  期：2012.05.15	
** 修改说明：创建

** 版    本：1.0

****************************************************************/

#ifndef	INC_UASLIBV2_H
#define	INC_UASLIBV2_H
#include "bmuType.h"

#if	__cplusplus
extern "C"
{
#endif /*__cplusplus*/

struct USR_UAS_STRUCT
    {
		/* 用户输入数据*/		
		unsigned long	ulSesLimit;				/*线路严重误码秒门限*/
		unsigned long long ullErrorCounter;		/*采集的误码个数计数(8字节)*/		
		unsigned char ucLofFlag;				/*当前秒线路信号状态是否有Lof的标志(1有LOF，0无LOF)*/		
		unsigned char ucDefectFlag;				/*当前秒线路信号状态是否有严重缺陷标志(1有严重缺陷，0无严重缺陷)*/

        /*UAS计算结果输出数据*/       
		unsigned short usEscapeSecond;			/*15分钟内消逝的时间 单位：秒*/
        unsigned short usLofSecond;				/*15分钟内有LOF(帧丢失)的时间(单位：秒)*/       
        unsigned short usEsSecond;				/*15分钟内有Es(有误码包括严重误码)的时间(单位：秒)*/        
        unsigned short usNoEsSecond;			/*15分钟内没有误码的时间(单位：秒)*/       
        unsigned short usSesSecond;				/*15分钟内有SES(严重误码)的时间(单位：秒)*/       
        unsigned short usCsSesSecond;			/*15分钟内有连续SES(严重误码)的时间(单位：秒)*/      
        unsigned short usUasSecond;				/*15分钟内有UAS(不可用秒)的时间(单位：秒)*/       
        unsigned short usUsedSecond;			/*15分钟内正常使用(无UAS)的时间(单位：秒)*/        
        unsigned long long ullCvs;				/*15分钟内所有(包括UAS和ES)的误码个数计数(8个字节)*/       
        unsigned long long ullBbe;				/*15分钟内背景块误码个数计数(8个字节)*/             
        float fEsRate;							/*15分钟内误码秒比*/        
        float fSesRate;							/*15分钟内严重误码秒比*/

        /*临时存储的数据*/        
        unsigned char ucNoUseFlag;				/*信号不可用标志*/       
        unsigned char ucEsTemp;					/*处于不可用状态下的有ES的时间*/      
        unsigned char ucNoEsTemp;				/*处于不可用状态下的无误码时间*/       
        unsigned char ucSesTemp;				/*处于可以状态下的不可用时间*/       
        unsigned long long ullBbeTemp;			/*处于不可用状态下的误码个数*/
		struct USR_UAS_STRUCT *pstuNext;		/*下一个UAS数据结构*/
    }; 

/*****************************************************
    函数名：UasLibInit()

    功 能：	UAS计算库初始化函数

    输 入：	无

    输 出：	OK		初始化成功
    		ERROR	初始化失败

    描 述：	初始化UAS计算需要的变量和其它资源

    作 者：	yuanf

    修 改： 创建

    时 间： 2012.05.15
*****************************************************/
extern int UasLibInit(void);

/*****************************************************
    函数名：RegUas()

    功 能：	注册一个需要计算的UAS。

    输 入：	pstuUserUas		需要计算的UAS数据结构

    输 出：	OK		注册成功
    		ERROR	注册错误
    				原因：	1 输入参数为NULL
    						2 输入的UAS数据结构已经被注册
    						3 没有足够的内存

    描 述：	这个函数向UAS库输入一个UAS数据结构,并根据此结构，公共库计算UAS值。在这个数据结构中:
    	ucLofFlag,ucDefectFlag,ulSesLimit,ullErrorCounter是用户输入的数据，作为UAS计算的依据

    	ucLofFlag		当前秒线路信号状态是否有Lof的标志(1有LOF，0无LOF)
    	ucDefectFlag	当前秒线路信号状态是否有严重缺陷标志(1有严重缺陷，0无严重缺陷)  	
    	ulSesLimit		线路严重误码秒门限
    	ullErrorCounter	采集的误码个数计数(8字节)

		usEscapeSecond	15分钟内时间值
    	usLofSecond		15分钟内LOF值
    	usEsSecond		15分钟内ES值
    	ucSesCode		15分钟内SES值
    	ucCsSesCode		15分钟内CSSES值
    	usCvsCode		15分钟内CVS值
    	usBbeCode		15分钟内BBE值
    	ucUasCode		15分钟内UAS值
    	ucNoEsCode		15分钟内NOES值
    	ucUseCode		15分钟内USE值
    	ucEsRate		15分钟内误码秒比
    	ucSesRate		15分钟内严重误码秒比

    	NOES			指15分钟内没有ES和UAS的时间
    	USE				指15分钟内没有UAS的时间
    	误码秒比		指15分钟内ES/USE的值
    	严重误码秒比	指15分钟内SES/USE的值
    	
    	例：

    	struct USR_UAS_STRUCT g_stuVc4Uas[4];

		for(i = 0; i < 4; i++)
		{
			//严重误码门限
    		g_stuVc4Uas[i].ulSesLimit = 2500; 	
    		RegUas(&g_stuRsUas);
		}

    作 者：	yuanf

    修 改： 创建

    时 间： 2012.05.15
*****************************************************/  
extern int RegUas(struct USR_UAS_STRUCT *pstuUserUas);

/*****************************************************
    函数名：DeleteUas()

    功 能：	注册一个需要计算的UAS。

    输 入：	pstuUserUas		需要删除的UAS数据结构

    输 出：	OK		删除成功
    		ERROR	删除错误
    				原因：	1 没有找到指定的UAS数据结构

    描 述：	删除一个已经注册的UAS数据结构

    		例：	DeleteUas(&g_stuVc4Uas[1]);
    作 者：	yuanf

    修 改： 创建

    时 间： 2012.05.15
*****************************************************/
extern int DeleteUas(struct USR_UAS_STRUCT *pstuUserUas);

/*****************************************************
    函数名：RegUasGatherFunc()

    功 能：	注册采集误码的函数。

    输 入：	func		采集误码的函数

    输 出：	OK		注册成功
    		ERROR	注册错误
    				原因：	1 输入参数为NULL  						
    						2 没有注册UAS

    描 述：	这个函数注册误码采集函数。在误码采集函数中应对UAS数据结构的成员
    		ucLofFlag，ucDefectFlag，ulErrorCounter赋值，便于计算UAS.

    		注意：在执行这个函数前请先执行RegUas(),完成UAS计算的初始化。

    		例：
			struct USR_UAS_STRUCT g_stuVc4Uas[4];
    		int GatherError(void)
    		{
    			int i;
    			for(i = 0; i < 4; i++)
    			{
    				g_stuVc4Uas[i].ucLofFlag = 1;
    				g_stuVc4Uas[i].ucDefectFlag = 1;
    				g_stuVc4Uas[i].ullErrorCounter += 10000;
    			}

    			return OK;
    		}
    		
    		int UsrEntry(void)
    		{
				int i;

				for(i = 0; i < 4; i++)
				{	
					RegUas(&g_stuVc4Uas[i]);
				}

    			RegUasGatherFunc((FUNCPTR)GatherError);
    		}

    作 者：	yuanf

    修 改： 创建

    时 间： 2012.5.15
*****************************************************/
extern int RegUasGatherFunc(FUNCPTR func);

/*****************************************************
    函数名：RegGetUasResultFunc()

    功 能：	注册UAS计算结果赋值到性能的函数。

    输 入：	func		UAS计算结果赋值到性能的函数

    输 出：	OK		注册成功
    		ERROR	注册错误
    				原因：	1 输入参数为NULL
    						2 没有注册UAS

    描 述：	通过此函数注册的用户函数func(),在UAS处理任务(tUasCal)计算当前秒的UAS后，
			调用一次，将UAS计算结果赋给性能。

    		注意：在执行这个函数前请先执行RegUas(),完成UAS计算的初始化。

    		例：int GetUasPmResult(void)
				{
					int i;

					for(i = 0; i < 4; i++)
					{
						for(i = 0; i < 4; i++)
						{
							SetPm(1,(char *)&lineCode[i],7,0,0,0,LOF_CODE,1,g_stuVc4Uas[i].usLofSecond);
							SetPm(1,(char *)&lineCode[i],7,0,0,0,ES_CODE,1,g_stuVc4Uas[i].usEsSecond);
							SetPm(1,(char *)&lineCode[i],7,0,0,0,SES_CODE,1,g_stuVc4Uas[i].usSesSecond);
							SetPm(1,(char *)&lineCode[i],7,0,0,0,CVS_CODE,1,g_stuVc4Uas[i].ullCvs);
						}
					}
				}

				RegGetUasResultFunc((FUNCPTR)GetUasPmResult);
    		
    作 者：	yuanf

    修 改： 创建

    时 间： 2012.05.15
*****************************************************/
extern int RegGetUasResultFunc(FUNCPTR func);	

/*****************************************************
    函数名：RegUasTask1sProcFunc()

    功 能：	注册在误码处理任务中1s时刻点处理函数。

    输 入：	func		1s时间到时的处理函数

    输 出：	OK		注册成功
                ERROR	注册错误
                                原因：	1 输入参数为NULL
                                                2 没有足够的内存
                                                3 没有注册UAS

    描 述：	通过此函数注册的用户函数func(),在UAS处理任务(tUasCal)时每隔
                1秒钟被执行一次。可以处理与UAS相关的一些标志、告警、性能和单
                盘的特殊要求。

                注意：在执行这个函数前请先执行RegUas(),完成UAS计算的初始化。

                例：
                int ProcFunc1(void)
        {
                if(g_stuRsUas.ullErrorCounter > g_uiSdAlmLimit)
                {
                        //设置告警标志
                        SetSdAlmFlag(ON);
                }
                else
                {
                        //告警已经处理后才能清除告警标志
                        if(IsSdAlm() == OK)
                        {
                                //清除告警标志
                                SetSdAlmFlag(OFF)
                        }
                }

                return OK;
        }

        int UsrEntry(void)
        {
                RegUasTask1sProcFunc((FUNCPTR)ProcFunc1);
        }

    作 者：	yuanf

    修 改： 创建

    时 间： 2009.12.05
*****************************************************/
extern int RegUasTask1sProcFunc(FUNCPTR func);

/*****************************************************
    函数名：ActiveUasTask()

    功 能：	激活误码采集和UAS计算的任务。

    输 入：	无

    输 出：	OK		激活看门狗定时器成功。
    		ERROR	激活看门狗定时器失败或没有注册UAS

    描 述：	这个函数激活看门狗的定时器，当时间到时释放信号量，
    		激活误码采集和UAS计算任务(tUasCal)，并同时重新启
    		动看门狗定时器。UAS注册和误码采集注册完成后，必须
    		通过这个函数激活误码计算的任务(tUasCal)，否则UAS库
    		不会执行误码采集函数和误码计算。

    作 者：	yuanf

    修 改： 创建

    时 间： 2012.05.15
*****************************************************/
extern int ActiveUasTask(void);


/*****************************************************
    函数名：ModifyUasGatherTime()

    功 能：	这个函数修改注册的误码采集函数的执行间隔时间。

    输 入：	ms		每次执行采集误码函数的时间间隔，单位ms，取值范围5-1000ms

    输 出：	OK		修改成功
    		ERROR	没有注册UAS

    描 述：	默认情况下误码采集函数每100ms执行一次，用这个函数可以加快或减慢误
    		码采集函数执行的频率。为防止芯片误码计数器溢出，可以加快误码采集函
    		数的执行频率。参数ms取值时最好满足ms*n = 1000,其中n为整数。

    		例：
    		ModifyUasGatherTime(500);
    		或
    		ModifyUasGatherTime(1000);

    作 者：	yuanf

    修 改： 创建

    时 间： 2012.05.15
*****************************************************/
extern int ModifyUasGatherTime(int ms);

/*****************************************************
    函数名：ModifyUasTaskPriority()

    功 能：	这个函数修改误码采集和UAS计算任务tUasCal的优先级。

    输 入：	newPriority		任务tUasCal的新优先级

    输 出：	OK		修改成功
    		ERROR	任务tUasCal不存在

    描 述：	默认情况下任务tUasCal的优先级为100，通过这个函数可以提高和降低任务tUasCal的优先级。

    		例：
    		ModifyUasTaskPriority(150);

    作 者：	yuanf

    修 改： 创建

    时 间： 2012.05.15
*****************************************************/
extern int ModifyUasTaskPriority(int newPriority);

/*****************************************************
    函数名：uasShow()

    功 能：	这个函数在终端上显示UAS数据结构的性能值。

    输 入：pstuUasNode	指定的UAS数据结构地址

    输 出：	OK		成功
    		ERROR	没有注册UAS

    描 述：	这个函数用于调试UAS计算

    作 者：	yuanf

    修 改： 创建

    时 间： 2012.05.15
*****************************************************/
extern int uasShow(struct USR_UAS_STRUCT *pstuUasNode);


#if	__cplusplus
}
#endif /*__cplusplus*/

#endif	/*INC_UASLIBV2_H*/

/***************************************************************/
/**************************End uasLibV2.h***********************/
/***************************************************************/
