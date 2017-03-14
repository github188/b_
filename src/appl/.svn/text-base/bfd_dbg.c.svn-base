/***********************************************************************************

 * 文 件 名   : bfd_dbg.c
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年10月12日
 * 版 本 号   : 
 * 文件描述   : BFD调试用
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#include "bfd.h"

extern BFD_DATABASE g_bfd_database;

/*****************************************************************************
 * 函 数 名  : bfd_help
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年10月12日
 * 函数功能  : BFD帮助函数入口
 * 输入参数  : 无
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
NBB_VOID bfd_help()
{
    NBB_CHAR **msg = NULL;
    
    static NBB_CHAR *s_bfd_help_msg[] = {
        "---------------------------------------------------------","",
        "bfd_version()",                                    "show  bfd version",
        "bfd_show_cfg(myid)",                               "show  bfd cfg",
        "bfd_show_all_cfg()",                               "show all bfd cfg",
        "bfd_show_fpga_by_index(index)",                    "show bfd fpga info",
        "bfd_show_fpga_by_myid(myid)",                      "show bfd fpga info",
        "bfd_show_fpga_function_by_index(index)",            "show bfd fpga function info",
        "bfd_show_fpga_function_by_myid(myid)",              "show bfd fpga function info",
        "bfd_show_fpga_sysport_by_index(index)",             "show bfd sysport in ITMH head",
        "bfd_show_fpga_sysport_by_myid(myid)",               "show bfd sysport in ITMH head",
        "bfd_show_fpga_mac_by_index(index)",                 "show bfd MAC info",
        "bfd_show_fpga_mac_by_myid(myid)",                   "show bfd MAC info",
        "bfd_show_fpga_label_by_index(index)",               "show bfd label info",
        "bfd_show_fpga_label_by_myid(myid)",                 "show bfd label info",
        "bfd_show_fpga_ip_by_index(index)",                  "show bfd ip head",
        "bfd_show_fpga_ip_by_myid(myid)",                    "show bfd ip head",
        "bfd_show_fpga_udp_by_index(index)",                  "show bfd udp head",
        "bfd_show_fpga_udp_by_myid(myid)",                    "show bfd udp head",
        "bfd_show_fpga_discr_by_index(index)",                "show bfd discriminate",
        "bfd_show_fpga_discr_by_myid(myid)",                  "show bfd discriminate",
        "bfd_show_fpga_state_interval_by_index(index)",         "show bfd state and interval",
        "bfd_show_fpga_state_interval_by_myid(myid)",           "show bfd state and interval",
        "bfd_show_state_by_index(start_index, end_index)",       "show session state",
        "bfd_show_state_by_myid(myid)",                       "show session state",
        "bfd_show_counter_by_index(start_index, end_index)",     "show session counter",
        "bfd_show_counter_by_myid(myid)",                     "show session counter",
        "bfd_show_anti_attack_info_by_index(start_index, end_index)", "show anti attack info",
        "bfd_show_anti_attack_info_by_myid(myid)",           "show anti attack info",
        "bfd_show_alarm(myid)",                              "show bfd alarm",
        "bfd_show_all_alarm()",                              "show all bfd alarm",
        "bfd_show_oam_cfg_info(my_sid, bfd_frame_type)","show lsp cfg info, bfd_frame_type:2/3=lsp/pw", 
        "bfd_show_oam_bfd_cfg_info(my_sid)",          "show bfd lsp cfg info",
        "bfd_show_event(show_num)",                     "show bfd event",
        "bfd_show_event_by_myid(my_id, show_num)",      "show bfd event",
        "bfd_wlog()",                                       "write bfd log",
        
        /*"showbfdrecource",                           "show total num",
        "show_bfd_fpga_drop_counter()",               "show drop counter of fpga RxBfdPacket",
        "show_bfd_fpga_packet_info(ulNumber)",        "show bfd packet of FPGA's RX or TX",
        "show_bfd_fpga_store_info(ulBfdId)",          "show bfd info of fpga's storage",
        "show_bfd_dma_store_info(ulBfdId)",           "show bfd info of dma's storage",*/
        "---------------------------------------------------------","",
        "bfd_dbg_help",                               "debug info",
        "bfd_set_help",                               "bfd set debug info",
        "bfd_fpga_help",                              "bfd fpga debug",
        NULL };
    
    BFD_LOG(BFD_SHELL_INFO, "\n");

    for (msg = s_bfd_help_msg; *msg != NULL; msg += 2) /* 打印格式 */
    {
        if(strlen(*msg) > BFD_PRT_FUC_NAME_LEN)/* 判断打印长度 */
        {
            BFD_LOG(BFD_SHELL_INFO, " %s %s\n", *msg, *(msg + 1));
        }
        else /* 判断打印长度 */
        {
            BFD_LOG(BFD_SHELL_INFO, " %-*s %s\n", BFD_PRT_FUC_NAME_LEN, *msg, *(msg + 1)); 
        }
    }

    BFD_LOG(BFD_SHELL_INFO, "\n");
}

/*****************************************************************************
 * 函 数 名  : bfd_dbg_help
 * 负 责 人  : 蒋博,jiangbo
 * 创建日期  : 2014年11月27日
 * 函数功能  : BFD 调试函数
 * 输入参数  : NBB_VOID  无
 * 输出参数  : 无
 * 返 回 值  : NBB_VOID  无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
NBB_VOID bfd_dbg_help(NBB_VOID)
{
    NBB_CHAR **msg;
    
    static NBB_CHAR *s_bfd_dbg_help_msg[] = {
        "---------------------------------------------------------","",
        "spm_bfd_init_test(start_index, end_index, send_type, loop_flag)",  "create bfd from start_index to end_index",
        "spm_bfd_deleteloop_test(start_index, end_index)",                  "delete bfd from start_index to end_index",
        "bfd_unit_test_add_fpga(index)",                                    "add fpga",
        "bfd_unit_test_del_fpga(index)",                                    "del fpga",
        "bfd_unit_test_cfg(op, send_type, num, loop_flag)",     "config bfd, op:0/1=add/del,send_type:2/3=lsp/pw",
        "bfd_unit_test_add_alarm()",                            "add alarm",
        "bfd_unit_test_del_alarm()",                            "del alarm",
        /*"setStateMachineSwitch(bSwitch, usstartnum, usendnum)",             "switch 0 is close, 1 is open",
        "showStateMachineSwitch(usloopi)",                                  "show item machine state",
        "showStateMachineSwitchall",                                        "show all item machine state",*/
        "---------------------------------------------------------",   "",
        NULL };
    
    BFD_LOG(BFD_SHELL_INFO, "\n");

    for (msg = s_bfd_dbg_help_msg; *msg != NULL; msg += 2) /* 打印格式 */
    {
        if(strlen(*msg)>60)/* 判断打印长度 */
        {
            BFD_LOG(BFD_SHELL_INFO, " %s %s\n", *msg, *(msg + 1));
        }
        else /* 判断打印长度 */
        {
            BFD_LOG(BFD_SHELL_INFO, " %-55s %s\n", *msg, *(msg + 1)); 
        }
    }

    BFD_LOG(BFD_SHELL_INFO, "\n");
}

/*****************************************************************************
 * 函 数 名  : bfd_set_help
 * 负 责 人  : tianf
 * 创建日期  : 2016年3月2日
 * 函数功能  : BFD 调试函数
 * 输入参数  : NBB_VOID  无
 * 输出参数  : 无
 * 返 回 值  : NBB_VOID  无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
NBB_VOID bfd_set_help()
{
    NBB_CHAR **msg;
    
    static NBB_CHAR *s_bfd_set_help_msg[] = {
        "---------------------------------------------------------","",
        "spm_bfd_set_send_switch(ulBfdId,ucEnable)",            "set single bfd's SendFlag",
        "spm_bfd_set_send_flag(usStartNum,usEndNum,ucEnable)",  "set bfd's SendFlag",
        "---------------------------------------------------------",   "",        
        NULL };
    
    BFD_LOG(BFD_SHELL_INFO, "\n");

    for (msg = s_bfd_set_help_msg; *msg != NULL; msg += 2) /* 打印格式 */
    {
        if(strlen(*msg)>60)/* 判断打印长度 */
        {
            BFD_LOG(BFD_SHELL_INFO, " %s %s\n", *msg, *(msg + 1));
        }
        else /* 判断打印长度 */
        {
            BFD_LOG(BFD_SHELL_INFO, " %-55s %s\n", *msg, *(msg + 1)); 
        }
    }

    BFD_LOG(BFD_SHELL_INFO, "\n");

}

