/***********************************************************************************

 * 文 件 名   : bfd_stub.c
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年11月25日
 * 版 本 号   : 
 * 文件描述   : BFD桩函数
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#include "bfd.h"

#ifdef X86_UINT_TEST

#ifndef USE_BMU_LIB         /* 不使用BMU库的情况 */
#include <time.h>
#endif

unsigned char reg_block_by_external_module(unsigned char blockid, unsigned char ken_len, 
    unsigned long size_of_element, unsigned long max_elment_num, int (*func)(unsigned char **, unsigned char))
{
    BFD_LOG(BMU_NOTICE, "blockid: %u, ken_len: %u, size_of_element: %lu, max_elment_num: %lu\n",
        blockid, ken_len, size_of_element, max_elment_num);
    return 0;
}

int fhdrv_fap_udf_entry_create(int unit, drv_udf_key_t* key, drv_udf_action_t* action)
{
    BFD_LOG(BMU_NOTICE, "unit: %d\n", unit);
    return 10;
}

int fhdrv_fap_udf_entry_destroy(int unit,int entry)
{
    BFD_LOG(BMU_NOTICE, "unit: %d, entry: %d\n", unit, entry);
    return 0;
}

char get_frame_type()
{
    return FRAME_U40;
}

int oam_get_traffic_info_stub(unsigned long bfd_myid, unsigned char type, TP_OAM_LSP_CFG *LspRxCfg)
{
    BFD_LOG(BMU_NOTICE, "bfd_myid: %lu, type: %u\n", bfd_myid, type);
    return 0;
}

#ifndef USE_BMU_LIB         /* 不使用BMU库的情况 */
UINT16 BmuGetBoardAddr_stub(void)
{
    BFD_LOG(BMU_NOTICE, "\n");
    return 0;
}

int BmuLog_stub(const char *file,
    const char *fun,
    const int line,
    int level,
    const char *logfile,
    const char *fmt,
    ...)
{
    va_list vargs;
    char buf[BMU_PRINT_MSG_BUF_SIZE] = {0};
    const char *color_pfx = "";
    const char *color_sfx = BFD_COLOR_NORMAL;

    /*记录位置*/
    if ((file != NULL) && (fun != NULL) && (fun != NULL))
    {
        snprintf(buf, sizeof(buf), "%s:%d %s() ", file, line, fun);
    }

    /*记录内容*/
    va_start(vargs, fmt);
    vsnprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), fmt, vargs);
    va_end(vargs);

    /*输出打印*/
    switch (level)
    {
        case BMU_CRIT:
            color_pfx = BFD_COLOR_RED;
            break;
        case BMU_ERR:
            color_pfx = BFD_COLOR_MAGENTA;
            break;
        case BMU_WARNING:
            color_pfx = BFD_COLOR_YELLOW;
            break;
        case BMU_NOTICE:
            color_pfx = BFD_COLOR_CYAN;
            break;
        case BMU_INFO:
            color_pfx = BFD_COLOR_GREEN;
            break;
        default:
            color_pfx = "";
            color_sfx = "";
        break;
    }
    printf("%s%s%s", color_pfx, buf, color_sfx);

    return 0;
}

void GetSysClock_stub(struct SYSTIME *pstuClock)
{
    struct timespec now = {.tv_sec = 0, .tv_nsec = 0};
    struct tm stuTm;

    if (clock_gettime(CLOCK_REALTIME, &now) < 0)
    {
        fprintf(stderr, "%s %d:%s\n", __FUNCTION__, __LINE__, strerror(errno));
        return;
    }
    localtime_r(&now.tv_sec, &stuTm);

    pstuClock->usYear = stuTm.tm_year + 1900;
    pstuClock->ucMonth = stuTm.tm_mon + 1;
    pstuClock->ucDate = stuTm.tm_mday;
    pstuClock->ucHour = stuTm.tm_hour;
    pstuClock->ucMinute = stuTm.tm_min;
    pstuClock->ucSecond = stuTm.tm_sec;
    pstuClock->us5Ms = (now.tv_nsec / 1000000) / 5;

    return;
}

#endif

unsigned short *g_stub_fpga_buf;

unsigned int ptn_fpga_base_addr_get()
{
    return (unsigned int)g_stub_fpga_buf;
}

int malloc_fpga_base_addr()
{
    g_stub_fpga_buf = calloc(sizeof(unsigned short), BFD_STUB_FPGA_MAC_ADDR);
    if(NULL == g_stub_fpga_buf)
    {
        return -1;
    }
    return 0;
}
#endif


