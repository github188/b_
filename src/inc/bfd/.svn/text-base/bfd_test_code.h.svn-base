/***********************************************************************************

 * 文 件 名   : bfd_test_code.h
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年11月30日
 * 版 本 号   : 
 * 文件描述   : bfd_test_code.c 的头文件
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#ifndef __BFD_TEST_CODE_H__
#define __BFD_TEST_CODE_H__


#ifdef __cplusplus
#if __cplusplus
{
extern "C"
#endif
#endif /* __cplusplus */

#ifdef X86_UINT_TEST

typedef struct spm_bfd_fifo_cvlan_test
{
    union
    {
        struct HEAD
        {
            BITFIELDS2(
            NBB_USHORT lag:       1,
            NBB_USHORT pad:       15);
        }lag_head;
        struct IP_HEAD
        {
            BITFIELDS4(
            NBB_USHORT lag:       1,
            NBB_USHORT usPktType:   2,  /* 包类型，=0，表示LSP层包，=2表示纯IP包，=1表示PW无IP封装的包，=3表示PW有IP封装的包 */
            NBB_USHORT usIpType:    1,  /* 表示IP协议类型，为1表示IPV6，为0表示IPV4 */
            NBB_USHORT usVrfL:      12);
        }ip_head;

        struct PORT_HEAD
        {
            BITFIELDS4(
            NBB_USHORT lag:       1,
            NBB_USHORT port_pad1:   4,  /* 包类型，=0，表示LSP层包，=2表示纯IP包，=1表示PW无IP封装的包，=3表示PW有IP封装的包 */
            NBB_USHORT port_pad2:    6,  /* 表示IP协议类型，为1表示IPV6，为0表示IPV4 */
            NBB_USHORT port:      5);
        }port_head;
    }head;
}SPM_BFD_FIFO_CVLAN_TEST;

extern int main(int argc, char *argv[]);
extern void test_endian();
extern int test_union();

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BFD_TEST_CODE_H__ */
