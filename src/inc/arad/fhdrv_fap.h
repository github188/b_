/***********************************************************************************
 * 文 件 名   : Fhdrv_fap.h
 * 负 责 人   : 门高鑫
 * 创建日期   : 2015年1月5日
 * 文件描述   : QOS映射驱动头文件
 * 版权说明   : Copyright (c) 2015-2020   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 
***********************************************************************************/

#ifndef _FHDRV_FAP_H
#define _FHDRV_FAP_H


/*函数返回错误类型定义*/
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

/*QOS 映射表类型*/
typedef enum 
{
    FHDRV_L2_INGRESS  =  1,     /*pri->phb+color映射表*/
    FHDRV_MPLS_INGRESS	 =  2,  /*exp->phb+color映射表*/
    FHDRV_L2_EGRESS	=  3,       /*phb+color->pri映射表*/
    FHDRV_MPLS_EGRESS	=  4,   /*phb+color->exp映射表*/

	FHDRV_ALL_TYPE = 5          /*所有类型的映射表*/
}qos_table_t;


#define  FHDRV_UNIT_ONE    0    /*第一片从0开始*/
#define  FHDRV_UNIT_TWO    1
#define  FHDRV_UNIT_MAX    2   


#define INGRESS_MAP_ID       0x10020000  /*INGRESS_MAP_ID 基址*/
#define MPLS_EGRESS_MAP_ID    0x20040000 /*MPLS_EGRESS_MAP_ID 基址*/
#define L2_EGRESS_MAP_ID      0x20010000 /*L2_EGRESS_MAP_ID 基址*/

/****************************************************************************************
 * INGRESS 侧L2_INGRSS MAP分配 8个，MPLS_INGRESS MAP 分配7个,上述两种类型映射在芯片中的
 * MAP_ID基址是一样的；EGRESS侧两种类型QOS map(L2_EGRESS MAP与MPLS_EGRESS MAP)在芯片中的
 * MAP_ID基址不一样，MPLS_EGRESS MAP芯片最多支持3个(1,2,3),L2_EGRESS MAP芯片最多支持14个。
*****************************************************************************************/

#define L2_INGRESS_MAX_PROFILE_ID  8 /*ingress qos profile 最大值*/
#define L2_INGRESS_MIN_PROFILE_ID  1 /*ingress qos profile 最小值*/
#define MPLS_INGRESS_MAX_PROFILE_ID  7 /*ingress qos profile 最大值*/
#define MPLS_INGRESS_MIN_PROFILE_ID  1 /*ingress qos profile 最小值*/


#define L2_EGRESS_MAX_PROFILE_ID  14 /*l2 egress qos profile 最大值*/
#define L2_EGRESS_MIN_PROFILE_ID  1 /*l2 egress qos profile 最小值*/
#define MPLS_EGRESS_MAX_PROFILE_ID  3 /*mpls egrss qos profile 最大值*/
#define MPLS_EGRESS_MIN_PROFILE_ID  1 /*mpls egrss qos profile 最小值*/

#define INGRSS_ID_OFFSET 8 /*ingress profile_id偏移值*/
#define EGRESS_ID_OFFSET 3 /*egress profile_id偏移值*/

#define PRI_MAX_ID  7 /*pri最大值*/
#define PRI_MIN_ID  0 /*pri最小值*/
#define COLOR_MAX_ID  2 /*color最大值*/
#define COLOR_MIN_ID  0 /*color最小值*/

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
  unsigned int map_id; /*底层芯片创建的map_id值*/
  unsigned char create_flag; /*判断map_id是否被创建*/
  char pcp[QOS_MAP_NUM];
  int phb[QOS_MAP_NUM];
  int color[QOS_MAP_NUM];
}pcp_to_tc_dp_t;

typedef struct exp_to_tc_dp_s
{
  unsigned int map_id; /*底层芯片创建的map_id值*/
  unsigned char create_flag; /*判断map_id是否被创建*/
  int exp[QOS_MAP_NUM];
  int phb[QOS_MAP_NUM];
  int color[QOS_MAP_NUM];
}exp_to_tc_dp_t;

