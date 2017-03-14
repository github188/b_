/***********************************************************************************

 * �� �� ��   : bfd_fpga.c
 * �� �� ��   : jiangbo,����
 * ��������   : 2016��10��14��
 * �� �� ��   : 
 * �ļ�����   : BFD FPGA�������
 * ��Ȩ˵��   : Copyright (C) 2000-2016   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 

***********************************************************************************/

#include "bfd.h"

/* FPGAʹ�õ�ȫ�ֱ�����BFD����������һֱ��Ч */
BFD_FPGA_GLOBAL g_bfd_fpga_global;

/*****************************************************************************
 * �� �� ��  : bfd_init_fpga
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ʼ��FPGA����
 * �������  : ��
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_init_fpga()
{
    unsigned short bfd_tree_node_max_num = 0;
    int result = 0;
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
    {
        /* ��ȡFPGA����ַ */
        g_bfd_fpga_global.fpga_base_mcard = ptn_fpga_base_addr_get();
        
        g_bfd_fpga_global.bfd_my_id_tree.level = BFD_TREE_LEVEL;
        bfd_tree_node_max_num = (1 << g_bfd_fpga_global.bfd_my_id_tree.level);
        g_bfd_fpga_global.bfd_my_id_tree.lsp_no_max = bfd_tree_node_max_num - 1;

        /* �����ڴ沢��ʼ�� */
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
        
        /* ��������ʼ�� */    
        result = spm_oamtree_init(bfd_tree_node_max_num, spm_bfd_tree_get_fpga_data,
            &g_bfd_fpga_global.bfd_my_id_tree.node_set);
        if (OK != result)
        {
            BFD_LOG(BMU_ERR, "Bfd node set error, nodenum = %d\n", bfd_tree_node_max_num);
            ret = FPGA_MYID_TREE;
            break;
        }
    } while ( 0 ); /* ѭ��ֱ��0������ */
    
    return ret;
}

/*****************************************************************************
 * �� �� ��  : oam_fpga_32bits_write
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��15��
 * ��������  : дFPGA����(16λд)
 * �������  : IN unsigned long fpga_base_addr  FPGA����ַ
               IN unsigned long fpga_offset     ��ַƫ��
               IN unsigned long data            Ҫд�������
 * �������  : ��
 * �� �� ֵ  : int                              ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
int oam_fpga_16bits_write(IN unsigned long fpga_base_addr, IN unsigned long fpga_offset, IN unsigned short data)
{
    *(unsigned short *)(fpga_base_addr + (fpga_offset << 1)) = data;
    return SUCCESS;
}

/*****************************************************************************
 * �� �� ��  : oam_fpga_32bits_write
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��15��
 * ��������  : дFPGA����(32λд)
 * �������  : unsigned long fpga_base_addr  FPGA����ַ
               unsigned long fpga_offset     ��ַƫ��
               unsigned long data            Ҫд�������
 * �������  : ��
 * �� �� ֵ  : int                           ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
int oam_fpga_32bits_write(unsigned long fpga_base_addr, unsigned long fpga_offset, unsigned long data)
{
    *(unsigned long *)(fpga_base_addr + (fpga_offset << 2)) = data;
    return SUCCESS;
}

/*****************************************************************************
 * �� �� ��  : oam_fpga_16bits_read
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��15��
 * ��������  : ��ȡFPGA����(16λ��ȡ)
 * �������  : IN unsigned long fpga_base_addr  FPGA����ַ
               IN unsigned long fpga_offset     FPGA��ַƫ��
 * �������  : ��
 * �� �� ֵ  : unsigned long                    ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
unsigned short oam_fpga_16bits_read(IN unsigned long fpga_base_addr, IN unsigned long fpga_offset)
{
    unsigned short data = 0;
    data = *(unsigned short *)(fpga_base_addr + (fpga_offset << 1));
    return data;
}

/*****************************************************************************
 * �� �� ��  : oam_fpga_32bits_read
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��15��
 * ��������  : ��ȡFPGA����(32λ��ȡ)
 * �������  : IN unsigned long fpga_base_addr  FPGA����ַ
               IN unsigned long fpga_offset     FPGA��ַƫ��
 * �������  : ��
 * �� �� ֵ  : unsigned long                    ��ȡ����ָ����ַ��ֵ
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
unsigned long oam_fpga_32bits_read(IN unsigned long fpga_base_addr, IN unsigned long fpga_offset)
{
    unsigned long data = 0;
    data = *(unsigned long *)(fpga_base_addr + (fpga_offset << 2));
    return data;
}


/*****************************************************************************
 * �� �� ��  : write_fpga_mmap
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����ָ��λ�õ�FPGA�Ĵ�������(16λд)
 * �������  : IN unsigned long base_offset  FPGAģ�����ַƫ��
               IN unsigned int offset        ��ַƫ��ֵ
               IN unsigned short data        ����
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG                 ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : write_fpga_mmap_32b
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����ָ��λ�õ�FPGA�Ĵ�������(32λд)
 * �������  : IN unsigned long base_offset  FPGAģ�����ַƫ��
               IN unsigned int offset        ��ַƫ��ֵ
               IN unsigned long data         ����
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG                 ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : read_fpga_mmap
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ȡָ��λ�õ�FPGA�Ĵ�������(16λ)
 * �������  : IN unsigned long base_offset  FPGAģ�����ַƫ��
               IN unsigned int offset        ��ַƫ��ֵ
 * �������  : OUT unsigned short *data      ����
 * �� �� ֵ  : int                           ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : read_fpga_mmap_32b
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ȡָ��λ�õ�FPGA�Ĵ�������(32λ)
 * �������  : IN unsigned long base_offset  FPGAģ�����ַƫ��
               IN unsigned int offset        ��ַƫ��ֵ
 * �������  : OUT unsigned long *data       ����
 * �� �� ֵ  : RESULT_BFDCFG                 ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : spm_bfd_tree_set_data
 * �� �� ��  : ����,jiangbo
 * ��������  : 2015��7��21��
 * ��������  : BFD����FPGA��������ֵ
 * �������  : IN NBB_USHORT index                    ��Ŀ��
               IN NBB_ULONG ulDrim                    MY IDֵ
               OUT SPM_OAMTREE_NODE * pstBfdTreeNode  �ڴ�KEYֵ
 * �������  : ��
 * �� �� ֵ  : NBB_INT  ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : spm_bfd_tree_get_fpga_data
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��8��
 * ��������  : ����KEYֵ��ȡFPGA��������KEYֵ
 * �������  : IN SPM_OAMTREE_NODE* oamTreeNode     �ڴ�KEYֵ
               OUT SPM_FPGATREE_DATA *fpgaTreeDate  FPGA������KEYֵ
 * �������  : ��
 * �� �� ֵ  : NBB_INT                              ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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

        fpgaTreeDate->num = 4;  /* ��Ч�ֽ�Ϊ4�ֽ� */
        fpgaTreeDate->usData.bfdTable.index = oamTreeNode->usLspNo;
        fpgaTreeDate->usData.bfdTable.myId_31to28b = (oamTreeNode->ulTunnelId >> 28) & 0xf;
        fpgaTreeDate->usData.bfdTable.myId_27to20b = (oamTreeNode->ulTunnelId >> 20) & 0xff;
        fpgaTreeDate->usData.bfdTable.myId_19to0b = oamTreeNode->ulTunnelId & 0xfffff;

        iRet = SUCCESS;
    }while(0);

    return iRet;
}

