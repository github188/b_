/***********************************************************************************

 * 文 件 名   : bfd_fpga.c
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年10月14日
 * 版 本 号   : 
 * 文件描述   : BFD FPGA相关配置
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#include "bfd.h"

/* FPGA使用的全局变量，BFD程序运行中一直有效 */
BFD_FPGA_GLOBAL g_bfd_fpga_global;

/*****************************************************************************
 * 函 数 名  : bfd_init_fpga
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 初始化FPGA数据
 * 输入参数  : 无
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_init_fpga()
{
    unsigned short bfd_tree_node_max_num = 0;
    int result = 0;
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        /* 获取FPGA基地址 */
        g_bfd_fpga_global.fpga_base_mcard = ptn_fpga_base_addr_get();
        
        g_bfd_fpga_global.bfd_my_id_tree.level = BFD_TREE_LEVEL;
        bfd_tree_node_max_num = (1 << g_bfd_fpga_global.bfd_my_id_tree.level);
        g_bfd_fpga_global.bfd_my_id_tree.lsp_no_max = bfd_tree_node_max_num - 1;

        /* 分配内存并初始化 */
        g_bfd_fpga_global.bfd_my_id_tree.tree_base = 
            (BFD_PUL_TREE_BASE)malloc(sizeof(NBB_ULONG) * g_bfd_fpga_global.bfd_my_id_tree.level);
        if (NULL == g_bfd_fpga_global.bfd_my_id_tree.tree_base)
        {
            BFD_LOG(BMU_ERR, "bfd tree malloc error\n");
            ret = ALLOC_ERROR;
            break;
        }
        OS_MEMSET(g_bfd_fpga_global.bfd_my_id_tree.tree_base, 0,
            sizeof(NBB_ULONG) * g_bfd_fpga_global.bfd_my_id_tree.level);
        
        /* 二叉树初始化 */    
        result = spm_oamtree_init(bfd_tree_node_max_num, spm_bfd_tree_get_fpga_data,
            &g_bfd_fpga_global.bfd_my_id_tree.node_set);
        if (OK != result)
        {
            BFD_LOG(BMU_ERR, "Bfd node set error, nodenum = %d\n", bfd_tree_node_max_num);
            ret = FPGA_MYID_TREE;
            break;
        }
    } while ( 0 ); /* 循环直到0不成立 */
    
    return ret;
}

/*****************************************************************************
 * 函 数 名  : oam_fpga_32bits_write
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月15日
 * 函数功能  : 写FPGA数据(16位写)
 * 输入参数  : IN unsigned long fpga_base_addr  FPGA基地址
               IN unsigned long fpga_offset     地址偏移
               IN unsigned long data            要写入的数据
 * 输出参数  : 无
 * 返 回 值  : int                              错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
int oam_fpga_16bits_write(IN unsigned long fpga_base_addr, IN unsigned long fpga_offset, IN unsigned short data)
{
    *(unsigned short *)(fpga_base_addr + (fpga_offset << 1)) = data;
    return SUCCESS;
}

/*****************************************************************************
 * 函 数 名  : oam_fpga_32bits_write
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月15日
 * 函数功能  : 写FPGA数据(32位写)
 * 输入参数  : unsigned long fpga_base_addr  FPGA基地址
               unsigned long fpga_offset     地址偏移
               unsigned long data            要写入的数据
 * 输出参数  : 无
 * 返 回 值  : int                           错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
int oam_fpga_32bits_write(unsigned long fpga_base_addr, unsigned long fpga_offset, unsigned long data)
{
    *(unsigned long *)(fpga_base_addr + (fpga_offset << 2)) = data;
    return SUCCESS;
}

/*****************************************************************************
 * 函 数 名  : oam_fpga_16bits_read
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月15日
 * 函数功能  : 读取FPGA内容(16位读取)
 * 输入参数  : IN unsigned long fpga_base_addr  FPGA基地址
               IN unsigned long fpga_offset     FPGA地址偏移
 * 输出参数  : 无
 * 返 回 值  : unsigned long                    错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
unsigned short oam_fpga_16bits_read(IN unsigned long fpga_base_addr, IN unsigned long fpga_offset)
{
    unsigned short data = 0;
    data = *(unsigned short *)(fpga_base_addr + (fpga_offset << 1));
    return data;
}

/*****************************************************************************
 * 函 数 名  : oam_fpga_32bits_read
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月15日
 * 函数功能  : 读取FPGA内容(32位读取)
 * 输入参数  : IN unsigned long fpga_base_addr  FPGA基地址
               IN unsigned long fpga_offset     FPGA地址偏移
 * 输出参数  : 无
 * 返 回 值  : unsigned long                    获取到的指定地址的值
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
unsigned long oam_fpga_32bits_read(IN unsigned long fpga_base_addr, IN unsigned long fpga_offset)
{
    unsigned long data = 0;
    data = *(unsigned long *)(fpga_base_addr + (fpga_offset << 2));
    return data;
}


/*****************************************************************************
 * 函 数 名  : write_fpga_mmap
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定位置的FPGA寄存器内容(16位写)
 * 输入参数  : IN unsigned long base_offset  FPGA模块基地址偏移
               IN unsigned int offset        地址偏移值
               IN unsigned short data        数据
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG                 错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG write_fpga_mmap(IN unsigned long base_offset, IN unsigned int offset, IN unsigned short data)
{
    RESULT_BFDCFG ret = CFG_OK;

    do
    {
        BFD_CHECK_PARAM_MAX(BMU_ERR, base_offset, BFD_FPGA_BFD_ETH_MAX_BASE, "%lu", "%u", ret);
        oam_fpga_16bits_write(g_bfd_fpga_global.fpga_base_mcard + base_offset, offset, data);
    }while(0);
    
    return ret;
}

/*****************************************************************************
 * 函 数 名  : write_fpga_mmap_32b
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定位置的FPGA寄存器内容(32位写)
 * 输入参数  : IN unsigned long base_offset  FPGA模块基地址偏移
               IN unsigned int offset        地址偏移值
               IN unsigned long data         数据
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG                 错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG write_fpga_mmap_32b(IN unsigned long base_offset, IN unsigned int offset, IN unsigned long data)
{
    RESULT_BFDCFG ret = CFG_OK;

    do
    {
        BFD_CHECK_PARAM_MAX(BMU_ERR, base_offset, BFD_FPGA_BFD_ETH_MAX_BASE, "%lu", "%u", ret);
        oam_fpga_32bits_write(g_bfd_fpga_global.fpga_base_mcard + base_offset, offset, data);
    }while(0);
    
    return ret;
}

/*****************************************************************************
 * 函 数 名  : read_fpga_mmap
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 读取指定位置的FPGA寄存器内容(16位)
 * 输入参数  : IN unsigned long base_offset  FPGA模块基地址偏移
               IN unsigned int offset        地址偏移值
 * 输出参数  : OUT unsigned short *data      数据
 * 返 回 值  : int                           错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG read_fpga_mmap(IN unsigned long base_offset, IN unsigned long offset, OUT unsigned short *data)
{
    RESULT_BFDCFG ret = CFG_OK;

    do
    {
        BFD_CHECK_PARAM_MAX(BMU_ERR, base_offset, BFD_FPGA_BFD_ETH_MAX_BASE, "%lu", "%u", ret);
        *data = oam_fpga_16bits_read(g_bfd_fpga_global.fpga_base_mcard + base_offset, offset);

        ret = CFG_OK;
    }while(0);
    
    return ret;
}

/*****************************************************************************
 * 函 数 名  : read_fpga_mmap_32b
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 读取指定位置的FPGA寄存器内容(32位)
 * 输入参数  : IN unsigned long base_offset  FPGA模块基地址偏移
               IN unsigned int offset        地址偏移值
 * 输出参数  : OUT unsigned long *data       数据
 * 返 回 值  : RESULT_BFDCFG                 错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG read_fpga_mmap_32b(IN unsigned long base_offset, IN unsigned long offset, OUT unsigned long *data)
{
    RESULT_BFDCFG ret = CFG_OK;

    do
    {
        BFD_CHECK_PARAM_MAX(BMU_ERR, base_offset, BFD_FPGA_BFD_ETH_MAX_BASE, "%lu", "%u", ret);
        *data = oam_fpga_32bits_read(g_bfd_fpga_global.fpga_base_mcard + base_offset, offset);
    }while(0);
    
    return ret;
}

/*****************************************************************************
 * 函 数 名  : spm_bfd_tree_set_data
 * 负 责 人  : 蒋博,jiangbo
 * 创建日期  : 2015年7月21日
 * 函数功能  : BFD树的FPGA二叉树赋值
 * 输入参数  : IN NBB_USHORT index                    条目号
               IN NBB_ULONG ulDrim                    MY ID值
               OUT SPM_OAMTREE_NODE * pstBfdTreeNode  内存KEY值
 * 输出参数  : 无
 * 返 回 值  : NBB_INT  错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
NBB_INT spm_bfd_tree_set_data(IN NBB_USHORT index,
    IN NBB_ULONG ulDrim,
    OUT SPM_OAMTREE_NODE *pstBfdTreeNode)
{
    NBB_INT iRet = ERROR;

    do
    {
        if (NULL == pstBfdTreeNode)
        {
            iRet = ERROR;
            break;
        }

        OS_MEMSET(pstBfdTreeNode, 0, sizeof(SPM_OAMTREE_NODE));

        pstBfdTreeNode->usLspNo = index;
        pstBfdTreeNode->ulTunnelId = ulDrim;
        
        iRet = SUCCESS;
    }while(0);

    return iRet;
}

/*****************************************************************************
 * 函 数 名  : spm_bfd_tree_get_fpga_data
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月8日
 * 函数功能  : 根据KEY值获取FPGA二叉树的KEY值
 * 输入参数  : IN SPM_OAMTREE_NODE* oamTreeNode     内存KEY值
               OUT SPM_FPGATREE_DATA *fpgaTreeDate  FPGA二叉树KEY值
 * 输出参数  : 无
 * 返 回 值  : NBB_INT                              错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
NBB_INT spm_bfd_tree_get_fpga_data(IN SPM_OAMTREE_NODE* oamTreeNode,
    OUT SPM_FPGATREE_DATA *fpgaTreeDate)
{
    NBB_INT iRet = ERROR;

    do
    {
        if ((NULL == oamTreeNode) || (NULL == fpgaTreeDate))
        {
            iRet = ERROR;
            break;
        }
    
        OS_MEMSET(fpgaTreeDate, 0, sizeof(SPM_FPGATREE_DATA));

        fpgaTreeDate->num = 4;  /* 有效字节为4字节 */
        fpgaTreeDate->usData.bfdTable.index = oamTreeNode->usLspNo;
        fpgaTreeDate->usData.bfdTable.myId_31to28b = (oamTreeNode->ulTunnelId >> 28) & 0xf;
        fpgaTreeDate->usData.bfdTable.myId_27to20b = (oamTreeNode->ulTunnelId >> 20) & 0xff;
        fpgaTreeDate->usData.bfdTable.myId_19to0b = oamTreeNode->ulTunnelId & 0xfffff;

        iRet = SUCCESS;
    }while(0);

    return iRet;
}