/*****************************************************************************
 * 函 数 名  : bfd_version
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年12月19日
 * 函数功能  : 打印编译日期、时间
 * 输入参数  : 无
 * 输出参数  : 无
 * 返 回 值  : void无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_version()
{
    BFD_LOG(BFD_SHELL_INFO, "\n");
    BFD_LOG(BFD_SHELL_INFO, "**********************************************************\n");
    BFD_LOG(BFD_SHELL_INFO, "*** BFD MODULE BUILD TIME :%s, %s *********\n", __DATE__, __TIME__);
    BFD_LOG(BFD_SHELL_INFO, "**********************************************************\n");
}

/*****************************************************************************
 * 函 数 名  : bfd_analyze_bfd_cfg
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 记录BFD配置块数据
 * 输入参数  : IN BFD_CFG *cfg  BFD配置快
               IN int level     打印级别
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG    错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_analyze_bfd_cfg(IN BFD_CFG *cfg, IN int level)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned char ipv4_addr[4];
    unsigned short ipv6_addr[8];

    do /* 开始循环 */
    {
        if(NULL == cfg)
        {
            BFD_LOG(level, "cfg is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        BFD_LOG(level, "%-*s  %-lu\n", BFD_PRT_CFG_NAME_LEN, "key", cfg->key);
        BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "op", ((0 == cfg->op) ? "add" : "del"));
        BFD_LOG(level, "%-*s  %-lu\n", BFD_PRT_CFG_NAME_LEN, "serial num", cfg->serial_num);
        BFD_LOG(level, "%-*s  %-lu\n", BFD_PRT_CFG_NAME_LEN, "len", cfg->len);
        BFD_LOG(level, "%-*s  %-#x\n", BFD_PRT_CFG_NAME_LEN, "+type", cfg->base_cfg.head.type);
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "+len", cfg->base_cfg.head.len);
        BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+enable",
            ((0 == cfg->base_cfg.cfg.bfd_enable) ? "off" : "on"));
        switch ( cfg->base_cfg.cfg.detect_method )
        {
            case BFD_SIGHOP :
                BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+detect method", "single");
                break;
            case BFD_MULTIHOP :
                BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+detect method", "mutiple");
                break;
            case BFD_LAG :
                BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+detect method", "LAG");
                break;
            default:
                BFD_LOG(level, "%-*s  unknown -- %-u\n", BFD_PRT_CFG_NAME_LEN, "|+detect method",
                    cfg->base_cfg.cfg.detect_method);
        }
        switch ( cfg->base_cfg.cfg.bfd_frame_type )
        {
            case BFD_CFG_IP :
                BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+bfd frame type", "IP");
                break;
            case BFD_CFG_Tunnel:
                BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+bfd frame type", "Tunnel");
                break;
            case BFD_CFG_LSP:
                BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+bfd frame type", "LSP");
                break;
            case BFD_CFG_PW:
                BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+bfd frame type", "VC");
                break;
            case BFD_CFG_INTERFACE:
                BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+bfd frame type", "interface");
                break;
            default:
                BFD_LOG(level, "%-*s  unknown -- %u\n", BFD_PRT_CFG_NAME_LEN, "|+bfd frame type",
                    cfg->base_cfg.cfg.bfd_frame_type);
        }
        switch ( cfg->base_cfg.cfg.service_type )
        {
            case 0 :
                BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+service type", "General service");
                break;
            case 2 :
                BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+service type", "minimum cost");
                break;
            case 4 :
                BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+service type", "maximum");
                break;
            case 8 :
                BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+service type", "minimum");
                break;
            case 16 :
                BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+service type",
                    "maximum throughput delay reliability");
                break;
            default:
                BFD_LOG(level, "%-*s  unknown -- %u\n", BFD_PRT_CFG_NAME_LEN, "|+service type",
                    cfg->base_cfg.cfg.service_type);
        }
        
        BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+ip type",
            ((BFD_IPV4 == cfg->base_cfg.cfg.ip_type) ? "IPv4": "IPv6"));
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "|+vrf", cfg->base_cfg.cfg.vrf_id);
        if(BFD_IPV4 == cfg->base_cfg.cfg.ip_type)
        {
            BFD_GET_UCHAR_FORM_ULONG(cfg->base_cfg.cfg.local_ip[3],ipv4_addr[0],
                ipv4_addr[1], ipv4_addr[2], ipv4_addr[3]);
            BFD_LOG(level, "%-*s  %3u.%3u.%3u.%3u\n", BFD_PRT_CFG_NAME_LEN, "|+local ip",
                ipv4_addr[0], ipv4_addr[1], ipv4_addr[2], ipv4_addr[3]);
            BFD_GET_UCHAR_FORM_ULONG(cfg->base_cfg.cfg.remote_ip[3],
                ipv4_addr[0], ipv4_addr[1], ipv4_addr[2], ipv4_addr[3]);
            BFD_LOG(level, "%-*s  %3u.%3u.%3u.%3u\n", BFD_PRT_CFG_NAME_LEN, "|+remote ip",
                ipv4_addr[0], ipv4_addr[1], ipv4_addr[2], ipv4_addr[3]);
        }
        else
        {
            BFD_GET_USHORT_FORM_ULONG(cfg->base_cfg.cfg.local_ip[0], ipv6_addr[0], ipv6_addr[1]);
            BFD_GET_USHORT_FORM_ULONG(cfg->base_cfg.cfg.local_ip[1], ipv6_addr[2], ipv6_addr[3]);
            BFD_GET_USHORT_FORM_ULONG(cfg->base_cfg.cfg.local_ip[2], ipv6_addr[4], ipv6_addr[5]);
            BFD_GET_USHORT_FORM_ULONG(cfg->base_cfg.cfg.local_ip[3], ipv6_addr[6], ipv6_addr[7]);
            BFD_LOG(level, "%-*s  %4x:%4x:%4x:%4x:%4x:%4x:%4x:%4x\n", BFD_PRT_CFG_NAME_LEN, "|+local ip",
                ipv6_addr[0], ipv6_addr[1], ipv6_addr[2], ipv6_addr[3], 
                ipv6_addr[4], ipv6_addr[5], ipv6_addr[6], ipv6_addr[7]);
            BFD_GET_USHORT_FORM_ULONG(cfg->base_cfg.cfg.remote_ip[0], ipv6_addr[0], ipv6_addr[1]);
            BFD_GET_USHORT_FORM_ULONG(cfg->base_cfg.cfg.remote_ip[1], ipv6_addr[2], ipv6_addr[3]);
            BFD_GET_USHORT_FORM_ULONG(cfg->base_cfg.cfg.remote_ip[2], ipv6_addr[4], ipv6_addr[5]);
            BFD_GET_USHORT_FORM_ULONG(cfg->base_cfg.cfg.remote_ip[3], ipv6_addr[6], ipv6_addr[7]);
            BFD_LOG(level, "%-*s  %4x:%4x:%4x:%4x:%4x:%4x:%4x:%4x\n", BFD_PRT_CFG_NAME_LEN, "|+remote ip",
                ipv6_addr[0], ipv6_addr[1], ipv6_addr[2], ipv6_addr[3], 
                ipv6_addr[4], ipv6_addr[5], ipv6_addr[6], ipv6_addr[7]);
        }
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "|+udp src port", cfg->base_cfg.cfg.udp_src_port);
        BFD_LOG(level, "%-*s  %-lu\n", BFD_PRT_CFG_NAME_LEN, "|+my sid", cfg->base_cfg.cfg.my_sid);
        BFD_LOG(level, "%-*s  %-lu\n", BFD_PRT_CFG_NAME_LEN, "|+peer sid", cfg->base_cfg.cfg.peer_sid);
        BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+peer sid selflearn enable", 
            (0 == cfg->base_cfg.cfg.peer_sid_selflearn_enable) ? "disable": "enable");
        if(cfg->base_cfg.cfg.dmti < BFD_TIME_BUTT)
        {
            BFD_LOG(level, "%-*s  %-s\n", BFD_PRT_CFG_NAME_LEN, "|+dmti", g_bfd_interval_str[cfg->base_cfg.cfg.dmti]);
        }
        else
        {
            BFD_LOG(level, "%-*s  unknown -- %u\n", BFD_PRT_CFG_NAME_LEN, "|+dmti", cfg->base_cfg.cfg.dmti);
        }
        if(cfg->base_cfg.cfg.rmri < BFD_TIME_BUTT)
        {
            BFD_LOG(level, "%-*s  %s\n", BFD_PRT_CFG_NAME_LEN, "|+rmti", g_bfd_interval_str[cfg->base_cfg.cfg.rmri]);
        }
        else
        {
            BFD_LOG(level, "%-*s  unknown -- %-u\n", BFD_PRT_CFG_NAME_LEN, "|+rmti", cfg->base_cfg.cfg.rmri);
        }
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "|+dete mul", cfg->base_cfg.cfg.dete_mul);
        BFD_LOG(level, "%-*s  %-lu\n", BFD_PRT_CFG_NAME_LEN, "|+phy if index", cfg->base_cfg.cfg.phy_if_index);

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
    
    return ret;
}


/*****************************************************************************
 * 函 数 名  : bfd_fpga_help
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月19日
 * 函数功能  : BFD FPGA帮助函数入口
 * 输入参数  : 无
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
NBB_VOID bfd_fpga_help()
{
    NBB_CHAR **msg = NULL;
    
    static NBB_CHAR *s_bfd_fpga_help_msg[] = {
        "------------------------fpga-----------------------------","",
        "hw_print_fpga_base_offset_addr(tree_level)",                            "show fpga model base",
        "hw_print_fpga(base_offset, offset, num)",                               "show fpga reg",
        "hw_write_fpga(base_offset, offset, data)",                              "write fpga reg",
        "hw_write_fpga_batch(base_offset, addr, addr_off, data, date_off, num)", "write fpga in a row",
        "bfd_print_bfd_model_fpga(offset, num)",                                 "show fpga bfd model reg",
        "bfd_print_bfd_adapt_fpga(offset, num)",                                 "show fpga bfd adapt reg",
        "bfd_write_bfd_model_fpga(offset, data)",                                "write fpga bfd model reg",
        "bfd_write_bfd_adapt_fpga(offset, data)",                                "write fpga bfd adapt reg",
        "bfd_set_fpga_loop(flag)",                                               "set bfd loop,0=not loop,1=loop",
        "bfd_set_fpga_capture_packet(directon)",                                 "set directon,0=help",
        "bfd_show_fpga_capture_packet()",                                        "show capture packet of FPGA",
        /*"setsrcgeloop(ucType)",    "set src ge(1/2/3) loop",*/
        NULL };
    
    BFD_LOG(BFD_SHELL_INFO, "\n");

    for (msg = s_bfd_fpga_help_msg; *msg != NULL; msg += 2) /* 打印格式 */
    {
        if(strlen(*msg) > BFD_PRT_FUC_NAME_LEN)/* 判断打印长度 */
        {
            BFD_LOG(BFD_SHELL_INFO, " %s %s\n", *msg, *(msg + 1));
        }
        else /* 判断打印长度 */
        {
            BFD_LOG(BFD_SHELL_INFO, " %-*s %s\n", BFD_PRT_FUC_NAME_LEN, *msg, *(msg + 1)); 
        }
    }

    BFD_LOG(BFD_SHELL_INFO, "\n");
}