/*****************************************************************************
 * �� �� ��  : spm_bfd_rebuild_session_tree_fpgareg
 * �� �� ��  : ����,jiangbo
 * ��������  : 2015��9��23��
 * ��������  : �ؽ�BFD������
 * �������  : ��
 * �������  : ��
 * �� �� ֵ  : NBB_VOID  ��
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
NBB_VOID spm_bfd_rebuild_session_tree_fpgareg()
{
    /* �ؽ��Ự������ */
    spm_oamtree_build(g_bfd_fpga_global.bfd_my_id_tree.level, &g_bfd_fpga_global.bfd_my_id_tree.node_set, 
        g_bfd_fpga_global.bfd_my_id_tree.tree_base, BFD_FPGA_BFD_MODEL_BASE, BFD_FGPA_RCV_SESSION_TREE);
    
    /* ��ҳд���� */
    spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_REV_BASE, OAMTREESWITCHOFFSET, 1);
     
    spm_oamtree_build(g_bfd_fpga_global.bfd_my_id_tree.level, &g_bfd_fpga_global.bfd_my_id_tree.node_set, 
        g_bfd_fpga_global.bfd_my_id_tree.tree_base, BFD_FPGA_BFD_MODEL_BASE, BFD_FGPA_RCV_SESSION_TREE);

    spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_REV_BASE, OAMTREESWITCHOFFSET, 1);

    return;
}

/*****************************************************************************
 * �� �� ��  : bfd_add_fpga_session_tree
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��8��
 * ��������  : ����FPGAʹ�õ�BFD MYID��������Ա
 * �������  : IN unsigned short index  �����±�
               IN unsigned long my_sid  BFD MYID
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
        
        /* �õ�FPGA��������KEY */
        result = spm_bfd_tree_set_data(index, my_sid, &bfd_tree_node);
        if(OK != result)
        {
            ret = FPGA_MYID_TREE;
            break;
        }
        
        /* �ӽڵ� */
        result = spm_oamtree_nodeadd(g_bfd_fpga_global.bfd_my_id_tree.lsp_no_max, &bfd_tree_node,
            &g_bfd_fpga_global.bfd_my_id_tree.node_set);
        if(OK != result)
        {
            ret = FPGA_MYID_TREE;
            break;
        }
        
        /* �����Ự������ */
        spm_bfd_rebuild_session_tree_fpgareg();

        ret = CFG_OK;
    }while(0);

    return ret;
}