typedef struct tc_dp_to_pcp_s
{
  unsigned int map_id; /*底层芯片创建的map_id值*/
  unsigned char create_flag; /*判断map_id是否被创建*/
  char pcp[24];
  int phb[24];
  int color[24];
}tc_dp_to_pcp_t;

typedef struct tc_dp_to_exp_s
{
  unsigned int map_id;  /*底层芯片创建的map_id值*/
  unsigned char create_flag; /*判断map_id是否被创建*/
  int exp[24];
  int phb[24];
  int color[24];
}tc_dp_to_exp_t;

/*为了满足不同color映射成不同的exp/pcp 将数组个数扩展为24 1501231 gxmen*/
#if 0
typedef struct tc_dp_to_pcp_s
{
  unsigned int map_id; /*底层芯片创建的map_id值*/
  unsigned char create_flag; /*判断map_id是否被创建*/
  char pcp[QOS_MAP_NUM];
  int phb[QOS_MAP_NUM];
  int color[QOS_MAP_NUM];
}tc_dp_to_pcp_t;

typedef struct tc_dp_to_exp_s
{
  unsigned int map_id;  /*底层芯片创建的map_id值*/
  unsigned char create_flag; /*判断map_id是否被创建*/
  int exp[QOS_MAP_NUM];
  int phb[QOS_MAP_NUM];
  int color[QOS_MAP_NUM];
}tc_dp_to_exp_t;

#endif
/***************************************************************************
 * 以下数组保存应用层传递的QOS映射信息,包括底层创建的map_id;几种QOS map应用
 * 层传的profile值都从0开始，l2_ingress_map map_id范围0x10020001~0x10020008;
 * mpls_ingress_map map_id范围0x10020009~0x10020000f；l2_egress_map map_id
 * 范围0x20010001~0x2001000e;mpls_egress_map map_id范围:0x20040001~0x20040003.
****************************************************************************/

extern pcp_to_tc_dp_t g_l2_ingress_map[L2_INGRESS_MAX_PROFILE_ID]; /* pri->tc+dp */
extern exp_to_tc_dp_t g_mpls_ingress_map[MPLS_INGRESS_MAX_PROFILE_ID]; /* exp->tc+dp */
extern tc_dp_to_pcp_t g_l2_egress_map[L2_EGRESS_MAX_PROFILE_ID]; /* tc+dp->pri */
extern tc_dp_to_exp_t g_mpls_egress_map[MPLS_EGRESS_MAX_PROFILE_ID]; /* tc+dp->exp */


/***************************************************************************
 * 以下是ACL开发新增定义------gxmen 20151019
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

#define FHDRV_FIELD_ENTRY_PRIO_DEFAULT 0 /*entry 默认优先级*/

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

/*以下两个枚举变量驱动自测用，应用层无需关心*/
typedef enum drv_acl_action_e 
{
    /* 未使用动作 */
	DRV_ACL_ACTION_UNUSED = 0,

	/* 重定向动作，重定向单播流*/
    DRV_ACL_ACTION_DROP = 1,

	/* 丢弃动作，丢弃单播流 */
    DRV_ACL_ACTION_REDIRECT = 2,

	/* Trap动作，将Trap code应用于流 */
    DRV_ACL_ACTION_TRAP = 3,

	/*满足ACL匹配修改TC*/
    DRV_ACL_ASSIGN_TC = 4,

	/*满足ACL匹配修改DP*/
    DRV_ACL_ASSIGN_DP = 5,

	/*满足ACL匹配统计*/
    DRV_ACL_ACTION_STAT = 6,

	/*满足ACL匹配统计*/
    DRV_ACL_ACTION_METER = 7,

    /* 动作个数 */
    DRV_ACL_ACTION_MAX
}drv_acl_action_t;

