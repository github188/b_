/***********************************************************************************
 * �� �� ��   : Fhdrv_fap.h
 * �� �� ��   : �Ÿ���
 * ��������   : 2015��1��5��
 * �ļ�����   : QOSӳ������ͷ�ļ�
 * ��Ȩ˵��   : Copyright (c) 2015-2020   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 
***********************************************************************************/

#ifndef _FHDRV_FAP_H
#define _FHDRV_FAP_H


/*�������ش������Ͷ���*/
typedef enum 
{
    FHDRV_E_NONE			=  0,
    FHDRV_E_INTERNAL	    =  -1001,
    FHDRV_E_MEMORY		=  -1002,
    FHDRV_E_UNIT			=  -1003,
    FHDRV_E_PARAM		=  -1004,
    FHDRV_E_EMPTY		=  -1005,
    FHDRV_E_FULL			=  -1006,
    FHDRV_E_NOT_FOUND	=  -1007,
    FHDRV_E_EXISTS		=  -1008,
    FHDRV_E_TIMEOUT		=  -1009,
    FHDRV_E_BUSY			=  -1010,
    FHDRV_E_FAIL			=  -1011,
    FHDRV_E_DISABLED	    =  -1012,
    FHDRV_E_BADID		=  -1013,
    FHDRV_E_RESOURCE	=  -1014,
    FHDRV_E_CONFIG		=  -1015,
    FHDRV_E_UNAVAIL		=  -1016,
    FHDRV_E_INIT			=  -1017,
    FHDRV_E_PORT			=  -1018,
 
    FHDRV_E_LIMIT		=  -1019		/* Must come last */
}FHDRV_FAP_ERROR_T;

/*QOS ӳ�������*/
typedef enum 
{
    FHDRV_L2_INGRESS  =  1,     /*pri->phb+colorӳ���*/
    FHDRV_MPLS_INGRESS	 =  2,  /*exp->phb+colorӳ���*/
    FHDRV_L2_EGRESS	=  3,       /*phb+color->priӳ���*/
    FHDRV_MPLS_EGRESS	=  4,   /*phb+color->expӳ���*/

	FHDRV_ALL_TYPE = 5          /*�������͵�ӳ���*/
}qos_table_t;


#define  FHDRV_UNIT_ONE    0    /*��һƬ��0��ʼ*/
#define  FHDRV_UNIT_TWO    1
#define  FHDRV_UNIT_MAX    2   


#define INGRESS_MAP_ID       0x10020000  /*INGRESS_MAP_ID ��ַ*/
#define MPLS_EGRESS_MAP_ID    0x20040000 /*MPLS_EGRESS_MAP_ID ��ַ*/
#define L2_EGRESS_MAP_ID      0x20010000 /*L2_EGRESS_MAP_ID ��ַ*/

/****************************************************************************************
 * INGRESS ��L2_INGRSS MAP���� 8����MPLS_INGRESS MAP ����7��,������������ӳ����оƬ�е�
 * MAP_ID��ַ��һ���ģ�EGRESS����������QOS map(L2_EGRESS MAP��MPLS_EGRESS MAP)��оƬ�е�
 * MAP_ID��ַ��һ����MPLS_EGRESS MAPоƬ���֧��3��(1,2,3),L2_EGRESS MAPоƬ���֧��14����
*****************************************************************************************/

#define L2_INGRESS_MAX_PROFILE_ID  8 /*ingress qos profile ���ֵ*/
#define L2_INGRESS_MIN_PROFILE_ID  1 /*ingress qos profile ��Сֵ*/
#define MPLS_INGRESS_MAX_PROFILE_ID  7 /*ingress qos profile ���ֵ*/
#define MPLS_INGRESS_MIN_PROFILE_ID  1 /*ingress qos profile ��Сֵ*/


#define L2_EGRESS_MAX_PROFILE_ID  14 /*l2 egress qos profile ���ֵ*/
#define L2_EGRESS_MIN_PROFILE_ID  1 /*l2 egress qos profile ��Сֵ*/
#define MPLS_EGRESS_MAX_PROFILE_ID  3 /*mpls egrss qos profile ���ֵ*/
#define MPLS_EGRESS_MIN_PROFILE_ID  1 /*mpls egrss qos profile ��Сֵ*/

#define INGRSS_ID_OFFSET 8 /*ingress profile_idƫ��ֵ*/
#define EGRESS_ID_OFFSET 3 /*egress profile_idƫ��ֵ*/

#define PRI_MAX_ID  7 /*pri���ֵ*/
#define PRI_MIN_ID  0 /*pri��Сֵ*/
#define COLOR_MAX_ID  2 /*color���ֵ*/
#define COLOR_MIN_ID  0 /*color��Сֵ*/

#define QOS_MAP_NUM  8 

#define NUM_0 0 /*0*/
#define NUM_1 1 /*1*/
#define NUM_2 2 /*2*/
#define NUM_3 3 /*3*/
#define NUM_4 4 /*4*/
#define NUM_5 5 /*5*/
#define NUM_6 6 /*6*/
#define NUM_7 7 /*7*/

