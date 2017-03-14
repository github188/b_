/***********************************************************************************

 * 文 件 名   : bfd_ntllist.h
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年12月15日
 * 版 本 号   : 
 * 文件描述   : bfd_ntllist.c 的头文件
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#ifndef __BFD_NTLLIST_H__
#define __BFD_NTLLIST_H__


#ifdef __cplusplus
#if __cplusplus
{
extern "C"
#endif
#endif /* __cplusplus */

#include "nbase_stub.h"

/**STRUCT-********************************************************************/

/**STRUCT+********************************************************************/
/* Structure: NBB_LQE                                                        */
/*                                                                           */
/* Description: List/Queue element.                                          */
/*****************************************************************************/

typedef struct nbb_lqe
{
  /***************************************************************************/
  /* Fields for use only within the N-BASE.                                  */
  /***************************************************************************/

  /***************************************************************************/
  /* Pointer to next LQE.                                                    */
  /***************************************************************************/
  struct nbb_lqe *next;

  /***************************************************************************/
  /* Pointer to previous LQE.                                                */
  /***************************************************************************/
  struct nbb_lqe *prev;

  /***************************************************************************/
  /* Self pointer which will point to the beginning of the structure which   */
  /* contains this LQE (to allow a control block to be in multiple lists.    */
  /***************************************************************************/
  NBB_VOID *self;

} NBB_LQE;

/**STRUCT-********************************************************************/

/**STRUCT+********************************************************************/
/* Structure: NBB_QE                                                         */
/*                                                                           */
/* Description: Queue element.                                               */
/*****************************************************************************/

typedef struct nbb_qe
{
  /***************************************************************************/
  /* Fields for use only within the N-BASE.                                  */
  /***************************************************************************/

  /***************************************************************************/
  /* Pointer to next queue element.  This structure does not have a self     */
  /* pointer so must be the first field in a control block.                  */
  /***************************************************************************/
  struct nbb_qe *next;

} NBB_QE;

/**STRUCT-********************************************************************/

/*****************************************************************************/
/* L3QE lists provide equivalent functionality to LLQE lists, with a lower   */
/* occupancy for the list root, but require the caller to supply an          */
/* additional parameter to some of the macros.                               */
/*                                                                           */
/* LLQE structures and macros are deprecated, but are retained for           */
/* back-compatibility.                                                       */
/*****************************************************************************/

/**STRUCT+********************************************************************/
/* Structure: NBB_L3QE                                                       */
/*                                                                           */
/* Description: Lite lite list element.                                      */
/*                                                                           */
/*****************************************************************************/

typedef struct nbb_l3qe
{
  /***************************************************************************/
  /* Pointer to next L3QE.                                                   */
  /***************************************************************************/
  struct nbb_l3qe *next;

  /***************************************************************************/
  /* Pointer to previous L3QE.                                               */
  /***************************************************************************/
  struct nbb_l3qe *prev;

} NBB_L3QE;

/**STRUCT-********************************************************************/

/**STRUCT+********************************************************************/
/* Structure: NBB_L3QE_ROOT                                                  */
/*                                                                           */
/* Description: Lite lite list root.                                         */
/*                                                                           */
/*****************************************************************************/

typedef struct nbb_l3qe_root
{
  /***************************************************************************/
  /* Root L3QE.                                                              */
  /***************************************************************************/
  NBB_L3QE l3qe;

} NBB_L3QE_ROOT;

/**STRUCT-********************************************************************/

/**STRUCT+********************************************************************/
/* Structure: NBB_LLQE                                                       */
/*                                                                           */
/* Description: Lite list element (deprecated).                              */
/*                                                                           */
/*****************************************************************************/

typedef struct nbb_l3qe NBB_LLQE;

/**STRUCT-********************************************************************/

/**STRUCT+********************************************************************/
/* Structure: NBB_LLQE_ROOT                                                  */
/*                                                                           */
/* Description: Lite list root (deprecated).                                 */
/*                                                                           */
/*****************************************************************************/

