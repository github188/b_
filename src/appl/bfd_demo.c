/***********************************************************************************

 * 文 件 名   : bfd_demo.c
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年10月14日
 * 版 本 号   : 
 * 文件描述   : BFD单元自测
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#include "bfd.h"

/*****************************************************************************
 * 函 数 名  : bfd_demo_add
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年10月19日
 * 函数功能  : 配置BFD
 * 输入参数  : 无
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_demo_add()
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned char *ptr_bfd_cfg_buf = NULL;
    unsigned char bfd_cfg_buf[BFD_CFG_LEN] = {0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x58, 0x00, 0x11, 0x00, 0x54, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x0b, 0x01, 0x00, 0x02, 0x10, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x14, 0x00, 0x00, 0x00, 0x14, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    do /* 开始循环 */
    {
        ptr_bfd_cfg_buf = bfd_cfg_buf;
        bfd_active_cfg_process(&ptr_bfd_cfg_buf, 0);
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}



RESULT_BFDCFG bfd_demo_cfg_add()
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned char *ptr_bfd_cfg_buf = NULL;
    unsigned char bfd_cfg_buf[BFD_CFG_LEN] = {0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x58, 0x00, 0x11, 0x00, 0x54, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x02, 0x10, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x14, 0x00, 0x00, 0x00, 0x14, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    do /* 开始循环 */
    {
        ptr_bfd_cfg_buf = bfd_cfg_buf;
        bfd_active_cfg_process(&ptr_bfd_cfg_buf, 0x80);
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}


RESULT_BFDCFG bfd_demo_del()
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned char *ptr_bfd_cfg_buf = NULL;
    unsigned char bfd_cfg_buf[BFD_CFG_LEN] = {0x00, 0x00, 0x00, 0x0b, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00};

    do /* 开始循环 */
    {
        ptr_bfd_cfg_buf = bfd_cfg_buf;
        bfd_active_cfg_process(&ptr_bfd_cfg_buf, 0);
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}


RESULT_BFDCFG bfd_init_test(IN NBB_USHORT start_index,
                           IN NBB_USHORT end_index,
                           IN NBB_BYTE send_type,
                           IN NBB_BYTE loop_flag)
{
    NBB_USHORT index = 0;
    RESULT_BFDCFG ret = CFG_OK;
    BFD_FPGA_INFO fpga_info;
    unsigned short loop = 0;

    do
    {
        /* 检查参数 */
        if ((end_index > BFD_MAX_SESNUM) || (start_index > BFD_MAX_SESNUM))
        {
            ret = PARAM_ERROR;
            break;
        }
        
        /* 检查参数 */
        if (send_type >= BFD_PCK_BUTT)
        {
            ret = PARAM_ERROR;
            break;
        }
                
        BFD_LOG(BFD_SHELL_INFO, "process bfd init\n");
        

        for (index = start_index; index < end_index; index++)/* 初始化 */
        {
            OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));

            fpga_info.index = index;
            fpga_info.send_cfg.frame_type = send_type; /* send_type F6K固定填2 */
            fpga_info.send_cfg.function.send_flag = 1;
            fpga_info.send_cfg.function.detection_type = 0;
            fpga_info.send_cfg.function.vlan_able = 1;
            fpga_info.send_cfg.function.vlan_num = 0;
            fpga_info.send_cfg.function.pw_type = 1;
            fpga_info.send_cfg.sysport.des_fapid = 100;
            fpga_info.send_cfg.sysport.local_sysport = 164;
            for (loop = 0; loop < MAC_LENGTH; loop++) /* 对变量loop进行循环 */
            {
                fpga_info.send_cfg.eth_mac.des_mac[loop] = 0x10 + loop;
                fpga_info.send_cfg.eth_mac.src_mac[loop] = 0x20 + loop;
            }
            fpga_info.send_cfg.label.lsp_label = 55555 + 5 * index;
            fpga_info.send_cfg.label.pw_label = 66665 + 5 * index;
            fpga_info.send_cfg.label.ach = 0x10000021;
            fpga_info.send_cfg.ip.type = BFD_IPV4;
            fpga_info.send_cfg.ip.tos = 16;
            fpga_info.send_cfg.ip.total_length = 52;
            for (loop = 0; loop < ATG_DCI_IPV6_LEN; loop++) /* 对变量loop进行循环 */
            {
                fpga_info.send_cfg.ip.local_ip[loop]  = 0x0c010100 + index + ATG_DCI_IPV6_LEN - loop;
                fpga_info.send_cfg.ip.remote_ip[loop] = 0x0c010200 + index + ATG_DCI_IPV6_LEN - loop;
            }
            fpga_info.send_cfg.udp.src_port = 5000;
            fpga_info.send_cfg.udp.udp_len = 32;
            fpga_info.send_cfg.udp.data_len = 24;
            fpga_info.send_cfg.discr.my_id = 156 + index;
            if (1 == loop_flag)
            {
                fpga_info.send_cfg.discr.peer_id = 100 + index + ((index % 2) ? (-1) : 1);
            }
            else
            {
                fpga_info.send_cfg.discr.peer_id = 100 + index;
            }
            fpga_info.send_cfg.state.diag = bfd_diag_no_diag;
            fpga_info.send_cfg.state.state = BFD_DOWN;
            fpga_info.send_cfg.interval.required_min_rx_interval = BFD_100MS;
            fpga_info.send_cfg.interval.desired_min_tx_interval = BFD_100MS;
            fpga_info.send_cfg.interval.detect_mult = 3;

            ret = bfd_set_fpga(&fpga_info);
            if(CFG_OK != ret)
            {
                break;
            }
            
            /* 存储配置 */
            ret = bfd_add_specify_fpga_database(index, &fpga_info);
            if(CFG_OK != ret)
            {
                break;
            }
        }
    }while(0);
        
    return ret;
}

