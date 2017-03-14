/******************************************************************************

	Copyright (C), 2002-2010, Wuhan FiberHome Tech. Co., Ltd.

 ******************************************************************************
  文 件 名   : oam_fpga_tree.h
  版 本 号   : 初稿
  作    者   : 丁浩
  生成日期   : 2015年10月17日
  功能描述   : oam_fpga_tree.c的头文件
  修改历史   :
  1.日    期   : 2015年10月17日
    作    者   : 丁浩   
    修改内容   : 创建文件

******************************************************************************/
#ifndef __OAM_FPGA_TREE_H__
#define __OAM_FPGA_TREE_H__

/**STRUCT+********************************************************************/
/*Description: fpga二叉搜索树宏定义                                          */
/*                                                                           */
/* Added by dinghao, 2015/10/17                                              */
/*****************************************************************************/
#define SUCCESS 0
#define ERROR -1

#define FPGA_TABLE_OFFSET (0x17)
#define TMP_LABEL_MAX     (0xFFFFF)     /* TUNNEL 标签最大值  1048575 */
#define TMC_LABEL_MAX     (0xFFFFF)     /* PW 标签最大值  1048575 */
#define NODESTEP  (4)
#define OAM_TREE_LEVEL  (11)             /*  level = 11 ; 每棵树2k*/
#define OAM_TREE_NODE_NUM_MAX    (1 << OAM_TREE_LEVEL)   /*  maxnum =2k ; */
#define OAM_TREE_ADDR_OFFSET (0x15000)

//#define OAM_TREE_ADDR_OFFSET_MODULE_ONE    0x15000    /*第一个2k二叉树模块偏移地址*/   
//#define OAM_TREE_ADDR_OFFSET_MODULE_TWO   0x15000    /*第二个2k二叉树模块偏移地址*/


//#define CFM_OAM_DEBUG


/**STRUCT+********************************************************************/
/*Description: FPGA二插搜索树相关结构体定义                                  */
/*                                                                           */
/* Added by dinghao, 2015/10/17                                              */
/*****************************************************************************/

/* 二叉树节点 */
typedef struct  oam_tree_node
{
    unsigned int    tunnel_id;   /* 第一个排序指标，初始化为0xFFFFFFFF */
    unsigned int    pw_id;       /* 第二个排序指标, 初始化为0xFFFFFFFF*/
    unsigned short   item;    /* 本地条目号 */
    unsigned short   pad;      /* 保留字段 */
}OAM_TREE_NODE;

/* 二叉树 */
typedef struct  oam_tree_set
{
    OAM_TREE_NODE   *node_array;
    unsigned short       node_num;    /* 节点数目 */ 
    unsigned char        pad[2];     /* 保留字段 */
}OAM_TREE_SET;


#endif