/*****************************************************************************
 * �� �� ��  : bfd_del_fpga_session_tree
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��8��
 * ��������  : ɾ��FPGAʹ�õ�BFD MYID��������Ա
 * �������  : IN unsigned short index  FPGA�����±�
               IN unsigned long my_sid  BFD MYID
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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

        /* �õ�FPGA��������KEY */
        result = spm_bfd_tree_set_data(index, my_sid, &bfd_tree_node);
        if(OK != result)
        {
            ret = FPGA_MYID_TREE;
            break;
        }
            
        /* ɾ���ڵ� */
        result = spm_oamtree_nodedel(g_bfd_fpga_global.bfd_my_id_tree.lsp_no_max, &bfd_tree_node,
            &g_bfd_fpga_global.bfd_my_id_tree.node_set);
        if(OK != result)
        {
            ret = FPGA_MYID_TREE;
            break;
        }
                        
        /* �ؽ��Ự������ */
        spm_bfd_rebuild_session_tree_fpgareg();
        
        ret = CFG_OK;
    }while(0);
        
    return ret;
}

/*****************************************************************************
 * �� �� ��  : bfd_get_fpga_info
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ���ݶ��������ȡFPGA��Ҫ����Ϣ
 * �������  : IN unsigned short index              FPGA��������
               IN BFD_BASIC_DATA *cfg               BFD������
               IN TP_OAM_LSP_CFG *oam_traffic_info  LSP����
 * �������  : OUT BFD_FPGA_INFO *fpga_info         FPGA��Ϣ
 * �� �� ֵ  : 
 * ���ù�ϵ  : 
 * ��    ��  : 

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

        switch ( cfg->bfd_frame_type ) /* BFD��֡���� */
        {
            /* �����BFD_PW_type2������Ҫ fpga_info->send_cfg.label.ach = 0x10000021; */
            
            case BFD_CFG_LSP:
                fpga_info->send_cfg.frame_type = BFD_PW_type1;
                fpga_info->send_cfg.label.pw_label = 13;    /* GAL��ǩֵ */
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
        if (TRUE != cfg->bfd_enable)/* ���Ͳ�ʹ�� */
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
 * �� �� ��  : bfd_set_fpga
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����BFD FPGA�Ĵ���
 * �������  : IN BFD_FPGA_INFO *fpga_info  FPGA��Ϣ
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG                ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga(IN BFD_FPGA_INFO *fpga_info)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
    {
        if(NULL == fpga_info)
        {
            BFD_LOG(BMU_ERR, "fpga_info is NULL\n");
            ret = PARAM_ERROR;
            break;
        }        

        /* ���FPGAʹ�õ�BFD MYID�Ự��������Ա */
        ret = bfd_add_fpga_session_tree(fpga_info->index, fpga_info->send_cfg.discr.my_id);

        /* дMAC��ַ */
        ret = bfd_set_fpga_mac(fpga_info->index, &(fpga_info->send_cfg.eth_mac));

        /* �޸��շ���ʱ�������BFD״̬ */
        ret = bfd_set_fpga_state_interval(fpga_info->index, &(fpga_info->send_cfg.state),
            &(fpga_info->send_cfg.interval), FALSE);

        /* �޸�IPͷ */
        ret = bfd_set_fpga_ip(fpga_info->index, &(fpga_info->send_cfg.ip));

        /* �޸�UDPͷ */
        ret = bfd_set_fpga_udp(fpga_info->index, &(fpga_info->send_cfg.udp));

        /* �޸�BFD�������� */
        ret = bfd_set_fpga_bfd_discr(fpga_info->index, &(fpga_info->send_cfg.discr));

        /* �޸ı�ǩ */
        ret = bfd_set_fpga_label(fpga_info->index, fpga_info->send_cfg.frame_type, &(fpga_info->send_cfg.label));

        /* �޸�BFD������Ϣ */
        ret = bfd_set_fpga_function(fpga_info->index, fpga_info->send_cfg.frame_type, fpga_info->send_cfg.ip.type, 
            &(fpga_info->send_cfg.function));

        /* �޸�ITMHͷ��sysport */
        ret = bfd_set_fpga_sysport(fpga_info->index, &(fpga_info->send_cfg.sysport));
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;
}

/*****************************************************************************
 * �� �� ��  : bfd_set_fpga_mac
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����ָ��FPGAλ�õ�BFD MAC��ַ
 * �������  : IN unsigned short index  �����±�
               IN BFD_ETH_MAC *eth_mac  MAC��ַ
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_mac(IN unsigned short index, IN BFD_ETH_MAC *eth_mac)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned int i = 0;
    unsigned short data = 0;
    BFD_FPGA_REG_SMAC1 smac1;
    BFD_FPGA_REG_ADAPT_SMAC1 adapt_smac;

    do /* ��ʼѭ�� */
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

        for (i = 0; i < (MAC_LENGTH >> 1); i ++) /* �Ա���i����ѭ�� */
        {
            data = (eth_mac->des_mac[i << 1] << 8) + eth_mac->des_mac[(i << 1) + 1];
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DMAC, 4 * index + i + 1, data);
        }

        
        /* ԴMAC��SMAC[42:32]��Ҫ�浽BFD����ģ�飬Ϊ�˸��������ԴMAC�� */
        adapt_smac.smac = ((eth_mac->src_mac[0] & 0x7) << 8) + eth_mac->src_mac[1];  /* ȡMAC��ַ��[42:32]���� */
        data = *(unsigned short*)(&adapt_smac);
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FGAP_BFD_ADAPT_SMAC, index, data);

        /* ԴMAC��SMAC[42:32]��Ҫ�滻������������Ϊ�˸�FPGA��BFD����ģ�����sysportʱ������ */
        smac1.index = index;
        smac1.smac = (eth_mac->src_mac[0] >> 3) & 0x1f;  /* ȡMAC��ַ��ǰ5���� */
        data = *(unsigned short*)(&smac1);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_SMAC, BFD_FPGA_MAC_HIGH(index), data);

        /* ԴMAC�ĺ�4���ֽ���������MAC��ַ */
        for (i = 1; i < (MAC_LENGTH >> 1); i ++) /* �Ա���i����ѭ�� */
        {
            data = (eth_mac->src_mac[i << 1] << 8) + eth_mac->src_mac[(i << 1) + 1];
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_SMAC, 4 * index + i + 1, data);
        }
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