typedef enum drv_acl_rule_e 
{
    /* 基于入端口匹配. */
    DRV_ACL_RULE_SYSPORT = 1,

	/* 基于外层VLAN匹配. */
    DRV_ACL_RULE_VLANID = 2,

	/* 基于外层VLAN优先级匹配. */
    DRV_ACL_RULE_VLANPRI = 3,

	/* 基于源MAC匹配. */
    DRV_ACL_RULE_SRCMAC = 4,

	/* 基于目的MAC匹配. */
    DRV_ACL_RULE_DSTMAC = 5,

	/* 基于源IP匹配. */
    DRV_ACL_RULE_SRCIP = 6,

	/* 基于目的IP匹配. */
    DRV_ACL_RULE_DSTIP = 7,

	/* 基于四层源端口号匹配. */
    DRV_ACL_RULE_L4SRCPORT = 8,

	/* 基于四层目的端口号匹配. */
    DRV_ACL_RULE_L4DSTPORT = 9,

	/* 基于四层目的端口号匹配. */
    DRV_ACL_RULE_DSCP = 10,

	/* 基于四层目的端口号匹配. */
    DRV_ACL_RULE_PW = 11,
   
    /* 动作个数 */
    DRV_ACL_RULE_MAX
}drv_acl_rule_t;

/*应用层关注以下两个结构体*/
typedef struct drv_acl_rule_key_s
{
    /* 掩码有效bit范围和其对应参数有关 */
	int entryprio;/*entry优先级，默认值0；值越大优先级越高*/
	int port; /*local port*/
	int port_mask;
	unsigned char vlan_pri; 
	unsigned char pri_mask;/* PRI长三bit,掩码低三bit有效,下面掩码类同 */
	unsigned short vlan_id;
	unsigned short vlan_mask;/* 有效范围与上类同 */
	unsigned int srcip;
	unsigned int srcip_mask;/* 有效范围与上类同 */
	unsigned int dstip;
	unsigned int dstip_mask;/* 有效范围与上类同 */
	int l4srcport;
	int l4srcport_mask;/* 有效范围与上类同 */
 	int l4dstport;
 	int l4dstport_mask;/* 有效范围与上类同 */
	unsigned int assign_tc; /* TC -> PHB   */
	unsigned int assign_dp; /* DP -> COLOR */
	unsigned int redirect_port; /* LOCAL-PORT */
	unsigned int redirect_modid;/*重定向单盘modid*/
	unsigned char dscp;
	unsigned char dscp_mask; /* 有效范围与上类同 */
	int statid;    /* COUNTER ID , 应用层不用管*/
	int policerId; /* METER ID , 应用层不用管*/
	int ckbits_sec; /* CIR */
	int pkbits_sec; /* PIR */
	unsigned int pw; /*pw lable*/
	unsigned int pw_mask;
	unsigned int tunnel; /*tunnel lable*/
	unsigned int tunnel_mask;
	drv_meter_sence_t sence;/* ACL上METER的色感控制 */
	drv_mac_t src_mac;
	drv_mac_t srcmac_mask;
	drv_mac_t dst_mac; 
	drv_mac_t dstmac_mask; 
 }drv_acl_rule_key_t;

typedef struct drv_acl_action_list_s
{	
	/* 所有标识置1有效 */
	unsigned char PermitFlag;    /* 与DROP互斥   */
	unsigned char DropFlag;      /* 与PERMIT互斥 */
	unsigned char RedirectFlag;  /*重定向flag，置1动作有效*/
	unsigned char AssignTcFlag;  /*指定TCflag，置1动作有效*/
	unsigned char AssignDpFlag;  /*指定DPflag，置1动作有效*/
	unsigned char StatFlag;	     /*计数flag，置1动作有效*/
	unsigned char MeterFlag;     /*meter flag，置1动作有效*/
	unsigned char WhiteListFlag;  /*白名单flag*/
	
}drv_acl_action_list_t;

/* 驱动保存配置信息结构体，应用层无需关心 */
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
	int entryprio;/*entry优先级，默认值0；值越大优先级越高*/
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
	unsigned short ethertype; /*ETHERNET OAM 断业务*/
	unsigned char subtype[4]; /*EFM SUBTYPE*/
	unsigned char subtype_mask[4]; /*EFM SUBTYPE mask*/
	unsigned int redirect_port;/*重定向端口,local port*/
	unsigned int redirect_dest_port;/*镜像端口，local port*/
	unsigned int redirect_dest_modid;/*镜像单盘modid*/
	unsigned int mirror_dest_port;/*镜像端口，local port*/
	unsigned int mirror_dest_modid;/*镜像单盘modid*/

}drv_udf_key_t;

