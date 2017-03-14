/***********************************************************************************

 * �� �� ��   : spm_bfd.h
 * �� �� ��   : ����,jiangbo
 * ��������   : 2014��11��28��
 * �� �� ��   : 
 * �ļ�����   : BFDͷ�ļ�
 * ��Ȩ˵��   : Copyright (C) 2000-2014   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 

***********************************************************************************/

#ifndef SPM_BFD_INCLUDED
#define SPM_BFD_INCLUDED

#include "bmuInclude.h"



/***************************************************************************/
/* BFD����������Ͷ���                                                     */
/***************************************************************************/
typedef NBB_ULONG*  BFD_PUL_TREE_BASE;
typedef NBB_ULONG*  BFD_PUL_FWD_TREE_BASE;
typedef NBB_BYTE*   BFD_PUC_SYN_ID_INFO;
typedef NBB_BYTE*   BFD_PUC_ALARM_INFO;

typedef NBB_BYTE* (*SPM_BFD_SLOT_TRAN_GET_DATA)(NBB_ULONG *);
typedef NBB_INT (*SPM_BFD_SLOT_TRAN_SET_DATA)(NBB_VOID *, NBB_ULONG, NBB_USHORT);
typedef NBB_INT (*SPM_BFD_SLOT_TRAN_RELEASE)(NBB_BYTE *);


/***************************************************************************/
/* BFD�����붨��                                                           */
/***************************************************************************/
#define BFD_ERROR_BASE                      (-50000)
#define BFD_ERROR_PAMT_NULL                 (BFD_ERROR_BASE - 1)    /* ����Ϊ�� */
#define BFD_ERROR_PAMT_OVER                 (BFD_ERROR_BASE - 2)    /* ����ΪԽ�� */
#define BFD_ERROR_MTL_ALLOC                 (BFD_ERROR_BASE - 3)    /* MTL�����ڴ�ʧ�� */
#define BFD_ERROR_MTL_SEND                  (BFD_ERROR_BASE - 4)    /* MTL����ʧ�� */
#define BFD_ERROR_LACK_LAYER                (BFD_ERROR_BASE - 5)    /* �̼�ͨ�Ű��м�ȱ��һ�� */
#define BFD_ERROR_DO_NOT_HAVE_MAIN_BOARD    (BFD_ERROR_BASE - 6)    /* ���ز���λ */
#define BFD_ERROR_NOT_EXIST                 (BFD_ERROR_BASE - 7)    /* ���ҵ������ */
#define BFD_ERROR_NBB_ALLOC                 (BFD_ERROR_BASE - 8)    /* nbase�����ڴ�ʧ�� */
#define BFD_ERROR_ADD_LIMITED_TREE          (BFD_ERROR_BASE - 9)    /* ���Խ�����ô洢������ʧ�� */
#define BFD_ERROR_LIMITED_TREE_NOT_FOUND    (BFD_ERROR_BASE - 10)   /* Խ�����ô洢�����������ڲ��ҽڵ� */


/***************************************************************************/
/* BEP������                                                             */
/***************************************************************************/
#ifdef BEP_ENABLE
#define BFD_SYS_CALLOC(SIZE, TYPE)      sys_calloc((SIZE), 1)
#define BFD_SYS_FREE(MEM, SIZE)         sys_free(MEM)
#else
#define BFD_SYS_CALLOC(SIZE, TYPE)          OS_ALLOC((SIZE), (TYPE))
#define BFD_SYS_FREE(MEM, SIZE)             OS_FREE((MEM), (SIZE))
#endif /* BEP_ENABLE */

#define BFD_MAX_SESNUM    (2047)   /* ÿ������֧�ֵ�BFD�Ự��Ŀ */
#define BFD_MAX_DMA_NUM     (BFD_MAX_SESNUM + 1)    /* DMA������ */
#define BFD_MAX_DMA_DRIM_NUM (BFD_MAX_DMA_NUM * 2)   /* DAM�������� */
#define BFD_MAX_FWDNUM    (2047)   /* ҵ����֧�ֵ�ת����Ŀ */
#define BFD_TREE_LEVEL      (11)    /* ��BFD_MAX_SESNUM������2K����Ŀ��11�� */
#ifdef PTN690
#define BFD_MAX_ALARMNUM  (4096)    /* hdlc�澯ͬ������֧�ֵ�BFD ID���ֵ */
#endif
#define BFD_MAX_ALL_SESNUM 16384