void hw_print_fpga_base_offset_addr(IN unsigned char level)
{
    if(0 == level)
    {
        level = 2;
    }

    BFD_LOG(BFD_SHELL_INFO, "=============  FPGA map addr  =============\n");
    if(level > 0)
    {
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "fpga base",
            BFD_PRT_FPGA_ADDR_OFFSET_LEN, g_bfd_fpga_global.fpga_base_mcard);
        if(level > 1)
        {
            BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "+bfd model",
                BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_BFD_MODEL_BASE);
            if(level > 2)
            {
                BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "|+rev",
                    BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_REV_BASE);
                if(level > 3)
                {
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+packet loop",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_RCV_LOOP);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+session tree",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FGPA_RCV_SESSION_TREE);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+learned discriminate",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_RCV_MYID);
                }
                BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "|+session",
                    BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SESSION_BASE);
                if(level > 3)
                {
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+diag state",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SESSION_DIAG_STATE);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+work interval(low word)",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SESSION_WORK_INTERVAL_LOW);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+work interval(high word)",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SESSION_WORK_INTERVAL_HIGH);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+receive count",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SESSION_RECV_COUNT);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+send state diag",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SESSION_SEND_STATE_DIAG);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+receive state diag",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SESSION_RECV_STATE_DIAG);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+required myid",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SESSION_REQUIRED_MYID);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+required myid switch",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SESSION_REQUIRED_MYID_SWITCH);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+up to down state",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SESSION_UP_TO_DOWN_STA);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+checksum",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SESSION_CHEKSUM);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+error count",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SESSION_ERROR_COUNT);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+interval not match",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SESSION_INTERVAL_NOT_MATCH);
                }
                BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "|+send",
                    BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_BASE);
                if(level > 3)
                {
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+function",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_FUNCTION);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+DMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_DMAC);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+SMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_SMAC);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+SVLAN",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_SVLAN);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+CVLAN",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_CVLAN);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv4 TOS/IPv6 traffic calss",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPv4_TOS);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv4 length/IPv6 flow label",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV4_TOTAL_LEN);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n",
                        BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv4 identifier/IPv6 payload length",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV4_IDENTIFIER);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n",
                        BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv4 fragment offset/IPv6 hop limit",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV4_FLAG_FRAMOFF);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv4 TTL and protocol/IPv6 SMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV4_TTL_PROTOCOL);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv4 checksum/IPv6 SMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV4_CHECKSUM);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv4 SMAC/IPv6 SMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV4_SRC1TO2);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv4 SMAC/IPv6 SMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV4_SRC3TO4);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv4 DMAC/IPv6 SMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV4_DEC1TO2);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv4 DMAC/IPv6 SMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV4_DEC3TO4);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv6 SMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV6_SRC13TO14);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv6 SMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV6_SRC15TO16);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv6 DMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV6_DEC1TO2);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv6 DMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV6_DEC3TO4);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv6 DMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV6_DEC5TO6);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv6 DMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV6_DEC7TO8);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv6 DMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV6_DEC9TO10);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv6 DMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV6_DEC11TO12);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv6 DMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV6_DEC13TO14);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+IPv6 DMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_IPV6_DEC15TO16);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+UDP source port",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_UPD_SPORT);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+UDP length",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_UPD_LEN);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+BFD length",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_BFD_LEN);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+my discriminator",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_MYID);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+your discriminator",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_YID);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+dm and interval",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_DIAG_STA_DM_INTERVAL);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+real working interval",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_WORK_INTERVAL);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+LSP label",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_LSP_LABEL);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+PW label",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_PW_LABEL);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+ACH label",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_ACH_LABEL);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+timer down count",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_TIMER_DOWN_COUNT);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+remote down count",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_REMOTE_DOWN_COUNT);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+interval modify flag",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_INTERVAL_MODIFY);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+send count",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_SEND_COUNT);
                }
            }
            BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "+bfd adapt model",
                BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FPGA_BFD_ADAPT_BASE);
            if(level > 2)
            {
                BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "|+all",
                    BFD_PRT_FPGA_ADDR_OFFSET_LEN, 0);
                if(level > 3)
                {
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+SMAC",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FGAP_BFD_ADAPT_SMAC);
                    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*x\n", BFD_PRT_FPGA_ADDR_OFFSET_NAME_LEN, "||+sysport",
                        BFD_PRT_FPGA_ADDR_OFFSET_LEN, BFD_FGAP_BFD_ADAPT_SYSPORT);
                }
            }
        }
    }
    

    return;
}

/*****************************************************************************
 * 函 数 名  : hw_print_fpga
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 打印指定位置的FPGA寄存器内容
 * 输入参数  : IN unsigned long base_offset  FPGA模块基地址偏移
               IN unsigned int offset        地址偏移值
 * 输出参数  : OUT unsigned short *data      数据
 * 返 回 值  : RESULT_BFDCFG                 错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG hw_print_fpga(IN unsigned long base_offset, IN unsigned long offset, IN unsigned int num)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned long counter = 0;
    unsigned long addr = 0;
    unsigned short buf = 0;
    
    if (num == 0)
    {
        num = 128;
    }

    for (counter = 0; counter < num; counter++)
    {
        if (0 == (counter % 8))
        {
            addr = (base_offset + (counter + offset));
            BFD_LOG(BFD_SHELL_INFO, "0x%08lx:  ", addr);
        }

        ret = read_fpga_mmap(base_offset, (offset + counter), &buf);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, read_fpga_mmap, ret);
        
        BFD_LOG(BFD_SHELL_INFO, "%04x  ", buf);
        if (!((counter + 1) % 8))
        {
            BFD_LOG(BFD_SHELL_INFO, "\n");
        }
    }
    BFD_LOG(BFD_SHELL_INFO, "\n");

    return ret;
}

void bfd_print_bfd_model_fpga(IN unsigned long offset, IN unsigned int num)
{
    hw_print_fpga(BFD_FPGA_BFD_MODEL_BASE , offset, num);
    
    return;
}

void bfd_print_bfd_adapt_fpga(IN unsigned long offset, IN unsigned int num)
{
    hw_print_fpga(BFD_FPGA_BFD_ADAPT_BASE , offset, num);
    
    return;
}

/*****************************************************************************
 * 函 数 名  : hw_write_fpga
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定位置的FPGA寄存器内容
 * 输入参数  : IN unsigned long base_offset  FPGA模块基地址偏移
               IN unsigned int offset        地址偏移值
               IN unsigned short data        数据
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG                 错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG hw_write_fpga(IN unsigned long base_offset, IN unsigned long offset, IN unsigned short data)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        ret = write_fpga_mmap(base_offset, offset, data);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, write_fpga_mmap, ret);
    } while ( 0 ); /* 循环直到0不成立 */
    
    return ret;
}

/*****************************************************************************
 * 函 数 名  : hw_write_fpga_batch
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 批量设置指定位置的FPGA寄存器内容
 * 输入参数  : IN unsigned long base_offset  FPGA模块基地址偏移
               IN unsigned long addr         需要修改的首地址
               IN unsigned long addr_off     地址的偏移值
               IN unsigned short data        数据
               IN unsigned short date_off    数据的偏移值
               IN unsigned short num         数量
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG                 错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG hw_write_fpga_batch(IN unsigned long base_offset,
    IN unsigned long addr,
    IN unsigned long addr_off,
    IN unsigned short data,
    IN unsigned short date_off,
    IN unsigned short num)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short loop = 0;

    /* 循环写入 */
    for (loop = 0; loop < num; loop++)
    {
        ret = write_fpga_mmap(base_offset, addr + addr_off * loop, data + date_off * loop);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, write_fpga_mmap, ret);
    }

    return ret;
}


int bfd_write_bfd_model_fpga(IN unsigned long offset, IN unsigned short data)
{
    int ret = 0;
    ret = hw_write_fpga(BFD_FPGA_BFD_MODEL_BASE, offset, data);
    
    return ret;
}

int bfd_write_bfd_adapt_fpga(IN unsigned long offset, IN unsigned short data)
{
    int ret = 0;
    ret = hw_write_fpga(BFD_FPGA_BFD_ADAPT_BASE, offset, data);
    
    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_show_fpga_by_index
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月11日
 * 函数功能  : 根据数组下标打印FPGA内容
 * 输入参数  : IN unsigned short index    数组下标
               IN char *head_name         表格头名称
               IN NBB_BOOL not_need_head  是否不需要头，TRUE=不需要头，FALSE=需要头
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_fpga_by_index(IN unsigned short index)
{
    do
    {
        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BFD_SHELL_CRIT, "index:%u is too big,max is %u\n", index, BFD_MAX_SESNUM);
            break;
        }

        /* 打印头 */
        bfd_show_fpga_head_by_index(index, "FPGA INFO", FALSE);

        /* 打印BFD功能参数 */
        bfd_show_fpga_function_by_index(index, TRUE);

        /* 打印ITMH头中的sysport */
        bfd_show_fpga_sysport_by_index(index, TRUE);
        
        /* 打印MAC地址 */
        bfd_show_fpga_mac_by_index(index, TRUE);
        
        /* 打印标签 */
        bfd_show_fpga_label_by_index(index, TRUE);

        /* 打印IP头 */
        bfd_show_fpga_ip_by_index(index, TRUE);

        /* 打印UDP头 */
        bfd_show_fpga_udp_by_index(index, TRUE);

        /* 打印BFD的描述符 */
        bfd_show_fpga_discr_by_index(index, TRUE);

        /* 打印BFD状态和时间间隔 */
        bfd_show_fpga_state_interval_by_index(index, TRUE);
    }while(0);

    return;
}

void bfd_show_fpga_by_myid(IN unsigned long bfd_sid)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short index = 0;

    do
    {
        ret = bfd_find_array(bfd_sid, &index);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, bfd_find_array, ret);
        bfd_show_fpga_by_index(index);
    }while(0);

    return;

}

/*****************************************************************************
 * 函 数 名  : bfd_show_fpga_head_by_index
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月11日
 * 函数功能  : 根据数组下标打印FPGA内容的表格头
 * 输入参数  : IN unsigned short index    数组下标
               IN char *head_name         表格头名称
               IN NBB_BOOL not_need_head  是否不需要头，TRUE=不需要头，FALSE=需要头
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_fpga_head_by_index(IN unsigned short index, IN char *head_name, IN NBB_BOOL not_need_head)
{
    unsigned long  key = 0;
    BFD_DISCR discr;

    do
    {
        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BFD_SHELL_CRIT, "index:%u is too big,max is %u\n", index, BFD_MAX_SESNUM);
            break;
        }
        
        if(NULL == head_name)
        {
            BFD_LOG(BFD_SHELL_CRIT, "head_name is NULL\n");
            break;
        }
        
        if(FALSE == not_need_head)
        {
            BFD_LOG(BFD_SHELL_INFO, "---------index:%-*u--------%-*s-------------\n",
                BFD_PRT_FPGA_INDEX_LEN, index,
                BFD_PRT_FPGA_INFO_HEAD_NAME_LEN, head_name);
            BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*s  %-*s\n", BFD_PRT_FPGA_INFO_NAME_LEN, "name",
                BFD_PRT_FPGA_INFO_DATA_LEN, "local", BFD_PRT_FPGA_INFO_DATA_LEN, "fpga");

            bfd_get_specify_fpga_database_key(index, &key);

            /* 获取FGPA中的本地描述符 */
            bfd_get_fpga_bfd_discr(index, &discr);
            
            BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*lu  %-*lu\n", BFD_PRT_FPGA_INFO_NAME_LEN, "key",
                BFD_PRT_FPGA_INFO_DATA_LEN, key, BFD_PRT_FPGA_INFO_DATA_LEN, discr.my_id);
        }
    }while(0);
    
    return;
}


