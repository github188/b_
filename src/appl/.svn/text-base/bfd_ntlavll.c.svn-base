/***********************************************************************************

 * 文 件 名   : bfd_ntlavll.c
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年10月19日
 * 版 本 号   : 
 * 文件描述   : AVL Lite and AVL3 (AVL Lite Lite) tree functions
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

/**MOD+***********************************************************************/
/* Module:    ntlavll.c                                                      */
/*                                                                           */
/* Purpose:   AVL Lite and AVL3 (AVL Lite Lite) tree functions               */
/*                                                                           */
/* (C) COPYRIGHT METASWITCH NETWORKS 1999 - 2012                             */
/*                                                                           */
/* $Revision:: 10002                   $$Date:: 2012-01-13 16:29:26 +0000 #$ */
/*                                                                           */
/**MOD-***********************************************************************/

#define BFD_INTERNAL
#include "nbase_stub.h"
#include "nbbxtype.h"
#include <bfd_ntlavll.h>


/*
Chenpeng 201303
The non-nbase thread call will cause the internal trace assert failed.
so do not use the internal tracing in these API.
*/

void bfd_avl3_balance_tree(AVL3_TREE *, AVL3_NODE *);

void bfd_avl3_rebalance(AVL3_NODE **);

void bfd_avl3_rotate_right(AVL3_NODE **);

void bfd_avl3_rotate_left(AVL3_NODE **);

void bfd_avl3_swap_right_most(AVL3_TREE *,
                                  AVL3_NODE *,
                                  AVL3_NODE *);

