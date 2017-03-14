
/****************************************************************
** 文 件 名：bmuV2ALine.h
** 简    叙: bmu公共库线路接口

** 作　  者：yuanf
** 日　  期：2012.3.14
** 修改说明：创建

****************************************************************/
#ifndef	INC_BMUV2Line_H
#define	INC_BMUV2Line_H

#ifdef	__cplusplus
extern  "C"{
#endif	/* __cplusplus */


/*****************************************************
函数名：RegLineCode()

功 能：	注册一条新线路

输 入：	uiLineTag			线路tag值
		pLineValue			线路值
		uiLineLen			线路值长度
		uiKeyWord		线路业务关键字
		pKeyName			线路业务关键字名称
		pKeyNameLen			线路业务关键字名称长度
	
输 出：	线路索引

描 述：	通过这个函数通知公共库增加了一条业务关键字线路。
		
作 者：	yuanf
	
修 改： 创建

时 间：	2012.4.5		
*****************************************************/
extern int RegLineCode(unsigned int uiLineTag,unsigned char *pLineValue,unsigned int uiLineLen,unsigned int uiKeyWord,unsigned char *pKeyName,unsigned char pKeyNameLen);


/*****************************************************
函数名：DeleteOneLineCode()

功 能：	删除一条线路，并将线路上的全部告警和性能删除

输 入：	lineIndex		要删除的线路索引

输 出：	OK				删除正确
		ERROR			没有找到指定的线路

描 述：	删除一条线路，并将线路上的全部告警和性能删除

作 者：	yuanf
	
修 改：	创建

时 间：	2012.4.5	
*****************************************************/
//extern int DeleteOneLineCode(unsigned int lineIndex);

/*****************************************************
函数名：DeleteOneLine()

功 能：	删除一条线路，并将线路上的全部告警和性能删除

输 入：	lineIndex		要删除的线路索引

输 出：	OK		删除正确
		ERROR	没有找到指定的线路

描 述：	删除一条线路，并将线路上的全部告警和性能删除

作 者：	yuanf
	
修 改：	创建

时 间：	2012.4.5	
*****************************************************/
int DeleteOneLine(unsigned int lineIndex);


/*****************************************************
函数名：showLine()

功 能：	查看线路信息和线路下的告警和性能数据

输 入：	lineIndex		要查看的线路索引
		flag			控制标志
						0	查看线路下的性能
						1	查看线路下的高警
		
输 出：	OK			

描 述：	查看线路信息和线路下的告警和性能数据。

作 者：	yuanf
	
修 改：创建

时 间：2012.05.08			
*****************************************************/ 
extern int showLine(unsigned int lineIndex,unsigned char flag);

/*****************************************************
函数名：SetBoardSn()

功 能：	设置单盘的SN号信息

输 入：	buffer			单盘SN号存放地址
		len				单盘SN号的长度
		
输 出：	OK				设置单盘的SN号正确
		ERROR			设置单盘的SN号错误

描 述：	设置单盘的SN号信息。此函数应在SetBoardCode()前调用，且SN号信息长度不超过100个字符。

作 者：	yuanf
	
修 改：创建

时 间：2012.05.08			
*****************************************************/ 
extern int SetBoardSn(char *buffer,int len);

#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif	/*INC_BMUV2LINE_H*/

/***************************************************************/
/***********************End bmuV2Line.h*************************/
/***************************************************************/


