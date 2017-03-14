
#ifndef __BMUV2_DOWNLOAD_H__
#define __BMUV2_DOWNLOAD_H__

struct BMU_VER_INFO_STORE
{ 
	unsigned int uiOffsetAddr;									/*器件版本信息写入存储介质中的地址*/    
    int (*pReadMethod)(unsigned int, unsigned char *, unsigned int);    /*读存储介质的方法*/
    int (*pWriteMethod)(unsigned int, unsigned char *, unsigned int);   /*写存储介质的方法*/
    int (*pEnableCtlFunc)(int);                                  /*器件下载使能控制*/
	int (*pRstFunc)(void);										/*器件复位接口*/
	int (*pCsEnable)();											/*EPCS器件片选使能*/
	int (*pCsDisable)();											/*EPCS器件片选禁止*/
};

#ifdef  __cplusplus
extern  "C" {
#endif  /* __cplusplus */
int downFpga(const char *pcFileName,int pinSel);	
int downCpld(const char *pcFileName);

/*****************************************************************************
* 函 数 名      : BmuForceDownCpld
* 负 责 人      : qhxiong
* 创建日期  : 2013年12月31日星期二
* 函数功能  : 强制下载cpld接口
* 输入参数  : const char *pFileName
* 输出参数  : 无
* 返 回 值      :
* 调用关系  :
* 其 他            :
*****************************************************************************/
int BmuForceDownCpld(const char *pFileName, struct BMU_VER_INFO_STORE *pVerStoreCtl);

/*****************************************************************************
* 函 数 名      : BmuDownCpld
* 负 责 人      : qhxiong
* 创建日期  : 2013年5月17日星期五
* 函数功能  : cpld下载接口
* 输入参数  : const char *pFileName
*                           struct BMU_VER_INFO_STORE *pVerStoreCtl
* 输出参数  : 无
* 返 回 值      : -1 下载失败
                        0 下载成功
                        1 无需下载
* 调用关系  :
* 其 他            :
*****************************************************************************/
int BmuDownCpld(const char *pFileName, struct BMU_VER_INFO_STORE *pVerStoreCtl);


#ifdef  __cplusplus
}
#endif  /* __cplusplus */

#endif

