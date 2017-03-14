
/****************************************************************
** 文 件 名：bmuV2Alm.h
** 简    叙: bmu公共库告警接口

** 作　  者：yuanf
** 日　  期：2012.3.14
** 修改说明：创建

****************************************************************/
#ifndef	INC_BMUV2ALM_H
#define	INC_BMUV2ALM_H

#ifdef	__cplusplus
extern  "C"{
#endif	/* __cplusplus */


/*****************************************************
函数名：RegAlmCode()

功 能：	注册告警代码。

输 入：	uiAlmCode	告警代码
		uiAlmType	告警类型
		almName		告警名
输 出：	无
返回值：告警代码的索引

描 述：	输入一个告警信息

作 者： yuanf
	
修 改：创建

时 间：2012。05.29			
*****************************************************/ 
extern int RegAlmCode(unsigned int uiAlmCode,unsigned int uiAlmType,char *almName);


/*****************************************************
函数名：SetAlm()

功 能：	设置告警。

输 入：	lineIndex	告警从属的线路索引
		almIndex	告警代码索引
		almState	告警状态
					1：告警发生
					0：告警消失
输 出：	无
返回值：OK

描 述： 设置单盘指定告警的状态	

作 者： yuanf
	
修 改：创建

时 间：2012。05.29			
*****************************************************/ 
extern int SetAlm(unsigned int lineIndex,unsigned int almIndex,unsigned int almState);


/*****************************************************
函数名：RegLineAlmRestrain()

功 能：	关联线路号和告警抑制的关键字。

输 入：	lineIndex	告警从属的线路索引
		keyType		线路下关键字类型
					0：物理端口
					1：OTN业务
					2：LSP层
					3：PW层
					4：VPWS
					5：VPLS
		keyLen		关键字长度
		keyValue	关键字值
					当类型为物理端口时，关键字长度为字符串长度，关键字为物理端口字符串，格式如下：/端口类型/端口号，例如"/0/10" = 端口类型0 端口号10 十进制数据表示端口类型和端口号 。
					当类型为OTN业务时，关键字长度为4, 关键字为 POTS网管配置协议中的OTN交叉配置中的globalid字段.
					当类型为LSP层时，关键字长度为4, 关键字为 POTS网管配置协议中的Tunnel配置中的globalid字段.
					当类型为PW层时，关键字长度为8, 关键字为VC id(4字节)+Peer IP(4字节).
					当类型为VPWS时，关键字长度为4, 关键字为 POTS网管配置协议中的VPWS+VC配置中的vpwsid字段.
					当类型为VPLS时，关键字长度为4, 关键字为 POTS网管配置协议中的VPLS+VC配置中的vplsid字段.		
输 出：	无			
返回值：OK			关联正确
		ERROR		lineIndex 为0

描 述： 关联线路号和告警抑制的关键字。

作 者： yuanf
	
修 改：创建

时 间：2013.01.8			
*****************************************************/ 
extern int RegLineAlmRestrain(unsigned int lineIndex,unsigned char keyType,unsigned char keyLen,char *keyValue);

/*****************************************************
函数名：RegLineRestrainAlmCode()

功 能：	设置参与线路告警抑制的告警代码。

输 入：	lineIndex	告警从属的线路索引
		almIndex	参与抑制的告警代码索引

输 出：	无

返回值：OK			设置正确
		ERROR		lineIndex为0

描 述：	按代码进行告警屏蔽

作 者： yuanf
	
修 改：创建

时 间：2013.01.08			
*****************************************************/ 
extern int RegLineRestrainAlmCode(unsigned int lineIndex,unsigned int almIndex);


//extern int FromGlobalIdGetLineIndex(int idType,int idLen,char *id,char *lineIndex);

/*****************************************************
函数名：RegGlobalIdToLineIndexFunc()

功 能：	注册通过global id获取线路索引的函数。

输 入：	func		通过global id获取线路索引的函数 


输 出：	无

返回值：OK			注册成功

描 述：	注册通过global id获取线路索引的函数。
		函数func()的原型必须如下：

		int FromGlobalIdGetLineIndex(int idType,int idLen,char *id,int *pLineNum,char *lineIndex);

		其中参数idType为global 	id的类型
								0：物理端口
								1：OTN业务
								2：LSP层
								3：PW层
								4：VPWS
								5：VPLS
						idLen	表示id的长度
						id		存放global id的buffer
						pLineNum	表示线路索引的个数存放地址
						lineIndex 	表示存放线路索引的buffer，最大不超过64个字节

		此函数被公共库调用，用于告警抑制。

作 者： yuanf
	
修 改：创建

时 间：2013.01.08			
*****************************************************/ 
extern int RegGlobalIdToLineIndexFunc(FUNCPTR func);


/*****************************************************
函数名：MaskAlmCode()

功 能：	设置告警代码屏蔽。

输 入：	uiAlmCode		告警代码
		maskState		屏蔽标志	0：不屏蔽
									1：屏蔽

输 出：	无

返回值：OK

描 述：	按代码进行告警屏蔽

作 者： yuanf
	
修 改：创建

时 间：2012.05.29			
*****************************************************/ 
extern int MaskAlmCode(unsigned int uiAlmCode,unsigned int maskState);

/*****************************************************
函数名：MaskLineAlm()

功 能：	设置线路告警屏蔽。

输 入：	lineIndex		线路索引号
		almIndex		告警代码索引号
		maskState		屏蔽标志	0：不屏蔽
									1：屏蔽

输 出：	无

返回值：OK

描 述：	按线路和告警代码进行告警屏蔽

作 者： yuanf
	
修 改：创建

时 间：2012.05.29			
*****************************************************/ 
extern int MaskLineAlm(unsigned int lineIndex,unsigned int almIndex,unsigned int maskState);

/*****************************************************
函数名：showAlmCode()

功 能：	查看注册的告警代码

输 入：	无
		
输 出：	OK			

描 述：	查看注册的告警代码。

作 者：	yuanf
	
修 改：创建

时 间：2012.05.08			
*****************************************************/
extern int showAlmCode(void);


#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif	/*INC_BMUV2ALM_H*/

/***************************************************************/
/************************End bmuV2Alm.h*************************/
/***************************************************************/
