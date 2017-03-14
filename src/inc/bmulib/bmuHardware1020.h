#ifndef	INC_HARDWARE1020_H
#define	INC_HARDWARE1020_H

#ifdef __cplusplus
extern "C"{
#endif	/*__cplusplus*/
typedef void (*IRQFUNCPTR)(void *);

/*****************************************************
   函数名：SetInterupt()

   功 能：	设置外部中断

   输 入：	pIRQ	中断向量
                ucModel	中断产生方式
                                1：	下降沿触发中断
                                0：	低电平触发中断
                pFunc	中断处理函数
                arg		中断处理函数的参数

   输 出：	OK:		设置正确
                ERROR:	设置错误

   描 述：

   作 者：zhaojzh

   修 改： 创建

   时 间：	2013.11.05
*****************************************************/
STATUS SetInterupt(int pIRQ, UINT8 ucModel, IRQFUNCPTR pFunc, void *arg);

#ifdef __cplusplus
}
#endif	/*__cplusplus*/
#endif



