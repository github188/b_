
/****************************************************************
** 文 件 名：bmuV2State.h
** 简    叙: bmu公共库中状态数据结构及相关的函数声明

** 作　  者：yuanf
** 日　  期：2012.3.14
** 修	 改：创建

** 版    本：1.0

** 函数列表：	 
****************************************************************/
#ifndef	INC_BMUV2STATE_H
#define	INC_BMUV2STATE_H

#ifdef	__cplusplus
extern  "C"{
#endif	/* __cplusplus */

/*状态分块ID号*/
#define	REVERSE_ID			0x00	/*保留						*/
#define	HARD_INFO_ID		0x01	/*基本硬件信息状态块ID		*/
#define	CONFIG_DOWN_TIME_ID	0x02	/*配置数据下载时间状态块ID	*/
#define	BOARD_NO_ID			0x03	/*盘号状态块ID				*/
#define	PCB_NO_ID			0x04	/*PCB版号状态块ID			*/
#define PCB_TIME_ID			0x05	/*PCB制板时间状态块ID		*/
#define SOFT_VER_ID			0x06	/*软件版本号状态块ID		*/
#define SOFT_BUILD_TIME_ID	0x07	/*软件编译时间状态块ID		*/
#define BOARD_ACTIVE_ID		0x08	/*盘激活状态块ID			*/
#define ASON_BOARD_INFO_ID	0x09	/*ASON*/

/*****************************************************
函数名：RegNewBoardState()
RegNewBoardState(){}
功 能：	向公共库输入状态数据块信息

输 入：	uiID		单盘状态块的ID
		ucLabCode	状态块标识码(网管分配的状态块序号，01固定为配置下载时间块)
		buffer		单盘状态数据存放的地址
		len			单盘状态数据长度
		uiShowType	状态块显示类型
		pName		状态块名称
		ucBackup	备用(填0)
		
输 出：	OK:		成功记录单盘状态数据信息
		ERROR:	输入的参数非法
		原因：	1 buffer为空指针
				2 内存空间不够
				3 状态块标识码小于2

描 述：	公共库通过这个函数获取单盘每个状态数据块数据的
		存放地址，数据长度，状态数据块ID号，显示类型。
		uiID 由网管协议分配，其中0x00为保留号，不能分配给状态块。
		状态块ID号为0x02到0x09时忽略标识码。
			0x0000xxxx 公共类 所有单盘都可以使用的通用属性。
			0x0001xxxx 交叉类 交叉盘使用。
			0x0002xxxx 时钟类 时钟盘使用。
			0x0003xxxx 接口盘 接口盘使用。
			0x8000xxxx 自定义类 任何盘申请协议时必须指明的特殊状态,该类的数据格式不定,网管界面根据事先约定的单盘协议显示数据内容.
			
			以下uiID值表示固定的状态数据块
			0x00保留
			0x01表示硬件信息
			0x02配置下载时间(公共库处理，应用程序不用操作)
			0x03表示盘号
			0x04表示板号
			0x05表示制盘时间
			0x06表示BMU软件版本号
			0x07表示BMU软件生成时间
			0x08表示激活
			0x09表示ASON设备单盘状态基本信息(公共库处理，应用程序不用操作)
			0x0A-0x0f保留
						
		uiShowType表示状态数据在网管界面上的显示方式。
			0x00保留数据类型 网管按16进制显示一遍再按ASICC显示一遍
			0x01表示按2进制数
			0x02表示按16进制数显示
			0x03表示按ASCII显示
			0x04表示显示配置下载时间
			0x05表示显示ASON设备单盘状态基本信息
			other:未定(由网管协议指定)
			
		pName表示网管上显示的状态数据块名，长度必须小于9个字符，可以为NULL。  
		
		例：
		unsigned char CrossData[200];
		RegNewBoardState(0x10003,0x02,crossData,200,0x0,"Cross",0);
		
		注：这个函数和RegBoardState()都可用于注册单盘状态数据，在同一个程序
		中，所有的状态块只能全部用RegNewBoardState()或全部用RegBoardState()
		注册，不能两者混用。
		
		只有使用NMU_BMU通信协议的程序，这个函数才有效，使用EMU_BCT下行通信
		协议的程序必须用RegBoardState()注册状态数据。
		
		相关函数：	ChangeStateBlockValidLen()
					SetStateBlockValidFlag()
					PrintState() 
作 者：	yuanf	
修 改： 创建
时 间： 2012.3.14			
*****************************************************/ 
extern int RegNewBoardState
(
	unsigned int	uiID,		/*状态块ID号*/
	unsigned char 	ucLabCode,	/*状态块标识码*/
	char 			*buffer,	/*状态块数据存放地址*/
	unsigned int 	len,		/*状态块数据最大长度*/
	unsigned int 	uiShowType,	/*状态块数据显示类型*/
	char 			*pName,		/*状态块数据名(ASCII字符)*/
	unsigned char ucBackup		/*备用字节填0*/
);

/*****************************************************
函数名：ChangeStateBlockValidLen()
ChangeStateBlockValidLen(){}
功 能：	这个函数可以动态的修改由RegNewBoardState()注册的状态块数据的有效长度。

输 入：	ucLabCode	指定状态数据块的标识码
		uiValidLen	状态数据块的有效长度
输 出：	OK		修改成功
		ERROR	修改失败
				原因：
				1 不存在这个状态块
				2 有效长度超过最大长度
				3 修改标识码为0x01的状态块

描 述：	修改新格式状态块上报的数据有效长度。没有修改前，状态块的有效数据长度
		为注册的最大数据块长度。
				
		例：
			ChangeStateBlockValidLen(0x02,100);
			
		相关函数：	RegNewBoardState()
					SetStateBlockValidFlag()
					PrintState() 
作 者：	yuanf	
修 改： 创建
时 间： 2012.3.14				
*****************************************************/ 
extern int ChangeStateBlockValidLen
(
	unsigned char ucLabCode,	/*状态块标识码*/
	unsigned int uiValidLen	/*状态块数据的有效长度*/
);

/*****************************************************
函数名：SetStateBlockValidFlag()
SetStateBlockValidFlag(){}
功 能：	修改指定状态块的数据有效长度。

输 入：	ucLabCode	指定状态数据块的标识码
		ucFlag		状态数据块有效标志
					1	状态数据块有效
					0	状态数据块无效
					other 备用
输 出：	OK		修改成功
		ERROR	修改失败
		原因	1 注册的状态块不是新格式的状态块
				2 不存在指定的状态块

描 述：	利用这个函数可以修改新格式状态块是否有效的标志。默认情况下
		新格式状态块的数据是有效，如果希望某个状态块不上报给网管，
		可以利用这个函数将状态块有效标志改为无效，在网管上将不会出
		现这个状态块；也可以将无效的状态块改为有效的，在网管上显示
		这个状态块。
		
		这个函数可以动态的修改由RegNewBoardState()注册的状态块数据
		的有效标志。
		
		例如:
		修改状态块为无效状态块:
		SetStateBlockValidFlag(0x02,0);
		
		修改状态块为有效状态块:
		SetStateBlockValidFlag(0x02,1);
		
		相关函数:	RegNewBoardState()
					ChangeStateBlockValidLen()
					PrintState()
作 者：	yuanf	
修 改： 创建
时 间： 2012.3.14				
*****************************************************/ 
extern int SetStateBlockValidFlag	/*yuanf070116*/
(
	unsigned char ucLabCode,		/*状态块标识码*/
	unsigned char ucFlag			/*状态块数据的有效标志*/
);


/*****************************************************
函数名：PrintState() 
PrintState(){}

功 能：	打印状态链表信息
	
输 入：	无
	
输 出：	无

描 述：	调试时可通过这个函数查看单盘状态数据链表的信息。

		相关函数:	RegBoardState()
					SetAlmPmOffset()
					RegNewBoardState()
					ChangeStateBlockValidLen()
					SetStateBlockValidFlag()
					
作 者：	yuanf	
修 改： 创建
时 间： 2012.3.14	
*****************************************************/
extern void PrintState(void);



#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif	/*INC_BMUV2STATE_H*/

/***************************************************************/
/*************************End bmuV2State.h************************/
/***************************************************************/