/*****************************************************************************
 * 函 数 名  : spm_bfd_rebuild_session_tree_fpgareg
 * 负 责 人  : 蒋博,jiangbo
 * 创建日期  : 2015年9月23日
 * 函数功能  : 重建BFD二叉树
 * 输入参数  : 无
 * 输出参数  : 无
 * 返 回 值  : NBB_VOID  无
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
NBB_VOID spm_bfd_rebuild_session_tree_fpgareg()
{
    /* 重建会话二叉树 */
    spm_oamtree_build(g_bfd_fpga_global.bfd_my_id_tree.level, &g_bfd_fpga_global.bfd_my_id_tree.node_set, 
        g_bfd_fpga_global.bfd_my_id_tree.tree_base, BFD_FPGA_BFD_MODEL_BASE, BFD_FGPA_RCV_SESSION_TREE);
    
    /* 翻页写备表 */
    spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_REV_BASE, OAMTREESWITCHOFFSET, 1);
     
    spm_oamtree_build(g_bfd_fpga_global.bfd_my_id_tree.level, &g_bfd_fpga_global.bfd_my_id_tree.node_set, 
        g_bfd_fpga_global.bfd_my_id_tree.tree_base, BFD_FPGA_BFD_MODEL_BASE, BFD_FGPA_RCV_SESSION_TREE);

    spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_REV_BASE, OAMTREESWITCHOFFSET, 1);

    return;
}

