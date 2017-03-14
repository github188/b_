/******************************************************************************

                  ��Ȩ���� (C), 1999-2013, ���ͨ�ſƼ��ɷ����޹�˾

******************************************************************************
   �� �� ��   : spm_oam_tree.c
   �� �� ��   : ����
   ��    ��   : limingming
   ��������   : 2012��9��24��
   ����޸�   :
   ��������   : FPGA����������ģ�飬��BFD��OAM��ͬʹ��
   �����б�   :
   �޸���ʷ   :
   1.��    ��   : 2012��9��24��
    ��    ��   : limingming
    �޸�����   : �����ļ�

******************************************************************************/

#include "bfd.h"

/*****************************************************************************
   �� �� ��  : spm_oamtree_init
   ��������  : OAM/BFD��������ʼ��
   �������  : IN    NBB_USHORT  usTreeNodeMaxNum:�����������ڵ���
               IN SPM_OAMTREE_GET_DATA_PFN pfnGetDate:�����������ش洢����ת����FPGA��Ҫ�����ݵĺ���ָ��
             INOUT SPM_OAMTREE_SET *pstTreeANodeSet : ������
   �������  : INOUT SPM_OAMTREE_SET *pstTreeANodeSet
   �� �� ֵ  : SUCCESS/ERROR
   ���ú���  :
   ��������  :

   �޸���ʷ      :
   1.��    ��   : 2012��8��20��
    ��    ��   : limingming
    �� �� ��   : aa
    �޸�����   : �����ɺ���

*****************************************************************************/
NBB_INT spm_oamtree_init(
    IN NBB_USHORT usTreeNodeMaxNum,
    IN SPM_OAMTREE_GET_DATA_PFN pfnGetDate,
    INOUT SPM_OAMTREE_SET *pstTreeANodeSet)
{
    /***************************************************************************/
    /* Local Variables                                                         */
    /***************************************************************************/
    NBB_ULONG ulTmpNO = 0; /* ѭ������ */
    NBB_INT iRet = ERROR;

    /***************************************************************************/
    /* ����ж�                                                                */
    /***************************************************************************/
    if ((NULL == pstTreeANodeSet) || (NULL == pfnGetDate))
    {
        BFD_LOG(BMU_ERR, "Input message is NULL\n");
        goto EXIT_LABEL;
    }

    /***************************************************************************/
    /* ����ж�                                                                */
    /***************************************************************************/
    if (0 == usTreeNodeMaxNum)
    {
       BFD_LOG(BMU_ERR, "Tree node is zero\n");
        goto EXIT_LABEL;
    }

    /***************************************************************************/
    /* ��ʼ��                                                                  */
    /***************************************************************************/
    pstTreeANodeSet->usNodeNum = 0;
    pstTreeANodeSet->pfnGetDate = pfnGetDate;

    pstTreeANodeSet->pstNodeArr = (SPM_OAMTREE_NODE *)malloc(sizeof(SPM_OAMTREE_NODE) * usTreeNodeMaxNum);

    /***************************************************************************/
    /* �ڴ�����ʧ��                                                            */
    /***************************************************************************/
    if (NULL == pstTreeANodeSet->pstNodeArr)
    {
        BFD_LOG(BMU_ERR, "Malloc error\n");
        goto EXIT_LABEL;
    }

    /* ѭ���ڵ� */
    for (ulTmpNO = 0; ulTmpNO < usTreeNodeMaxNum; ulTmpNO++)
    {
        pstTreeANodeSet->pstNodeArr[ulTmpNO].ulTunnelId = 0xffffffff;
        pstTreeANodeSet->pstNodeArr[ulTmpNO].ulPwId = 0xffffffff;
        pstTreeANodeSet->pstNodeArr[ulTmpNO].usLspNo = 0;
    }

    iRet = SUCCESS;

    EXIT_LABEL: 

    return iRet;
}