#ifdef R8000
#define SYS_TOTAL_SLOTNUM (13)     /* 8010�豸��λ��������13�� */
#define BFD_MAX_ID ((SYS_TOTAL_SLOTNUM - 2) * BFD_MAX_SESNUM)   /* ��������֧�ֵ�BFD���� */
#else               /* PTN 690 */
#define SYS_TOTAL_SLOTNUM   (42)     /* 690�豸��֧��40��ҵ���̣���Ӧ��λ1~40, ��40���� */
#define BFD_MAX_ID BFD_MAX_SESNUM                               /* ��������֧�ֵ�BFD���� */
#endif

#ifdef R8000
#define BFD_MAX_SYN_SESNUM (1023)
#define BFD_MAX_NNINUM      (1023)  /* NNI���С������VE�˿ڵ������仯 */
#endif

#define BFD_DEFAULT_MPLS_EXP    (7)     /* ��MPLS��ǩ��BFD���ĵ�MPLSĬ�����ȼ� */
#define BFD_DEFAULT_MPLS_TTL    (255)   /* ��MPLS��ǩ��BFD���ĵ�MPLSĬ��TTL */

#define BFD_FSM_TASK_TIMER      (5)     /* spm_bfd_task_fsm�߳������������� */

/*
#define SPU
*/
/**STRUCT+********************************************************************/
/*Description: FPGA������ģ��ṹ�嶨��                                        */
/*                                                                           */
/* Added by limingming, 2012/9/24                                             */
/*****************************************************************************/
#define NODESTEP        (4)   /* NODESTEP  =  64bits = 4 * 16 */
#define TMPLABELMAX     (0xFFFFF)     /* TUNNEL ��ǩ���ֵ  1048575 */
#define TMCLABELMAX     (0xFFFFF)     /* PW ��ǩ���ֵ  1048575 */
#define DRV_BYTE_INVALID    (0xFF)
#define DRV_USHORT_INVALID (0xFFFF)
#define DRV_ULONG_INVALID  (0xFFFFFFFF)
#define DRV_INT_INVALID    (-1)

#define SYS_MAX_SLOTNUM   (SYS_TOTAL_SLOTNUM)     /* �豸��֧�ֵ�ҵ�������� */

#ifdef R8000        /* CR 8000 */
#define FPGABASE (0xc80000000LL)        /* FPGAƫ�Ƶ�ַ */
#else               /* PTN 690 */
#ifdef SRC      /* CCUT�� */
#define FPGABASE (0xc40000000LL)        /* FPGAƫ�Ƶ�ַ */
#else           /* ҵ���� */
#define FPGABASE (0xc80000000LL)        /* FPGAƫ�Ƶ�ַ */
#endif
#endif

#ifdef R8000    /* CR 8000 */
#define BFDSTATEBASE    (0x900000)               /* �������� */
#else           /* PTN 690 */
#define BFDSTATEBASE    (0x800000)               /* �������� */
#endif


#ifdef PTN690   /* PTN 690 */
#ifdef SPU
#define BFDHDLCSTATE        (0x20A5080)     /* 690 SPU��BFD �澯�ļĴ�������ַ */
#endif
#define DDR3ID                  (0X1000000)                 /* DDR3����ID */
#define DDR3IDBFDOFFBASE        (0x10800)                   /* DDR3����ID��BFD�Ļ���ַ */
#define DDR3IDBDFMAPDATEBASE    (0x28800)                   /* CCUT��BFD�澯��ӳ���ϵ��ֵ */
#endif


#define OAMFWDSRCFPAGBASE   (0xa0000)              /* ����ת��ģ��Ĵ�������ַ */
#define OAMFWDFPAGBASE (0xa0000 + 0x4000)    /* ת���������������ַ */
#define OAMFWDPAKFPGABASE (0xa0000 + 0x8000)     /* ת���Ự���û���ַ */

#define OAMTREESWITCHOFFSET      (0x01)           /* �Ự��������ʾ�����Ƿ��ڷ�ҳ��ƫ�Ƶ�ַ */
#define FWDTREESWITCHOFFSET      (0x04)           /* ���Ҷ�������ʾ�����Ƿ��ڷ�ҳ��ƫ�Ƶ�ַ */