typedef struct nbb_llqe_root
{
  /***************************************************************************/
  /* L3QE root.                                                              */
  /***************************************************************************/
  NBB_L3QE_ROOT llqe;

  /***************************************************************************/
  /* Offset of NBB_LLQE structure in elements stored in this list.           */
  /***************************************************************************/
  NBB_BUF_SIZE llqe_offset;

} NBB_LLQE_ROOT;

/**STRUCT-********************************************************************/

/**STRUCT+********************************************************************/
/* Structure: NBB_Q_ROOT                                                     */
/*                                                                           */
/* Description: Queue root.                                                  */
/*****************************************************************************/

typedef struct nbb_q_root
{
  /***************************************************************************/
  /* Fields for use only within the N-BASE.                                  */
  /***************************************************************************/

  /***************************************************************************/
  /* Pointers to the first and last entries in a queue.                      */
  /***************************************************************************/
  struct nbb_qe *first;
  struct nbb_qe *last;
} NBB_Q_ROOT;

/*****************************************************************************/
/* Queue Management                                                          */
/*****************************************************************************/
#define NBB_INIT_Q_ROOT(R)                                                 \
      (R).first = NULL;                                                    \
      (R).last = NULL

#define NBB_ADD_TO_Q_HEAD(QR, QE)                                          \
      ((NBB_QE *)(QE))->next = (QR).first;                                 \
      (QR).first = (NBB_QE *)(QE);                                         \
      if ((QR).last == NULL)                                               \
      {                                                                    \
        (QR).last = (NBB_QE *)(QE);                                        \
      }

#define NBB_ADD_TO_Q_TAIL(QR, QE)                                          \
      ((NBB_QE *)(QE))->next = NULL;                                       \
      if ((QR).last != NULL)                                               \
      {                                                                    \
        (QR).last->next = (NBB_QE *)(QE);                                  \
      }                                                                    \
      else                                                                 \
      {                                                                    \
        (QR).first = (NBB_QE *)(QE);                                       \
      }                                                                    \
      (QR).last = (NBB_QE *)(QE)

#define NBB_ADD_TO_Q_AFTER(QR, QE_PREVIOUS, QE_NEW)                        \
      ((NBB_QE *)(QE_NEW))->next = ((NBB_QE *)(QE_PREVIOUS))->next;        \
      ((NBB_QE *)(QE_PREVIOUS))->next = ((NBB_QE *)(QE_NEW));              \
      if ((QR).last == ((NBB_QE *)(QE_PREVIOUS)))                          \
      {                                                                    \
        (QR).last = (NBB_QE *)(QE_NEW);                                    \
      }

#define NBB_REMOVE_NEXT_FROM_Q(QR, QE)                                     \
      BFD_NBB_ASSERT_PTR_NE(((NBB_QE *)(QE))->next, NULL);                     \
      if ((QR).last == ((NBB_QE *)(QE))->next)                             \
      {                                                                    \
        (QR).last = (NBB_QE *)(QE);                                        \
      }                                                                    \
      ((NBB_QE *)(QE))->next = ((NBB_QE *)(QE))->next->next

#define NBB_GET_Q_HEAD(QR)      nbb_get_q_head(&QR  NBB_CCXT)
#define NBB_Q_HEAD(QR)          ((NBB_VOID *)(QR).first)
#define NBB_Q_NEXT(QE)          ((NBB_VOID *)((NBB_QE *)(QE))->next)

/*****************************************************************************/
/* List Management                                                           */
/*****************************************************************************/
/* 初始化root节点 */
#define NBB_INIT_ROOT(R)        (R).self = NULL;               \
                                (R).next = &(R);               \
                                (R).prev = &(R)

/* 初始化普通节点，S是节点E挂载的结构体首地址 */
#define NBB_INIT_LQE(E, S)      (E).self = (S);                \
                                (E).next = NULL;               \
                                (E).prev = NULL