/*****************************************************************************
   �� �� ��  : spm_oamtree_nodeadd
   ��������  : ������������ڵ�
   �������  : IN NBB_USHORT usLspNumMax : �����Ŀ��
             IN SPM_OAMTREE_NODE *pstTreeNode :��Ҫ����Ľڵ�
   �������  : INOUT SPM_OAMTREE_SET *pstTree :������
   �� �� ֵ  : SUCCES/ERROR
   ���ú���  :
   ��������  :

   �޸���ʷ      :
   1.��    ��   : 2012��8��20��
    ��    ��   : limingming
    �� �� ��   : aa
    �޸�����   : �����ɺ���

*****************************************************************************/
NBB_INT spm_oamtree_nodeadd(
    IN NBB_USHORT usLspNumMax, 
    IN SPM_OAMTREE_NODE *pstTreeNode, 
    INOUT SPM_OAMTREE_SET *pstTree)
{
    /***************************************************************************/
    /* Local Variables                                                         */
    /***************************************************************************/
    NBB_INT iRet = ERROR;  /* ��������ֵ */
    NBB_USHORT usNodeNum = 0;
    NBB_USHORT usSearchIndex = 0;

    /***************************************************************************/
    /* ����ж�                                                                */
    /***************************************************************************/
    if ((NULL == pstTree) || (NULL == pstTreeNode))
    {
        BFD_LOG(BMU_ERR, "Input message is NULL\n");
        iRet = -1;
        goto EXIT_LABEL;
    }

    /***************************************************************************/
    /* ����ж�                                                                */
    /***************************************************************************/
    if ( (pstTreeNode->usLspNo >= usLspNumMax) 
        || (pstTreeNode->ulPwId > TMCLABELMAX))
    {
        BFD_LOG(BMU_ERR, "Insert node is invalid��p1 = %ld, p2 = %d, p3 = %ld, p4 = %d\n",
            pstTreeNode->ulTunnelId, pstTreeNode->usLspNo, pstTreeNode->ulPwId, usLspNumMax);
        iRet = -2;
        goto EXIT_LABEL;
    }

    /* �ж����� */
    if (pstTree->usNodeNum > usLspNumMax)
    {
        BFD_LOG(BMU_ERR, "Tree is full,p1 = %d,p2 = %d\n", pstTree->usNodeNum, usLspNumMax);
        iRet = -3;
        goto EXIT_LABEL;
    }

    /* �½ڵ��������в��� */
    iRet = spm_oamtree_nodesearch(pstTreeNode->ulTunnelId, pstTreeNode->ulPwId, pstTree, &usSearchIndex);

    if (SUCCESS == iRet) /* �Ѿ����ڽڵ� */
    {
        BFD_LOG(BMU_ERR, "This node has been add in the tree idx = %u, tunnel = %lu , pw = %lu\n",
            usSearchIndex, pstTreeNode->ulTunnelId, pstTreeNode->ulPwId);
        
//        iRet = ERROR;
        iRet = -4;
        goto EXIT_LABEL;
    }

    /* ���½ڵ㱣������������ */
    usNodeNum = pstTree->usNodeNum;
    pstTree->pstNodeArr[usNodeNum].ulTunnelId = pstTreeNode->ulTunnelId;
    pstTree->pstNodeArr[usNodeNum].usLspNo = pstTreeNode->usLspNo;
    pstTree->pstNodeArr[usNodeNum].ulPwId = pstTreeNode->ulPwId;
    pstTree->pstNodeArr[usNodeNum].usPad = pstTreeNode->usPad;

    pstTree->usNodeNum++;

    /* ����������(����С�����˳��) */
    qsort(pstTree->pstNodeArr, pstTree->usNodeNum, sizeof(SPM_OAMTREE_NODE), spm_oamtree_nodecmp);

    iRet = SUCCESS;

    EXIT_LABEL:

    return iRet;
}

