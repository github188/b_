/***********************************************************************************

 * �� �� ��   : spm_oam_tree.h
 * �� �� ��   : jiangbo,����
 * ��������   : 2016��11��8��
 * �� �� ��   : 
 * �ļ�����   : spm_oam_tree.c ��ͷ�ļ�
 * ��Ȩ˵��   : Copyright (C) 2000-2016   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 

***********************************************************************************/

#ifndef __SPM_OAM_TREE_H__
#define __SPM_OAM_TREE_H__


#ifdef __cplusplus
#if __cplusplus
{
extern "C"
#endif
#endif /* __cplusplus */

#define FPGA_TREE_DATA_NUM  (4)     /* FPGA�����������ݳ��� */

/* �������ڵ� */
typedef struct   spm_oamtree_node
{
    NBB_ULONG    ulTunnelId;   /* ��һ������ָ�꣬��ʼ��Ϊ0xFFFFFFFF */
    NBB_ULONG    ulPwId;       /* �ڶ�������ָ��, ��ʼ��Ϊ0xFFFFFFFF*/
    NBB_USHORT   usLspNo;    /* ������Ŀ�� */
    NBB_USHORT   usPad;      /* �����ֶ� */
}SPM_OAMTREE_NODE;

typedef struct   spm_fpgatree_data
{
    NBB_USHORT num;             /* ��2�ֽ�Ϊ��λ�����ݵ���Ч���ݳ��� */
    union
    {
        struct FPGA_DATA
        {
            NBB_USHORT fpgaData[FPGA_TREE_DATA_NUM];         /* ��2�ֽ�Ϊ��λ�����ݣ�����д��FPGA */
        }fpgaData;
        struct BFD_TABLE
        {
            NBB_USHORT   index;             /* ��Ŀ������ */
            NBB_USHORT   reserved1 : 12,    /* �����ֽ� */
                myId_31to28b : 4;           /* MY ID�ĸ�4���� */
            NBB_ULONG    myId_27to20b : 8,  /* MY ID��27-20���� */
                reserved2 : 4,              /* �����ֽ� */
                myId_19to0b : 20;           /* MY ID�ĵ�20���� */
        }bfdTable;
        struct FWD_TABLE
        {
            NBB_USHORT   index;             /* ��Ŀ������ */
            NBB_USHORT   reserved1 : 12,    /* �����ֽ� */
                myId_31to28b : 4;           /* MY ID�ĸ�4���� */
            NBB_ULONG    myId_27to20b : 8,  /* MY ID��27-20���� */
                reserved2 : 4,              /* �����ֽ� */
                myId_19to0b : 20;           /* MY ID�ĵ�20���� */
        }fwdTable;
        struct NNI_TABLE
        {
            NBB_ULONG index : 12,           /* ��Ŀ�� */
                ipv4_31to12b : 20;          /* IPv4��ǰ20���ֽ� */
            NBB_ULONG ipv4_11to0b : 12,     /* IPv4�ĺ�12���ֽ� */
                pwLabel : 20;               /* PW��ǩ */
        }nniTable;
        struct OAM_TABLE
        {
            NBB_USHORT lspNo;               /* ��Ŀ�� */
            NBB_USHORT reserved1  : 4,      /* �����ֽ� */
                tunnel_19to8b : 12;         /* TUNNELֵ��19-8���� */
            NBB_ULONG  tunnel_7to0b : 8,    /* TUNNELֵ��7-0���� */
                reserved2 : 4,              /* �����ֽ� */
                pwLabel : 20;               /* PW��ǩ */
        }oamTable;
    }usData;
}SPM_FPGATREE_DATA;

/***********************************************************************
   FPGA��������ȡ��Ҫ��䵽FPGA�����ݵĺ��� 
   ������� : SPM_OAMTREE_NODE*     Ӧ�ò������¼�õ�FPGA����������
   ������� : SPM_FPGATREE_DATA *   ��䵽FPGA������
   ����ֵ   : NBB_INT               ������
************************************************************************/
typedef NBB_INT (*SPM_OAMTREE_GET_DATA_PFN)(SPM_OAMTREE_NODE*, SPM_FPGATREE_DATA *);

/* ������ */
typedef struct  spm_oamtree_set
{
    SPM_OAMTREE_NODE    *pstNodeArr;
    SPM_OAMTREE_GET_DATA_PFN pfnGetDate;
    NBB_USHORT           usNodeNum;    /* �ڵ���Ŀ */ 
    NBB_BYTE             aucpad[2];     /* �����ֶ� */
}SPM_OAMTREE_SET;

extern NBB_INT spm_oamtree_build(IN NBB_USHORT usTreeLevelMax,
             IN SPM_OAMTREE_SET *pstTreeNodeSet,
             IN NBB_ULONG *pulTreeBaseAdd,
             IN NBB_ULONG model_base,
             IN NBB_ULONG ulBaseAddress);
extern NBB_INT spm_oamtree_getarridx(
             IN NBB_USHORT usTreeLevel, 
             IN NBB_USHORT usLevelIndex, 
             IN NBB_USHORT usTreeLevelMax, 
             OUT NBB_USHORT *pusArrIndex);
extern NBB_INT spm_oamtree_gettreelen (
             IN NBB_USHORT usTreeLevel, 
             IN NBB_USHORT usTreeLevelMax, 
             OUT NBB_USHORT *pusLenth);
extern NBB_INT spm_oamtree_init(
             IN NBB_USHORT usTreeNodeMaxNum,
             IN SPM_OAMTREE_GET_DATA_PFN pfnGetDate,
             INOUT SPM_OAMTREE_SET *pstTreeANodeSet);
extern NBB_INT spm_oamtree_nodeadd(
             IN NBB_USHORT usLspNumMax, 
             IN SPM_OAMTREE_NODE *pstTreeNode, 
             INOUT SPM_OAMTREE_SET *pstTree);
extern NBB_INT spm_oamtree_nodecmp (IN const NBB_VOID *enta, IN const NBB_VOID *entb);
extern NBB_INT spm_oamtree_nodedel(
             IN NBB_USHORT usLspNumMax, 
             IN SPM_OAMTREE_NODE *pstTreeNode, 
             INOUT SPM_OAMTREE_SET *pstTree);
extern NBB_INT spm_oamtree_nodesearch (
             IN NBB_ULONG ulTunnelId, 
             IN NBB_ULONG ulPwId, 
             IN SPM_OAMTREE_SET *pstTree, 
             OUT NBB_USHORT *usIndex);
extern NBB_VOID spm_oamtree_print(IN SPM_OAMTREE_SET *pstTree, IN NBB_USHORT usNumMax);
extern NBB_USHORT spm_oamtree_s16read(IN NBB_ULONG model_base, IN NBB_ULONG sub_model_base, IN NBB_ULONG offset_addr);
extern NBB_VOID spm_oamtree_s16write(IN NBB_ULONG model_base,
             IN NBB_ULONG sub_model_base,
             IN NBB_ULONG offset_addr,
             IN NBB_USHORT data);
extern NBB_ULONG spm_oamtree_s32read(IN NBB_ULONG model_base, IN NBB_ULONG sub_model_base, IN NBB_ULONG offset_addr);
extern NBB_VOID spm_oamtree_s32write(IN NBB_ULONG model_base,
             IN NBB_ULONG sub_model_base, 
             IN NBB_ULONG offset_addr, 
             IN NBB_ULONG data);
extern NBB_VOID  spm_oamtree_switch(IN NBB_ULONG model_base, IN NBB_ULONG rev_head_analyze_base,
             IN NBB_ULONG tree_swtich_offset);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __SPM_OAM_TREE_H__ */