RESULT_BFDCFG bfd_deleteloop_test(IN NBB_USHORT start_index, IN NBB_USHORT end_index)
{
    NBB_USHORT index = 0;
    BFD_FPGA_INFO fpga_info;
    RESULT_BFDCFG ret = CFG_OK;

    do
    {
        /* 检查参数 */
        if ((end_index > BFD_MAX_SESNUM) || (start_index > BFD_MAX_SESNUM))
        {
            ret = PARAM_ERROR;
            break;
        }

        for (index = start_index; index < end_index; index++)/* 初始化 */
        {
            OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
            
            /* 获取存储的FPGA数据 */
            ret = bfd_get_specify_array_info(index, &fpga_info);
            if(CFG_OK != ret)   /* 获取不到可能是没有add */
            {
                continue;
            }
            
            /* 删除存储配置 */
            ret = bfd_del_specify_fpga_database(index);
            
            /* 删除FPGA内容 */
            ret = bfd_del_fpga(index, fpga_info.send_cfg.discr.my_id);
        }
    }while(0);
    
    return ret;
}


RESULT_BFDCFG bfd_unit_test_add_fpga(unsigned short index)
{
    RESULT_BFDCFG ret = CFG_OK;
    
    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BFD_SHELL_CRIT, "input num %d is wrong!\n", index);
            ret = PARAM_ERROR;
            break;
        }

        ret = bfd_init_test(index, index + 1, 2, 0);
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}

RESULT_BFDCFG bfd_unit_test_del_fpga(unsigned short index)
{
    RESULT_BFDCFG ret = CFG_OK;
    
    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BFD_SHELL_CRIT, "input num %d is wrong!\n", index);
            ret = PARAM_ERROR;
            break;
        }

        ret = bfd_deleteloop_test(index, index + 1);

    }while(0);
    
    return ret;
}