#define L2_INGRESS_FLAG   0x404 
#define MPLS_INGRESS_FLAG  0x500 
#define L2_EGRESS_FLAG    0x834 
#define MPLS_EGRESS_FLAG 0xa04 

#define FHDRV_UNIT_VALID(_unit) 	\
	  ((_unit >= FHDRV_UNIT_ONE) && (_unit < FHDRV_UNIT_MAX))

#define FHDRV_PRI_VALID(_pri) 	\
	  ((_pri >= PRI_MIN_ID) && (_pri <= PRI_MAX_ID))

#define FHDRV_COLOR_VALID(_color) 	\
	  ((_color >= COLOR_MAX_ID) && (_color <= COLOR_MAX_ID))

#define L2_INGRESS_PROFILE_VALID(_id) 	\
	  ((_id >= L2_INGRESS_MIN_PROFILE_ID) && (_id <= L2_INGRESS_MAX_PROFILE_ID))

#define MPLS_INGRESS_PROFILE_VALID(_id) 	\
	  ((_id >= MPLS_INGRESS_MIN_PROFILE_ID) && (_id <= MPLS_INGRESS_MAX_PROFILE_ID))


#define L2_EGRESS_PROFILE_VALID(_id) 	\
	  ((_id >= L2_EGRESS_MIN_PROFILE_ID) && (_id <= L2_EGRESS_MAX_PROFILE_ID))

#define MPLS_EGRESS_PROFILE_VALID(_id) 	\
	  ((_id >= MPLS_EGRESS_MIN_PROFILE_ID) && (_id <= MPLS_EGRESS_MAX_PROFILE_ID))

#define FHDRV_FAP_API_CHECK(action)                          \
    if ((rv = (action)) < 0)                       \
    {                                              \
        printf("ERROR: %s %d: %s rv=%d\n",         \
            __FILE__, __LINE__, __FUNCTION__, rv); \
        return rv;                                \
    }

#define FHDRV_NULL_CHECK(_arg) \
	if (NULL == _arg)                           \
	{                                        \
		return FHDRV_E_EMPTY;                  \
	}

typedef struct pcp_to_tc_dp_s
{
  unsigned int map_id; /*�ײ�оƬ������map_idֵ*/
  unsigned char create_flag; /*�ж�map_id�Ƿ񱻴���*/
  char pcp[QOS_MAP_NUM];
  int phb[QOS_MAP_NUM];
  int color[QOS_MAP_NUM];
}pcp_to_tc_dp_t;

typedef struct exp_to_tc_dp_s
{
  unsigned int map_id; /*�ײ�оƬ������map_idֵ*/
  unsigned char create_flag; /*�ж�map_id�Ƿ񱻴���*/
  int exp[QOS_MAP_NUM];
  int phb[QOS_MAP_NUM];
  int color[QOS_MAP_NUM];
}exp_to_tc_dp_t;

typedef struct tc_dp_to_pcp_s
{
  unsigned int map_id; /*�ײ�оƬ������map_idֵ*/
  unsigned char create_flag; /*�ж�map_id�Ƿ񱻴���*/
  char pcp[24];
  int phb[24];
  int color[24];
}tc_dp_to_pcp_t;

typedef struct tc_dp_to_exp_s
{
  unsigned int map_id;  /*�ײ�оƬ������map_idֵ*/
  unsigned char create_flag; /*�ж�map_id�Ƿ񱻴���*/
  int exp[24];
  int phb[24];
  int color[24];
}tc_dp_to_exp_t;

/*Ϊ�����㲻ͬcolorӳ��ɲ�ͬ��exp/pcp �����������չΪ24 1501231 gxmen*/
#if 0
typedef struct tc_dp_to_pcp_s
{
  unsigned int map_id; /*�ײ�оƬ������map_idֵ*/
  unsigned char create_flag; /*�ж�map_id�Ƿ񱻴���*/
  char pcp[QOS_MAP_NUM];
  int phb[QOS_MAP_NUM];
  int color[QOS_MAP_NUM];
}tc_dp_to_pcp_t;

typedef struct tc_dp_to_exp_s
{
  unsigned int map_id;  /*�ײ�оƬ������map_idֵ*/
  unsigned char create_flag; /*�ж�map_id�Ƿ񱻴���*/
  int exp[QOS_MAP_NUM];
  int phb[QOS_MAP_NUM];
  int color[QOS_MAP_NUM];
}tc_dp_to_exp_t;

#endif
/***************************************************************************
 * �������鱣��Ӧ�ò㴫�ݵ�QOSӳ����Ϣ,�����ײ㴴����map_id;����QOS mapӦ��
 * �㴫��profileֵ����0��ʼ��l2_ingress_map map_id��Χ0x10020001~0x10020008;
 * mpls_ingress_map map_id��Χ0x10020009~0x10020000f��l2_egress_map map_id
 * ��Χ0x20010001~0x2001000e;mpls_egress_map map_id��Χ:0x20040001~0x20040003.
****************************************************************************/