#define BFD_MAX_FWDRECORDNUM  (32)
#define BFD_MULTI_ID          (0x7FFA)

#define BFD_FWD_MSG_ID    0X1                     /* linx��������һ:ͬ��ID */
#define BFD_FWD_MSG_PCK   0X2                     /* linx��������һ:ת������ */
#define BFD_FWD_FPGA_INFO   0X3                   /* linx����������������FPGAЭ�̳�����ʵ���շ������ */
#define CLK_SYNC_INFO             0x4                 /*by xwl*/

#define BFD_FWD_ID_BFD      (1)         /* BFD��ͬ��ID */
#define BFD_FWD_ID_OAM      (2)         /* OAM��ͬ��ID */

#define BFD_LIVEUP        (2000 / BFD_FSM_TASK_TIMER)         /* 10�� */
#define BFD_STAYDOWN      (12000 / BFD_FSM_TASK_TIMER)        /* 60�� */
#define BFD_LIVEUPTIMES   (20 / BFD_FSM_TASK_TIMER)     /* 100���� */
#define BFD_ALARM_TYPE    (0X0001)               /* �ϱ�BFD�������� */
#define BFD_ALARM_LENTH   (12)                   /* ÿһ���Ự�ϱ���Ϣ���ֽڳ��� */

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

#define SYN_ID_TIMER    (75)        /* �ϱ�BFD ID�Ķ�ʱ����15�� */

#define MTL_CPU_MAIN_PROCESS   (1)     /* ���ؽ������ڵ�CPU�� */
#define MTL_CPU_TRANS_PROCESS  (0)     /* ת���������ڵ�CPU�� */



/* �̼�ͨ�Ű�����,���㼶 */
#define SLOT_TRANSFER   (1 << 0)
#define SLOT_TRAN_SYN   (1 << 1)


/* �̼�ͨ�Ű�ʵ�������ɸĳɶ�̬fd */
typedef enum SLOT_TRAN_INST
{
    tran_forwad = 0,    /* ת���� */
    tran_syn_bfd,       /* BFDͬ��ID�� */
    tran_syn_oam,       /* OAMͬ��ID�� */
    tran_fpga_working_info,  /* FPGAЭ�̳������շ������ */
    tran_syn_clk,           /*ʱ������ͬ�� by xwl */
    TRAN_MAX_NUM       /* ������ */
}SLOT_TRAN_INST_ENUM;

/***************************************************************************/
/* NNI����(������VE�ӿڵ�BFD FOR PWʹ��)                                   */
/***************************************************************************/
typedef struct spm_bfd_nniinfo
{
    NBB_ULONG ulDrim;            /* BFD ID */
    NBB_ULONG ulIpv4;            /* IPv4��ַ */
    NBB_ULONG ulPwLabel;         /* PW��ǩ */
    NBB_ULONG ulNniId;           /* C3ʹ�õ�NNI ID */
}SPM_BFD_NNIINFO;


/***************************************************************************/
/* ���̻Ựת������                                                        */
/***************************************************************************/
typedef struct spm_bfd_fwdinfo
{
    NBB_ULONG ulDiscrimer;     /* �Ự������ */
    NBB_USHORT usSlotid;       /* �Ự��Ӧ���������̲�λ�� */
}SPM_BFD_FWDINFO;

/***************************************************************************/
/* ������ID����ṹ��                                                       */
/***************************************************************************/
/* �����̴洢��ID���� */
typedef struct spm_bfd_id_info
{
    NBB_ULONG ulDiscrimer; /* �Ự������ */
}SPM_BFD_ID_INFO;

/* �����̴洢�ĸ�ҵ���̵�ID */
typedef struct spm_bfd_id_store
{
    SPM_BFD_ID_INFO stBfdIdInfo[BFD_MAX_SESNUM];
    
}SPM_BFD_ID_STORE;

/***************************************************************************/
/*�����õĽṹ��                                                           */
/***************************************************************************/
typedef struct spm_bfd_fwdrecord
{
    NBB_ULONG aulDiscrimer[BFD_MAX_FWDRECORDNUM]; /* ת���ı��ģ�һ������¼32�������� */
    NBB_ULONG ulNum;
}SPM_BFD_FWDRECORD;

/**STRUCT-********************************************************************/
/*Description: BFD����ģ��ṹ�嶨��                                         */
/*                                                                           */
/* Added by limingming, 2012/9/24                                            */
/*****************************************************************************/