typedef struct drv_udf_action_s
{
	unsigned char DropFlag;/*丢弃flag，置1动作有效*/      
	unsigned char RedirectFlag;/*重定向flag，置1动作有效*/
	unsigned char MirrorFlag;/*镜像flag，置1动作有效*/
} drv_udf_action_t;

/******************************************************************************
** 函 数 名 ：fhdrv_fap_qos_set_pcp_ingress()
** 功能描述 ：创建或修改INGRESS侧某个profile pcp到phb和color的映射
** 输    入 ：unit				芯片ID,从0开始
**		   	  profile		    取值范围(0~7,包含边界值)
**            *pcp              长度为8的char类型数组,数组成员取值0~7
**            *phb              长度为8的int类型数组,数组成员取值0~7
**            *color            长度为8的int类型数组,数组成员取值0~2
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.1.4
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 调用示例 :{
                char pcp[QOS_MAP_NUM] = {0,1,2,3,4,5,6,7};
                int phb[QOS_MAP_NUM] = {4,2,1,5,6,7,0,3};
                int color[QOS_MAP_NUM] = {0,0,0,0,0,0,0,0};

                fhdrv_fap_qos_set_pcp_ingress(unit,profile,pcp,phb,color);
             }
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_qos_set_pcp_ingress(int unit,
    unsigned char profile,char *pcp,int *phb,int *color);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_qos_set_exp_ingress()
** 功能描述 ：创建或修改INGRESS侧某个profile exp到phb和color的映射
** 输    入 ：unit				芯片ID,从0开始
**		   	  profile		    取值范围(0~6，包含边界值)
**            *exp              长度为8的int类型数组,数组成员取值0~7
**            *phb              长度为8的int类型数组,数组成员取值0~7
**            *color            长度为8的int类型数组,数组成员取值0~2
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.1.4
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 调用示例 :{
                int exp[QOS_MAP_NUM] = {0,1,2,3,4,5,6,7};
                int phb[QOS_MAP_NUM] = {6,3,0,2,7,4,5,1};
                int color[QOS_MAP_NUM] = {0,0,0,0,0,0,0,0};

                fhdrv_fap_qos_set_exp_ingress(unit,profile,exp,phb,color);
             }
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_qos_set_exp_ingress(int unit,unsigned char profile,
    int *exp,int *phb,int *color);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_qos_set_pcp_egress()
** 功能描述 ：创建或修改EGRESS侧某个profile phb和color到pcp的映射
** 输    入 ：unit				芯片ID,从0开始
**		   	  profile		    取值范围(0~13，包含边界值)
**            *pcp              长度为8的char类型数组,数组成员取值0~7
**            *phb              长度为8的int类型数组,数组成员取值0~7
**            *color            长度为8的int类型数组,数组成员取值0~2
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.1.4
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 调用示例 :{
                char pcp[QOS_MAP_NUM] = {0,1,2,3,4,5,6,7};
                int phb[QOS_MAP_NUM] = {4,1,5,2,3,7,0,6};
                int color[QOS_MAP_NUM] = {0,0,0,0,0,0,0,0};

                fhdrv_fap_qos_set_pcp_egress(unit,profile,pcp,phb,color);
             }
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_qos_set_pcp_egress(int unit, unsigned char profile,
    char *pcp);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_qos_set_exp_egress()
** 功能描述 ：创建或修改EGRESS侧某个profile phb和color到exp的映射
** 输    入 ：unit				芯片ID,从0开始
**		   	  profile		    取值范围(0~2，包含边界值)
**            *exp              长度为8的int类型数组,数组成员取值0~7
**            *phb              长度为8的int类型数组,数组成员取值0~7
**            *color            长度为8的int类型数组,数组成员取值0~2
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.1.4
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 调用示例 :{
                int exp[QOS_MAP_NUM] = {0,1,2,3,4,5,6,7};
                int phb[QOS_MAP_NUM] = {7,4,5,1,3,2,0,6};
                int color[QOS_MAP_NUM] = {0,0,0,0,0,0,0,0};

                fhdrv_fap_qos_set_exp_egress(unit,profile,exp,phb,color);
             }
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_qos_set_exp_egress(int unit,unsigned char profile,
    int *exp);

/********************************************************************************
** 函 数 名 ：fhdrv_fap_qos_get_profile()
** 功能描述 ：获取某个qos profile映射关系
** 输    入 ：unit				芯片ID,从0开始
**		   	  profile		    取值范围(0~13，包含边界值)
**            table_type        取值范围(1~5)，表类型详见qos_table_t定义
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.1.4
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :调测函数
** 调用示例 : 1、获取8021p到PHB映射表(profile=3)
                fhdrv_fap_qos_get_profile(0,3,1);
              2、获取EXP到PHB映射表(profile=4)
                fhdrv_fap_qos_get_profile(0,4,2);              
              3、获取PHB到8021p映射表(profile=2)
                fhdrv_fap_qos_get_profile(0,2,3);              
              4、获取PHB到EXP映射表(profile=1)
                fhdrv_fap_qos_get_profile(0,1,4); 
              5、获取所有映射表
                fhdrv_fap_qos_get_profile(0,0,5);                                
** 版    本 ：1.0
*********************************************************************************/