/*****************************************************************************
 * 函 数 名  : bfd_show_fpga_ip_by_index
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月11日
 * 函数功能  : 根据数组下标打印FPGA内容的IP头
 * 输入参数  : IN unsigned short index    数组下标
               IN char *head_name         表格头名称
               IN NBB_BOOL not_need_head  是否不需要头，TRUE=不需要头，FALSE=需要头
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_fpga_ip_by_index(IN unsigned short index, IN NBB_BOOL not_need_head )
{
    BFD_FPGA_INFO fpga_info;
    BFD_IP_HEAD ip_head;
    RESULT_BFDCFG ret = CFG_OK;

    do
    {
        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BFD_SHELL_CRIT, "index:%u is too big, max is %u\n", index,BFD_MAX_SESNUM);
            break;
        }

        OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
        OS_MEMSET(&ip_head, 0, sizeof(ip_head));
       
        /* 获取本地数据 */
        bfd_get_specify_array_info(index, &fpga_info);

        /* 获取FPGA数据 */
        ret = bfd_get_fpga_ip(index, &ip_head);
        BFD_CHECK_FUNC_RETURN_NO_BREAK(BFD_SHELL_NOTICE, bfd_get_fpga_ip, ret);

        switch ( ip_head.type )
        {
            case BFD_IPV4:
                /* 打印头 */
                bfd_show_fpga_head_by_index(index, "IPv4", not_need_head);

                /* 打印IPv4数据 */
                bfd_print_fpga_ipv4(&(fpga_info.send_cfg.ip), &ip_head);
                
                break;
            case BFD_IPV6 :
                /* 打印头 */
                bfd_show_fpga_head_by_index(index, "IPv4", not_need_head);

                /* 打印IPv6数据 */
                bfd_print_fpga_ipv6(&(fpga_info.send_cfg.ip), &ip_head);
                
                break;
            case BFD_IP_NONE:   /* 没有获取到IP类型，按IPv6的类型打印 */
                /* 打印头 */
                bfd_show_fpga_head_by_index(index, "IP NONE", not_need_head);

                /* 打印IPv6数据 */
                bfd_print_fpga_ipv6(&(fpga_info.send_cfg.ip), &ip_head);
                
                break;
            default:
                BFD_LOG(BFD_SHELL_WARNING, "ip type:%u is wrong!\n", ip_head.type);
        }
        BFD_CHECK_RETURN(ret);
    }while(0);

    return;
}


void bfd_show_fpga_ip_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short index = 0;

    do
    {
        ret = bfd_find_array(bfd_sid, &index);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, bfd_find_array, ret);
        bfd_show_fpga_ip_by_index(index, not_need_head);
    } while ( 0 );

    return;

}


/*****************************************************************************
 * 函 数 名  : bfd_print_fpga_ipv4
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年12月2日
 * 函数功能  : 打印IPv4头
 * 输入参数  : IN BFD_IP_HEAD *ip_head_local  本地存储的IP头
               IN BFD_IP_HEAD *ip_head_fpga   FPGA中的IP头
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_print_fpga_ipv4(IN BFD_IP_HEAD *ip_head_local, IN BFD_IP_HEAD *ip_head_fpga)
{
    unsigned char ip_local[4];
    unsigned char ip_fpga[4];

    do
    {
        if(NULL == ip_head_local)
        {
            BFD_LOG(BFD_SHELL_CRIT, "ip_head_local is NULL\n");
            break;
        }
        
        if(NULL == ip_head_fpga)
        {
            BFD_LOG(BFD_SHELL_CRIT, "ip_head_fpga is NULL\n");
            break;
        }
        
        OS_MEMSET(ip_local, 0, sizeof(ip_local));
        OS_MEMSET(ip_fpga, 0, sizeof(ip_fpga));

        /* 打印TOS */
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "tos",
            BFD_PRT_FPGA_INFO_DATA_LEN, ip_head_local->tos,
            BFD_PRT_FPGA_INFO_DATA_LEN, ip_head_fpga->tos);
        
        /* 打印源ip */
        BFD_GET_UCHAR_FORM_ULONG(ip_head_local->local_ip[3], ip_local[0], ip_local[1], ip_local[2], ip_local[3]);
        BFD_GET_UCHAR_FORM_ULONG(ip_head_fpga->local_ip[3], ip_fpga[0], ip_fpga[1], ip_fpga[2], ip_fpga[3]);
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %3u.%3u.%3u.%3u%*s  %3u.%3u.%3u.%3u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "local ipv4",
            ip_local[0], ip_local[1], ip_local[2], ip_local[3],
            BFD_PRT_FPGA_INFO_DATA_LEN - 15, " ",   /* 补空格 */
            ip_fpga[0], ip_fpga[1], ip_fpga[2], ip_fpga[3]);

        /* 打印目的ip */
        BFD_GET_UCHAR_FORM_ULONG(ip_head_local->remote_ip[3],ip_local[0], ip_local[1], ip_local[2], ip_local[3]);
        BFD_GET_UCHAR_FORM_ULONG(ip_head_fpga->remote_ip[3],ip_fpga[0], ip_fpga[1], ip_fpga[2], ip_fpga[3]);
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %3u.%3u.%3u.%3u%*s  %3u.%3u.%3u.%3u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "remote ipv4",
            ip_local[0], ip_local[1], ip_local[2], ip_local[3],
            BFD_PRT_FPGA_INFO_DATA_LEN - 15, " ",   /* 补空格 */
            ip_fpga[0], ip_fpga[1], ip_fpga[2], ip_fpga[3]);
    }while(0);

    return;
}

/*****************************************************************************
 * 函 数 名  : bfd_print_fpga_ipv6
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年12月2日
 * 函数功能  : 打印IPv6头
 * 输入参数  : IN BFD_IP_HEAD *ip_head_local  本地存储的IP头
               IN BFD_IP_HEAD *ip_head_fpga   FPGA中的IP头
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_print_fpga_ipv6(IN BFD_IP_HEAD *ip_head_local, IN BFD_IP_HEAD *ip_head_fpga)
{
    unsigned short ipv6_addr_local[8];
    unsigned short ipv6_addr_fpga[8];

    do
    {
        if(NULL == ip_head_local)
        {
            BFD_LOG(BFD_SHELL_CRIT, "ip_head_local is NULL\n");
            break;
        }
        
        if(NULL == ip_head_fpga)
        {
            BFD_LOG(BFD_SHELL_CRIT, "ip_head_fpga is NULL\n");
            break;
        }

        OS_MEMSET(ipv6_addr_local, 0, sizeof(ipv6_addr_local));
        OS_MEMSET(ipv6_addr_fpga, 0, sizeof(ipv6_addr_fpga));
        
        /*打印源ip*/
        BFD_GET_USHORT_FORM_ULONG(ip_head_local->local_ip[0], ipv6_addr_local[0], ipv6_addr_local[1]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_local->local_ip[1], ipv6_addr_local[2], ipv6_addr_local[3]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_local->local_ip[2], ipv6_addr_local[4], ipv6_addr_local[5]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_local->local_ip[3], ipv6_addr_local[6], ipv6_addr_local[7]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_fpga->local_ip[0], ipv6_addr_fpga[0], ipv6_addr_fpga[1]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_fpga->local_ip[1], ipv6_addr_fpga[2], ipv6_addr_fpga[3]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_fpga->local_ip[2], ipv6_addr_fpga[4], ipv6_addr_fpga[5]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_fpga->local_ip[3], ipv6_addr_fpga[6], ipv6_addr_fpga[7]);
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %4x:%4x:%4x:%4x:%4x:%4x:%4x:%4x  %4x:%4x:%4x:%4x:%4x:%4x:%4x:%4x\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "local ipv6", 
            ipv6_addr_local[0], ipv6_addr_local[1], ipv6_addr_local[2], ipv6_addr_local[3], 
            ipv6_addr_local[4], ipv6_addr_local[5], ipv6_addr_local[6], ipv6_addr_local[7], 
            ipv6_addr_fpga[0], ipv6_addr_fpga[1], ipv6_addr_fpga[2], ipv6_addr_fpga[3], 
            ipv6_addr_fpga[4], ipv6_addr_fpga[5], ipv6_addr_fpga[6], ipv6_addr_fpga[7]);
        
        /* 打印目的ip */
        BFD_GET_USHORT_FORM_ULONG(ip_head_local->remote_ip[0], ipv6_addr_local[0], ipv6_addr_local[1]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_local->remote_ip[1], ipv6_addr_local[2], ipv6_addr_local[3]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_local->remote_ip[2], ipv6_addr_local[4], ipv6_addr_local[5]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_local->remote_ip[3], ipv6_addr_local[6], ipv6_addr_local[7]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_fpga->remote_ip[0], ipv6_addr_fpga[0], ipv6_addr_fpga[1]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_fpga->remote_ip[1], ipv6_addr_fpga[2], ipv6_addr_fpga[3]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_fpga->remote_ip[2], ipv6_addr_fpga[4], ipv6_addr_fpga[5]);
        BFD_GET_USHORT_FORM_ULONG(ip_head_fpga->remote_ip[3], ipv6_addr_fpga[6], ipv6_addr_fpga[7]);
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %4x:%4x:%4x:%4x:%4x:%4x:%4x:%4x  %4x:%4x:%4x:%4x:%4x:%4x:%4x:%4x\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "remote ipv6", 
            ipv6_addr_local[0], ipv6_addr_local[1], ipv6_addr_local[2], ipv6_addr_local[3], 
            ipv6_addr_local[4], ipv6_addr_local[5], ipv6_addr_local[6], ipv6_addr_local[7], 
            ipv6_addr_fpga[0], ipv6_addr_fpga[1], ipv6_addr_fpga[2], ipv6_addr_fpga[3], 
            ipv6_addr_fpga[4], ipv6_addr_fpga[5], ipv6_addr_fpga[6], ipv6_addr_fpga[7]);
    }while(0);

    return;
}

/*****************************************************************************
 * 函 数 名  : bfd_show_fpga_udp_by_index
 * 负 责 人  : qyliu,刘权毅
 * 创建日期  : 2016年11月11日
 * 函数功能  : 根据数组下标打印FPGA内容的UDP头
 * 输入参数  : IN unsigned short index    数组下标
               IN char *head_name         表格头名称
               IN NBB_BOOL not_need_head  是否不需要头，TRUE=不需要头，FALSE=需要头
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_fpga_udp_by_index(IN unsigned short index, IN NBB_BOOL not_need_head )
{
    BFD_FPGA_INFO fpga_info;
    BFD_UDP_HEAD udp;

    do
    {
        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BFD_SHELL_CRIT, "index:%u is too big, max is %u\n", index, BFD_MAX_SESNUM);
            break;
        }

        OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
        OS_MEMSET(&udp, 0, sizeof(udp));

        /* 打印头 */
        bfd_show_fpga_head_by_index(index, "UDP", not_need_head);

        /* 获取本地数据 */
        bfd_get_specify_array_info(index, &fpga_info);

        /* 获取FPGA数据 */
        bfd_get_fpga_udp(index, &udp);

        /* 打印udp */
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "src_port",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.udp.src_port,
            BFD_PRT_FPGA_INFO_DATA_LEN, udp.src_port);
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "udp_len",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.udp.udp_len,
            BFD_PRT_FPGA_INFO_DATA_LEN, udp.udp_len);
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "data_len",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.udp.data_len,
            BFD_PRT_FPGA_INFO_DATA_LEN, udp.data_len);
    }while(0);

    return;
}