typedef struct spm_bfdglb_ip_key
{
    NBB_ULONG ulSip;                      /* ԴIP��ַ */
    NBB_ULONG ulDip;                      /* Ŀ��IP��ַ */
    NBB_USHORT usVrfid;                   /* �ӿڰ󶨵�vpnid */
}SPM_BFDGLB_IP_KEY;

typedef struct spm_bfd_ip_global
{
    AVLL_NODE spm_bfdip_node;
    SPM_BFDGLB_IP_KEY  stBfdGlbKey;
    NBB_ULONG ulDiscrimer;                /* ������ */
    NBB_USHORT usSlotid;                  /* �Ự���������� */
}SPM_BFD_IP_GLOBAL;

/* add begin by limingming, 2013/5/3, Mantis��:HSDIPV6BFD, ԭ��:ʵ��IPV6BFD */
typedef struct spm_bfdglb_ipv6_key
{
    NBB_ULONG ulSip[4];                      /* ԴIP��ַ */
    NBB_ULONG ulDip[4];                      /* Ŀ��IP��ַ */
    NBB_USHORT usVrfid;                   /* �ӿڰ󶨵�vpnid */
}SPM_BFDGLB_IPV6_KEY;

typedef struct spm_bfd_ipv6_global
{
    AVLL_NODE spm_bfdipv6_node;
    SPM_BFDGLB_IPV6_KEY  stBfdGlbKey;
    NBB_ULONG ulDiscrimer;                /* ������ */
    NBB_USHORT usSlotid;                  /* �Ự���������� */
}SPM_BFD_IPV6_GLOBAL;
/* add end by limingming, 2013/5/3 */

/***************************************************************************/
/* ������Ϣ��ȡ                                                            */
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
/* ��ҵ����ת����Ϣ��¼                                                    */
/***************************************************************************/
typedef struct  spm_fwd_global
{
    AVLL_NODE spm_fwd_node;
    NBB_ULONG ulDiscrimer;                /* key id */
    NBB_USHORT usSlotid;                  /* �Ự���������� */
}SPM_FWD_GLOBAL;

/* bfdͬ��ID���ĵİ����ɸ�ʽ */
typedef struct spm_bfd_syn_bfd_id
{
    NBB_USHORT      arrucBfdId[BFD_MAX_SESNUM]; /* BFD ID */
}__attribute__ ((packed)) SPM_BFD_SYN_BFD_ID;

/* �̼䴫�䱨�Ĵ����İ�ͷ��ʽ */
typedef struct spm_bfd_slot_tran_head
{
    NBB_BYTE    ucType;             /* ���� */
    NBB_BYTE    ucPad[3];           /* �����ֽ� */
    NBB_ULONG   ulSrcSlot;          /* ����Դ��λ */
}__attribute__ ((packed)) SPM_BFD_SLOT_TRAN_HEAD;

/* �̼䴫�䱨��ͬ����İ�ͷ��ʽ */
typedef struct spm_bfd_syn_id_head
{
    NBB_BYTE    ucInstance;         /* ʵ�� */
    NBB_BYTE    ucPad[3];           /* �����ֽ� */
    NBB_ULONG   ulSequenceID;       /* ���к� */
}__attribute__ ((packed)) SPM_BFD_SYN_ID_HEAD;

/* �̼䴫��Ľ��ն�ͷ�İ���ʽ */
typedef struct spm_bfd_syn_rev_pkt_head
{
    SPM_BFD_SLOT_TRAN_HEAD    tran_head;               /* bfd��λ֮��ͬ������ͷ */
    SPM_BFD_SYN_ID_HEAD       syn_head;               /* ͬ��ͷ */
}__attribute__ ((packed)) SPM_BFD_SYN_REV_PKT_HEAD;   /* bfd��ͬ��λ֮��ͬ���հ��İ�ͷ */

/* �̼䴫��ķ��Ͷ�ͷ�İ���ʽ */
typedef struct spm_bfd_slot_tran_send_pkt_head
{
    SPM_BFD_SLOT_TRAN_HEAD  tran_head;              /* ת��ͷ */
    SPM_BFD_SYN_ID_HEAD     syn_head;               /* ͬ��ͷ */
}__attribute__ ((packed)) SPM_BFD_SLOT_TRAN_SEND_PKT_HEAD;   /* bfd��ͬ��λ֮��ͬ�������İ�ͷ */