extern pcp_to_tc_dp_t g_l2_ingress_map[L2_INGRESS_MAX_PROFILE_ID]; /* pri->tc+dp */
extern exp_to_tc_dp_t g_mpls_ingress_map[MPLS_INGRESS_MAX_PROFILE_ID]; /* exp->tc+dp */
extern tc_dp_to_pcp_t g_l2_egress_map[L2_EGRESS_MAX_PROFILE_ID]; /* tc+dp->pri */
extern tc_dp_to_exp_t g_mpls_egress_map[MPLS_EGRESS_MAX_PROFILE_ID]; /* tc+dp->exp */


/***************************************************************************
 * ������ACL������������------gxmen 20151019
****************************************************************************/
/*
 * General Utility Macros
 */

#define UNITS_MAX 2

#define ENTRY_MAX 2048

#define INT_MASK 0xffffffff

#define SHORT_MASK 0xffff

#define CHAR_MASK 0xff

#define VLAN_DEFAULT_MASK 0xfff

#define PW_DEFAULT_MASK 0xfffff

#define TUNNEL_DEFAULT_MASK 0xfffff

#define PRI_DEFAULT_MASK 0X7

#define L4PORT_DEFAULT_MASK 0xff

#define DSCP_DEFAULT_MASK 0x3f

#define FHDRV_FIELD_ENTRY_PRIO_DEFAULT 0 /*entry Ĭ�����ȼ�*/

#define DRV_FAP_UNIT_CHECK(unit) \
    do {  \
	    if (((unit) < 0) || ((unit) >= UNITS_MAX)) \
		{ printf("unit exceed 2 !!!\n"); \
		  return FHDRV_E_PARAM; }  \
    } while (0)

#define DRV_FAP_NULL_CHECK(arg) \
    do {  \
        if ((arg) == NULL) \
        { printf("pointer is null !!!\n"); \
          return FHDRV_E_PARAM; } \
    } while (0)

#define DRV_FAP_METER_PARAM_CHECK(a,b) \
    do {  \
        if (a > b) \
        { printf("The commit rate exceed peak rate!!! ckbits_sec=%d pkbits_sec%d\n",a,b); \
          return FHDRV_E_PARAM; } \
    } while (0)
		
#define DRV_FAP_METER_SENSE_CHECK(arg) \
    do {  \
        if (arg != 1 && arg != 2) \
        { printf("The sence is not exited!! sense=%d\n",arg); \
          return FHDRV_E_PARAM; } \
    } while (0)

#define DRV_MAC_IS_ZERO(_mac_)  \
    (((_mac_)[0] | (_mac_)[1] | (_mac_)[2] | \
      (_mac_)[3] | (_mac_)[4] | (_mac_)[5]) == 0) 

#define DRV_MACMASK_IS_VALID(_macmask_)  \
    (((_macmask_)[0] & (_macmask_)[1] & (_macmask_)[2] & \
      (_macmask_)[3] & (_macmask_)[4] & (_macmask_)[5]) != 0xff) 


typedef unsigned char drv_mac_t[6];

typedef enum drv_meter_sence_e 
{
	DRV_METER_COLOR_AWARE = 1,
	DRV_METER_COLOR_BLIND = 2,
}drv_meter_sence_t;

/*��������ö�ٱ��������Բ��ã�Ӧ�ò��������*/
typedef enum drv_acl_action_e 
{
    /* δʹ�ö��� */
	DRV_ACL_ACTION_UNUSED = 0,

	/* �ض��������ض��򵥲���*/
    DRV_ACL_ACTION_DROP = 1,

	/* �������������������� */
    DRV_ACL_ACTION_REDIRECT = 2,

	/* Trap��������Trap codeӦ������ */
    DRV_ACL_ACTION_TRAP = 3,

	/*����ACLƥ���޸�TC*/
    DRV_ACL_ASSIGN_TC = 4,

	/*����ACLƥ���޸�DP*/
    DRV_ACL_ASSIGN_DP = 5,

	/*����ACLƥ��ͳ��*/
    DRV_ACL_ACTION_STAT = 6,

	/*����ACLƥ��ͳ��*/
    DRV_ACL_ACTION_METER = 7,

    /* �������� */
    DRV_ACL_ACTION_MAX
}drv_acl_action_t;

typedef enum drv_acl_rule_e 
{
    /* ������˿�ƥ��. */
    DRV_ACL_RULE_SYSPORT = 1,

	/* �������VLANƥ��. */
    DRV_ACL_RULE_VLANID = 2,

	/* �������VLAN���ȼ�ƥ��. */
    DRV_ACL_RULE_VLANPRI = 3,

	/* ����ԴMACƥ��. */
    DRV_ACL_RULE_SRCMAC = 4,

	/* ����Ŀ��MACƥ��. */
    DRV_ACL_RULE_DSTMAC = 5,

	/* ����ԴIPƥ��. */
    DRV_ACL_RULE_SRCIP = 6,

	/* ����Ŀ��IPƥ��. */
    DRV_ACL_RULE_DSTIP = 7,

	/* �����Ĳ�Դ�˿ں�ƥ��. */
    DRV_ACL_RULE_L4SRCPORT = 8,

	/* �����Ĳ�Ŀ�Ķ˿ں�ƥ��. */
    DRV_ACL_RULE_L4DSTPORT = 9,

	/* �����Ĳ�Ŀ�Ķ˿ں�ƥ��. */
    DRV_ACL_RULE_DSCP = 10,

	/* �����Ĳ�Ŀ�Ķ˿ں�ƥ��. */
    DRV_ACL_RULE_PW = 11,
   
    /* �������� */
    DRV_ACL_RULE_MAX
}drv_acl_rule_t;

