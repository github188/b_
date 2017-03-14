/***********************************************************************************

 * 文 件 名   : bfd_get_extern_info.c
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年10月12日
 * 版 本 号   : 
 * 文件描述   : BFD获取外部模块信息
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#include "bfd.h"

extern char get_frame_type();

PTN_GLOBAL_CFG    g_ptn_global_cfg_data_store[MAX_PTN_GLOBAL_CFG];
unsigned char g_frame_type = 0; /*全局变量，定义当前机框类型*/

/*说明: slot ---> fapid*/
unsigned char g_slot_map_fapid_U60[] = 
{
     0 , 1 , 2 , 3 , 4 , 5 , 6 , 7, 8 , 9 , 10 , 11 , 0 , 0 , 0 , 0 ,  /*C400 :槽位 0-15*/
     0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10, 11, 12, 13, 14, 15, /*C700槽位:16-31*/
     16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, /*32 - 47*/
     47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32,/*48 - 63*/
     63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48,/*64 - 79*/
     0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
 };

 //fapid -> slot (c700)
 unsigned char g_fapid_map_slotid_U60[MAX_SLOT_NUM_U60] =
 {
     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 
 0x1c, 0x1d, 0x1e, 0x1f,
     0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 
 0x2c, 0x2d, 0x2e, 0x2f,
     0x3f, 0x3e, 0x3d, 0x3c, 0x3b, 0x3a, 0x39, 0x38, 0x37, 0x36, 0x35, 0x34, 
 0x33, 0x32, 0x31, 0x30,
     0x4f, 0x4e, 0x4d, 0x4c, 0x4b, 0x4a, 0x49, 0x48, 0x47, 0x46, 0x45, 0x44, 
 0x43, 0x42, 0x41, 0x40
 };

RESULT_BFDCFG bfd_init_get_extern_info()
{
    RESULT_BFDCFG ret = CFG_OK;
    
    g_frame_type = get_frame_type();/*获取机框类型*/

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_get_vc_traffic_info
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 获取VC的LSP配置信息
 * 输入参数  : IN unsigned short bfd_id       BFD MYID
 * 输出参数  : OUT BFD_LSP_CFG_INFO* lsp_cfg  LSP配置
 * 返 回 值  : RESULT_BFDCFG                  错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_vc_traffic_info(IN unsigned long bfd_id, OUT BFD_LSP_CFG_INFO* lsp_cfg)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if(bfd_id > BFD_MAX_ALL_SESNUM)
        {
            BFD_LOG(BMU_ERR, "bfd_id:%lu is too big\n", bfd_id);
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == lsp_cfg)
        {
            BFD_LOG(BMU_ERR, "lsp_cfg is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;
}




/*****************************************************************************
 函 数 名  : oam_traffic_info_print
 功能描述  : 打印与OAM相关联的业务信息
 输入参数  : oam_traffic_info 获取业务信息结构体指针
             IN int level     打印级别
 输出参数  : 无
 返 回 值  : 0 ---> 成功， -1 ---> 失败
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2016年2月1日
    作    者   : 丁浩
    修改内容   : 

*****************************************************************************/
int oam_traffic_info_print(TP_OAM_LSP_CFG *oam_traffic_info, IN int level)
{
    BFD_LOG(level, "打印与OAM相关联的业务信息\n");
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "is_protect :",oam_traffic_info->is_protect);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "in_lsp_label :",oam_traffic_info->InLspLable);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "in_pw_label :",oam_traffic_info->InPwLable);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "in_port :",oam_traffic_info->InPort);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "in_slot :",oam_traffic_info->InSlot);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "out_lsp_label :",oam_traffic_info->OutLspLable);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "out_pw_label :",oam_traffic_info->OutPwLable);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "out_port :",oam_traffic_info->OutPort);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "out_slot :",oam_traffic_info->OutSlot);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "sys_port_id :",oam_traffic_info->SysPortId);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "tx_sys_port_id :",oam_traffic_info->TxSysPortId);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "tx_tunnel_eep :",oam_traffic_info->TxTunnelEep);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "rx_tunnel_eep :",oam_traffic_info->RxTunnelEep);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "lag_id :",oam_traffic_info->lag_id);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "uni_is_lag :",oam_traffic_info->uni_is_lag);

    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "Slot_West :",oam_traffic_info->Slot_West);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "Port_West :",oam_traffic_info->Port_West);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "Slot_East :",oam_traffic_info->Slot_East);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "Port_East :",oam_traffic_info->Port_East);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "SysPortId_West :",oam_traffic_info->SysPortId_West);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "SysPortId_East :",oam_traffic_info->SysPortId_East);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "LspLable_West_Rx :",oam_traffic_info->LspLable_West_Rx);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "PwLable_West_Rx :",oam_traffic_info->PwLable_West_Rx);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "LspLable_East_Rx :",oam_traffic_info->LspLable_East_Rx);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "PwLable_East_Rx :",oam_traffic_info->PwLable_East_Rx);
    
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "LspLable_West_Tx :",oam_traffic_info->LspLable_West_Tx);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "PwLable_West_Tx :",oam_traffic_info->PwLable_West_Tx);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "LspLable_East_Tx :",oam_traffic_info->LspLable_East_Tx);
    BFD_LOG(level, "%-*s%d\n", STRING_LEN, "PwLable_East_Tx :",oam_traffic_info->PwLable_East_Tx);
    
    BFD_LOG(level, "%-*s%02x:%02x:%02x:%02x:%02x:%02x\n", STRING_LEN, "des_mac_nni :",
        oam_traffic_info->des_mac_nni[0],oam_traffic_info->des_mac_nni[1],
        oam_traffic_info->des_mac_nni[2],oam_traffic_info->des_mac_nni[3],
        oam_traffic_info->des_mac_nni[4],oam_traffic_info->des_mac_nni[5]);
    BFD_LOG(level, "%-*s%02x:%02x:%02x:%02x:%02x:%02x\n", STRING_LEN, "src_mac_nni :",
        oam_traffic_info->src_mac_nni[0],oam_traffic_info->src_mac_nni[1],
        oam_traffic_info->src_mac_nni[2],oam_traffic_info->src_mac_nni[3],
        oam_traffic_info->src_mac_nni[4],oam_traffic_info->src_mac_nni[5]);
    
    return SUCCESS;
}