/*****************************************************************************
 * 函 数 名  : bfd_add_fpga_session_tree
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月8日
 * 函数功能  : 增加FPGA使用的BFD MYID二叉树成员
 * 输入参数  : IN unsigned short index  数组下标
               IN unsigned long my_sid  BFD MYID
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_add_fpga_session_tree(IN unsigned short index, IN unsigned long my_sid)
{
    RESULT_BFDCFG ret= CFG_OK;
    int result = 0;
    SPM_OAMTREE_NODE bfd_tree_node;

    do
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        OS_MEMSET(&bfd_tree_node, 0, sizeof(bfd_tree_node));
        
        /* 得到FPGA二叉树的KEY */
        result = spm_bfd_tree_set_data(index, my_sid, &bfd_tree_node);
        if(OK != result)
        {
            ret = FPGA_MYID_TREE;
            break;
        }
        
        /* 加节点 */
        result = spm_oamtree_nodeadd(g_bfd_fpga_global.bfd_my_id_tree.lsp_no_max, &bfd_tree_node,
            &g_bfd_fpga_global.bfd_my_id_tree.node_set);
        if(OK != result)
        {
            ret = FPGA_MYID_TREE;
            break;
        }
        
        /* 建立会话二叉树 */
        spm_bfd_rebuild_session_tree_fpgareg();

        ret = CFG_OK;
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_del_fpga_session_tree
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月8日
 * 函数功能  : 删除FPGA使用的BFD MYID二叉树成员
 * 输入参数  : IN unsigned short index  FPGA数组下标
               IN unsigned long my_sid  BFD MYID
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_del_fpga_session_tree(IN unsigned short index, IN unsigned long my_sid)
{
    RESULT_BFDCFG ret= CFG_OK;
    int result = 0;
    SPM_OAMTREE_NODE bfd_tree_node;
    
    do
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        OS_MEMSET(&bfd_tree_node, 0, sizeof(bfd_tree_node));

        /* 得到FPGA二叉树的KEY */
        result = spm_bfd_tree_set_data(index, my_sid, &bfd_tree_node);
        if(OK != result)
        {
            ret = FPGA_MYID_TREE;
            break;
        }
            
        /* 删除节点 */
        result = spm_oamtree_nodedel(g_bfd_fpga_global.bfd_my_id_tree.lsp_no_max, &bfd_tree_node,
            &g_bfd_fpga_global.bfd_my_id_tree.node_set);
        if(OK != result)
        {
            ret = FPGA_MYID_TREE;
            break;
        }
                        
        /* 重建会话二叉树 */
        spm_bfd_rebuild_session_tree_fpgareg();
        
        ret = CFG_OK;
    }while(0);
        
    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_get_fpga_info
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 根据多项参数获取FPGA需要的信息
 * 输入参数  : IN unsigned short index              FPGA数组索引
               IN BFD_BASIC_DATA *cfg               BFD净配置
               IN TP_OAM_LSP_CFG *oam_traffic_info  LSP配置
 * 输出参数  : OUT BFD_FPGA_INFO *fpga_info         FPGA信息
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_info(IN unsigned short index, IN BFD_BASIC_DATA *cfg, IN TP_OAM_LSP_CFG *oam_traffic_info,
    OUT BFD_FPGA_INFO *fpga_info)
{
    RESULT_BFDCFG ret = CFG_OK;

    do
    {
        if (NULL == cfg)
        {
            BFD_LOG(BMU_ERR, "cfg is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (NULL == oam_traffic_info)
        {
            BFD_LOG(BMU_ERR, "oam_traffic_info is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (NULL == fpga_info)
        {
            BFD_LOG(BMU_ERR, "fpga_info is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(fpga_info, 0, sizeof(BFD_FPGA_INFO));

        fpga_info->index = index;

        switch ( cfg->bfd_frame_type ) /* BFD发帧类型 */
        {
            /* 如果是BFD_PW_type2，则需要 fpga_info->send_cfg.label.ach = 0x10000021; */
            
            case BFD_CFG_LSP:
                fpga_info->send_cfg.frame_type = BFD_PW_type1;
                fpga_info->send_cfg.label.pw_label = 13;    /* GAL标签值 */
                break;
            case BFD_CFG_PW :
                fpga_info->send_cfg.frame_type = BFD_PW_type1;
                fpga_info->send_cfg.label.pw_label = oam_traffic_info->OutPwLable;
                break;
            default:
                BFD_LOG(BMU_ERR, "do not support frame type:%u\n", cfg->bfd_frame_type);
                ret = PARAM_ERROR;
                break;
        }
        BFD_CHECK_RETURN(ret);

        fpga_info->send_cfg.label.lsp_label = oam_traffic_info->OutLspLable;
        
        fpga_info->send_cfg.function.send_flag = cfg->bfd_enable;
        fpga_info->send_cfg.function.detection_type = cfg->detect_method;
        fpga_info->send_cfg.function.vlan_able = TRUE;
        fpga_info->send_cfg.function.vlan_num = 0;
        fpga_info->send_cfg.function.pw_type = 1;
        
        fpga_info->send_cfg.discr.my_id = cfg->my_sid;
        fpga_info->send_cfg.discr.peer_id = cfg->peer_sid;

        fpga_info->send_cfg.interval.required_min_rx_interval = cfg->rmri;
        fpga_info->send_cfg.interval.desired_min_tx_interval = cfg->dmti;
        fpga_info->send_cfg.interval.detect_mult = cfg->dete_mul;

        fpga_info->send_cfg.state.diag = bfd_diag_no_diag;
        if (TRUE != cfg->bfd_enable)/* 发送不使能 */
        {
            fpga_info->send_cfg.state.state = BFD_ADMINDOWN;
        }
        else
        {
            fpga_info->send_cfg.state.state = BFD_DOWN;
        }

        fpga_info->send_cfg.ip.type = cfg->ip_type;
        fpga_info->send_cfg.ip.tos = cfg->service_type;
        fpga_info->send_cfg.ip.total_length = 52;
        OS_MEMCPY(fpga_info->send_cfg.ip.local_ip, cfg->local_ip, sizeof(fpga_info->send_cfg.ip.local_ip));
        OS_MEMCPY(fpga_info->send_cfg.ip.remote_ip, cfg->remote_ip, sizeof(fpga_info->send_cfg.ip.remote_ip));

        fpga_info->send_cfg.udp.src_port = cfg->udp_src_port;
        fpga_info->send_cfg.udp.udp_len = 32;
        fpga_info->send_cfg.udp.data_len = 24;
        
        OS_MEMCPY(fpga_info->send_cfg.eth_mac.des_mac, oam_traffic_info->des_mac_nni,
            sizeof(fpga_info->send_cfg.eth_mac.des_mac));
        OS_MEMCPY(fpga_info->send_cfg.eth_mac.src_mac, oam_traffic_info->src_mac_nni,
            sizeof(fpga_info->send_cfg.eth_mac.src_mac));
        
        fpga_info->send_cfg.sysport.des_fapid = oam_traffic_info->TxSysPortId;
        fpga_info->send_cfg.sysport.local_sysport = 164;

        ret = CFG_OK;
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_set_fpga
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置BFD FPGA寄存器
 * 输入参数  : IN BFD_FPGA_INFO *fpga_info  FPGA信息
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG                错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga(IN BFD_FPGA_INFO *fpga_info)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if(NULL == fpga_info)
        {
            BFD_LOG(BMU_ERR, "fpga_info is NULL\n");
            ret = PARAM_ERROR;
            break;
        }        

        /* 添加FPGA使用的BFD MYID会话二叉树成员 */
        ret = bfd_add_fpga_session_tree(fpga_info->index, fpga_info->send_cfg.discr.my_id);

        /* 写MAC地址 */
        ret = bfd_set_fpga_mac(fpga_info->index, &(fpga_info->send_cfg.eth_mac));

        /* 修改收发包时间参数和BFD状态 */
        ret = bfd_set_fpga_state_interval(fpga_info->index, &(fpga_info->send_cfg.state),
            &(fpga_info->send_cfg.interval), FALSE);

        /* 修改IP头 */
        ret = bfd_set_fpga_ip(fpga_info->index, &(fpga_info->send_cfg.ip));

        /* 修改UDP头 */
        ret = bfd_set_fpga_udp(fpga_info->index, &(fpga_info->send_cfg.udp));

        /* 修改BFD的描述符 */
        ret = bfd_set_fpga_bfd_discr(fpga_info->index, &(fpga_info->send_cfg.discr));

        /* 修改标签 */
        ret = bfd_set_fpga_label(fpga_info->index, fpga_info->send_cfg.frame_type, &(fpga_info->send_cfg.label));

        /* 修改BFD功能信息 */
        ret = bfd_set_fpga_function(fpga_info->index, fpga_info->send_cfg.frame_type, fpga_info->send_cfg.ip.type, 
            &(fpga_info->send_cfg.function));

        /* 修改ITMH头的sysport */
        ret = bfd_set_fpga_sysport(fpga_info->index, &(fpga_info->send_cfg.sysport));
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_set_fpga_mac
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定FPGA位置的BFD MAC地址
 * 输入参数  : IN unsigned short index  数组下标
               IN BFD_ETH_MAC *eth_mac  MAC地址
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_mac(IN unsigned short index, IN BFD_ETH_MAC *eth_mac)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned int i = 0;
    unsigned short data = 0;
    BFD_FPGA_REG_SMAC1 smac1;
    BFD_FPGA_REG_ADAPT_SMAC1 adapt_smac;

    do /* 开始循环 */
    {
        if(NULL == eth_mac)
        {
            BFD_LOG(BMU_ERR, "eth_mac is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(&smac1, 0, sizeof(smac1));
        OS_MEMSET(&adapt_smac, 0, sizeof(adapt_smac));

        for (i = 0; i < (MAC_LENGTH >> 1); i ++) /* 对变量i进行循环 */
        {
            data = (eth_mac->des_mac[i << 1] << 8) + eth_mac->des_mac[(i << 1) + 1];
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DMAC, 4 * index + i + 1, data);
        }

        
        /* 源MAC的SMAC[42:32]需要存到BFD适配模块，为了给重新填充源MAC用 */
        adapt_smac.smac = ((eth_mac->src_mac[0] & 0x7) << 8) + eth_mac->src_mac[1];  /* 取MAC地址的[42:32]比特 */
        data = *(unsigned short*)(&adapt_smac);
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FGAP_BFD_ADAPT_SMAC, index, data);

        /* 源MAC的SMAC[42:32]需要替换成数组索引，为了给FPGA的BFD适配模块填充sysport时查找用 */
        smac1.index = index;
        smac1.smac = (eth_mac->src_mac[0] >> 3) & 0x1f;  /* 取MAC地址的前5比特 */
        data = *(unsigned short*)(&smac1);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_SMAC, BFD_FPGA_MAC_HIGH(index), data);

        /* 源MAC的后4个字节是正常的MAC地址 */
        for (i = 1; i < (MAC_LENGTH >> 1); i ++) /* 对变量i进行循环 */
        {
            data = (eth_mac->src_mac[i << 1] << 8) + eth_mac->src_mac[(i << 1) + 1];
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_SMAC, 4 * index + i + 1, data);
        }
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

/*****************************************************************************
 * 函 数 名  : bfd_get_fpga_mac
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定FPGA位置的BFD MAC地址
 * 输入参数  : IN unsigned short index  数组下标
               IN BFD_ETH_MAC *eth_mac  MAC地址
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_mac(IN unsigned short index, OUT BFD_ETH_MAC *eth_mac, OUT unsigned short *fpga_reg_index)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data = 0;
    BFD_FPGA_REG_SMAC1 smac1;
    BFD_FPGA_REG_ADAPT_SMAC1 adapt_smac;

    do /* 开始循环 */
    {
        if(NULL == eth_mac)
        {
            BFD_LOG(BMU_ERR, "eth_mac is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(eth_mac, 0, sizeof(*eth_mac));
        OS_MEMSET(&smac1, 0, sizeof(smac1));
        OS_MEMSET(&adapt_smac, 0, sizeof(adapt_smac));

        /* 目的MAC */        
        data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DMAC, BFD_FPGA_MAC_HIGH(index));
        BFD_GET_UCHAR_FORM_USHORT(data, eth_mac->des_mac[0], eth_mac->des_mac[1]);
        data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DMAC, BFD_FPGA_MAC_MIDDLE(index));
        BFD_GET_UCHAR_FORM_USHORT(data, eth_mac->des_mac[2], eth_mac->des_mac[3]);
        data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DMAC, BFD_FPGA_MAC_LOW(index));
        BFD_GET_UCHAR_FORM_USHORT(data, eth_mac->des_mac[4], eth_mac->des_mac[5]);

        /* 源MAC */        
        data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_SMAC, BFD_FPGA_MAC_HIGH(index));
        smac1 = *(BFD_FPGA_REG_SMAC1*)(&data);
        *fpga_reg_index = smac1.index;
        data = spm_oamtree_s16read(BFD_FPGA_BFD_ADAPT_BASE, BFD_FGAP_BFD_ADAPT_SMAC, index);
        adapt_smac = *(BFD_FPGA_REG_ADAPT_SMAC1*)(&data);
        eth_mac->src_mac[0] = (smac1.smac << 3) | (adapt_smac.smac >> 8);
        eth_mac->src_mac[1] = adapt_smac.smac & 0xff;
        data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_SMAC, BFD_FPGA_MAC_MIDDLE(index));
        BFD_GET_UCHAR_FORM_USHORT(data, eth_mac->src_mac[2], eth_mac->src_mac[3]);
        data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_SMAC, BFD_FPGA_MAC_LOW(index));
        BFD_GET_UCHAR_FORM_USHORT(data, eth_mac->src_mac[4], eth_mac->src_mac[5]);        
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

/*****************************************************************************
 * 函 数 名  : bfd_set_fpga_state_interval
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定FPGA位置的BFD 状态和时间参数
 * 输入参数  : IN unsigned short index    数组下标
               IN BFD_STATE *state        BFD状态
               IN BFD_INTERVAL *interval  时间参数
               IN NBB_BOOL is_modify      是否修改
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG              错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_state_interval(IN unsigned short index, IN BFD_STATE *state,
    IN BFD_INTERVAL *interval, IN NBB_BOOL is_modify)
{
    NBB_USHORT   sta_diag_data = 0;
    NBB_USHORT   interval_data = 0;
    BFD_FPGA_REG_STATE_DIAG sta_diag_stu;
    BFD_FPGA_REG_INTERVAL interval_stu;

    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if(NULL == state)
        {
            BFD_LOG(BMU_ERR, "state is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == interval)
        {
            BFD_LOG(BMU_ERR, "interval is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        OS_MEMSET(&sta_diag_stu, 0, sizeof(sta_diag_stu));
        sta_diag_stu.usDiag = state->diag;
        sta_diag_stu.usSta = state->state;
        sta_diag_stu.usDectMult = interval->detect_mult;
        sta_diag_data = *(NBB_USHORT *)(&sta_diag_stu);
        
        /* BFD发送模块寄存器偏移0xd000+2*N+0x0：
           Bit15-11：BFD报文诊断码（Diag），表明发送方最近一次会话down的原因。
           Bit10-9：BFD当前会话状态（Sta），0-AdminDown，1-Down，2-Init，3-Up。
           Bit7-0：检测时间倍数（Detect Mult）。默认值为3 */
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DIAG_STA_DM_INTERVAL, BFD_FPGA_ULONG_HIGH(index),
            sta_diag_data);

        OS_MEMSET(&interval_stu, 0, sizeof(interval_stu));
        interval_stu.usRxInterval = interval->required_min_rx_interval;
        interval_stu.usTxInterval = interval->desired_min_tx_interval;
        interval_stu.usModify     = is_modify; /*填充 字节 无意义，20160513*/
        interval_data = *(NBB_USHORT *)(&interval_stu);
        
        /* BFD发送模块寄存器偏移0xd000+2*N+0x1：
           Bit0：上述2个间隔中任何一个需要被修改，由软件写'1'，启动投票进程。由FPGA内部清零。 */
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DIAG_STA_DM_INTERVAL, BFD_FPGA_ULONG_LOW(index),
            interval_data);

        /*Bit1-0：
           本端支持的最小发送间隔（Desired Min TX Interval）
           和本端支持的最小接收间隔（Required Min RX Interval）中任何一个需要被修改，
           由软件写'0b11'，启动投票进程。由FPGA内部清零。*/
        if(TRUE == is_modify)  /*FPGA自己优化调试完后，告知应用放开*/
        {
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_INTERVAL_MODIFY, index, 0x3);
        }

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

/*****************************************************************************
 * 函 数 名  : bfd_get_fpga_state_interval
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 获取指定FPGA位置的BFD 状态和时间参数
 * 输入参数  : IN unsigned short index              数组下标
 * 输出参数  : OUT BFD_FPGA_REG_STATE_DIAG *state   BFD状态
               OUT BFD_FPGA_REG_INTERVAL *interval  时间参数
 * 返 回 值  : RESULT_BFDCFG                        错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_state_interval(IN unsigned short index, OUT BFD_FPGA_REG_STATE_DIAG *state_diag,
    OUT BFD_FPGA_REG_INTERVAL *interval)
{
    NBB_USHORT   sta_diag_data = 0;
    NBB_USHORT   interval_data = 0;

    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        if(NULL == state_diag)
        {
            BFD_LOG(BMU_ERR, "state_diag is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == interval)
        {
            BFD_LOG(BMU_ERR, "interval is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        OS_MEMSET(state_diag, 0, sizeof(*state_diag));
        OS_MEMSET(interval, 0, sizeof(*interval));
        
        sta_diag_data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DIAG_STA_DM_INTERVAL,
            BFD_FPGA_ULONG_HIGH(index));
        *state_diag = *(BFD_FPGA_REG_STATE_DIAG *)(&sta_diag_data);
        
        interval_data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DIAG_STA_DM_INTERVAL,
            BFD_FPGA_ULONG_LOW(index));
        *interval = *(BFD_FPGA_REG_INTERVAL *)(&interval_data);

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}


/*****************************************************************************
 * 函 数 名  : bfd_set_fpga_ip
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定FPGA位置的BFD IP头
 * 输入参数  : IN unsigned short index  数组下标
               IN BFD_IP_HEAD *ip       IP头信息
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_ip(IN unsigned short index, IN BFD_IP_HEAD *ip)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if(NULL == ip)
        {
            BFD_LOG(BMU_ERR, "ip is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
                
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        switch ( ip->type )
        {
            case BFD_IPV4:
                bfd_set_fpga_ipv4(index,ip);
                break;
            case BFD_IPV6 :
                bfd_set_fpga_ipv6(index,ip);
                break;
            default:
                BFD_LOG(BMU_ERR, "ip type:%u is wrong!\n", ip->type);
                ret = PARAM_ERROR;
        }
        BFD_CHECK_RETURN(ret);
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

/*****************************************************************************
 * 函 数 名  : bfd_get_fpga_ip
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 获取指定FPGA位置的BFD IP头
 * 输入参数  : IN unsigned short index  数组下标
 * 输出参数  : OUT BFD_IP_HEAD *ip      IP头信息
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_ip(IN unsigned short index, OUT BFD_IP_HEAD *ip_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_FPGA_REG_IP_HEAD_VER_TOS ver_tos;
    unsigned short data = 0;

    do /* 开始循环 */
    {
        if(NULL == ip_head)
        {
            BFD_LOG(BMU_ERR, "ip_head is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
                
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(ip_head, 0, sizeof(*ip_head));
        OS_MEMSET(&ver_tos, 0, sizeof(ver_tos));
        
        data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPv4_TOS, index);
        ver_tos = *(BFD_FPGA_REG_IP_HEAD_VER_TOS *)(&data);
        
        ip_head->tos = ver_tos.tos;
        switch ( ver_tos.version )
        {
            case 4:
                bfd_get_fpga_ipv4(index, ip_head);
                ip_head->type = BFD_IPV4;
                break;
            case 6 :
                bfd_get_fpga_ipv6(index, ip_head);
                ip_head->type = BFD_IPV6;
                break;
            default:
                BFD_LOG(BMU_ERR, "ip version:%u is wrong!\n", ver_tos.version);

                /* IP类型识别不了，把IP相关的所有寄存器全取一遍 */
                bfd_get_fpga_ipv6(index, ip_head);
                ip_head->type = BFD_IP_NONE;
                
                ret = IP_TYPE_ERR;
        }
        BFD_CHECK_RETURN(ret);
        
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}


/*****************************************************************************
 * 函 数 名  : bfd_set_fpga_ipv4
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定FPGA位置的BFD IPv4头
 * 输入参数  : IN unsigned short index  数组下标
               IN BFD_IP_HEAD *ip       IP信息
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_ipv4(IN unsigned short index, IN BFD_IP_HEAD *ip)
{
    RESULT_BFDCFG ret = CFG_OK;
    NBB_USHORT ip_type_data = 0;
    NBB_USHORT ttl_data = 0;
    NBB_USHORT data_high = 0;
    NBB_USHORT data_low = 0;
    BFD_FPGA_REG_IP_HEAD_VER_TOS ip_ver_tos;

    do /* 开始循环 */
    {
        if(NULL == ip)
        {
            BFD_LOG(BMU_ERR, "ip is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
                
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(&ip_ver_tos, 0, sizeof(ip_ver_tos));

        ip_ver_tos.version = 4;     /* 版本IPv4 */
        ip_ver_tos.head_len = 5;    /* 长度20字节 */
        ip_ver_tos.recedence = 7;   /* 优先级 */
        ip_ver_tos.tos = ip->tos;
        ip_type_data = *(NBB_SHORT *)(&ip_ver_tos);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPv4_TOS, index, ip_type_data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_TOTAL_LEN, index, ip->total_length);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_IDENTIFIER, index, 0);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_FLAG_FRAMOFF, index, 0);
        if (0xE0000000 == (ip->local_ip[3] & 0xEFFFFF00)) /* 224.0.0.0/24地址的组播TTL必须为1 */
        {
            ttl_data = 0x0111;
        }
        else
        {
            ttl_data = 0xff11;
        }
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_TTL_PROTOCOL, index, ttl_data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_CHECKSUM, index, 0);
        BFD_GET_USHORT_FORM_ULONG(ip->local_ip[3], data_high, data_low);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_SRC1TO2, index, data_high);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_SRC3TO4, index, data_low);
        BFD_GET_USHORT_FORM_ULONG(ip->remote_ip[3], data_high, data_low);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_DEC1TO2, index,data_high);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_DEC3TO4, index,data_low);

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

