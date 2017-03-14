/***********************************************************************************

 * 文 件 名   : bfd_test_code.c
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年10月14日
 * 版 本 号   : 
 * 文件描述   : 测着玩，验证功能
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#include "bfd.h"

#ifdef X86_UINT_TEST

int test_union()
{
    SPM_BFD_FIFO_CVLAN_TEST cvlan;

    OS_MEMSET(&cvlan, 0, sizeof(cvlan));

    cvlan.head.lag_head.lag = 1;
    cvlan.head.ip_head.usPktType = 2;
    cvlan.head.ip_head.usIpType = 0;
    cvlan.head.ip_head.usVrfL = 4095;

    BFD_LOG(BFD_SHELL_INFO, "size %d\n", sizeof(cvlan));
    BFD_LOG(BFD_SHELL_INFO, "%#x\n", *(NBB_USHORT*)(&cvlan));

    BFD_LOG(BFD_SHELL_INFO, "lag %u\n", cvlan.head.lag_head.lag);
    BFD_LOG(BFD_SHELL_INFO, "ip head: lag %u, pkt type %u, ip type %u, vrf %u\n",
         cvlan.head.ip_head.lag, cvlan.head.ip_head.usPktType, cvlan.head.ip_head.usIpType, cvlan.head.ip_head.usVrfL);
    BFD_LOG(BFD_SHELL_INFO, "port head: lag %u, pad1 %u, pad2 %u, port %u\n",
         cvlan.head.port_head.lag, cvlan.head.port_head.port_pad1, cvlan.head.port_head.port_pad2, cvlan.head.port_head.port);

    return 0;
}

void test_endian()
{
    unsigned char buf[20] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10,
        0x11, 0x12, 0x13, 0x14};
    unsigned char *ptr_buf = buf;
    unsigned long long_val_n = 0;
    unsigned long long_val_l = 0;
    unsigned long long_val = 0;
    unsigned long short_val = 0;
    unsigned long residual_length = 0;

    long_val_n = *((unsigned long *)(ptr_buf));
    long_val_l = BFD_HTONL(long_val_n);
    BFD_LOG(BFD_SHELL_INFO, "long_val_n:%#lx\n", long_val_n);
    BFD_LOG(BFD_SHELL_INFO, "long_val_l:%#lx\n", long_val_l);

    residual_length = sizeof(buf);
    BFD_GET_ULONG(long_val, ptr_buf, residual_length);
    BFD_GET_USHORT(short_val, ptr_buf, residual_length);
    BFD_LOG(BFD_SHELL_INFO, "long_val:%#lx\n", long_val);
    BFD_LOG(BFD_SHELL_INFO, "short_val:%#lx\n", short_val);
    
    return;
}

int main(int argc, char *argv[])
{
    int ret = 0;

    do /* 开始循环 */
    {
        ret = malloc_fpga_base_addr();
        if(0 != ret)
        {
            return ret;
        }
        
        bfd_init();


        /* 使用BMU的库，可以在x86环境的linux上实现类似设备的效果 */
        #ifdef USE_BMU_LIB
        ret = BmuLibInit(0);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, BmuLibInit, ret);
        ret = CliCmdInit(argv[0], "eth1", 9002);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, CliCmdInit, ret);
        
        while(1)
        {
            sleep(1000);
        }
        #else

        /*************** 在该行以下加入自己的调试函数 *******************/

        #if 0
        /* 测试BFD打印 */
        BFD_LOG(BFD_SHELL_NOTICE, "***************************测试BFD打印***********************\n");
        BFD_LOG(BFD_SHELL_CRIT, "BFD_SHELL_CRIT\n");
        BFD_LOG(BFD_SHELL_ERR, "BFD_SHELL_ERR\n");
        BFD_LOG(BFD_SHELL_WARNING, "BFD_SHELL_WARNING\n");
        BFD_LOG(BFD_SHELL_NOTICE, "BFD_SHELL_NOTICE\n");
        BFD_LOG(BFD_SHELL_INFO, "BFD_SHELL_INFO\n");
        BFD_LOG(BFD_SHELL_DEBUG, "BFD_SHELL_DEBUG\n");
        #endif

        #if 0
        /* 测试大小端 */
        BFD_LOG(BFD_SHELL_NOTICE, "***************************测试大小端**************************\n");
        test_endian();
        #endif

        #if 0
        /* 测试添加4条BFD配置，查看BFD配置是否生效 */
        BFD_LOG(BFD_SHELL_NOTICE, "*************测试添加4条BFD配置，查看BFD配置是否生效***********\n");
        bfd_unit_test_cfg(0, 2, 4, FALSE);
        bfd_show_all_cfg();
        bfd_show_fpga_by_myid(10000);
        
        /* 测试删除4条BFD配置，查看BFD配置是否生效 */
        BFD_LOG(BFD_SHELL_NOTICE, "*************测试删除4条BFD配置，查看BFD配置是否生效***********\n");
        bfd_unit_test_cfg(1, 2, 4, FALSE);
        bfd_show_all_cfg();
        bfd_show_fpga_by_myid(10000);
        #endif

        #if 0
        /* 测试1.联合体 2.位域在大小端系统下的应用 */
        BFD_LOG(BFD_SHELL_NOTICE, "*************测试 1.联合体 2.位域在大小端系统下的应用***********\n");
        test_union();
        #endif

        #if 0
        /* 测试往FPGA增加一条BFD */
        BFD_LOG(BFD_SHELL_NOTICE, "************************测试往FPGA增加一条BFD*******************\n");
        bfd_unit_test_add_fpga(2046);
        bfd_show_fpga_by_index(2046);
        
        /* 测试往FPGA删除一条BFD */
        BFD_LOG(BFD_SHELL_NOTICE, "************************测试往FPGA删除一条BFD*******************\n");
        bfd_unit_test_del_fpga(2046);
        bfd_show_fpga_by_index(2046);
        #endif

        #if 1
        /* 测试网管下发的配置 */
        BFD_LOG(BFD_SHELL_NOTICE, "***************************测试网管下发的配置 *******************\n");
        bfd_demo_add();
        bfd_demo_cfg_add();
        bfd_show_all_cfg();
        bfd_show_fpga_by_index(0);
        bfd_show_fpga_by_index(1);

        /* 测试网管删除配置 */
        BFD_LOG(BFD_SHELL_NOTICE, "***************************测试网管删除配置 **********************\n");
        bfd_demo_del();
        bfd_show_all_cfg();
        bfd_show_fpga_by_index(0);
        bfd_show_fpga_by_index(1);
        #endif

        #if 0
        /* 测试事件日志 */
        BFD_LOG(BFD_SHELL_NOTICE, "***************************测试事件日志 *******************\n");
        {
            BFD_STATE last_state;
            BFD_STATE new_state;
            EN_BFD_RECV_ACTION action;

            last_state.state = BFD_DOWN;
            new_state.diag = bfd_diag_ctrl_detect_exp;
            action = BFD_ACTION_DOWN;
            new_state.state = BFD_INIT;
            new_state.diag = bfd_diag_no_diag;
            bfd_record_state_change_event(100, 1, &last_state, action, &new_state);

            last_state.state = BFD_INIT;
            new_state.diag = bfd_diag_no_diag;
            action = BFD_ACTION_INIT;
            new_state.state = BFD_UP;
            new_state.diag = bfd_diag_no_diag;
            bfd_record_state_change_event(100, 1, &last_state, action, &new_state);
            
            last_state.state = BFD_DOWN;
            new_state.diag = bfd_diag_ctrl_detect_exp;
            action = BFD_ACTION_DOWN;
            new_state.state = BFD_INIT;
            new_state.diag = bfd_diag_no_diag;
            bfd_record_state_change_event(200, 2, &last_state, action, &new_state);

            last_state.state = BFD_INIT;
            new_state.diag = bfd_diag_no_diag;
            action = BFD_ACTION_INIT;
            new_state.state = BFD_UP;
            new_state.diag = bfd_diag_no_diag;
            bfd_record_state_change_event(200, 2, &last_state, action, &new_state);

            BFD_LOG(BFD_SHELL_NOTICE, "======================打印全部事件日志=====================\n");
            bfd_show_event(3);
            BFD_LOG(BFD_SHELL_NOTICE, "====================过滤myid为100的事件日志================\n");
            bfd_show_event_by_myid(100, 3);
        }
        #endif

        #if 0
        bfd_set_fpga_capture_packet(0);
        bfd_set_fpga_capture_packet(1);
        bfd_set_fpga_capture_packet(2);
        bfd_set_fpga_capture_packet(3);
        #endif
        
        /*************** 在该行以上加入自己的调试函数 *******************/
        #endif
    } while ( 0 ); /* 循环直到0不成立 */
    
    return 0;
}


#endif

