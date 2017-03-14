/***********************************************************************************

 * 文 件 名   : bfd_common.h
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年10月12日
 * 版 本 号   : 
 * 文件描述   : bfd.h 的头文件
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#ifndef __BFD_COMMON_H__
#define __BFD_COMMON_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */

/* BFD模块错误码 */
typedef enum result_bfdcfg
{
    CFG_OK = 0,             /* 增加或删除条目操作成功 */
    PARAM_ERROR,            /* 参数错误 */
    KEY_NOT_EQUAL_MYID,     /* key值错误，与本地描述符不相等 */
    KEY_NOT_EXIST,          /* KEY值不存在 */
    SET_DRIVE_ERROR,        /* 写驱动失败 */
    ALLOC_ERROR,            /* 申请内存空间时失败 */
    ADD_KEY_EXIST,          /* 该key已存在 */
    CFG_FULL,               /* 配置已满 */
    FUC_NULL,               /* 回调函数未注册 */
    INSERT_ERR,             /* 配置树中增加节点失败 */
    FORCED_END,             /* 强制终结，一般调试用，不执行函数实现，直接返回 */
    FRAME_TYPE_ERR,         /* 发帧类型错误或不支持 */
    SET_ARAD,               /* 写ARAD错误 */
    FPGA_STORT_NULL,        /* 未分配存储FPGA的数据空间 */
    KEY_NOT_MATCH,          /* KEY值不匹配 */
    FPGA_MYID_TREE,         /* 操作FPGA使用的二叉树失败 */
    IP_TYPE_ERR,            /* IP类型错误 */
    FUNC_RET_ERR,           /* 调用其他接口返回错误 */
    LIST_NULL,              /* 链表为空 */
    CFG_RESULT_MAX
}RESULT_BFDCFG;

extern const char * const result_str[];
extern const char * const g_bfd_state_str[];
extern const char * const g_bfd_interval_str[];
extern const char * const g_bfd_action_str[];


/* 获取宏名的字符串 */
#define GET_MACRO_NAME(macro)   ""#macro

/*****************************************************************************/
/* Find the offset of specified field within specified structure             */
/*****************************************************************************/
#define NBB_OFFSETOF(STRUCT, FIELD)                                           \
            (NBB_BUF_SIZE)((NBB_BYTE *)(&((STRUCT *)0)->FIELD) - (NBB_BYTE *)0)

#define BFD_SET_STRUCT_FIELD(STRUCT, FIELD, struct_addr, data_addr, data_length)                    \
    do                                                                                              \
    {                                                                                               \
        BFD_SET_STRUCT_MEMBER((STRUCT), NBB_OFFSETOF((STRUCT), (FIELD)), data_addr, data_length);  \
    }while(0);

#define BFD_SET_STRUCT_MEMBER(STRUCT, struct_addr, member_offset, data_addr, data_length)                             \
    do                                                                                                                \
    {                                                                                                                 \
        if((member_offset) + (data_length) < sizeof(STRUCT))                                                          \
        {                                                                                                             \
            OS_MEMCPY((size_t)(struct_addr) + (size_t)(member_offset), (data_addr), (data_length)); \
        }                                                                                                             \
    }while(0);


#define size_t                    unsigned int

/*****************************************************************************/
/* These are necessary in addition to the NBB_MEMSET                         */
/*****************************************************************************/
#define OS_MEMSET(MEM, VALUE, LENGTH) \
                               memset((char *)(MEM), (VALUE), (size_t)(LENGTH))
#define OS_MEMCMP(MEM1, MEM2, LENGTH) memcmp((MEM1), (MEM2), (size_t)(LENGTH))
#define OS_MEMCHR(MEM1, VALUE, LENGTH)memchr((MEM1), (VALUE), (size_t)(LENGTH))
#define OS_MEMMOVE(DEST, SRC, LENGTH) memmove((DEST), (SRC), (size_t)(LENGTH))
#define OS_MEMCPY(DEST, SRC, LENGTH)  \
                  memcpy((char *)(DEST), (const char *)(SRC), (size_t)(LENGTH))

#if defined(BFD_BIG_ENDIAN)

/* 主机序转网络序 */ 
#define BFD_HTONL(addr)    ((unsigned long) (addr))

/* 网络序转主机序 */
#define BFD_NTOHL(addr)    ((unsigned long) (addr))

/* 主机序转网络序 */
#define BFD_HTONS(addr)    ((unsigned short) (addr))

/* 网络序转主机序 */
#define BFD_NTOHS(addr)    ((unsigned short) (addr))