/*****************************************************************************
   �� �� ��  : spm_oamtree_nodedel
   ��������  : ������������ڵ�
   �������  : IN NBB_USHORT usLspNumMax : �����Ŀ��
             IN SPM_OAMTREE_NODE *pstTreeNode :��Ҫɾ���Ľڵ�
   �������  : INOUT SPM_OAMTREE_SET *pstTree :������
   �� �� ֵ  : SUCCES/FAILED
   ���ú���  :
   ��������  :

   �޸���ʷ      :
   1.��    ��   : 2012��8��20��
    ��    ��   : limingming
    �� �� ��   : aa
    �޸�����   : �����ɺ���

*****************************************************************************/
NBB_INT spm_oamtree_nodedel(
    IN NBB_USHORT usLspNumMax, 
    IN SPM_OAMTREE_NODE *pstTreeNode, 
    INOUT SPM_OAMTREE_SET *pstTree)
{
    NBB_INT iRet = ERROR;  /* ��������ֵ */
    NBB_USHORT usSearchIndex = 0;

    /* ����ж� */
    if ((NULL == pstTree) || (NULL == pstTreeNode))
    {
        BFD_LOG(BMU_ERR, "Input message is NULL\n");
        goto EXIT_LABEL;
    }

    /* ����ж� */
    if ((pstTreeNode->usLspNo >= usLspNumMax) 
        || (pstTreeNode->ulPwId > TMCLABELMAX))
    {
        BFD_LOG(BMU_ERR, "Del node is invalid��p1 = %ld, p2 = %d, p3 = %ld, p4 = %d\n",
            pstTreeNode->ulTunnelId, pstTreeNode->usLspNo, pstTreeNode->ulPwId, usLspNumMax);
        goto EXIT_LABEL;
    }

    /* ��û�нڵ� */
    if (0 == pstTree->usNodeNum)
    {
        BFD_LOG(BMU_ERR, "Tree is empty\n");
        goto EXIT_LABEL;
    }

    /* �½ڵ��������в��� */
    iRet = spm_oamtree_nodesearch(pstTreeNode->ulTunnelId, pstTreeNode->ulPwId, pstTree, &usSearchIndex);
    if (SUCCESS != iRet) /* �ж�ִ�н�� */
    {
        BFD_LOG(BMU_ERR, "This node is not in the tree idx = %u, tunnel = %lu , pw = %lu\n",
            usSearchIndex, pstTreeNode->ulTunnelId, pstTreeNode->ulPwId);
        goto EXIT_LABEL;
    }

    /* ���������еĽڵ���λ��Чֵ */
    pstTree->pstNodeArr[usSearchIndex].usLspNo = pstTree->pstNodeArr[pstTree->usNodeNum - 1].usLspNo;
    pstTree->pstNodeArr[usSearchIndex].ulTunnelId = pstTree->pstNodeArr[pstTree->usNodeNum - 1].ulTunnelId;
    pstTree->pstNodeArr[usSearchIndex].ulPwId = pstTree->pstNodeArr[pstTree->usNodeNum - 1].ulPwId;

    pstTree->pstNodeArr[pstTree->usNodeNum - 1].usLspNo = 0;
    pstTree->pstNodeArr[pstTree->usNodeNum - 1].ulTunnelId = 0xffffffff;
    pstTree->pstNodeArr[pstTree->usNodeNum - 1].ulPwId = 0xffffffff;
    pstTree->usNodeNum--;

    /* ����������(����С�����˳��) */
    qsort(pstTree->pstNodeArr, pstTree->usNodeNum, sizeof(SPM_OAMTREE_NODE), spm_oamtree_nodecmp);

    iRet = SUCCESS;
    EXIT_LABEL: 

    return iRet;

}

