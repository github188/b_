/***********************************************************************************

 * �� �� ��   : bfd_test_code.c
 * �� �� ��   : jiangbo,����
 * ��������   : 2016��10��14��
 * �� �� ��   : 
 * �ļ�����   : �����棬��֤����
 * ��Ȩ˵��   : Copyright (C) 2000-2016   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 

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

    do /* ��ʼѭ�� */
    {
        ret = malloc_fpga_base_addr();
        if(0 != ret)
        {
            return ret;
        }
        
        bfd_init();


        /* ʹ��BMU�Ŀ⣬������x86������linux��ʵ�������豸��Ч�� */
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

        /*************** �ڸ������¼����Լ��ĵ��Ժ��� *******************/

        #if 0
        /* ����BFD��ӡ */
        BFD_LOG(BFD_SHELL_NOTICE, "***************************����BFD��ӡ***********************\n");
        BFD_LOG(BFD_SHELL_CRIT, "BFD_SHELL_CRIT\n");
        BFD_LOG(BFD_SHELL_ERR, "BFD_SHELL_ERR\n");
        BFD_LOG(BFD_SHELL_WARNING, "BFD_SHELL_WARNING\n");
        BFD_LOG(BFD_SHELL_NOTICE, "BFD_SHELL_NOTICE\n");
        BFD_LOG(BFD_SHELL_INFO, "BFD_SHELL_INFO\n");
        BFD_LOG(BFD_SHELL_DEBUG, "BFD_SHELL_DEBUG\n");
        #endif

        #if 0
        /* ���Դ�С�� */
        BFD_LOG(BFD_SHELL_NOTICE, "***************************���Դ�С��**************************\n");
        test_endian();
        #endif

        #if 0
        /* �������4��BFD���ã��鿴BFD�����Ƿ���Ч */
        BFD_LOG(BFD_SHELL_NOTICE, "*************�������4��BFD���ã��鿴BFD�����Ƿ���Ч***********\n");
        bfd_unit_test_cfg(0, 2, 4, FALSE);
        bfd_show_all_cfg();
        bfd_show_fpga_by_myid(10000);
        
        /* ����ɾ��4��BFD���ã��鿴BFD�����Ƿ���Ч */
        BFD_LOG(BFD_SHELL_NOTICE, "*************����ɾ��4��BFD���ã��鿴BFD�����Ƿ���Ч***********\n");
        bfd_unit_test_cfg(1, 2, 4, FALSE);
        bfd_show_all_cfg();
        bfd_show_fpga_by_myid(10000);
        #endif

        #if 0
        /* ����1.������ 2.λ���ڴ�С��ϵͳ�µ�Ӧ�� */
        BFD_LOG(BFD_SHELL_NOTICE, "*************���� 1.������ 2.λ���ڴ�С��ϵͳ�µ�Ӧ��***********\n");
        test_union();
        #endif

        #if 0
        /* ������FPGA����һ��BFD */
        BFD_LOG(BFD_SHELL_NOTICE, "************************������FPGA����һ��BFD*******************\n");
        bfd_unit_test_add_fpga(2046);
        bfd_show_fpga_by_index(2046);
        
        /* ������FPGAɾ��һ��BFD */
        BFD_LOG(BFD_SHELL_NOTICE, "************************������FPGAɾ��һ��BFD*******************\n");
        bfd_unit_test_del_fpga(2046);
        bfd_show_fpga_by_index(2046);
        #endif

        #if 1
        /* ���������·������� */
        BFD_LOG(BFD_SHELL_NOTICE, "***************************���������·������� *******************\n");
        bfd_demo_add();
        bfd_demo_cfg_add();
        bfd_show_all_cfg();
        bfd_show_fpga_by_index(0);
        bfd_show_fpga_by_index(1);

        /* ��������ɾ������ */
        BFD_LOG(BFD_SHELL_NOTICE, "***************************��������ɾ������ **********************\n");
        bfd_demo_del();
        bfd_show_all_cfg();
        bfd_show_fpga_by_index(0);
        bfd_show_fpga_by_index(1);
        #endif

        #if 0
        /* �����¼���־ */
        BFD_LOG(BFD_SHELL_NOTICE, "***************************�����¼���־ *******************\n");
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

            BFD_LOG(BFD_SHELL_NOTICE, "======================��ӡȫ���¼���־=====================\n");
            bfd_show_event(3);
            BFD_LOG(BFD_SHELL_NOTICE, "====================����myidΪ100���¼���־================\n");
            bfd_show_event_by_myid(100, 3);
        }
        #endif

        #if 0
        bfd_set_fpga_capture_packet(0);
        bfd_set_fpga_capture_packet(1);
        bfd_set_fpga_capture_packet(2);
        bfd_set_fpga_capture_packet(3);
        #endif
        
        /*************** �ڸ������ϼ����Լ��ĵ��Ժ��� *******************/
        #endif
    } while ( 0 ); /* ѭ��ֱ��0������ */
    
    return 0;
}


#endif