#define BITFIELDS2(A,B)      A; B
#define BITFIELDS3(A,B,C)    A; B; C
#define BITFIELDS4(A,B,C,D)  A; B; C; D
#define BITFIELDS5(A,B,C,D,E)  A; B; C; D; E
#define BITFIELDS6(A,B,C,D,E,F)  A; B; C; D; E; F
#define BITFIELDS7(A,B,C,D,E,F,G)  A; B; C; D; E; F; G
#define BITFIELDS8(A,B,C,D,E,F,G,H)  A; B; C; D; E; F; G;H
#define BITFIELDS9(A,B,C,D,E,F,G,H,I)  A; B; C; D; E; F; G; H; I
#define BITFIELDS10(A,B,C,D,E,F,G,H,I,J)  A; B; C; D; E; F; G; H; I; J
#define BITFIELDS11(A,B,C,D,E,F,G,H,I,J,K)  A; B; C; D; E; F; G; H; I; J; K
#define BITFIELDS12(A,B,C,D,E,F,G,H,I,J,K,L)  A; B; C; D; E; F; G; H; I; J; K; L

#elif defined(BFD_LITTLE_ENDIAN)

/* 主机序转网络序 */
#define BFD_HTONL(addr) \
        ( \
            (((unsigned long) (addr) & 0x000000FF) << 24) | \
                (((unsigned long) (addr) & 0x0000FF00) << 8) | \
                    (((unsigned long) (addr) & 0x00FF0000) >> 8) | \
                        (((unsigned long) (addr) & 0xFF000000) >> 24) \
        )

/* 网络序转主机序 */
#define BFD_NTOHL(addr) BFD_HTONL(addr)

/* 主机序转网络序 */
#define BFD_HTONS(addr) \
        ( \
            (((unsigned short) (addr) & 0x00FF) << 8) | \
                (((unsigned short) (addr) & 0xFF00) >> 8) \
        )

/* 网络序转主机序 */
#define BFD_NTOHS(addr) BFD_HTONS(addr)

#define BITFIELDS2(A,B)      B; A
#define BITFIELDS3(A,B,C)    C; B; A
#define BITFIELDS4(A,B,C,D)  D; C; B; A
#define BITFIELDS5(A,B,C,D,E)  E; D; C; B; A
#define BITFIELDS6(A,B,C,D,E,F)  F; E; D; C; B; A
#define BITFIELDS7(A,B,C,D,E,F,G)  G; F; E; D; C; B; A
#define BITFIELDS8(A,B,C,D,E,F,G,H)  H; G; F; E; D; C; B; A
#define BITFIELDS9(A,B,C,D,E,F,G,H,I)  I; H; G; F; E; D; C; B; A
#define BITFIELDS10(A,B,C,D,E,F,G,H,I,J)  J; I; H; G; F; E; D; C; B; A
#define BITFIELDS11(A,B,C,D,E,F,G,H,I,J,K)  K; J; I; H; G; F; E; D; C; B; A
#define BITFIELDS12(A,B,C,D,E,F,G,H,I,J,K,L)  L; K; J; I; H; G; F; E; D; C; B; A

#else
    #error DEFINED BFD_BIG_ENDIAN OR BFD_LITTLE_ENDIAN
#endif

/* 从盘间通信数据的BUF中获取N字节 */
#define BFD_GET_BUF(val_point, point, len, residual_length)         \
        do                                                          \
        {                                                           \
            if((residual_length) >= (len))                          \
            {                                                       \
                if((NULL != (val_point)) && (NULL != (point)))     \
                {                                                   \
                    OS_MEMCPY((val_point), (point), (len));         \
                    (point) = (point) + (len);                      \
                    (residual_length) = (residual_length) - (len);  \
                }                                                   \
            }                                                       \
        }while(0)

/* 从盘间通信数据的BUF中获取4字节 */
#define BFD_GET_ULONG(val, point, residual_length)                  \
        do                                                          \
        {                                                           \
            if((residual_length) >= 4)                              \
            {                                                       \
                (val) = BFD_NTOHL(*((unsigned long *)(point)));    \
                (point) = (point) + 4;                              \
                (residual_length) = (residual_length) - 4;          \
            }                                                       \
        }while(0)
        
/* 从盘间通信数据的BUF中获取2字节 */
#define BFD_GET_USHORT(val, point, residual_length)                 \
        do                                                          \
        {                                                           \
            if((residual_length) >= 2)                              \
            {                                                       \
                (val) = BFD_NTOHS(*((unsigned short *)(point)));   \
                (point) = (point) + 2;                              \
                (residual_length) = (residual_length) - 1;          \
            }                                                       \
        }while(0)

