/***********************************************************************************

 * �� �� ��   : bfd_database.c
 * �� �� ��   : jiangbo,����
 * ��������   : 2016��10��14��
 * �� �� ��   : 
 * �ļ�����   : BFD���ݿ�
 * ��Ȩ˵��   : Copyright (C) 2000-2016   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 

***********************************************************************************/

#include "bfd.h"

/* BFD���ݿ⣬BFD����������һֱ��Ч */
BFD_DATABASE g_bfd_database;

/*****************************************************************************
 * �� �� ��  : bfd_init_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ʼ��BFD���ݿ�
 * �������  : ��
 * �������  : ��
 * �� �� ֵ  : 
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : bfd_get_null_array_index
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ȡ�յ���������
 * �������  : ��
 * �������  : OUT unsigned short *index  ��������
 * �� �� ֵ  : 
 * ���ù�ϵ  : 
 * ��    ��  : 

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

        #if 0   /* �ȶ���һ��Ч�ʵڶ� */
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
        for (i = 0; i < BFD_MAX_SESNUM; i++) /* �Ա���i����ѭ�� */
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

/* �ȶ���һ��Ч�ʵڶ� */
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
 * �� �� ��  : bfd_compare_fpga_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : �Ƚ�keyֵ�Ĵ�С
 * �������  : IN unsigned long key       ��Ҫ�Ƚϵ�keyֵ
               IN unsigned long node_key  ԭ���ݽṹ�е�keyֵ
 * �������  : ��
 * �� �� ֵ  : unsigned
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : bfd_get_specify_fpga_database_key
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ȡָ������������KEYֵ
 * �������  : IN unsigned short index  ��������
 * �������  : OUT unsigned long *key   BFD MYID
 * �� �� ֵ  : RESULT_BFDCFG
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : bfd_find_array
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����KEYֵ�ҵ�BFD��������
 * �������  : IN unsigned long key       BFD MYID
 * �������  : OUT unsigned short *index  ��������
 * �� �� ֵ  : RESULT_BFDCFG              ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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

        /* �ȶ���һ��Ч�ʵڶ� */
        #if 0
        if((0 == g_bfd_database.fpga_info.max_index) 
            && (0 == g_bfd_database.fpga_info.null_index)) /* һ����û�� */
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
            
            for (i = 0; i < g_bfd_database.fpga_info.max_index + 1; i++) /* �Ա���i����ѭ�� */
            {
                result = bfd_compare_fpga_database(key, g_bfd_database.fpga_info.data[i].key);
                if(0 == result) /* ƥ�䵽�� */
                {
                    break;
                }
            }
            if(i == (g_bfd_database.fpga_info.max_index + 1))  /* û�ҵ� */
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
        for (i = 0; i < BFD_MAX_SESNUM; i++) /* �Ա���i����ѭ�� */
        {
            if(key == g_bfd_database.fpga_info.data[i].key)    /* ƥ�䵽�� */
            {
                break;
            }
        }
        if(i == BFD_MAX_SESNUM)  /* û�ҵ� */
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
 * �� �� ��  : bfd_get_array_info
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��9��
 * ��������  : ����KEYֵ��ȡ�洢��FPGA��Ϣ
 * �������  : IN unsigned long key          BFD MYID
 * �������  : OUT BFD_FPGA_INFO *fpga_info  FPGA��Ϣ
 * �� �� ֵ  : RESULT_BFDCFG                 ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : bfd_get_specify_array_info
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��9��
 * ��������  : ��ȡ�洢��ָ��������FPGA��Ϣ
 * �������  : IN unsigned short index       ������
 * �������  : OUT BFD_FPGA_INFO *fpga_info  FPGA��Ϣ
 * �� �� ֵ  : RESULT_BFDCFG                 ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : bfd_insert_specify_array
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��ָ�������±����Ԫ��
 * �������  : IN unsigned short index  ��������
               IN unsigned long key     BFD MYID
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : bfd_insert_array
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��BFD�������Ԫ��
 * �������  : IN unsigned long key       BFD MYID
 * �������  : OUT unsigned short *index  �������������
 * �� �� ֵ  : RESULT_BFDCFG              ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
        
        /* �ȶ���һ��Ч�ʵڶ� */
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

        if(new_index < max_index)   /* ��ֵС�����ֵ */
        {
            for (i = new_index + 1; i < max_index; i++) /* ���ֵû��Ҫ��ѯ���϶������� */
            {
                if(0 == g_bfd_database.fpga_info.data[i].key)  /* �м���û����� */
                {
                    break;
                }
            }
            if(i == max_index)  /* �м�û��û����� */
            {
                if(max_index >= BFD_MAX_SESNUM - 1) /* û�пռ��� */
                {
                    /* ���ֵ���� */                    
                }
                else
                {
                    g_bfd_database.fpga_info.max_index = max_index + 1;
                }
                
                g_bfd_database.fpga_info.null_index = g_bfd_database.fpga_info.max_index + 1;
            }
            else    /* �м仹��û������� */
            {
                g_bfd_database.fpga_info.null_index = i;

                /* ���ֵ���� */
            }
        }
        else if(new_index == max_index)
        {
            if (0 == new_index) /* ֻ����ȫû����ı���п��� */
            {
                g_bfd_database.fpga_info.max_index = 0;
                g_bfd_database.fpga_info.null_index = g_bfd_database.fpga_info.max_index + 1;
            }
            else
            {
                assert(new_index != max_index);
            }
        }
        else    /* ��ֵ�������ֵ */
        {
            assert(new_index == max_index + 1); /* ��ֵ�����ֵ��������ֻ���������ֵ+1 */

            if(max_index >= BFD_MAX_SESNUM - 1) /* û�пռ��� */
            {
                /* ���ֵ���� */
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
 * �� �� ��  : bfd_set_specify_fpga_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : �޸�BFD����ָ��λ�õ�����
 * �������  : IN unsigned short index  �����±�
               IN BFD_FPGA_INFO *info   FPGA��ز���
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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

    do /* ��ʼѭ�� */
    {
        /* ������� */
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
    while (0); /* ѭ��ֱ��0������ */

    return ret;
}

/*****************************************************************************
 * �� �� ��  : bfd_add_specify_fpga_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��BFD�����ָ��λ�ü���FPGA��Ϣ
 * �������  : IN unsigned short index  �����±�
               IN BFD_FPGA_INFO *info   FPGA�����Ϣ
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : bfd_add_fpga_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��BFD�����в���FPGA�����Ϣ
 * �������  : IN BFD_FPGA_INFO *info         FPGA��Ϣ
               OUT unsigned short *add_index  ����������±�
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG                  ����
 * ���ù�ϵ  : 
 * ��    ��  : 

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

        if(KEY_NOT_EXIST == ret)    /* δ�ҵ� */
        {
            ret = bfd_insert_array(info->send_cfg.discr.my_id, &new_index);
            if(CFG_OK != ret)
            {
                break;
            }
        }
        else if (CFG_OK == ret)  /* �ҵ� */
        {
            new_index = index;
        }
        else    /* ��������ֱֵ�ӷ��� */
        {
            break;
        }

        *add_index = new_index;
        
        ret = bfd_set_specify_fpga_database(new_index, info);
    }while(0);

    return ret;
}