#define NBB_LIST_ROOT(R)        ((R).self == NULL)
#define NBB_EMPTY_LIST(R)       ((R).next == &(R))
#define NBB_IN_LIST(E)          ((E).next != NULL)
#define NBB_NEXT_IN_LIST(E)     (NBB_VOID *)((E).next->self)
#define NBB_PREV_IN_LIST(E)     (NBB_VOID *)((E).prev->self)

/* 在循环链表中，将节点E插入到节点P后面 */
#define NBB_INSERT_AFTER(P, E)  BFD_NBB_ASSERT_PTR_EQ((E).next, NULL);         \
                                BFD_NBB_ASSERT_PTR_EQ((E).prev, NULL);         \
                                BFD_NBB_ASSERT_PTR_NE((P).prev, NULL);         \
                                BFD_NBB_ASSERT_PTR_NE((P).next, NULL);         \
                                (E).next = (P).next;                       \
                                (E).prev = &(P);                           \
                                (E).next->prev = &(E);                     \
                                (E).prev->next = &(E)

/* 在循环链表中，将节点E插入到节点N前面 */
#define NBB_INSERT_BEFORE(N, E) BFD_NBB_ASSERT_PTR_EQ((E).next, NULL);         \
                                BFD_NBB_ASSERT_PTR_EQ((E).prev, NULL);         \
                                BFD_NBB_ASSERT_PTR_NE((N).prev, NULL);         \
                                BFD_NBB_ASSERT_PTR_NE((N).next, NULL);         \
                                (E).prev = (N).prev;                       \
                                (E).next = &(N);                           \
                                (E).next->prev = &(E);                     \
                                (E).prev->next = &(E)

/* 将循环链表R插入到循环链表P的后面，root节点R被抛弃，后续请做资源回收处理 */
#define NBB_INSERT_LIST_AFTER(P, R)                                        \
                                BFD_NBB_ASSERT_TRUE(NBB_LIST_ROOT(R));         \
                                if (!NBB_EMPTY_LIST(R))                    \
                                {                                          \
                                  BFD_NBB_ASSERT_PTR_NE((P).prev, NULL);       \
                                  BFD_NBB_ASSERT_PTR_NE((P).next, NULL);       \
                                  (P).next->prev = (R).prev;               \
                                  (R).prev->next = (P).next;               \
                                  (P).next = (R).next;                     \
                                  (R).next->prev = &(P);                   \
                                }                                          \
                                NBB_INIT_ROOT(R)

/* 将循环链表R插入到循环链表P的前面，root节点R被抛弃，后续请做资源回收处理 */
#define NBB_INSERT_LIST_BEFORE(N, R)                                       \
                                BFD_NBB_ASSERT_TRUE(NBB_LIST_ROOT(R));         \
                                if (!NBB_EMPTY_LIST(R))                    \
                                {                                          \
                                  BFD_NBB_ASSERT_PTR_NE((N).prev, NULL);       \
                                  BFD_NBB_ASSERT_PTR_NE((N).next, NULL);       \
                                  (N).prev->next = (R).next;               \
                                  (R).next->prev = (N).prev;               \
                                  (N).prev = (R).prev;                     \
                                  (R).prev->next = &(N);                   \
                                }                                          \
                                NBB_INIT_ROOT(R)

/* 从循环链表上把节点E移除 */
#define NBB_REMOVE_FROM_LIST(E) BFD_NBB_ASSERT_PTR_NE((E).prev, NULL);         \
                                BFD_NBB_ASSERT_PTR_NE((E).next, NULL);         \
                                (E).next->prev = (E).prev;                 \
                                (E).prev->next = (E).next;                 \
                                (E).next = NULL;                           \
                                (E).prev = NULL

