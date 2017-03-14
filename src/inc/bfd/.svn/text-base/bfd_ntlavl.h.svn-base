/***********************************************************************************

 * 文 件 名   : bfd_ntlavl.h
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年10月19日
 * 版 本 号   : 
 * 文件描述   : 平衡二叉树相关头文件
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#ifndef NTLAVL_INCLUDED
#define NTLAVL_INCLUDED

#include <assert.h>

#ifndef TRUE
#define TRUE  1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define BFD_NBB_MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define BFD_NBB_MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define BFD_NBB_REF_DEBUG_VARIABLE(X) { (X) = (X); }

/*****************************************************************************/
/* Find the offset of specified field within specified structure             */
/*****************************************************************************/
#define STRUCT_OFFSETOF(STRUCT, FIELD)                                           \
            (unsigned long)((unsigned char *)(&((STRUCT *)0)->FIELD) - (unsigned char *)0)

/**INC+***********************************************************************/
/* Header:    ntlavl.h                                                       */
/*                                                                           */
/* Purpose:   AVL tree functions                                             */
/*                                                                           */
/* (C) COPYRIGHT METASWITCH NETWORKS 1993 - 2010                             */
/*                                                                           */
/* $Revision:: 1537                    $$Date:: 2010-07-19 21:32:33 +0100 (#$*/
/**INC-***********************************************************************/

/*****************************************************************************/
/* VxWorks 5.4.2 and above and VxWorks AE 1.0 typedef AVL_TREE and AVL_NODE  */
/* structures.  In order to avoid conflict with the OS equivalents the       */
/* N-BASE definitions are renamed.                                           */
/*****************************************************************************/
/**STRUCT+********************************************************************/
/* Structure: AVL_NODE                                                       */
/*                                                                           */
/* Description: Node in an AVL tree.                                         */
/*****************************************************************************/

typedef struct avl_node
{
  struct avl_node *parent;
  struct avl_node *left;
  struct avl_node *right;
  unsigned short l_height;
  unsigned short r_height;
  void *self;
  void *key;
} AVL_NODE;

/**STRUCT-********************************************************************/

/*****************************************************************************/
/* compare function                                                          */
/*****************************************************************************/
typedef int(AVL_COMPARE)(void *, void *);

/**STRUCT+********************************************************************/
/* Structure: AVL_TREE                                                       */
/*                                                                           */
/* Description: AVL tree root.                                               */
/*****************************************************************************/

typedef struct avl_tree
{
  AVL_COMPARE *compare;
  AVL_NODE *root;
  AVL_NODE *first;
  AVL_NODE *last;
} AVL_TREE;

/**STRUCT-********************************************************************/

/*****************************************************************************/
/* AVL functions                                                             */
/*****************************************************************************/
void *bfd_avl_insert_or_find(AVL_TREE  *,
                                            AVL_NODE  *);
void bfd_avl_delete(AVL_TREE *, AVL_NODE *);
void *bfd_avl_find(AVL_TREE *, void *  BFD_NBB_CCXT_T);
void *bfd_avl_find_or_find_next(AVL_TREE *,
                                             void *, int  BFD_NBB_CCXT_T);
void *bfd_avl_next(AVL_NODE *);
void *bfd_avl_prev(AVL_NODE *);
void bfd_avl_verify_tree(AVL_TREE *);

/*****************************************************************************/
/* AVL access macros                                                         */
/*****************************************************************************/
#define AVL_INIT_TREE(TREE, COMPARE)   (TREE).compare = &(COMPARE);      \
                                       (TREE).first = NULL;              \
                                       (TREE).last = NULL;               \
                                       (TREE).root = NULL

#define AVL_INIT_NODE(NODE, SELF, KEY) (NODE).parent = NULL;             \
                                       (NODE).left = NULL;               \
                                       (NODE).right = NULL;              \
                                       (NODE).self = (SELF);             \
                                       (NODE).key = (KEY);               \
                                       (NODE).l_height = -1;             \
                                       (NODE).r_height = -1;

/*****************************************************************************/
/* Macro definitions                                                         */
/*****************************************************************************/
#define AVL_INSERT(TREE, NODE)                                                \
               (bfd_avl_insert_or_find(&(TREE), &(NODE)) == NULL)
#define AVL_INSERT_OR_FIND(TREE, NODE)                                        \
               bfd_avl_insert_or_find(&(TREE), &(NODE))
#define AVL_DELETE(TREE, NODE)     bfd_avl_delete(&(TREE), &(NODE))
#define AVL_FIND(TREE, KEY)        bfd_avl_find(&(TREE), (KEY))
#define AVL_NEXT(NODE)             bfd_avl_next(&(NODE))
#define AVL_PREV(NODE)             bfd_avl_prev(&(NODE))
#define AVL_FIRST(TREE)                                                       \
                   (((&(TREE))->first != NULL) ? (&(TREE))->first->self : NULL)

#define AVL_LAST(TREE)                                                        \
                     (((&(TREE))->last != NULL) ? (&(TREE))->last->self : NULL)

#define AVL_IN_TREE(NODE)  (((NODE).l_height != -1) && ((NODE).r_height != -1))

#define AVL_FIND_NEXT(TREE, KEY)                                              \
                      bfd_avl_find_or_find_next(&(TREE), (KEY), TRUE)

#define AVL_FIND_OR_FIND_NEXT(TREE, KEY)                                      \
                     bfd_avl_find_or_find_next(&(TREE), (KEY), FALSE)


#define AVL_VERIFY_TREE(TREE)


/*****************************************************************************/
/* Standard compare functions                                                */
/*****************************************************************************/
int compare_byte(void *, void *);
int compare_short(void *, void *);
int compare_ushort(void *, void *);
int compare_long(void *, void *);
int compare_ulong(void *, void *);
int compare_int(void *, void *);
int compare_uint(void *, void *);

#endif