/*****************************************************************************
   �� �� ��  : spm_oamtree_nodesearch
   ��������  : �����в��ҽڵ㣬�����Ѿ����չ���˳�����򣬲��ö��ַ�����
   �������  : IN NBB_ULONG ulTunnelId : �ڵ�ĵ�һ���Ƚ�Ԫ��
               IN NBB_ULONG ulPwId     : �ڵ�ĵڶ����Ƚ�Ԫ��
               IN SPM_OAMTREE_SET *pstTree  : �洢�ڵ������ָ��
   �������  :  OUT NBB_USHORT *usIndex  : �����ڣ���ʾ�ڵ��
   �� �� ֵ  :  SUCCESS �ýڵ����
                ERROR  �ýڵ㲻����
   ���ú���  :
   ��������  :

   �޸���ʷ      :
   1.��    ��   : 2012��8��23��
    ��    ��   : limingming
    �� �� ��   : aa
    �޸�����   : �����ɺ���

*****************************************************************************/
NBB_INT spm_oamtree_nodesearch (
    IN NBB_ULONG ulTunnelId, 
    IN NBB_ULONG ulPwId, 
    IN SPM_OAMTREE_SET *pstTree, 
    OUT NBB_USHORT *usIndex)
{
    NBB_USHORT usBegin = 0;
    NBB_USHORT usEnd = 0;
    NBB_USHORT usSearchIndex = 0;
    NBB_INT iRet = ERROR;

    /* ��μ�� */
    if ((NULL == pstTree) || (NULL == usIndex))
    {
        BFD_LOG(BMU_ERR, "Input message is NULL\n");
        goto EXIT_LABEL;
    }

    usEnd = pstTree->usNodeNum;

    /* ���ַ����� */
    while (usBegin < usEnd)
    {
        usSearchIndex = (usBegin + usEnd) / 2;

        /* ����ȣ����ҵ� */
        if ((pstTree->pstNodeArr[usSearchIndex].ulTunnelId == ulTunnelId) 
            && (pstTree->pstNodeArr[usSearchIndex].ulPwId == ulPwId))
        {
            iRet = SUCCESS;
            *usIndex = usSearchIndex;
            break;
        }
        else /* �����ȣ�����ַ����� */
        {
            if (pstTree->pstNodeArr[usSearchIndex].ulTunnelId == ulTunnelId) /* tunnelid��� */
            {
                if (pstTree->pstNodeArr[usSearchIndex].ulPwId < ulPwId) /* �ж�pwid */
                {
                    if (usBegin >= usSearchIndex) /* �ж����� */
                    {
                        break;
                    }
                    usBegin = usSearchIndex;
                }
                else if (pstTree->pstNodeArr[usSearchIndex].ulPwId > ulPwId) /* �ж�pwid */
                {
                    if (usEnd <= usSearchIndex) /* ��ѯ�����Ƚ� */
                    {
                        break;
                    }
                    usEnd = usSearchIndex;
                }
            }
            else if (pstTree->pstNodeArr[usSearchIndex].ulTunnelId < ulTunnelId) /* �ж�tunnelid */
            {
                if (usBegin >= usSearchIndex) /* ��ѯ�����Ƚ� */
                {
                    break;
                }
                usBegin = usSearchIndex;
            }
            else if (pstTree->pstNodeArr[usSearchIndex].ulTunnelId > ulTunnelId) /* �ж�tunnelid */
            {
                if (usEnd <= usSearchIndex) /* ��ѯ�����Ƚ� */
                {
                    break;
                }
                usEnd = usSearchIndex;
            }
        }
    }

    if (ERROR == iRet) /* ��û���ҵ� */
    {
        /* �ж����м�Ľڵ� */
        if ((usBegin == usEnd) && (pstTree->pstNodeArr[usBegin].ulTunnelId == ulTunnelId)
            && (pstTree->pstNodeArr[usSearchIndex].ulPwId == ulPwId))
        {
            iRet = SUCCESS;
            *usIndex = usSearchIndex;
        }
    }

    EXIT_LABEL:

    return iRet;
}

/*****************************************************************************
   �� �� ��  : spm_oamtree_nodecmp
   ��������  : ����ȽϺ���
   �������  : const NBB_VOID *enta
               const NBB_VOID *entb
   �������  : ��
   �� �� ֵ  :
   ���ú���  :
   ��������  :

   �޸���ʷ      :
   1.��    ��   : 2012��8��24��
    ��    ��   : limingming
    �� �� ��   : aa
    �޸�����   : �����ɺ���

*****************************************************************************/
NBB_INT spm_oamtree_nodecmp (IN const NBB_VOID *enta, IN const NBB_VOID *entb)
{
    NBB_ULONG ulTunnela = 0;  
    NBB_ULONG ulTunnelb = 0;
    NBB_ULONG ulPwa = 0;
    NBB_ULONG ulPwb = 0;
    NBB_INT   iRet = 0;
        
    /* �Ϸ��Լ�� */
    if ((NULL == enta) || (NULL == entb))
    {
//        BFD_LOG(BMU_ERR, "Input message is NULL\n");
        goto EXIT_LABEL;
    }

    ulTunnela = ((SPM_OAMTREE_NODE *)enta)->ulTunnelId;
    ulTunnelb = ((SPM_OAMTREE_NODE *)entb)->ulTunnelId;
    ulPwa = ((SPM_OAMTREE_NODE *)enta)->ulPwId;
    ulPwb = ((SPM_OAMTREE_NODE *)entb)->ulPwId;

    /* �ж���������tunnelidֵ�����Ƚ�pwid */
    if (ulTunnela == ulTunnelb) 
    {
        if (ulPwa == ulPwb) /* ��pwidֵ��� */
        {
            goto EXIT_LABEL;
        }
        else /* ��pwidֵ����� */
        {
            iRet = ((ulPwa < ulPwb) ? -1 : 1);
            goto EXIT_LABEL;
        }
    }
    else /* ��tunnelidֵ���� */
    {
        iRet = ((ulTunnela < ulTunnelb) ? -1 : 1);
        goto EXIT_LABEL;
    }
    
    EXIT_LABEL://

    return iRet;
}