void bfd_show_fpga_udp_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short index = 0;

    do
    {
        ret = bfd_find_array(bfd_sid, &index);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, bfd_find_array, ret);
        bfd_show_fpga_udp_by_index(index, not_need_head);
    }while(0);

    return;

}

 
/*****************************************************************************
* 函 数 名  : bfd_show_fpga_state_interval_by_index
* 负 责 人  : qyliu,刘权毅
* 创建日期  : 2016年11月11日
* 函数功能  : 根据数组下标打印FPGA内容的BFD状态和时间间隔
* 输入参数  : IN unsigned short index    数组下标
            IN char *head_name         表格头名称
            IN NBB_BOOL not_need_head  是否不需要头，TRUE=不需要头，FALSE=需要头
* 输出参数  : 无
* 返 回 值  : void                       无
* 调用关系  : 
* 其    它  : 

*****************************************************************************/
void bfd_show_fpga_state_interval_by_index(IN unsigned short index, IN NBB_BOOL not_need_head )
{
    BFD_FPGA_INFO fpga_info;
    BFD_FPGA_REG_STATE_DIAG sta_diag_stu;
    BFD_FPGA_REG_INTERVAL interval_stu;

    do
    {
        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BFD_SHELL_CRIT, "index:%u is too big, max is %u\n", index,BFD_MAX_SESNUM);
            break;
        }

        OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
        OS_MEMSET(&sta_diag_stu, 0, sizeof(sta_diag_stu));
        OS_MEMSET(&interval_stu, 0, sizeof(interval_stu));

        /* 打印头 */
        bfd_show_fpga_head_by_index(index, "interval", not_need_head);

        /* 获取本地数据 */
        bfd_get_specify_array_info(index, &fpga_info);

        /* 获取BFD状态和收发包时间参数 */
        bfd_get_fpga_state_interval(index, &sta_diag_stu, &interval_stu);

       /* 打印BFD状态、down原因 */
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "diag",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.state.diag,
            BFD_PRT_FPGA_INFO_DATA_LEN, sta_diag_stu.usDiag);
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "state",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.state.state,
            BFD_PRT_FPGA_INFO_DATA_LEN, sta_diag_stu.usSta);
        
        /* 打印interval */
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "min_tx",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.interval.desired_min_tx_interval,
            BFD_PRT_FPGA_INFO_DATA_LEN, interval_stu.usTxInterval);
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "min_rx",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.interval.required_min_rx_interval,
            BFD_PRT_FPGA_INFO_DATA_LEN, interval_stu.usRxInterval);
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "mult",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.interval.detect_mult,
            BFD_PRT_FPGA_INFO_DATA_LEN, sta_diag_stu.usDectMult);
    }while(0);

    return;
}
 
 
void bfd_show_fpga_state_interval_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short index = 0;

    do
    {
        ret = bfd_find_array(bfd_sid, &index);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, bfd_find_array, ret);
        bfd_show_fpga_state_interval_by_index(index, not_need_head);
    }while(0);

    return;

}


/*****************************************************************************
 * 函 数 名  : bfd_show_fpga_mac_by_index
 * 负 责 人  : qyliu,刘权毅
 * 创建日期  : 2016年11月11日
 * 函数功能  : 根据数组下标打印FPGA内容的BFD MAC地址
 * 输入参数  : IN unsigned short index    数组下标
               IN char *head_name         表格头名称
               IN NBB_BOOL not_need_head  是否不需要头，TRUE=不需要头，FALSE=需要头
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_fpga_mac_by_index(IN unsigned short index, IN NBB_BOOL not_need_head)
{
    BFD_FPGA_INFO  fpga_info;
    BFD_ETH_MAC eth_mac;
    unsigned short fpga_reg_index = 0;

    do
    {
        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BFD_SHELL_CRIT, "index:%u is too big,max is %u\n", index, BFD_MAX_SESNUM);
            break;
        }

        OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
        OS_MEMSET(&eth_mac, 0, sizeof(eth_mac));

        /* 打印头 */
        bfd_show_fpga_head_by_index(index, "MAC", not_need_head);

        /* 获取本地数据 */
        bfd_get_specify_array_info(index, &fpga_info);

        /* 获取FPGA数据 */
        bfd_get_fpga_mac(index, &eth_mac, &fpga_reg_index);

        /* 打印目的MAC */
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %02x:%02x:%02x:%02x:%02x:%02x%*s  %02x:%02x:%02x:%02x:%02x:%02x\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "des mac",
            fpga_info.send_cfg.eth_mac.des_mac[0], fpga_info.send_cfg.eth_mac.des_mac[1],
            fpga_info.send_cfg.eth_mac.des_mac[2], fpga_info.send_cfg.eth_mac.des_mac[3],
            fpga_info.send_cfg.eth_mac.des_mac[4], fpga_info.send_cfg.eth_mac.des_mac[5],
            BFD_PRT_FPGA_INFO_DATA_LEN - 17, " ",       /* 补空格 */
            eth_mac.des_mac[0], eth_mac.des_mac[1], eth_mac.des_mac[2],
            eth_mac.des_mac[3], eth_mac.des_mac[4], eth_mac.des_mac[5]);

        /* 打印源MAC */        
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %02x:%02x:%02x:%02x:%02x:%02x%*s  %02x:%02x:%02x:%02x:%02x:%02x\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "src mac",
            fpga_info.send_cfg.eth_mac.src_mac[0], fpga_info.send_cfg.eth_mac.src_mac[1],
            fpga_info.send_cfg.eth_mac.src_mac[2], fpga_info.send_cfg.eth_mac.src_mac[3],
            fpga_info.send_cfg.eth_mac.src_mac[4], fpga_info.send_cfg.eth_mac.src_mac[5],
            BFD_PRT_FPGA_INFO_DATA_LEN - 17, " ",       /* 补空格 */
            eth_mac.src_mac[0], eth_mac.src_mac[1], eth_mac.src_mac[2],
            eth_mac.src_mac[3], eth_mac.src_mac[4], eth_mac.src_mac[5]);

        /* 打印FPGA源MAC中填的index */
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "index in mac",
            BFD_PRT_FPGA_INFO_DATA_LEN, index,
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_reg_index);
    }while(0);
    
    return;
}

void bfd_show_fpga_mac_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short index = 0;

    do
    {
        ret = bfd_find_array(bfd_sid, &index);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, bfd_find_array, ret);
        bfd_show_fpga_mac_by_index(index, not_need_head);
    }while(0);

    return;
}


/*****************************************************************************
 * 函 数 名  : bfd_show_fpga_discr_by_index
 * 负 责 人  : qyliu,刘权毅
 * 创建日期  : 2016年11月11日
 * 函数功能  : 根据数组下标打印FPGA内容的BFD 描述符
 * 输入参数  : IN unsigned short index    数组下标
               IN char *head_name         表格头名称
               IN NBB_BOOL not_need_head  是否不需要头，TRUE=不需要头，FALSE=需要头
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_fpga_discr_by_index(IN unsigned short index, IN NBB_BOOL not_need_head )
{
    BFD_FPGA_INFO fpga_info;
    BFD_DISCR discr;

    do
    {
        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BFD_SHELL_CRIT, "index:%u is too big, max is %u\n", index,BFD_MAX_SESNUM);
            break;
        }

       OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
       OS_MEMSET(&discr, 0, sizeof(discr));

        /* 打印头 */
        bfd_show_fpga_head_by_index(index, "DISCR", not_need_head);

        /* 获取本地数据 */
        bfd_get_specify_array_info(index, &fpga_info);

        /* 获取FPGA数据 */
        bfd_get_fpga_bfd_discr(index, &discr);

        /* 打印discr */
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*lu  %-*lu\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "my_id",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.discr.my_id,
            BFD_PRT_FPGA_INFO_DATA_LEN, discr.my_id);
        
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*lu  %-*lu\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "peer_id",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.discr.peer_id,
            BFD_PRT_FPGA_INFO_DATA_LEN, discr.peer_id);

    }while(0);

    return;
}


void bfd_show_fpga_discr_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short index = 0;

    do
    {
        ret = bfd_find_array(bfd_sid, &index);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, bfd_find_array, ret);
        bfd_show_fpga_discr_by_index(index, not_need_head);
    }while(0);

    return;

}


/*****************************************************************************
 * 函 数 名  : bfd_show_fpga_label_by_index
 * 负 责 人  : qyliu,刘权毅
 * 创建日期  : 2016年11月11日
 * 函数功能  : 根据数组下标打印FPGA内容的标签
 * 输入参数  : IN unsigned short index    数组下标
               IN char *head_name         表格头名称
               IN NBB_BOOL not_need_head  是否不需要头，TRUE=不需要头，FALSE=需要头
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_fpga_label_by_index(IN unsigned short index, IN NBB_BOOL not_need_head)
{
    BFD_FPGA_INFO  fpga_info;
    BFD_FPGA_MPLS_LABEL label;

    do
    {
        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BFD_SHELL_CRIT, "index:%u is too big,max is %u\n", index, BFD_MAX_SESNUM);
            break;
        }

        OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
        OS_MEMSET(&label, 0, sizeof(label));
        
        /* 打印头 */
        bfd_show_fpga_head_by_index(index, "LABEL", not_need_head);

        /* 获取本地数据 */
        bfd_get_specify_array_info(index, &fpga_info);

        /* 获取FPGA中的标签 */
        bfd_get_fpga_label(index, &label);
        
        /* 打印外层标签 */
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*lu  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "lsp label",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.label.lsp_label,
            BFD_PRT_FPGA_INFO_DATA_LEN, label.lsp_label.ulMplsLabel);
                
        /* 打印内层标签 */
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*lu  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "pw label",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.label.pw_label,
            BFD_PRT_FPGA_INFO_DATA_LEN, label.pw_label.ulMplsLabel);
        
        /* 打印ACH标签 */
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-#*lx  %-#*lx\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "ach label",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.label.ach,
            BFD_PRT_FPGA_INFO_DATA_LEN, label.ach);
    }while(0);
    
    return;
}