/*Ӧ�ò��ע���������ṹ��*/
typedef struct drv_acl_rule_key_s
{
    /* ������Чbit��Χ�����Ӧ�����й� */
	int entryprio;/*entry���ȼ���Ĭ��ֵ0��ֵԽ�����ȼ�Խ��*/
	int port; /*local port*/
	int port_mask;
	unsigned char vlan_pri; 
	unsigned char pri_mask;/* PRI����bit,�������bit��Ч,����������ͬ */
	unsigned short vlan_id;
	unsigned short vlan_mask;/* ��Ч��Χ������ͬ */
	unsigned int srcip;
	unsigned int srcip_mask;/* ��Ч��Χ������ͬ */
	unsigned int dstip;
	unsigned int dstip_mask;/* ��Ч��Χ������ͬ */
	int l4srcport;
	int l4srcport_mask;/* ��Ч��Χ������ͬ */
 	int l4dstport;
 	int l4dstport_mask;/* ��Ч��Χ������ͬ */
	unsigned int assign_tc; /* TC -> PHB   */
	unsigned int assign_dp; /* DP -> COLOR */
	unsigned int redirect_port; /* LOCAL-PORT */
	unsigned int redirect_modid;/*�ض�����modid*/
	unsigned char dscp;
	unsigned char dscp_mask; /* ��Ч��Χ������ͬ */
	int statid;    /* COUNTER ID , Ӧ�ò㲻�ù�*/
	int policerId; /* METER ID , Ӧ�ò㲻�ù�*/
	int ckbits_sec; /* CIR */
	int pkbits_sec; /* PIR */
	unsigned int pw; /*pw lable*/
	unsigned int pw_mask;
	unsigned int tunnel; /*tunnel lable*/
	unsigned int tunnel_mask;
	drv_meter_sence_t sence;/* ACL��METER��ɫ�п��� */
	drv_mac_t src_mac;
	drv_mac_t srcmac_mask;
	drv_mac_t dst_mac; 
	drv_mac_t dstmac_mask; 
 }drv_acl_rule_key_t;

typedef struct drv_acl_action_list_s
{	
	/* ���б�ʶ��1��Ч */
	unsigned char PermitFlag;    /* ��DROP����   */
	unsigned char DropFlag;      /* ��PERMIT���� */
	unsigned char RedirectFlag;  /*�ض���flag����1������Ч*/
	unsigned char AssignTcFlag;  /*ָ��TCflag����1������Ч*/
	unsigned char AssignDpFlag;  /*ָ��DPflag����1������Ч*/
	unsigned char StatFlag;	     /*����flag����1������Ч*/
	unsigned char MeterFlag;     /*meter flag����1������Ч*/
	unsigned char WhiteListFlag;  /*������flag*/
	
}drv_acl_action_list_t;

/* ��������������Ϣ�ṹ�壬Ӧ�ò�������� */
typedef struct EntryInfo_s
{
    int use_flag;
	int entryId;
    int groupId;
    drv_acl_rule_key_t matchkey;
	drv_acl_action_list_t actionlist;
} EntryInfo_t;

typedef struct service_stat_s
{
  unsigned char clean_flag;
  unsigned char lsr_flag;
  unsigned char mspw_flag;
  unsigned int high_pkt_cnt; 
  unsigned int low_pkt_cnt; 
  unsigned int high_byte_cnt;
  unsigned int low_byte_cnt;
  unsigned int high_drop_pkt_cnt; 
  unsigned int low_drop_pkt_cnt; 
  unsigned int high_drop_byte_cnt; 
  unsigned int low_drop_byte_cnt; 
}service_stat_t;

typedef enum drv_drop_clor_e 
{
	GREEN_DROP = 1,
    YELLOW_DROP = 2,
    RED_DROP = 3,
    NONE_DROP = 4

}drv_drop_clor_t;

/********************************************************************************************
 ********************************  USER DEFINE QUALIFIER PMF  *******************************
 ********************************************************************************************/
