/******************************************************************************

	Copyright (C), 2002-2010, Wuhan FiberHome Tech. Co., Ltd.

 ******************************************************************************
  �� �� ��   : oam_fpga_tree.h
  �� �� ��   : ����
  ��    ��   : ����
  ��������   : 2015��10��17��
  ��������   : oam_fpga_tree.c��ͷ�ļ�
  �޸���ʷ   :
  1.��    ��   : 2015��10��17��
    ��    ��   : ����   
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __OAM_FPGA_TREE_H__
#define __OAM_FPGA_TREE_H__

/**STRUCT+********************************************************************/
/*Description: fpga�����������궨��                                          */
/*                                                                           */
/* Added by dinghao, 2015/10/17                                              */
/*****************************************************************************/
#define SUCCESS 0
#define ERROR -1

#define FPGA_TABLE_OFFSET (0x17)
#define TMP_LABEL_MAX     (0xFFFFF)     /* TUNNEL ��ǩ���ֵ  1048575 */
#define TMC_LABEL_MAX     (0xFFFFF)     /* PW ��ǩ���ֵ  1048575 */
#define NODESTEP  (4)
#define OAM_TREE_LEVEL  (11)             /*  level = 11 ; ÿ����2k*/
#define OAM_TREE_NODE_NUM_MAX    (1 << OAM_TREE_LEVEL)   /*  maxnum =2k ; */
#define OAM_TREE_ADDR_OFFSET (0x15000)

//#define OAM_TREE_ADDR_OFFSET_MODULE_ONE    0x15000    /*��һ��2k������ģ��ƫ�Ƶ�ַ*/   
//#define OAM_TREE_ADDR_OFFSET_MODULE_TWO   0x15000    /*�ڶ���2k������ģ��ƫ�Ƶ�ַ*/


//#define CFM_OAM_DEBUG


/**STRUCT+********************************************************************/
/*Description: FPGA������������ؽṹ�嶨��                                  */
/*                                                                           */
/* Added by dinghao, 2015/10/17                                              */
/*****************************************************************************/

/* �������ڵ� */
typedef struct  oam_tree_node
{
    unsigned int    tunnel_id;   /* ��һ������ָ�꣬��ʼ��Ϊ0xFFFFFFFF */
    unsigned int    pw_id;       /* �ڶ�������ָ��, ��ʼ��Ϊ0xFFFFFFFF*/
    unsigned short   item;    /* ������Ŀ�� */
    unsigned short   pad;      /* �����ֶ� */
}OAM_TREE_NODE;

/* ������ */
typedef struct  oam_tree_set
{
    OAM_TREE_NODE   *node_array;
    unsigned short       node_num;    /* �ڵ���Ŀ */ 
    unsigned char        pad[2];     /* �����ֶ� */
}OAM_TREE_SET;


#endif