#ifndef X86_UINT_TEST
/*以下是tp_oam模块需要配置分发模块提供的接口封装*/
/*****************************************************************************
 函 数 名  : oam_get_traffic_info
 功能描述  : 根据oam_id获取业务信息
 输入参数  : 
 输出参数  : 0 成功 -1 失败
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2015年10月13日
    作    者   : 丁浩
    修改内容   : 新建
*****************************************************************************/
int oam_get_traffic_info(unsigned long bfd_myid, unsigned char type, TP_OAM_LSP_CFG *LspRxCfg)
{
    int return_value = 0;

    /*1 函数入参检查*/
    /*if ((bfd_myid < 1) || (bfd_myid > BFD_MAX_ALL_SESNUM))
    {
         printf("TP_OAM_ERROR:oam_get_traffic_info parameter \"tpoam_id\" error!\n");
         return PARAM_ERROR;
    }*/

    if (type > 4)/*范围有问题*/
    {
         printf("TP_OAM_ERROR:oam_get_traffic_info parameter \"type\" error!\n");
         return PARAM_ERROR;
    }

   return_value = tp_oam_get_traffic_plus(bfd_myid, type,LspRxCfg);
   
   if (return_value != 0)
   {
        printf("TP_OAM_ERROR:oam_get_traffic_info get traffic info error\n");
        return return_value;/*将接口获取参数失败的返回值作为返回值*/
   }

   return CFG_OK;
    
}

/*说明: 在vp/vc的基础上增加过站业务查找接口，代替之前的tp_oam_get_traffic接口
    暂时规定type = 5为查找lsp过站业务信息
            type = 6为查找pw过站业务信息
*/
int tp_oam_get_traffic_plus(unsigned long bfd_myid, unsigned char type, TP_OAM_LSP_CFG *LspRxCfg)
{
    int return_value = 0;
    
    /*1 函数入参检查*/
    /*if ((bfd_myid < 1) || (bfd_myid > BFD_MAX_ALL_SESNUM))
    {
        printf("tp_oam_get_traffic:tpoam_id is out of range!\n");
        return PARAM_ERROR;
    }*/

    if (NULL == LspRxCfg)
    {
        printf("LspRxCfg is NULL!\n");
        return PARAM_ERROR;    
    }

    switch (type)
    {
        case BFD_CFG_LSP:
            return_value = tp_oam_get_vp_traffic_info(bfd_myid, LspRxCfg);
            break;
        
        case BFD_CFG_PW:
            return_value = tp_oam_get_vc_traffic_info(bfd_myid, LspRxCfg);
            break;

         default:
            printf("tp_oam_get_traffic_plus: parameter \"type\" is out of range!\n");
            break;

    }

    if (return_value != 0)
    {
        printf("tp_oam_get_traffic_plus: oam get traffic info failed!\n");
        return PARAM_ERROR;
    }
    
    return CFG_OK;
}

