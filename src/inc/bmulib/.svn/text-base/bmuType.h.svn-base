/****************************************************************
* 文件名  ：bmuType.h
* 负责人  ：赵家志
* 创建日期：20150101
* 版本号  ： v1.1
* 文件描述：VXworks数据类型定义
* 版权说明：Copyright (c) 2000-2020   烽火通信科技股份有限公司
* 其    它：无
* 修改日志：20150728 by赵家志, 修改布尔类型数据定义
******************************************************************************/
#ifndef __BMUTYPES_H__
#define __BMUTYPES_H__
#ifndef OK
#define OK      0
#endif

#ifndef ERROR
#define ERROR   -1
#endif

#ifndef TRUE

/*定义与vxworks保持一致*/
#define TRUE            1
#endif

#ifndef FALSE

/*定义与vxworks保持一致*/
#define FALSE   0
#endif

#ifndef FOREVER
#define FOREVER while (1)
#endif

#ifndef STATUS
#define STATUS  int
#endif

#ifndef LOCAL
#define LOCAL   static
#endif

#ifndef FAST
#define FAST
#endif
#ifndef NULL
#define NULL            0
#endif
#ifndef FOREVER
#define FOREVER while (1)
#endif

#if 1
typedef char INT8;
typedef short INT16;
typedef int INT32;
typedef long long INT64;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long long UINT64;
#endif
#ifdef __cplusplus
typedef int (*FUNCPTR)(...);
typedef void (*VOIDFUNCPTR)(...);
#else
typedef int (*FUNCPTR)();
typedef void (*VOIDFUNCPTR)();
#endif

union INT_SHORT
{
	UINT16 	ushort[2];
	UINT32 	uint;
	float	fvalue;
};

#endif