/*****************************************************************************
 * 函 数 名  : bfd_get_fpga_ipv4
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 获取指定FPGA位置的BFD IPv4头(不能被直接调用，调用请用bfd_get_fpga_ip)
 * 输入参数  : IN unsigned short index   数组下标
 * 输出参数  : OUT BFD_IP_HEAD *ip_head  IP信息
 * 返 回 值  : RESULT_BFDCFG             错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_ipv4(IN unsigned short index, OUT BFD_IP_HEAD *ip_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_high = 0;
    unsigned short data_low = 0;
    BFD_FPGA_REG_IP_HEAD_VER_TOS ver_tos;

    do /* 开始循环 */
    {
        if(NULL == ip_head)
        {
            BFD_LOG(BMU_ERR, "ip_head is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
                
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(ip_head, 0, sizeof(*ip_head));
        OS_MEMSET(&ver_tos, 0, sizeof(ver_tos));
                
        ip_head->total_length = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_TOTAL_LEN, index);
        
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_SRC1TO2, index); 
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_SRC3TO4, index);    
        ip_head->local_ip[3] = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_DEC1TO2, index); 
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_DEC3TO4, index);    
        ip_head->remote_ip[3] = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}


/*****************************************************************************
 * 函 数 名  : bfd_set_fpga_ipv6
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定FPGA位置的BFD IPv6头
 * 输入参数  : IN unsigned short index  数组下标
               IN BFD_IP_HEAD *ip       IP信息
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_ipv6(IN unsigned short index, IN BFD_IP_HEAD *ip)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_high = 0;
    unsigned short data_low = 0;

    do /* 开始循环 */
    {
        if(NULL == ip)
        {
            BFD_LOG(BMU_ERR, "ip is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
                
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_TC_FL, index, 0x6000);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_FLOW_LABEL, index, 0);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_PAYLOAD_LEN, index, 32);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_NEXTHEAD_HOPLIMIT, index, 0x11ff);

        /* 设置源IP */
        BFD_GET_USHORT_FORM_ULONG(ip->local_ip[0], data_high, data_low);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC1TO2, index, data_high);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC3TO4, index, data_low);
        BFD_GET_USHORT_FORM_ULONG(ip->local_ip[1], data_high, data_low);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC5TO6, index, data_high);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC7TO8, index, data_low);
        BFD_GET_USHORT_FORM_ULONG(ip->local_ip[2], data_high, data_low);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC9TO10, index, data_high);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC11TO12, index, data_low);
        BFD_GET_USHORT_FORM_ULONG(ip->local_ip[3], data_high, data_low);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC13TO14, index, data_high);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC15TO16, index, data_low);
        
        /* 设置目的IP */
        BFD_GET_USHORT_FORM_ULONG(ip->remote_ip[0], data_high, data_low);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC1TO2, index, data_high);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC3TO4, index, data_low);
        BFD_GET_USHORT_FORM_ULONG(ip->remote_ip[1], data_high, data_low);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC5TO6, index, data_high);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC7TO8, index, data_low);
        BFD_GET_USHORT_FORM_ULONG(ip->remote_ip[2], data_high, data_low);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC9TO10, index, data_high);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC11TO12, index, data_low);
        BFD_GET_USHORT_FORM_ULONG(ip->remote_ip[3], data_high, data_low);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC13TO14, index, data_high);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC15TO16, index, data_low);

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