void bfd_avl3_swap_left_most(AVL3_TREE *,
                                 AVL3_NODE *,
                                 AVL3_NODE *);

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_insert_or_find                                        */
/*                                                                           */
/* Purpose:   Insert the supplied node into the specified AVL3 tree if key   */
/*            does not already exist, otherwise returning the existing node  */
/*                                                                           */
/* Returns:   void *          - Pointer to existing entry if found.      */
/*                                  NULL if no such entry (implies node      */
/*                                  successfully inserted)                   */
/*                                                                           */
/* Params:    IN/OUT tree         - a pointer to the AVL3 tree               */
/*            IN/OUT node         - a pointer to the node to insert          */
/*            IN     tree_info    - a pointer to the AVL3 tree info          */
/*                                                                           */
/* Operation: Scan down the tree looking for the insert point, going left if */
/*            the insert key is less than the key in the tree and right if   */
/*            it is greater.  When the insert point is found insert the new  */
/*            node and rebalance the tree if necessary.  Return the existing */
/*            entry instead, if found                                        */
/*                                                                           */
/**PROC-**********************************************************************/
void *bfd_avl3_insert_or_find(AVL3_TREE *tree,
                                  AVL3_NODE *node,
                                  const AVL3_TREE_INFO *tree_info)
{
  /***************************************************************************/
  /* insert specified node into tree                                         */
  /***************************************************************************/
  AVL3_NODE *parent_node;
  int result;
  void *existing_entry = NULL;


  BFD_NBB_ASSERT_NUM_EQ(AVL3_IN_TREE(*node), 0);


  node->r_height = 0;
  node->l_height = 0;

  if (tree->root == NULL)
  {
    /*************************************************************************/
    /* tree is empty, so insert at root                                      */
    /*************************************************************************/
    tree->root = node;
    tree->first = node;
    tree->last = node;
    goto EXIT;
  }

  /***************************************************************************/
  /* scan down the tree looking for the appropriate insert point             */
  /***************************************************************************/
  parent_node = tree->root;
  while (parent_node != NULL)
  {
    /*************************************************************************/
    /* go left or right, depending on comparison                             */
    /*************************************************************************/
    result = tree_info->compare((void *)((unsigned char *)node -
                                             tree_info->node_offset +
                                             tree_info->key_offset),
                                (void *)((unsigned char *)parent_node -
                                             tree_info->node_offset +
                                             tree_info->key_offset));

    if (result > 0)
    {
      /***********************************************************************/
      /* new key is greater than this node's key, so move down right subtree */
      /***********************************************************************/
      if (parent_node->right == NULL)
      {
        /*********************************************************************/
        /* right subtree is empty, so insert here                            */
        /*********************************************************************/
        node->parent = parent_node;
        parent_node->right = node;
        parent_node->r_height = 1;
        if (parent_node == tree->last)
        {
          /*******************************************************************/
          /* parent was the right-most node in the tree, so new node is now  */
          /* right-most                                                      */
          /*******************************************************************/
          tree->last = node;
        }
        break;
      }
      else
      {
        /*********************************************************************/
        /* right subtree is not empty                                        */
        /*********************************************************************/
        parent_node = parent_node->right;
      }
    }
    else if (result < 0)
    {
      /***********************************************************************/
      /* new key is less than this node's key, so move down left subtree     */
      /***********************************************************************/
      if (parent_node->left == NULL)
      {
        /*********************************************************************/
        /* left subtree is empty, so insert here                             */
        /*********************************************************************/
        node->parent = parent_node;
        parent_node->left = node;
        parent_node->l_height = 1;
        if (parent_node == tree->first)
        {
          /*******************************************************************/
          /* parent was the left-most node in the tree, so new node is now   */
          /* left-most                                                       */
          /*******************************************************************/
          tree->first = node;
        }
        break;
      }
      else
      {
        /*********************************************************************/
        /* left subtree is not empty                                         */
        /*********************************************************************/
        parent_node = parent_node->left;
      }
    }
    else
    {
      /***********************************************************************/
      /* found a matching key, so get out now and return entry found         */
      /***********************************************************************/

      existing_entry = (void *)
                            ((unsigned char *)parent_node - tree_info->node_offset);
      node->r_height = -1;
      node->l_height = -1;
      goto EXIT;
    }
  }

  /***************************************************************************/
  /* now rebalance the tree if necessary                                     */
  /***************************************************************************/
  bfd_avl3_balance_tree(tree, parent_node);

EXIT:


  return(existing_entry);

} /* bfd_avl3_insert_or_find */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_delete                                                */
/*                                                                           */
/* Purpose:   Delete the specified node from the specified AVL3 tree         */
/*                                                                           */
/* Returns:   Nothing                                                        */
/*                                                                           */
/* Params:    IN/OUT tree         - a pointer to the AVL3 tree               */
/*            IN/OUT node         - a pointer to the node to delete          */
/*                                                                           */
/**PROC-**********************************************************************/
void bfd_avl3_delete(AVL3_TREE *tree, AVL3_NODE *node)
{
  /***************************************************************************/
  /* delete specified node from tree                                         */
  /***************************************************************************/
  AVL3_NODE *replace_node;
  AVL3_NODE *parent_node;
  unsigned short new_height;


  BFD_NBB_ASSERT_NUM_NE(AVL3_IN_TREE(*node), 0);

  if ((node->left == NULL) &&
      (node->right == NULL))
  {
    /*************************************************************************/
    /* barren node (no children), so just delete it                          */
    /*************************************************************************/
    replace_node = NULL;

    if (tree->first == node)
    {
      /***********************************************************************/
      /* node was first in tree, so replace it                               */
      /***********************************************************************/
      tree->first = node->parent;
    }

    if (tree->last == node)
    {
      /***********************************************************************/
      /* node was last in tree, so replace it                                */
      /***********************************************************************/
      tree->last = node->parent;
    }
  }
  else if (node->left == NULL)
  {
    /*************************************************************************/
    /* node has no left son, so replace with right son                       */
    /*************************************************************************/
    replace_node = node->right;

    if (tree->first == node)
    {
      /***********************************************************************/
      /* node was first in tree, so replace it                               */
      /***********************************************************************/
      tree->first = replace_node;
    }
  }
  else if (node->right == NULL)
  {
    /*************************************************************************/
    /* node has no right son, so replace with left son                       */
    /*************************************************************************/
    replace_node = node->left;

    if (tree->last == node)
    {
      /***********************************************************************/
      /* node was last in tree, so replace it                                */
      /***********************************************************************/
      tree->last = replace_node;
    }
  }
  else
  {
    /*************************************************************************/
    /* node has both left and right-sons                                     */
    /*************************************************************************/
    if (node->r_height > node->l_height)
    {
      /***********************************************************************/
      /* right subtree is higher than left subtree                           */
      /***********************************************************************/
      if (node->right->left == NULL)
      {
        /*********************************************************************/
        /* can replace node with right-son (since it has no left-son)        */
        /*********************************************************************/
        replace_node = node->right;
        replace_node->left = node->left;
        replace_node->left->parent = replace_node;
        replace_node->l_height = node->l_height;
      }
      else
      {
        /*********************************************************************/
        /* swap with left-most descendent of right subtree                   */
        /*********************************************************************/
        bfd_avl3_swap_left_most(tree, node->right, node);
        replace_node = node->right;
      }
    }
    else
    {
      /***********************************************************************/
      /* left subtree is higher (or subtrees are of same height)             */
      /***********************************************************************/
      if (node->left->right == NULL)
      {
        /*********************************************************************/
        /* can replace node with left-son (since it has no right-son)        */
        /*********************************************************************/
        replace_node = node->left;
        replace_node->right = node->right;
        replace_node->right->parent = replace_node;
        replace_node->r_height = node->r_height;
      }
      else
      {
        /*********************************************************************/
        /* swap with right-most descendent of left subtree                   */
        /*********************************************************************/
        bfd_avl3_swap_right_most(tree, node->left, node);
        replace_node = node->left;
      }
    }
  }

  /***************************************************************************/
  /* save parent node of deleted node                                        */
  /***************************************************************************/
  parent_node = node->parent;

  /***************************************************************************/
  /* reset deleted node                                                      */
  /***************************************************************************/
  node->parent = NULL;
  node->right = NULL;
  node->left = NULL;
  node->r_height = -1;
  node->l_height = -1;

  if (replace_node != NULL)
  {
    /*************************************************************************/
    /* fix-up parent pointer of replacement node, and calculate new height   */
    /* of subtree                                                            */
    /*************************************************************************/
    replace_node->parent = parent_node;
    new_height = (unsigned short)
                 (1 + BFD_NBB_MAX(replace_node->l_height, replace_node->r_height));
  }
  else
  {
    /*************************************************************************/
    /* no replacement, so new height of subtree is zero                      */
    /*************************************************************************/
    new_height = 0;
  }

  if (parent_node != NULL)
  {
    /*************************************************************************/
    /* fixup parent node                                                     */
    /*************************************************************************/
    if (parent_node->right == node)
    {
      /***********************************************************************/
      /* node is right son of parent                                         */
      /***********************************************************************/
      parent_node->right = replace_node;
      parent_node->r_height = new_height;
    }
    else
    {
      /***********************************************************************/
      /* node is left son of parent                                          */
      /***********************************************************************/
      parent_node->left = replace_node;
      parent_node->l_height = new_height;
    }

    /*************************************************************************/
    /* now rebalance the tree (if necessary)                                 */
    /*************************************************************************/
    bfd_avl3_balance_tree(tree, parent_node);
  }
  else
  {
    /*************************************************************************/
    /* replacement node is now root of tree                                  */
    /*************************************************************************/
    tree->root = replace_node;
  }


  return;

} /* bfd_avl3_delete */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_find                                                  */
/*                                                                           */
/* Purpose:   Find the node in the AVL3 tree with the supplied key           */
/*                                                                           */
/* Returns:   A pointer to the node                                          */
/*            NULL if no node is found with the specified key                */
/*                                                                           */
/* Params:    IN     tree         - a pointer to the AVL3 tree               */
/*            IN     key          - a pointer to the key                     */
/*            IN     tree_info    - a pointer to the AVL3 tree info          */
/*                                                                           */
/* Operation: Search down the tree going left if the search key is less than */
/*            the node in the tree and right if the search key is greater.   */
/*            When we run out of tree to search through either we've found   */
/*            it or the node is not in the tree.                             */
/*                                                                           */
/**PROC-**********************************************************************/
void *bfd_avl3_find(AVL3_TREE *tree,
                        void *key,
                        const AVL3_TREE_INFO *tree_info)
{
  /***************************************************************************/
  /* find node with specified key                                            */
  /***************************************************************************/
  AVL3_NODE *node;
  int result;



  node = tree->root;

  while (node != NULL)
  {
    /*************************************************************************/
    /* compare key of current node with supplied key                         */
    /*************************************************************************/
    result = tree_info->compare(key,
                                (void *)((unsigned char *)node -
                                             tree_info->node_offset +
                                             tree_info->key_offset));

    if (result > 0)
    {
      /***********************************************************************/
      /* specified key is greater than key of this node, so look in right    */
      /* subtree                                                             */
      /***********************************************************************/
      node = node->right;
    }
    else if (result < 0)
    {
      /***********************************************************************/
      /* specified key is less than key of this node, so look in left        */
      /* subtree                                                             */
      /***********************************************************************/
      node = node->left;
    }
    else
    {
      /***********************************************************************/
      /* found the requested node                                            */
      /***********************************************************************/
      break;
    }
  }


  return((node != NULL) ?
               (void *)((unsigned char *)node - tree_info->node_offset) : NULL);

} /* bfd_avl3_find */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_first                                                 */
/*                                                                           */
/* Purpose:   Find the first entry in the AVL3 tree.                         */
/*                                                                           */
/* Returns:   A pointer to the first entry.  NULL if the tree is empty.      */
/*                                                                           */
/* Params:    IN     tree         - a pointer to the AVL3 tree               */
/*            IN     tree_info    - a pointer to the AVL3 tree info          */
/*                                                                           */
/**PROC-**********************************************************************/
void *bfd_avl3_first(AVL3_TREE *tree,
                         const AVL3_TREE_INFO *tree_info)
{
  /***************************************************************************/
  /* find first node in tree                                                 */
  /***************************************************************************/
  AVL3_NODE *node;



  if (tree->first != NULL)
  {
    node = tree->first;
  }
  else
  {
    node = NULL;
  }


  return((node != NULL) ?
               (void *)((unsigned char *)node - tree_info->node_offset) : NULL);

} /* bfd_avl3_first */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_last                                                  */
/*                                                                           */
/* Purpose:   Find the last entry in the AVL3 tree.                          */
/*                                                                           */
/* Returns:   A pointer to the last entry.  NULL if the tree is empty.       */
/*                                                                           */
/* Params:    IN     tree         - a pointer to the AVL3 tree               */
/*            IN     tree_info    - a pointer to the AVL3 tree info          */
/*                                                                           */
/**PROC-**********************************************************************/
void *bfd_avl3_last(AVL3_TREE *tree,
                        const AVL3_TREE_INFO *tree_info)
{
  /***************************************************************************/
  /* find last node in tree                                                  */
  /***************************************************************************/
  AVL3_NODE *node;



  if (tree->last != NULL)
  {
    node = tree->last;
  }
  else
  {
    node = NULL;
  }


  return((node != NULL) ?
               (void *)((unsigned char *)node - tree_info->node_offset) : NULL);

} /* bfd_avl3_last */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_next                                                  */
/*                                                                           */
/* Purpose:   Find next node in the AVL3 tree                                */
/*                                                                           */
/* Returns:   A pointer to the next node in the tree                         */
/*                                                                           */
/* Params:    IN     node         - a pointer to the current node in the     */
/*                                  tree                                     */
/*            IN     tree_info    - a pointer to the AVL3 tree info          */
/*                                                                           */
/* Operation: If the specified node has a right-son then return the left-    */
/*            most son of this.  Otherwise search back up until we find a    */
/*            node of which we are in the left sub-tree and return that.     */
/*                                                                           */
/**PROC-**********************************************************************/
void *bfd_avl3_next(AVL3_NODE *node,
                        const AVL3_TREE_INFO *tree_info)
{
  /***************************************************************************/
  /* find next node in tree                                                  */
  /***************************************************************************/


  BFD_NBB_ASSERT_NUM_NE(AVL3_IN_TREE(*node), 0);

  if (node->right != NULL)
  {
    /*************************************************************************/
    /* next node is left-most node in right subtree                          */
    /*************************************************************************/
    node = node->right;
    while (node->left != NULL)
    {
      /***********************************************************************/
      /* FLOW TRACING NOT REQUIRED    Reason: Tight loop.                    */
      /***********************************************************************/
      node = node->left;
    }
  }
  else
  {
    /*************************************************************************/
    /* no right-son, so find a node of which we are in the left subtree      */
    /*************************************************************************/

    while (node != NULL)
    {
      /***********************************************************************/
      /* FLOW TRACING NOT REQUIRED    Reason: Tight loop.                    */
      /***********************************************************************/
      if ((node->parent == NULL) ||
          (node->parent->left == node))
      {
        node = node->parent;
        break;
      }
      node = node->parent;
    }
  }


  return((node != NULL) ?
               (void *)((unsigned char *)node - tree_info->node_offset) : NULL);

} /* bfd_avl3_next */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_prev                                                  */
/*                                                                           */
/* Purpose:   Find previous node in the AVL3 tree                            */
/*                                                                           */
/* Returns:   A pointer to the previous node in the tree                     */
/*                                                                           */
/* Params:    IN     node         - a pointer to the current node in the     */
/*                                  tree                                     */
/*            IN     tree_info    - a pointer to the AVL3 tree info          */
/*                                                                           */
/* Operation: If we have a left-son then the previous node is the right-most */
/*            son of this.  Otherwise, look for a node of whom we are in the */
/*            left subtree and return that.                                  */
/*                                                                           */
/**PROC-**********************************************************************/
void *bfd_avl3_prev(AVL3_NODE *node,
                        const AVL3_TREE_INFO *tree_info)
{
  /***************************************************************************/
  /* find previous node in tree                                              */
  /***************************************************************************/


  BFD_NBB_ASSERT_NUM_NE(AVL3_IN_TREE(*node), 0);

  if (node->left != NULL)
  {
    /*************************************************************************/
    /* previous node is right-most node in left subtree                      */
    /*************************************************************************/
    node = node->left;
    while (node->right != NULL)
    {
      /***********************************************************************/
      /* FLOW TRACING NOT REQUIRED    Reason: Tight loop.                    */
      /***********************************************************************/
      node = node->right;
    }
  }
  else
  {
    /*************************************************************************/
    /* no left-son, so find a node of which we are in the right subtree      */
    /*************************************************************************/
    while (node != NULL)
    {
      /***********************************************************************/
      /* FLOW TRACING NOT REQUIRED    Reason: Tight loop.                    */
      /***********************************************************************/
      if ((node->parent == NULL) ||
          (node->parent->right == node))
      {
        node = node->parent;
        break;
      }
      node = node->parent;
    }
  }


  return((node != NULL) ?
               (void *)((unsigned char *)node - tree_info->node_offset) : NULL);

} /* bfd_avl3_prev */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_balance_tree                                          */
/*                                                                           */
/* Purpose:   Rebalance the tree starting at the supplied node and ending at */
/*            the root of the tree                                           */
/*                                                                           */
/* Returns:   Nothing                                                        */
/*                                                                           */
/* Params:    IN/OUT tree              - a pointer to the AVL3 tree          */
/*            IN/OUT node              - a pointer to the node to start      */
/*                                       balancing from                      */
/*                                                                           */
/**PROC-**********************************************************************/
void bfd_avl3_balance_tree(AVL3_TREE *tree,
                               AVL3_NODE *node)
{
  /***************************************************************************/
  /* balance the tree starting at the supplied node, and ending at the root  */
  /* of the tree                                                             */
  /***************************************************************************/

  while (node->parent != NULL)
  {
    /*************************************************************************/
    /* node has uneven balance, so may need to rebalance it                  */
    /*************************************************************************/

    if (node->parent->right == node)
    {
      /***********************************************************************/
      /* node is right-son of its parent                                     */
      /***********************************************************************/
      node = node->parent;
      bfd_avl3_rebalance(&node->right);

      /***********************************************************************/
      /* now update the right height of the parent                           */
      /***********************************************************************/
      node->r_height = (unsigned short)
                   (1 + BFD_NBB_MAX(node->right->r_height, node->right->l_height));
    }
    else
    {
      /***********************************************************************/
      /* node is left-son of its parent                                      */
      /***********************************************************************/
      node = node->parent;
      bfd_avl3_rebalance(&node->left);

      /***********************************************************************/
      /* now update the left height of the parent                            */
      /***********************************************************************/
      node->l_height = (unsigned short)
                     (1 + BFD_NBB_MAX(node->left->r_height, node->left->l_height));
    }
  }

  if (node->l_height != node->r_height)
  {
    /*************************************************************************/
    /* rebalance root node                                                   */
    /*************************************************************************/
    bfd_avl3_rebalance(&tree->root);
  }


  return;

} /* bfd_avl3_balance_tree */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_rebalance                                             */
/*                                                                           */
/* Purpose:   Rebalance a subtree of the AVL3 tree (if necessary)            */
/*                                                                           */
/* Returns:   Nothing                                                        */
/*                                                                           */
/* Params:    IN/OUT subtree           - a pointer to the subtree to         */
/*                                       rebalance                           */
/*                                                                           */
/**PROC-**********************************************************************/
void bfd_avl3_rebalance(AVL3_NODE **subtree)
{
  /***************************************************************************/
  /* Local data                                                              */
  /***************************************************************************/
  int moment;

  /***************************************************************************/
  /* rebalance a subtree of the AVL3 tree                                    */
  /***************************************************************************/

  /***************************************************************************/
  /* How unbalanced - don't want to recalculate                              */
  /***************************************************************************/
  moment = (*subtree)->r_height - (*subtree)->l_height;

  if (moment > 1)
  {
    /*************************************************************************/
    /* subtree is heavy on the right side                                    */
    /*************************************************************************/
    if ((*subtree)->right->l_height > (*subtree)->right->r_height)
    {
      /***********************************************************************/
      /* right subtree is heavier on left side, so must perform right        */
      /* rotation on this subtree to make it heavier on the right side       */
      /***********************************************************************/
      bfd_avl3_rotate_right(&(*subtree)->right);
    }

    /*************************************************************************/
    /* now rotate the subtree left                                           */
    /*************************************************************************/
    bfd_avl3_rotate_left(subtree);
  }
  else if (moment < -1)
  {
    /*************************************************************************/
    /* subtree is heavy on the left side                                     */
    /*************************************************************************/
    if ((*subtree)->left->r_height > (*subtree)->left->l_height)
    {
      /***********************************************************************/
      /* left subtree is heavier on right side, so must perform left         */
      /* rotation on this subtree to make it heavier on the left side        */
      /***********************************************************************/
      bfd_avl3_rotate_left(&(*subtree)->left);
    }

    /*************************************************************************/
    /* now rotate the subtree right                                          */
    /*************************************************************************/
    bfd_avl3_rotate_right(subtree);
  }


  return;

} /* bfd_avl3_rebalance */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_rotate_right                                          */
/*                                                                           */
/* Purpose:   Rotate a subtree of the AVL3 tree right                        */
/*                                                                           */
/* Returns:   Nothing                                                        */
/*                                                                           */
/* Params:    IN/OUT subtree           - a pointer to the subtree to rotate  */
/*                                                                           */
/**PROC-**********************************************************************/
void bfd_avl3_rotate_right(AVL3_NODE **subtree)
{
  /***************************************************************************/
  /* rotate subtree of AVL3 tree right                                       */
  /***************************************************************************/
  AVL3_NODE *left_son;


  left_son = (*subtree)->left;

  (*subtree)->left = left_son->right;
  if ((*subtree)->left != NULL)
  {
    (*subtree)->left->parent = (*subtree);
  }
  (*subtree)->l_height = left_son->r_height;

  left_son->parent = (*subtree)->parent;

  left_son->right = *subtree;
  left_son->right->parent = left_son;
  left_son->r_height = (unsigned short)
                     (1 + BFD_NBB_MAX((*subtree)->r_height, (*subtree)->l_height));

  *subtree = left_son;


  return;

} /* bfd_avl3_rotate_right */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_rotate_left                                           */
/*                                                                           */
/* Purpose:   Rotate a subtree of the AVL3 tree left                         */
/*                                                                           */
/* Returns:   Nothing                                                        */
/*                                                                           */
/* Params:    IN/OUT subtree           - a pointer to the subtree to rotate  */
/*                                                                           */
/**PROC-**********************************************************************/
void bfd_avl3_rotate_left(AVL3_NODE **subtree)
{
  /***************************************************************************/
  /* rotate a subtree of the AVL tree left                                   */
  /***************************************************************************/
  AVL3_NODE *right_son;


  right_son = (*subtree)->right;

  (*subtree)->right = right_son->left;
  if ((*subtree)->right != NULL)
  {
    (*subtree)->right->parent = (*subtree);
  }
  (*subtree)->r_height = right_son->l_height;

  right_son->parent = (*subtree)->parent;

  right_son->left = *subtree;
  right_son->left->parent = right_son;
  right_son->l_height = (unsigned short)
                     (1 + BFD_NBB_MAX((*subtree)->r_height, (*subtree)->l_height));

  *subtree = right_son;


  return;

} /* bfd_avl3_rotate_left */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_swap_right_most                                       */
/*                                                                           */
/* Purpose:   Swap node with right-most descendent of subtree                */
/*                                                                           */
/* Returns:   Nothing                                                        */
/*                                                                           */
/* Params:    IN     tree              - a pointer to the tree               */
/*            IN     subtree           - a pointer to the subtree            */
/*            IN     node              - a pointer to the node to swap       */
/*                                                                           */
/**PROC-**********************************************************************/
void bfd_avl3_swap_right_most(AVL3_TREE *tree,
                                  AVL3_NODE *subtree,
                                  AVL3_NODE *node)
{
  /***************************************************************************/
  /* swap node with right-most descendent of specified subtree               */
  /***************************************************************************/
  AVL3_NODE *swap_node;
  AVL3_NODE *swap_parent;
  AVL3_NODE *swap_left;


  BFD_NBB_ASSERT_PTR_NE(node->right, NULL);
  BFD_NBB_ASSERT_PTR_NE(node->left, NULL);

  /***************************************************************************/
  /* find right-most descendent of subtree                                   */
  /***************************************************************************/
  swap_node = subtree;
  while (swap_node->right != NULL)
  {
    /*************************************************************************/
    /* FLOW TRACING NOT REQUIRED    Reason: Tight loop.                      */
    /*************************************************************************/
    swap_node = swap_node->right;
  }

  BFD_NBB_ASSERT_NUM_EQ(swap_node->r_height, 0);
  BFD_NBB_ASSERT_NUM_LE(swap_node->l_height, 1);

  /***************************************************************************/
  /* save parent and left-son of right-most descendent                       */
  /***************************************************************************/
  swap_parent = swap_node->parent;
  swap_left = swap_node->left;

  /***************************************************************************/
  /* move swap node to its new position                                      */
  /***************************************************************************/
  swap_node->parent = node->parent;
  swap_node->right = node->right;
  swap_node->left = node->left;
  swap_node->r_height = node->r_height;
  swap_node->l_height = node->l_height;
  swap_node->right->parent = swap_node;
  swap_node->left->parent = swap_node;
  if (node->parent == NULL)
  {
    /*************************************************************************/
    /* node is at root of tree                                               */
    /*************************************************************************/
    tree->root = swap_node;
  }
  else if (node->parent->right == node)
  {
    /*************************************************************************/
    /* node is right-son of parent                                           */
    /*************************************************************************/
    swap_node->parent->right = swap_node;
  }
  else
  {
    /*************************************************************************/
    /* node is left-son of parent                                            */
    /*************************************************************************/
    swap_node->parent->left = swap_node;
  }

  /***************************************************************************/
  /* move node to its new position                                           */
  /***************************************************************************/
  node->parent = swap_parent;
  node->right = NULL;
  node->left = swap_left;
  if (node->left != NULL)
  {
    node->left->parent = node;
    node->l_height = 1;
  }
  else
  {
    node->l_height = 0;
  }
  node->r_height = 0;
  node->parent->right = node;


  return;

} /* bfd_avl3_swap_right_most */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_swap_left_most                                        */
/*                                                                           */
/* Purpose:   Swap node with left-most descendent of subtree                 */
/*                                                                           */
/* Returns:   Nothing                                                        */
/*                                                                           */
/* Params:    IN     tree              - a pointer to the tree               */
/*            IN     subtree           - a pointer to the subtree            */
/*            IN     node              - a pointer to the node to swap       */
/*                                                                           */
/**PROC-**********************************************************************/
void bfd_avl3_swap_left_most(AVL3_TREE *tree,
                                 AVL3_NODE *subtree,
                                 AVL3_NODE *node)
{
  /***************************************************************************/
  /* swap node with left-most descendent of specified subtree                */
  /***************************************************************************/
  AVL3_NODE *swap_node;
  AVL3_NODE *swap_parent;
  AVL3_NODE *swap_right;


  BFD_NBB_ASSERT_PTR_NE(node->right, NULL);
  BFD_NBB_ASSERT_PTR_NE(node->left, NULL);

  /***************************************************************************/
  /* find left-most descendent of subtree                                    */
  /***************************************************************************/
  swap_node = subtree;
  while (swap_node->left != NULL)
  {
    /*************************************************************************/
    /* FLOW TRACING NOT REQUIRED    Reason: Tight loop.                      */
    /*************************************************************************/
    swap_node = swap_node->left;
  }

  BFD_NBB_ASSERT_NUM_EQ(swap_node->l_height, 0);
  BFD_NBB_ASSERT_NUM_LE(swap_node->r_height, 1);

  /***************************************************************************/
  /* save parent and right-son of left-most descendent                       */
  /***************************************************************************/
  swap_parent = swap_node->parent;
  swap_right = swap_node->right;

  /***************************************************************************/
  /* move swap node to its new position                                      */
  /***************************************************************************/
  swap_node->parent = node->parent;
  swap_node->right = node->right;
  swap_node->left = node->left;
  swap_node->r_height = node->r_height;
  swap_node->l_height = node->l_height;
  swap_node->right->parent = swap_node;
  swap_node->left->parent = swap_node;
  if (node->parent == NULL)
  {
    /*************************************************************************/
    /* node is at root of tree                                               */
    /*************************************************************************/
    tree->root = swap_node;
  }
  else if (node->parent->right == node)
  {
    /*************************************************************************/
    /* node is right-son of parent                                           */
    /*************************************************************************/
    swap_node->parent->right = swap_node;
  }
  else
  {
    /*************************************************************************/
    /* node is left-son of parent                                            */
    /*************************************************************************/
    swap_node->parent->left = swap_node;
  }

  /***************************************************************************/
  /* move node to its new position                                           */
  /***************************************************************************/
  node->parent = swap_parent;
  node->right = swap_right;
  node->left = NULL;
  if (node->right != NULL)
  {
    node->right->parent = node;
    node->r_height = 1;
  }
  else
  {
    node->r_height = 0;
  }
  node->l_height = 0;
  node->parent->left = node;


  return;

} /* bfd_avl3_swap_left_most */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_find_or_find_next                                     */
/*                                                                           */
/* Purpose:   Find the successor node to the supplied key in the AVL3 tree   */
/*                                                                           */
/* Returns:   A pointer to the node                                          */
/*            NULL if no successor node to the supplied key is found         */
/*                                                                           */
/* Params:    IN     tree         - a pointer to the AVL3 tree               */
/*            IN     key          - a pointer to the key                     */
/*            IN     not_equal    - TRUE return a node strictly > key FALSE  */
/*                                  return a node >= key                     */
/*            IN     tree_info    - a pointer to the AVL3 tree info          */
/*                                                                           */
/**PROC-**********************************************************************/
void *bfd_avl3_find_or_find_next(AVL3_TREE *tree,
                                     void *key,
                                     int not_equal,
                                     const AVL3_TREE_INFO *tree_info)
{
  /***************************************************************************/
  /* Local Variables                                                         */
  /***************************************************************************/
  AVL3_NODE *node;
  void *found_node = NULL;
  int result;


  node = tree->root;

  if (node != NULL)
  {
    /*************************************************************************/
    /* There is something in the tree                                        */
    /*************************************************************************/
    for (;;)
    {
      /***********************************************************************/
      /* FLOW TRACING NOT REQUIRED           Reason: Performance             */
      /*                                                                     */
      /* compare key of current node with supplied key                       */
      /***********************************************************************/
      result = tree_info->compare(key,
                                  (void *)((unsigned char *)node -
                                               tree_info->node_offset +
                                               tree_info->key_offset));

      if (result > 0)
      {
        /*********************************************************************/
        /* specified key is greater than key of this node, so look in right  */
        /* subtree                                                           */
        /*********************************************************************/
        if (node->right == NULL)
        {
          /*******************************************************************/
          /* We've found the previous node - so we now need to find the      */
          /* successor to this one.                                          */
          /*******************************************************************/
          found_node = bfd_avl3_next(node, tree_info);
          break;
        }
        node = node->right;
      }
      else if (result < 0)
      {
        /*********************************************************************/
        /* specified key is less than key of this node, so look in left      */
        /* subtree                                                           */
        /*********************************************************************/

        if (node->left == NULL)
        {
           /******************************************************************/
           /* We've found the next node so store and drop out                */
           /******************************************************************/
           found_node = (void *)
                                   ((unsigned char *)node - tree_info->node_offset);
           break;
        }
        node = node->left;
      }
      else
      {
        /*********************************************************************/
        /* found the requested node                                          */
        /*********************************************************************/

        if (TRUE == not_equal)
        {
          /*******************************************************************/
          /* need to find the successor node to this node                    */
          /*******************************************************************/
          found_node = bfd_avl3_next(node, tree_info);
        }
        else
        {
          found_node = (void *)((unsigned char *)node - tree_info->node_offset);
        }
        break;
      }
    }
  }


  return(found_node);

} /* bfd_avl3_find_or_find_next */

