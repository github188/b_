/***********************************************************************************

 * 文 件 名   : spm_bfd.h
 * 负 责 人   : 蒋博,jiangbo
 * 创建日期   : 2014年11月28日
 * 版 本 号   : 
 * 文件描述   : BFD头文件
 * 版权说明   : Copyright (C) 2000-2014   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#ifndef SPM_BFD_INCLUDED
#define SPM_BFD_INCLUDED

#include "bmuInclude.h"



/***************************************************************************/
/* BFD相关数据类型定义                                                     */
/***************************************************************************/
typedef NBB_ULONG*  BFD_PUL_TREE_BASE;
typedef NBB_ULONG*  BFD_PUL_FWD_TREE_BASE;
typedef NBB_BYTE*   BFD_PUC_SYN_ID_INFO;
typedef NBB_BYTE*   BFD_PUC_ALARM_INFO;

typedef NBB_BYTE* (*SPM_BFD_SLOT_TRAN_GET_DATA)(NBB_ULONG *);
typedef NBB_INT (*SPM_BFD_SLOT_TRAN_SET_DATA)(NBB_VOID *, NBB_ULONG, NBB_USHORT);
typedef NBB_INT (*SPM_BFD_SLOT_TRAN_RELEASE)(NBB_BYTE *);


/***************************************************************************/
/* BFD错误码定义                                                           */
/***************************************************************************/
#define BFD_ERROR_BASE                      (-50000)
#define BFD_ERROR_PAMT_NULL                 (BFD_ERROR_BASE - 1)    /* 参数为空 */
#define BFD_ERROR_PAMT_OVER                 (BFD_ERROR_BASE - 2)    /* 参数为越界 */
#define BFD_ERROR_MTL_ALLOC                 (BFD_ERROR_BASE - 3)    /* MTL分配内存失败 */
#define BFD_ERROR_MTL_SEND                  (BFD_ERROR_BASE - 4)    /* MTL发送失败 */
#define BFD_ERROR_LACK_LAYER                (BFD_ERROR_BASE - 5)    /* 盘间通信包中间缺少一层 */
#define BFD_ERROR_DO_NOT_HAVE_MAIN_BOARD    (BFD_ERROR_BASE - 6)    /* 主控不在位 */
#define BFD_ERROR_NOT_EXIST                 (BFD_ERROR_BASE - 7)    /* 查找的项不存在 */
#define BFD_ERROR_NBB_ALLOC                 (BFD_ERROR_BASE - 8)    /* nbase分配内存失败 */
#define BFD_ERROR_ADD_LIMITED_TREE          (BFD_ERROR_BASE - 9)    /* 添加越限配置存储二叉树失败 */
#define BFD_ERROR_LIMITED_TREE_NOT_FOUND    (BFD_ERROR_BASE - 10)   /* 越限配置存储二叉树不存在查找节点 */


/***************************************************************************/
/* BEP部署定义                                                             */
/***************************************************************************/
#ifdef BEP_ENABLE
#define BFD_SYS_CALLOC(SIZE, TYPE)      sys_calloc((SIZE), 1)
#define BFD_SYS_FREE(MEM, SIZE)         sys_free(MEM)
#else
#define BFD_SYS_CALLOC(SIZE, TYPE)          OS_ALLOC((SIZE), (TYPE))
#define BFD_SYS_FREE(MEM, SIZE)             OS_FREE((MEM), (SIZE))
#endif /* BEP_ENABLE */

#define BFD_MAX_SESNUM    (2047)   /* 每个盘子支持的BFD会话数目 */
#define BFD_MAX_DMA_NUM     (BFD_MAX_SESNUM + 1)    /* DMA的数量 */
#define BFD_MAX_DMA_DRIM_NUM (BFD_MAX_DMA_NUM * 2)   /* DAM的总数量 */
#define BFD_MAX_FWDNUM    (2047)   /* 业务盘支持的转发数目 */
#define BFD_TREE_LEVEL      (11)    /* 与BFD_MAX_SESNUM关联，2K个条目是11层 */
#ifdef PTN690
#define BFD_MAX_ALARMNUM  (4096)    /* hdlc告警同步总线支持的BFD ID最大值 */
#endif
#define BFD_MAX_ALL_SESNUM 16384

#ifdef R8000
#define SYS_TOTAL_SLOTNUM (13)     /* 8010设备槽位总数，共13槽 */
#define BFD_MAX_ID ((SYS_TOTAL_SLOTNUM - 2) * BFD_MAX_SESNUM)   /* 所有盘子支持的BFD数量 */
#else               /* PTN 690 */
#define SYS_TOTAL_SLOTNUM   (42)     /* 690设备共支持40块业务盘，对应槽位1~40, 共40块盘 */
#define BFD_MAX_ID BFD_MAX_SESNUM                               /* 所有盘子支持的BFD数量 */
#endif

#ifdef R8000
#define BFD_MAX_SYN_SESNUM (1023)
#define BFD_MAX_NNINUM      (1023)  /* NNI表大小，跟随VE端口的数量变化 */
#endif