typedef struct drv_udf_key_s
{
	int inport; /*local port*/
	int mirror_type_flag; /*local port*/
	int entryprio;/*entry���ȼ���Ĭ��ֵ0��ֵԽ�����ȼ�Խ��*/
	unsigned int pw;/*pw lable*/
	unsigned int pw_lif;/*pw lable*/
	unsigned int tunnel;/*tunnel lable*/
	unsigned int ach;/*oam ach*/
	unsigned char igmp_vlannum;
	unsigned char iptype[4];
	unsigned char iptype_mask[4];
    unsigned char igmpver[4];
    unsigned char igmpver_mask[4];
	unsigned char channel_type[4];
	unsigned char channel_type_mask[4];
	unsigned char OpCode[4];
	unsigned char OpCode_mask[4];
	unsigned char id_sub_type[4];
	unsigned char id_sub_type_mask[4];
    unsigned char node_id[4];
    unsigned char node_id_mask[4];
    unsigned short vlan_id;
	unsigned short ethertype; /*ETHERNET OAM ��ҵ��*/
	unsigned char subtype[4]; /*EFM SUBTYPE*/
	unsigned char subtype_mask[4]; /*EFM SUBTYPE mask*/
	unsigned int redirect_port;/*�ض���˿�,local port*/
	unsigned int redirect_dest_port;/*����˿ڣ�local port*/
	unsigned int redirect_dest_modid;/*������modid*/
	unsigned int mirror_dest_port;/*����˿ڣ�local port*/
	unsigned int mirror_dest_modid;/*������modid*/

}drv_udf_key_t;

typedef struct drv_udf_action_s
{
	unsigned char DropFlag;/*����flag����1������Ч*/      
	unsigned char RedirectFlag;/*�ض���flag����1������Ч*/
	unsigned char MirrorFlag;/*����flag����1������Ч*/
} drv_udf_action_t;

/******************************************************************************
** �� �� �� ��fhdrv_fap_qos_set_pcp_ingress()
** �������� ���������޸�INGRESS��ĳ��profile pcp��phb��color��ӳ��
** ��    �� ��unit				оƬID,��0��ʼ
**		   	  profile		    ȡֵ��Χ(0~7,�����߽�ֵ)
**            *pcp              ����Ϊ8��char��������,�����Աȡֵ0~7
**            *phb              ����Ϊ8��int��������,�����Աȡֵ0~7
**            *color            ����Ϊ8��int��������,�����Աȡֵ0~2
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.1.4
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ����ʾ�� :{
                char pcp[QOS_MAP_NUM] = {0,1,2,3,4,5,6,7};
                int phb[QOS_MAP_NUM] = {4,2,1,5,6,7,0,3};
                int color[QOS_MAP_NUM] = {0,0,0,0,0,0,0,0};

                fhdrv_fap_qos_set_pcp_ingress(unit,profile,pcp,phb,color);
             }
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_qos_set_pcp_ingress(int unit,
    unsigned char profile,char *pcp,int *phb,int *color);

/******************************************************************************
** �� �� �� ��fhdrv_fap_qos_set_exp_ingress()
** �������� ���������޸�INGRESS��ĳ��profile exp��phb��color��ӳ��
** ��    �� ��unit				оƬID,��0��ʼ
**		   	  profile		    ȡֵ��Χ(0~6�������߽�ֵ)
**            *exp              ����Ϊ8��int��������,�����Աȡֵ0~7
**            *phb              ����Ϊ8��int��������,�����Աȡֵ0~7
**            *color            ����Ϊ8��int��������,�����Աȡֵ0~2
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.1.4
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ����ʾ�� :{
                int exp[QOS_MAP_NUM] = {0,1,2,3,4,5,6,7};
                int phb[QOS_MAP_NUM] = {6,3,0,2,7,4,5,1};
                int color[QOS_MAP_NUM] = {0,0,0,0,0,0,0,0};

                fhdrv_fap_qos_set_exp_ingress(unit,profile,exp,phb,color);
             }
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_qos_set_exp_ingress(int unit,unsigned char profile,
    int *exp,int *phb,int *color);

/******************************************************************************
** �� �� �� ��fhdrv_fap_qos_set_pcp_egress()
** �������� ���������޸�EGRESS��ĳ��profile phb��color��pcp��ӳ��
** ��    �� ��unit				оƬID,��0��ʼ
**		   	  profile		    ȡֵ��Χ(0~13�������߽�ֵ)
**            *pcp              ����Ϊ8��char��������,�����Աȡֵ0~7
**            *phb              ����Ϊ8��int��������,�����Աȡֵ0~7
**            *color            ����Ϊ8��int��������,�����Աȡֵ0~2
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.1.4
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ����ʾ�� :{
                char pcp[QOS_MAP_NUM] = {0,1,2,3,4,5,6,7};
                int phb[QOS_MAP_NUM] = {4,1,5,2,3,7,0,6};
                int color[QOS_MAP_NUM] = {0,0,0,0,0,0,0,0};

                fhdrv_fap_qos_set_pcp_egress(unit,profile,pcp,phb,color);
             }
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_qos_set_pcp_egress(int unit, unsigned char profile,
    char *pcp);

/******************************************************************************
** �� �� �� ��fhdrv_fap_qos_set_exp_egress()
** �������� ���������޸�EGRESS��ĳ��profile phb��color��exp��ӳ��
** ��    �� ��unit				оƬID,��0��ʼ
**		   	  profile		    ȡֵ��Χ(0~2�������߽�ֵ)
**            *exp              ����Ϊ8��int��������,�����Աȡֵ0~7
**            *phb              ����Ϊ8��int��������,�����Աȡֵ0~7
**            *color            ����Ϊ8��int��������,�����Աȡֵ0~2
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.1.4
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ����ʾ�� :{
                int exp[QOS_MAP_NUM] = {0,1,2,3,4,5,6,7};
                int phb[QOS_MAP_NUM] = {7,4,5,1,3,2,0,6};
                int color[QOS_MAP_NUM] = {0,0,0,0,0,0,0,0};

                fhdrv_fap_qos_set_exp_egress(unit,profile,exp,phb,color);
             }
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_qos_set_exp_egress(int unit,unsigned char profile,
    int *exp);

/********************************************************************************
** �� �� �� ��fhdrv_fap_qos_get_profile()
** �������� ����ȡĳ��qos profileӳ���ϵ
** ��    �� ��unit				оƬID,��0��ʼ
**		   	  profile		    ȡֵ��Χ(0~13�������߽�ֵ)
**            table_type        ȡֵ��Χ(1~5)�����������qos_table_t����
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.1.4
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :���⺯��
** ����ʾ�� : 1����ȡ8021p��PHBӳ���(profile=3)
                fhdrv_fap_qos_get_profile(0,3,1);
              2����ȡEXP��PHBӳ���(profile=4)
                fhdrv_fap_qos_get_profile(0,4,2);              
              3����ȡPHB��8021pӳ���(profile=2)
                fhdrv_fap_qos_get_profile(0,2,3);              
              4����ȡPHB��EXPӳ���(profile=1)
                fhdrv_fap_qos_get_profile(0,1,4); 
              5����ȡ����ӳ���
                fhdrv_fap_qos_get_profile(0,0,5);                                
** ��    �� ��1.0
*********************************************************************************/