/* 从盘间通信数据的BUF中获取1字节 */
#define BFD_GET_UCHAR(val, point, residual_length)          \
        do                                                  \
        {                                                   \
            if((residual_length) >= 2)                      \
            {                                               \
                (val) = *((unsigned char *)(point));        \
                (point)++;                                  \
                (residual_length)--;                        \
            }                                               \
        }while(0)

/* 忽略N字节 */
#define BFD_IGNORE_BYTES(num, point, residual_length)           \
        do                                                      \
        {                                                       \
            if((residual_length) >= (num))                      \
            {                                                   \
                (point) = (point) + (num);                      \
                (residual_length) = (residual_length) - (num);  \
            }                                                   \
        }while(0)

#ifdef linux
#define BFD_COLOR_RED       "\33[1;31;40m"             /* 加粗，红色字体，黑色底纹 */
#define BFD_COLOR_MAGENTA   "\33[1;35;40m"             /* 加粗，洋红色字体，黑色底纹 */
#define BFD_COLOR_YELLOW    "\33[4;33;40m"             /* 下划线，黄色字体，黑色底纹 */
#define BFD_COLOR_CYAN      "\33[0;36;40m"             /* 无特效，蓝色字体，黑色底纹 */
#define BFD_COLOR_GREEN     "\033[0;32;40m"            /* 无特效，绿色字体，黑色底纹 */
#define BFD_COLOR_NORMAL    "\033[0;0;0m"              /* 无特效，默认颜色 */
#else   /* windows printf无颜色控制 */
#define BFD_COLOR_RED       ""
#define BFD_COLOR_MAGENTA   ""
#define BFD_COLOR_YELLOW    ""
#define BFD_COLOR_CYAN      ""
#define BFD_COLOR_GREEN     ""
#define BFD_COLOR_NORMAL    ""
#endif

#define BFD_LOG_DIR         "log/bfd.log"             /* BFD log日志 */
#define BFD_SHELL_DEBUG     (-100)                     /* 仅在shell上打印 */
#define BFD_SHELL_CRIT      (BFD_SHELL_DEBUG - 1)      /* 在shell上打印critical级别 */
#define BFD_SHELL_ERR       (BFD_SHELL_DEBUG - 2)      /* 在shell上打印error级别 */
#define BFD_SHELL_WARNING   (BFD_SHELL_DEBUG - 3)      /* 在shell上打印warning级别 */
#define BFD_SHELL_NOTICE    (BFD_SHELL_DEBUG - 4)      /* 在shell上打印normal but significant级别 */
#define BFD_SHELL_INFO      (BFD_SHELL_DEBUG - 5)      /* 在shell上打印informational级别 */