/*****************************************************************************
   �� �� ��  : spm_oamtree_getarridx
   ��������  : ��������Ķ���������Ⱥ͸���ȵĽ��ţ���ȡ��Ӧ��Tree�����
               Ա����š�
   �������  : IN NBB_USHORT usTreeLevel   :  �����������
               IN NBB_USHORT usLevelIndex  :  ��ȵĽڵ��
               IN NBB_USHORT usTreeLevelMax : ��������������
   �������  : OUT NBB_USHORT *pusArrIndex :  �����Ա�����
   �� �� ֵ  :
   ���ú���  :
   ��������  :

   �޸���ʷ      :
   1.��    ��   : 2012��8��27��
    ��    ��   : limingming
    �� �� ��   : aa
    �޸�����   : �����ɺ���

*****************************************************************************/
NBB_INT spm_oamtree_getarridx(
    IN NBB_USHORT usTreeLevel, 
    IN NBB_USHORT usLevelIndex, 
    IN NBB_USHORT usTreeLevelMax, 
    OUT NBB_USHORT *pusArrIndex)
{
    NBB_USHORT usLength = 0;
    NBB_USHORT usArridx = 0;
    NBB_INT iRet = ERROR;
        
    /* �Ϸ��Լ�� */
    if (usTreeLevel >= usTreeLevelMax)
    {
//        BFD_LOG(BMU_ERR, "level exceed, treelevel=%d,treelevel >%d\n", usTreeLevel, usTreeLevelMax);

        goto EXIT_LABEL;
    }

    /* ������� */
    if (NULL == pusArrIndex)
    {
//        BFD_LOG(BMU_ERR, "Input message is NULL\n");
        goto EXIT_LABEL;
    }

    iRet = spm_oamtree_gettreelen(usTreeLevel, usTreeLevelMax, &usLength);
    if (SUCCESS != iRet) /* �ж�ִ�н�� */
    {
//        BFD_LOG(BMU_ERR, "get tree len error, treelevel = %d, maxlevel = %d\n", usTreeLevel, usTreeLevelMax);
        goto EXIT_LABEL;
    }

    if (usLevelIndex >= usLength) /* �жϷ���ֵ����Ч�� */
    {
        iRet = ERROR;
        goto EXIT_LABEL;
    }

    usArridx = (1 << (usTreeLevelMax - 1 - usTreeLevel))
        + (usLevelIndex / NODESTEP) * (1 << (usTreeLevelMax - usTreeLevel)) - 1;
    *pusArrIndex = usArridx;
        
    EXIT_LABEL://

    return iRet;

}

/*****************************************************************************
   �� �� ��  : spm_oamtree_gettreelen
   ��������  : ��ȡ������ָ������ȵĳ���
   �������  : IN NBB_USHORT usTreeLevel  :��������ָ�����
               IN NBB_USHORT usTreeLevelMax:��������������
   �������  : OUT NBB_USHORT *pusLenth  :ָ����ȵĳ���
   �� �� ֵ  : SUCCESS/FAILED
   ���ú���  :
   ��������  :

   �޸���ʷ      :
   1.��    ��   : 2012��8��27��
    ��    ��   : limingming
    �� �� ��   : aa
    �޸�����   : �����ɺ���

*****************************************************************************/
NBB_INT spm_oamtree_gettreelen (
    IN NBB_USHORT usTreeLevel, 
    IN NBB_USHORT usTreeLevelMax, 
    OUT NBB_USHORT *pusLenth)
{
    NBB_USHORT usLength = 0;
    NBB_INT    iRet = ERROR;
    
        
    
    /* �Ϸ��Լ�� */
    if (usTreeLevel >= usTreeLevelMax)
    {
//        BFD_LOG(BMU_ERR, "get tree len error, treelevel = %d, maxlevel = %d\n", usTreeLevel, usTreeLevelMax);
        goto EXIT_LABEL;
    }

    /* �Ϸ��Լ�� */
    if (NULL == pusLenth)
    {
//        BFD_LOG(BMU_ERR, "Input message is NULL\n");
        goto EXIT_LABEL;
    }

    usLength = NODESTEP * (1 << usTreeLevel);
    *pusLenth = usLength;

    iRet = SUCCESS;
    
    EXIT_LABEL://

    return iRet;

}

