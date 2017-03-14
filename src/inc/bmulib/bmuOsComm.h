/******************************************************************************
*  �� �� ��    : bmuOsComm.h
*  �� �� ��    : qhxiong
*  �������� : 2013��6��25�����ڶ�
*  �� �� ��    : V1.0
*  �ļ����� : bmulib osͨ�ýӿ�ͷ�ļ�
*  ��Ȩ˵�� : Copyright (c) 2000-2020   ���ͨ�ſƼ��ɷ����޹�˾
*  ��    ��	        : ��
*  �޸���־ :
******************************************************************************/
#ifndef __BMUOSCOMM_H__
#define __BMUOSCOMM_H__
#ifdef __cplusplus
extern "C" {
#endif  /*__cplusplus*/

/*************** bmulib��ӡ��ɫ�궨�� ***************/
#define BMU_COLOR_RED           "\33[01;31m"
#define BMU_COLOR_MAGENTA   "\33[35m"
#define BMU_COLOR_BLUE          "\33[34m"
#define BMU_COLOR_GREEN         "\033[0;40;32m"
#define BMU_COLOR_NORMAL        "\033[0m"

/*************** bmulib��־�洢�궨��***************/
#define BMU_PRINT_MSG_BUF_SIZE            512
#define BMU_LOG_MSG_BUF_SIZE              (50 * 1024)
#define BMU_LOG_MSG_FILE_SIZE             (10 * 1024 * 1024)
#define BMU_LOG_MSG_BUF_NUM                             10

/*************** bmulib��Ϣ��ӡ����***************/
#define BMU_CRIT                1       /* critical conditions			*/
#define BMU_ERR                         2       /* error conditions			*/
#define BMU_WARNING                     3       /* warning conditions			*/
#define BMU_NOTICE                      4       /* normal but significant condition	*/
#define BMU_INFO                5       /* informational			*/
#define BMU_DEBUG               6       /* debug-level messages			*/

/*************** bmulib��������ǿ��ת���궨��***************/
#define RW32            *(volatile unsigned int *)
#define RW16            *(volatile unsigned short *)
#define RW8             *(volatile unsigned char *)

/*��Ϣ��ӡ�������ȫ�ֱ���*/
extern unsigned char g_ucPrintMsgLevel;

/*��Ϣ��ӡ��ɫ����ȫ�ֱ���*/
extern unsigned char g_ucPrintMsgColor;

/*ģ����������ȫ�ֱ���*/
extern char *g_pThisModule;

/*****************************************************************************
* �� �� ��      : MalloZero
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ��̬�����ڴ沢����
* �������  : int size
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern char *MalloZero(int size);

/*****************************************************************************
* �� �� ��      : BmuMalloc
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ��̬�����ڴ�
* �������  : int size
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern void *BmuMalloc(int size);

/*****************************************************************************
* �� �� ��      : BmuFree
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : �ͷ��ڴ�
* �������  : char * *buffer
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern void BmuFree(char * *buffer);

/*****************************************************************************
* �� �� ��      : BmuPrintf
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��ӡ�ӿ�
* �������  : const char *module
*                           const char *fun
*                           const int line
*                           int iLevel
*                           const char *fmt
*                           ...
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern void BmuPrintf(const char *module, const char *fun, const int line, int iLevel, const char *fmt, ...);

/*****************************************************************************
* �� �� ��      : BmuTimePrintf
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��ӡ�ӿڣ���ʱ���
* �������  : const char *module
*                           const char *fun
*                           const int line
*                           int iLevel
*                           const char *fmt
*                           ...
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern void BmuTimePrintf(const char *module, const char *fun, const int line, int iLevel, const char *fmt, ...);

/*****************************************************************************
* �� �� ��      : BmuLog
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib��־�洢�ӿ�
* �������  : const char *file
*                           const char *fun
*                           const int line
*                           int level
*                           const char *logfile
*                           const char *fmt
*                           ...
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuLog(const char *file,
    const char *fun,
    const int line,
    int level,
    const char *logfile,
    const char *fmt,
    ...);

/*****************************************************************************
* �� �� ��      : BmuGetDirFileName
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ��Ŀ¼�����ļ����ϲ�����������·����
* �������  : unsigned char *dirAndName
*                           unsigned char *string
*                           unsigned char *dir
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuGetDirFileName(unsigned char *dirAndName, unsigned char *string, unsigned char *dir);

/*****************************************************************************
* �� �� ��      : BmuGetNakeName
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ͨ������·������ȡ�ļ���
* �������  : char *nakeName
*                           char *dirAndName
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuGetNakeName(char *nakeName, char *dirAndName);

/*****************************************************************************
* �� �� ��      : BmuGetDirName
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ͨ������·������ȡĿ¼��
* �������  : char *dirName
*                           char *dirAndName
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuGetDirName(char *dirName, char *dirAndName);

/*****************************************************************************
* �� �� ��      : BmuGetRealName
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ͨ��ת�����ļ�����ȡת��ǰ�ļ���
* �������  : char *realName
*                           char *nakeName
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuGetRealName(char *realName, char *nakeName);

/*****************************************************************************
* �� �� ��      : BmuGetUntarName
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ��ȡ������ļ���
* �������  : char *untarName
*                           char *nakeName
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuGetUntarName(char *untarName, char *nakeName);

/*****************************************************************************
* �� �� ��      : BmuGetLocalFileLen
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ��ȡ�ļ�����
* �������  : char *localName
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuGetLocalFileLen(char *localName);

/*****************************************************************************
* �� �� ��      : BmuReadLocalFile
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ���ļ���ȡָ������������������
* �������  : char *localName
*                           char *buffer
*                           int len
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuReadLocalFile(char *localName, char *buffer, int len);

/*****************************************************************************
* �� �� ��      : BmuWriteLocalFile
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ������������д���ļ�
* �������  : char *localName
*                           char *buffer
*                           int len
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuWriteLocalFile(char *localName, char *buffer, int len);

/*****************************************************************************
* �� �� ��      : BmuRead32Buf
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ������ת���ӿڣ����մ��ģʽ��4�ֽ�uchar��ת����uint
* �������  : unsigned char *buffer
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern unsigned int BmuRead32Buf(unsigned char *buffer);

/*****************************************************************************
* �� �� ��      : BmuWrite32Buf
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : д����ת���ӿڣ����մ��ģʽ��uintת����4�ֽ�uchar
* �������  : unsigned char *buffer
*                           unsigned int uiValue
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuWrite32Buf(unsigned char *buffer, unsigned int uiValue);

/*****************************************************************************
* �� �� ��      : BmuRead16Buf
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ������ת���ӿڣ����մ��ģʽ��2�ֽ�uchar��ת����ushort
* �������  : unsigned char *buffer
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern unsigned short BmuRead16Buf(unsigned char *buffer);

/*****************************************************************************
* �� �� ��      : BmuWrite16Buf
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : д����ת���ӿڣ����մ��ģʽ��ushortת����2�ֽ�uchar
* �������  : unsigned char *buffer
*                           unsigned short usValue
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuWrite16Buf(unsigned char *buffer, unsigned short usValue);

/*****************************************************************************
* �� �� ��      : BmuWriteFloatBuf
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : д����ת���ӿڣ����մ��ģʽ��floatת����4�ֽ�uchar
* �������  : unsigned char *buffer
*                           float fValue
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuWriteFloatBuf(unsigned char *buffer, float fValue);

/*****************************************************************************
* �� �� ��      : BmuReadFloatBuf
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ������ת���ӿڣ����մ��ģʽ��4�ֽ�uchar��ת����float
* �������  : unsigned char *buffer
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern float BmuReadFloatBuf(unsigned char *buffer);

/*****************************************************************************
* �� �� ��      : BmuRemoveNewLineSign
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ȥ���ַ���ĩβ"\n"
* �������  : char *pStrBuf
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuRemoveNewLineSign(char *pStrBuf);

/*****************************************************************************
* �� �� ��      : BmuGetFileAbsolutePath
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ��ȡ�ļ�����·����
* �������  : char *pFilePath
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuGetFileAbsolutePath(char *pFilePath);

/*****************************************************************************
* �� �� ��      : BmuRemoveFileDotSign
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : ȥ���ļ���׺������'.'��ʼ
* �������  : char *nakeName
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuRemoveFileDotSign(char *nakeName);

/*****************************************************************************
* �� �� ��      : BmuRemoveStrEndingBlank
* �� �� ��      : qhxiong
* ��������  : 2013��7��25��������
* ��������  : ȥ���ַ���ĩβ�Ŀո��ַ����Ʊ��ַ�
* �������  : char *pStrBuf
* �������  : ��
* �� �� ֵ      :
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern int BmuRemoveStrEndingBlank(char *pStrBuf);

/*****************************************************************************
* �� �� ��      : BmuCrcCalc
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib 16λcrcЧ��ӿ�
* �������  : unsigned char *data
*                           int length
*                           unsigned short seed
*                           unsigned short final
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern unsigned short BmuCrcCalc(unsigned char *data, int length, unsigned short seed, unsigned short final);

/*****************************************************************************
* �� �� ��      : BmuZipGetRAMCRC
* �� �� ��      : qhxiong
* ��������  : 2013��6��25�����ڶ�
* ��������  : bmulib 32λcrcЧ��ӿ�
* �������  : const unsigned char *pvMem
*                           int iLen
* �������  : ��
* �� �� ֵ      : extern
* ���ù�ϵ  :
* �� ��            :
*****************************************************************************/
extern unsigned int BmuZipGetRAMCRC(const unsigned char *pvMem, int iLen);

#ifndef RELEASE
/*************** bmulib��ӡ�ӿں궨�� ***************/
#define BMU_SPRINTF(level, fmt, args...)         BmuPrintf(NULL, NULL, NULL, level, fmt, ##args)

/*************** bmulib��ӡ�ӿں궨�� ***************/
#define BMU_PRINTF(level, fmt, args...)         BmuPrintf(g_pThisModule, __FUNCTION__, __LINE__, level, fmt, ##args)

/*************** bmulib��ӡ�ӿ�(��ʱ���)�궨�� ***************/
#define BMU_TPRINTF(level, fmt, args...)        BmuTimePrintf(g_pThisModule, \
        __FUNCTION__,                                                        \
        __LINE__,                                                            \
        level,                                                               \
        fmt,                                                                 \
        ##args)
/*************** bmulib��ӡ�ӿ�(����ģ���������������к�)�궨�� ***************/
#define BMU_SPRINTF(level, fmt, args...)         BmuPrintf(NULL, NULL, NULL, level, fmt, ##args)
#else 
#define BMU_SPRINTF(level, fmt, args...) 
#define BMU_PRINTF(level, fmt, args...)
#define BMU_TPRINTF(level, fmt, args...)   
#define BMU_SPRINTF(level, fmt, args...)
#endif 
/*************** bmulib��־�洢�궨�� ***************/
#define BMU_LOG(level, logfile, fmt, args...)   BmuLog(__FILE__, __FUNCTION__, __LINE__, level, logfile, fmt, ##args)

/*************** bmulib��־�洢(�����ļ��������������к�)�궨�� ***************/
#define BMU_SLOG(level, logfile, fmt, args...)   BmuLog(NULL, NULL, 0, level, logfile, fmt, ##args)


#if 0
/*************** bmulib�ڴ��ͷź궨�� ***************/
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

/*************** bmulib�ļ��رպ궨�� ***************/
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

/*************** bmulib�ļ��رպ궨�� ***************/
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