#define BFD_DEFAULT_MPLS_EXP    (7)     /* 带MPLS标签的BFD报文的MPLS默认优先级 */
#define BFD_DEFAULT_MPLS_TTL    (255)   /* 带MPLS标签的BFD报文的MPLS默认TTL */

#define BFD_FSM_TASK_TIMER      (5)     /* spm_bfd_task_fsm线程任务运行周期 */

/*
#define SPU
*/
/**STRUCT+********************************************************************/
/*Description: FPGA二叉树模块结构体定义                                        */
/*                                                                           */
/* Added by limingming, 2012/9/24                                             */
/*****************************************************************************/
#define NODESTEP        (4)   /* NODESTEP  =  64bits = 4 * 16 */
#define TMPLABELMAX     (0xFFFFF)     /* TUNNEL 标签最大值  1048575 */
#define TMCLABELMAX     (0xFFFFF)     /* PW 标签最大值  1048575 */
#define DRV_BYTE_INVALID    (0xFF)
#define DRV_USHORT_INVALID (0xFFFF)
#define DRV_ULONG_INVALID  (0xFFFFFFFF)
#define DRV_INT_INVALID    (-1)

#define SYS_MAX_SLOTNUM   (SYS_TOTAL_SLOTNUM)     /* 设备共支持的业务盘数量 */

#ifdef R8000        /* CR 8000 */
#define FPGABASE (0xc80000000LL)        /* FPGA偏移地址 */
#else               /* PTN 690 */
#ifdef SRC      /* CCUT盘 */
#define FPGABASE (0xc40000000LL)        /* FPGA偏移地址 */
#else           /* 业务盘 */
#define FPGABASE (0xc80000000LL)        /* FPGA偏移地址 */
#endif
#endif

#ifdef R8000    /* CR 8000 */
#define BFDSTATEBASE    (0x900000)               /* 背板总线 */
#else           /* PTN 690 */
#define BFDSTATEBASE    (0x800000)               /* 背板总线 */
#endif


#ifdef PTN690   /* PTN 690 */
#ifdef SPU
#define BFDHDLCSTATE        (0x20A5080)     /* 690 SPU盘BFD 告警的寄存器基地址 */
#endif
#define DDR3ID                  (0X1000000)                 /* DDR3配置ID */
#define DDR3IDBFDOFFBASE        (0x10800)                   /* DDR3配置ID上BFD的基地址 */
#define DDR3IDBDFMAPDATEBASE    (0x28800)                   /* CCUT上BFD告警的映射关系基值 */
#endif


#define OAMFWDSRCFPAGBASE   (0xa0000)              /* 查找转发模块寄存器基地址 */
#define OAMFWDFPAGBASE (0xa0000 + 0x4000)    /* 转发表项二叉树基地址 */
#define OAMFWDPAKFPGABASE (0xa0000 + 0x8000)     /* 转发会话配置基地址 */

#define OAMTREESWITCHOFFSET      (0x01)           /* 会话二叉树表示该树是否在翻页的偏移地址 */
#define FWDTREESWITCHOFFSET      (0x04)           /* 查找二叉树表示该树是否在翻页的偏移地址 */

#define BFD_MAX_FWDRECORDNUM  (32)
#define BFD_MULTI_ID          (0x7FFA)

#define BFD_FWD_MSG_ID    0X1                     /* linx报文类型一:同步ID */
#define BFD_FWD_MSG_PCK   0X2                     /* linx报文类型一:转发报文 */
#define BFD_FWD_FPGA_INFO   0X3                   /* linx报文类型三：主盘FPGA协商出来的实际收发包间隔 */
#define CLK_SYNC_INFO             0x4                 /*by xwl*/

#define BFD_FWD_ID_BFD      (1)         /* BFD的同步ID */
#define BFD_FWD_ID_OAM      (2)         /* OAM的同步ID */

#define BFD_LIVEUP        (2000 / BFD_FSM_TASK_TIMER)         /* 10秒 */
#define BFD_STAYDOWN      (12000 / BFD_FSM_TASK_TIMER)        /* 60秒 */
#define BFD_LIVEUPTIMES   (20 / BFD_FSM_TASK_TIMER)     /* 100毫秒 */
#define BFD_ALARM_TYPE    (0X0001)               /* 上报BFD数据类型 */
#define BFD_ALARM_LENTH   (12)                   /* 每一个会话上报信息的字节长度 */

#define BFD_MSG_DEEP_QUEUE     (1000)
#define BFD_MSG_BUF_LENTH      (128)

#define BFD_PARA_DM_CHANGE         (0X1)
#define BFD_PARA_INTERVAL_CHANGE   (0X2)

#define BFD_IPV4                   (0X0)
#define BFD_IPV6                   (0X1)
#define BFD_IP_NONE                (0X2)

#ifdef R8000    /* CR 8000 */
#define BFD_ARAD_LOGICPORT         (100)
#else           /* CR 690 */
#define BFD_ARAD_LOGICPORT         (107)
#endif

