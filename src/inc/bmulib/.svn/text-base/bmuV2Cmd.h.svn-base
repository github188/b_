
/****************************************************************
** 文 件 名：bmuV2cmd.h
** 简    叙: bmu与其它单盘通信的接口头文件

** 作　  者：yuanf
** 日　  期：2012.3.14
** 修改说明：创建

****************************************************************/
#ifndef	INC_BMUV2CMD_H
#define	INC_BMUV2CMD_H

/*typedef int 		(*FUNCPTR) ();*/

#ifdef	__cplusplus
extern  "C"{
#endif	/* __cplusplus */

/********************************************/
/*          用户处理命令数据结构            */
/********************************************/
struct USR_CMD_STRUCT
{
	unsigned int	uiSourceAddr;	/*命令的来源*/
	unsigned int	uiCmdCode;		/*命令代码
							  bit31-bit24 0 表示由公共库填充盘特征1－－数据长度字节
							  			  1 表示由单盘程序填充盘特征1－－数据长度字节。
							  			    此时从发送帧中的盘特征1字节开始依次填入buffer
							  			    内的数据；iParaLen表示buffer内数据的个数；
							  			    ucCharacter字节无效。
							  			   other 备用
							  bit23-bit0  命令代码(命令类型 命令代码 命令附加)
	
							*/
	unsigned char	ucCharacter;	/*命令的特征字节*/
	int				iParaLen;		/*命令参数长度返回参数个数小于0则不发送*/	
	unsigned char *	buffer;			/*参数存放地址*/
};
extern struct USR_CMD_STRUCT g_stuCmd;

/*****************************************************
函数名：RegUsrCmd()
RegUsrCmd(){}

功 能：	注册用户处理网管命令的函数

输 入：	pUsrCmdFunc		用户处理命令的函数地址
	
输 出：	OK：	注册成功
		ERROR:	注册失败，公共库没有取到用户处理命令的
				函数的地址
		原因：	pUsrCmdFunc为空指针。

描 述：	公共库通过这个函数获取用户处理命令的函数地址，
		当判断接收到的命令不是公共命令时，通过这个地
		址调用用户处理命令的函数来处理命令。这个注册
		函数只应被调用一次，如果多次调用，只有最后一
		次调用是有效的。

		例：
			int UsrCmd(void);
			RegUsrCmd((FUNCPTR)UsrCmd);

作 者：	yuanf	
修 改： 创建
时 间： 2012.3.14	
*****************************************************/
extern int RegUsrCmd
(
	FUNCPTR pUsrCmdFunc	/*用户处理命令的函数地址*/
);

/*****************************************************************************
* 函 数 名      : RegBmuUserCmd
* 负 责 人      : 交叉配置初始化
* 创建日期  : 2013年3月21日星期四
* 函数功能  : 根据命令码注册用户回调函数
* 输入参数  : unsigned int uiCmdCode  
*                           FUNCPTR func            
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  : 
* 其 他            :
*****************************************************************************/
extern int RegBmuUserCmd
(	
	unsigned int uiCmdCode, 
	FUNCPTR func
);


/*****************************************************
函数名：SendData()
SendData(){}
功 能：	通过发送任务发送数据包

输 入：	uiDstAddr	数据的目的地址
		uiDstType	数据的接收端类型
					0		NMU
					1		ACU
					2		BMU
					other	备用
		uiCmdCode	数据的命令字(命令类型,命令码,命令附加)
		uiDataLen	发送的数据长度
		buffer		发送数据的地址
		
输 出：	n:		发送到发送队列的有效数据个数
		ERROR:	没有申请到内存空间
				错误的接收端类型
				buffer为空指针

描 述：	这个函数将数据组织成数据帧，发送到发送队列中。接收端类
		型为BMU时，盘地址字节固定填0XFF，为其他类型时盘地址字节
		为本盘盘号。
		使用EMU-BCT协议的库没有这个函数。

		例：发送100个字节(命令码为01 44 00)给ACU。
			SendData(GetAcuIpAddr(),1,0x014400,100,buffer);
							
作 者：	yuanf	
修 改： 创建
时 间： 2012.3.14			
*****************************************************/
extern int SendData
(
	unsigned int	uiDstAddr,	/*数据的目的地址*/
	unsigned int	uiDstType,	/*数据接收端类型
						0		NMU
						1		ACU
						2		BMU
						other	备用
						*/
	unsigned int	uiCmdCode,	/*数据的命令字(命令类型,命令码,命令附加)*/
	unsigned int	uiDataLen,	/*发送的数据长度*/
	char			*buffer		/*发送数据的地址*/
);


#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif	/*INC_BMUV2CMD_H*/

/***************************************************************/
/************************End bmuV2cmd.h*************************/
/***************************************************************/