RESULT_BFDCFG bfd_unit_test_cfg(IN OP_TYPE_T op,
    IN unsigned char send_type,
    IN unsigned short num,
    IN NBB_BOOL loop_flag)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_CFG cfg;
    unsigned short loop = 0;
    unsigned short i = 0;

    do /* 开始循环 */
    {
        if(num >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BFD_SHELL_CRIT, "num:%u is too big, max is %u\n", num, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        for (i = 0; i < num; i++) /* 对变量i进行循环 */
        {
            OS_MEMSET(&cfg, 0, sizeof(cfg));
            
            cfg.key = 10000 + i;
            cfg.op = op;
            cfg.serial_num = 1;
            cfg.len = 88;
            cfg.base_cfg.head.type = 1;
            cfg.base_cfg.head.len = 84;
            cfg.base_cfg.cfg.my_sid = cfg.key;
            if(TRUE == loop_flag)
            {
                cfg.base_cfg.cfg.peer_sid = cfg.base_cfg.cfg.my_sid + ((i % 2) ? (-1) : 1);
            }
            else
            {
                cfg.base_cfg.cfg.peer_sid = cfg.base_cfg.cfg.my_sid;
            }
            cfg.base_cfg.cfg.bfd_enable = 1;
            cfg.base_cfg.cfg.detect_method = 0;
            cfg.base_cfg.cfg.bfd_frame_type = send_type;
            cfg.base_cfg.cfg.service_type = 16;
            cfg.base_cfg.cfg.udp_src_port = 5000;
            for (loop = 0; loop < ATG_DCI_IPV6_LEN; loop++) /* 对变量loop进行循环 */
            {
                cfg.base_cfg.cfg.local_ip[loop]  = 0x0c010101 + i + ATG_DCI_IPV6_LEN - loop;
                cfg.base_cfg.cfg.remote_ip[loop] = 0x0c010201 + i + ATG_DCI_IPV6_LEN - loop;
            }
            cfg.base_cfg.cfg.peer_sid_selflearn_enable = 0;
            cfg.base_cfg.cfg.dmti = BFD_100MS;
            cfg.base_cfg.cfg.rmri = BFD_100MS;
            cfg.base_cfg.cfg.dete_mul = 3;
            cfg.base_cfg.cfg.vrf_id = 0;
            cfg.base_cfg.cfg.ip_type = BFD_IPV4;
            cfg.base_cfg.cfg.phy_if_index = 1111;
            
            ret = bfd_cfg_pro(&cfg);
        }
    } while ( 0 ); /* 循环直到0不成立 */

    return  ret;
}

RESULT_BFDCFG bfd_unit_test_add_alarm()
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned long my_sid = 0;
    BFD_STATE last_state;
    BFD_STATE new_state;

    do /* 开始循环 */
    {
        OS_MEMSET(&last_state, 0, sizeof(last_state));
        OS_MEMSET(&new_state, 0, sizeof(new_state));

        my_sid = 200;
        last_state.diag = bfd_diag_no_diag;
        last_state.state = BFD_UP;
        new_state.diag = bfd_diag_ctrl_detect_exp;
        new_state.state = BFD_DOWN;
        
        ret = bfd_produce_alarm(my_sid, &last_state, &new_state);
        
        my_sid = 201;
        last_state.diag = bfd_diag_no_diag;
        last_state.state = BFD_UP;
        new_state.diag = bfd_diag_nbr_session_down;
        new_state.state = BFD_DOWN;
        
        ret = bfd_produce_alarm(my_sid, &last_state, &new_state);
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}

RESULT_BFDCFG bfd_unit_test_del_alarm()
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned long my_sid = 0;
    BFD_STATE last_state;
    BFD_STATE new_state;

    do /* 开始循环 */
    {
        OS_MEMSET(&last_state, 0, sizeof(last_state));
        OS_MEMSET(&new_state, 0, sizeof(new_state));

        my_sid = 200;
        last_state.diag = bfd_diag_ctrl_detect_exp;
        last_state.state = BFD_DOWN;
        new_state.diag = bfd_diag_no_diag;
        new_state.state = BFD_UP;
        
        ret = bfd_produce_alarm(my_sid, &last_state, &new_state);
        
        my_sid = 201;
        last_state.diag = bfd_diag_nbr_session_down;
        last_state.state = BFD_DOWN;
        new_state.diag = bfd_diag_no_diag;
        new_state.state = BFD_UP;
        
        ret = bfd_produce_alarm(my_sid, &last_state, &new_state);
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}