#define SPM_BFD_LOG_DIR     "log/BFD.log"

#define SYN_ID_TIMER    (75)        /* 上报BFD ID的定时器，15秒 */

#define MTL_CPU_MAIN_PROCESS   (1)     /* 主控进程所在的CPU号 */
#define MTL_CPU_TRANS_PROCESS  (0)     /* 转发进程所在的CPU号 */



/* 盘间通信包类型,包层级 */
#define SLOT_TRANSFER   (1 << 0)
#define SLOT_TRAN_SYN   (1 << 1)


/* 盘间通信包实例，今后可改成动态fd */
typedef enum SLOT_TRAN_INST
{
    tran_forwad = 0,    /* 转发包 */
    tran_syn_bfd,       /* BFD同步ID包 */
    tran_syn_oam,       /* OAM同步ID包 */
    tran_fpga_working_info,  /* FPGA协商出来的收发包间隔 */
    tran_syn_clk,           /*时钟数据同步 by xwl */
    TRAN_MAX_NUM       /* 最大个数 */
}SLOT_TRAN_INST_ENUM;

/***************************************************************************/
/* NNI表项(配置在VE接口的BFD FOR PW使用)                                   */
/***************************************************************************/
typedef struct spm_bfd_nniinfo
{
    NBB_ULONG ulDrim;            /* BFD ID */
    NBB_ULONG ulIpv4;            /* IPv4地址 */
    NBB_ULONG ulPwLabel;         /* PW标签 */
    NBB_ULONG ulNniId;           /* C3使用的NNI ID */
}SPM_BFD_NNIINFO;


/***************************************************************************/
/* 跨盘会话转发表项                                                        */
/***************************************************************************/
typedef struct spm_bfd_fwdinfo
{
    NBB_ULONG ulDiscrimer;     /* 会话描述符 */
    NBB_USHORT usSlotid;       /* 会话对应的主处理盘槽位号 */
}SPM_BFD_FWDINFO;

/***************************************************************************/
/* 主控盘ID处理结构体                                                       */
/***************************************************************************/
/* 主控盘存储的ID属性 */
typedef struct spm_bfd_id_info
{
    NBB_ULONG ulDiscrimer; /* 会话描述符 */
}SPM_BFD_ID_INFO;

/* 主控盘存储的各业务盘的ID */
typedef struct spm_bfd_id_store
{
    SPM_BFD_ID_INFO stBfdIdInfo[BFD_MAX_SESNUM];
    
}SPM_BFD_ID_STORE;

/***************************************************************************/
/*调试用的结构体                                                           */
/***************************************************************************/
typedef struct spm_bfd_fwdrecord
{
    NBB_ULONG aulDiscrimer[BFD_MAX_FWDRECORDNUM]; /* 转发的报文，一次最多纪录32条描述符 */
    NBB_ULONG ulNum;
}SPM_BFD_FWDRECORD;

/**STRUCT-********************************************************************/
/*Description: BFD配置模块结构体定义                                         */
/*                                                                           */
/* Added by limingming, 2012/9/24                                            */
/*****************************************************************************/


typedef struct spm_bfdglb_ip_key
{
    NBB_ULONG ulSip;                      /* 源IP地址 */
    NBB_ULONG ulDip;                      /* 目的IP地址 */
    NBB_USHORT usVrfid;                   /* 接口绑定的vpnid */
}SPM_BFDGLB_IP_KEY;

typedef struct spm_bfd_ip_global
{
    AVLL_NODE spm_bfdip_node;
    SPM_BFDGLB_IP_KEY  stBfdGlbKey;
    NBB_ULONG ulDiscrimer;                /* 描述符 */
    NBB_USHORT usSlotid;                  /* 会话的主处理盘 */
}SPM_BFD_IP_GLOBAL;

/* add begin by limingming, 2013/5/3, Mantis号:HSDIPV6BFD, 原因:实现IPV6BFD */
typedef struct spm_bfdglb_ipv6_key
{
    NBB_ULONG ulSip[4];                      /* 源IP地址 */
    NBB_ULONG ulDip[4];                      /* 目的IP地址 */
    NBB_USHORT usVrfid;                   /* 接口绑定的vpnid */
}SPM_BFDGLB_IPV6_KEY;

typedef struct spm_bfd_ipv6_global
{
    AVLL_NODE spm_bfdipv6_node;
    SPM_BFDGLB_IPV6_KEY  stBfdGlbKey;
    NBB_ULONG ulDiscrimer;                /* 描述符 */
    NBB_USHORT usSlotid;                  /* 会话的主处理盘 */
}SPM_BFD_IPV6_GLOBAL;
/* add end by limingming, 2013/5/3 */

/***************************************************************************/
/* 报文信息提取                                                            */
/***************************************************************************/
typedef struct spm_bfd_packet_abstract
{
    NBB_BYTE  ucIpType;   /* ipv4(0) or ipv6(1) */
    NBB_ULONG ulDip[4];
    NBB_ULONG ulSip[4];
    NBB_ULONG ulMyDrim;
    NBB_BYTE  ucState;
}SPM_BFD_PACKET_ABSTRACT;