/*说明: 获取vp层业务信息*/
int tp_oam_get_vp_traffic_info(unsigned long bfd_myid, TP_OAM_LSP_CFG *LspRxCfg)
{
    TX_LSP_CFG_NODE *tx_lsp_cfg_ptr = (TX_LSP_CFG_NODE *)NULL;
    TX_LSP_CFG_NODE *rx_lsp_cfg_ptr = (TX_LSP_CFG_NODE *)NULL;
    PVE_INTERFACE_NODE *pve_interface_ptr = (PVE_INTERFACE_NODE *)NULL;
    INTERFACE_PHY_NODE *interface_phy_node = (INTERFACE_PHY_NODE *)NULL;
    
    unsigned char lsp_find_flag = 0;
    unsigned short pve_id = 0;
    char tp_oam_error_msg[TP_OAM_ERROR_MSG_LEN];
    unsigned char mac[6] = {0};

    /*1 从配置块id=10的lsp_rx中取数据
    上话节点，即标签动作push，也叫源
    
    InLspLable取配置块10里的字节1~4
    
    下话节点，即标签动作pop，也叫宿
    
    TxSysPortId取配置块10里的字节15-16；
    OutLspLable取配置块10字节30~33;
    */
    if (NULL == g_rx_lsp_cfg_node_head)
    {
        printf("the g_rx_lsp_cfg_node_head is NULL now!!\n"); 
        return -1; 
    }
    
    rx_lsp_cfg_ptr = g_rx_lsp_cfg_node_head->cfg_next;

    if (NULL == rx_lsp_cfg_ptr) 
    {
        printf("the g_rx_lsp_cfg_node_head->cfg_next is NULL now!!\n"); 
        return -1; 
    }

    while (rx_lsp_cfg_ptr != NULL)
    {
        printf("bfd_localid=%u, bfd_myid=%lu\n", rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.bfd_localid, bfd_myid);
        if ((bfd_myid == rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.bfd_localid))
        {
            lsp_find_flag = 1;
            
            if (0 == rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.label_action) /*如果是上话节点*/
            {
                LspRxCfg->InLspLable = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.rec_label;
            }
            else  /*默认按照下话节点处理*/
            {
               LspRxCfg->OutLspLable = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.lsp_label[0].label;
               
               LspRxCfg->TxSysPortId = (rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.slot << 8)
                    + rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.portnum;
               
               LspRxCfg->RxTunnelEep = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.encap_id;
               LspRxCfg->TxTunnelEep = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.encap_id;
               pve_id = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.nni_pve_id;

               if (pve_id != 0)
               {
                   pve_interface_ptr = find_key_list_pve_interface_cfg(pve_id);
                   if (NULL == pve_interface_ptr)
                   {
                        //printf("pve_id (%d) does not exist in the pve link list\n",pve_id);
                        
                        sprintf(tp_oam_error_msg,"1:pve_id (%d) does not exist in the pve link list\n",pve_id);
                        BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                        return ERROR;
                   }
                   LspRxCfg->OutPort = pve_interface_ptr->pve_interface_cfg_data.phy_port;
                   memcpy(mac,pve_interface_ptr->pve_interface_cfg_data.mac_dress,6);
                   memcpy(LspRxCfg->des_mac_nni, mac, 6);
                   memcpy(LspRxCfg->src_mac_nni, g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
                   LspRxCfg->src_mac_nni[5] = mac[5];
                   LspRxCfg->src_mac_nni[4] = (LspRxCfg->src_mac_nni[4] & 0xf0) + (mac[4] & 0x0f);
                   
                   LspRxCfg->pve_flag = PVE_MODE_OAM;
                   LspRxCfg->pve_id_or_phy_index = pve_id;
               }
               else
               {
                    if (NULL == g_interface_phy_node_head)
                    {
                        printf("g_interface_phy_node_head is null !\n");
                        return ERROR;
                    }
                    interface_phy_node = g_interface_phy_node_head->cfg_next;

                    if (NULL == g_interface_phy_node_head->cfg_next)
                    {
                        printf("g_interface_phy_node_head->cfg_next is null !\n");
                        return ERROR;    
                    }

                    while(interface_phy_node != NULL)
                    {
                        if ((LspRxCfg->TxSysPortId == interface_phy_node->interface_phy_cfg_data.base_cfg.sysport)
                            && (1 == interface_phy_node->interface_phy_cfg_data.eth_cfg.port_tp))
                        {
                            printf("base_cfg.sysport = %d\n",
                                interface_phy_node->interface_phy_cfg_data.base_cfg.sysport);
                            
                            LspRxCfg->OutPort = interface_phy_node->interface_phy_cfg_data.base_cfg.portnum; 
                            memcpy(mac,&interface_phy_node->interface_phy_cfg_data.eth_cfg.phy_addr[8],6);
                            
                            memcpy(LspRxCfg->des_mac_nni, mac, 6);
                            memcpy(LspRxCfg->src_mac_nni, 
                                g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
                            
                            LspRxCfg->src_mac_nni[5] = mac[5];
                            LspRxCfg->src_mac_nni[4] = (LspRxCfg->src_mac_nni[4] & 0xf0) + (mac[4] & 0x0f);
                            
                            LspRxCfg->pve_flag = PHY_MODE_OAM;

                            printf("interface_phy_node->index = %d\n",interface_phy_node->index);
                            LspRxCfg->pve_id_or_phy_index = interface_phy_node->index;
                            break;
                        }
                        interface_phy_node = interface_phy_node->cfg_next;
                    }

                    if (NULL == interface_phy_node)
                    {
                        //printf("error,pve = 0, cannot find outport from interface phy link list!\n");
                        
                        sprintf(tp_oam_error_msg,"2 error,pve=0,cannot find outport from interface phy link list!\n");
                        BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                        return ERROR;
                    }
               }
               
               
               printf("slot = %d\n",rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.slot);
               printf("portnum = %d\n",rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.portnum);
               printf("tx_sys_port_id = %d\n",LspRxCfg->TxSysPortId);
               printf("pve_id_or_phy_index = %d\n", LspRxCfg->pve_id_or_phy_index);
               printf("out_port is %d\n", LspRxCfg->OutPort);
            }

            
            printf("RxTunnelEep = 0x%x\n",LspRxCfg->RxTunnelEep);
            break;
        }

        rx_lsp_cfg_ptr = rx_lsp_cfg_ptr->cfg_next;
        
    }

    if (0 == lsp_find_flag)
    {
        printf("tp_oam is not in the rx_lsp_cfg!\n");
        return -1;
    }
    
    lsp_find_flag = 0;
    
    /*2 从配置块id=11的lsp_tx中取数据
    
    上话节点，即标签动作push，也叫源
      TxSysPortId取配置块11里的字节15-16；
      OutLspLable取配置块11字节30~33;

    下话节点，即标签动作pop，也叫宿
    InLspLable取配置块11里的字节1~4；*/
    if (NULL == g_tx_lsp_cfg_node_head)
    {
        printf("the g_tx_lsp_cfg_node_head is NULL now!!\n"); 
        return -1; 
    }
    tx_lsp_cfg_ptr = g_tx_lsp_cfg_node_head->cfg_next;

    if (NULL == tx_lsp_cfg_ptr) 
    {
        printf("the g_tx_lsp_cfg_node_head->cfg_next is NULL now!!\n"); 
        return -1; 
    }

    while (tx_lsp_cfg_ptr != NULL)
    {
        printf("bfd_localid=%u, bfd_myid=%lu\n", rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.bfd_localid, bfd_myid);
        if ((bfd_myid == tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.bfd_localid)) 
        {
            lsp_find_flag = 1;
            
            if (0 == tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.label_action) /*如果是上话节点*/ 
            { 
               LspRxCfg->OutLspLable = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.lsp_label[0].label;
               
               LspRxCfg->TxSysPortId = (tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.slot << 8) 
                + tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.portnum;

               LspRxCfg->RxTunnelEep = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.encap_id;
               LspRxCfg->TxTunnelEep = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.encap_id;
               pve_id = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.nni_pve_id;

               if (pve_id != 0)
               {
                   pve_interface_ptr = find_key_list_pve_interface_cfg(pve_id);
                   if (NULL == pve_interface_ptr)
                   {
                        //printf("pve_id (%d) does not exist in the pve link list\n",pve_id);
                        
                        sprintf(tp_oam_error_msg,"3:pve_id (%d) does not exist in the pve link list\n",pve_id);
                        BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                        return ERROR;
                   }
                   LspRxCfg->OutPort = pve_interface_ptr->pve_interface_cfg_data.phy_port;
                   memcpy(mac, pve_interface_ptr->pve_interface_cfg_data.mac_dress, 6);
                   
                   memcpy(LspRxCfg->des_mac_nni, mac, 6);
                   memcpy(LspRxCfg->src_mac_nni, g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
                   LspRxCfg->src_mac_nni[5] = mac[5];
                   LspRxCfg->src_mac_nni[4] = (LspRxCfg->src_mac_nni[4] & 0xf0) + (mac[4] & 0x0f);
                   
                   LspRxCfg->pve_flag = PVE_MODE_OAM;
                   LspRxCfg->pve_id_or_phy_index = pve_id;
               }
               else
               {
                    if (NULL == g_interface_phy_node_head)
                    {
                        printf("g_interface_phy_node_head is null !\n");
                        return ERROR;
                    }
                    interface_phy_node = g_interface_phy_node_head->cfg_next;

                    if (NULL == g_interface_phy_node_head->cfg_next)
                    {
                        printf("g_interface_phy_node_head->cfg_next is null !\n");
                        return ERROR;    
                    }

                    while(interface_phy_node != NULL)
                    {
                        if ((LspRxCfg->TxSysPortId == interface_phy_node->interface_phy_cfg_data.base_cfg.sysport)
                            && (1 == interface_phy_node->interface_phy_cfg_data.eth_cfg.port_tp))
                        {
                            LspRxCfg->OutPort = interface_phy_node->interface_phy_cfg_data.base_cfg.portnum;
                            memcpy(mac,&interface_phy_node->interface_phy_cfg_data.eth_cfg.phy_addr[8],6);
                            
                            memcpy(LspRxCfg->des_mac_nni, mac, 6);
                            memcpy(LspRxCfg->src_mac_nni, 
                                g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
                            LspRxCfg->src_mac_nni[5] = mac[5];
                            LspRxCfg->src_mac_nni[4] = (LspRxCfg->src_mac_nni[4] & 0xf0) + (mac[4] & 0x0f);

                            LspRxCfg->pve_flag = PHY_MODE_OAM;
                            LspRxCfg->pve_id_or_phy_index = interface_phy_node->index;
                            break;
                        }
                        interface_phy_node = interface_phy_node->cfg_next;
                    }

                    if (NULL == interface_phy_node)
                    {
                        sprintf(tp_oam_error_msg,"4 error,pve=0,cannot find outport from interface phy link list!\n");
                        BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                        return ERROR;
                    }
               }


               printf("slot = %d\n",tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.slot);
               printf("portnum = %d\n",tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.portnum);
               printf("tx_sys_port_id = %d\n",LspRxCfg->TxSysPortId);
               printf("pve_id = %d\n", pve_id);
               printf("out_port is %d\n", LspRxCfg->OutPort);
            } 
            else  /*默认按照下话节点处理*/ 
            {
                LspRxCfg->InLspLable = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.rec_label;
            }

            printf("TxTunnelEep = 0x%x\n",LspRxCfg->TxTunnelEep);
            break;
        }

        tx_lsp_cfg_ptr = tx_lsp_cfg_ptr->cfg_next;
    }

    if (0 == lsp_find_flag)
    {
        printf("tp_oam is not in the tx_lsp_cfg!\n");
        return -1;
    }
    lsp_find_flag = 0;

    LspRxCfg->OutPwLable = 0xd; 
    LspRxCfg->InPwLable = 0xd; 
    memcpy(LspRxCfg->global_mac, g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
    return SUCCESS;
}


/*说明: 获取vc层业务信息*/
int tp_oam_get_vc_traffic_info(unsigned long bfd_myid, TP_OAM_LSP_CFG *LspRxCfg)
{
    TX_LSP_CFG_NODE *tx_lsp_cfg_ptr = (TX_LSP_CFG_NODE *)NULL;
    TX_LSP_CFG_NODE *rx_lsp_cfg_ptr = (TX_LSP_CFG_NODE *)NULL;
    VPWS_CFG_NODE *vpws_cfg_ptr = (VPWS_CFG_NODE *)NULL;
    PORT_LOGIC_CFG_NODE *port_logic_cfg_ptr = (PORT_LOGIC_CFG_NODE *)NULL;
    INTERFACE_PHY_NODE *interface_phy_ptr = (INTERFACE_PHY_NODE *)NULL;
    PVE_INTERFACE_NODE *pve_interface_ptr = (PVE_INTERFACE_NODE *)NULL;
    
    //PVE_INTERFACE_NODE *pve_interface_ptr = (PVE_INTERFACE_NODE *)NULL;
    
    unsigned int port_logic_index = 0;/*关联到配置块68*/
    unsigned int phy_port_index = 0;/*关联到配置块67*/
    
    //unsigned short pve_id = 0;
    char tp_oam_error_msg[TP_OAM_ERROR_MSG_LEN];
    unsigned short pve_id = 0;
    unsigned char mac[6] = {0};

    unsigned long store_bfd_myid = 0;
    unsigned char *point = NULL;

    unsigned long residual_length = 0;

    int i;

    if (NULL == g_vpws_cfg_node_head)
    {
        printf("the g_vpws_cfg_node_head is NULL now!!\n"); 
        return -1; 
    }
    
    vpws_cfg_ptr = g_vpws_cfg_node_head->cfg_next;

    if (NULL == g_vpws_cfg_node_head->cfg_next) 
    {
        printf("the g_vpws_cfg_node_head->cfg_next is NULL now!!\n"); 
        return -1; 
    }

    while (vpws_cfg_ptr != NULL) 
    {
        
        printf("vpws_cfg_ptr->vpws_cfg_data.nni[0].main.res_1:");
        for (i = 0; i < 6; i++) /* 对变量i进行循环 */
        {
            printf("%x", vpws_cfg_ptr->vpws_cfg_data.nni[0].main.res_1[i]);
        }
        printf("\n");
        point = vpws_cfg_ptr->vpws_cfg_data.nni[0].main.res_1;
        residual_length = sizeof(vpws_cfg_ptr->vpws_cfg_data.nni[0].main.res_1);
        BFD_GET_ULONG(store_bfd_myid, point, residual_length);
        printf("store_bfd_myid=%lu, bfd_myid=%lu\n", store_bfd_myid, bfd_myid);
        if (bfd_myid == store_bfd_myid) 
        {
            printf("ingrees_id = 0x%x, egress_id = 0x%x, lsp_id = 0x%x\n",
                vpws_cfg_ptr->vpws_cfg_data.nni[0].main.ingress, 
                vpws_cfg_ptr->vpws_cfg_data.nni[0].main.egress, 
                vpws_cfg_ptr->vpws_cfg_data.nni[0].main.lsp_id);
            
            tx_lsp_cfg_ptr = find_key_list_tx_lsp_cfg(vpws_cfg_ptr->vpws_cfg_data.nni[0].main.ingress, 
            vpws_cfg_ptr->vpws_cfg_data.nni[0].main.egress, vpws_cfg_ptr->vpws_cfg_data.nni[0].main.lsp_id);

            if (NULL == tx_lsp_cfg_ptr)
            {
                printf("vpws: tx_lsp_cfg_ptr is null!\n");
                return -1;
            }

            if (0 == tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.label_action) /*如果是上话节点*/ 
            { 
               LspRxCfg->OutLspLable = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.lsp_label[0].label;
               
               LspRxCfg->TxSysPortId = (tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.slot << 8) 
                + tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.portnum;

               LspRxCfg->TxTunnelEep = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.encap_id;
               LspRxCfg->RxTunnelEep = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.encap_id;
               LspRxCfg->OutPort = 0x2f;
               
/*vc oam不需要outport*/
#if 1               
               pve_id = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.nni_pve_id;
               
               if (pve_id != 0)
               {
                   pve_interface_ptr = find_key_list_pve_interface_cfg(pve_id);
                   if (NULL == pve_interface_ptr)
                   {
                        //printf("pve_id (%d) does not exist in the pve link list\n",pve_id);
                        
                        sprintf(tp_oam_error_msg,"1: pve_id (%d) does not exist in the pve link list\n",pve_id);
                        BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                        return ERROR;
                   }
                   LspRxCfg->OutPort = pve_interface_ptr->pve_interface_cfg_data.phy_port;
                   LspRxCfg->pve_flag = PVE_MODE_OAM;
                   LspRxCfg->pve_id_or_phy_index = pve_id;
                   memcpy(mac,pve_interface_ptr->pve_interface_cfg_data.mac_dress,6);
                   
                   memcpy(LspRxCfg->des_mac_nni, mac, 6);
                   memcpy(LspRxCfg->src_mac_nni, g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
                   LspRxCfg->src_mac_nni[5] = mac[5];
                   LspRxCfg->src_mac_nni[4] = (LspRxCfg->src_mac_nni[4] & 0xf0) + (mac[4] & 0x0f);
                   
               }
               else
               {
                    if (NULL == g_interface_phy_node_head)
                    {
                        printf("g_interface_phy_node_head is null !\n");
                        return ERROR;
                    }
                    interface_phy_ptr = g_interface_phy_node_head->cfg_next;

                    if (NULL == g_interface_phy_node_head->cfg_next)
                    {
                        printf("g_interface_phy_node_head->cfg_next is null !\n");
                        return ERROR;    
                    }

                    while(interface_phy_ptr != NULL)
                    {
                        if ((LspRxCfg->TxSysPortId == interface_phy_ptr->interface_phy_cfg_data.base_cfg.sysport)
                            && (1 == interface_phy_ptr->interface_phy_cfg_data.eth_cfg.port_tp))
                        {
                            LspRxCfg->OutPort = interface_phy_ptr->interface_phy_cfg_data.base_cfg.portnum;
                            LspRxCfg->pve_flag = PHY_MODE_OAM;
                            LspRxCfg->pve_id_or_phy_index = interface_phy_ptr->index;
                            memcpy(mac,&interface_phy_ptr->interface_phy_cfg_data.eth_cfg.phy_addr[8],6);
                            
                            memcpy(LspRxCfg->des_mac_nni, mac, 6); 
                            memcpy(LspRxCfg->src_mac_nni,
                                g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
                            LspRxCfg->src_mac_nni[5] = mac[5];
                            LspRxCfg->src_mac_nni[4] = (LspRxCfg->src_mac_nni[4] & 0xf0) + (mac[4] & 0x0f);
                            
                            break;
                        }
                        interface_phy_ptr = interface_phy_ptr->cfg_next;
                        
                    }

                    if (NULL == interface_phy_ptr)
                    {
                        //printf("error,pve = 0, cannot find outport from interface phy link list!\n");

                        sprintf(tp_oam_error_msg,"2:error,pve=0, cannot find outport from interface phy link list!\n");
                        BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                        return ERROR;
                    }
               }
#endif


               printf("slot = %d\n",tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.slot);
               printf("portnum = %d\n",tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.portnum);
            } 
            else  /*默认按照下话节点处理*/ 
            {
                LspRxCfg->InLspLable = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.rec_label;
            }

            printf("TxTunnelEep = 0x%x\n",LspRxCfg->TxTunnelEep);

            
            rx_lsp_cfg_ptr = find_key_list_rx_lsp_cfg(vpws_cfg_ptr->vpws_cfg_data.nni[0].main.ingress, 
            vpws_cfg_ptr->vpws_cfg_data.nni[0].main.egress, vpws_cfg_ptr->vpws_cfg_data.nni[0].main.lsp_id);
            
            if (NULL == rx_lsp_cfg_ptr)
            {
                printf("vpws: rx_lsp_cfg_ptr is null!\n");
                return -1;
            }

            if (0 == rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.label_action) /*如果是上话节点*/ 
            { 
                LspRxCfg->InLspLable = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.rec_label;
            } 
            else  /*默认按照下话节点处理*/ 
            {

               LspRxCfg->OutLspLable = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.lsp_label[0].label;
               
               LspRxCfg->TxSysPortId = (rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.slot << 8) 
                + rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.portnum;
               
               LspRxCfg->TxTunnelEep = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.encap_id;
               LspRxCfg->RxTunnelEep = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.encap_id;
               LspRxCfg->OutPort = 0x2f;

#if 1
               pve_id = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.nni_pve_id;

               if (pve_id != 0)
               {
                   pve_interface_ptr = find_key_list_pve_interface_cfg(pve_id);
                   if (NULL == pve_interface_ptr)
                   {
                        //printf("pve_id (%d) does not exist in the pve link list\n",pve_id);
                        
                        sprintf(tp_oam_error_msg,"3: pve_id (%d) does not exist in the pve link list\n",pve_id);
                        BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                        return ERROR;
                   }
                   LspRxCfg->OutPort = pve_interface_ptr->pve_interface_cfg_data.phy_port;
                   LspRxCfg->pve_flag = PVE_MODE_OAM;
                   LspRxCfg->pve_id_or_phy_index = pve_id;
                   memcpy(mac,pve_interface_ptr->pve_interface_cfg_data.mac_dress,6);

                   memcpy(LspRxCfg->des_mac_nni, mac, 6);
                   memcpy(LspRxCfg->src_mac_nni, g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
                   LspRxCfg->src_mac_nni[5] = mac[5];
                   LspRxCfg->src_mac_nni[4] = (LspRxCfg->src_mac_nni[4] & 0xf0) + (mac[4] & 0x0f);
               }
               else
               {
                    if (NULL == g_interface_phy_node_head)
                    {
                        printf("g_interface_phy_node_head is null !\n");
                        return ERROR;
                    }
                    interface_phy_ptr = g_interface_phy_node_head->cfg_next;

                    if (NULL == g_interface_phy_node_head->cfg_next)
                    {
                        printf("g_interface_phy_node_head->cfg_next is null !\n");
                        return ERROR;    
                    }

                    while(interface_phy_ptr != NULL)
                    {
                        if ((LspRxCfg->TxSysPortId == interface_phy_ptr->interface_phy_cfg_data.base_cfg.sysport)
                            && (1 == interface_phy_ptr->interface_phy_cfg_data.eth_cfg.port_tp))
                        {
                            LspRxCfg->OutPort = interface_phy_ptr->interface_phy_cfg_data.base_cfg.portnum;
                            
                            LspRxCfg->pve_flag = PHY_MODE_OAM;
                            LspRxCfg->pve_id_or_phy_index = interface_phy_ptr->index;
                            memcpy(mac,&interface_phy_ptr->interface_phy_cfg_data.eth_cfg.phy_addr[8],6);

                            memcpy(LspRxCfg->des_mac_nni, mac, 6);
                            memcpy(LspRxCfg->src_mac_nni, 
                                g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
                            LspRxCfg->src_mac_nni[5] = mac[5];
                            LspRxCfg->src_mac_nni[4] = (LspRxCfg->src_mac_nni[4] & 0xf0) + (mac[4] & 0x0f);
                            break;
                        }
                        interface_phy_ptr = interface_phy_ptr->cfg_next;
                    }

                    if (NULL == interface_phy_ptr)
                    {
                        //printf("error,pve = 0, cannot find outport from interface phy link list!\n");

                        sprintf(tp_oam_error_msg,"4:error,pve=0,cannot find outport from interface phy link list!\n");
                        BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                        return ERROR;
                    }
               }
#endif

               printf("slot = %d\n",rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.slot);
               printf("portnum = %d\n",rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.portnum);
            }

            printf("TxTunnelEep = 0x%x\n",LspRxCfg->TxTunnelEep);
            

            LspRxCfg->InPwLable = vpws_cfg_ptr->vpws_cfg_data.nni[0].main.rcv_pw_label; 
            LspRxCfg->OutPwLable = vpws_cfg_ptr->vpws_cfg_data.nni[0].main.send_pw_label; 
            LspRxCfg->TxSysLifId = vpws_cfg_ptr->vpws_cfg_data.nni[0].main.logic_id_peer_id;
            LspRxCfg->lag_id = vpws_cfg_ptr->vpws_cfg_data.uni_id[0].lag_id;

            if (LspRxCfg->lag_id != 0)
            {
                LspRxCfg->uni_is_lag = 1;
            }

            LspRxCfg->InSlot = vpws_cfg_ptr->vpws_cfg_data.uni_id[0].slot;
            port_logic_index = vpws_cfg_ptr->vpws_cfg_data.uni_id[0].port_logic_index;
            LspRxCfg->SysPortId = vpws_cfg_ptr->vpws_cfg_data.uni_id[0].sysport;/*仅在vc时有*/
            printf("port_logic_index is %d\n",port_logic_index);
            port_logic_cfg_ptr = find_key_list_port_logic_cfg(port_logic_index);

            if (NULL == port_logic_cfg_ptr)
            {
                //printf("port_logic_cfg_ptr is NULL!\n");

                sprintf(tp_oam_error_msg,"5: port_logic_index = %d(bfdid=%lu) does not exist in port_logic link list\n",
                    port_logic_index,bfd_myid);
                BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                return ERROR;
            }

            phy_port_index = port_logic_cfg_ptr->port_logic_cfg_data.port_cfg_port_logic_data.port_index;
            printf("phy_port_index is %d\n",phy_port_index);
            
            interface_phy_ptr = find_key_list_interface_phy_cfg(phy_port_index);
            if (NULL == interface_phy_ptr)
            {
                //printf("interface_phy_ptr is NULL!\n");

                sprintf(tp_oam_error_msg,"6:phy_port_index = %d(bfdid=%lu) does not exist in phy_port link list\n",
                    phy_port_index,bfd_myid);
                BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                return ERROR;
            }

            LspRxCfg->InPort = interface_phy_ptr->interface_phy_cfg_data.base_cfg.portnum;
            break;
        }

        
        printf("vpws_cfg_ptr->vpws_cfg_data.nni[1].main.res_1:");
        for (i = 0; i < 6; i++) /* 对变量i进行循环 */
        {
            printf("%x", vpws_cfg_ptr->vpws_cfg_data.nni[1].main.res_1[i]);
        }
        printf("\n");
        point = vpws_cfg_ptr->vpws_cfg_data.nni[1].main.res_1;
        residual_length = sizeof(vpws_cfg_ptr->vpws_cfg_data.nni[1].main.res_1);
        BFD_GET_ULONG(store_bfd_myid, point, residual_length);
        printf("store_bfd_myid = %lu, bfd_myid = %lu\n", store_bfd_myid, bfd_myid);
        if (bfd_myid == store_bfd_myid)
        {
            printf("ingrees_id = 0x%x, egress_id = 0x%x, lsp_id = 0x%x\n",
                vpws_cfg_ptr->vpws_cfg_data.nni[1].main.ingress, 
                vpws_cfg_ptr->vpws_cfg_data.nni[1].main.egress, 
                vpws_cfg_ptr->vpws_cfg_data.nni[1].main.lsp_id);
            
            tx_lsp_cfg_ptr = find_key_list_tx_lsp_cfg(vpws_cfg_ptr->vpws_cfg_data.nni[1].main.ingress, 
            vpws_cfg_ptr->vpws_cfg_data.nni[1].main.egress, vpws_cfg_ptr->vpws_cfg_data.nni[1].main.lsp_id);

            if (NULL == tx_lsp_cfg_ptr)
            {
                printf("vpws: tx_lsp_cfg_ptr is null!\n");
                return -1;
            }

            if (0 == tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.label_action) /*如果是上话节点*/ 
            { 
               LspRxCfg->OutLspLable = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.lsp_label[0].label;
               
               LspRxCfg->TxSysPortId = (tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.slot << 8) 
                + tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.portnum;

               LspRxCfg->TxTunnelEep = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.encap_id;
               LspRxCfg->RxTunnelEep = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.encap_id;
               LspRxCfg->OutPort = 0x2f;

#if 1
               pve_id = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.nni_pve_id;
               
               if (pve_id != 0)
               {
                   pve_interface_ptr = find_key_list_pve_interface_cfg(pve_id);
                   if (NULL == pve_interface_ptr)
                   {
                        //printf("pve_id (%d) does not exist in the pve link list\n",pve_id);
                        
                        sprintf(tp_oam_error_msg,"7 :pve_id (%d) does not exist in the pve link list\n",pve_id);
                        BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                        return ERROR;
                   }
                   LspRxCfg->OutPort = pve_interface_ptr->pve_interface_cfg_data.phy_port;
                   LspRxCfg->pve_flag = PVE_MODE_OAM;
                   LspRxCfg->pve_id_or_phy_index = pve_id;
                   memcpy(mac,pve_interface_ptr->pve_interface_cfg_data.mac_dress,6);
                   
                   memcpy(LspRxCfg->des_mac_nni, mac, 6);
                   memcpy(LspRxCfg->src_mac_nni, g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
                   LspRxCfg->src_mac_nni[5] = mac[5];
                   LspRxCfg->src_mac_nni[4] = (LspRxCfg->src_mac_nni[4] & 0xf0) + (mac[4] & 0x0f);
               }
               else
               {
                    if (NULL == g_interface_phy_node_head)
                    {
                        printf("g_interface_phy_node_head is null !\n");
                        return ERROR;
                    }
                    interface_phy_ptr = g_interface_phy_node_head->cfg_next;

                    if (NULL == g_interface_phy_node_head->cfg_next)
                    {
                        printf("g_interface_phy_node_head->cfg_next is null !\n");
                        return ERROR;    
                    }

                    while(interface_phy_ptr != NULL)
                    {
                        if ((LspRxCfg->TxSysPortId == interface_phy_ptr->interface_phy_cfg_data.base_cfg.sysport)
                            && (1 == interface_phy_ptr->interface_phy_cfg_data.eth_cfg.port_tp))
                        {
                            LspRxCfg->OutPort = interface_phy_ptr->interface_phy_cfg_data.base_cfg.portnum;
                            LspRxCfg->pve_flag = PHY_MODE_OAM;
                            LspRxCfg->pve_id_or_phy_index = interface_phy_ptr->index;
                            memcpy(mac,&interface_phy_ptr->interface_phy_cfg_data.eth_cfg.phy_addr[8],6);
                            
                            memcpy(LspRxCfg->des_mac_nni, mac, 6);
                            memcpy(LspRxCfg->src_mac_nni, 
                                g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
                            LspRxCfg->src_mac_nni[5] = mac[5];
                            LspRxCfg->src_mac_nni[4] = (LspRxCfg->src_mac_nni[4] & 0xf0) + (mac[4] & 0x0f);

                            break;
                        }
                        interface_phy_ptr = interface_phy_ptr->cfg_next;
                    }

                    if (NULL == interface_phy_ptr)
                    {
                        //printf("error,pve = 0, cannot find outport from interface phy link list!\n");

                        sprintf(tp_oam_error_msg,"8:error,pve=0,cannot find outport from interface phy link list!\n");
                        BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                        return ERROR;
                    }
               }
#endif

               printf("slot = %d\n",tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.slot);
               printf("portnum = %d\n",tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.portnum);
            } 
            else  /*默认按照下话节点处理*/ 
            {
                LspRxCfg->InLspLable = tx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.rec_label;
            }

            printf("TxTunnelEep = 0x%x\n",LspRxCfg->TxTunnelEep);

            
            rx_lsp_cfg_ptr = find_key_list_rx_lsp_cfg(vpws_cfg_ptr->vpws_cfg_data.nni[1].main.ingress, 
            vpws_cfg_ptr->vpws_cfg_data.nni[1].main.egress, vpws_cfg_ptr->vpws_cfg_data.nni[1].main.lsp_id);
            
            if (NULL == rx_lsp_cfg_ptr)
            {
                printf("vpws: rx_lsp_cfg_ptr is null!\n");
                return -1;
            }

            if (0 == rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.label_action) /*如果是上话节点*/ 
            { 
                LspRxCfg->InLspLable = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.rec_label;
            } 
            else  /*默认按照下话节点处理*/ 
            {

               LspRxCfg->OutLspLable = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.lsp_label[0].label;
               
               LspRxCfg->TxSysPortId = (rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.slot << 8) 
                + rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.portnum;
               
               LspRxCfg->TxTunnelEep = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.encap_id;
               LspRxCfg->RxTunnelEep = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.encap_id;
               LspRxCfg->OutPort = 0x2f;

#if 1               
               pve_id = rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.outputcfg.nni_pve_id;

               if (pve_id != 0)
               {
                   pve_interface_ptr = find_key_list_pve_interface_cfg(pve_id);
                   if (NULL == pve_interface_ptr)
                   {
                        //printf("pve_id (%d) does not exist in the pve link list\n",pve_id);
                        
                        sprintf(tp_oam_error_msg,"9:pve_id (%d) does not exist in the pve link list\n",pve_id);
                        BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                        return ERROR;
                   }
                   LspRxCfg->OutPort = pve_interface_ptr->pve_interface_cfg_data.phy_port;
                   LspRxCfg->pve_flag = PVE_MODE_OAM;
                   LspRxCfg->pve_id_or_phy_index = pve_id;
                   memcpy(mac,pve_interface_ptr->pve_interface_cfg_data.mac_dress,6);
                   
                   memcpy(LspRxCfg->des_mac_nni, mac, 6);
                   memcpy(LspRxCfg->src_mac_nni, g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
                   LspRxCfg->src_mac_nni[5] = mac[5];
                   LspRxCfg->src_mac_nni[4] = (LspRxCfg->src_mac_nni[4] & 0xf0) + (mac[4] & 0x0f);
               }
               else
               {
                    if (NULL == g_interface_phy_node_head)
                    {
                        printf("g_interface_phy_node_head is null !\n");
                        return ERROR;
                    }
                    interface_phy_ptr = g_interface_phy_node_head->cfg_next;

                    if (NULL == g_interface_phy_node_head->cfg_next)
                    {
                        printf("g_interface_phy_node_head->cfg_next is null !\n");
                        return ERROR;    
                    }

                    while(interface_phy_ptr != NULL)
                    {
                        if ((LspRxCfg->TxSysPortId == interface_phy_ptr->interface_phy_cfg_data.base_cfg.sysport)
                            && (1 == interface_phy_ptr->interface_phy_cfg_data.eth_cfg.port_tp))
                        {
                            LspRxCfg->OutPort = interface_phy_ptr->interface_phy_cfg_data.base_cfg.portnum;
                            LspRxCfg->pve_flag = PHY_MODE_OAM;
                            LspRxCfg->pve_id_or_phy_index = interface_phy_ptr->index;
                            memcpy(mac,&interface_phy_ptr->interface_phy_cfg_data.eth_cfg.phy_addr[8],6);

                            memcpy(LspRxCfg->des_mac_nni, mac, 6);
                            memcpy(LspRxCfg->src_mac_nni,
                                g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
                            LspRxCfg->src_mac_nni[5] = mac[5];
                            LspRxCfg->src_mac_nni[4] = (LspRxCfg->src_mac_nni[4] & 0xf0) + (mac[4] & 0x0f);
                            break;
                        }
                        interface_phy_ptr = interface_phy_ptr->cfg_next;
                    }

                    if (NULL == interface_phy_ptr)
                    {
                        //printf("error,pve = 0, cannot find outport from interface phy link list!\n");

                        sprintf(tp_oam_error_msg,"10:error,pve=0,cannot find outport from interface phy link list!\n");
                        BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                        return ERROR;
                    }
               }
#endif

               printf("slot = %d\n",rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.slot);
               printf("portnum = %d\n",rx_lsp_cfg_ptr->lsp_tx_cfg_data.tx_las_base.next_hop.portnum);
            }

            printf("TxTunnelEep = 0x%x\n",LspRxCfg->TxTunnelEep);
            

            LspRxCfg->InPwLable = vpws_cfg_ptr->vpws_cfg_data.nni[1].main.rcv_pw_label; 
            LspRxCfg->OutPwLable = vpws_cfg_ptr->vpws_cfg_data.nni[1].main.send_pw_label; 
            LspRxCfg->TxSysLifId = vpws_cfg_ptr->vpws_cfg_data.nni[1].main.logic_id_peer_id;
            LspRxCfg->lag_id = vpws_cfg_ptr->vpws_cfg_data.uni_id[0].lag_id;

            if (LspRxCfg->lag_id != 0)
            {
                LspRxCfg->uni_is_lag = 1;
            }

            LspRxCfg->InSlot = vpws_cfg_ptr->vpws_cfg_data.uni_id[0].slot;
            port_logic_index = vpws_cfg_ptr->vpws_cfg_data.uni_id[0].port_logic_index;
            
            LspRxCfg->SysPortId = vpws_cfg_ptr->vpws_cfg_data.uni_id[0].sysport;/*仅在vc时有*/
            printf("port_logic_index is %d\n",port_logic_index);
            port_logic_cfg_ptr = find_key_list_port_logic_cfg(port_logic_index);

            if (NULL == port_logic_cfg_ptr)
            {
                sprintf(tp_oam_error_msg,"11: port_logic_index = %d(bfdid=%lu) does not exist in port_logic link list\n",
                    port_logic_index,bfd_myid);
                BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                return ERROR;
            }

            phy_port_index = port_logic_cfg_ptr->port_logic_cfg_data.port_cfg_port_logic_data.port_index;
            printf("phy_port_index is %d\n",phy_port_index);
            
            interface_phy_ptr = find_key_list_interface_phy_cfg(phy_port_index);
            if (NULL == interface_phy_ptr)
            {
                sprintf(tp_oam_error_msg,"12: phy_port_index = %d(bfdid=%lu) does not exist in phy_port link list\n",
                    phy_port_index,bfd_myid);
                BMU_SLOG(BMU_CRIT,TP_OAM_LOG_DIR,tp_oam_error_msg);
                return ERROR;
            }

            LspRxCfg->InPort = interface_phy_ptr->interface_phy_cfg_data.base_cfg.portnum;
            memcpy(LspRxCfg->global_mac, g_ptn_global_cfg_data_store[0].stPtnGlobalBaseCfg.ucGloablMac,6);
            break;
        }    

        vpws_cfg_ptr = vpws_cfg_ptr->cfg_next;
    }

    return SUCCESS;
}
#endif

/*****************************************************************************
 * 函 数 名  : bfd_get_fapid
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 根据槽位获取FAP ID
 * 输入参数  : IN unsigned char slot  槽位
 * 输出参数  : 无
 * 返 回 值  : unsigned int           fap ID
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
unsigned int bfd_get_fapid(IN unsigned char slot)
{
    unsigned int fapid;
    
    if (FRAME_U60 == g_frame_type)
    {
        fapid = g_slot_map_fapid_U60[slot];
    }
    else
    {
        fapid = slot;
    }

    return fapid;
}

/*********************************凑代码注释率********************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 *****************************************************************************
 ****************************************************************************/