typedef struct spm_bfd_syn_pamt
{
    NBB_BYTE                mainEmuId;              /* ���ز�λ */
    NBB_BYTE                timer;                  /* ������ */
    BMU_WDOG_ID             wdog;                   /* ��ʱ�� */
    NBB_BOOL                isModifySession;        /* �ỰID�Ƿ����˱仯���������仯������Ҫͬ�� */
    NBB_BOOL                isReadySendtoMaster;    /* �Ƿ����ͬ��ID,��Ϊ���ڷ��͵ȴ�ʱ�� */
}SPM_BFD_SYN_PAMT;


typedef struct spm_bfd_slot_tran_info
{
    NBB_CHAR                        pkt_type;       /* �����ͣ��������ǵڼ���ģ�λͼ��ʽ��ʾ */
    SPM_BFD_SLOT_TRAN_HEAD          tran_head;      /* ͬ��ת�����ͷ */
    SPM_BFD_SYN_ID_HEAD             syn_head;       /* �̼�IDͬ�����ͷ */
    SPM_BFD_SLOT_TRAN_GET_DATA      getDate;        /* ��ȡ�����ɻص����� */
    SPM_BFD_SLOT_TRAN_RELEASE       release;        /* �ͷ���Դ�ص����� */
    SPM_BFD_SLOT_TRAN_SET_DATA      setDate;        /* ��������ɻص����� */
    SPM_BFD_SYN_PAMT                syn_pamt;       /* ͬ�����ĵ���ز��� */
}SPM_BFD_SLOT_TRAN_INFO;    /* �̼�ͨ�ŵ�������Ϣ */

typedef struct spm_bfd_interval_report
{
    NBB_ULONG ulworkingtx; /* ʵ�ʹ����������� */
    NBB_ULONG ulworkingrx; /* ʵ�ʹ����������� */
    NBB_BOOL  bflag;       /* ��־λ��Ϊ�˷�ֹʼ�ղ��ϱ� */
}SPM_BFD_INTERVAL_REPORT;

/*****************************�Ự״̬***************************************/

/* �Ự����״̬ */
#define BFD_NO_CREATE       (0)
#define BFD_NORMAL          (1<<0)
#define BFD_DMTI_CHANGE     (1<<1)
#define BFD_RMRI_CHANGE     (1<<2)
#define BFD_DM_CHANGE       (1<<3)
#define BFD_DESTROY         (1<<4)
#define BFD_REPORT_EN       (1<<5)

//����ϵͳ���һ�λỰDOWN��ԭ��
enum bfd_diag_type
{
    bfd_diag_no_diag = 0,                /*0=�����*/
    bfd_diag_ctrl_detect_exp,            /*1=���Ƽ�ⳬʱ*/
    bfd_diag_echo_failed,                /*2=��������ʧ��*/
    bfd_diag_nbr_session_down,            /*3=�ھӷ�������ĻỰDOWN*/
    bfd_diag_fwd_reset,                    /*4=ת��ƽ������*/
    bfd_diag_path_down,                /*5=·��DOWN*/
    bfd_diag_concat_path_down,            /*6=���ӵ�·��DOWN*/
    bfd_diag_admin_down,                /*7=ϵͳ����ʹ֮DOWN*/
    bfd_diag_rev_concat_path_down        /*8=������·DOWN*/
};

/* ��ǰBFD�Ự��״̬ */
typedef enum en_BfdSta
{
    BFD_ADMINDOWN = 0,
    BFD_DOWN,
    BFD_INIT,
    BFD_UP,
    BFD_STA_BUTT
}en_BfdSta_T;

/*����BFDԭ��*/
typedef enum set_BfdSta
{
    TIMEOUT_DOWN = 5,
    APS_DOWN,
    APS_ADMINDOWN
}set_BfdSta_T;

typedef enum en_bfd_recv_action
{
    /*************** ����ֵ���ܸı�λ�ã����ܸı�ֵ *******************/
    BFD_ACTION_ADMINDOWN = 0,
    BFD_ACTION_DOWN = 1,
    BFD_ACTION_INIT = 2,
    BFD_ACTION_UP = 3,
    
    /***** ����ֵ���ܸı�λ�ã����ܸı�ֵ���¼�ö��ֵ�������¼� *******/
    BFD_ACTION_TIME_OUT,

    /****************** �����ö��ֵ����������� **********************/
    BFD_ACTION_NONE
}EN_BFD_RECV_ACTION;