/***************************************************************************/
/* 各业务盘转发信息记录                                                    */
/***************************************************************************/
typedef struct  spm_fwd_global
{
    AVLL_NODE spm_fwd_node;
    NBB_ULONG ulDiscrimer;                /* key id */
    NBB_USHORT usSlotid;                  /* 会话的主处理盘 */
}SPM_FWD_GLOBAL;

/* bfd同步ID报文的包净荷格式 */
typedef struct spm_bfd_syn_bfd_id
{
    NBB_USHORT      arrucBfdId[BFD_MAX_SESNUM]; /* BFD ID */
}__attribute__ ((packed)) SPM_BFD_SYN_BFD_ID;

/* 盘间传输报文传输层的包头格式 */
typedef struct spm_bfd_slot_tran_head
{
    NBB_BYTE    ucType;             /* 类型 */
    NBB_BYTE    ucPad[3];           /* 保留字节 */
    NBB_ULONG   ulSrcSlot;          /* 发包源槽位 */
}__attribute__ ((packed)) SPM_BFD_SLOT_TRAN_HEAD;

/* 盘间传输报文同步层的包头格式 */
typedef struct spm_bfd_syn_id_head
{
    NBB_BYTE    ucInstance;         /* 实例 */
    NBB_BYTE    ucPad[3];           /* 保留字节 */
    NBB_ULONG   ulSequenceID;       /* 序列号 */
}__attribute__ ((packed)) SPM_BFD_SYN_ID_HEAD;

/* 盘间传输的接收端头的包格式 */
typedef struct spm_bfd_syn_rev_pkt_head
{
    SPM_BFD_SLOT_TRAN_HEAD    tran_head;               /* bfd槽位之间同步包的头 */
    SPM_BFD_SYN_ID_HEAD       syn_head;               /* 同步头 */
}__attribute__ ((packed)) SPM_BFD_SYN_REV_PKT_HEAD;   /* bfd不同槽位之间同步收包的包头 */

/* 盘间传输的发送端头的包格式 */
typedef struct spm_bfd_slot_tran_send_pkt_head
{
    SPM_BFD_SLOT_TRAN_HEAD  tran_head;              /* 转发头 */
    SPM_BFD_SYN_ID_HEAD     syn_head;               /* 同步头 */
}__attribute__ ((packed)) SPM_BFD_SLOT_TRAN_SEND_PKT_HEAD;   /* bfd不同槽位之间同步发包的包头 */

typedef struct spm_bfd_syn_pamt
{
    NBB_BYTE                mainEmuId;              /* 主控槽位 */
    NBB_BYTE                timer;                  /* 计数器 */
    BMU_WDOG_ID             wdog;                   /* 定时器 */
    NBB_BOOL                isModifySession;        /* 会话ID是否发生了变化，若发生变化，则需要同步 */
    NBB_BOOL                isReadySendtoMaster;    /* 是否可以同步ID,因为存在发送等待时间 */
}SPM_BFD_SYN_PAMT;


typedef struct spm_bfd_slot_tran_info
{
    NBB_CHAR                        pkt_type;       /* 包类型，标明包是第几层的，位图形式表示 */
    SPM_BFD_SLOT_TRAN_HEAD          tran_head;      /* 同步转发层包头 */
    SPM_BFD_SYN_ID_HEAD             syn_head;       /* 盘间ID同步层包头 */
    SPM_BFD_SLOT_TRAN_GET_DATA      getDate;        /* 获取包净荷回调函数 */
    SPM_BFD_SLOT_TRAN_RELEASE       release;        /* 释放资源回调函数 */
    SPM_BFD_SLOT_TRAN_SET_DATA      setDate;        /* 处理包净荷回调函数 */
    SPM_BFD_SYN_PAMT                syn_pamt;       /* 同步报文的相关参数 */
}SPM_BFD_SLOT_TRAN_INFO;    /* 盘间通信的类型信息 */

typedef struct spm_bfd_interval_report
{
    NBB_ULONG ulworkingtx; /* 实际工作发送周期 */
    NBB_ULONG ulworkingrx; /* 实际工作接收周期 */
    NBB_BOOL  bflag;       /* 标志位，为了防止始终不上报 */
}SPM_BFD_INTERVAL_REPORT;

/*****************************会话状态***************************************/

/* 会话建立状态 */
#define BFD_NO_CREATE       (0)
#define BFD_NORMAL          (1<<0)
#define BFD_DMTI_CHANGE     (1<<1)
#define BFD_RMRI_CHANGE     (1<<2)
#define BFD_DM_CHANGE       (1<<3)
#define BFD_DESTROY         (1<<4)
#define BFD_REPORT_EN       (1<<5)