/*****************************************************************************
 * �� �� ��  : bfd_get_fpga_mac
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����ָ��FPGAλ�õ�BFD MAC��ַ
 * �������  : IN unsigned short index  �����±�
               IN BFD_ETH_MAC *eth_mac  MAC��ַ
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_mac(IN unsigned short index, OUT BFD_ETH_MAC *eth_mac, OUT unsigned short *fpga_reg_index)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data = 0;
    BFD_FPGA_REG_SMAC1 smac1;
    BFD_FPGA_REG_ADAPT_SMAC1 adapt_smac;

    do /* ��ʼѭ�� */
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

        /* Ŀ��MAC */        
        data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DMAC, BFD_FPGA_MAC_HIGH(index));
        BFD_GET_UCHAR_FORM_USHORT(data, eth_mac->des_mac[0], eth_mac->des_mac[1]);
        data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DMAC, BFD_FPGA_MAC_MIDDLE(index));
        BFD_GET_UCHAR_FORM_USHORT(data, eth_mac->des_mac[2], eth_mac->des_mac[3]);
        data = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DMAC, BFD_FPGA_MAC_LOW(index));
        BFD_GET_UCHAR_FORM_USHORT(data, eth_mac->des_mac[4], eth_mac->des_mac[5]);

        /* ԴMAC */        
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

/*****************************************************************************
 * �� �� ��  : bfd_set_fpga_state_interval
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����ָ��FPGAλ�õ�BFD ״̬��ʱ�����
 * �������  : IN unsigned short index    �����±�
               IN BFD_STATE *state        BFD״̬
               IN BFD_INTERVAL *interval  ʱ�����
               IN NBB_BOOL is_modify      �Ƿ��޸�
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG              ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_state_interval(IN unsigned short index, IN BFD_STATE *state,
    IN BFD_INTERVAL *interval, IN NBB_BOOL is_modify)
{
    NBB_USHORT   sta_diag_data = 0;
    NBB_USHORT   interval_data = 0;
    BFD_FPGA_REG_STATE_DIAG sta_diag_stu;
    BFD_FPGA_REG_INTERVAL interval_stu;

    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
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
        
        /* BFD����ģ��Ĵ���ƫ��0xd000+2*N+0x0��
           Bit15-11��BFD��������루Diag�����������ͷ����һ�λỰdown��ԭ��
           Bit10-9��BFD��ǰ�Ự״̬��Sta����0-AdminDown��1-Down��2-Init��3-Up��
           Bit7-0�����ʱ�䱶����Detect Mult����Ĭ��ֵΪ3 */
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DIAG_STA_DM_INTERVAL, BFD_FPGA_ULONG_HIGH(index),
            sta_diag_data);

        OS_MEMSET(&interval_stu, 0, sizeof(interval_stu));
        interval_stu.usRxInterval = interval->required_min_rx_interval;
        interval_stu.usTxInterval = interval->desired_min_tx_interval;
        interval_stu.usModify     = is_modify; /*��� �ֽ� �����壬20160513*/
        interval_data = *(NBB_USHORT *)(&interval_stu);
        
        /* BFD����ģ��Ĵ���ƫ��0xd000+2*N+0x1��
           Bit0������2��������κ�һ����Ҫ���޸ģ������д'1'������ͶƱ���̡���FPGA�ڲ����㡣 */
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_DIAG_STA_DM_INTERVAL, BFD_FPGA_ULONG_LOW(index),
            interval_data);

        /*Bit1-0��
           ����֧�ֵ���С���ͼ����Desired Min TX Interval��
           �ͱ���֧�ֵ���С���ռ����Required Min RX Interval�����κ�һ����Ҫ���޸ģ�
           �����д'0b11'������ͶƱ���̡���FPGA�ڲ����㡣*/
        if(TRUE == is_modify)  /*FPGA�Լ��Ż�������󣬸�֪Ӧ�÷ſ�*/
        {
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_INTERVAL_MODIFY, index, 0x3);
        }

        ret = CFG_OK;
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