/*****************************************************************************
   �� �� ��  : spm_oamtree_build
   ��������  : ����������
   �������  : IN SPM_OAMTREE_SET *pstTreeNodeSet:������
             IN NBB_USHORT usTreeLevelMax:������������
             IN NBB_ULONG *pulTreeBaseAdd:������ÿ�����ʼ��ַ
             IN NBB_ULONG model_base      ģ�����ַ����BFDģ�飬OAMģ���
             IN NBB_ULONG ulBaseAddress:�������Ļ���ַ
   �������  : ��
   �� �� ֵ  :
   ���ú���  :
   ��������  :

   �޸���ʷ      :
   1.��    ��   : 2012��8��27��
    ��    ��   : limingming
    �� �� ��   : aa
    �޸�����   : �����ɺ���

*****************************************************************************/
NBB_INT spm_oamtree_build(IN NBB_USHORT usTreeLevelMax,
    IN SPM_OAMTREE_SET *pstTreeNodeSet,
    IN NBB_ULONG *pulTreeBaseAdd,
    IN NBB_ULONG model_base,
    IN NBB_ULONG ulBaseAddress)
{
    NBB_USHORT usTreeLevel = 0; /* �������Ĳ��� */
    NBB_USHORT usLevelLength = 0; /* �������Ľڵ�� */
    NBB_USHORT usIndex = 0; /* ��Ӧ���������� */
    NBB_ULONG  ulAddress = 0;
    NBB_USHORT usTempLoop = 0; /* ѭ������ */
    NBB_INT    iRet = ERROR;
    SPM_FPGATREE_DATA stFpagData;
    NBB_USHORT usLoopi = 0;

    
    /* �Ϸ��Լ�� */
    if ((NULL == pstTreeNodeSet) || (NULL == pulTreeBaseAdd))
    {
        BFD_LOG(BMU_ERR, "Input message is NULL\n");
        goto EXIT_LABEL;
    }

    OS_MEMSET(&stFpagData, 0, sizeof(SPM_FPGATREE_DATA));

    /* ѭ������ */
    for (usTreeLevel = 0; usTreeLevel < usTreeLevelMax; usTreeLevel++)
    {
        pulTreeBaseAdd[usTreeLevel] = (((1 << usTreeLevelMax) - 2) << (usTreeLevel + 2)) 
            & ((1 << usTreeLevelMax) * 4 - 1); 
        
        iRet = spm_oamtree_gettreelen(usTreeLevel, usTreeLevelMax, &usLevelLength);
        if (SUCCESS != iRet) /* �ж�ִ�н�� */
        {
            BFD_LOG(BMU_ERR, "get tree len error, treelevel = %d, maxlevel = %d\n", usTreeLevel, usTreeLevelMax);
            goto EXIT_LABEL;
        }

        /* ѭ�� */
        for (usTempLoop = 0; usTempLoop < usLevelLength; usTempLoop = usTempLoop + 4)
        {
            iRet = spm_oamtree_getarridx(usTreeLevel, usTempLoop, usTreeLevelMax, &usIndex);
            if (SUCCESS != iRet) /* �ж�ִ�н�� */
            {
                BFD_LOG(BMU_ERR, "Get tree Index error,p1 = %d,p2 = %d,p3 = %d\n", 
                    usTreeLevel, usTempLoop, usIndex);
                goto EXIT_LABEL;
            }
            ulAddress = pulTreeBaseAdd[usTreeLevel] + usTempLoop;


            if(NULL != pstTreeNodeSet->pfnGetDate)
            {
                /* ת�����ش洢��ֵΪFPGA��Ҫʹ�õ����� */
                iRet = pstTreeNodeSet->pfnGetDate(&(pstTreeNodeSet->pstNodeArr[usIndex]), &stFpagData);
                if (SUCCESS != iRet)
                {
                    goto EXIT_LABEL;
                }

                /* ��ֹ�Ժ��������ݽṹSPM_FPGATREE_DATA�ܳ��ȵ���û�иĺ�FPGA_TREE_DATA_NUM */
                assert(stFpagData.num <= FPGA_TREE_DATA_NUM);
                
                /* ��FPGAд���� */
                for (usLoopi = 0; usLoopi < stFpagData.num; usLoopi++) /* �Ա���usLoopi����ѭ�� */
                {
                    spm_oamtree_s16write(model_base, ulBaseAddress, ulAddress + usLoopi, 
                        stFpagData.usData.fpgaData.fpgaData[usLoopi]);
                }
            }
        }
    }

    iRet = SUCCESS;
    EXIT_LABEL:

    return iRet;
}