//本地系统最后一次会话DOWN的原因
enum bfd_diag_type
{
    bfd_diag_no_diag = 0,                /*0=不诊断*/
    bfd_diag_ctrl_detect_exp,            /*1=控制检测超时*/
    bfd_diag_echo_failed,                /*2=回声功能失败*/
    bfd_diag_nbr_session_down,            /*3=邻居发过信令的会话DOWN*/
    bfd_diag_fwd_reset,                    /*4=转发平面重置*/
    bfd_diag_path_down,                /*5=路径DOWN*/
    bfd_diag_concat_path_down,            /*6=连接的路径DOWN*/
    bfd_diag_admin_down,                /*7=系统管理使之DOWN*/
    bfd_diag_rev_concat_path_down        /*8=反向链路DOWN*/
};

/* 当前BFD会话的状态 */
typedef enum en_BfdSta
{
    BFD_ADMINDOWN = 0,
    BFD_DOWN,
    BFD_INIT,
    BFD_UP,
    BFD_STA_BUTT
}en_BfdSta_T;

/*设置BFD原因*/
typedef enum set_BfdSta
{
    TIMEOUT_DOWN = 5,
    APS_DOWN,
    APS_ADMINDOWN
}set_BfdSta_T;

typedef enum en_bfd_recv_action
{
    /*************** 以上值不能改变位置，不能改变值 *******************/
    BFD_ACTION_ADMINDOWN = 0,
    BFD_ACTION_DOWN = 1,
    BFD_ACTION_INIT = 2,
    BFD_ACTION_UP = 3,
    
    /***** 以上值不能改变位置，不能改变值，新加枚举值请在以下加 *******/
    BFD_ACTION_TIME_OUT,

    /****************** 新添加枚举值请在以上添加 **********************/
    BFD_ACTION_NONE
}EN_BFD_RECV_ACTION;

#ifdef R8000    /* CR 8000 */
/* 提供倒换模块的BFD状态 */
typedef enum en_BfdRcordSta
{
    BFD_RECORD_INVALID = 0,/* 初始化无效 */
    BFD_RECORD_UP,
    BFD_RECORD_DOWN,
    BFD_RECORD_BUTT
}en_BfdRcordSta_T;
#else           /* CR 690 */
typedef enum en_BfdRcordSta
{
    BFD_RECORD_INVALID = 0,
    BFD_RECORD_UP = 2,
    BFD_RECORD_DOWN = 3,
    BFD_RECORD_BUTT
}en_BfdRcordSta_T;
#endif


/* 协议栈会话类型0/1/2/3= IP/Tunnel/LSP/PW+LSP */
typedef enum en_BfdCfgType
{
    BFD_CFG_IP = 0,
    BFD_CFG_Tunnel, /* rsvp lsp、tunnel */
    BFD_CFG_LSP,    /* ldp lsp */
    BFD_CFG_PW,     /* pw */
    BFD_CFG_INTERFACE /* for interface */
}en_BfdCfgType_T;

/* LSP的类型 */
typedef enum en_BfdLspType
{
    BFD_LDP_LSP = 1,
    BFD_RSVP_LSP
}en_BfdLspType_T;

/* 会话类型 */
typedef enum en_BfdType
{
    BFD_SIGHOP = 0,  /* 单跳，UDP3784 */
    BFD_MULTIHOP,    /* 多跳，UDP3785 */
    BFD_LAG,         /* LAG, UDP6784 */
    BFD_HOP_BUTT
}en_BfdType_T;

/* FPGA组帧类型 */
typedef enum en_BfdPckType
{
    BFD_IP = 0,   
    BFD_LSP,
    BFD_PW_type1, /* 无IP头有ACH头帧格式发送 */
    BFD_PW_type2, /* 有LSP标签、PW标签 有ACH头有IP头帧格式发送 */
    BFD_PCK_BUTT
}en_BfdPckType_T;

/* 检查时间间隔 */
typedef enum en_BfdTimer
{
    BFD_3MS3 = 1,
    BFD_10MS,
    BFD_20MS,
    BFD_30MS,
    BFD_40MS,
    BFD_50MS,
    BFD_60MS,
    BFD_70MS,
    BFD_80MS,
    BFD_90MS,
    BFD_100MS,
    BFD_200MS,
    BFD_300MS,
    BFD_400MS,
    BFD_500MS,
    BFD_150MS,
    BFD_250MS,
    BFD_350MS,
    BFD_450MS,
    BFD_1000MS,
    BFD_TIME_BUTT
}en_BfdTimer_T;

/**********************状态写寄存器************************************/
#ifdef R8000    /* CR 8000 */
typedef struct spm_bfd_reg_state
{
    NBB_UINT uiState16 : 2;
    NBB_UINT uiState15 : 2;
    NBB_UINT uiState14 : 2;
    NBB_UINT uiState13 : 2;
    NBB_UINT uiState12 : 2;
    NBB_UINT uiState11 : 2;
    NBB_UINT uiState10 : 2;
    NBB_UINT uiState9 : 2;
    NBB_UINT uiState8 : 2;
    NBB_UINT uiState7 : 2;
    NBB_UINT uiState6 : 2;
    NBB_UINT uiState5 : 2;
    NBB_UINT uiState4 : 2;
    NBB_UINT uiState3 : 2;
    NBB_UINT uiState2 : 2;
    NBB_UINT uiState1 : 2;
}SPM_BFD_REG_STATE;
#endif