extern int fhdrv_fap_qos_get_profile (int unit, unsigned char profile,
	qos_table_t table_type);

/********************************************************************************
** 函 数 名 ：fhdrv_fap_qos_destroy_profile()
** 功能描述 ：删除某个qos profile
** 输    入 ：unit				芯片ID,从0开始
**		   	  profile		    取值范围(0~13，包含边界值)
**            table_type        取值范围(1~4)，表类型详见qos_table_t定义
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.1.4
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 : 一般不会调用该函数；QOS MAP在底层建了，一般只会修改。
** 调用示例 : 1、删除8021p到PHB映射表(profile=3)
                fhdrv_fap_qos_destroy_profile(0,3,1);
              2、删除EXP到PHB映射表(profile=4)
                fhdrv_fap_qos_destroy_profile(0,4,2);              
              3、删除PHB到8021p映射表(profile=2)
                fhdrv_fap_qos_destroy_profile(0,2,3);              
              4、删除PHB到EXP映射表(profile=1)
                fhdrv_fap_qos_destroy_profile(0,1,4); 
** 版    本 ：1.0
*********************************************************************************/
extern int fhdrv_fap_qos_destroy_profile(int unit, unsigned char profile,
	qos_table_t table_type);

/*******************************************************************************
** 函 数 名 ：fhdrv_fap_qos_get_chip_map()
** 功能描述 ：调测函数，依据flags打印某个map_id芯片底层QOS MAP映射关系。
** 输    入 ：unit			芯片ID,从0开始
**		   	  flags		    L2_INGRESS flags=0x404; 
**                          MPLS_INGRESS flags=0x500;
**                          L2_EGRESS flags=0x834;
**                          MPLS_EGRESS flags=0xa04;注:目前SDK不支持该flag的查询。 
**            map_id        将全局变量g_qos_arad_debug置为1，即可在创建或修改时获
**                          取相应的map_id.
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.1.4
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 调用示例 : 1、芯片底层表中获取8021p到PHB映射表(L2_INGRESS,map_id=0x10020002)
                fhdrv_fap_qos_get_chip_map(0,0x404,0x10020002);
              2、芯片底层表中获取EXP到PHB映射表(MPLS_INGRESS,map_id=0x1002000a)
                fhdrv_fap_qos_get_chip_map(0,0x500,0x1002000a);
              3、芯片底层表中获取PHB到8021p映射表(L2_EGRESS,map_id=0x20010002)
                fhdrv_fap_qos_get_chip_map(0,0x834,0x20010002);
              4、注:目前SDK不支持flags=0xa04的查询。 
** 版    本 ：1.0
*********************************************************************************/
extern int fhdrv_fap_qos_get_chip_map (int unit, int flags, int map_id);


/*******************************************************************************
 * 以下是ACL开发新增定义------gxmen 20151019
*********************************************************************************/