/*****************************************************************************
 * 函 数 名  : bfd_get_fpga_ipv6
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 获取指定FPGA位置的BFD IPv6头(不能被直接调用，调用请用bfd_get_fpga_ip)
 * 输入参数  : IN unsigned short index   数组下标
 * 输出参数  : OUT BFD_IP_HEAD *ip_head  IP信息
 * 返 回 值  : RESULT_BFDCFG             错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_ipv6(IN unsigned short index, OUT BFD_IP_HEAD *ip_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    NBB_USHORT data_high = 0;
    NBB_USHORT data_low = 0;

    do /* 开始循环 */
    {
        if(NULL == ip_head)
        {
            BFD_LOG(BMU_ERR, "ip_head is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
                
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        OS_MEMSET(ip_head, 0, sizeof(*ip_head));

        /* 获取源IP */
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC1TO2, index);
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC3TO4, index);
        ip_head->local_ip[0] = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC5TO6, index);
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC7TO8, index);
        ip_head->local_ip[1] = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC9TO10, index);
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC11TO12, index);
        ip_head->local_ip[2] = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC13TO14, index);
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC15TO16, index);
        ip_head->local_ip[3] = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);

        /* 获取目的IP */
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC1TO2, index);
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC3TO4, index);
        ip_head->remote_ip[0] = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC5TO6, index);
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC7TO8, index);
        ip_head->remote_ip[1] = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC9TO10, index);
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC11TO12, index);
        ip_head->remote_ip[2] = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC13TO14, index);
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC15TO16, index);
        ip_head->remote_ip[3] = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        
        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