#ifdef R8000    /* CR 8000 */
/* �ṩ����ģ���BFD״̬ */
typedef enum en_BfdRcordSta
{
    BFD_RECORD_INVALID = 0,/* ��ʼ����Ч */
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


/* Э��ջ�Ự����0/1/2/3= IP/Tunnel/LSP/PW+LSP */
typedef enum en_BfdCfgType
{
    BFD_CFG_IP = 0,
    BFD_CFG_Tunnel, /* rsvp lsp��tunnel */
    BFD_CFG_LSP,    /* ldp lsp */
    BFD_CFG_PW,     /* pw */
    BFD_CFG_INTERFACE /* for interface */
}en_BfdCfgType_T;

/* LSP������ */
typedef enum en_BfdLspType
{
    BFD_LDP_LSP = 1,
    BFD_RSVP_LSP
}en_BfdLspType_T;

/* �Ự���� */
typedef enum en_BfdType
{
    BFD_SIGHOP = 0,  /* ������UDP3784 */
    BFD_MULTIHOP,    /* ������UDP3785 */
    BFD_LAG,         /* LAG, UDP6784 */
    BFD_HOP_BUTT
}en_BfdType_T;

/* FPGA��֡���� */
typedef enum en_BfdPckType
{
    BFD_IP = 0,   
    BFD_LSP,
    BFD_PW_type1, /* ��IPͷ��ACHͷ֡��ʽ���� */
    BFD_PW_type2, /* ��LSP��ǩ��PW��ǩ ��ACHͷ��IPͷ֡��ʽ���� */
    BFD_PCK_BUTT
}en_BfdPckType_T;

/* ���ʱ���� */
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

/**********************״̬д�Ĵ���************************************/
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

/***********************���ͱ��ļĴ����ṹ��****************************/

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
    NBB_USHORT usUnit: 1;  /* оƬ�� */
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
    unsigned short index:   11;     /* FPGA��BFD����λ�õ��������������±� */
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
    NBB_USHORT usPad1:       4;  /* �̶�ΪA */
    NBB_USHORT usPad2:       8;
    NBB_USHORT usVrfH:      4;
}SPM_BFD_FIFO_SVLAN;

typedef struct spm_bfd_fifo_cvlan
{
    NBB_USHORT usPad:       1;
    NBB_USHORT usPktType:   2;  /* �����ͣ�=0����ʾLSP�����=2��ʾ��IP����=1��ʾPW��IP��װ�İ���=3��ʾPW��IP��װ�İ� */
    NBB_USHORT usIpType:    1;  /* ��ʾIPЭ�����ͣ�Ϊ1��ʾIPV6��Ϊ0��ʾIPV4 */
    NBB_USHORT usVrfL:      12;
}SPM_BFD_FIFO_CVLAN;
#endif

typedef struct spm_bfd_up_to_down_sta
{
    NBB_USHORT time_out_count : 4;  /* ��¼���˳�ʱ�澯�������� */
    NBB_USHORT pkt_count      : 4;  /* �Ựup��down��⿪�ش�ʱ���յ��Զ�down���Ĵ������� */
    NBB_USHORT pad2           : 2;  /* ���� */
    NBB_USHORT dig            : 2;  /* �Ựup��down��⿪�ش�ʱ������Ŀ�Ựdownԭ�򣬡�1����ʱdown����3���Զ�down */
    NBB_USHORT pad1           : 3;  /* ���� */
    NBB_USHORT enable         : 1;  /* �Ựup��down��⿪��, ��1��ʹ�ܴ򿪣���0��ʹ�ܹر� */
}SPM_BFD_UP_TO_DOWN_STA;

/* ת��ƽ��ת������,�����չ��8������ */
typedef enum BFD_FWDTYPE
{
    BFD_FWD_IP = 0, /* BFD IPV4ת����΢�����VRFID+IPV4 ADDRESS��·�ɱ� */
    BFD_FWD_LSPID,  /* BFD FOR LSP��VP OAM��΢�����lspidת������ */
    BFD_FWD_TUNNELID, /* BFD FOR TUNNEL��΢�����TunnelIDת������ */
    BFD_FWD_PORT,    /* BFD FOR INTERFACE��VS OAMת����΢�����SVLAN+IPV4 ADDRESS(��һ��)+port���� */
    BFD_FWD_PW,     /* BFD FOR PW,VC OAM,΢�����NHIIDת������ */
    BFD_FWD_LAG,    /* BFD FOR LAG��΢����ݲ�λ�źͶ˿ں�ת������ */
    BFD_FWD_BUTT
}BFD_FWDTYPE_T;