/* BFD日志 */
#define BFD_LOG(level, fmt, args...)                                        \
        do                                                                  \
        {                                                                   \
            switch (level)                                                  \
            {                                                               \
                case BFD_SHELL_CRIT:                                        \
                    printf(BFD_COLOR_RED fmt BFD_COLOR_NORMAL, ##args);     \
                    break;                                                  \
                case BFD_SHELL_ERR:                                         \
                    printf(BFD_COLOR_MAGENTA fmt BFD_COLOR_NORMAL, ##args); \
                    break;                                                  \
                case BFD_SHELL_WARNING:                                     \
                    printf(BFD_COLOR_YELLOW fmt BFD_COLOR_NORMAL, ##args);  \
                    break;                                                  \
                case BFD_SHELL_NOTICE:                                      \
                    printf(BFD_COLOR_CYAN fmt BFD_COLOR_NORMAL, ##args);    \
                    break;                                                  \
                case BFD_SHELL_INFO:                                        \
                    printf(BFD_COLOR_GREEN fmt BFD_COLOR_NORMAL, ##args);   \
                    break;                                                  \
                case BFD_SHELL_DEBUG:                                       \
                    printf(fmt, ##args);                                    \
                    break;                                                  \
                default:                                                    \
                    BMU_LOG(level, BFD_LOG_DIR, fmt, ##args);               \
            }                                                               \
        }                                                                   \
        while(0)

/* 检查指针参数，配合do{}while(0);使用，LOG建议使用ERR级别 */
#define BFD_CHECK_PARAM_POINT(log_level, point_param, ret)                  \
    if (NULL == (point_param))                                              \
    {                                                                       \
        BFD_LOG((log_level), #point_param" is NULL\n");                   \
        (ret) = PARAM_ERROR;                                                \
        break;                                                              \
    }

/* 检查参数的最大值(闭区间)，配合do{}while(0);使用，LOG建议使用ERR级别 */
#define BFD_CHECK_PARAM_MAX(log_level, param, max, param_format, max_format, ret)               \
    if ((param) > (max))                                                                        \
    {                                                                                           \
        BFD_LOG((log_level),#param":"param_format" > max:"max_format"\n", (param), (max));    \
        (ret) = PARAM_ERROR;                                                                    \
        break;                                                                                  \
    }

/* 检查参数的最大值(开区间)，配合do{}while(0);使用，LOG建议使用ERR级别 */
#define BFD_CHECK_PARAM_OPEN_MAX(log_level, param, max, param_format, max_format, ret)          \
    if ((param) >= (max))                                                                       \
    {                                                                                           \
        BFD_LOG((log_level), #param":"param_format" >= max:"max_format"\n", (param), (max));  \
        (ret) = PARAM_ERROR;                                                                    \
        break;                                                                                  \
    }

/* 检查参数的最小值(闭区间)，配合do{}while(0);使用，LOG建议使用ERR级别 */
#define BFD_CHECK_PARAM_MIN(log_level, param, min, param_format, min_format, ret)               \
    if ((param) < (min))                                                                        \
    {                                                                                           \
        BFD_LOG((log_level), #param":"param_format" < min:"min_format"\n", (param), (min));   \
        (ret) = PARAM_ERROR;                                                                    \
        break;                                                                                  \
    }

/* 检查参数的最小值(开区间)，配合do{}while(0);使用，LOG建议使用ERR级别 */
#define BFD_CHECK_PARAM_OPEN_MIN(log_level, param, min, param_format, min_format, ret)          \
    if ((param) <= (min))                                                                       \
    {                                                                                           \
        BFD_LOG((log_level), #param":"param_format" <= min:"min_format"\n", (param), (min));  \
        (ret) = PARAM_ERROR;                                                                    \
        break;                                                                                  \
    }


/* 检查返回值是BFD错误码RESULT_BFDCFG的函数执行结果(不成功退出)，配合do{}while(0);使用，LOG建议使用WARNING级别 */
#define BFD_CHECK_FUNC_RETURN_BREAK(log_level, func_name, ret)                  \
    if(CFG_OK != (ret))                                                         \
    {                                                                           \
        BFD_LOG((log_level), #func_name" return %s\n", result_str[(ret)]);    \
        break;                                                                  \
    }

/* 检查返回值是BFD错误码RESULT_BFDCFG的函数执行结果(不成功不退出)，LOG建议使用NOTICE级别 */
#define BFD_CHECK_FUNC_RETURN_NO_BREAK(log_level, func_name, ret)               \
    if(CFG_OK != (ret))                                                         \
    {                                                                           \
        BFD_LOG((log_level), #func_name" return %s\n", result_str[(ret)]);    \
        (ret) = CFG_OK;                                                         \
    }

/* 检查外部函数执行结果(不成功退出)，配合do{}while(0);使用，LOG建议使用WARNING级别 */
#define BFD_CHECK_EXTERN_FUNC_RETURN_BREAK(log_level, func_name, func_ret, func_ret_format, ret)    \
    if(CFG_OK != (func_ret))                                                                        \
    {                                                                                               \
        BFD_LOG((log_level), #func_name" return:"func_ret_format"\n", (func_ret));                \
        (ret) = FUNC_RET_ERR;                                                                       \
        break;                                                                                      \
    }

/* 检查外部函数执行结果(不成功不退出)，LOG建议使用NOTICE级别 */
#define BFD_CHECK_EXTERN_FUNC_RETURN_NO_BREAK(log_level, func_name, func_ret, func_ret_format)      \
    if(CFG_OK != (func_ret))                                                                        \
    {                                                                                               \
        BFD_LOG((log_level), #func_name" return:"func_ret_format"\n", (func_ret));                \
    }

/* 检查返回值为NULL的函数执行结果(不成功退出)，配合do{}while(0);使用，LOG建议使用WARNING级别 */
#define BFD_CHECK_NULL_FUNC_BREAK(log_level, func_name, func_ret, ret)          \
    if(NULL == (func_ret))                                                      \
    {                                                                           \
        BFD_LOG((log_level), #func_name" return null\n");                     \
        (ret) = FUNC_RET_ERR;                                                   \
        break;                                                                  \
    }

/* 检查返回值为NULL的函数执行结果(不成功不退出)，LOG建议使用NOTICE级别 */
#define BFD_CHECK_NULL_FUNC_NO_BREAK(log_level, func_name, func_ret)            \
    if(NULL == (func_ret))                                                      \
    {                                                                           \
        BFD_LOG((log_level), #func_name" return null\n");                     \
    }

/* 检查BFD错误码RESULT_BFDCFG是否成功，配合do{}while(0) */
#define BFD_CHECK_RETURN(ret)   \
    if(CFG_OK != ret)           \
    {                           \
        break;                  \
    }

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BFD_COMMON_H__ */

