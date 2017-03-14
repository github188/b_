/***********************************************************************************

 * 文 件 名   : nbbxtype.h
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年10月19日
 * 版 本 号   : 
 * 文件描述   : External N-BASE types
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#ifndef NBBXTYPE_INCLUDED
#define NBBXTYPE_INCLUDED

/**INC+***********************************************************************/
/* Header:    nbbxtype.h                                                     */
/*                                                                           */
/* Purpose:   External N-BASE types                                          */
/*                                                                           */
/* (C) COPYRIGHT METASWITCH NETWORKS 1996 - 2011                             */
/*                                                                           */
/* $Revision:: 5008                 $ $Date:: 2011-03-30 17:31:47 +0100 (#$  */
/**INC-***********************************************************************/

#if     !defined(NULL)
#define NULL            0
#endif

#define IN
#define OUT
#define INOUT

/*****************************************************************************/
/*****************************************************************************/
/* Common Types                                                              */
/*****************************************************************************/
/*****************************************************************************/
typedef unsigned char    NBB_BYTE;     /* 8 bits                             */
typedef          char    NBB_CHAR;     /*                                    */
typedef          short   NBB_SHORT;    /* 2 byte signed integer              */
typedef unsigned short   NBB_USHORT;   /* 2 byte unsigned integer            */
typedef          long    NBB_LONG;     /* 4 byte signed integer              */
typedef unsigned long    NBB_ULONG;    /* 4 byte unsigned integer            */
typedef          int     NBB_INT;      /* >= 2 byte signed integer (machine word) */
typedef unsigned int     NBB_UINT;     /* >= 2 byte unsigned integer (machine word) */
typedef          int     NBB_BOOL;     /* boolean                            */
typedef          void    NBB_VOID;     /* void if supported, char otherwise  */
#define NBB_CONST const

/*****************************************************************************/
/* See OS specific header file for NBB_COUNTER                               */
/*****************************************************************************/

/*****************************************************************************/
/*****************************************************************************/
/* Derived types                                                             */
/*****************************************************************************/
/*****************************************************************************/
typedef NBB_ULONG   NBB_BUF_SIZE;           /* size of memory, buffers etc.  */
typedef NBB_ULONG   NBB_QUEUE_ID;           /* queue identifier              */
typedef NBB_ULONG   NBB_HANDLE;
typedef NBB_HANDLE  NBB_PROC_ID;            /* process identifier            */
typedef NBB_VOID *  NBB_LOCK_ID;
typedef NBB_LOCK_ID NBB_LOCK_DATA;
typedef NBB_LONG    NBB_PROC_TYPE;          /* process type                  */
typedef NBB_BYTE    NBB_PROC_PRIORITY;      /* process priority              */

/*****************************************************************************/
/* The NBB_CORRELATOR type is guaranteed to be large enough to store a       */
/* pointer, a HANDLE, a LOCK_ID, a QUEUE_ID, a PROC_ID or a ULONG and should */
/* be defined as the largest of these.  NBB_CORRELATORs should only be       */
/* accessed using the NBB_CORR_PUT_VALUE and NBB_CORR_GET_VALUE macros.      */
/*****************************************************************************/
typedef NBB_VOID *  NBB_CORRELATOR;         /* general correlator type       */

/*****************************************************************************/
/* NBB_PTR_INT is an integer type that is the same size as a pointer.  This  */
/* is equivalent to the intptr_t type, introduced in C99.                    */
/*****************************************************************************/
#ifdef NBB_64_BIT_POINTERS
#define NBB_PTR_INT NBB_UINT64
#else
#define NBB_PTR_INT NBB_ULONG
#endif

/*****************************************************************************/
/* Void parameter for functions                                              */
/*****************************************************************************/
#define NBB_VOID_PARMS  NBB_VOID

/*****************************************************************************/
/* Defined only to give a shorter variable name to access                    */
/* nbb_thread_global_data.  All fields in nbb_thread_global_data should be   */
/* accessed using 'TGD->' in the code.                                       */
/*****************************************************************************/
#define TGD         ((NBB_THREAD_GLOBAL_DATA *)nbb_thread_global_data)

/*****************************************************************************/
/* Process Context.  "LOCAL" is also #defined in VxWorks headers as a        */
/* synonym for "static".  Undefine LOCAL first to avoid a compiler error     */
/*****************************************************************************/
#ifdef LOCAL
#undef LOCAL                                           /* undefine OS SYMBOL */
#endif
#define LOCAL (*(LOCAL_DATA_TYPE *)(TGD->nbb_local_tgd))
#define SHARED (*(SHARED_DATA_TYPE *)(TGD->nbb_shared_local_tgd))

/*****************************************************************************/
/* MP context macros                                                         */
/*****************************************************************************/
#ifdef NBB_CONTEXT
#define NBB_CXT_T   NBB_VOID *
#define NBB_CCXT_T  , NBB_VOID *
#define NBB_CXT     nbb_thread_global_data
#define NBB_CCXT    , nbb_thread_global_data
#else
#define NBB_CXT_T   NBB_VOID_PARMS
#define NBB_CCXT_T
#define NBB_CXT
#define NBB_CCXT
#endif



/*****************************************************************************/
/* Stubs-only callback procedure type.                                       */
/*****************************************************************************/
typedef NBB_VOID(NBS_CLEANUP_PROC) (NBB_CXT_T);

/*****************************************************************************/
/* Trace filter                                                              */
/*****************************************************************************/
typedef char NBB_TRACE_FILTER[9];

#define NBB_MAX_LEN_FUNC_NAME 31
typedef char NBB_TRACE_FILTER_FUNC[NBB_MAX_LEN_FUNC_NAME + 1];

#endif

