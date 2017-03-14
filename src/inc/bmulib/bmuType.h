/****************************************************************
* �ļ���  ��bmuType.h
* ������  ���Լ�־
* �������ڣ�20150101
* �汾��  �� v1.1
* �ļ�������VXworks�������Ͷ���
* ��Ȩ˵����Copyright (c) 2000-2020   ���ͨ�ſƼ��ɷ����޹�˾
* ��    ������
* �޸���־��20150728 by�Լ�־, �޸Ĳ����������ݶ���
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

/*������vxworks����һ��*/
#define TRUE            1
#endif

#ifndef FALSE

/*������vxworks����һ��*/
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