void bfd_show_fpga_label_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short index = 0;

    do
    {
        ret = bfd_find_array(bfd_sid, &index);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, bfd_find_array, ret);
        bfd_show_fpga_label_by_index(index, not_need_head);
    }while(0);

    return;
}


/*****************************************************************************
 * 函 数 名  : bfd_show_fpga_sysport_by_index
 * 负 责 人  : qyliu,刘权毅
 * 创建日期  : 2016年11月11日
 * 函数功能  : 根据数组下标打印FPGA内容的sysport
 * 输入参数  : IN unsigned short index    数组下标
               IN char *head_name         表格头名称
               IN NBB_BOOL not_need_head  是否不需要头，TRUE=不需要头，FALSE=需要头
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_fpga_sysport_by_index(IN unsigned short index, IN NBB_BOOL not_need_head )
{
    BFD_FPGA_INFO  fpga_info;
    BFD_SYSPORT sysport;

    do
    {
        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BFD_SHELL_CRIT, "index:%u is too big, max is %u\n", index,BFD_MAX_SESNUM);
            break;
       }

       OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
       OS_MEMSET(&sysport, 0, sizeof(sysport));

        /* 打印头 */
        bfd_show_fpga_head_by_index(index, "sysport", not_need_head);

        /* 获取本地数据 */
        bfd_get_specify_array_info(index, &fpga_info);

        /* 获取FPGA数据 */
        bfd_get_fpga_sysport(index, &sysport);

        /* 打印sysport */
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "sysport",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.sysport.des_fapid,
            BFD_PRT_FPGA_INFO_DATA_LEN, sysport.des_fapid);

    }while(0);

    return;
}


void bfd_show_fpga_sysport_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short index = 0;

    do
    {
        ret = bfd_find_array(bfd_sid, &index);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, bfd_find_array, ret);
        bfd_show_fpga_sysport_by_index(index, not_need_head);
    }while(0);

    return;

}


/*****************************************************************************
 * 函 数 名  : bfd_show_fpga_function_by_index
 * 负 责 人  : qyliu,刘权毅
 * 创建日期  : 2016年11月11日
 * 函数功能  : 根据数组下标打印FPGA内容的功能参数
 * 输入参数  : IN unsigned short index    数组下标
               IN char *head_name         表格头名称
               IN NBB_BOOL not_need_head  是否不需要头，TRUE=不需要头，FALSE=需要头
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_fpga_function_by_index(IN unsigned short index, IN NBB_BOOL not_need_head )
{
    BFD_FPGA_INFO  fpga_info;
    BFD_FPGA_REG_FUCTION fuction_info;

    do
    {
        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BFD_SHELL_CRIT, "index:%u is too big, max is %u\n", index,BFD_MAX_SESNUM);
            break;
        }

       OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
       OS_MEMSET(&fuction_info, 0, sizeof(BFD_FPGA_REG_FUCTION));

        /* 打印头 */
        bfd_show_fpga_head_by_index(index, "function", not_need_head);

        /* 获取本地数据 */
        bfd_get_specify_array_info(index, &fpga_info);

        /* 获取FPGA中BFD功能内容 */
        bfd_get_fpga_function(index, &fuction_info);

        /* 打印function */
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "sendflag",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.function.send_flag,
            BFD_PRT_FPGA_INFO_DATA_LEN, fuction_info.usSendFlag);
        
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "dec_type",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.function.detection_type,
            BFD_PRT_FPGA_INFO_DATA_LEN, fuction_info.usUDPtype);
        
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "vlan_able",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.function.vlan_able,
            BFD_PRT_FPGA_INFO_DATA_LEN, fuction_info.usVlanAble);
        
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "vlan_num",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.function.vlan_num,
            BFD_PRT_FPGA_INFO_DATA_LEN, fuction_info.usVlanNum);
        
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*s  %-*s\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "pw ach",
            BFD_PRT_FPGA_INFO_DATA_LEN, ((0 == fpga_info.send_cfg.function.pw_type) ? "0x10000007" : "0x10000022"),
            BFD_PRT_FPGA_INFO_DATA_LEN, ((0 == fuction_info.usPWtype) ? "0x10000007" : "0x10000022"));
        
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*u  %-*u\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "frame type",
            BFD_PRT_FPGA_INFO_DATA_LEN, fpga_info.send_cfg.frame_type,
            BFD_PRT_FPGA_INFO_DATA_LEN, fuction_info.usSendType);
        
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*s  %-*s\n",
            BFD_PRT_FPGA_INFO_NAME_LEN, "ip type",
            BFD_PRT_FPGA_INFO_DATA_LEN, ((0 == fpga_info.send_cfg.ip.type) ? "IPv4" : "IPv6"),
            BFD_PRT_FPGA_INFO_DATA_LEN, ((0 == fuction_info.usIpType) ? "IPv4" : "IPv6"));

    }while(0);

    return;
}


void bfd_show_fpga_function_by_myid(IN unsigned long bfd_sid, IN NBB_BOOL not_need_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short index = 0;

    do
    {
        ret = bfd_find_array(bfd_sid, &index);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, bfd_find_array, ret);
        
        bfd_show_fpga_function_by_index(index, not_need_head);
    }while(0);

    return;

}

/*****************************************************************************
 * 函 数 名  : bfd_show_state_by_index
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月17日
 * 函数功能  : 根据数组下标打印BFD的状态
 * 输入参数  : IN unsigned short start_index  起始条目号
               IN unsigned short end_index    结束条目号
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_state_by_index(IN unsigned short start_index, IN unsigned short end_index)
{
    unsigned short index = 0;
    BFD_FPGA_INFO fpga_info;
    BFD_FPGA_REG_STATE_DIAG sta_diag_stu;
    BFD_FPGA_REG_INTERVAL interval_stu;
    BFD_FPGA_REG_DIAG_STATE diag_state;
    unsigned long fpga_work_rmri = 0;
    unsigned short fpga_work_dmti = 0;
    unsigned short fpga_cfg_rmri = 0;
    unsigned short fpga_cfg_dmti = 0;
    unsigned short local_cfg_tx = 0;
    unsigned short local_cfg_rx = 0;

    /* 收发包间隔的本地记录方式与实际值的映射表 */
    char *lpszInterval[] = {"None",      /* 收发包技术的记录从1开始，此处定义忽略0号位 */
                                "3.3", "10", "20", "30", "40", "50", "60", "70", "80", "90", "100",
                                "200", "300", "400", "500", "150", "250", "350", "450", "1000"};
    char *lpszSta[] = {"Admin", "Down", "Init", "Up"};

    NBB_USHORT interval_num = sizeof(lpszInterval) / 4;    /* 指针数组，取出来的长度是数组个数*4字节 */

    do
    {
        /* 入参判断 */
        if ((end_index > BFD_MAX_SESNUM) || (start_index > BFD_MAX_SESNUM))
        {
            BFD_LOG(BFD_SHELL_CRIT, "Please check input,start_index:%u or end_index:%u is too big,max is %u\n",
                start_index, end_index, BFD_MAX_SESNUM);
            break;
        }

        OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
        OS_MEMSET(&sta_diag_stu, 0, sizeof(sta_diag_stu));
        OS_MEMSET(&interval_stu, 0, sizeof(interval_stu));
        OS_MEMSET(&diag_state, 0, sizeof(diag_state));

        /* 输出表格头 */
        BFD_LOG(BFD_SHELL_INFO, "     | State info   |           |           |          Working info           |       fpga  cfg      |"
        "    local cfg   \n");
        BFD_LOG(BFD_SHELL_INFO, "Loop |--------------|   MyDrim  |  YourDrim |---------------------------------|----------------------|"
            "----------------\n");
        BFD_LOG(BFD_SHELL_INFO, "     | state | diag |           |           | alarm | rxinterval | txinterval | rmri | dmti | pfflag |"
            "  tx |  rx | dm \n");   
        BFD_LOG(BFD_SHELL_INFO, "-----|-------|------|-----------|-----------|-------|------------|------------|------|------|--------|"
            "-----|-----|----\n");
        /* 循环输出内容 */
        for (index = start_index; index < end_index; index++)
        {
            /* 获取BFD状态和收发包时间参数 */
            bfd_get_fpga_state_interval(index, &sta_diag_stu, &interval_stu);

            fpga_cfg_rmri = interval_stu.usRxInterval;
            fpga_cfg_dmti = interval_stu.usTxInterval;

            bfd_get_fpga_session_state(index, &diag_state);
            bfd_get_fpga_session_work_interval(index, &fpga_work_rmri);
            bfd_get_fpga_send_work_interval(index, &fpga_work_dmti);
                        
            /* 获取本地数据 */
            bfd_get_specify_array_info(index, &fpga_info);

            local_cfg_tx = fpga_info.send_cfg.interval.desired_min_tx_interval;
            local_cfg_rx = fpga_info.send_cfg.interval.required_min_rx_interval;

            /* 越界检查 */        
            if(fpga_work_dmti >= interval_num)
            {
                fpga_work_dmti = 0;    /* 强制指定非法值 */
                BFD_LOG(BFD_SHELL_ERR, "Working info txinterval error, value = %u", fpga_work_dmti);
            }
            if(fpga_cfg_rmri >= interval_num)
            {
                fpga_cfg_rmri = 0;    /* 强制指定非法值 */
                BFD_LOG(BFD_SHELL_ERR, "FPGA config rmri error, value = %u", fpga_cfg_rmri);
            }
            if(fpga_cfg_dmti >= interval_num)
            {
                fpga_cfg_dmti = 0;    /* 强制指定非法值 */
                BFD_LOG(BFD_SHELL_ERR, "FPGA config dmti error, value = %u", fpga_cfg_dmti);
            }
            if(local_cfg_tx >= interval_num)
            {
                local_cfg_tx = 0;    /* 强制指定非法值 */
                BFD_LOG(BFD_SHELL_ERR, "Local config dmti error, value = %u", local_cfg_tx);
            }
            if(local_cfg_rx >= interval_num)
            {
                local_cfg_rx = 0;    /* 强制指定非法值 */
                BFD_LOG(BFD_SHELL_ERR, "Local config rmri error, value = %u", local_cfg_rx);
            }
            
            BFD_LOG(BFD_SHELL_INFO, "%4u |%6s |%5d |%10lu |%10lu |%6u |%11lu |%11s |%5s |%5s |%7u |%4s |%4s |%3u \n",
                index, lpszSta[sta_diag_stu.usSta], sta_diag_stu.usDiag,
                fpga_info.send_cfg.discr.my_id, fpga_info.send_cfg.discr.peer_id,
                diag_state.timer_alarm, fpga_work_rmri, lpszInterval[fpga_work_dmti],
                lpszInterval[fpga_cfg_rmri], lpszInterval[fpga_cfg_dmti], interval_stu.usModify,
                lpszInterval[local_cfg_tx], lpszInterval[local_cfg_rx], fpga_info.send_cfg.interval.detect_mult);
        }
    }while(0);
    
    return;
}