/*******************************************************���Դ�ӡ����******************************************************/

/*****************************************************************************
 �� �� ��  : spm_oamtree_print
 ��������  : ��������ӡ����
 �������  : IN SPM_OAMTREE_SET *pstTree :������ָ��
             IN NBB_USHORT usNumMax      :��Ҫ��ӡ�Ľڵ���          
             NBB_CCXT_T NBB_CCXT          
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��9��26��
    ��    ��   : limingming
    �� �� ��   : #
    �޸�����   : �����ɺ���

*****************************************************************************/
NBB_VOID spm_oamtree_print(IN SPM_OAMTREE_SET *pstTree, IN NBB_USHORT usNumMax)
{
    NBB_USHORT usLoopi = 0; /* ѭ������ */
    
    /* �ж���� */
    if (NULL == pstTree)
    {
        BFD_LOG(BMU_ERR, "Input message is NULL\n");
        goto EXIT_LABEL;
    }

    /* �ж���Σ���Ҫ�������ֵ���ڽڵ������򲻷��أ���ӡȫ�����ڵĽڵ��� */
    if (usNumMax > pstTree->usNodeNum)
    {
        BFD_LOG(BMU_ERR, "Exceed tree node��input num is %d\n", usNumMax);
        usNumMax = pstTree->usNodeNum;
    }
    
    BFD_LOG(BMU_ERR, "Tree node = %d\n", pstTree->usNodeNum);

    /* ѭ����ӡ */
    for (usLoopi = 0; usLoopi < usNumMax; usLoopi++)
    {
        BFD_LOG(BMU_ERR, "tunnel = %lu, pw = %lu, lspno = %u\n", pstTree->pstNodeArr[usLoopi].ulTunnelId,
            pstTree->pstNodeArr[usLoopi].ulPwId, pstTree->pstNodeArr[usLoopi].usLspNo);
    }
    
    EXIT_LABEL:

    return;
}

/*******************************************FPGA��ز���**************************************************/
/*****************************************************************************
 �� �� ��  : spm_oamtree_switch
 ��������  : �ȴ����������ڷǷ�ҳ״̬
 �������  : IN NBB_ULONG model_base :             ģ�����ַ����BFDģ�飬BFD����ģ�飬OAMģ���
             IN NBB_ULONG rev_head_analyze_base  : BFD������ͷ������ģ��        
             IN NBB_ULONG tree_swtich_offset  :    �Ự���������ұ�ҳ���Ƶ�ַƫ��
             NBB_CCXT_T NBB_CCXT              
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��9��27��
    ��    ��   : limingming
    �� �� ��   : #
    �޸�����   : �����ɺ���

*****************************************************************************/
NBB_VOID  spm_oamtree_switch(IN NBB_ULONG model_base, IN NBB_ULONG rev_head_analyze_base,
    IN NBB_ULONG tree_swtich_offset)
{
    NBB_USHORT usTempValue = DRV_USHORT_INVALID;

    /* �ȴ����������ڿ���״̬ */
    while (0 != usTempValue)
    {
        usTempValue = spm_oamtree_s16read(model_base, rev_head_analyze_base, tree_swtich_offset);
        usTempValue = usTempValue & 0x1;
    }

    

    return;
}