/*****************************************************************************/
/* L3QE List Management.                                                     */
/*                                                                           */
/* L3QE lists provide equivalent functionality to LLQE lists, with a lower   */
/* occupancy for the list root, but require the caller to supply an          */
/* additional parameter to some of the macros.                               */
/*                                                                           */
/* LLQE structures and macros are deprecated, but are retained for           */
/* back-compatibility.                                                       */
/*****************************************************************************/
#ifdef NBB_DEBUG
#define NBB_L3QE_INIT_ROOT(R, L3QE_OFFSET)                                    \
              (R).l3qe.next = &((R).l3qe);                                    \
              (R).l3qe.prev = &((R).l3qe);                                    \
              NBB_TRC_DETAIL((NBB_FORMAT "Init L3QE root %p with offset %lu", \
                              (&(R)),                                         \
                              (L3QE_OFFSET)))
#else
#define NBB_L3QE_INIT_ROOT(R, L3QE_OFFSET)                                    \
              (R).l3qe.next = (NBB_L3QE *)&(R);                               \
              (R).l3qe.prev = (NBB_L3QE *)&(R)
#endif

#define NBB_L3QE_INIT_LQE(E)     (E).next = NULL;                             \
                                 (E).prev = NULL

#define NBB_L3QE_EMPTY_LIST(R)   (((NBB_L3QE *)&(R))->next == (NBB_L3QE *)&(R))

#define NBB_L3QE_IN_LIST(E)      (((NBB_L3QE *)&(E))->next != NULL)

/*****************************************************************************/
/* Note that if the next / prev element is the root, this macro returns      */
/* NULL.  Otherwise it returns a pointer to the next / prev NBB_L3QE         */
/* element.                                                                  */
/*****************************************************************************/
#define NBB_L3QE_NEXT_IN_LIST(R, E, L3QE_OFFSET)                              \
       nbb_l3qe_next_in_list(&(R), (NBB_L3QE *)(&(E)), (L3QE_OFFSET)  NBB_CCXT)

#define NBB_L3QE_PREV_IN_LIST(R, E, L3QE_OFFSET)                              \
       nbb_l3qe_prev_in_list(&(R), (NBB_L3QE *)(&(E)), (L3QE_OFFSET)  NBB_CCXT)

/*****************************************************************************/
/* These macros have to cope with the fact that P or N may be the root       */
/* element, in which case they must be cast to an NBB_L3QE element to access */
/* the next and prev fields.                                                 */
/*****************************************************************************/
#define NBB_L3QE_INSERT_AFTER(P, E)                                           \
                          BFD_NBB_ASSERT_PTR_EQ((E).next, NULL);                  \
                          BFD_NBB_ASSERT_PTR_EQ((E).prev, NULL);                  \
                          BFD_NBB_ASSERT_PTR_NE(((NBB_L3QE *)(&(P)))->prev, NULL);\
                          BFD_NBB_ASSERT_PTR_NE(((NBB_L3QE *)(&(P)))->next, NULL);\
                          (E).next = ((NBB_L3QE *)(&(P)))->next;              \
                          (E).prev = (NBB_L3QE *)(&(P));                      \
                          (E).next->prev = &(E);                              \
                          (E).prev->next = &(E)

#define NBB_L3QE_INSERT_BEFORE(N, E)                                          \
                          BFD_NBB_ASSERT_PTR_EQ((E).next, NULL);                  \
                          BFD_NBB_ASSERT_PTR_EQ((E).prev, NULL);                  \
                          BFD_NBB_ASSERT_PTR_NE(((NBB_L3QE *)(&(N)))->prev, NULL);\
                          BFD_NBB_ASSERT_PTR_NE(((NBB_L3QE *)(&(N)))->next, NULL);\
                          (E).prev = ((NBB_L3QE *)(&(N)))->prev;              \
                          (E).next = (NBB_L3QE *)(&(N));                      \
                          (E).next->prev = &(E);                              \
                          (E).prev->next = &(E)

