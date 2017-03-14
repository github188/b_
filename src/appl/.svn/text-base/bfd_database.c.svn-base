/***********************************************************************************

 * 文 件 名   : bfd_database.c
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年10月14日
 * 版 本 号   : 
 * 文件描述   : BFD数据库
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#include "bfd.h"

/* BFD数据库，BFD程序运行中一直有效 */
BFD_DATABASE g_bfd_database;

/*****************************************************************************
 * 函 数 名  : bfd_init_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 初始化BFD数据库
 * 输入参数  : 无
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_init_database()
{
    RESULT_BFDCFG ret = CFG_OK;

    do
    {
        OS_MEMSET(&g_bfd_database, 0, sizeof(g_bfd_database));

        bfd_init_cfg_database();

        bfd_init_alarm_database();

        bfd_init_event_database();

        ret = CFG_OK;
    }
    while (0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_get_null_array_index
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 获取空的数组索引
 * 输入参数  : 无
 * 输出参数  : OUT unsigned short *index  数组索引
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_null_array_index(OUT unsigned short *index)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short i = 0;
    
    do
    {
        if (NULL == index)
        {
            BFD_LOG(BMU_ERR, "index is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        #if 0   /* 稳定第一，效率第二 */
        if(g_bfd_database.fpga_info.null_index >= BFD_MAX_SESNUM)
        {
            ret = CFG_FULL;
            break;
        }
        else
        {
            *index = g_bfd_database.fpga_info.null_index;
            
            ret = CFG_OK;
        }
        #else
        for (i = 0; i < BFD_MAX_SESNUM; i++) /* 对变量i进行循环 */
        {
            if(0 == g_bfd_database.fpga_info.data[i].key)
            {
                break;
            }
        }
        if(BFD_MAX_SESNUM == i)
        {
            ret = CFG_FULL;
            break;
        }
        else
        {
            *index = i;
        }
        #endif
    }while(0);
    
    if(CFG_OK != ret)
    {
        if(NULL != index)
        {
            *index = DRV_USHORT_INVALID;
        }
    }
    return ret;
}