/******************************************************************************
** 函 数 名 ：fhdrv_fap_acl_init()
** 功能描述 ：ACL初始化->创建GROUP,初始化ruleinfo数组。
** 输    入 ：unit
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :PP驱动初始化是调用
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_acl_init(int unit);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_acl_group_destroy()
** 功能描述 ：底层删除GROUP
** 输    入 ：unit
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_acl_group_destroy(int unit);

/******************************************************************************

                         以下ACL接口供应用层调用
                    
*******************************************************************************/
/******************************************************************************
** 函 数 名 ：fhdrv_fap_acl_entry_create()
** 功能描述 ：创建ACL entry
** 输    入 ：unit		芯片ID,从0开始
**		   	  rule		所有的掩码默认设置为全1，其余默认值为0，驱动底层
**                      检测到非0值即认为要匹配该规则
**            action    默认为全0结构，驱动底层检测到某个动作flag置1即认
**                      为要执行该动作。
** 输    出 ：无
** 返    回 ：返回值为entry_id值,从0开始,小于0为异常
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_acl_entry_create(int unit, drv_acl_rule_key_t *rule, drv_acl_action_list_t *action);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_acl_stat_get()
** 功能描述 ：获取挂载counter 的entry计数(基于packet)
** 输    入 ：unit		芯片ID,从0开始
**		   	  entry     entry_id值
** 输    出 ：无
** 返    回 ：返回计数值
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_acl_stat_get(int unit, int entry, service_stat_t *stat);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_acl_entry_destroy()
** 功能描述 ：删除 一条ACL entry
** 输    入 ：unit		芯片ID,从0开始
**		   	  entry     entry_id值
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_acl_entry_destroy(int unit, int entry_id);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_acl_entryid_show()
** 功能描述 ：显示ACL GROUP中创建的entry_id
** 输    入 ：unit		芯片ID,从0开始
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern void fhdrv_fap_acl_entryid_show(int unit);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_acl_entryid_show()
** 功能描述 ：删除ACL GROUP中创建的所有entry
** 输    入 ：unit		芯片ID,从0开始
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_acl_entry_destroy_all(int unit);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_acl_entryinfo_dump()
** 功能描述 ：打印一条ACL应用层配置信息
** 输    入 ：unit		芯片ID,从0开始
**          ：entry_id	查询的entry_id
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_acl_entryinfo_dump(int unit,int entry_id);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_acl_entryinfo_dump_all()
** 功能描述 ：打印所有ACL应用层配置信息
** 输    入 ：unit		芯片ID,从0开始
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_acl_entryinfo_dump_all(int unit);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_acl_entryinfo_chip_dump()
** 功能描述 ：打印芯片底层一条entry的配置信息
** 输    入 ： unit		芯片ID,从0开始
** 			： entry    entry_id
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_acl_entryinfo_chip_dump(int unit, int entry);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_acl_groupinfo_chip_dump()
** 功能描述 ：打印芯片底层group配置信息
** 输    入 ：unit		芯片ID,从0开始
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_acl_groupinfo_chip_dump(int unit);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_acl_policer_set()
** 功能描述 ：修改meter配置
** 输    入 ：unit				芯片ID,从0开始
**		   	  entry_id		    挂载的entry_id
**            ckbits_sec        meter设置的保证带宽,单位kbits
**            pkbits_sec        meter设置的峰值带宽,单位kbits
**            sence             meter色感/色盲模式选择 1代表色感 2代表色盲
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_acl_policer_set(int unit, int entry_id, int ckbits_sec, 
	int pkbits_sec, drv_meter_sence_t sence);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_whitelist_default_entry()
** 功能描述 ：创建白名单默认ACL entry
** 输    入 ：unit		芯片ID,从0开始
**		   	  rule		所有的掩码默认设置为全1，其余默认值为0，驱动底层
**                      检测到非0值即认为要匹配该规则
**            action    默认为全0结构，驱动底层检测到某个动作flag置1即认
**                      为要执行该动作。
** 输    出 ：无
** 返    回 ：返回值为entry_id值
** 作　  者 ：gxmen
** 日　  期 ：2015.12.07
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_whitelist_default_entry(int unit, drv_acl_rule_key_t *rule, drv_acl_action_list_t *action);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_baselif_stat_get()
** 功能描述 ：基于lif_id的性能统计获取接口
** 输    入 ：unit		  芯片ID,从0开始
**            is_ingress  1:入口统计 0:出口统计
**            is_uni      1:UNI侧统计 0:NNI侧统计
**            lif_id      lif id值
**            stat        用于保存统计值的结构体指针
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.12.08
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_baselif_stat_get(int unit, unsigned char is_ingress, unsigned char is_uni, 
	unsigned int lif_id, service_stat_t *stat);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_baselif_stat_show()
** 功能描述 ：显示基于lif_id的性能统计
** 输    入 ：unit		  芯片ID,从0开始
**            is_ingress  1:入口统计 0:出口统计
**            is_uni      1:UNI侧统计 0:NNI侧统计
**            lif_id      lif id值
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.12.08
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_baselif_stat_show(int unit, int is_ingress, unsigned char is_uni, unsigned int lif_id,
	unsigned char lsr_flag, unsigned char mspw_flag);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_service_policer_set()
** 功能描述 ：修改业务meter配置
** 输    入 ：unit				芯片ID,从0开始
**		   	  is_uni		    1:UNI 0:NNI
**		   	  lif_id		    AC_LIFID/PW_LIFID
**            ckbits_sec        meter设置的保证带宽,单位kbits
**            pkbits_sec        meter设置的峰值带宽,单位kbits
**            sence             meter色感/色盲模式选择 1代表色感 2代表色盲
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_service_policer_set(int unit, unsigned char is_uni, int lif_id, int ckbits_sec, 
	int pkbits_sec, drv_meter_sence_t sence);

/******************************************************************************
** 函 数 名 ：ApiInitPmfModule()
** 功能描述 ：应用层调用PMF初始化接口
** 输    入 ：unit   
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int ApiInitPmfModule(int unit);

/********************************************************************************************
 ********************************  USER DEFINE QUALIFIER PMF  *******************************
 ********************************************************************************************/

