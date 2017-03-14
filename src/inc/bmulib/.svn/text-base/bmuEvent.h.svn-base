

/****************************************************************
** 文 件 名：bmuEvent.h
** 简    叙: bmu公共库事件处理相关函数

** 作　  者：yuanf
** 日　  期：2010.12.09

** 版    本：1.0

** 函数列表：	SendEvent()		 
****************************************************************/
#ifndef	INC_BMUEVENT_H
#define	INC_BMUEVENT_H

/*#include <vxWorks.h>*/

#ifdef	__cplusplus
extern  "C"{
#endif	/* __cplusplus */

/*****************************************************
函数名：SendEvent()

功  能：上报单盘事件

输  入：eventId		事件ID号
		eventType	事件类型	BIT0:事件是否为紧急事件 （0/1=非紧急/紧急事件）
		eventState	事件状态	1/2	发生/振荡
		dspType		描述类型	0/1 ：buffer中内容ascii字符/16进制网管协商数据 
		showType	显示类型 	0/1： 后台/前台
		buffer		事件内容	事件内容数据
		len			事件内容长度 buffer中有效数据长度
		
输  出：OK

描  述：调用这个函数向网管上报一条事件。对紧急事件需要立即上报，并对所有事件存储，等待网管轮询。

作  者：yuanf
修  改：创建	
时  间：2010.11.2		
*****************************************************/ 
extern int SendEvent(unsigned int eventId,unsigned int eventType,unsigned int eventState,unsigned int dspType,unsigned short showType,char *buffer,int len);


#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif	/*INC_BMUEVENT_H*/