/*****************************************************************************
 * �� �� ��  : bfd_get_fpga_state_interval
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ȡָ��FPGAλ�õ�BFD ״̬��ʱ�����
 * �������  : IN unsigned short index              �����±�
 * �������  : OUT BFD_FPGA_REG_STATE_DIAG *state   BFD״̬
               OUT BFD_FPGA_REG_INTERVAL *interval  ʱ�����
 * �� �� ֵ  : RESULT_BFDCFG                        ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_state_interval(IN unsigned short index, OUT BFD_FPGA_REG_STATE_DIAG *state_diag,
    OUT BFD_FPGA_REG_INTERVAL *interval)
{
    NBB_USHORT   sta_diag_data = 0;
    NBB_USHORT   interval_data = 0;

    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}


/*****************************************************************************
 * �� �� ��  : bfd_set_fpga_ip
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����ָ��FPGAλ�õ�BFD IPͷ
 * �������  : IN unsigned short index  �����±�
               IN BFD_IP_HEAD *ip       IPͷ��Ϣ
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_ip(IN unsigned short index, IN BFD_IP_HEAD *ip)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

/*****************************************************************************
 * �� �� ��  : bfd_get_fpga_ip
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ȡָ��FPGAλ�õ�BFD IPͷ
 * �������  : IN unsigned short index  �����±�
 * �������  : OUT BFD_IP_HEAD *ip      IPͷ��Ϣ
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_ip(IN unsigned short index, OUT BFD_IP_HEAD *ip_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_FPGA_REG_IP_HEAD_VER_TOS ver_tos;
    unsigned short data = 0;

    do /* ��ʼѭ�� */
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

                /* IP����ʶ���ˣ���IP��ص����мĴ���ȫȡһ�� */
                bfd_get_fpga_ipv6(index, ip_head);
                ip_head->type = BFD_IP_NONE;
                
                ret = IP_TYPE_ERR;
        }
        BFD_CHECK_RETURN(ret);
        
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}


/*****************************************************************************
 * �� �� ��  : bfd_set_fpga_ipv4
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����ָ��FPGAλ�õ�BFD IPv4ͷ
 * �������  : IN unsigned short index  �����±�
               IN BFD_IP_HEAD *ip       IP��Ϣ
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_ipv4(IN unsigned short index, IN BFD_IP_HEAD *ip)
{
    RESULT_BFDCFG ret = CFG_OK;
    NBB_USHORT ip_type_data = 0;
    NBB_USHORT ttl_data = 0;
    NBB_USHORT data_high = 0;
    NBB_USHORT data_low = 0;
    BFD_FPGA_REG_IP_HEAD_VER_TOS ip_ver_tos;

    do /* ��ʼѭ�� */
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

        ip_ver_tos.version = 4;     /* �汾IPv4 */
        ip_ver_tos.head_len = 5;    /* ����20�ֽ� */
        ip_ver_tos.recedence = 7;   /* ���ȼ� */
        ip_ver_tos.tos = ip->tos;
        ip_type_data = *(NBB_SHORT *)(&ip_ver_tos);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPv4_TOS, index, ip_type_data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_TOTAL_LEN, index, ip->total_length);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_IDENTIFIER, index, 0);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_IPV4_FLAG_FRAMOFF, index, 0);
        if (0xE0000000 == (ip->local_ip[3] & 0xEFFFFF00)) /* 224.0.0.0/24��ַ���鲥TTL����Ϊ1 */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

/*****************************************************************************
 * �� �� ��  : bfd_get_fpga_ipv4
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ȡָ��FPGAλ�õ�BFD IPv4ͷ(���ܱ�ֱ�ӵ��ã���������bfd_get_fpga_ip)
 * �������  : IN unsigned short index   �����±�
 * �������  : OUT BFD_IP_HEAD *ip_head  IP��Ϣ
 * �� �� ֵ  : RESULT_BFDCFG             ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_ipv4(IN unsigned short index, OUT BFD_IP_HEAD *ip_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_high = 0;
    unsigned short data_low = 0;
    BFD_FPGA_REG_IP_HEAD_VER_TOS ver_tos;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}


/*****************************************************************************
 * �� �� ��  : bfd_set_fpga_ipv6
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����ָ��FPGAλ�õ�BFD IPv6ͷ
 * �������  : IN unsigned short index  �����±�
               IN BFD_IP_HEAD *ip       IP��Ϣ
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_ipv6(IN unsigned short index, IN BFD_IP_HEAD *ip)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_high = 0;
    unsigned short data_low = 0;

    do /* ��ʼѭ�� */
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

        /* ����ԴIP */
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
        
        /* ����Ŀ��IP */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

/*****************************************************************************
 * �� �� ��  : bfd_get_fpga_ipv6
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ȡָ��FPGAλ�õ�BFD IPv6ͷ(���ܱ�ֱ�ӵ��ã���������bfd_get_fpga_ip)
 * �������  : IN unsigned short index   �����±�
 * �������  : OUT BFD_IP_HEAD *ip_head  IP��Ϣ
 * �� �� ֵ  : RESULT_BFDCFG             ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_ipv6(IN unsigned short index, OUT BFD_IP_HEAD *ip_head)
{
    RESULT_BFDCFG ret = CFG_OK;
    NBB_USHORT data_high = 0;
    NBB_USHORT data_low = 0;

    do /* ��ʼѭ�� */
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

        /* ��ȡԴIP */
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

        /* ��ȡĿ��IP */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