/**PROC+**********************************************************************/
/* Name:      bfd_avl3_verify_tree                                           */
/*                                                                           */
/* Purpose:   To verify that an AVL3 tree is correctly sorted.               */
/*                                                                           */
/* Returns:   Nothing.                                                       */
/*                                                                           */
/* Params:    IN     tree         - a pointer to the AVL3 tree               */
/*            IN     tree_info    - a pointer to the AVL3 tree info          */
/*                                                                           */
/**PROC-**********************************************************************/
void bfd_avl3_verify_tree(AVL3_TREE *tree,
                              const AVL3_TREE_INFO *tree_info)
{
  /***************************************************************************/
  /* Local Variables                                                         */
  /***************************************************************************/
  AVL3_NODE *node = NULL;
  AVL3_NODE *tmpnode = NULL;
  int result;


  /***************************************************************************/
  /* Start at the nominal first entry in the tree.  We check later that      */
  /* this really is the first.                                               */
  /***************************************************************************/
  node = tree->first;

  /***************************************************************************/
  /* Step up through the first node's family tree asserting that each older  */
  /* generation does not have a left pointer, or that left pointer is us.    */
  /***************************************************************************/
  while (node != NULL)
  {
    /*************************************************************************/
    /* FLOW TRACING NOT REQUIRED Reason: Performance                         */
    /*************************************************************************/
    BFD_NBB_ASSERT_OR(node->left == NULL, node->left == tmpnode);

    /*************************************************************************/
    /* Ensure the tree root is planted in Eden (it has no parents).          */
    /*************************************************************************/
    if (node == tree->root)
    {
      /***********************************************************************/
      /* FLOW TRACING NOT REQUIRED Reason: Performance                       */
      /***********************************************************************/
      BFD_NBB_ASSERT_PTR_EQ(node->parent, NULL);
    }
    tmpnode = node;
    node = node->parent;
  }

  /***************************************************************************/
  /* Now we've ascertained that the first and root are correct, check the    */
  /* relative ordering of everything else in the tree.                       */
  /***************************************************************************/
  node = tree->first;

  while (node != NULL)
  {
    /*************************************************************************/
    /* FLOW TRACING NOT REQUIRED Reason: Performance                         */
    /*************************************************************************/
    tmpnode = (AVL3_NODE *)AVL3_NEXT(*node, *tree_info);

    /*************************************************************************/
    /* Get out if we have reach the end of the line.                         */
    /*************************************************************************/
    if (tmpnode == NULL)
    {
      /***********************************************************************/
      /* FLOW TRACING NOT REQUIRED Reason: Performance                       */
      /***********************************************************************/
      break;
    }

    /*************************************************************************/
    /* Check that node and its next node are ordered correctly.  Check the   */
    /* ordering in both directions to ensure there are no infinite loops.    */
    /*************************************************************************/
    tmpnode = (AVL3_NODE *)(((unsigned char *)tmpnode + tree_info->node_offset));
    result = tree_info->compare((void *)((unsigned char *)node -
                                             tree_info->node_offset +
                                             tree_info->key_offset),
                                (void *)((unsigned char *)tmpnode -
                                             tree_info->node_offset +
                                             tree_info->key_offset));
    BFD_NBB_ASSERT_NUM_LT(result, 0);

    result = tree_info->compare((void *)((unsigned char *)tmpnode -
                                             tree_info->node_offset +
                                             tree_info->key_offset),
                                (void *)((unsigned char *)node -
                                             tree_info->node_offset +
                                             tree_info->key_offset));
    BFD_NBB_ASSERT_NUM_GT(result, 0);
    BFD_NBB_REF_DEBUG_VARIABLE(result);

    /*************************************************************************/
    /* Also check the parentage.                                             */
    /*************************************************************************/
    BFD_NBB_ASSERT_OR(node->parent != NULL, node == tree->root);
    node = tmpnode;
  }

  /***************************************************************************/
  /* Finally, now we have completed the walk of the (potentially empty)      */
  /* tree, check that the last pointer is set correctly.                     */
  /***************************************************************************/
  BFD_NBB_ASSERT_PTR_EQ(node, tree->last);

  /***************************************************************************/
  /* There is no need to walk through last's parentage to check them since   */
  /* we have already checked the correct ordering of all members of the tree */
  /* while we were walking.  This step is necessary for the first since it   */
  /* it the foundation upon which we base our tree walk to check all the     */
  /* relative orderings.                                                     */
  /***************************************************************************/


  return;

} /* bfd_avl3_verify_tree */
