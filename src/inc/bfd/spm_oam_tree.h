/***********************************************************************************

 * 文 件 名   : spm_oam_tree.h
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年11月8日
 * 版 本 号   : 
 * 文件描述   : spm_oam_tree.c 的头文件
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#ifndef __SPM_OAM_TREE_H__
#define __SPM_OAM_TREE_H__


#ifdef __cplusplus
#if __cplusplus
{
extern "C"
#endif
#endif /* __cplusplus */

#define FPGA_TREE_DATA_NUM  (4)     /* FPGA二叉树的数据长度 */

/* 二叉树节点 */
typedef struct   spm_oamtree_node
{
    NBB_ULONG    ulTunnelId;   /* 第一个排序指标，初始化为0xFFFFFFFF */
    NBB_ULONG    ulPwId;       /* 第二个排序指标, 初始化为0xFFFFFFFF*/
    NBB_USHORT   usLspNo;    /* 本地条目号 */
    NBB_USHORT   usPad;      /* 保留字段 */
}SPM_OAMTREE_NODE;

typedef struct   spm_fpgatree_data
{
    NBB_USHORT num;             /* 以2字节为单位的数据的有效数据长度 */
    union
    {
        struct FPGA_DATA
        {
            NBB_USHORT fpgaData[FPGA_TREE_DATA_NUM];         /* 以2字节为单位的数据，方便写入FPGA */
        }fpgaData;
        struct BFD_TABLE
        {
            NBB_USHORT   index;             /* 条目号索引 */
            NBB_USHORT   reserved1 : 12,    /* 保留字节 */
                myId_31to28b : 4;           /* MY ID的高4比特 */
            NBB_ULONG    myId_27to20b : 8,  /* MY ID的27-20比特 */
                reserved2 : 4,              /* 保留字节 */
                myId_19to0b : 20;           /* MY ID的低20比特 */
        }bfdTable;
        struct FWD_TABLE
        {
            NBB_USHORT   index;             /* 条目号索引 */
            NBB_USHORT   reserved1 : 12,    /* 保留字节 */
                myId_31to28b : 4;           /* MY ID的高4比特 */
            NBB_ULONG    myId_27to20b : 8,  /* MY ID的27-20比特 */
                reserved2 : 4,              /* 保留字节 */
                myId_19to0b : 20;           /* MY ID的低20比特 */
        }fwdTable;
        struct NNI_TABLE
        {
            NBB_ULONG index : 12,           /* 条目号 */
                ipv4_31to12b : 20;          /* IPv4的前20个字节 */
            NBB_ULONG ipv4_11to0b : 12,     /* IPv4的后12个字节 */
                pwLabel : 20;               /* PW标签 */
        }nniTable;
        struct OAM_TABLE
        {
            NBB_USHORT lspNo;               /* 条目号 */
            NBB_USHORT reserved1  : 4,      /* 保留字节 */
                tunnel_19to8b : 12;         /* TUNNEL值的19-8比特 */
            NBB_ULONG  tunnel_7to0b : 8,    /* TUNNEL值的7-0比特 */
                reserved2 : 4,              /* 保留字节 */
                pwLabel : 20;               /* PW标签 */
        }oamTable;
    }usData;
}SPM_FPGATREE_DATA;

/***********************************************************************
   FPGA二叉树获取需要填充到FPGA的数据的函数 
   输入参数 : SPM_OAMTREE_NODE*     应用层软件记录用的FPGA二叉树数据
   输出参数 : SPM_FPGATREE_DATA *   填充到FPGA的数据
   返回值   : NBB_INT               错误码
************************************************************************/
typedef NBB_INT (*SPM_OAMTREE_GET_DATA_PFN)(SPM_OAMTREE_NODE*, SPM_FPGATREE_DATA *);

/* 二叉树 */
typedef struct  spm_oamtree_set
{
    SPM_OAMTREE_NODE    *pstNodeArr;
    SPM_OAMTREE_GET_DATA_PFN pfnGetDate;
    NBB_USHORT           usNodeNum;    /* 节点数目 */ 
    NBB_BYTE             aucpad[2];     /* 保留字段 */
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