/*****************************************************************************
 * �� �� ��  : bfd_del_specify_fpga_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��BFD������ɾ��ָ����Ԫ��
 * �������  : IN unsigned short index  ��Ҫɾ���������±�
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : bfd_del_fpga_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ��BFD������ɾ��ָ����KEYֵ��Ԫ��
 * �������  : IN unsigned long key  BFD MYID
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG         ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : bfd_find_cfg_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : ����BFD MYID�����ݿ��в���BFD����
 * �������  : IN unsigned long my_sid      BFD MYID
 * �������  : OUT BFD_CFG_DATABASE **data  BFD��������
 * �� �� ֵ  : RESULT_BFDCFG                ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : bfd_add_cfg_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : �����ݿ��в���BFD���ú���������
 * �������  : IN unsigned long my_sid       BFD MYID
               IN BFD_CFG *cfg               BFD��������
               IN unsigned short fpga_index  FPGA����
               IN int arad_index             arad����
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG                 ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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

        /* �����ڴ� */
        cfg_data = (BFD_CFG_DATABASE*)malloc(sizeof(BFD_CFG_DATABASE));
        if(NULL == cfg_data)
        {
            ret = ALLOC_ERROR;
            break;
        }

        OS_MEMSET(cfg_data, 0 , sizeof(BFD_CFG_DATABASE));

        /* �������� */
        cfg_data->my_sid = my_sid;
        OS_MEMCPY(&(cfg_data->cfg_data), cfg, sizeof(cfg_data->cfg_data));
        cfg_data->fpga_index = fpga_index;
        cfg_data->arad_index = arad_index;

        /* ��������� */
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
 * �� �� ��  : bfd_del_cfg_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : �����ݿ���ɾ��ָ��BFD MYID������
 * �������  : IN unsigned long my_sid  BFD MYID
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
        
        /* ���洢����ɾ�� */
        AVLL_DELETE(g_bfd_database.cfg, cfg_data->cfg_node);
        free(cfg_data);
        cfg_data = NULL;

        ret = CFG_OK;
    }while(0);

    return ret;
}

