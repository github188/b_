/***********************************************************************************

 * 文 件 名   : bfd_cfg_proc.c
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年10月12日
 * 版 本 号   : 
 * 文件描述   : BFD配置处理
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#include "bfd.h"

/*****************************************************************************
 * 函 数 名  : bfd_init
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月8日
 * 函数功能  : BFD初始化总入口
 * 输入参数  : 无
 * 输出参数  : 无
 * 返 回 值  : NBB_INT错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
NBB_INT bfd_init()
{
    RESULT_BFDCFG ret = CFG_OK;
    NBB_INT   result = OK;

    ret = bfd_init_get_extern_info();

    ret = bfd_init_fpga();

    ret = bfd_init_database();

    //reg_block_by_external_module(BFD_CFG_BLOCK_NUM, BFD_KEY_LEN, 110, BFD_MAX_ALL_SESNUM, bfd_active_cfg_process);

    return result;
}

/*****************************************************************************
 * 函 数 名  : bfd_decode_cfg
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 解析单盘协议
 * 输入参数  : IN unsigned char **cfg_data  根据单盘协议组成的BFD数据
 * 输出参数  : OUT BFD_CFG *cfg             BFD配置块
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
int bfd_decode_cfg(IN unsigned char **cfg_data, OUT BFD_CFG *cfg)
{
    int ret = CFG_OK;
    unsigned char *cfg_start_addr = NULL;
    unsigned long residual_length = 0;

    do
    {
        if(NULL == cfg_data)
        {
            BFD_LOG(BMU_ERR, "cfg_data is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == cfg_data)
        {
            BFD_LOG(BMU_ERR, "cfg_data is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        cfg_start_addr = *cfg_data;

        if(NULL == cfg_start_addr)
        {
            BFD_LOG(BMU_ERR, "cfg_date point to a NULL address\n");
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(cfg, 0, sizeof(BFD_CFG));

        residual_length = 13;   /* 配置块头长度 */

        BFD_GET_ULONG(cfg->key, cfg_start_addr, residual_length);
        BFD_GET_UCHAR(cfg->op, cfg_start_addr, residual_length);
        BFD_GET_ULONG(cfg->serial_num, cfg_start_addr, residual_length);
        BFD_GET_ULONG(cfg->len, cfg_start_addr, residual_length);
        residual_length = cfg->len;     /*  配置块内容长度 */
        BFD_GET_USHORT(cfg->base_cfg.head.type, cfg_start_addr, residual_length);
        BFD_GET_USHORT(cfg->base_cfg.head.len, cfg_start_addr, residual_length);
        BFD_GET_ULONG(cfg->base_cfg.cfg.my_sid, cfg_start_addr, residual_length);
        BFD_GET_ULONG(cfg->base_cfg.cfg.peer_sid, cfg_start_addr, residual_length);
        BFD_GET_UCHAR(cfg->base_cfg.cfg.bfd_enable, cfg_start_addr, residual_length);
        BFD_GET_UCHAR(cfg->base_cfg.cfg.detect_method, cfg_start_addr, residual_length);
        BFD_GET_UCHAR(cfg->base_cfg.cfg.bfd_frame_type, cfg_start_addr, residual_length);
        BFD_GET_UCHAR(cfg->base_cfg.cfg.service_type, cfg_start_addr, residual_length);
        BFD_GET_USHORT(cfg->base_cfg.cfg.udp_src_port, cfg_start_addr, residual_length);
        BFD_GET_BUF(cfg->base_cfg.cfg.local_ip, cfg_start_addr, sizeof(cfg->base_cfg.cfg.local_ip), residual_length);
        BFD_GET_BUF(cfg->base_cfg.cfg.remote_ip, cfg_start_addr, sizeof(cfg->base_cfg.cfg.remote_ip), residual_length);
        BFD_GET_UCHAR(cfg->base_cfg.cfg.peer_sid_selflearn_enable, cfg_start_addr, residual_length);
        BFD_GET_ULONG(cfg->base_cfg.cfg.dmti, cfg_start_addr, residual_length);
        BFD_GET_ULONG(cfg->base_cfg.cfg.rmri, cfg_start_addr, residual_length);
        BFD_GET_USHORT(cfg->base_cfg.cfg.dete_mul, cfg_start_addr, residual_length);
        BFD_GET_USHORT(cfg->base_cfg.cfg.vrf_id, cfg_start_addr, residual_length);
        BFD_GET_UCHAR(cfg->base_cfg.cfg.ip_type, cfg_start_addr, residual_length);
        BFD_GET_ULONG(cfg->base_cfg.cfg.phy_if_index, cfg_start_addr, residual_length);
        BFD_IGNORE_BYTES(20, cfg_start_addr, residual_length);

        ret = CFG_OK;
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_active_cfg_process
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年10月12日
 * 函数功能  : BFD配置处理
 * 输入参数  : unsigned char **cfg_data     对应配置协议中"内容"的起始地址
               unsigned char mes_type       消息类型,0x00/0x80/0x81/0x82=增量/全量中间/全量结束/全量删除
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
int bfd_active_cfg_process(IN unsigned char **cfg_data, IN unsigned char mes_type)
{
    BFD_CFG cfg;
    RESULT_BFDCFG ret = CFG_OK;
    BFD_CFG_DATABASE *data = NULL;

    do
    {
        BFD_CHECK_PARAM_POINT(BMU_ERR, cfg_data, ret);

        BFD_LOG(BMU_INFO, "message type:%#x\n", mes_type);

        OS_MEMSET(&cfg, 0, sizeof(cfg));
        bfd_decode_cfg(cfg_data, &cfg);
        

        switch ( mes_type ) /* 判断匹配条件mes_type */
        {
            case 0x00 : /* 增量 */
                ret = bfd_cfg_pro(&cfg);
                break;
            case 0x80 : /* 全量中间 */             
                ret = bfd_cfg_pro(&cfg);
                ret = bfd_find_cfg_database(cfg.key, &data);
                data->tab = 1;
                break;
            case 0x81 : /* 全量结束 */
                ret = bfd_traverse_cfg_database(bfd_find_cfg_tab);
                break;
            case 0x82 : /* 全量删除 */
                ret = bfd_traverse_cfg_database(bfd_del_all_cfg);
                break;
            default:
                BFD_LOG(BMU_ERR, "do not support mes_type:%u\n", mes_type);
                ret = PARAM_ERROR;
        }
        BFD_CHECK_RETURN(ret);
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_cfg_pro
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 配置BFD
 * 输入参数  : IN BFD_CFG *cfg  BFD配置块
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_cfg_pro(IN BFD_CFG *cfg)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short fpga_index = DRV_USHORT_INVALID;
    int arad_index = DRV_INT_INVALID;
    BFD_CFG_DATABASE *cfg_data = NULL;
    int result = 0;

    do /* 开始循环 */
    {
        if(NULL == cfg)
        {
            BFD_LOG(BMU_ERR, "cfg is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        ret = bfd_analyze_bfd_cfg(cfg, BMU_INFO);

        if(op_add == cfg->op)
        {
            //assert(cfg->key == cfg->base_cfg.cfg.my_sid);
            if(cfg->key != cfg->base_cfg.cfg.my_sid)
            {
                BFD_LOG(BMU_CRIT, "cfg key:%lu != myid:%lu\n", cfg->key , cfg->base_cfg.cfg.my_sid);
                ret = KEY_NOT_EQUAL_MYID;
                break;
            }

            ret = bfd_find_cfg_database(cfg->key, &cfg_data);
            if(CFG_OK != ret)   /* 添加 */
            {
                ret = bfd_add_cfg(&(cfg->base_cfg.cfg), &fpga_index, &arad_index);
                ret = bfd_add_cfg_database(cfg->key, cfg, fpga_index, arad_index);
            }
            else    /* 修改 */
            {
                if(NULL == cfg_data)
                {
                    ret = KEY_NOT_EXIST;
                    break;
                }

                result = memcmp(&(cfg_data->cfg_data), cfg, sizeof(*cfg));
                if(result != 0)
                {
                    fpga_index = cfg_data->fpga_index;
                    arad_index = cfg_data->arad_index;
                    ret = bfd_modify_cfg(cfg, cfg_data, fpga_index, arad_index);
                    ret = bfd_modify_cfg_database(cfg->key,
                        cfg, fpga_index, arad_index);
                }
            }
        }
        else
        {
            /* 删除告警 */
            (void)bfd_del_alarm_database(cfg->key);
            
            ret = bfd_find_cfg_database(cfg->key, &cfg_data);
            if(CFG_OK != ret)
            {
                break;
            }
            
            if(NULL == cfg_data)
            {
                ret = KEY_NOT_EXIST;
                break;
            }
            ret = bfd_del_cfg(cfg->key, cfg_data->fpga_index, cfg_data->arad_index);
            ret = bfd_del_cfg_database(cfg->key);
        }
    } while ( 0 ); /* 循环直到0不成立 */
    
    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_add_cfg
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 增加BFD配置
 * 输入参数  : IN BFD_BASIC_DATA *cfg          BFD基本配置块
 * 输出参数  : OUT unsigned short *fpga_index  FPGA的数组索引
               OUT int *arad_index             ARAD的数组索引
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_add_cfg(IN BFD_BASIC_DATA *cfg, OUT unsigned short *fpga_index, OUT int *arad_index)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if(NULL == cfg)
        {
            BFD_LOG(BMU_ERR, "cfg is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == fpga_index)
        {
            BFD_LOG(BMU_ERR, "fpga_index is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == arad_index)
        {
            BFD_LOG(BMU_ERR, "arad_index is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        switch ( cfg->bfd_frame_type ) /* BFD发帧类型 */
        {
            case BFD_CFG_LSP:
                ret = bfd_add_lsp_cfg(cfg, fpga_index, arad_index);
                break;
            case BFD_CFG_PW :
                ret = bfd_add_pw_cfg(cfg, fpga_index, arad_index);
                break;
            default:
                BFD_LOG(BMU_ERR, "do not support frame type:%u\n", cfg->bfd_frame_type);
                ret = PARAM_ERROR;
        }
        BFD_CHECK_RETURN(ret);
    } while ( 0 ); /* 循环直到0不成立 */
    
    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_del_cfg
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 删除BFD配置
 * 输入参数  : IN BFD_BASIC_DATA *cfg        BFD净配置块
               IN unsigned short fpga_index  FPGA的数组索引
               IN int arad_index             ARAD的数组索引
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_del_cfg(IN unsigned long key, IN unsigned short fpga_index, IN int arad_index)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned long fpga_key = 0;
    BFD_FPGA_INFO fpga_info;

    do /* 开始循环 */
    {        
        if ((fpga_index >= BFD_MAX_SESNUM) && (DRV_USHORT_INVALID != fpga_index))
        {
            BFD_LOG(BMU_ERR, "input fpga index %u is wrong!\n", fpga_index);
            ret = PARAM_ERROR;
            break;
        }

        /* 配过FPGA */
        if(DRV_USHORT_INVALID != fpga_index)
        {
            OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
            
            ret = bfd_get_specify_fpga_database_key(fpga_index, &fpga_key);
            if(CFG_OK != ret)
            {
                break;
            }
            if(fpga_key != key)
            {
                BFD_LOG(BMU_ERR, "fpga database fpga_key:%lu not match cfg myid:%lu!\n", fpga_key, key);
                ret = KEY_NOT_MATCH;
                break;
            }

            /* 获取存储的FPGA数据 */
            ret = bfd_get_specify_array_info(fpga_index, &fpga_info);
            if(fpga_info.send_cfg.discr.my_id != key)
            {
                BFD_LOG(BMU_ERR, "fpga store myid:%lu not match cfg myid:%lu!\n",
                    fpga_info.send_cfg.discr.my_id, key);
                ret = KEY_NOT_MATCH;
                break;
            }
        
            /* 删除FPGA存储配置 */
            ret = bfd_del_specify_fpga_database(fpga_index);
            
            /* 删除FPGA内容，用fpga_info->discr.my_id不用cfg->my_sid的原因是保持与add时一致，虽然两个值相等 */
            ret = bfd_del_fpga(fpga_index, fpga_info.send_cfg.discr.my_id);
        }

        /* 配过ARAD */
        if(DRV_INT_INVALID != arad_index)
        {
            /* 删除ARAD提包规则 */
            ret = bfd_del_arad(arad_index);
        }

    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;
}


/*****************************************************************************
 * 函 数 名  : bfd_modify_cfg
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 修改BFD配置
 * 输入参数  : IN BFD_BASIC_DATA *cfg            BFD净配置块
               INOUT unsigned short *fpga_index  FPGA的数组索引
               INOUT int *arad_index             ARAD的数组索引
 * 输出参数  : INOUT unsigned short *fpga_index  FPGA的数组索引
               INOUT int *arad_index             ARAD的数组索引
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_modify_cfg(IN BFD_CFG *cfg, 
    IN BFD_CFG_DATABASE * cfg_data, 
    INOUT unsigned short fpga_index, 
    INOUT int arad_index)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        if(NULL == cfg)
        {
            BFD_LOG(BMU_ERR, "cfg is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        ret = bfd_del_cfg(cfg->key, cfg_data->fpga_index, cfg_data->arad_index);
        ret = bfd_del_cfg_database(cfg->key);
        ret = bfd_add_cfg(&(cfg->base_cfg.cfg), &fpga_index, &arad_index);
        ret = bfd_add_cfg_database(cfg->key, cfg, fpga_index, arad_index);
        
    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_add_lsp_cfg
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 增加BFD for lsp的配置
 * 输入参数  : IN BFD_BASIC_DATA *cfg          BFD基本配置块
 * 输出参数  : OUT unsigned short *fpga_index  FPGA的数组索引
               OUT int *arad_index             ARAD的数组索引
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_add_lsp_cfg(IN BFD_BASIC_DATA *cfg, OUT unsigned short *fpga_index, OUT int *arad_index)
{
    RESULT_BFDCFG ret = CFG_OK;
    int result = 0;
    unsigned short index = DRV_USHORT_INVALID;
    BFD_FPGA_INFO fpga_info;
    TP_OAM_LSP_CFG oam_traffic_info;

    do /* 开始循环 */
    {
        if(NULL == cfg)
        {
            BFD_LOG(BMU_ERR, "cfg is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        if(NULL == fpga_index)
        {
            BFD_LOG(BMU_ERR, "fpga_index is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == arad_index)
        {
            BFD_LOG(BMU_ERR, "arad_index is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
        OS_MEMSET(&oam_traffic_info, 0, sizeof(oam_traffic_info));

        ret = bfd_get_null_array_index(&(index));

        result = oam_get_traffic_info(cfg->my_sid, cfg->bfd_frame_type, &oam_traffic_info);
        oam_traffic_info_print(&oam_traffic_info, BMU_INFO);

        ret = bfd_get_fpga_info(index, cfg, &oam_traffic_info, &fpga_info);
        BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_get_fpga_info, ret);
                
        /* 将组织好的BFD发送报文内容写FPGA */
        ret = bfd_set_fpga(&fpga_info);

        /* 向ARAD写入提包规则 */
        ret = bfd_set_arad(cfg->bfd_frame_type, &oam_traffic_info, arad_index);

        /* 存储配置 */
        ret = bfd_add_specify_fpga_database(index, &fpga_info);

        *fpga_index = index;

    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_add_pw_cfg
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 增加BFD for pw的配置
 * 输入参数  : IN BFD_BASIC_DATA *cfg          BFD基本配置块
 * 输出参数  : OUT unsigned short *fpga_index  FPGA的数组索引
               OUT int *arad_index             ARAD的数组索引
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_add_pw_cfg(IN BFD_BASIC_DATA *cfg, OUT unsigned short *fpga_index, OUT int *arad_index)
{
    RESULT_BFDCFG ret = CFG_OK;
    int result = 0;
    unsigned short index;
    BFD_FPGA_INFO fpga_info;
    TP_OAM_LSP_CFG oam_traffic_info;
    unsigned char slot = 0;     /* 本盘槽位 */

    do /* 开始循环 */
    {
        if(NULL == cfg)
        {
            BFD_LOG(BMU_ERR, "cfg is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == fpga_index)
        {
            BFD_LOG(BMU_ERR, "fpga_index is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if(NULL == arad_index)
        {
            BFD_LOG(BMU_ERR, "arad_index is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(&fpga_info, 0, sizeof(fpga_info));
        OS_MEMSET(&oam_traffic_info, 0, sizeof(oam_traffic_info));


        result = oam_get_traffic_info(cfg->my_sid, cfg->bfd_frame_type, &oam_traffic_info);
        oam_traffic_info_print(&oam_traffic_info, BMU_INFO);
        
        slot = BmuGetBoardAddr()&0xff;

        if(slot == oam_traffic_info.InSlot)    /* 本盘是UNI槽位，配置状态机，不需要arad提包规则，包从NNI槽位收发 */
        {
            ret = bfd_get_null_array_index(&(index));

            ret = bfd_get_fpga_info(index, cfg, &oam_traffic_info, &fpga_info);
            BFD_CHECK_FUNC_RETURN_BREAK(BMU_WARNING, bfd_get_fpga_info, ret);
                    
            /* 将组织好的BFD发送报文内容写FPGA */
            ret = bfd_set_fpga(&fpga_info);
            
            /* 存储配置 */
            ret = bfd_add_specify_fpga_database(index, &fpga_info);

            *fpga_index = index;

            /* 没有配置arad */
            *arad_index = DRV_INT_INVALID;
        }
        else    /* NNI槽位，需要写ARAD提包规则 */
        {
            /* 向ARAD写入提包规则 */
            ret = bfd_set_arad(cfg->bfd_frame_type, &oam_traffic_info, arad_index);

            
            /* 没有配置fpga */
            *fpga_index = DRV_USHORT_INVALID;
        }

    } while ( 0 ); /* 循环直到0不成立 */
        
    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_set_arad
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 增加ARAD的提包规则
 * 输入参数  : IN unsigned char bfd_type            BFD类型
               IN TP_OAM_LSP_CFG* oam_traffic_info  LSP配置信息
 * 输出参数  : OUT int *arad_index                  ARAD索引
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_arad(IN unsigned char bfd_type, IN TP_OAM_LSP_CFG* oam_traffic_info, OUT int *arad_index)
{
    RESULT_BFDCFG ret = CFG_OK;
    int result = 0;
    unsigned char slot = 0;     /* 本盘槽位 */
    unsigned int fapid = 0;
    drv_udf_key_t key;
    drv_udf_action_t action;
    int i = 0;

    do
    {
        if (NULL == oam_traffic_info)
        {
            BFD_LOG(BMU_ERR, "oam_traffic_info is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (NULL == arad_index)
        {
            BFD_LOG(BMU_ERR, "arad_index is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(&key, 0, sizeof(key));
        OS_MEMSET(&action, 0, sizeof(action));
        
        slot = BmuGetBoardAddr()&0xff;

        switch ( bfd_type ) /* BFD类型 */
        {
            case BFD_CFG_LSP:
                fapid = bfd_get_fapid(slot);
                key.tunnel = oam_traffic_info->InLspLable;
                break;
            case BFD_CFG_PW :
                fapid = bfd_get_fapid(oam_traffic_info->InSlot);
                key.pw = oam_traffic_info->InPwLable;
                break;
            default:
                BFD_LOG(BMU_ERR, "do not support type:%u\n", bfd_type);
                ret = PARAM_ERROR;
                break;
        }
        BFD_CHECK_RETURN(ret);
                
        //key.ach = 0x10000022;       /* 普通BFD是0x0007,0x0022是MPLS-CC, 0x0023是MPLS-CV,RFC6428规定 */
        BFD_GET_UCHAR_FORM_ULONG(0x10000022,
            key.channel_type[0], key.channel_type[1], key.channel_type[2], key.channel_type[3]);
        for (i = 0; i <sizeof(4); i++) /* 对变量i进行循环 */
        {
            key.channel_type_mask[i] = 0xff;
        }
        key.ethertype = 0x8847;
        key.redirect_dest_modid = fapid;
        key.redirect_dest_port = 164;
        key.entryprio = 6;

        action.RedirectFlag = 1;

        result = fhdrv_fap_udf_entry_create(0, &key, &action);

        ret = bfd_analyze_bfd_set_arad(&key, &action, BMU_INFO);
        
        if(result < OK)
        {
            ret = SET_ARAD;
            break;
        }
        else
        {
            *arad_index = result;
        }

        ret = CFG_OK;
    }while(0);

    if(CFG_OK != ret)
    {
        if(NULL != arad_index)
        {
            *arad_index = DRV_INT_INVALID;
        }
    }
    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_del_arad
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 删除ARAD的提包规则
 * 输入参数  : IN int index  ARAD索引
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_del_arad(IN int index)
{
    RESULT_BFDCFG ret = CFG_OK;
    int result = OK;

    do
    {
        if (index <= 0)
        {
            BFD_LOG(BMU_ERR, "input index %d is wrong!\n", index);
            ret = PARAM_ERROR;
            break;
        }

        result = fhdrv_fap_udf_entry_destroy(0, index);
        if(result != 0)
        {
            ret = SET_ARAD;
            break;
        }
    }while(0);

    return ret;
}

RESULT_BFDCFG bfd_del_all_cfg(IN BFD_CFG_DATABASE* cfg_database)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_CFG cfg;
    do 
    {
        BFD_CHECK_PARAM_POINT(BMU_ERR, cfg_database, ret);

        OS_MEMSET(&cfg ,0, sizeof(cfg));
        
        cfg.op = op_del;
        cfg.key = cfg_database->my_sid;
        
        ret = bfd_cfg_pro(&cfg);

    }while(0);

    return ret;
}


RESULT_BFDCFG bfd_find_cfg_tab(IN BFD_CFG_DATABASE* cfg_database)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_CFG cfg;
    do
    {
        BFD_CHECK_PARAM_POINT(BMU_ERR, cfg_database, ret);
        OS_MEMSET(&cfg, 0, sizeof(cfg));
        if(cfg_database->tab == 0)
        {
            cfg.op = op_del;
            cfg.key = cfg_database->my_sid;
            ret = bfd_cfg_pro(&cfg);
        }
        else
        {
            cfg_database->tab = 0;
        }
    }while(0);

    return ret;
}