/* DUNEͨ������,�����չ��8������  */
typedef enum BFD_DUNETYPE
{
    BFD_DUNE_FROMC3 = 0,/* BFD�����շ���ҵ����FPGAת�����͵�������(���غ�ҵ����)FPGA��BFD���� */
    BFD_DUNE_TOC3,      /* BFD���ķ��ͷ���������FPGA���͵�ҵ����FPGA��BFD���� */
    BFD_DUNE_LINKLOSS,  /* ҵ����FPGA���͵�����ҵ����FPGA��link loss�澯 */
    BFD_DUNE_BUTT
}BFD_DUNETYPE_T;

/* BFD������Ϣ */
typedef struct bfd_report_info
{
    NBB_ULONG ulLocalDisrim;
    NBB_BYTE  ucSessionState;
    NBB_BYTE  ucDiag;
    NBB_BYTE  ucDMTI;
    NBB_BYTE  ucRMRI;
    NBB_ULONG ulRemoteDisrim;
}BFD_REPORT_INFO;

/* SPU��״̬��Ϣ */
typedef struct bfd_board_info
{
    NBB_BYTE ucBoardState; /* ����λ��Ϣ */
    NBB_BYTE ucBoardBmuState; /* ��������Ϣ */
    NBB_USHORT usTimeCounter;/* �̲���λ��ʱ */
}BFD_BOARD_INFO;

typedef struct bfd_slot_tran_fd
{
    NBB_BOOL foward_id;         /* �洢bfd�������̼��ת������� */
    NBB_BOOL syn_id_fd;         /* �洢bfd�������̼�ͬ��ID����� */
    NBB_BOOL fpga_info_fd;      /* �洢����FPGAЭ�̳������շ����������� */
}BFD_SLOT_TRAN_FD;

/* ������λ��Ϣ */
typedef struct bfd_main_board_state
{
    NBB_BYTE ucMainSlot;    /* ���ò���λʱ��Ϊ0xff������Ϊ��λ�� */
    NBB_BYTE ucBackSlot;    /* ���ò���λʱ��Ϊ0xff������Ϊ��λ�� */
}BFD_MAIN_BOARD_STATE;

/* FPGAʵ�ʹ������շ������ */
typedef struct bfd_fpga_working_info
{
    NBB_USHORT rx_interval[BFD_MAX_SESNUM];  /* �հ���ʱ���� */
    NBB_BYTE   tx_interval[BFD_MAX_SESNUM];  /* ������ʱ���� */
}BFD_FPGA_WORKING_INFO;



/***************************************************************************/
/* BFDģ��ȫ�ֱ���  Added by limingming, 2012/10/8                         */
/***************************************************************************/    
extern NBB_BYTE   g_aucCouterRecord[BFD_MAX_SESNUM]; /* ÿ����Ŀ��¼�Ľ��յ��ĻỰ��Couter�����б仯��˵���յ������±��� */
extern AVLL_TREE  g_stBfdGlbTreeByDis;              /* ȫ�����ô洢,�����������洢 */
extern AVLL_TREE  g_stBfdGlbTreeByIp;               /* BFD FOR IP���ô洢������vrfid+sip�洢 */
extern AVLL_TREE  g_stBfdGlbTreeByIpv6;             /* BFD FOR IPV6���ô洢������vrfid+sipv6�洢 */
extern AVLL_TREE  g_stFwdGlbTreeByDis;              /* ҵ����ת���Ự�洢�������������洢 */
extern AVLL_TREE  g_stBfdGlbExcTreeByDis;       /* ȫ��Խ�����ô洢,�����������洢(����) */