/*****************************************************************************
 * 函 数 名  : bfd_set_fpga_udp
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定FPGA位置的BFD UDP信息
 * 输入参数  : IN unsigned short index  数组下标
               IN BFD_UDP_HEAD *udp     UPD信息
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_udp(IN unsigned short index, IN BFD_UDP_HEAD *udp)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if(NULL == udp)
        {
            BFD_LOG(BMU_ERR, "udp is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
                
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_UPD_SPORT, index, udp->src_port);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_UPD_LEN, index, udp->udp_len);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_BFD_LEN, index, udp->data_len);

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}


/*****************************************************************************
 * 函 数 名  : bfd_get_fpga_udp
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 获取指定FPGA位置的BFD UDP信息
 * 输入参数  : IN unsigned short index   数组下标
 * 输出参数  : OUT BFD_UDP_HEAD *udp     UPD信息
 * 返 回 值  : RESULT_BFDCFG             错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_udp(IN unsigned short index, OUT BFD_UDP_HEAD *udp)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if(NULL == udp)
        {
            BFD_LOG(BMU_ERR, "udp is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
                
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        OS_MEMSET(udp, 0, sizeof(*udp));
        
        udp->src_port = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_UPD_SPORT, index);        
        udp->udp_len = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_UPD_LEN, index);    
        udp->data_len = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_BFD_LEN, index);    
        
        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}


/*****************************************************************************
 * 函 数 名  : bfd_set_fpga_bfd_discr
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定FPGA位置的BFD描述符
 * 输入参数  : IN unsigned short index  数组下标
               IN BFD_DISCR *discr      描述符
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_bfd_discr(IN unsigned short index, IN BFD_DISCR *discr)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if(NULL == discr)
        {
            BFD_LOG(BMU_ERR, "discr is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_MYID, BFD_FPGA_ULONG_HIGH(index),
            (discr->my_id >> 16) & DRV_USHORT_INVALID);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_MYID, BFD_FPGA_ULONG_LOW(index),
            (discr->my_id) & DRV_USHORT_INVALID);
        
        /* BFD发送模块寄存器偏移0xc000+2*N+0x0：Bit15-0：BFD报文远端会话标识符（Your Discriminator），高16位。 */
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_YID, BFD_FPGA_ULONG_HIGH(index),
            (discr->peer_id >> 16)&DRV_USHORT_INVALID);
        
        /* BFD发送模块寄存器偏移0xc000+2*N+0x1：Bit15-0：BFD报文远端会话标识符（Your Discriminator），低16位。 */
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_YID, BFD_FPGA_ULONG_LOW(index),
            (discr->peer_id)&DRV_USHORT_INVALID);
        
        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

/*****************************************************************************
 * 函 数 名  : bfd_get_fpga_bfd_discr
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月17日
 * 函数功能  : 获取指定FPGA位置的BFD描述符
 * 输入参数  : IN unsigned short index  数组下标
 * 输出参数  : OUT BFD_DISCR *discr     描述符
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_bfd_discr(IN unsigned short index, OUT BFD_DISCR *discr)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_high = 0;
    unsigned short data_low = 0;

    do /* 开始循环 */
    {
        if(NULL == discr)
        {
            BFD_LOG(BMU_ERR, "discr is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(discr, 0, sizeof(*discr));
        
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_MYID, BFD_FPGA_ULONG_HIGH(index));
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_MYID, BFD_FPGA_ULONG_LOW(index));
        discr->my_id = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        
        /* BFD发送模块寄存器偏移0xc000+2*N+0x0：Bit15-0：BFD报文远端会话标识符（Your Discriminator），高16位。 */
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_YID, BFD_FPGA_ULONG_HIGH(index));
        
        /* BFD发送模块寄存器偏移0xc000+2*N+0x1：Bit15-0：BFD报文远端会话标识符（Your Discriminator），低16位。 */
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_YID, BFD_FPGA_ULONG_LOW(index));
        discr->peer_id = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        
        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}


/*****************************************************************************
 * 函 数 名  : bfd_set_fpga_label
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定FPGA位置的BFD标签
 * 输入参数  : IN unsigned short index      数组下标
               IN unsigned char frame_type  BFD发帧类型
               IN BFD_LABEL *label          标签
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG                错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_label(IN unsigned short index, IN unsigned char frame_type, IN BFD_LABEL *label)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_MPLS_LABEL   lsp_label;
    BFD_MPLS_LABEL   pw_label;
    NBB_ULONG    lsp_label_data = 0;
    NBB_ULONG    pw_label_data = 0;
    unsigned short data_high = 0;
    unsigned short data_low = 0;
    

    do /* 开始循环 */
    {
        if(NULL == label)
        {
            BFD_LOG(BMU_ERR, "label is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        OS_MEMSET(&lsp_label, 0, sizeof(BFD_MPLS_LABEL));
        OS_MEMSET(&pw_label, 0, sizeof(BFD_MPLS_LABEL));

        switch ( frame_type ) /* BFD报文发帧类型 */
        {
            case BFD_LSP :
                lsp_label.ulMplsLabel = label->lsp_label;
                lsp_label.ulStack = 1;
                lsp_label.ulExp = BFD_DEFAULT_MPLS_EXP;
                lsp_label.ulTtl = BFD_DEFAULT_MPLS_TTL;
                lsp_label_data = *(NBB_ULONG *)(&lsp_label);
                BFD_GET_USHORT_FORM_ULONG(lsp_label_data, data_high, data_low);
                spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_LSP_LABEL, BFD_FPGA_ULONG_HIGH(index),
                    data_high);
                spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_LSP_LABEL, BFD_FPGA_ULONG_LOW(index),
                    data_low);
                break;
            case BFD_PW_type2 :
                BFD_GET_USHORT_FORM_ULONG(label->ach, data_high, data_low);
                spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_ACH_LABEL, BFD_FPGA_ULONG_HIGH(index),
                    data_high);
                spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_ACH_LABEL, BFD_FPGA_ULONG_LOW(index),
                    data_low);

                /* 没有break,后续的标签配置和pw_type1相同 */
                
            case BFD_PW_type1 :
                lsp_label.ulMplsLabel = label->lsp_label;
                lsp_label.ulStack = 0;
                lsp_label.ulExp = BFD_DEFAULT_MPLS_EXP;
                lsp_label.ulTtl = BFD_DEFAULT_MPLS_TTL;
                lsp_label_data = *(NBB_ULONG *)(&lsp_label);
                BFD_GET_USHORT_FORM_ULONG(lsp_label_data, data_high, data_low);
                spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_LSP_LABEL, BFD_FPGA_ULONG_HIGH(index),
                    data_high);
                spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_LSP_LABEL, BFD_FPGA_ULONG_LOW(index),
                    data_low);
                
                pw_label.ulMplsLabel = label->pw_label;
                pw_label.ulStack = 1;
                pw_label.ulExp = BFD_DEFAULT_MPLS_EXP;
                pw_label.ulTtl = BFD_DEFAULT_MPLS_TTL;
                pw_label_data = *(NBB_ULONG *)(&pw_label);
                BFD_GET_USHORT_FORM_ULONG(pw_label_data, data_high, data_low);
                spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_PW_LABEL, BFD_FPGA_ULONG_HIGH(index),
                    data_high);
                spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_PW_LABEL, BFD_FPGA_ULONG_LOW(index),
                    data_low);
                break;
            default:
                BFD_LOG(BMU_INFO, "label type:%u do not has label!\n", frame_type);
                ret = CFG_OK;
        }
        BFD_CHECK_RETURN(ret);
                
        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