/***********************发送报文寄存器结构体****************************/

/* fwd packet type1 */
#ifdef PTN690
typedef struct spm_bfd_fwd_packet1
{
    NBB_USHORT usPad1 :1;
    NBB_USHORT pph_persent_flag:1;
    NBB_USHORT vlan_num:2;
    NBB_USHORT cw_exist_flag:1;
    NBB_USHORT usPad2:2;
    NBB_USHORT usFwdTrafficClass :3;
    NBB_USHORT usFwdDp :2;
    NBB_USHORT usFwdDesInfo1:4;
}SPM_BFD_FWD_PACKET1;
#else
typedef struct spm_bfd_fwd_packet1
{
    NBB_USHORT usPad :7;
    NBB_USHORT usFwdTrafficClass :3;
    NBB_USHORT usFwdDp :2;
    NBB_USHORT usFwdDesInfo1:4;
}SPM_BFD_FWD_PACKET1;
#endif

/* fwd packet type2 */
typedef struct spm_bfd_fwd_packet2
{
    NBB_USHORT usPad :1;
    NBB_USHORT usSysPortID : 15;
}SPM_BFD_FWD_PACKET2;

/* fwd packet type3 */
typedef struct spm_bfd_fwd_packet3
{
    NBB_USHORT usPktType :3;
    NBB_USHORT usDslotid :5;
    NBB_USHORT usSslotid :5;
    NBB_USHORT usFwdType :3;
}SPM_BFD_FWD_PACKET3;

/* fwd packet type4 */
typedef struct spm_bfd_interface_dmac3
{
    NBB_USHORT usPad : 7;
    NBB_USHORT usUnit: 1;  /* 芯片号 */
    NBB_USHORT usSlotid:8;
}SPM_BFD_INTERFACE_DMAC3;

typedef struct spm_bfd_interface_smac2
{
    NBB_USHORT usBIsLag:    1;
    NBB_USHORT usPortId:    7;
    NBB_USHORT usVlanH:     8;
}SPM_BFD_INTERFACE_SMAC2;

typedef struct spm_bfd_interface_smac3
{
    NBB_USHORT usVlanL:     8;
    NBB_USHORT usPad:       8;
}SPM_BFD_INTERFACE_SMAC3;

typedef struct bfd_fpga_reg_smac1
{
    unsigned short smac:    5;
    unsigned short index:   11;     /* FPGA中BFD所在位置的索引，即数组下标 */
}BFD_FPGA_REG_SMAC1;

typedef struct bfd_fpga_reg_adapt_smac1
{
    unsigned short pad:     5;
    unsigned short smac:   11;     /* SMAC[42:32] */
}BFD_FPGA_REG_ADAPT_SMAC1;

typedef struct spm_bfd_pw_smac2
{
    NBB_USHORT usPeerIpH;
}SPM_BFD_PW_SMAC2;

typedef struct spm_bfd_pw_smac3
{
    NBB_USHORT usPeerIpL;
}SPM_BFD_PW_SMAC3;


/* fwd packet type5 */
typedef struct spm_bfd_fwd_packet5
{
    NBB_USHORT usBIsLag : 1;
    NBB_USHORT usPortid: 7;  
    NBB_USHORT usPad:5;
    NBB_USHORT usFwdType:3;
}SPM_BFD_FWD_PACKET5;

#ifdef PTN690
/* fwd packet type6 */
typedef struct spm_bfd_fwd_packet6
{
    NBB_USHORT usPad   : 9;
    NBB_USHORT usSlotId: 7;
}SPM_BFD_FWD_PACKET6;

/* fwd packet type7 */
typedef struct spm_bfd_fwd_packet7
{
    NBB_USHORT usBIsLag: 1;
    NBB_USHORT usPortid: 7;
    NBB_USHORT usPad: 2;
    NBB_USHORT usPktType: 3;
    NBB_USHORT usDectecType: 3;  
}SPM_BFD_FWD_PACKET7;

typedef struct spm_bfd_fifo_svlan
{
    NBB_USHORT usPad1:       4;  /* 固定为A */
    NBB_USHORT usPad2:       8;
    NBB_USHORT usVrfH:      4;
}SPM_BFD_FIFO_SVLAN;

typedef struct spm_bfd_fifo_cvlan
{
    NBB_USHORT usPad:       1;
    NBB_USHORT usPktType:   2;  /* 包类型，=0，表示LSP层包，=2表示纯IP包，=1表示PW无IP封装的包，=3表示PW有IP封装的包 */
    NBB_USHORT usIpType:    1;  /* 表示IP协议类型，为1表示IPV6，为0表示IPV4 */
    NBB_USHORT usVrfL:      12;
}SPM_BFD_FIFO_CVLAN;
#endif

