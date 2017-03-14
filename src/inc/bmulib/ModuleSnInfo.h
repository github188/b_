/****************************************************************
** 文 件 名：ModuleSnInfo.h
** 简    叙: 模块SN信息存储和获取接口头文件

** 作　  者：yuanf
** 日　  期：2014.3.27
** 修改说明：创建

****************************************************************/
#ifndef	INC_MODULESNINFO_H
#define	INC_MODULESNINFO_H
#include "bmuType.h"

#ifdef	__cplusplus
extern  "C"{
#endif	/* __cplusplus */


/*****************************************************
函数名：RegModuleInfoFunc()

功 能：	注册模块信息读函数

输 入：	chipType	器件类型
					0x01	单盘
					0x02	光模块
					0x03	子卡
		chipSeq		同类器件编号从1开始
		infoType	信息类型
		readFunc	读信息存储空间操作函数
					
			
输 出：	OK		注册成功
		ERROR	注册失败

描 述：	将读器件存储信息的接口挂到公共库中。
		对单盘信息类型如下：
		0x10	盘SN号
		0X11	厂家名
		0x12	产地
		0x13	生产日期
	
		对光模块信息类型如下:
		0x50	光模块SN号
		0x51	光模块类型
		0x52	光模块厂家
		0x53	产地
		0x54	器件位置信息
		0x55	生产日期


		读操作函数原型如下：
		int readFunc(unsigned int chipType,unsigned int chipSeq,unsigned int infoType,char *infoBuffer,unsigned int *pbufLen)
		{

			return n;
		}
	
		参数：chipType		器件类型
			  chipSeq		器件编号	
			  infoType		信息类型		
			  infoBuffer	读出数据存放buffer地址
			  pbufLen		表示读出的数据长度
		返回值	n			当操作失败时，返回ERROR(-1)
							操作成功时，返回OK

		写操作函数原型如下：
		int writeFunc(unsigned int chipType,unsigned int chipSeq,unsigned int infoType,char *infoBuffer,unsigned int bufLen)
		{

			return n;
		}
	
		参数：chipType		器件类型
			  chipSeq		器件编号	
			  infoType		信息类型	
			  infoBuffer	写入数据存放buffer地址
			  bufLen		表示写入的数据长度
		返回值	n			当操作失败时，返回ERROR(-1)
							操作成功时，返回OK(0)

作 者：	yuanf
	
修 改：创建

时 间：2014.3.27			
*****************************************************/
extern int RegModuleInfoFunc(unsigned int chipType,unsigned int chipSeq,unsigned int infoType,FUNCPTR readFunc,FUNCPTR writeFunc);

/*****************************************************
函数名：showRegChipSnInfo()

功 能：	查看注册的器件信息接口

输 入：	无
			
输 出：	OK		

描 述：	显示所有注册的器件信息类型和操作接口函数

作 者：	yuanf
	
修 改：创建

时 间：2014.3.27			
*****************************************************/
extern int showRegChipSnInfo(void);

#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif	/*INC_MODULESNINFO_H*/

/***************************************************************/
/**********************End ModuleSnInfo.h***********************/
/***************************************************************/