/*****************************************************************************
 * 函 数 名  : bfd_get_fpga_label
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定FPGA位置的BFD标签
 * 输入参数  : IN unsigned short index           数组下标
 * 输出参数  : OUT BFD_FPGA_MPLS_LABEL *label    标签
 * 返 回 值  : RESULT_BFDCFG                错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_label(IN unsigned short index, OUT BFD_FPGA_MPLS_LABEL *label)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_high = 0;
    unsigned short data_low = 0;
    NBB_ULONG    label_data = 0;

    do /* 开始循环 */
    {
        if(NULL == label)
        {
            BFD_LOG(BMU_ERR, "label is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
                
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        OS_MEMSET(label, 0, sizeof(*label));
        
        /* 获取FPGA中外层标签 */
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_LSP_LABEL, BFD_FPGA_ULONG_HIGH(index));
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_LSP_LABEL, BFD_FPGA_ULONG_LOW(index));
        label_data = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        label->lsp_label = *((BFD_MPLS_LABEL*)&label_data);
        
        /* 获取FPGA中内层标签 */
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_PW_LABEL, BFD_FPGA_ULONG_HIGH(index));
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_PW_LABEL, BFD_FPGA_ULONG_LOW(index));
        label_data = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        label->pw_label = *((BFD_MPLS_LABEL*)&label_data);

        
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_ACH_LABEL, BFD_FPGA_ULONG_HIGH(index));
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_ACH_LABEL, BFD_FPGA_ULONG_LOW(index));
        label_data = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        label->ach = label_data;

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}


