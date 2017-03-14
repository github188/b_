/******************************************************************************
*  文 件 名    : bmuOsComm.h
*  负 责 人    : qhxiong
*  创建日期 : 2013年6月25日星期二
*  版 本 号    : V1.0
*  文件描述 : bmulib os通用接口头文件
*  版权说明 : Copyright (c) 2000-2020   烽火通信科技股份有限公司
*  其    他	        : 无
*  修改日志 :
******************************************************************************/
#ifndef __BMUOSCOMM_H__
#define __BMUOSCOMM_H__
#ifdef __cplusplus
extern "C" {
#endif  /*__cplusplus*/

/*************** bmulib打印颜色宏定义 ***************/
#define BMU_COLOR_RED           "\33[01;31m"
#define BMU_COLOR_MAGENTA   "\33[35m"
#define BMU_COLOR_BLUE          "\33[34m"
#define BMU_COLOR_GREEN         "\033[0;40;32m"
#define BMU_COLOR_NORMAL        "\033[0m"

/*************** bmulib日志存储宏定义***************/
#define BMU_PRINT_MSG_BUF_SIZE            512
#define BMU_LOG_MSG_BUF_SIZE              (50 * 1024)
#define BMU_LOG_MSG_FILE_SIZE             (10 * 1024 * 1024)
#define BMU_LOG_MSG_BUF_NUM                             10

/*************** bmulib信息打印级别***************/
#define BMU_CRIT                1       /* critical conditions			*/
#define BMU_ERR                         2       /* error conditions			*/
#define BMU_WARNING                     3       /* warning conditions			*/
#define BMU_NOTICE                      4       /* normal but significant condition	*/
#define BMU_INFO                5       /* informational			*/
#define BMU_DEBUG               6       /* debug-level messages			*/

/*************** bmulib数据类型强制转换宏定义***************/
#define RW32            *(volatile unsigned int *)
#define RW16            *(volatile unsigned short *)
#define RW8             *(volatile unsigned char *)

/*信息打印级别控制全局变量*/
extern unsigned char g_ucPrintMsgLevel;

/*信息打印颜色控制全局变量*/
extern unsigned char g_ucPrintMsgColor;

/*模块类型描述全局变量*/
extern char *g_pThisModule;

/*****************************************************************************
* 函 数 名      : MalloZero
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 动态分配内存并清零
* 输入参数  : int size
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern char *MalloZero(int size);

/*****************************************************************************
* 函 数 名      : BmuMalloc
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 动态分配内存
* 输入参数  : int size
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern void *BmuMalloc(int size);

/*****************************************************************************
* 函 数 名      : BmuFree
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 释放内存
* 输入参数  : char * *buffer
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern void BmuFree(char * *buffer);

/*****************************************************************************
* 函 数 名      : BmuPrintf
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib打印接口
* 输入参数  : const char *module
*                           const char *fun
*                           const int line
*                           int iLevel
*                           const char *fmt
*                           ...
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern void BmuPrintf(const char *module, const char *fun, const int line, int iLevel, const char *fmt, ...);

/*****************************************************************************
* 函 数 名      : BmuTimePrintf
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib打印接口，带时间戳
* 输入参数  : const char *module
*                           const char *fun
*                           const int line
*                           int iLevel
*                           const char *fmt
*                           ...
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern void BmuTimePrintf(const char *module, const char *fun, const int line, int iLevel, const char *fmt, ...);

/*****************************************************************************
* 函 数 名      : BmuLog
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib日志存储接口
* 输入参数  : const char *file
*                           const char *fun
*                           const int line
*                           int level
*                           const char *logfile
*                           const char *fmt
*                           ...
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuLog(const char *file,
    const char *fun,
    const int line,
    int level,
    const char *logfile,
    const char *fmt,
    ...);

/*****************************************************************************
* 函 数 名      : BmuGetDirFileName
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 将目录名与文件名合并成完整绝对路径名
* 输入参数  : unsigned char *dirAndName
*                           unsigned char *string
*                           unsigned char *dir
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuGetDirFileName(unsigned char *dirAndName, unsigned char *string, unsigned char *dir);

/*****************************************************************************
* 函 数 名      : BmuGetNakeName
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 通过绝对路径名获取文件名
* 输入参数  : char *nakeName
*                           char *dirAndName
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuGetNakeName(char *nakeName, char *dirAndName);

/*****************************************************************************
* 函 数 名      : BmuGetDirName
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 通过绝对路径名获取目录名
* 输入参数  : char *dirName
*                           char *dirAndName
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuGetDirName(char *dirName, char *dirAndName);

/*****************************************************************************
* 函 数 名      : BmuGetRealName
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 通过转换后文件名获取转换前文件名
* 输入参数  : char *realName
*                           char *nakeName
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuGetRealName(char *realName, char *nakeName);

/*****************************************************************************
* 函 数 名      : BmuGetUntarName
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 获取解包后文件名
* 输入参数  : char *untarName
*                           char *nakeName
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuGetUntarName(char *untarName, char *nakeName);

/*****************************************************************************
* 函 数 名      : BmuGetLocalFileLen
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 获取文件长度
* 输入参数  : char *localName
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuGetLocalFileLen(char *localName);

/*****************************************************************************
* 函 数 名      : BmuReadLocalFile
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 从文件读取指定长度数据至缓冲区
* 输入参数  : char *localName
*                           char *buffer
*                           int len
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuReadLocalFile(char *localName, char *buffer, int len);

/*****************************************************************************
* 函 数 名      : BmuWriteLocalFile
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 将缓冲区数据写入文件
* 输入参数  : char *localName
*                           char *buffer
*                           int len
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuWriteLocalFile(char *localName, char *buffer, int len);

/*****************************************************************************
* 函 数 名      : BmuRead32Buf
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 读数据转换接口，按照大端模式将4字节uchar，转换至uint
* 输入参数  : unsigned char *buffer
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern unsigned int BmuRead32Buf(unsigned char *buffer);

/*****************************************************************************
* 函 数 名      : BmuWrite32Buf
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 写数据转换接口，按照大端模式将uint转换至4字节uchar
* 输入参数  : unsigned char *buffer
*                           unsigned int uiValue
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuWrite32Buf(unsigned char *buffer, unsigned int uiValue);

/*****************************************************************************
* 函 数 名      : BmuRead16Buf
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 读数据转换接口，按照大端模式将2字节uchar，转换至ushort
* 输入参数  : unsigned char *buffer
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern unsigned short BmuRead16Buf(unsigned char *buffer);

/*****************************************************************************
* 函 数 名      : BmuWrite16Buf
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 写数据转换接口，按照大端模式将ushort转换至2字节uchar
* 输入参数  : unsigned char *buffer
*                           unsigned short usValue
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuWrite16Buf(unsigned char *buffer, unsigned short usValue);

/*****************************************************************************
* 函 数 名      : BmuWriteFloatBuf
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 写数据转换接口，按照大端模式将float转换至4字节uchar
* 输入参数  : unsigned char *buffer
*                           float fValue
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuWriteFloatBuf(unsigned char *buffer, float fValue);

/*****************************************************************************
* 函 数 名      : BmuReadFloatBuf
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 读数据转换接口，按照大端模式将4字节uchar，转换至float
* 输入参数  : unsigned char *buffer
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern float BmuReadFloatBuf(unsigned char *buffer);

/*****************************************************************************
* 函 数 名      : BmuRemoveNewLineSign
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 去除字符串末尾"\n"
* 输入参数  : char *pStrBuf
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuRemoveNewLineSign(char *pStrBuf);

/*****************************************************************************
* 函 数 名      : BmuGetFileAbsolutePath
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 获取文件绝对路径名
* 输入参数  : char *pFilePath
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuGetFileAbsolutePath(char *pFilePath);

/*****************************************************************************
* 函 数 名      : BmuRemoveFileDotSign
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : 去除文件后缀名，从'.'起始
* 输入参数  : char *nakeName
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuRemoveFileDotSign(char *nakeName);

/*****************************************************************************
* 函 数 名      : BmuRemoveStrEndingBlank
* 负 责 人      : qhxiong
* 创建日期  : 2013年7月25日星期四
* 函数功能  : 去除字符串末尾的空格字符、制表字符
* 输入参数  : char *pStrBuf
* 输出参数  : 无
* 返 回 值      :
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern int BmuRemoveStrEndingBlank(char *pStrBuf);

/*****************************************************************************
* 函 数 名      : BmuCrcCalc
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib 16位crc效验接口
* 输入参数  : unsigned char *data
*                           int length
*                           unsigned short seed
*                           unsigned short final
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern unsigned short BmuCrcCalc(unsigned char *data, int length, unsigned short seed, unsigned short final);

/*****************************************************************************
* 函 数 名      : BmuZipGetRAMCRC
* 负 责 人      : qhxiong
* 创建日期  : 2013年6月25日星期二
* 函数功能  : bmulib 32位crc效验接口
* 输入参数  : const unsigned char *pvMem
*                           int iLen
* 输出参数  : 无
* 返 回 值      : extern
* 调用关系  :
* 其 他            :
*****************************************************************************/
extern unsigned int BmuZipGetRAMCRC(const unsigned char *pvMem, int iLen);

#ifndef RELEASE
/*************** bmulib打印接口宏定义 ***************/
#define BMU_SPRINTF(level, fmt, args...)         BmuPrintf(NULL, NULL, NULL, level, fmt, ##args)

/*************** bmulib打印接口宏定义 ***************/
#define BMU_PRINTF(level, fmt, args...)         BmuPrintf(g_pThisModule, __FUNCTION__, __LINE__, level, fmt, ##args)

/*************** bmulib打印接口(带时间戳)宏定义 ***************/
#define BMU_TPRINTF(level, fmt, args...)        BmuTimePrintf(g_pThisModule, \
        __FUNCTION__,                                                        \
        __LINE__,                                                            \
        level,                                                               \
        fmt,                                                                 \
        ##args)
/*************** bmulib打印接口(不带模块名、函数名与行号)宏定义 ***************/
#define BMU_SPRINTF(level, fmt, args...)         BmuPrintf(NULL, NULL, NULL, level, fmt, ##args)
#else 
#define BMU_SPRINTF(level, fmt, args...) 
#define BMU_PRINTF(level, fmt, args...)
#define BMU_TPRINTF(level, fmt, args...)   
#define BMU_SPRINTF(level, fmt, args...)
#endif 
/*************** bmulib日志存储宏定义 ***************/
#define BMU_LOG(level, logfile, fmt, args...)   BmuLog(__FILE__, __FUNCTION__, __LINE__, level, logfile, fmt, ##args)

/*************** bmulib日志存储(不带文件名、函数名与行号)宏定义 ***************/
#define BMU_SLOG(level, logfile, fmt, args...)   BmuLog(NULL, NULL, 0, level, logfile, fmt, ##args)


#if 0
/*************** bmulib内存释放宏定义 ***************/
#define BMU_FREE(x)      \
    do                   \
    {                    \
        if ((x) != NULL) \
        {                \
            free((x));   \
            (x) = NULL;  \
        }                \
    }                    \
    while (0)
#endif

/*************** bmulib文件关闭宏定义 ***************/
#define BMU_FCLOSE(x)    \
    do                   \
    {                    \
        if ((x) != NULL) \
        {                \
            fflush((x)); \
            fclose((x)); \
            (x) = NULL;  \
        }                \
    }                    \
    while (0)

/*************** bmulib文件关闭宏定义 ***************/
#define BMU_CLOSE(x)    \
    do                  \
    {                   \
        if ((x) >= 0)   \
        {               \
            close((x)); \
            (x) = -1;   \
        }               \
    }                   \
    while (0)

#ifdef __cplusplus
}
#endif  /*__cplusplus*/

#endif