/*****************************************************************************
 * 函 数 名  : bfd_show_state_by_myid
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月17日
 * 函数功能  : 根据BFD本地描述符打印BFD的状态
 * 输入参数  : IN unsigned long bfd_sid  BFD本地描述符
 * 输出参数  : 无
 * 返 回 值  : void                      无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_state_by_myid(IN unsigned long bfd_sid)
{
    RESULT_BFDCFG result = CFG_OK;
    unsigned short index = 0;

    do
    {
        result = bfd_find_array(bfd_sid, &index);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, bfd_find_array, result);
        
        bfd_show_state_by_index(index, index + 1);

    }while(0);
    
    return;
}

/*****************************************************************************
 * 函 数 名  : bfd_show_counter_by_index
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月17日
 * 函数功能  : 根据数组下标打印BFD的收发包计数
 * 输入参数  : IN unsigned short start_index  起始条目号
               IN unsigned short end_index    结束条目号
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
NBB_VOID bfd_show_counter_by_index(IN unsigned short start_index, IN unsigned short end_index)
{
    unsigned short index = 0;
    BFD_DISCR discr;
    unsigned short sent_count = 0;
    unsigned short recv_count = 0;

    do
    {
        /* 入参判断 */
        if ((end_index > BFD_MAX_SESNUM) || (start_index > BFD_MAX_SESNUM))
        { 
            BFD_LOG(BFD_SHELL_CRIT, "Please check input,start_index:%u or end_index:%u is too big,max is %u\n",
                start_index, end_index, BFD_MAX_SESNUM);
            break;
        }

        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-*s  %-*s  %-*s  %-*s\n", BFD_PRT_FPGA_INDEX_LEN, "index",
            BFD_PRT_BFD_ID_LEN, "my id", BFD_PRT_BFD_ID_LEN, "your id",
            BFD_PRT_FPGA_COUNT_DATA_LEN, "tx", BFD_PRT_FPGA_COUNT_DATA_LEN, "rx");

        /* 循环输出 */
        for (index = start_index; index < end_index; index++)
        {
            bfd_get_fpga_bfd_discr(index, &discr);
            
            bfd_get_fpga_send_count(index, &sent_count);
            bfd_get_fpga_session_recv_count(index, &recv_count);    /* 收包计数 */
            
            BFD_LOG(BFD_SHELL_INFO, "%-*u  %-*lu  %-*lu  %-*u  %-*u\n", BFD_PRT_FPGA_INDEX_LEN, index,
                BFD_PRT_BFD_ID_LEN, discr.my_id, BFD_PRT_BFD_ID_LEN, discr.peer_id,
                BFD_PRT_FPGA_COUNT_DATA_LEN, sent_count, BFD_PRT_FPGA_COUNT_DATA_LEN, recv_count);
        }
    }while(0);
    return;
}

/*****************************************************************************
 * 函 数 名  : bfd_show_counter_by_myid
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月17日
 * 函数功能  : 根据BFD本地描述符打印BFD的收发包计数
 * 输入参数  : IN unsigned long bfd_sid  BFD本地描述符
 * 输出参数  : 无
 * 返 回 值  : void                      无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_counter_by_myid(IN unsigned long bfd_sid)
{
    RESULT_BFDCFG result = CFG_OK;
    unsigned short index = 0;

    do
    {
        result = bfd_find_array(bfd_sid, &index);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, bfd_find_array, result);
        
        bfd_show_counter_by_index(index, index + 1);

    }while(0);
    
    return;
}


/*****************************************************************************
 * 函 数 名  : bfd_show_anti_attack_info
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月17日
 * 函数功能  : 根据数组下标打印BFD的防攻击信息
 * 输入参数  : IN unsigned short start_index  起始条目号
               IN unsigned short end_index    结束条目号
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_anti_attack_info_by_index(IN unsigned short start_index, IN unsigned short end_index)
{
    unsigned short index = 0;
    BFD_FPGA_REG_STATE_DIAG sta_diag_stu;
    BFD_FPGA_REG_INTERVAL interval_stu;
    unsigned long your_id = 0;
    unsigned short enable = 0;
    BFD_FPGA_INFO fpga_info;
    RESULT_BFDCFG ret = CFG_OK;
    NBB_CHAR *lpszSta[] = {"AdminD","Down","Init","Up"};    

    do
    {
        /* 入参判断 */
        if ((end_index > BFD_MAX_SESNUM) || (start_index > BFD_MAX_SESNUM))
        { 
            BFD_LOG(BFD_SHELL_CRIT, "Please check input,start_index:%u or end_index:%u is too big,max is %u\n",
                start_index, end_index, BFD_MAX_SESNUM);
            break;
        }

        /* 输出表格头 */
        BFD_LOG(BFD_SHELL_INFO, "     |         |           |  State info  |       Anti-Attack       |\n");
        BFD_LOG(BFD_SHELL_INFO, "Loop | MyDiscr | YourDiscr |--------------|-------------------------|\n");
        BFD_LOG(BFD_SHELL_INFO, "     |         |           | state | diag |    Discr  | Anti_Enable |\n");   
        BFD_LOG(BFD_SHELL_INFO, "-----|---------|-----------|-------|------|-----------|-------------|\n");

        /* 循环输出 */
        for (index = start_index; index < end_index; index++)
        {
            ret = bfd_get_specify_array_info(index, &fpga_info);

            /* 获取BFD状态和收发包时间参数 */
            bfd_get_fpga_state_interval(index, &sta_diag_stu, &interval_stu);

            /* 获取FPGA防攻击信息 */
            bfd_get_fpga_session_anti_attack(index, &your_id, &enable);

            BFD_LOG(BFD_SHELL_INFO, "%4d |%8lu |%10lu |%6s |%5d |%10ld |%12s |\n", index, fpga_info.send_cfg.discr.my_id,
                fpga_info.send_cfg.discr.peer_id, lpszSta[sta_diag_stu.usSta], sta_diag_stu.usDiag,
                your_id, (enable == 1) ? "ENABLE" : "DISABLE");
        }
    }while(0);
    return;
}

/*****************************************************************************
 * 函 数 名  : bfd_show_anti_attack_info_by_myid
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月17日
 * 函数功能  : 根据BFD本地描述符打印BFD的防攻击信息
 * 输入参数  : IN unsigned long bfd_sid  BFD本地描述符
 * 输出参数  : 无
 * 返 回 值  : void                      无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_anti_attack_info_by_myid(IN unsigned long bfd_sid)
{
    RESULT_BFDCFG result = CFG_OK;
    unsigned short index = 0;

    do
    {
        result = bfd_find_array(bfd_sid, &index);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, bfd_find_array, result);
        
        bfd_show_anti_attack_info_by_index(index, index + 1);

    }while(0);
    
    return;
}


void bfd_print_alarm_head()
{
    BFD_LOG(BFD_SHELL_INFO, "%-*s  %-s\n", BFD_PRT_BFD_ID_LEN, "MyDrim", "alarm:down,remote down");
    return;
}

RESULT_BFDCFG bfd_print_alarm_data(BFD_ALARM_DATABASE *alarm_data)
{
    RESULT_BFDCFG ret = CFG_OK;
    do
    {
        if(NULL == alarm_data)
        {
            ret = PARAM_ERROR;
            break;
        }
        
        BFD_LOG(BFD_SHELL_INFO, "%-*lu  %-u,%-u\n", BFD_PRT_BFD_ID_LEN, alarm_data->my_sid,
            alarm_data->alarm.down, alarm_data->alarm.remote_down);

        ret = CFG_OK;
    }while(0);
    
    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_show_alarm
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月17日
 * 函数功能  : 根据BFD本地描述符打印BFD的告警信息
 * 输入参数  : IN unsigned long bfd_sid  BFD本地描述符
 * 输出参数  : 无
 * 返 回 值  : void                      无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_alarm(IN unsigned long bfd_sid)
{
    RESULT_BFDCFG result = CFG_OK;
    BFD_ALARM_DATABASE *alarm_data = NULL;

    do
    {
        result = bfd_find_alarm_database(bfd_sid, &alarm_data);
        if(CFG_OK != result)
        {
            BFD_LOG(BFD_SHELL_WARNING, "bfd_find_alarm_database return %d\n", result);
            break;
        }

        if(NULL == alarm_data)
        {
            BFD_LOG(BFD_SHELL_WARNING, "bfd_sid = %ld is not existed!\n", bfd_sid);
            break;
        }

        /* 打印头 */
        bfd_print_alarm_head();

        /* 打印数据 */
        bfd_print_alarm_data(alarm_data);

    }while(0);
    
    return;
}

void bfd_show_all_alarm()
{
    /* 打印头 */
    bfd_print_alarm_head();
    
    /* 轮询打印数据 */
    bfd_traverse_alarm_database(bfd_print_alarm_data);

    return;
}

RESULT_BFDCFG bfd_print_cfg(BFD_CFG_DATABASE* cfg)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if(NULL == cfg)
        {
            BFD_LOG(BFD_SHELL_CRIT, "cfg is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        BFD_LOG(BFD_SHELL_INFO, "--------------------------------------------\n");
        
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-lu\n", BFD_PRT_CFG_NAME_LEN, "myid", cfg->my_sid);

        ret = bfd_analyze_bfd_cfg(&(cfg->cfg_data), BFD_SHELL_INFO);
        
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "fpga index", cfg->fpga_index);
        BFD_LOG(BFD_SHELL_INFO, "%-*s  %-d\n", BFD_PRT_CFG_NAME_LEN, "arad index", cfg->arad_index);

        BFD_LOG(BFD_SHELL_INFO, "--------------------------------------------\n");
    } while ( 0 ); /* 循环直到0不成立 */

    return ret;
}


/*****************************************************************************
 * 函 数 名  : bfd_show_cfg
 * 负 责 人  : qyliu,刘权毅
 * 创建日期  : 2016年11月14日
 * 函数功能  : 根据BFD的my_sid打印BFD的配置
 * 输入参数  : my_sid
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_cfg(IN unsigned long my_sid)
{

    RESULT_BFDCFG ret = CFG_OK;
    BFD_CFG_DATABASE *cfg = NULL;
            
    
    do /* 开始循环 */
    {
        ret = bfd_find_cfg_database(my_sid, &cfg);
        BFD_CHECK_FUNC_RETURN_BREAK(BFD_SHELL_WARNING, bfd_find_cfg_database, ret)

        if(NULL == cfg)
        {
            BFD_LOG(BFD_SHELL_WARNING, "cfg is NULL\n");
            break;
        }
        
        ret = bfd_print_cfg(cfg);

    } while ( 0 ); /* 循环直到0不成立 */

    return;
}