/*****************************************************************************
 * �� �� ��  : bfd_modify_cfg_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : �����ݿ����޸�ָ����BFD MYID������
 * �������  : IN unsigned long my_sid       BFD MYID
               IN BFD_CFG *cfg               BFD��������
               IN unsigned short fpga_index  FPGA����
               IN int arad_index             ARAD����
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG                 ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
        
        /* �������� */
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
 * �� �� ��  : bfd_find_alarm_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��17��
 * ��������  : ����BFD MYID�����ݿ��в���BFD�澯
 * �������  : IN unsigned long my_sid        BFD MYID
 * �������  : OUT BFD_ALARM_DATABASE **data  BFD�澯
 * �� �� ֵ  : RESULT_BFDCFG                  ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
 * �� �� ��  : bfd_add_alarm_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��17��
 * ��������  : �����ݿ��в���BFD�澯
 * �������  : IN unsigned long my_sid       BFD MYID
               IN BFD_ALM_REPORT *alarm      BFD�澯
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG                 ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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

        /* �����ڴ� */
        alarm_data = (BFD_ALARM_DATABASE*)malloc(sizeof(BFD_ALARM_DATABASE));
        if(NULL == alarm_data)
        {
            ret = ALLOC_ERROR;
            break;
        }

        OS_MEMSET(alarm_data, 0 , sizeof(*alarm_data));

        /* �������� */
        alarm_data->my_sid = my_sid;
        OS_MEMCPY(&(alarm_data->alarm), alarm, sizeof(alarm_data->alarm));

        /* ��������� */
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
 * �� �� ��  : bfd_del_alarm_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : �����ݿ���ɾ��ָ��BFD MYID�ĸ澯
 * �������  : IN unsigned long my_sid  BFD MYID
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG            ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
        
        /* ���洢����ɾ�� */
        AVLL_DELETE(g_bfd_database.alarm, alarm_data->alarm_node);
        free(alarm_data);
        alarm_data = NULL;

        ret = CFG_OK;
    }while(0);

    return ret;
}

/*****************************************************************************
 * �� �� ��  : bfd_modify_alarm_database
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��7��
 * ��������  : �����ݿ����޸�ָ����BFD MYID�ĸ澯
 * �������  : IN unsigned long my_sid       BFD MYID
               IN BFD_CFG *cfg               BFD��������
 * �������  : ��
 * �� �� ֵ  : RESULT_BFDCFG                 ������
 * ���ù�ϵ  : 
 * ��    ��  : 

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
        
        /* �������� */
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

    do /* ��ʼѭ�� */
    {
        /* ������� */
        BFD_CHECK_PARAM_POINT(BMU_ERR, event_log, ret);

        if (g_bfd_database.event.count >= BFD_EVENT_RECORD_MAX_NUM)
        {
            ret = CFG_FULL;
            break;
        }

        /* ��ʼ������ */
        NBB_INIT_LQE(event_log->list, event_log);

        /* ǰ��������ݿ��˫�������� */
        NBB_INSERT_BEFORE(g_bfd_database.event.event, event_log->list);
        g_bfd_database.event.count++;

        ret = CFG_OK;
    }
    while (0); /* ѭ��ֱ��0������ */

    return ret;
}

RESULT_BFDCFG bfd_remove_event_database(IN BFD_EVENT_LOG_INFO *event_log)
{
    RESULT_BFDCFG ret = CFG_OK;

    do /* ��ʼѭ�� */
    {
        BFD_CHECK_PARAM_POINT(BMU_ERR, event_log, ret);

        /* �����ݿ��˫���������Ƴ� */
        NBB_REMOVE_FROM_LIST(event_log->list);
        g_bfd_database.event.count--;

        ret = CFG_OK;
    }
    while (0); /* ѭ��ֱ��0������ */

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

    do /* ��ʼѭ�� */
    {
        BFD_CHECK_PARAM_POINT(BMU_ERR, event_log, ret);

        /* �ҵ�root�ڵ�ĺ�һ������ */
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
    while (0); /* ѭ��ֱ��0������ */

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

        /* �ȽϺ���compare_func����Ϊ�գ���ʾ���Ƚ� */
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

            if(0 != limit_num)    /* Ϊ0��ʾ���������� */
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