extern int fhdrv_fap_qos_get_profile (int unit, unsigned char profile,
	qos_table_t table_type);

/********************************************************************************
** �� �� �� ��fhdrv_fap_qos_destroy_profile()
** �������� ��ɾ��ĳ��qos profile
** ��    �� ��unit				оƬID,��0��ʼ
**		   	  profile		    ȡֵ��Χ(0~13�������߽�ֵ)
**            table_type        ȡֵ��Χ(1~4)�����������qos_table_t����
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.1.4
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע : һ�㲻����øú�����QOS MAP�ڵײ㽨�ˣ�һ��ֻ���޸ġ�
** ����ʾ�� : 1��ɾ��8021p��PHBӳ���(profile=3)
                fhdrv_fap_qos_destroy_profile(0,3,1);
              2��ɾ��EXP��PHBӳ���(profile=4)
                fhdrv_fap_qos_destroy_profile(0,4,2);              
              3��ɾ��PHB��8021pӳ���(profile=2)
                fhdrv_fap_qos_destroy_profile(0,2,3);              
              4��ɾ��PHB��EXPӳ���(profile=1)
                fhdrv_fap_qos_destroy_profile(0,1,4); 
** ��    �� ��1.0
*********************************************************************************/
extern int fhdrv_fap_qos_destroy_profile(int unit, unsigned char profile,
	qos_table_t table_type);

/*******************************************************************************
** �� �� �� ��fhdrv_fap_qos_get_chip_map()
** �������� �����⺯��������flags��ӡĳ��map_idоƬ�ײ�QOS MAPӳ���ϵ��
** ��    �� ��unit			оƬID,��0��ʼ
**		   	  flags		    L2_INGRESS flags=0x404; 
**                          MPLS_INGRESS flags=0x500;
**                          L2_EGRESS flags=0x834;
**                          MPLS_EGRESS flags=0xa04;ע:ĿǰSDK��֧�ָ�flag�Ĳ�ѯ�� 
**            map_id        ��ȫ�ֱ���g_qos_arad_debug��Ϊ1�������ڴ������޸�ʱ��
**                          ȡ��Ӧ��map_id.
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.1.4
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ����ʾ�� : 1��оƬ�ײ���л�ȡ8021p��PHBӳ���(L2_INGRESS,map_id=0x10020002)
                fhdrv_fap_qos_get_chip_map(0,0x404,0x10020002);
              2��оƬ�ײ���л�ȡEXP��PHBӳ���(MPLS_INGRESS,map_id=0x1002000a)
                fhdrv_fap_qos_get_chip_map(0,0x500,0x1002000a);
              3��оƬ�ײ���л�ȡPHB��8021pӳ���(L2_EGRESS,map_id=0x20010002)
                fhdrv_fap_qos_get_chip_map(0,0x834,0x20010002);
              4��ע:ĿǰSDK��֧��flags=0xa04�Ĳ�ѯ�� 
** ��    �� ��1.0
*********************************************************************************/
extern int fhdrv_fap_qos_get_chip_map (int unit, int flags, int map_id);