#define NBB_L3QE_INSERT_LIST_AFTER(P, R)                                      \
                      if (!NBB_L3QE_EMPTY_LIST(R))                            \
                      {                                                       \
                        BFD_NBB_ASSERT_PTR_NE(((NBB_L3QE *)(&(P)))->next, NULL);  \
                        BFD_NBB_ASSERT_PTR_NE(((NBB_L3QE *)(&(P)))->prev, NULL);  \
                        ((NBB_L3QE *)(&(P)))->next->prev = (R).l3qe.prev;     \
                        (R).l3qe.prev->next = ((NBB_L3QE *)(&(P)))->next;     \
                        ((NBB_L3QE *)(&(P)))->next = (R).l3qe.next;           \
                        (R).l3qe.next->prev = ((NBB_L3QE *)(&(P)));           \
                        (R).l3qe.next = &((R).l3qe);                          \
                        (R).l3qe.prev = &((R).l3qe);                          \
                      }

#define NBB_L3QE_INSERT_LIST_BEFORE(N, R)                                     \
                      if (!NBB_L3QE_EMPTY_LIST(R))                            \
                      {                                                       \
                        BFD_NBB_ASSERT_PTR_NE(((NBB_L3QE *)(&(N)))->next, NULL);  \
                        BFD_NBB_ASSERT_PTR_NE(((NBB_L3QE *)(&(N)))->prev, NULL);  \
                        ((NBB_L3QE *)(&(N)))->prev->next = (R).l3qe.next;     \
                        (R).l3qe.next->prev = ((NBB_L3QE *)(&(N)))->prev;     \
                        ((NBB_L3QE *)(&(N)))->prev = (R).l3qe.prev;           \
                        (R).l3qe.prev->next = ((NBB_L3QE *)(&(N)));           \
                        (R).l3qe.next = &((R).l3qe);                          \
                        (R).l3qe.prev = &((R).l3qe);                          \
                      }

#define NBB_L3QE_REMOVE_FROM_LIST(E)  NBB_REMOVE_FROM_LIST((E))

/*****************************************************************************/
/* Lite List Management (deprecated).                                        */
/*****************************************************************************/
#define NBB_L_INIT_ROOT(R, O)      NBB_L3QE_INIT_ROOT((R).llqe, (O));         \
                                   (R).llqe_offset = O

#define NBB_L_INIT_LQE(E)          NBB_L3QE_INIT_LQE((E))

#define NBB_L_EMPTY_LIST(R)        NBB_L3QE_EMPTY_LIST((R).llqe)

#define NBB_L_IN_LIST(E)           NBB_L3QE_IN_LIST((E))

#define NBB_L_NEXT_IN_LIST(R, E)   NBB_L3QE_NEXT_IN_LIST((R).llqe,            \
                                                         (E),                 \
                                                         (R).llqe_offset)

#define NBB_L_PREV_IN_LIST(R, E)   NBB_L3QE_PREV_IN_LIST((R).llqe,            \
                                                         (E),                 \
                                                         (R).llqe_offset)

#define NBB_L_INSERT_AFTER(P, E)   NBB_L3QE_INSERT_AFTER((P), (E))

#define NBB_L_INSERT_BEFORE(N, E)  NBB_L3QE_INSERT_BEFORE((N), (E))

#define NBB_L_INSERT_LIST_AFTER(P, R)                                         \
                                   NBB_L3QE_INSERT_LIST_AFTER((P), (R).llqe)

#define NBB_L_INSERT_LIST_BEFORE(N, R)                                        \
                                   NBB_L3QE_INSERT_LIST_BEFORE((N), (R).llqe)

#define NBB_L_REMOVE_FROM_LIST(E)  NBB_L3QE_REMOVE_FROM_LIST((E))


extern NBB_VOID *nbb_get_q_head(NBB_Q_ROOT *root  NBB_CCXT_T NBB_CXT);
extern NBB_VOID *nbb_l3qe_next_in_list(NBB_L3QE_ROOT *root,
                                         NBB_L3QE *element,
                                         NBB_BUF_SIZE offset
                                         NBB_CCXT_T NBB_CXT);
extern NBB_VOID *nbb_l3qe_prev_in_list(NBB_L3QE_ROOT *root,
                                         NBB_L3QE *element,
                                         NBB_BUF_SIZE offset
                                         NBB_CCXT_T NBB_CXT);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BFD_NTLLIST_H__ */