typedef struct spm_bfd_up_to_down_sta
{
    NBB_USHORT time_out_count : 4;  /* 记录本端超时告警次数计数 */
    NBB_USHORT pkt_count      : 4;  /* 会话up到down检测开关打开时，收到对端down报文次数计数 */
    NBB_USHORT pad2           : 2;  /* 保留 */
    NBB_USHORT dig            : 2;  /* 会话up到down检测开关打开时，该条目会话down原因，‘1’超时down，‘3’对端down */
    NBB_USHORT pad1           : 3;  /* 保留 */
    NBB_USHORT enable         : 1;  /* 会话up到down检测开关, ‘1’使能打开，‘0’使能关闭 */
}SPM_BFD_UP_TO_DOWN_STA;

/* 转发平面转发类型,最多扩展到8种类型 */
typedef enum BFD_FWDTYPE
{
    BFD_FWD_IP = 0, /* BFD IPV4转发，微码根据VRFID+IPV4 ADDRESS查路由表 */
    BFD_FWD_LSPID,  /* BFD FOR LSP、VP OAM，微码根据lspid转发报文 */
    BFD_FWD_TUNNELID, /* BFD FOR TUNNEL，微码根据TunnelID转发报文 */
    BFD_FWD_PORT,    /* BFD FOR INTERFACE，VS OAM转发，微码根据SVLAN+IPV4 ADDRESS(下一跳)+port发送 */
    BFD_FWD_PW,     /* BFD FOR PW,VC OAM,微码根据NHIID转发报文 */
    BFD_FWD_LAG,    /* BFD FOR LAG，微码根据槽位号和端口号转发报文 */
    BFD_FWD_BUTT
}BFD_FWDTYPE_T;

/* DUNE通信类型,最多扩展到8种类型  */
typedef enum BFD_DUNETYPE
{
    BFD_DUNE_FROMC3 = 0,/* BFD报文收方向，业务盘FPGA转发发送到其他盘(主控和业务盘)FPGA的BFD报文 */
    BFD_DUNE_TOC3,      /* BFD报文发送方向，主控盘FPGA发送到业务盘FPGA的BFD报文 */
    BFD_DUNE_LINKLOSS,  /* 业务盘FPGA发送到其他业务盘FPGA的link loss告警 */
    BFD_DUNE_BUTT
}BFD_DUNETYPE_T;

/* BFD上送信息 */
typedef struct bfd_report_info
{
    NBB_ULONG ulLocalDisrim;
    NBB_BYTE  ucSessionState;
    NBB_BYTE  ucDiag;
    NBB_BYTE  ucDMTI;
    NBB_BYTE  ucRMRI;
    NBB_ULONG ulRemoteDisrim;
}BFD_REPORT_INFO;

/* SPU盘状态信息 */
typedef struct bfd_board_info
{
    NBB_BYTE ucBoardState; /* 盘在位信息 */
    NBB_BYTE ucBoardBmuState; /* 盘心跳信息 */
    NBB_USHORT usTimeCounter;/* 盘不在位计时 */
}BFD_BOARD_INFO;

typedef struct bfd_slot_tran_fd
{
    NBB_BOOL foward_id;         /* 存储bfd用来做盘间包转发的序号 */
    NBB_BOOL syn_id_fd;         /* 存储bfd用来做盘间同步ID的序号 */
    NBB_BOOL fpga_info_fd;      /* 存储主盘FPGA协商出来的收发包间隔的序号 */
}BFD_SLOT_TRAN_FD;

/* 主控在位信息 */
typedef struct bfd_main_board_state
{
    NBB_BYTE ucMainSlot;    /* 主用不在位时，为0xff，否则为槽位号 */
    NBB_BYTE ucBackSlot;    /* 备用不在位时，为0xff，否则为槽位号 */
}BFD_MAIN_BOARD_STATE;

/* FPGA实际工作的收发包间隔 */
typedef struct bfd_fpga_working_info
{
    NBB_USHORT rx_interval[BFD_MAX_SESNUM];  /* 收包的时间间隔 */
    NBB_BYTE   tx_interval[BFD_MAX_SESNUM];  /* 发包的时间间隔 */
}BFD_FPGA_WORKING_INFO;



/***************************************************************************/
/* BFD模块全局变量  Added by limingming, 2012/10/8                         */
/***************************************************************************/    
extern NBB_BYTE   g_aucCouterRecord[BFD_MAX_SESNUM]; /* 每个条目记录的接收到的会话的Couter，若有变化才说明收到的是新报文 */
extern AVLL_TREE  g_stBfdGlbTreeByDis;              /* 全局配置存储,按照描述符存储 */
extern AVLL_TREE  g_stBfdGlbTreeByIp;               /* BFD FOR IP配置存储，按照vrfid+sip存储 */
extern AVLL_TREE  g_stBfdGlbTreeByIpv6;             /* BFD FOR IPV6配置存储，按照vrfid+sipv6存储 */
extern AVLL_TREE  g_stFwdGlbTreeByDis;              /* 业务盘转发会话存储，按照描述符存储 */
extern AVLL_TREE  g_stBfdGlbExcTreeByDis;       /* 全局越限配置存储,按照描述符存储(索引) */