/*****************************************************************************
 * �� �� ��  : bfd_set_fpga_udp
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����ָ��FPGAλ�õ�BFD UDP��Ϣ
 * �������  : IN unsigned short index  �����±�
               IN BFD_UDP_HEAD *udp     UPD��Ϣ
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_udp(IN unsigned short index, IN BFD_UDP_HEAD *udp)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}


/*****************************************************************************
 * �� �� ��  : bfd_get_fpga_udp
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ȡָ��FPGAλ�õ�BFD UDP��Ϣ
 * �������  : IN unsigned short index   �����±�
 * �������  : OUT BFD_UDP_HEAD *udp     UPD��Ϣ
 * �� �� ֵ  : RESULT_BFDCFG             ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_udp(IN unsigned short index, OUT BFD_UDP_HEAD *udp)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}


/*****************************************************************************
 * �� �� ��  : bfd_set_fpga_bfd_discr
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����ָ��FPGAλ�õ�BFD������
 * �������  : IN unsigned short index  �����±�
               IN BFD_DISCR *discr      ������
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_bfd_discr(IN unsigned short index, IN BFD_DISCR *discr)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
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
        
        /* BFD����ģ��Ĵ���ƫ��0xc000+2*N+0x0��Bit15-0��BFD����Զ�˻Ự��ʶ����Your Discriminator������16λ�� */
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_YID, BFD_FPGA_ULONG_HIGH(index),
            (discr->peer_id >> 16)&DRV_USHORT_INVALID);
        
        /* BFD����ģ��Ĵ���ƫ��0xc000+2*N+0x1��Bit15-0��BFD����Զ�˻Ự��ʶ����Your Discriminator������16λ�� */
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_YID, BFD_FPGA_ULONG_LOW(index),
            (discr->peer_id)&DRV_USHORT_INVALID);
        
        ret = CFG_OK;
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

/*****************************************************************************
 * �� �� ��  : bfd_get_fpga_bfd_discr
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��17��
 * ��������  : ��ȡָ��FPGAλ�õ�BFD������
 * �������  : IN unsigned short index  �����±�
 * �������  : OUT BFD_DISCR *discr     ������
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_bfd_discr(IN unsigned short index, OUT BFD_DISCR *discr)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_high = 0;
    unsigned short data_low = 0;

    do /* ��ʼѭ�� */
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
        
        /* BFD����ģ��Ĵ���ƫ��0xc000+2*N+0x0��Bit15-0��BFD����Զ�˻Ự��ʶ����Your Discriminator������16λ�� */
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_YID, BFD_FPGA_ULONG_HIGH(index));
        
        /* BFD����ģ��Ĵ���ƫ��0xc000+2*N+0x1��Bit15-0��BFD����Զ�˻Ự��ʶ����Your Discriminator������16λ�� */
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_YID, BFD_FPGA_ULONG_LOW(index));
        discr->peer_id = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        
        ret = CFG_OK;
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}


/*****************************************************************************
 * �� �� ��  : bfd_set_fpga_label
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����ָ��FPGAλ�õ�BFD��ǩ
 * �������  : IN unsigned short index      �����±�
               IN unsigned char frame_type  BFD��֡����
               IN BFD_LABEL *label          ��ǩ
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG                ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
    

    do /* ��ʼѭ�� */
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

        switch ( frame_type ) /* BFD���ķ�֡���� */
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

                /* û��break,�����ı�ǩ���ú�pw_type1��ͬ */
                
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

/*****************************************************************************
 * �� �� ��  : bfd_get_fpga_label
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����ָ��FPGAλ�õ�BFD��ǩ
 * �������  : IN unsigned short index           �����±�
 * �������  : OUT BFD_FPGA_MPLS_LABEL *label    ��ǩ
 * �� �� ֵ  : RESULT_BFDCFG                ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_label(IN unsigned short index, OUT BFD_FPGA_MPLS_LABEL *label)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_high = 0;
    unsigned short data_low = 0;
    NBB_ULONG    label_data = 0;

    do /* ��ʼѭ�� */
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
        
        /* ��ȡFPGA������ǩ */
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_LSP_LABEL, BFD_FPGA_ULONG_HIGH(index));
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_LSP_LABEL, BFD_FPGA_ULONG_LOW(index));
        label_data = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        label->lsp_label = *((BFD_MPLS_LABEL*)&label_data);
        
        /* ��ȡFPGA���ڲ��ǩ */
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_PW_LABEL, BFD_FPGA_ULONG_HIGH(index));
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_PW_LABEL, BFD_FPGA_ULONG_LOW(index));
        label_data = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        label->pw_label = *((BFD_MPLS_LABEL*)&label_data);

        
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_ACH_LABEL, BFD_FPGA_ULONG_HIGH(index));
        data_low = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_ACH_LABEL, BFD_FPGA_ULONG_LOW(index));
        label_data = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
        label->ach = label_data;

        ret = CFG_OK;
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}