/*******************************************************************************
 * ������ACL������������------gxmen 20151019
*********************************************************************************/

/******************************************************************************
** �� �� �� ��fhdrv_fap_acl_init()
** �������� ��ACL��ʼ��->����GROUP,��ʼ��ruleinfo���顣
** ��    �� ��unit
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :PP������ʼ���ǵ���
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_acl_init(int unit);

/******************************************************************************
** �� �� �� ��fhdrv_fap_acl_group_destroy()
** �������� ���ײ�ɾ��GROUP
** ��    �� ��unit
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_acl_group_destroy(int unit);

/******************************************************************************

                         ����ACL�ӿڹ�Ӧ�ò����
                    
*******************************************************************************/
/******************************************************************************
** �� �� �� ��fhdrv_fap_acl_entry_create()
** �������� ������ACL entry
** ��    �� ��unit		оƬID,��0��ʼ
**		   	  rule		���е�����Ĭ������Ϊȫ1������Ĭ��ֵΪ0�������ײ�
**                      ��⵽��0ֵ����ΪҪƥ��ù���
**            action    Ĭ��Ϊȫ0�ṹ�������ײ��⵽ĳ������flag��1����
**                      ΪҪִ�иö�����
** ��    �� ����
** ��    �� ������ֵΪentry_idֵ,��0��ʼ,С��0Ϊ�쳣
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_acl_entry_create(int unit, drv_acl_rule_key_t *rule, drv_acl_action_list_t *action);

/******************************************************************************
** �� �� �� ��fhdrv_fap_acl_stat_get()
** �������� ����ȡ����counter ��entry����(����packet)
** ��    �� ��unit		оƬID,��0��ʼ
**		   	  entry     entry_idֵ
** ��    �� ����
** ��    �� �����ؼ���ֵ
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_acl_stat_get(int unit, int entry, service_stat_t *stat);

/******************************************************************************
** �� �� �� ��fhdrv_fap_acl_entry_destroy()
** �������� ��ɾ�� һ��ACL entry
** ��    �� ��unit		оƬID,��0��ʼ
**		   	  entry     entry_idֵ
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_acl_entry_destroy(int unit, int entry_id);

/******************************************************************************
** �� �� �� ��fhdrv_fap_acl_entryid_show()
** �������� ����ʾACL GROUP�д�����entry_id
** ��    �� ��unit		оƬID,��0��ʼ
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern void fhdrv_fap_acl_entryid_show(int unit);

/******************************************************************************
** �� �� �� ��fhdrv_fap_acl_entryid_show()
** �������� ��ɾ��ACL GROUP�д���������entry
** ��    �� ��unit		оƬID,��0��ʼ
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_acl_entry_destroy_all(int unit);

/******************************************************************************
** �� �� �� ��fhdrv_fap_acl_entryinfo_dump()
** �������� ����ӡһ��ACLӦ�ò�������Ϣ
** ��    �� ��unit		оƬID,��0��ʼ
**          ��entry_id	��ѯ��entry_id
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_acl_entryinfo_dump(int unit,int entry_id);

/******************************************************************************
** �� �� �� ��fhdrv_fap_acl_entryinfo_dump_all()
** �������� ����ӡ����ACLӦ�ò�������Ϣ
** ��    �� ��unit		оƬID,��0��ʼ
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_acl_entryinfo_dump_all(int unit);

/******************************************************************************
** �� �� �� ��fhdrv_fap_acl_entryinfo_chip_dump()
** �������� ����ӡоƬ�ײ�һ��entry��������Ϣ
** ��    �� �� unit		оƬID,��0��ʼ
** 			�� entry    entry_id
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_acl_entryinfo_chip_dump(int unit, int entry);

/******************************************************************************
** �� �� �� ��fhdrv_fap_acl_groupinfo_chip_dump()
** �������� ����ӡоƬ�ײ�group������Ϣ
** ��    �� ��unit		оƬID,��0��ʼ
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_acl_groupinfo_chip_dump(int unit);

/******************************************************************************
** �� �� �� ��fhdrv_fap_acl_policer_set()
** �������� ���޸�meter����
** ��    �� ��unit				оƬID,��0��ʼ
**		   	  entry_id		    ���ص�entry_id
**            ckbits_sec        meter���õı�֤����,��λkbits
**            pkbits_sec        meter���õķ�ֵ����,��λkbits
**            sence             meterɫ��/ɫäģʽѡ�� 1����ɫ�� 2����ɫä
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_acl_policer_set(int unit, int entry_id, int ckbits_sec, 
	int pkbits_sec, drv_meter_sence_t sence);

/******************************************************************************
** �� �� �� ��fhdrv_fap_whitelist_default_entry()
** �������� ������������Ĭ��ACL entry
** ��    �� ��unit		оƬID,��0��ʼ
**		   	  rule		���е�����Ĭ������Ϊȫ1������Ĭ��ֵΪ0�������ײ�
**                      ��⵽��0ֵ����ΪҪƥ��ù���
**            action    Ĭ��Ϊȫ0�ṹ�������ײ��⵽ĳ������flag��1����
**                      ΪҪִ�иö�����
** ��    �� ����
** ��    �� ������ֵΪentry_idֵ
** ����  �� ��gxmen
** �ա�  �� ��2015.12.07
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_whitelist_default_entry(int unit, drv_acl_rule_key_t *rule, drv_acl_action_list_t *action);

/******************************************************************************
** �� �� �� ��fhdrv_fap_baselif_stat_get()
** �������� ������lif_id������ͳ�ƻ�ȡ�ӿ�
** ��    �� ��unit		  оƬID,��0��ʼ
**            is_ingress  1:���ͳ�� 0:����ͳ��
**            is_uni      1:UNI��ͳ�� 0:NNI��ͳ��
**            lif_id      lif idֵ
**            stat        ���ڱ���ͳ��ֵ�Ľṹ��ָ��
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.12.08
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_baselif_stat_get(int unit, unsigned char is_ingress, unsigned char is_uni, 
	unsigned int lif_id, service_stat_t *stat);

/******************************************************************************
** �� �� �� ��fhdrv_fap_baselif_stat_show()
** �������� ����ʾ����lif_id������ͳ��
** ��    �� ��unit		  оƬID,��0��ʼ
**            is_ingress  1:���ͳ�� 0:����ͳ��
**            is_uni      1:UNI��ͳ�� 0:NNI��ͳ��
**            lif_id      lif idֵ
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.12.08
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_baselif_stat_show(int unit, int is_ingress, unsigned char is_uni, unsigned int lif_id,
	unsigned char lsr_flag, unsigned char mspw_flag);

/******************************************************************************
** �� �� �� ��fhdrv_fap_service_policer_set()
** �������� ���޸�ҵ��meter����
** ��    �� ��unit				оƬID,��0��ʼ
**		   	  is_uni		    1:UNI 0:NNI
**		   	  lif_id		    AC_LIFID/PW_LIFID
**            ckbits_sec        meter���õı�֤����,��λkbits
**            pkbits_sec        meter���õķ�ֵ����,��λkbits
**            sence             meterɫ��/ɫäģʽѡ�� 1����ɫ�� 2����ɫä
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_service_policer_set(int unit, unsigned char is_uni, int lif_id, int ckbits_sec, 
	int pkbits_sec, drv_meter_sence_t sence);

/******************************************************************************
** �� �� �� ��ApiInitPmfModule()
** �������� ��Ӧ�ò����PMF��ʼ���ӿ�
** ��    �� ��unit   
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int ApiInitPmfModule(int unit);

/********************************************************************************************
 ********************************  USER DEFINE QUALIFIER PMF  *******************************
 ********************************************************************************************/