extern NBB_USHORT g_usFwdTreeNodeMaxnum;             /* 转发二叉树最大节点数 */
extern NBB_USHORT g_usFwdTreeLevel;                  /* 转发二叉树的层数，每个业务盘支持2k转发，因此层数为11*/
extern NBB_USHORT g_usFwdLspNoMax;                   /* 转发最大条目号 */
extern BFD_PUL_FWD_TREE_BASE g_pulFwdTreebase;            /* 转发存储二叉树每一层的相对地址 */
extern NBB_USHORT g_usFwdNum;                        /* 转发数目 */
extern SPM_OAMTREE_SET  g_stTreeFwdNodeSet;     /* 存储第二颗二叉树的结点设置的内容，2k转发表项 */

extern SPM_BFD_FWDINFO  g_stBfdfwd[BFD_MAX_FWDNUM];  /* 转发表项存储 */

extern SPM_BFD_FWDRECORD g_stFwdTxRec[SYS_TOTAL_SLOTNUM]; /* 每个盘转发的报文计数，以目的槽位号减1为数组下标 */
extern SPM_BFD_FWDRECORD g_stFwdRxRec[SYS_TOTAL_SLOTNUM]; /* 每个盘接收到的的报文计数，以源槽位号减1为数组下标 */
extern SPM_BFD_ID_STORE  g_stBfdIdStore[SYS_MAX_SLOTNUM]; /* 主控盘存储的业务盘ID信息 */
extern NBB_INT linx_fd;                  /* LINX的fd换成全局变量 add by ljuan */
extern BFD_PUC_SYN_ID_INFO g_pucSynIdInfo;         /* 同步ID报文 */
extern NBB_ULONG g_ulSynIdInfoLth;       /* 同步ID报文长度 */

extern BFD_PUC_ALARM_INFO g_pucAlarmInfo;         /* 状态上报协议栈 */
extern NBB_USHORT g_usAlarmInfoLenth;
extern NBB_BYTE   g_ucCpuTick;          /* 心跳控制 */
extern NBB_BOOL   g_BIsRecordDownEvent;
extern NBB_BOOL   g_BIsCloseStateMachine[BFD_MAX_SESNUM];   /* 关闭状态机开关 */

extern SPM_BFD_INTERVAL_REPORT g_stintervalinfo[BFD_MAX_SESNUM];/* 频率 */


/* dma 读操作 */
extern NBB_UINT  g_auiDmaData[BFD_MAX_DMA_NUM];
extern NBB_UINT  g_auiDmaDrimData[BFD_MAX_DMA_DRIM_NUM];

extern unsigned long long g_aullDmaDataInfo[2][2];
extern int g_iDevFd;

extern BFD_BOARD_INFO  g_astBoardState[10];       /* 8010 SPU盘在位信息 */


extern BFD_SLOT_TRAN_FD  g_bfd_fd;               /* 存储bfd用来做盘间收发包的序号 */

extern SPM_BFD_SLOT_TRAN_INFO  g_astSlotTranInfo[TRAN_MAX_NUM];   /* 盘间通信信息 */

extern BFD_SLOT_TRAN_FD  g_bfd_fd;               /* 存储bfd用来做盘间收发包的序号 */

/*************************************************************************
 * 变量功能：BFD的收包和转发包打印
 * 取值范围：0代表打印关闭；1代表打印开启
 * 注意事项：无
 *************************************************************************/
extern NBB_BYTE g_bfd_send_recv_print_flag;

#ifdef R8000
extern NBB_USHORT g_usNniTreeNodeMaxnum;             /* NNI表二叉树最大节点数 */
extern NBB_USHORT g_usNniTreeLevel;                  /* NNI表二叉树的层数，每个业务盘支持1k转发，因此层数为10*/
extern NBB_USHORT g_usNniNoMax;                     /* NNI表最大条目号 */
extern BFD_PUL_FWD_TREE_BASE g_pulNniTreebase;            /* NNI表存储二叉树每一层的相对地址 */
extern NBB_USHORT g_usNniNum;                        /* NNI表数目 */
extern SPM_OAMTREE_SET  g_stTreeNniNodeSet;     /* 存储第二颗NNI表二叉树的结点设置的内容，1k转发表项 */
extern SPM_BFD_NNIINFO g_stBfdNni[BFD_MAX_NNINUM];  /* NNI表 */
#endif


/***************************功能宏定义****************************************/


#define BFD_FWD_INIT(usLoopi){ \
    if (usLoopi < BFD_MAX_FWDNUM)\
    {\
        g_stBfdfwd[usLoopi].usSlotid = DRV_USHORT_INVALID;\
        g_stBfdfwd[usLoopi].ulDiscrimer = DRV_ULONG_INVALID;\
    }\
}

#define BFD_PACKETLEN_JUDGE(lLength){\
    if (lLength < 0)\
    {\
        return ERROR;\
    }\
}

#endif