/*****************************************************************************
 * �� �� ��  : bfd_set_fpga_function
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����ָ��FPGAλ�õ�BFD������Ϣ
 * �������  : IN unsigned short index      �����±�
               IN unsigned char frame_type  BFD��֡����
               IN unsigned char ip_type     IP����
               IN BFD_FUNCTION *function    BFD������Ϣ
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG                ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_function(IN unsigned short index, IN unsigned char frame_type,
    IN unsigned char ip_type, IN BFD_FUNCTION *function)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_FPGA_REG_FUCTION fuction_info;
    NBB_USHORT   fuction_data = 0;

    do /* ��ʼѭ�� */
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

        /* UDP�˿ں� */
        fuction_info.usUDPtype = function->detection_type;

        /* �жϷ�װ���� */
        fuction_info.usSendType = frame_type;

        /* VLANʹ�� */
        fuction_info.usVlanAble = function->vlan_able;
        fuction_info.usVlanNum = function->vlan_num;

        /* PW ACH��װ��ʽ */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

/*****************************************************************************
 * �� �� ��  : bfd_get_fpga_function
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ȡָ��FPGAλ�õ�BFD������Ϣ
 * �������  : IN unsigned short index      �����±�
 * �������  : OUT BFD_FPGA_REG_FUCTION *fuction_info  BFD������Ϣ
 * �� �� ֵ  : RESULT_BFDCFG                ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_function(IN unsigned short index, OUT BFD_FPGA_REG_FUCTION *fuction_info)
{
    RESULT_BFDCFG ret = CFG_OK;
    NBB_USHORT   fuction_data = 0;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

/*****************************************************************************
 * �� �� ��  : bfd_set_fpga_sysport
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��8��
 * ��������  : ����ָ��FPGAλ�õ�sysport
 * �������  : IN unsigned short index  �����±�
               IN BFD_SYSPORT *sysport  ITMHͷ�����sysport
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_fpga_sysport(IN unsigned short index, IN BFD_SYSPORT *sysport)
{
    RESULT_BFDCFG ret = CFG_OK;
    NBB_USHORT   data = 0;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}


/*****************************************************************************
 * �� �� ��  : bfd_get_fpga_sysport
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��8��
 * ��������  : ��ȡָ��FPGAλ�õ�sysport
 * �������  : IN unsigned short index   �����±�
 * �������  : OUT BFD_SYSPORT *sysport  ITMHͷ�����sysport
 * �� �� ֵ  : RESULT_BFDCFG             ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_fpga_sysport(IN unsigned short index, OUT BFD_SYSPORT *sysport)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}


RESULT_BFDCFG bfd_get_fpga_send_count(IN unsigned short index, OUT unsigned short *sent_count)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}


RESULT_BFDCFG bfd_get_fpga_send_work_interval(IN unsigned short index, OUT unsigned short *send_interval)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}


/*****************************************************************************
 * �� �� ��  : bfd_del_fpga
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ɾ��ָ��λ�õ�BFD
 * �������  : IN unsigned short index  �����±�
               IN unsigned long my_sid  BFD MYID
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_del_fpga(IN unsigned short index, IN unsigned long my_sid)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        /* ɾ��FPGAʹ�õ�BFD MYID�Ự��������Ա */
        ret = bfd_del_fpga_session_tree(index, my_sid);

        /* ���FPGA�Ĵ��� */
        ret = bfd_clear_fpga(index);
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;
}

/*****************************************************************************
 * �� �� ��  : bfd_clear_fpga
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ���ָ��λ�õ�FPGA�Ĵ���
 * �������  : IN unsigned short index  ��������
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
RESULT_BFDCFG bfd_clear_fpga(IN unsigned short index)
{
    RESULT_BFDCFG ret = CFG_OK;
    NBB_USHORT data = 0;

    do /* ��ʼѭ�� */
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong,max is %d!\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        
        /************************************* BFD���ջỰ״̬��ģ�� ******************************************/
        /* BFD_FPGA_SESSION_DIAG_STATE ֻ�� */
        /* BFD_FPGA_SESSION_WORK_INTERVAL_LOW ֻ�� */
        /* BFD_FPGA_SESSION_WORK_INTERVAL_HIGH ֻ�� */
        
        /* BFD_FPGA_SESSION_RECV_COUNT FPGA���� */
        spm_oamtree_s16read(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_RECV_COUNT, index);
        
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_SEND_STATE_DIAG, index, data);

        /* BFD_FPGA_SESSION_RECV_STATE_DIAG ֻ�� */
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_REQUIRED_MYID, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_REQUIRED_MYID_SWITCH, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_UP_TO_DOWN_STA, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_CHEKSUM, index, data);

        /*  BFD_FPGA_SESSION_ERROR_COUNT FPGA���� */
        spm_oamtree_s16read(BFD_FPGA_BFD_ADAPT_BASE, BFD_FPGA_SESSION_ERROR_COUNT, index);

        /* BFD_FPGA_SESSION_INTERVAL_NOT_MATCHֻ�� */
        /****************************************************************************************************/
        
        /**********************************************  BFDģ�� **********************************************/
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
        
        /* BFD_FPGA_SEND_WORK_INTERVAL ֻ�� */
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_LSP_LABEL, BFD_FPGA_ULONG_HIGH(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_LSP_LABEL, BFD_FPGA_ULONG_LOW(index), data);
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_PW_LABEL, BFD_FPGA_ULONG_HIGH(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_PW_LABEL, BFD_FPGA_ULONG_LOW(index), data);
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_ACH_LABEL, BFD_FPGA_ULONG_HIGH(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SEND_ACH_LABEL, BFD_FPGA_ULONG_LOW(index), data);
        
        /* BFD_FPGA_SEND_TIMER_DOWN_COUNT ֻ�� */
        /* BFD_FPGA_SEND_REMOTE_DOWN_COUNT ֻ�� */
        /* BFD_FPGA_SEND_INTERVAL_MODIFY �Ĵ����Զ���� */
        /* BFD_FPGA_SEND_COUNT ֻ�� */
        
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_RCV_MYID, BFD_FPGA_ULONG_HIGH(index), data);
        spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_RCV_MYID, BFD_FPGA_ULONG_LOW(index), data);
        
        /****************************************************************************************************/

        /********************************************* BFD����ģ�� ******************************************/
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FGAP_BFD_ADAPT_SMAC, index, data);
        spm_oamtree_s16write(BFD_FPGA_BFD_ADAPT_BASE, BFD_FGAP_BFD_ADAPT_SYSPORT, index, data);
        
        /****************************************************************************************************/

        ret = CFG_OK;
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;
}

