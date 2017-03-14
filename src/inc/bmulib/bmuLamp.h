#ifndef BMU_LAMP_H
#define BMU_LAMP_H
#include "bmuType.h"

#ifdef  __cplusplus
extern  "C" {
#endif  /* __cplusplus */
/*****************************************************
函数名：RegLampOperate()

功 能：	注册控制红绿黄灯函数

输 入：	控制灯函数的地址
		
输 出：	OK：	注册成功
		
描 述：	这个函数通知公共库如何操作红、绿、黄灯。注册
		的函数必须有两个参数，参数必须按下面的方式输入。
		参数1：指明控制的灯类型
				0 表示控制green灯
				1 表示控制red灯
				2 表示控制yellow灯
		参数2：	操做方法	
				0 表示灯灭
				1 表示灯亮
				2 表示灯反转(亮变为灭，灭变为亮)		
		
		
		只有单盘程序和EMU盘程序合并时才需要这个函数。

		例：
			int ControlLamp(int lampType ,int onoff)
			{
				if(	lampType == 0)		//green
				{
					if(onoff == 0)		//off
					{
						//do it in there
					}
					else if(onoff == 1)	//on
					{
						//do it in there
					}
					else				//reverse
					{
						//do it in there
					}
				}
				else if(lampType == 1)	//red
				{
					if(onoff == 0)		//off
					{
						//do it in there
					}
					else if(onoff == 1)	//on
					{
						//do it in there
					}
					else				//reverse
					{
						//do it in there
					}
				}
				else					//yellow
				{
					if(onoff == 0)		//off
					{
						//do it in there
					}
					else if(onoff == 1)	//on
					{
						//do it in there
					}
					else				//reverse
					{
						//do it in there
					}
				}
			}
			RegLampOperate((VOIDFUNCPTR)ControlLamp);			

作 者：	yuanf			
修 改： 创建
时 间： 2007.4.2	
*****************************************************/
STATUS 	RegLampOperate(FUNCPTR pfunc);

/*****************************************************
   函数名：CtrLamp()

   功 能：	控制红、绿、黄灯，每一种灯都可选择是由公共库控制，
                还是用户控制以及是亮还是灭

   输 入：	ucLamp,		被控制的灯0:绿 1:红 2:黄
                ucModel,	0:公共库控制 1:用户控制
                ucOnOFF		1:亮 0:灭 2:闪烁
                unsigned int hold_time 保持时间

   输 出：	OK:		参数合法
                ERROR:	输入的参数非法

   描 述：	当绿灯的控制由用户变为公共库时，绿灯的初始状态为
                亮。

   作 者：	yuanf

   修 改：

   时 间：
*****************************************************/
STATUS CtrlLamp(unsigned char ucLamp, unsigned char ucModel, unsigned char ucOnOFF, unsigned int hold_time);

/*****************************************************************************
 * 函 数 名  : set_lamp_flash_interval
 * 负 责 人  : zhaojzh
 * 创建日期  : 2015年5月27日
 * 函数功能  : 设置闪烁状态变换时间间隔
 * 输入参数  : int interval  每次闪烁亮到灭或者灭到亮时间间隔，单位：微秒
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
int set_lamp_flash_interval(int interval);

/*****************************************************************************
 * 函 数 名  : get_lamp_flash_interval
 * 负 责 人  : zhaojzh
 * 创建日期  : 2015年5月27日
 * 函数功能  : 获取闪烁状态变化时间间隔，单位:微秒
 * 输入参数  : 无
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
int get_lamp_flash_interval();

#ifdef  __cplusplus
}
#endif  /* __cplusplus */

#endif