/******************************************************************************
** 函 数 名 ：fhdrv_fap_acl_udf_init()
** 功能描述 ：初始化自定义匹配的GROUP
** 输    入 ：unit			芯片ID,从0开始
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_acl_udf_init(int unit);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_udf_entry_create()
** 功能描述 ：创建ACL entry
** 输    入 ：unit		芯片ID,从0开始
**		   	  key		驱动底层检测到非0值即认为要匹配该规则
**            action    默认为全0结构，驱动底层检测到某个动作flag置1即认
**                      为要执行该动作。
** 输    出 ：无
** 返    回 ：返回值为entry_id值
** 作　  者 ：gxmen
** 日　  期 ：2015.12.10
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_udf_entry_create(int unit, drv_udf_key_t* key, drv_udf_action_t* action);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_udf_entry_destroy()
** 功能描述 ：删除 自定义 qualifier entry
** 输    入 ：unit		芯片ID,从0开始
**		   	  entry     entry_id值
** 输    出 ：无
** 返    回 ：entry_id
** 作　  者 ：gxmen
** 日　  期 ：2015.12.10
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_udf_entry_destroy(int unit,int entry);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_cosq_discard_set()
** 功能描述 ：芯片颜色丢弃设置
** 输    入 ：unit		芯片ID,从0开始
**            color     丢弃颜色
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_cosq_discard_set(int unit, drv_drop_clor_t color);

/******************************************************************************
** 函 数 名 ：fhdrv_fap_policer_adjust_set()
** 功能描述 ：配置meter补偿
** 输    入 ：unit				芯片ID,从0开始
**            port              local port
**            value             补偿值
** 输    出 ：无
** 返    回 ：返回为0则成功，否则为失败
** 作　  者 ：gxmen
** 日　  期 ：2015.10.15
** 修　  改 ：
** 日　  期 ：
** 修改说明 ：
** 备    注 :
** 版    本 ：1.0
*******************************************************************************/
extern int fhdrv_fap_policer_adjust_set(int unit, int port, int value);


#endif /*_FHDRV_FAP_H*/