/*****************************************************************************
 * 函 数 名  : bfd_set_fpga_function
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 设置指定FPGA位置的BFD功能信息
 * 输入参数  : IN unsigned short index      数组下标
               IN unsigned char frame_type  BFD发帧类型
               IN unsigned char ip_type     IP类型
               IN BFD_FUNCTION *function    BFD功能信息
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG                错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_function(IN unsigned short index, IN unsigned char frame_type,
    IN unsigned char ip_type, IN BFD_FUNCTION *function)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_FPGA_REG_FUCTION fuction_info;
    NBB_USHORT   fuction_data = 0;

    do /* 开始循环 */
    {
        if(NULL == function)
        {
            BFD_LOG(BMU_ERR, "function is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        OS_MEMSET(&fuction_info, 0, sizeof(BFD_FPGA_REG_FUCTION));

        fuction_info.usSendFlag = function->send_flag;

        /* UDP端口号 */
        fuction_info.usUDPtype = function->detection_type;

        /* 判断封装类型 */
        fuction_info.usSendType = frame_type;

        /* VLAN使能 */
        fuction_info.usVlanAble = function->vlan_able;
        fuction_info.usVlanNum = function->vlan_num;

        /* PW ACH封装格式 */
        fuction_info.usPWtype = function->pw_type;

        if (BFD_IPV6 == ip_type)
        {
            fuction_info.usIpType = TRUE;
        }
        else
        {
            fuction_info.usIpType = FALSE;
        }
        
        fuction_data = *(NBB_USHORT *)(&fuction_info);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_FUNCTION, index, fuction_data);
                
        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

/*****************************************************************************
 * 函 数 名  : bfd_get_fpga_function
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 获取指定FPGA位置的BFD功能信息
 * 输入参数  : IN unsigned short index      数组下标
 * 输出参数  : OUT BFD_FPGA_REG_FUCTION *fuction_info  BFD功能信息
 * 返 回 值  : RESULT_BFDCFG                错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_function(IN unsigned short index, OUT BFD_FPGA_REG_FUCTION *fuction_info)
{
    RESULT_BFDCFG ret = CFG_OK;
    NBB_USHORT   fuction_data = 0;

    do /* 开始循环 */
    {
        if(NULL == fuction_info)
        {
            BFD_LOG(BMU_ERR, "fuction_info is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        OS_MEMSET(fuction_info, 0, sizeof(*fuction_info));
        
        fuction_data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_FUNCTION, index);
        *fuction_info = *(BFD_FPGA_REG_FUCTION*)&fuction_data;
 
        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

/*****************************************************************************
 * 函 数 名  : bfd_set_fpga_sysport
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月8日
 * 函数功能  : 设置指定FPGA位置的sysport
 * 输入参数  : IN unsigned short index  数组下标
               IN BFD_SYSPORT *sysport  ITMH头里带的sysport
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_sysport(IN unsigned short index, IN BFD_SYSPORT *sysport)
{
    RESULT_BFDCFG ret = CFG_OK;
    NBB_USHORT   data = 0;

    do /* 开始循环 */
    {
        if(NULL == sysport)
        {
            BFD_LOG(BMU_ERR, "sysport is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        data = sysport->des_fapid;
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FGAP_BFD_ADAPT_SYSPORT, index, data);
                
        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}


/*****************************************************************************
 * 函 数 名  : bfd_get_fpga_sysport
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月8日
 * 函数功能  : 获取指定FPGA位置的sysport
 * 输入参数  : IN unsigned short index   数组下标
 * 输出参数  : OUT BFD_SYSPORT *sysport  ITMH头里带的sysport
 * 返 回 值  : RESULT_BFDCFG             错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_sysport(IN unsigned short index, OUT BFD_SYSPORT *sysport)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if(NULL == sysport)
        {
            BFD_LOG(BMU_ERR, "sysport is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(sysport, 0, sizeof(*sysport));

        sysport->des_fapid = spm_oamtree_s16read(BFD_FPGA_BFD_ADAPT_BASE, BFD_FGAP_BFD_ADAPT_SYSPORT, index);
                
        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}


RESULT_BFDCFG bfd_get_fpga_send_count(IN unsigned short index, OUT unsigned short *sent_count)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        if(NULL == sent_count)
        {
            BFD_LOG(BMU_ERR, "sent_count is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        *sent_count = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_COUNT, index);

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}


RESULT_BFDCFG bfd_get_fpga_send_work_interval(IN unsigned short index, OUT unsigned short *send_interval)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        if(NULL == send_interval)
        {
            BFD_LOG(BMU_ERR, "send_interval is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        *send_interval = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_WORK_INTERVAL, index);

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}


/*****************************************************************************
 * 函 数 名  : bfd_del_fpga
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 删除指定位置的BFD
 * 输入参数  : IN unsigned short index  数组下标
               IN unsigned long my_sid  BFD MYID
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_del_fpga(IN unsigned short index, IN unsigned long my_sid)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        /* 删除FPGA使用的BFD MYID会话二叉树成员 */
        ret = bfd_del_fpga_session_tree(index, my_sid);

        /* 清空FPGA寄存器 */
        ret = bfd_clear_fpga(index);
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_clear_fpga
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 清空指定位置的FPGA寄存器
 * 输入参数  : IN unsigned short index  数组索引
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_clear_fpga(IN unsigned short index)
{
    RESULT_BFDCFG ret = CFG_OK;
    NBB_USHORT data = 0;

    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        
        /************************************* BFD接收会话状态子模块 ******************************************/
        /* BFD_FPGA_SESSION_DIAG_STATE 只读 */
        /* BFD_FPGA_SESSION_WORK_INTERVAL_LOW 只读 */
        /* BFD_FPGA_SESSION_WORK_INTERVAL_HIGH 只读 */
        
        /* BFD_FPGA_SESSION_RECV_COUNT FPGA读清 */
        spm_oamtree_s16read(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_RECV_COUNT, index);
        
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_SEND_STATE_DIAG, index, data);

        /* BFD_FPGA_SESSION_RECV_STATE_DIAG 只读 */
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_REQUIRED_MYID, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_REQUIRED_MYID_SWITCH, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_UP_TO_DOWN_STA, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_CHEKSUM, index, data);

        /*  BFD_FPGA_SESSION_ERROR_COUNT FPGA读清 */
        spm_oamtree_s16read(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_ERROR_COUNT, index);

        /* BFD_FPGA_SESSION_INTERVAL_NOT_MATCH只读 */
        /****************************************************************************************************/
        
        /**********************************************  BFD模块 **********************************************/
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_FUNCTION, index, data);
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DMAC, BFD_FPGA_MAC_HIGH(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DMAC, BFD_FPGA_MAC_MIDDLE(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DMAC, BFD_FPGA_MAC_LOW(index), data);
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_SMAC, BFD_FPGA_MAC_HIGH(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_SMAC, BFD_FPGA_MAC_MIDDLE(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_SMAC, BFD_FPGA_MAC_LOW(index), data);
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_SVLAN, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_CVLAN, index, data);
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPv4_TOS, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_TOTAL_LEN, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_IDENTIFIER, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_FLAG_FRAMOFF, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_TTL_PROTOCOL, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_CHECKSUM, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_SRC1TO2, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_SRC3TO4, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_DEC1TO2, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_DEC3TO4, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC13TO14, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_SRC15TO16, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC1TO2, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC3TO4, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC5TO6, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC7TO8, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC9TO10, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC11TO12, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC13TO14, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV6_DEC15TO16, index, data);
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_UPD_SPORT, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_UPD_LEN, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_BFD_LEN, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_MYID, BFD_FPGA_ULONG_HIGH(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_MYID, BFD_FPGA_ULONG_LOW(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_YID, BFD_FPGA_ULONG_HIGH(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_YID, BFD_FPGA_ULONG_LOW(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DIAG_STA_DM_INTERVAL,
            BFD_FPGA_ULONG_HIGH(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DIAG_STA_DM_INTERVAL,
            BFD_FPGA_ULONG_LOW(index), data);
        
        /* BFD_FPGA_SEND_WORK_INTERVAL 只读 */
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_LSP_LABEL, BFD_FPGA_ULONG_HIGH(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_LSP_LABEL, BFD_FPGA_ULONG_LOW(index), data);
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_PW_LABEL, BFD_FPGA_ULONG_HIGH(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_PW_LABEL, BFD_FPGA_ULONG_LOW(index), data);
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_ACH_LABEL, BFD_FPGA_ULONG_HIGH(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_ACH_LABEL, BFD_FPGA_ULONG_LOW(index), data);
        
        /* BFD_FPGA_SEND_TIMER_DOWN_COUNT 只读 */
        /* BFD_FPGA_SEND_REMOTE_DOWN_COUNT 只读 */
        /* BFD_FPGA_SEND_INTERVAL_MODIFY 寄存器自动清空 */
        /* BFD_FPGA_SEND_COUNT 只读 */
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_RCV_MYID, BFD_FPGA_ULONG_HIGH(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_RCV_MYID, BFD_FPGA_ULONG_LOW(index), data);
        
        /****************************************************************************************************/

        /********************************************* BFD适配模块 ******************************************/
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FGAP_BFD_ADAPT_SMAC, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FGAP_BFD_ADAPT_SYSPORT, index, data);
        
        /****************************************************************************************************/

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;
}

RESULT_BFDCFG bfd_get_fpga_session_state(IN unsigned short index, OUT BFD_FPGA_REG_DIAG_STATE *diag_state)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data = 0;

    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        if(NULL == diag_state)
        {
            BFD_LOG(BMU_ERR, "diag_state is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(diag_state, 0, sizeof(*diag_state));

        data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_DIAG_STATE, index);
        *diag_state = *((BFD_FPGA_REG_DIAG_STATE*)(&data));

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}


RESULT_BFDCFG bfd_get_fpga_session_work_interval(IN unsigned short index, OUT unsigned long *recv_interval)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_low = 0;
    unsigned short data_high = 0;

    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        if(NULL == recv_interval)
        {
            BFD_LOG(BMU_ERR, "recv_interval is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_WORK_INTERVAL_LOW, index);
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_WORK_INTERVAL_HIGH, index);
        *recv_interval = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

RESULT_BFDCFG bfd_get_fpga_session_recv_count(IN unsigned short index, OUT unsigned short *recv_count)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        if(NULL == recv_count)
        {
            BFD_LOG(BMU_ERR, "recv_count is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        *recv_count = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_RECV_COUNT, index);

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

RESULT_BFDCFG bfd_set_fpga_session_up_to_down_sta(IN unsigned short index, IN NBB_BOOL enable)
{
    RESULT_BFDCFG ret = CFG_OK;
    SPM_BFD_UP_TO_DOWN_STA up_to_down_state;
    unsigned short data = 0;
    
    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(&up_to_down_state, 0, sizeof(up_to_down_state));

        up_to_down_state.enable = enable;
        
        data = *((unsigned short*)(&up_to_down_state));
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_UP_TO_DOWN_STA, index, data);

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    

}


RESULT_BFDCFG bfd_get_fpga_session_up_to_down_sta(IN unsigned short index, OUT SPM_BFD_UP_TO_DOWN_STA *up_to_down_state)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data = 0;

    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        if(NULL == up_to_down_state)
        {
            BFD_LOG(BMU_ERR, "up_to_down_state is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(up_to_down_state, 0, sizeof(*up_to_down_state));

        data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_UP_TO_DOWN_STA, index);
        *up_to_down_state = *((SPM_BFD_UP_TO_DOWN_STA*)(&data));

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

RESULT_BFDCFG bfd_set_fpga_session_anti_attack(IN unsigned short index, IN unsigned long your_id, IN NBB_BOOL enable)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_high = 0;
    unsigned short data_low = 0;

    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        if(TRUE == enable)
        {
            BFD_GET_USHORT_FORM_ULONG(your_id, data_high, data_low);
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID,
                BFD_FPGA_ULONG_HIGH(index), data_low);      /* FPGA这里的寄存器是反的 */
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID,
                BFD_FPGA_ULONG_LOW(index), data_high);      /* FPGA这里的寄存器是反的 */
                
            /* 本端YID与收包MYID匹配置位使能 */            
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID_SWITCH, index, 1);
        }
        else
        {
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID,
                BFD_FPGA_ULONG_HIGH(index), 0);
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID,
                BFD_FPGA_ULONG_LOW(index), 0);
                
            /* 本端YID与收包MYID匹配置位使能 */            
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID_SWITCH, index, 0);
        }
        
        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

RESULT_BFDCFG bfd_get_fpga_session_anti_attack(IN unsigned short index,
    OUT unsigned long *your_id,
    OUT unsigned short *enable)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_high = 0;
    unsigned short data_low = 0;

    do /* 开始循环 */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == your_id)
        {
            BFD_LOG(BMU_ERR, "your_id is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == enable)
        {
            BFD_LOG(BMU_ERR, "enable is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID,
            BFD_FPGA_ULONG_HIGH(index));        /* FPGA这里的寄存器是反的 */
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID,
            BFD_FPGA_ULONG_LOW(index));         /* FPGA这里的寄存器是反的 */
        *your_id = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
            
        /* 本端YID与收包MYID匹配置位 */            
        *enable = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID_SWITCH, index);
        
        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}


RESULT_BFDCFG bfd_get_fpga_capture_choose(OUT unsigned short *cap_choose)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {        
        if(NULL == cap_choose)
        {
            BFD_LOG(BMU_ERR, "cap_choose is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        *cap_choose = spm_oamtree_s16read(BFD_FPGA_GENERAL_BASE, 0, BFD_FPGA_PACKET_CAPTURE_CHOOSE);

        ret = CFG_OK;
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;    
}