void bfd_show_all_cfg()
{
    bfd_traverse_cfg_database(bfd_print_cfg);

    return;
}

/*****************************************************************************
 * 函 数 名  : bfd_show_oam_cfg_info
 * 负 责 人  : qyliu,刘权毅
 * 创建日期  : 2016年11月17日
 * 函数功能  : 根据BFD的my_sid和bfd_frame_type打印业务配置
 * 输入参数  : my_sid, bfd_frame_type, bfd_frame_type:2/3=lsp/pw
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_oam_cfg_info (IN unsigned long my_sid, IN unsigned char bfd_frame_type)
{
    TP_OAM_LSP_CFG oam_traffic_info ;
    int result = CFG_OK;

    OS_MEMSET(&oam_traffic_info, 0, sizeof(oam_traffic_info));

    result = oam_get_traffic_info(my_sid, bfd_frame_type, &oam_traffic_info);
    
    if(CFG_OK != result)
    {
        BFD_LOG(BFD_SHELL_WARNING, "TP_OAM_ERROR:oam_get_traffic_info get traffic info error\n");
    }

    oam_traffic_info_print(&oam_traffic_info, BFD_SHELL_INFO);

    return;
}


/*****************************************************************************
 * 函 数 名  : bfd_show_oam_bfd_cfg_info
 * 负 责 人  : qyliu,刘权毅
 * 创建日期  : 2016年11月17日
 * 函数功能  : 根据BFD的my_sid打印业务配置
 * 输入参数  : my_sid
 * 输出参数  : 无
 * 返 回 值  : void                       无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_show_oam_bfd_cfg_info (IN unsigned long my_sid)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_CFG_DATABASE *cfg_data = NULL;

    do
    {
        ret = bfd_find_cfg_database(my_sid, &cfg_data);
        if(CFG_OK != ret)
        {
            BFD_LOG(BFD_SHELL_WARNING, "bfd_find_cfg_database return %d\n", ret);
            break;
        }
        
        if(NULL == cfg_data)
        {
            BFD_LOG(BFD_SHELL_WARNING, "cfg_data is NULL\n");
            break;
        }
        
        bfd_show_oam_cfg_info(my_sid, cfg_data->cfg_data.base_cfg.cfg.bfd_frame_type);
    }while(0);
    
    return;
}

/*****************************************************************************
 * 函 数 名  : bfd_set_fpga_loop
 * 负 责 人  : 蒋博,jiangbo
 * 创建日期  : 2016-11-18
 * 函数功能  : 设置FPGA的BFD模块环回
 * 输入参数  : NBB_BOOL flag  0=不环回，其他=环回
 * 输出参数  : 无
 * 返 回 值  : void           无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void bfd_set_fpga_loop(NBB_BOOL flag)
{
    if (flag)
    {
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_RCV_LOOP, 0, 1);
    }
    else
    {
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_RCV_LOOP, 0, 0);
    }

    return;
}

void bfd_set_fpga_capture_packet(unsigned char directon)
{
    BFD_LOG(BFD_SHELL_INFO, "set FPGA capture packet\n");
    switch ( directon ) /* 判断匹配条件type */
    {
        case 0 :
            BFD_LOG(BFD_SHELL_INFO, "0: ""help\n");
            BFD_LOG(BFD_SHELL_INFO, "1: ""BFD adapt model to BFD model\n");
            BFD_LOG(BFD_SHELL_INFO, "2: ""BFD adapt model to GE\n");
            BFD_LOG(BFD_SHELL_INFO, "3: ""GE to BFD adapt model\n");
            break;
        case 1 :
            BFD_LOG(BFD_SHELL_INFO, "BFD adapt model to BFD model\n");
            spm_oamtree_s16write(BFD_FPGA_GENERAL_BASE, 0, BFD_FPGA_PACKET_CAPTURE_CHOOSE,
                BFD_FPGA_PACKET_CAPTURE_CHOOSE_BFD_RX);
            break;
        case 2 :
            BFD_LOG(BFD_SHELL_INFO, "BFD adapt model to GE\n");
            spm_oamtree_s16write(BFD_FPGA_GENERAL_BASE, 0, BFD_FPGA_PACKET_CAPTURE_CHOOSE,
                BFD_FPGA_PACKET_CAPTURE_CHOOSE_BFD_ADAPT_TX);
            break;
        case 3 :
            BFD_LOG(BFD_SHELL_INFO, "GE to BFD adapt model\n");
            spm_oamtree_s16write(BFD_FPGA_GENERAL_BASE, 0, BFD_FPGA_PACKET_CAPTURE_CHOOSE,
                BFD_FPGA_PACKET_CAPTURE_CHOOSE_GE_TX);
            break;
        default:
            BFD_LOG(BFD_SHELL_NOTICE, "unknown directon:%u\n", directon);
    }
    
    return;
}


void bfd_show_fpga_capture_packet()
{
    unsigned short cap_choose = 0;
    
    bfd_get_fpga_capture_choose(&cap_choose);
        
    BFD_LOG(BFD_SHELL_INFO, "read FPGA capture packet\n");
    switch ( cap_choose ) /* 判断匹配条件data */
    {
        case BFD_FPGA_PACKET_CAPTURE_CHOOSE_BFD_RX :
            BFD_LOG(BFD_SHELL_INFO, "BFD adapt model to BFD model\n");
            break;
        case BFD_FPGA_PACKET_CAPTURE_CHOOSE_BFD_ADAPT_TX :
            BFD_LOG(BFD_SHELL_INFO, "BFD adapt model to GE\n");
            break;
        case BFD_FPGA_PACKET_CAPTURE_CHOOSE_GE_TX :
            BFD_LOG(BFD_SHELL_INFO, "GE to BFD adapt model\n");
            break;
        default:
            BFD_LOG(BFD_SHELL_NOTICE, "unknown directon:%#x\n", cap_choose);
    }

    /* 捕获一个包 */
    spm_oamtree_s16write(BFD_FPGA_BFD_ETH_ANALYSER_BASE, 0, 0x8, 0x1);
    spm_oamtree_s16write(BFD_FPGA_BFD_ETH_ANALYSER_BASE, 0, 0x8, 0x0);
    spm_oamtree_s16write(BFD_FPGA_BFD_ETH_ANALYSER_BASE, 0, 0x10, 0x0);
        
    hw_print_fpga(BFD_FPGA_BFD_ETH_ANALYSER_BASE, 0x100, 128);
    return;
}


NBB_VOID bfd_wlog()
{
    BFD_LOG(BMU_CRIT, "bfd model sync msg log in memory to file!\n");
    return;
}



RESULT_BFDCFG bfd_analyze_bfd_set_arad(IN drv_udf_key_t *key, IN drv_udf_action_t *action, IN int level)
{
    RESULT_BFDCFG ret = CFG_OK;

    do
    {
        if(NULL == key)
        {
            BFD_LOG(level, "cfg is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "inport",  key->inport);/*localport*/
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "mirror_type_flag",  key->mirror_type_flag);/*localport*/
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "entryprio",  key->entryprio);/*entry优先级，默认值0；
                                                                                                值越大优先级越高*/
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "pw",  key->pw);/*pwlable*/
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "pw_lif",  key->pw_lif);/*pwlable*/
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "tunnel",  key->tunnel);/*tunnellable*/
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "ach",  key->ach);/*oamach*/
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "igmp_vlannum",  key->igmp_vlannum);
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "iptype",  key->iptype[0], 
            key->iptype[1], key->iptype[2],key->iptype[3]);
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "iptype_mask",  key->iptype_mask[0], 
            key->iptype_mask[1], key->iptype_mask[2], key->iptype_mask[3]);
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "igmpver",  key->igmpver[0], 
            key->igmpver[1], key->igmpver[2], key->igmpver[3]);
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "igmpver_mask",  key->igmpver_mask[0], 
            key->igmpver_mask[1], key->igmpver_mask[2], key->igmpver_mask[3]);
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "channel_type",  key->channel_type[0], 
            key->channel_type[1], key->channel_type[2], key->channel_type[3]);
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "channel_type_mask",  key->channel_type_mask[0],
            key->channel_type_mask[1], key->channel_type_mask[2], key->channel_type_mask[3]);
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "OpCode",  key->OpCode[0], 
            key->OpCode[1], key->OpCode[2], key->OpCode[3]);
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "OpCode_mask",  key->OpCode_mask[0], 
            key->OpCode_mask[1], key->OpCode_mask[2], key->OpCode_mask[3]);
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "id_sub_type",  key->id_sub_type[0], 
            key->id_sub_type[1], key->id_sub_type[2], key->id_sub_type[3]);
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "id_sub_type_mask",  key->id_sub_type_mask[0], 
            key->id_sub_type_mask[1], key->id_sub_type_mask[2], key->id_sub_type_mask[3]);
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "node_id",  key->node_id[0], 
            key->node_id[1], key->node_id[2], key->node_id[3]);
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "node_id_mask",  key->node_id_mask[0], 
            key->node_id_mask[1], key->node_id_mask[2], key->node_id_mask[3]);
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "vlan_id",  key->vlan_id);
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "ethertype",  key->ethertype);/*ETHERNETOAM断业务*/
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "subtype",  key->subtype[0], 
            key->subtype[1], key->subtype[2], key->subtype[3]);/*EFMSUBTYPE*/
        BFD_LOG(level, "%-*s  %u.%u.%u.%u\n", BFD_PRT_CFG_NAME_LEN, "subtype_mask",  key->subtype_mask[0], 
            key->subtype_mask[1], key->subtype_mask[2], key->subtype_mask[3]);/*EFMSUBTYPEmask*/
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "redirect_port",  key->redirect_port);/*重定向端口,localport*/
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "redirect_dest_port",  key->redirect_dest_port);/*镜像端口，localport*/
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "redirect_dest_modid",  key->redirect_dest_modid);/*镜像单盘modid*/
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "mirror_dest_port",  key->mirror_dest_port);/*镜像端口，localport*/
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "mirror_dest_modid",  key->mirror_dest_modid);/*镜像单盘modid*/


        if(NULL == action)
        {
            BFD_LOG(level, "cfg is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "DropFlag",  action->DropFlag);
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "RedirectFlag",  action->RedirectFlag);
        BFD_LOG(level, "%-*s  %-u\n", BFD_PRT_CFG_NAME_LEN, "MirrorFlag",  action->MirrorFlag);

    }while ( 0 );

    return ret;

}