RESULT_BFDCFG bfd_get_fpga_session_state(IN unsigned short index, OUT BFD_FPGA_REG_DIAG_STATE *diag_state)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data = 0;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}


RESULT_BFDCFG bfd_get_fpga_session_work_interval(IN unsigned short index, OUT unsigned long *recv_interval)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_low = 0;
    unsigned short data_high = 0;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

RESULT_BFDCFG bfd_get_fpga_session_recv_count(IN unsigned short index, OUT unsigned short *recv_count)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

RESULT_BFDCFG bfd_set_fpga_session_up_to_down_sta(IN unsigned short index, IN NBB_BOOL enable)
{
    RESULT_BFDCFG ret = CFG_OK;
    SPM_BFD_UP_TO_DOWN_STA up_to_down_state;
    unsigned short data = 0;
    
    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    

}


RESULT_BFDCFG bfd_get_fpga_session_up_to_down_sta(IN unsigned short index, OUT SPM_BFD_UP_TO_DOWN_STA *up_to_down_state)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data = 0;

    do /* ��ʼѭ�� */
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
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

RESULT_BFDCFG bfd_set_fpga_session_anti_attack(IN unsigned short index, IN unsigned long your_id, IN NBB_BOOL enable)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_high = 0;
    unsigned short data_low = 0;

    do /* ��ʼѭ�� */
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
                BFD_FPGA_ULONG_HIGH(index), data_low);      /* FPGA����ļĴ����Ƿ��� */
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID,
                BFD_FPGA_ULONG_LOW(index), data_high);      /* FPGA����ļĴ����Ƿ��� */
                
            /* ����YID���հ�MYIDƥ����λʹ�� */            
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID_SWITCH, index, 1);
        }
        else
        {
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID,
                BFD_FPGA_ULONG_HIGH(index), 0);
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID,
                BFD_FPGA_ULONG_LOW(index), 0);
                
            /* ����YID���հ�MYIDƥ����λʹ�� */            
            spm_oamtree_s16write(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID_SWITCH, index, 0);
        }
        
        ret = CFG_OK;
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

RESULT_BFDCFG bfd_get_fpga_session_anti_attack(IN unsigned short index,
    OUT unsigned long *your_id,
    OUT unsigned short *enable)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short data_high = 0;
    unsigned short data_low = 0;

    do /* ��ʼѭ�� */
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
            BFD_FPGA_ULONG_HIGH(index));        /* FPGA����ļĴ����Ƿ��� */
        data_high = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID,
            BFD_FPGA_ULONG_LOW(index));         /* FPGA����ļĴ����Ƿ��� */
        *your_id = BFD_GET_ULONG_FROM_TWO_USHORT(data_high, data_low);
            
        /* ����YID���հ�MYIDƥ����λ */            
        *enable = spm_oamtree_s16read(BFD_FPGA_BFD_MODEL_BASE, BFD_FPGA_SESSION_REQUIRED_MYID_SWITCH, index);
        
        ret = CFG_OK;
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}


RESULT_BFDCFG bfd_get_fpga_capture_choose(OUT unsigned short *cap_choose)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
    {        
        if(NULL == cap_choose)
        {
            BFD_LOG(BMU_ERR, "cap_choose is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        *cap_choose = spm_oamtree_s16read(BFD_FPGA_GENERAL_BASE, 0, BFD_FPGA_PACKET_CAPTURE_CHOOSE);

        ret = CFG_OK;
    } while ( 0 ); /* ѭ��ֱ��0������ */
        
    return ret;    
}