/******************************************************************************
** �� �� �� ��fhdrv_fap_acl_udf_init()
** �������� ����ʼ���Զ���ƥ���GROUP
** ��    �� ��unit			оƬID,��0��ʼ
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_acl_udf_init(int unit);

/******************************************************************************
** �� �� �� ��fhdrv_fap_udf_entry_create()
** �������� ������ACL entry
** ��    �� ��unit		оƬID,��0��ʼ
**		   	  key		�����ײ��⵽��0ֵ����ΪҪƥ��ù���
**            action    Ĭ��Ϊȫ0�ṹ�������ײ��⵽ĳ������flag��1����
**                      ΪҪִ�иö�����
** ��    �� ����
** ��    �� ������ֵΪentry_idֵ
** ����  �� ��gxmen
** �ա�  �� ��2015.12.10
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_udf_entry_create(int unit, drv_udf_key_t* key, drv_udf_action_t* action);

/******************************************************************************
** �� �� �� ��fhdrv_fap_udf_entry_destroy()
** �������� ��ɾ�� �Զ��� qualifier entry
** ��    �� ��unit		оƬID,��0��ʼ
**		   	  entry     entry_idֵ
** ��    �� ����
** ��    �� ��entry_id
** ����  �� ��gxmen
** �ա�  �� ��2015.12.10
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_udf_entry_destroy(int unit,int entry);

/******************************************************************************
** �� �� �� ��fhdrv_fap_cosq_discard_set()
** �������� ��оƬ��ɫ��������
** ��    �� ��unit		оƬID,��0��ʼ
**            color     ������ɫ
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_cosq_discard_set(int unit, drv_drop_clor_t color);

/******************************************************************************
** �� �� �� ��fhdrv_fap_policer_adjust_set()
** �������� ������meter����
** ��    �� ��unit				оƬID,��0��ʼ
**            port              local port
**            value             ����ֵ
** ��    �� ����
** ��    �� ������Ϊ0��ɹ�������Ϊʧ��
** ����  �� ��gxmen
** �ա�  �� ��2015.10.15
** �ޡ�  �� ��
** �ա�  �� ��
** �޸�˵�� ��
** ��    ע :
** ��    �� ��1.0
*******************************************************************************/
extern int fhdrv_fap_policer_adjust_set(int unit, int port, int value);


#endif /*_FHDRV_FAP_H*/