extern NBB_USHORT g_usFwdTreeNodeMaxnum;             /* ת�����������ڵ��� */
extern NBB_USHORT g_usFwdTreeLevel;                  /* ת���������Ĳ�����ÿ��ҵ����֧��2kת������˲���Ϊ11*/
extern NBB_USHORT g_usFwdLspNoMax;                   /* ת�������Ŀ�� */
extern BFD_PUL_FWD_TREE_BASE g_pulFwdTreebase;            /* ת���洢������ÿһ�����Ե�ַ */
extern NBB_USHORT g_usFwdNum;                        /* ת����Ŀ */
extern SPM_OAMTREE_SET  g_stTreeFwdNodeSet;     /* �洢�ڶ��Ŷ������Ľ�����õ����ݣ�2kת������ */

extern SPM_BFD_FWDINFO  g_stBfdfwd[BFD_MAX_FWDNUM];  /* ת������洢 */

extern SPM_BFD_FWDRECORD g_stFwdTxRec[SYS_TOTAL_SLOTNUM]; /* ÿ����ת���ı��ļ�������Ŀ�Ĳ�λ�ż�1Ϊ�����±� */
extern SPM_BFD_FWDRECORD g_stFwdRxRec[SYS_TOTAL_SLOTNUM]; /* ÿ���̽��յ��ĵı��ļ�������Դ��λ�ż�1Ϊ�����±� */
extern SPM_BFD_ID_STORE  g_stBfdIdStore[SYS_MAX_SLOTNUM]; /* �����̴洢��ҵ����ID��Ϣ */
extern NBB_INT linx_fd;                  /* LINX��fd����ȫ�ֱ��� add by ljuan */
extern BFD_PUC_SYN_ID_INFO g_pucSynIdInfo;         /* ͬ��ID���� */
extern NBB_ULONG g_ulSynIdInfoLth;       /* ͬ��ID���ĳ��� */

extern BFD_PUC_ALARM_INFO g_pucAlarmInfo;         /* ״̬�ϱ�Э��ջ */
extern NBB_USHORT g_usAlarmInfoLenth;
extern NBB_BYTE   g_ucCpuTick;          /* �������� */
extern NBB_BOOL   g_BIsRecordDownEvent;
extern NBB_BOOL   g_BIsCloseStateMachine[BFD_MAX_SESNUM];   /* �ر�״̬������ */

extern SPM_BFD_INTERVAL_REPORT g_stintervalinfo[BFD_MAX_SESNUM];/* Ƶ�� */


/* dma ������ */
extern NBB_UINT  g_auiDmaData[BFD_MAX_DMA_NUM];
extern NBB_UINT  g_auiDmaDrimData[BFD_MAX_DMA_DRIM_NUM];

extern unsigned long long g_aullDmaDataInfo[2][2];
extern int g_iDevFd;

extern BFD_BOARD_INFO  g_astBoardState[10];       /* 8010 SPU����λ��Ϣ */


extern BFD_SLOT_TRAN_FD  g_bfd_fd;               /* �洢bfd�������̼��շ�������� */

extern SPM_BFD_SLOT_TRAN_INFO  g_astSlotTranInfo[TRAN_MAX_NUM];   /* �̼�ͨ����Ϣ */

extern BFD_SLOT_TRAN_FD  g_bfd_fd;               /* �洢bfd�������̼��շ�������� */

/*************************************************************************
 * �������ܣ�BFD���հ���ת������ӡ
 * ȡֵ��Χ��0�����ӡ�رգ�1�����ӡ����
 * ע�������
 *************************************************************************/
extern NBB_BYTE g_bfd_send_recv_print_flag;

#ifdef R8000
extern NBB_USHORT g_usNniTreeNodeMaxnum;             /* NNI����������ڵ��� */
extern NBB_USHORT g_usNniTreeLevel;                  /* NNI��������Ĳ�����ÿ��ҵ����֧��1kת������˲���Ϊ10*/
extern NBB_USHORT g_usNniNoMax;                     /* NNI�������Ŀ�� */
extern BFD_PUL_FWD_TREE_BASE g_pulNniTreebase;            /* NNI��洢������ÿһ�����Ե�ַ */
extern NBB_USHORT g_usNniNum;                        /* NNI����Ŀ */
extern SPM_OAMTREE_SET  g_stTreeNniNodeSet;     /* �洢�ڶ���NNI��������Ľ�����õ����ݣ�1kת������ */
extern SPM_BFD_NNIINFO g_stBfdNni[BFD_MAX_NNINUM];  /* NNI�� */
#endif


/***************************���ܺ궨��****************************************/


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