/*****************************************************************************
 * �� �� ��  : spm_oamtree_s16read
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��15��
 * ��������  : ��ȡFPGA����(16λ��)
 * �������  : IN NBB_ULONG model_base      ģ�����ַ����BFDģ�飬BFD����ģ�飬OAMģ���
               IN NBB_ULONG sub_model_base  ��ģ�����ַ����BFD����ģ��Ĵ�����
               IN NBB_ULONG offset_addr     ƫ�Ƶ�ַ
 * �������  : ��
 * �� �� ֵ  : NBB_USHORT                   ��ȡ����ָ����ַ��ֵ
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
NBB_USHORT spm_oamtree_s16read(IN NBB_ULONG model_base, IN NBB_ULONG sub_model_base, IN NBB_ULONG offset_addr)
{
    NBB_USHORT data = 0;
    NBB_UINT offset = 0;
            
    offset = (NBB_INT)(sub_model_base + offset_addr);
    (NBB_VOID)read_fpga_mmap(model_base, offset, &data);

    return data;
}

/*****************************************************************************
 * �� �� ��  : spm_oamtree_s32read
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��15��
 * ��������  : ��ȡFPGA����(32λ��)
 * �������  : IN NBB_ULONG model_base      ģ�����ַ����BFDģ�飬BFD����ģ�飬OAMģ���
               IN NBB_ULONG sub_model_base  ��ģ�����ַ����BFD����ģ��Ĵ�����
               IN NBB_ULONG offset_addr     ƫ�Ƶ�ַ
 * �������  : ��
 * �� �� ֵ  : NBB_ULONG                    ��ȡ����ָ����ַ��ֵ
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
NBB_ULONG spm_oamtree_s32read(IN NBB_ULONG model_base, IN NBB_ULONG sub_model_base, IN NBB_ULONG offset_addr)
{
    NBB_ULONG data = 0;
    NBB_UINT offset = 0;
            
    offset = (NBB_INT)(sub_model_base + offset_addr);
    (NBB_VOID)read_fpga_mmap_32b(model_base, offset, &data);

    return data;
}

/*****************************************************************************
 * �� �� ��  : spm_oamtree_s16write
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��15��
 * ��������  : дFPGA����(16λд)
 * �������  : IN NBB_ULONG model_base      ģ�����ַ����BFDģ�飬BFD����ģ�飬OAMģ���
               IN NBB_ULONG sub_model_base  ��ģ�����ַ����BFD����ģ��Ĵ�����
               IN NBB_ULONG offset_addr     ƫ�Ƶ�ַ
               IN NBB_USHORT  data          ��Ҫд�������
 * �������  : ��
 * �� �� ֵ  : NBB_VOID                     ��
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
NBB_VOID spm_oamtree_s16write(IN NBB_ULONG model_base,
    IN NBB_ULONG sub_model_base,
    IN NBB_ULONG offset_addr,
    IN NBB_USHORT data)
{
    NBB_UINT offset = 0;
    
    offset = (NBB_INT)(sub_model_base + offset_addr);
    (NBB_VOID)write_fpga_mmap(model_base, offset, data);
    
    return;
}

/*****************************************************************************
 * �� �� ��  : spm_oamtree_s32write
 * �� �� ��  : jiangbo,����
 * ��������  : 2016��11��15��
 * ��������  : дFPGA����(32λд)
 * �������  : IN NBB_ULONG model_base      ģ�����ַ����BFDģ�飬BFD����ģ�飬OAMģ���
               IN NBB_ULONG sub_model_base  ��ģ�����ַ����BFD����ģ��Ĵ�����
               IN NBB_ULONG offset_addr     ƫ�Ƶ�ַ
               IN NBB_ULONG data            ��Ҫд�������
 * �������  : ��
 * �� �� ֵ  : NBB_VOID                     ��
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
NBB_VOID spm_oamtree_s32write(IN NBB_ULONG model_base,
    IN NBB_ULONG sub_model_base, 
    IN NBB_ULONG offset_addr, 
    IN NBB_ULONG data)
{
    NBB_UINT offset = 0;
    
    offset = (NBB_INT)(sub_model_base + offset_addr);
    (NBB_VOID)write_fpga_mmap_32b(model_base, offset, data);
    
    return;
}