/* 稳定第一，效率第二 */
#if 0
RESULT_BFDCFG bfd_get_max_array_index(OUT unsigned short *index)
{
    RESULT_BFDCFG ret = CFG_OK;
    
    do
    {
        if (NULL == index)
        {
            BFD_LOG(BMU_ERR, "index is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        if(g_bfd_database.fpga_info.max_index >= BFD_MAX_SESNUM)
        {
            ret = CFG_FULL;
            break;
        }
        else
        {
            *index = g_bfd_database.fpga_info.max_index;
            
            ret = CFG_OK;
        }
    }while(0)

    return ret;
}
#endif

/*****************************************************************************
 * 函 数 名  : bfd_compare_fpga_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 比较key值的大小
 * 输入参数  : IN unsigned long key       需要比较的key值
               IN unsigned long node_key  原数据结构中的key值
 * 输出参数  : 无
 * 返 回 值  : unsigned
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
unsigned long bfd_compare_fpga_database(IN unsigned long key, IN unsigned long node_key)
{
    return key - node_key;
}

/**PROC+**********************************************************************/
/* Name:      compare_ulong                                                  */
/*                                                                           */
/* Purpose:   Standard function for comparing BFD_NBB_ULONGs                     */
/*                                                                           */
/* Returns:   -1 if aa < bb                                                  */
/*             0 if aa = bb                                                  */
/*             1 if aa > bb                                                  */
/*                                                                           */
/* Params:    IN  aa                                                         */
/*            IN  bb                                                         */
/*                                                                           */
/**PROC-**********************************************************************/
int bfd_compare_ulong(void *aa, void *bb)
{
  /***************************************************************************/
  /* Local Variables                                                         */
  /***************************************************************************/
  int ret_val;

  if (*(unsigned long *)aa < *(unsigned long *)bb)
  {
    /*************************************************************************/
    /* FLOW TRACING NOT REQUIRED    Reason: Performance.                     */
    /*************************************************************************/
    ret_val = -1;
  }
  else if (*(unsigned long *)aa > *(unsigned long *)bb)
  {
    /*************************************************************************/
    /* FLOW TRACING NOT REQUIRED    Reason: Performance.                     */
    /*************************************************************************/
    ret_val = 1;
  }
  else
  {
    /*************************************************************************/
    /* FLOW TRACING NOT REQUIRED    Reason: Performance.                     */
    /*************************************************************************/
    ret_val = 0;
  }

  return(ret_val);

} /* compare_ulong */

/*****************************************************************************
 * 函 数 名  : bfd_get_specify_fpga_database_key
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 获取指定数组索引的KEY值
 * 输入参数  : IN unsigned short index  数组索引
 * 输出参数  : OUT unsigned long *key   BFD MYID
 * 返 回 值  : RESULT_BFDCFG
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_specify_fpga_database_key(IN unsigned short index, OUT unsigned long *key)
{
    RESULT_BFDCFG ret = CFG_OK;
    do
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong!\n", index);
            ret = PARAM_ERROR;
            break;
        }
        
        if (NULL == key)
        {
            BFD_LOG(BMU_ERR, "key is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        *key = g_bfd_database.fpga_info.data[index].key;

        ret = CFG_OK;
    }while(0);
    
    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_find_array
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 根据KEY值找到BFD数组索引
 * 输入参数  : IN unsigned long key       BFD MYID
 * 输出参数  : OUT unsigned short *index  数组索引
 * 返 回 值  : RESULT_BFDCFG              错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_find_array(IN unsigned long key, OUT unsigned short *index)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short i = 0;

    do
    {
        if (NULL == index)
        {
            BFD_LOG(BMU_ERR, "index is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        /* 稳定第一，效率第二 */
        #if 0
        if((0 == g_bfd_database.fpga_info.max_index) 
            && (0 == g_bfd_database.fpga_info.null_index)) /* 一条都没配 */
        {
            ret = KEY_NOT_EXIST;
            break;
        }
        else
        {
            if(BFD_MAX_SESNUM <= g_bfd_database.fpga_info.max_index)
            {
                ret = CFG_FULL;
                break;
            }
            
            for (i = 0; i < g_bfd_database.fpga_info.max_index + 1; i++) /* 对变量i进行循环 */
            {
                result = bfd_compare_fpga_database(key, g_bfd_database.fpga_info.data[i].key);
                if(0 == result) /* 匹配到了 */
                {
                    break;
                }
            }
            if(i == (g_bfd_database.fpga_info.max_index + 1))  /* 没找到 */
            {
                ret = KEY_NOT_EXIST;
                break;
            }
            else
            {
                *index = i;
            }

            ret = CFG_OK;
        }
        #else
        for (i = 0; i < BFD_MAX_SESNUM; i++) /* 对变量i进行循环 */
        {
            if(key == g_bfd_database.fpga_info.data[i].key)    /* 匹配到了 */
            {
                break;
            }
        }
        if(i == BFD_MAX_SESNUM)  /* 没找到 */
        {
            ret = KEY_NOT_EXIST;
            break;
        }
        else
        {
            *index = i;
        }
        
        ret = CFG_OK;
        #endif
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_get_array_info
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月9日
 * 函数功能  : 根据KEY值获取存储的FPGA信息
 * 输入参数  : IN unsigned long key          BFD MYID
 * 输出参数  : OUT BFD_FPGA_INFO *fpga_info  FPGA信息
 * 返 回 值  : RESULT_BFDCFG                 错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_array_info(IN unsigned long key, OUT BFD_FPGA_INFO *fpga_info)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short index = 0;

    do
    {
        if (NULL == fpga_info)
        {
            BFD_LOG(BMU_ERR, "fpga_info is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        ret = bfd_find_array(key, &index);
        if(CFG_OK != ret)
        {
            break;
        }

        bfd_get_specify_array_info(index, fpga_info);
        
        ret = CFG_OK;
    }while(0);

    return ret;
}


/*****************************************************************************
 * 函 数 名  : bfd_get_specify_array_info
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月9日
 * 函数功能  : 获取存储的指定索引的FPGA信息
 * 输入参数  : IN unsigned short index       索引号
 * 输出参数  : OUT BFD_FPGA_INFO *fpga_info  FPGA信息
 * 返 回 值  : RESULT_BFDCFG                 错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_get_specify_array_info(IN unsigned short index, OUT BFD_FPGA_INFO *fpga_info)
{
    RESULT_BFDCFG ret = CFG_OK;

    do
    {
        if (NULL == fpga_info)
        {
            BFD_LOG(BMU_ERR, "fpga_info is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "index:%u is too big, max is %u\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }

        OS_MEMSET(fpga_info, 0, sizeof(*fpga_info));

        if(NULL == g_bfd_database.fpga_info.data[index].fpga_info)
        {
            ret = FPGA_STORT_NULL;
            break;
        }

        OS_MEMCPY(fpga_info, g_bfd_database.fpga_info.data[index].fpga_info, sizeof(*fpga_info));
        
        ret = CFG_OK;
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_insert_specify_array
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 在指定数组下标插入元素
 * 输入参数  : IN unsigned short index  数组索引
               IN unsigned long key     BFD MYID
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_insert_specify_array(IN unsigned short index, IN unsigned long key)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_FPGA_INFO *new_node = NULL;

    do
    {
        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "index:%u is too big, max is %u\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        assert(0 == g_bfd_database.fpga_info.data[index].key);
        assert(NULL == g_bfd_database.fpga_info.data[index].fpga_info);

        if((0 != g_bfd_database.fpga_info.data[index].key) 
            || (NULL != g_bfd_database.fpga_info.data[index].fpga_info))
        {
            ret = ADD_KEY_EXIST;
            break;
        }

        new_node = (BFD_FPGA_INFO*)malloc(sizeof(BFD_FPGA_INFO));
        if(NULL == new_node)
        {
            ret = ALLOC_ERROR;
            break;
        }

        OS_MEMSET(new_node, 0, sizeof(BFD_FPGA_INFO));
        
        g_bfd_database.fpga_info.data[index].fpga_info = new_node;
        g_bfd_database.fpga_info.data[index].key = key;
        
        ret = CFG_OK;
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_insert_array
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 在BFD数组插入元素
 * 输入参数  : IN unsigned long key       BFD MYID
 * 输出参数  : OUT unsigned short *index  插入的数组索引
 * 返 回 值  : RESULT_BFDCFG              错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_insert_array(IN unsigned long key, OUT unsigned short *index)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short new_index = 0;

    do
    {
        if (NULL == index)
        {
            BFD_LOG(BMU_ERR, "index is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        ret = bfd_get_null_array_index(&new_index);
        if(CFG_OK != ret)
        {
            break;
        }
        
        /* 稳定第一，效率第二 */
        #if 0
        ret = bfd_get_max_array_index(&max_index);
        if(CFG_OK != ret)
        {
            break;
        }
        
        assert(NULL == g_bfd_database.fpga_info.data[new_index].fpga_info);

        new_node = (BFD_FPGA_INFO*)malloc(sizeof(BFD_FPGA_INFO));
        if(NULL = new_node)
        {
            ret = ALLOC_ERROR;
            break;
        }

        OS_MEMSET(new_node, 0, sizeof(BFD_FPGA_INFO));
        
        g_bfd_database.fpga_info.data[new_index].fpga_info = new_node;
        g_bfd_database.fpga_info.data[new_index].key = key;
        *index = new_index;

        if(new_index < max_index)   /* 空值小于最大值 */
        {
            for (i = new_index + 1; i < max_index; i++) /* 最大值没必要轮询，肯定配置了 */
            {
                if(0 == g_bfd_database.fpga_info.data[i].key)  /* 中间有没配过的 */
                {
                    break;
                }
            }
            if(i == max_index)  /* 中间没有没配过的 */
            {
                if(max_index >= BFD_MAX_SESNUM - 1) /* 没有空间了 */
                {
                    /* 最大值不变 */                    
                }
                else
                {
                    g_bfd_database.fpga_info.max_index = max_index + 1;
                }
                
                g_bfd_database.fpga_info.null_index = g_bfd_database.fpga_info.max_index + 1;
            }
            else    /* 中间还有没有配过的 */
            {
                g_bfd_database.fpga_info.null_index = i;

                /* 最大值不变 */
            }
        }
        else if(new_index == max_index)
        {
            if (0 == new_index) /* 只有完全没配过的表才有可能 */
            {
                g_bfd_database.fpga_info.max_index = 0;
                g_bfd_database.fpga_info.null_index = g_bfd_database.fpga_info.max_index + 1;
            }
            else
            {
                assert(new_index != max_index);
            }
        }
        else    /* 空值大于最大值 */
        {
            assert(new_index == max_index + 1); /* 空值比最大值大的情况，只可能是最大值+1 */

            if(max_index >= BFD_MAX_SESNUM - 1) /* 没有空间了 */
            {
                /* 最大值不变 */
            }
            else
            {
                g_bfd_database.fpga_info.max_index = max_index + 1;
            }
            
            g_bfd_database.fpga_info.null_index = g_bfd_database.fpga_info.max_index + 1;
        }
        #else
        ret = bfd_insert_specify_array(new_index, key);
        if(CFG_OK != ret)
        {
            break;
        }
        
        *index = new_index;
        #endif
        ret = CFG_OK;
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_set_specify_fpga_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 修改BFD数组指定位置的数据
 * 输入参数  : IN unsigned short index  数组下标
               IN BFD_FPGA_INFO *info   FPGA相关参数
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_set_specify_fpga_database(IN unsigned short index, IN BFD_FPGA_INFO *info)
{
    RESULT_BFDCFG ret = CFG_OK;
    do
    {
        if (NULL == info)
        {
            BFD_LOG(BMU_ERR, "info is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "index:%u is too big, max is %u\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        assert(NULL != g_bfd_database.fpga_info.data[index].fpga_info);
        if(NULL == g_bfd_database.fpga_info.data[index].fpga_info)
        {
            ret = FPGA_STORT_NULL;
            break;
        }
        OS_MEMCPY(g_bfd_database.fpga_info.data[index].fpga_info,
            info, sizeof(BFD_FPGA_INFO));
    }while(0);

    return ret;
}

RESULT_BFDCFG bfd_set_specify_fpga_specify_member_database(IN unsigned short index,
    IN unsigned long offset,
    IN void *data,
    IN unsigned long data_length)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        /* 参数检查 */
        BFD_CHECK_PARAM_MAX(BMU_ERR, index, BFD_MAX_SESNUM, "%u", "%u", ret);
        BFD_CHECK_PARAM_POINT(BMU_ERR, data, ret);
        BFD_CHECK_PARAM_OPEN_MAX(BMU_ERR, offset, sizeof(BFD_FPGA_INFO), "%lu", "%d", ret);
        BFD_CHECK_PARAM_OPEN_MAX(BMU_ERR, data_length, sizeof(BFD_FPGA_INFO), "%lu", "%d", ret);
        BFD_CHECK_PARAM_OPEN_MAX(BMU_ERR, offset + data_length, sizeof(BFD_FPGA_INFO), "%lu", "%d", ret);

        assert(NULL != g_bfd_database.fpga_info.data[index].fpga_info);
        if (NULL == g_bfd_database.fpga_info.data[index].fpga_info)
        {
            ret = FPGA_STORT_NULL;
            break;
        }

        BFD_SET_STRUCT_MEMBER(BFD_FPGA_INFO, g_bfd_database.fpga_info.data[index].fpga_info, offset, data, data_length);
        
        ret = CFG_OK;
    }
    while (0); /* 循环直到0不成立 */

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_add_specify_fpga_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 在BFD数组的指定位置加入FPGA信息
 * 输入参数  : IN unsigned short index  数组下标
               IN BFD_FPGA_INFO *info   FPGA相关信息
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_add_specify_fpga_database(IN unsigned short index, IN BFD_FPGA_INFO *info)
{
    RESULT_BFDCFG ret = CFG_OK;
    do
    {
        if (NULL == info)
        {
            BFD_LOG(BMU_ERR, "info is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if(index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "index:%u is too big, max is %u\n", index, BFD_MAX_SESNUM);
            ret = PARAM_ERROR;
            break;
        }
        
        ret = bfd_insert_specify_array(index, info->send_cfg.discr.my_id);
        if(CFG_OK != ret)
        {
            break;
        }
        
        ret = bfd_set_specify_fpga_database(index, info);
        if(CFG_OK != ret)
        {
            break;
        }
        
    }while(0);
    
    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_add_fpga_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 在BFD数组中插入FPGA相关信息
 * 输入参数  : IN BFD_FPGA_INFO *info         FPGA信息
               OUT unsigned short *add_index  插入的数组下标
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG                  错误
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_add_fpga_database(IN BFD_FPGA_INFO *info, OUT unsigned short *add_index)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short index = 0;
    unsigned short new_index = 0;

    do
    {
        if (NULL == info)
        {
            BFD_LOG(BMU_ERR, "info is NULL\n");
            ret = PARAM_ERROR;
            break;
        }
        
        if (NULL == add_index)
        {
            BFD_LOG(BMU_ERR, "add_index is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        ret = bfd_find_array(info->send_cfg.discr.my_id, &index);

        if(KEY_NOT_EXIST == ret)    /* 未找到 */
        {
            ret = bfd_insert_array(info->send_cfg.discr.my_id, &new_index);
            if(CFG_OK != ret)
            {
                break;
            }
        }
        else if (CFG_OK == ret)  /* 找到 */
        {
            new_index = index;
        }
        else    /* 其他错误值直接返回 */
        {
            break;
        }

        *add_index = new_index;
        
        ret = bfd_set_specify_fpga_database(new_index, info);
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_del_specify_fpga_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 在BFD数组中删除指定的元素
 * 输入参数  : IN unsigned short index  需要删除的数组下标
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_del_specify_fpga_database(IN unsigned short index)
{
    RESULT_BFDCFG ret = CFG_OK;

    do
    {
        if (index >= BFD_MAX_SESNUM)
        {
            BFD_LOG(BMU_ERR, "input num %d is wrong!\n", index);
            ret = PARAM_ERROR;
            break;
        }

        g_bfd_database.fpga_info.data[index].key = 0;
        if(NULL != g_bfd_database.fpga_info.data[index].fpga_info)
        {
            free(g_bfd_database.fpga_info.data[index].fpga_info);
            g_bfd_database.fpga_info.data[index].fpga_info = NULL;
        }

        ret = CFG_OK;
    }while(0);

return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_del_fpga_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 在BFD数组中删除指定的KEY值的元素
 * 输入参数  : IN unsigned long key  BFD MYID
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG         错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_del_fpga_database(IN unsigned long key)
{
    RESULT_BFDCFG ret = CFG_OK;
    unsigned short index = 0;

    do
    {
        ret = bfd_find_array(key, &index);
        if(CFG_OK != ret)
        {
            break;
        }
        
        ret = bfd_del_specify_fpga_database(index);
    }while(0);

    return ret;
}

RESULT_BFDCFG bfd_init_cfg_database()
{

    AVLL_INIT_TREE(g_bfd_database.cfg,
        bfd_compare_ulong,
        NBB_OFFSETOF(BFD_CFG_DATABASE, my_sid),
        NBB_OFFSETOF(BFD_CFG_DATABASE, cfg_node));

    return CFG_OK;
}

/*****************************************************************************
 * 函 数 名  : bfd_find_cfg_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 根据BFD MYID在数据库中查找BFD数据
 * 输入参数  : IN unsigned long my_sid      BFD MYID
 * 输出参数  : OUT BFD_CFG_DATABASE **data  BFD配置数据
 * 返 回 值  : RESULT_BFDCFG                错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_find_cfg_database(IN unsigned long my_sid, OUT BFD_CFG_DATABASE **data)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_CFG_DATABASE *cfg_data = NULL;

    do
    {
        if (NULL == data)
        {
            BFD_LOG(BMU_ERR, "data is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        cfg_data = (BFD_CFG_DATABASE *)AVLL_FIND(g_bfd_database.cfg, &my_sid);
        if(NULL == cfg_data)
        {
            ret = KEY_NOT_EXIST;
            break;
        }
        
        *data = cfg_data;
        
        ret = CFG_OK;
    }while(0);

    return ret;
}

RESULT_BFDCFG bfd_traverse_cfg_database(BFD_TRAVERSE_CFG_CALLBACK func)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_CFG_DATABASE *cfg_data = NULL;
    BFD_CFG_DATABASE *cfg_data_next = NULL;

    do
    {
        if(NULL == func)
        {
            ret = PARAM_ERROR;
            break;
        }
        
        cfg_data = (BFD_CFG_DATABASE*)AVLL_FIRST(g_bfd_database.cfg);
        while ( cfg_data != NULL )
        {
            cfg_data_next = (BFD_CFG_DATABASE*)AVLL_NEXT(g_bfd_database.cfg, cfg_data->cfg_node);
            ret = func(cfg_data);
            cfg_data = cfg_data_next;
        }
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_add_cfg_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 在数据库中插入BFD配置和驱动索引
 * 输入参数  : IN unsigned long my_sid       BFD MYID
               IN BFD_CFG *cfg               BFD配置数据
               IN unsigned short fpga_index  FPGA索引
               IN int arad_index             arad索引
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG                 错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_add_cfg_database(IN unsigned long my_sid,
    IN BFD_CFG *cfg,
    IN unsigned short fpga_index,
    IN int arad_index)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_CFG_DATABASE *cfg_data = NULL;

    do
    {
        if (NULL == cfg)
        {
            BFD_LOG(BMU_ERR, "cfg is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        /* 分配内存 */
        cfg_data = (BFD_CFG_DATABASE*)malloc(sizeof(BFD_CFG_DATABASE));
        if(NULL == cfg_data)
        {
            ret = ALLOC_ERROR;
            break;
        }

        OS_MEMSET(cfg_data, 0 , sizeof(BFD_CFG_DATABASE));

        /* 拷贝内容 */
        cfg_data->my_sid = my_sid;
        OS_MEMCPY(&(cfg_data->cfg_data), cfg, sizeof(cfg_data->cfg_data));
        cfg_data->fpga_index = fpga_index;
        cfg_data->arad_index = arad_index;

        /* 加入二叉树 */
        AVLL_INIT_NODE(cfg_data->cfg_node);
        if(!AVLL_INSERT(g_bfd_database.cfg, cfg_data->cfg_node))
        {
            free(cfg_data);
            cfg_data = NULL;
            ret = ADD_KEY_EXIST;
            break;
        }

        ret = CFG_OK;
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_del_cfg_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 在数据库中删除指定BFD MYID的数据
 * 输入参数  : IN unsigned long my_sid  BFD MYID
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_del_cfg_database(IN unsigned long my_sid)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_CFG_DATABASE *cfg_data = NULL;

    do
    {
        cfg_data = (BFD_CFG_DATABASE *)AVLL_FIND(g_bfd_database.cfg, &my_sid);
        if(NULL == cfg_data)
        {
            ret = KEY_NOT_EXIST;
            break;
        }
        
        /* 若存储过则删除 */
        AVLL_DELETE(g_bfd_database.cfg, cfg_data->cfg_node);
        free(cfg_data);
        cfg_data = NULL;

        ret = CFG_OK;
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_modify_cfg_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 在数据库中修改指定的BFD MYID的数据
 * 输入参数  : IN unsigned long my_sid       BFD MYID
               IN BFD_CFG *cfg               BFD配置数据
               IN unsigned short fpga_index  FPGA索引
               IN int arad_index             ARAD索引
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG                 错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_modify_cfg_database(IN unsigned long my_sid,
    IN BFD_CFG *cfg,
    IN unsigned short fpga_index,
    IN int arad_index)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_CFG_DATABASE *cfg_data = NULL;

    do
    {
        if (NULL == cfg)
        {
            BFD_LOG(BMU_ERR, "cfg is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        cfg_data = (BFD_CFG_DATABASE *)AVLL_FIND(g_bfd_database.cfg, &my_sid);
        if(NULL == cfg_data)
        {
            ret = KEY_NOT_EXIST;
            break;
        }
        
        /* 拷贝内容 */
        cfg_data->my_sid = my_sid;
        OS_MEMCPY(&(cfg_data->cfg_data), cfg, sizeof(cfg_data->cfg_data));
        cfg_data->fpga_index = fpga_index;
        cfg_data->arad_index = arad_index;

        ret = CFG_OK;
    }while(0);

    return ret;
}

RESULT_BFDCFG bfd_init_alarm_database()
{
    AVLL_INIT_TREE(g_bfd_database.alarm,
        bfd_compare_ulong,
        NBB_OFFSETOF(BFD_ALARM_DATABASE, my_sid),
        NBB_OFFSETOF(BFD_ALARM_DATABASE, alarm_node));

    return CFG_OK;
}

/*****************************************************************************
 * 函 数 名  : bfd_find_alarm_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月17日
 * 函数功能  : 根据BFD MYID在数据库中查找BFD告警
 * 输入参数  : IN unsigned long my_sid        BFD MYID
 * 输出参数  : OUT BFD_ALARM_DATABASE **data  BFD告警
 * 返 回 值  : RESULT_BFDCFG                  错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_find_alarm_database(IN unsigned long my_sid, OUT BFD_ALARM_DATABASE **data)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_ALARM_DATABASE *alarm_data = NULL;

    do
    {
        if (NULL == data)
        {
            BFD_LOG(BMU_ERR, "data is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        alarm_data = (BFD_ALARM_DATABASE *)AVLL_FIND(g_bfd_database.alarm, &my_sid);
        if(NULL == alarm_data)
        {
            ret = KEY_NOT_EXIST;
            break;
        }
        
        *data = alarm_data;
        
        ret = CFG_OK;
    }while(0);

    return ret;
}

RESULT_BFDCFG bfd_traverse_alarm_database(BFD_TRAVERSE_ALARM_CALLBACK func)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_ALARM_DATABASE *alarm_data = NULL;
    BFD_ALARM_DATABASE *alarm_data_next = NULL;

    do
    {
        if(NULL == func)
        {
            ret = PARAM_ERROR;
            break;
        }

        alarm_data = (BFD_ALARM_DATABASE*)AVLL_FIRST(g_bfd_database.alarm);
        while (alarm_data != NULL)
        {
            alarm_data_next = (BFD_ALARM_DATABASE*)AVLL_NEXT(g_bfd_database.alarm, alarm_data->alarm_node);
            ret = func(alarm_data);
            alarm_data = alarm_data_next;
        }
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_add_alarm_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月17日
 * 函数功能  : 在数据库中插入BFD告警
 * 输入参数  : IN unsigned long my_sid       BFD MYID
               IN BFD_ALM_REPORT *alarm      BFD告警
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG                 错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_add_alarm_database(IN unsigned long my_sid, IN BFD_ALM_REPORT *alarm)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_ALARM_DATABASE *alarm_data = NULL;

    do
    {
        if (NULL == alarm)
        {
            BFD_LOG(BMU_ERR, "alarm is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        /* 分配内存 */
        alarm_data = (BFD_ALARM_DATABASE*)malloc(sizeof(BFD_ALARM_DATABASE));
        if(NULL == alarm_data)
        {
            ret = ALLOC_ERROR;
            break;
        }

        OS_MEMSET(alarm_data, 0 , sizeof(*alarm_data));

        /* 拷贝内容 */
        alarm_data->my_sid = my_sid;
        OS_MEMCPY(&(alarm_data->alarm), alarm, sizeof(alarm_data->alarm));

        /* 加入二叉树 */
        AVLL_INIT_NODE(alarm_data->alarm_node);
        if(!AVLL_INSERT(g_bfd_database.alarm, alarm_data->alarm_node))
        {
            free(alarm_data);
            alarm_data = NULL;
            ret = ADD_KEY_EXIST;
            break;
        }

        ret = CFG_OK;
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_del_alarm_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 在数据库中删除指定BFD MYID的告警
 * 输入参数  : IN unsigned long my_sid  BFD MYID
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG            错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_del_alarm_database(IN unsigned long my_sid)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_ALARM_DATABASE *alarm_data = NULL;

    do
    {
        alarm_data = (BFD_ALARM_DATABASE *)AVLL_FIND(g_bfd_database.alarm, &my_sid);
        if(NULL == alarm_data)
        {
            ret = KEY_NOT_EXIST;
            break;
        }
        
        /* 若存储过则删除 */
        AVLL_DELETE(g_bfd_database.alarm, alarm_data->alarm_node);
        free(alarm_data);
        alarm_data = NULL;

        ret = CFG_OK;
    }while(0);

    return ret;
}

/*****************************************************************************
 * 函 数 名  : bfd_modify_alarm_database
 * 负 责 人  : jiangbo,蒋博
 * 创建日期  : 2016年11月7日
 * 函数功能  : 在数据库中修改指定的BFD MYID的告警
 * 输入参数  : IN unsigned long my_sid       BFD MYID
               IN BFD_CFG *cfg               BFD配置数据
 * 输出参数  : 无
 * 返 回 值  : RESULT_BFDCFG                 错误码
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
RESULT_BFDCFG bfd_modify_alarm_database(IN unsigned long my_sid, IN BFD_ALM_REPORT *alarm)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_ALARM_DATABASE *alarm_data = NULL;

    do
    {
        if (NULL == alarm)
        {
            BFD_LOG(BMU_ERR, "alarm is NULL\n");
            ret = PARAM_ERROR;
            break;
        }

        alarm_data = (BFD_ALARM_DATABASE *)AVLL_FIND(g_bfd_database.alarm, &my_sid);
        if(NULL == alarm_data)
        {
            ret = KEY_NOT_EXIST;
            break;
        }
        
        /* 拷贝内容 */
        alarm_data->my_sid = my_sid;
        OS_MEMCPY(&(alarm_data->alarm), alarm, sizeof(alarm_data->alarm));

        ret = CFG_OK;
    }while(0);

    return ret;
}

RESULT_BFDCFG bfd_init_event_database()
{
    NBB_INIT_ROOT(g_bfd_database.event.event);
    g_bfd_database.event.count = 0;
    return CFG_OK;
}

RESULT_BFDCFG bfd_insert_event_database(IN BFD_EVENT_LOG_INFO *event_log)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        /* 参数检查 */
        BFD_CHECK_PARAM_POINT(BMU_ERR, event_log, ret);

        if (g_bfd_database.event.count >= BFD_EVENT_RECORD_MAX_NUM)
        {
            ret = CFG_FULL;
            break;
        }

        /* 初始化链表 */
        NBB_INIT_LQE(event_log->list, event_log);

        /* 前向加入数据库的双向链表中 */
        NBB_INSERT_BEFORE(g_bfd_database.event.event, event_log->list);
        g_bfd_database.event.count++;

        ret = CFG_OK;
    }
    while (0); /* 循环直到0不成立 */

    return ret;
}

RESULT_BFDCFG bfd_remove_event_database(IN BFD_EVENT_LOG_INFO *event_log)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        BFD_CHECK_PARAM_POINT(BMU_ERR, event_log, ret);

        /* 从数据库的双向链表中移除 */
        NBB_REMOVE_FROM_LIST(event_log->list);
        g_bfd_database.event.count--;

        ret = CFG_OK;
    }
    while (0); /* 循环直到0不成立 */

    return ret;
}

NBB_BOOL bfd_is_event_full_database()
{
    if (g_bfd_database.event.count >= BFD_EVENT_RECORD_MAX_NUM)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}  

RESULT_BFDCFG bfd_get_fisrt_event_database(OUT BFD_EVENT_LOG_INFO **event_log)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* 开始循环 */
    {
        BFD_CHECK_PARAM_POINT(BMU_ERR, event_log, ret);

        /* 找到root节点的后一个数据 */
        *event_log = NBB_NEXT_IN_LIST(g_bfd_database.event.event);

        if(NULL == event_log)
        {
            ret = LIST_NULL;
        }
        else
        {
            ret = CFG_OK;
        }
    }
    while (0); /* 循环直到0不成立 */

    return ret;
}

RESULT_BFDCFG bfd_traverse_event_database(IN BFD_TRAVERSE_EVENT_CALLBACK func,
    IN BFD_COMPARE_EVENT_CALLBACK compare_func, IN void* compare_data, IN unsigned int limit_num, IN int level)
{
    RESULT_BFDCFG ret = CFG_OK;
    BFD_EVENT_LOG_INFO *event_data = NULL;
    BFD_EVENT_LOG_INFO *event_data_next = NULL;
    unsigned int count = 0;

    do
    {
        BFD_CHECK_PARAM_POINT(level, func, ret);

        /* 比较函数compare_func允许为空，表示不比较 */
        if(NULL != compare_data)
        {
            BFD_CHECK_PARAM_POINT(level, compare_data, ret);
        }

        event_data = (BFD_EVENT_LOG_INFO *)NBB_PREV_IN_LIST(g_bfd_database.event.event);
        while(event_data != NULL)
        {
            event_data_next = (BFD_EVENT_LOG_INFO *)NBB_PREV_IN_LIST(event_data->list);
            
            if(NULL != compare_func)
            {
                if(TRUE != compare_func(event_data, compare_data))
                {
                    continue;
                }
            }

            if(0 != limit_num)    /* 为0表示不限制数量 */
            {
                if(count < limit_num)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            
            ret = func(event_data, level);
            event_data = event_data_next;
        }
    }
    while (0);

    return ret;
}
