/*****************************************************************************
*  Copyright (C), 2002-2015, Wuhan FiberHome Tech. Co., Ltd.
*  File name      :   ppUsrApi.h   
*  Author         :  张珠玲      
*  Version        :  v1.1    
*  Date           :  2012.02.27
*  Description    :  PP应用层接口头文件
*                         
*  Others         :   
*  History         : 修改历史记录列表
*	1. Date:    2014.05.1
*	   Author:  张珠玲
*	   Modification: first in
*	2. ...
*
******************************************************************************/

#ifndef PP_USR_API_H
#define PP_USR_API_H

/*
   作者:张珠玲

   时间:20121112
   修改记录:1112添加is_disable_learning 、 is_hub、is_lag、lag_id成员；
   20121129 增加hash的类别；20121129增加api_pp_prog_trap_DA_set

 */

#ifdef    __cplusplus
extern "C" {
#endif

/*存放lif 信息*/
struct vpn_lif_info_s /*针对应用层从1开始，底层需或偏移值*/
{
    int mpls_port_id; /*为网管下发的lif-id ，范围为[[100,16K]]*/
    int tunnel_eep; /*20140922 modify 取值范围[1,16k] 偶数*//*为网管下发的tunnel-id，取值范围[40,0x1000]
                                         相同的tunnel封装建议配置相同的tunnel-eep值*/
    int vpn; /*为网管下发的vpn-id,vpws vpls lsr 的vpn各自独立，可重叠[40, 4095]*/
    int sys_port;
    unsigned char is_pwe; /*为1表明为pwe-lif*/
    unsigned char service; /*0 VPLS  ; 1  VPWS ;  2  LSR  */

    unsigned char is_wrap_protected; /*为1表明要实现v3版wrapping保护，不需将is_protected置1*/
    unsigned char is_sncp_1to1_protected; /*要用is_protected表示是主备口还是接入口*/
    unsigned char is_sncp_1plus1_protected; /*要用is_protected表示是主备口还是接入口*/
    unsigned char is_lsp_1plus1_protected; /*为1表明为lsp 1+1保护*/
    unsigned char is_lsp_1to1_protected; /*为vpls vpws 1:1 ，工程应用默认为该LSP 1:1保护*/

    unsigned char is_work; /*为1表示为主用，否则为备用*/
    int failover_id; /*从该端口出去时的保护ID选择，
                                 在WRAP时则是指相应的sys_port断开时的切换，
                                 相同倒换触发条件的保护条目组应配置同一个值，
                                 所赋值的failover_id需先调接口api_pp_create_failover_id创建，
                                 范围[40, 4095]*/

    unsigned int failover_group_id;/*20150209 add zzl*/
    unsigned char is2Tunnel; /*为1表示封装双层tunnel，为1表示封装一层tunnel*/

    int key_vlan_outer; /*单层vlan-tag时的匹配值，双层vlan时的外层匹配值*/
    int key_vlan_inner; /*双层vlan的内层匹配值*/
    int key_tunnel_outer; /*LSR 所属的pwe此值才有意义*/
    int key_tunnel_inner; /*暂时无意义*/
    int key_pw; /*匹配的vc label值*/
    int encap_pipe_exp; /*暂时无意义*/

    int encap_vlan_outer; /*单层或双层vlan的外层vlan值*/
    int encap_vlan_inner; /*双层vlan的内层vlan值，单层vlan 时无意义*/
    int encap_tunnel_outer; /*两层tunnel封装时的外层tunnel，一层tunnel时无意义*/
    int encap_tunnel_inner; /*一层tunnel的封装值，或两层tunnel的内层值*/
    int encap_pw; /*pwe的封装*/

	//20120920 zzl  int is_pw_disable_learning;
    int sncp_1plus1_mc_id; /*要为sncp 1+1保护专门分配mc-id，范围为[2 ,0X1000]*/

    unsigned char lsr_not_create; /*为1表明此lif属性入口包无需建单向路由，一般用于OAM 单向发包路由*/
    int uni_match_criteria; /*0表示基于端口，1表示基于单层vlan，
                                                 2表示基于双层vlan，建议与端口vlan属性保持一致，
                                                 3表示基于pvid*/

    // unsigned char is_q_in_q;
    int q_in_q_ive; /*0表示无动作，1:REMOVE 1; 2:REMOVE 2; 3:PUSH 1(PUSH 1只能用于untag的pvid的push)*/
    int q_in_q_eve;    /*0表示无动作，1表示移除vlan，
                                        2表示移除并添加一层vlan，3表示移除并添加两层vlan
                                        4:remove 2 push 1;5 :remove 2 push 2;6 :remove 1 push 1;7 :remove 1 push 2;
                                        8 :remove 2 ;9 :push 1;10 :push 2;11 :remove 1 ;*/
    int is_disable_learning; /*为1表示关闭学习功能，指其他端口学习不到此端口的mac地址*/

    int is_hub; /*1表示为hub属性，0为spoke属性，为端口属性*/
    int is_lag; /*为1 表示为lag成员，为lag成员时才需配置此参数*/
    int lag_id; /*创建lag所需的lag-id数值，为lag成员时才需配置此参数*/
    unsigned char ingress_profile;/*ac ingress profile must [0 7] pwe ingress profile must [0 6]*/
    unsigned char egress_profile;/*ac egress profile must [0 13] pwe egress profile must [0 2]*/


	/*--------------------------    新增成员  ，前面有些老成员没用了，不处理即可 ----------------------*/

	/*用于保护，需X2*/
	int g_vplsPro_learn_fec_id_only_work;  /*150819 chenge add 网管传入的VPLS保护模式下主用PWE_LIF所指定的学习FEC，具体分配是在相关联的AC侧单盘*/
  
	/*不用于保护，可以是单数，不X2；不同业务科共用*/
	int g_egress_intf_fec_id; /*创建EO时所需定义的指针，因VPLS不保护的学习时需两边一致，因此需网管分配；又因VPLS导致盘间任意可能的关联性，因此也定义为全局*/

	/*硬件规定一些封装ID必须为偶数，需X2；不同业务科共用*/
	int local_intf_id;  /*150824  chenge 网管下发的针对pwe的TUNNEL封装ID 和不带TUNNEL的 L3封装  只有pwe侧有 */

	/*用于保护，需X2；LSR本不需X2，但为了简单也统一X2，还为了今后LSR保护，查找函数结果自动X2，不需底层代码操作*/
	int self_cfg_vpwsPro_lsr_fec_id;/*150824   驱动自己维护增删的VPWS保护下的FEC和LSR业务 本地分配 */

	int failover_tunnel_id;/*20150902 基于TUNNEL倒换的ID，failover_id 是基于PWE倒换的ID*/

	/*-------------------------   SDN测试 eth 业务新增字段  --------------------------*/
	
	unsigned char 	is_protected; /*是否存在保护，只要有保护则为1，至于哪类由如下变量定义*/
	int 				is_1to1_protected;   /* TP 1:1保护 */
	int 				is_1plus1_protected;   /* TP 1+1保护 */
	int 				is_otn_protected;		/* TP 1+1保护进一步是为OTN*/
	int 				eth_1plus1_protect;   /* 用来标识 eth 1+1保护 */
	int 				eth_1to1_protect;   /* 用来标识 eth 1:1保护 */

	
	int 				protect_mc_id;                /* 保护模式下组播组id   */
	
};

/*mep_info 用于OAM测试*/
struct mep_info_s
{
    unsigned char *mac; /*同一端口上的所有mep 的da[8:47]应相同*/
    unsigned int level;
    unsigned int dual_lm_flag;
    unsigned int sys_port;
    unsigned int group_id;
    unsigned int is_upmep; /*为1表示upmep；0表示downmep*/
    unsigned char is_dm;
    unsigned char is_mip;  /*为1表示mip；0表示mep*/
    unsigned int fpga_sysport; /*上送到fpga报文的fpga系统端口号*/
    unsigned int cpu_sysport;  /*上送到cpu报文的cpu系统端口号*/
    unsigned int cfm_lif_info; /*所建mep端口的lif_id*/

	/*tx 属性 芯片自带模块发包*/
	unsigned int vlan;
	unsigned int inner_vlan;
	unsigned int out_tpid;
    unsigned int inner_tpid;
    unsigned char *smac; 
    unsigned int tx_sys_port;
	unsigned char ccm_period;/*1-3.33ms,2-10ms,3-100ms,4-1s,5-10s 6-1m,7-10m*/
	unsigned int tunnel_label;
	/*unsigned int tunnel_pop_id;lsp oam RX 属性，为剥除tunnnel时的id*/
	unsigned int ttl;
	unsigned int exp;
	unsigned int mep_index;/*芯片用于识别创建的mep，芯片本地ID资源概念，驱动返回给应用层用来删mep*/
	unsigned char oam_type;/*20141230 add zzl 0:ETH /1:LSP/2:pwe*/
	unsigned int rx_info;/*20150106 add zzl tp oam rx属性，for vc oam 输入lif，for tp oam 输入pop-id*/
	unsigned int tx_info;/*20150106 add zzl tp oam tx属性，for vc oam输入业务的tunnel-eep指针,for vp目前是固定值不可见*/
	/*unsigned int pwe_lif;20141230 add zzl pwe oam rx 属性，为业务的lif-id*/
	/*unsigned int tunnel_eep;20141230 add zzl pwe oam tx属性，为业务的tunnel eep指针*/
	

	/*unsigned int mep_id;151125   hl*//*group内唯一，*/
	
	unsigned short  mep_id;/*group内唯一，系统概念*/
	unsigned int remote_mep_id;/*group内唯一*/

	unsigned char is_pro;

    #if 1/*ETH双端LM使用 后续考虑另定义结构体*/
	unsigned int tx_nearend;/*近端发包数统计*/
	unsigned int rx_nearend;/*近端收包统计*/
	unsigned int tx_farend;/*远端发包统计*/
	unsigned int rx_farend;/*远端收包统计*/
	
	unsigned int loss_nearend_acc;/*近端累计丢包数统计*/
	unsigned int loss_farend_acc;/*远端累计丢包数统计*/

    unsigned int loss_nearend;/*近端丢包率*/
	unsigned int loss_farend;/*远端丢包率*/
	#endif
};

typedef struct mep_info_s MEP_INFO_S;


struct muticast_id
{
	unsigned int lif_id;
	unsigned int sys_port;
};


struct oam_state
{
		
	unsigned char loc;
	unsigned char rdi;
	unsigned char ais;
	unsigned char mismatch_level;
	unsigned char mismatch_meg;/*为1表明meg失配*/
	unsigned char mismatch_mep;/*为1表明mep失配*/
	unsigned char mismatch_period;/*为1表明period失配*/
	unsigned char is_valid; 	
	unsigned char is_mis_rx; /*为1表明表明cpu未收到失配报文*/	 
	
};
/*
   作者:张珠玲
   功能:添加pop操作
   输入:tunnel label值
   输出:返回为0则成功，否则为失败
   说明:
   时间:20120918
 */
extern int api_pp_add_tunnel_pop(int unit,int tunnel_label, int tunnel_eep);

extern int api_pp_add_tunnel_pop_inner(int unit,int tunnel_label, int tunnel_eep);

/*
   作者:张珠玲
   功能:删除pop-tunnel操作
   输入:tunnel label值
   输出:返回为0则成功，否则为失败
   说明:在删除业务时调用
   时间:20120918
 */

extern int api_pp_delete_tunnel_pop(int unit,int tunnel_label,int tunnel_eep);

extern int api_pp_delete_tunnel_pop_inner(int unit,int tunnel_label,int tunnel_eep);

/*
   作者:张珠玲
   功能:创建3种VPN
   输入:unit 暂固定为0，VPN类型,vpn值
   输出:返回为0则成功，否则为失败
   说明:service=0/1/2分别表示 VPLS/VPWS/LSR
   时间:20120718
 */
extern int api_pp_cfg_VswitchVpnCreate(int unit, int service, unsigned short vpn);

/*
   作者:张珠玲
   功能:将port信息导入指定的vpws_vpn_info[vpn]/vpls_vpn_info[vpn]/lsr_vpn_info[vpn]中
   输入:指向port信息的指针
   输出:返回为0则成功，否则为失败
   说明:无
   时间:20120718
 */
extern int api_pp_cfg_UsrAddMplsPortToVpn(struct vpn_lif_info_s *p_vpn_lif_info); /*仅操作vpn_mpls_portId_s*/

/*
   作者:张珠玲
   功能:创建3种VPN业务
   输入:unit 暂固定为0，VPN类型,vpn值
   输出:返回为0则成功，否则为失败
   说明:service=0/1/2分别表示 VPLS/VPWS/LSR
   时间:20120718
 */
extern int api_pp_cfg_CreateRouteVpn(int unit, int service, unsigned short vpn); /*物理实现，自动设置先AC再PWE*/

/*
   作者:张珠玲
   功能:删除指定vpn
   输入:unit 暂固定为0，VPN类型,vpn值
   输出:返回为0则成功，否则为失败
   说明:service=0/1/2分别表示 VPLS/VPWS/LSR
   时间:20120718
 */
extern int api_pp_cfg_DelVpn(int unit, int vpn, int service);

/*
   作者:张珠玲
   功能:设置匹配范围
   输入:TUNNEL终结的匹配范围的上下限
   输出:返回为0则成功，否则为失败
   说明:PW标签必须在此范围之外，否则会被终结
   时间:20120718
 */
extern int api_pp_cfg_term_tunnel_range(int min_temp, int max_temp);

/*
   作者:张珠玲
   功能:配置nni 端口信息
   输入:sys_port ,mymac(暂只取最低位字节)
   输出:返回为0则成功，否则为失败
   说明:sys_port为带槽位信息的port，如7号槽位(modid为1)的6端口，则输入106
            端口信息配置只需在本盘盘内配置，
   时间:20120718
 */
extern int api_pp_cfg_nni_port(int sys_pwe_port, unsigned short myMac);

/*
   作者:张珠玲
   功能:配置uni 端口信息
   输入:sys_port , vlanTagNum,外层tag的tpid，内层tpid
   输出:返回为0则成功，否则为失败
   说明:sys_port为带槽位信息的port，如7号槽位(modid为1)的6端口，
             则输入106，vlanTagNum=1表ac为1层标签，为2表双层标签，为0表示基于port
             端口信息配置只需在本盘盘内配置。
   时间:20120718
 */
extern int api_pp_cfg_uni_port(int sys_ac_port, unsigned char vlanTagNum, int out_tpid, int inner_tpid);

#if 0
/*
   作者:张珠玲
   功能:设置TTL的值，仅对uniform模型下的vpls业务下有效
   输入:ttl数值
   输出:无
   说明:所有业务共用同一个TTL ，一般是初始化时调用
   时间:20120724
 */
extern void api_pp_setGlobalTTL(unsigned char ttl);
#endif

/*
   作者:张珠玲
   功能:设置port出口属性为TM port属性，并使能OTMH头中源端口信息
   输入:local_port
   输出:返回为0则成功，否则为失败
   说明:一般是初始化时需调用,主要是针对cpu端口和FPGA-OAM端口
   时间:20120724
 */
extern int api_pp_setFpgaOamPort(int local_port);

/*
   作者:张珠玲
   功能:设置vs vp OAM
   输入:fpgaPort 及trapStrength
   输出:返回为0则成功，否则为失败
   说明:fpgaPort 为sysport，2<=trapStrength<=7，
            此为从NNI到FPGA的OAM trap;
            FPGA到NNI的OAM信道需建类似普通LSR业务流，只是NNI口tunnel =13 or 14
            FPGA端口tunnel依据协议暂定为localPort*0x100+13/14;
   时间:20120724 0911
 */
extern int api_pp_vs_vp_oam_trap_set(int fpgaPort, int trapStrength);

/*
   作者:张珠玲
   功能:删除已创建的vs vp OAM
   输入: 无
   输出:返回为0则成功，否则为失败
   说明:无

   时间:20120911
 */
extern int api_pp_vs_vp_oam_trap_delte(void);

/*
   作者:张珠玲
   功能:设置特殊mac OAM，01-80-c2-00-00-xx
   输入:fpgaPort 及trapStrength
   输出:返回为0则成功，否则为失败
   说明:fpgaPort 为sysport，默认到cpu端口；2<=trapStrength<=7，

   时间:20120911
 */
extern int api_pp_mac_oam_trap_set(int fpgaPort, int trapStrength);

/*
   作者:张珠玲
   功能:使能cpu收包
   输入:unit=0；  enable=1表明使能cpu收包
   输出:返回为0则成功，否则为失败
   说明:在执行api_pp_mac_oam_trap_set后执行该函数

   时间:20120911
 */

extern int api_pp_rx_trap_start(int unit, int enable);

/*
   作者:张珠玲
   功能:删除已创建的特殊mac OAM
   输入: 无
   输出:返回为0则成功，否则为失败
   说明:无

   时间:20120911
 */

extern int api_pp_mac_oam_trap_delte(void);

/*
   作者:张珠玲
   功能:设置vc OAM，
   输入:fpgaPort 及trapStrength
   输出:返回为0则成功，否则为失败
   说明:fpgaPort 为sysport，2<=trapStrength<=7，

   时间:20120911
 */

extern int api_pp_vc_oam_trap_set(int fpgaPort, int trapStrength);

/*
   作者:张珠玲
   功能:删除已创建的vc OAM
   输入: 无
   输出:返回为0则成功，否则为失败
   说明:无

   时间:20120911
 */
extern int api_pp_vc_oam_trap_delte(void);

/*
   作者:张珠玲
   功能:创建基于IGMP payload =0x11的trap 提包规则
   输入: 无
   输出:返回为0则成功，否则为失败
   说明:fpgaPort 为sysport，2<=trapStrength<=7，

   时间:20130715
 */
extern int api_pp_Igmp_query_trap_set(int fpgaPort, int trapStrength);

/*
   作者:张珠玲
   功能:删除基于IGMP payload =0x11的trap 提包规则
   输入: 无
   输出:返回为0则成功，否则为失败
   说明:无

   时间:20130715
 */
extern int api_pp_Igmp_query_trap_delte(void);

/*
   作者:张珠玲
   功能:创建基于IGMP payload = 0x12, 0x16, 0x17, or 0x22的trap 提包规则
   输入: 无
   输出:返回为0则成功，否则为失败
   说明:fpgaPort 为sysport，2<=trapStrength<=7，

   时间:20130715
 */
extern int api_pp_Igmp_Leave_trap_set(int fpgaPort, int trapStrength);

/*
   作者:张珠玲
   功能:删除基于IGMP payload = 0x12, 0x16, 0x17, or 0x22的trap 提包规则
   输入: 无
   输出:返回为0则成功，否则为失败
   说明:无

   时间:20130715
 */
extern int api_pp_Igmp_Leave_trap_delte(void);


/*
   作者:张珠玲
   功能:设置mirror业务
   输入:in_out_port(入口或出口) 及mirr_dest_port(镜像口)，
   		is_ingress_mirror指明为入口镜像还是出口镜像
   输出:返回为0则成功，否则为失败
   说明:in_out_port 及mirr_dest_port 均为sys_port，
        is_ingress_mirror=1时则in_out_port为入端口；
        is_ingress_mirror=0时则in_out_port为出端口；
   时间:20120724  20130401 
 */
extern int api_pp_mirror_set(int unit, int in_out_port, int mirr_dest_port, unsigned char is_ingress_mirror);


/*
   作者:张珠玲
   功能:删除mirror业务
   输入:in_out_port(入口或出口) 及mirr_dest_port(镜像口)，
   		is_ingress_mirror指明为入口镜像还是出口镜像
   输出:返回为0则成功，否则为失败
   说明:in_out_port 及mirr_dest_port 均为sys_port，
        is_ingress_mirror=1时则in_out_port为入端口；
        is_ingress_mirror=0时则in_out_port为出端口；
   时间:20120724  20130401 
 */

extern int api_pp_mirror_delete(int unit, int in_out_port, int mirr_dest_port, unsigned char is_ingress_mirror);

/*
   作者:张珠玲
   功能:获取端口镜像
   输入:port 被镜像端口，为sysport 
   
   输出:返回dest_sysport，flag
   说明:flag=1为ingress镜像；flag=2为egress镜像,flag=0无镜像
   时间:20140506
 */
extern int api_pp_port_mirror_get(int unit,int port,int *dest_sysport,int *flag);


/*
   作者:张珠玲
   功能:删除ingress egress map-id
   输入:无
   输出:返回为0则成功，否则为失败
   说明:
   时间:20120815
 */

extern int api_pp_delete_all_qos_map();

/*
   作者:张珠玲
   功能:创建map-id
   输入:无
   输出:返回为0则成功，否则为失败
   说明:类似初始化，只需调用一次，
   时间:20120815
 */

/*extern int api_pp_create_map(void);*/
int api_pp_create_map(unsigned char l2_ing_profile,
    unsigned char l2_egr_profile,
    unsigned char mpls_ing_profile,
    unsigned char mpls_egr_profile);

/*
   作者:张珠玲
   功能:创建ingress DP ,
   输入:8字节的指针，指向定义的DP表
   输出:返回为0则成功，否则为失败
   说明:取值为0-63
   时间:20120815
        20131220 增加参数profile，暂定此profile即local-port，

 */

/*extern int api_pp_cfg_ingress_color(int *color_ptr);*/
int api_pp_cfg_ingress_color(int *color_ptr, unsigned char profile); 

/*
   作者:张珠玲
   功能:创建egress 的pcp、exp封装表,
   输入:16字节的指针，指向定义的egress封装表
   输出:返回为0则成功，否则为失败
   说明:取值为0-15；如果需要更新exp表，直接运行api_pp_cfg_egress_exp_pcp即可，
   时间:20120815
        20131220 增加参数profile，暂定此profile即local-port，
 */

/*extern int api_pp_cfg_egress_exp_pcp(int *encap_pri);*/
int api_pp_cfg_egress_exp_pcp(int *encap_pri, unsigned char profile);


/*
   作者:张珠玲
   功能:vpws 1:1保护的主备选发切换
   输入:vpn值switch2Protect
   输出:返回为0则成功，否则为失败
   说明:switch2Protect为1表示切换到备用口，为0表示切换到主用
   时间:20120815
 */

extern int api_pp_vpws_1to1_switch(int vpn, int switch2Protect);

/*
   作者:张珠玲
   功能:vpls 1:1保护的主备选发切换
   输入:vpn值switch2Protect
   输出:返回为0则成功，否则为失败
   说明:switch2Protect为1表示切换到备用口，为0表示切换到主用
   时间:20120815 20140612增加failover_id
 */

//extern int api_pp_vpls_1to1_switch(int vpn, int switch2Protect,int failover_id);

/*
   作者:张珠玲
   功能:sncp1:1保护的主备选发切换
   输入:vpn值switch2Protect
   输出:返回为0则成功，否则为失败
   说明:switch2Protect为1表示切换到备用口，为0表示切换到主用
   时间:20120815
 */
extern int api_pp_sncp_1to1_switch(int vpn, int switch2Protect);

/*
   作者:张珠玲
   功能:LSP 1+1保护的主备选收切换
   输入:vpn值switch2Protect
   输出:返回为0则成功，否则为失败
   说明:switch2Protect为1表示切换到备用口，为0表示切换到主用
   时间:20120815
 */

extern int api_pp_vpls_vpws_1plus1_switch(int unit,int vpn, int switch2Protect);

/*
   作者:张珠玲
   功能:wrapping 保护切换
   输入:vpn值switch2Protect pwe_port_fail
   输出:返回为0则成功，否则为失败
   说明:pwe_port_fail为sys-port，如果switch2Protect为1，
                表明从peer-port到pwe_port_fail的业务切换到peer-port自己
   时间:20120924
 */
extern int api_pp_wrapping_switch(int vpn, int switch2Protect, int pwe_port_fail);

/*
   作者:张珠玲
   功能:SNCP 1+1保护的主备选收切换
   输入:vpn值switch2Protect
   输出:返回为0则成功，否则为失败
   说明:switch2Protect为1表示切换到备用口，为0表示切换到主用
   时间:20120924
 */
extern int api_pp_sncp_1plus1_switch(int vpn, int switch2Protect);

/*
   作者:张珠玲
   功能:sncp 1+1 保护组播id的创建
   输入:mc-id
   输出:返回为0则成功，否则为失败
   说明:只在sncp 1+1保护才调用
   时间:20120922
 */

extern int api_pp_create_mc_for_sncp1plus1(int unit, int mc_group_id);

/*
   作者:张珠玲
   功能:设置pvid
   输入:localPort，pvid
   输出:返回为0则成功，否则为失败
   说明:uniform模式下的vpws业务的ttl从pvid继承is_ignore=1,
           untag业务按pvid转发，需设置is_ignore=0
   时间:20120820
   修改记录:20121130 新增is_ignore参数
 */
extern int api_pp_setAcPortPvid(int localPort, int pvid, int is_ignore);

/*
   作者:张珠玲
   功能:针对1588的cpu收包后协议处理接口
   输入:函数指针
   输出:无
   说明:
   时间:20120917
 */

extern void Reg_rxPktApi_1588(void (*ftp)(unsigned short sys_port, unsigned char *p, unsigned short len));

/*
   作者:张珠玲
   功能:针对EthOam(即down_mep)的cpu收包后协议处理接口
   输入:函数指针
   输出:无
   说明:
   时间:20120917
 */

extern void Reg_rxPktApi_EthOam(void (*ftp)(unsigned short sys_port,
        unsigned char *p,
        unsigned short len,unsigned int counter));

/*
   作者:throng
   功能:针对egress EthOam(即up_mep)的cpu收包后协议处理接口即up_mep
   输入:函数指针
   输出:无
   说明:arad中egress pmf提上来的包dest为local port
   时间:20120917
 */
extern void Reg_rxPktApi_Bfd(void (*ftp)(unsigned short sys_port, unsigned char *p, unsigned short len));

/*
   作者:throng
   功能:针对egress EthOam(即up_mep)的cpu收包后协议处理接口即up_mep
   输入:函数指针
   输出:无
   说明:arad中egress pmf提上来的包dest为local port
   时间:20120917
 */
extern void Reg_rxEgPktApi_EthOam(void (*ftp)(unsigned short local_port,
        unsigned char *p,
        unsigned short len,unsigned int counter));

/*
   作者:张珠玲
   功能:针对LinkOam的cpu收包后协议处理接口
   输入:函数指针
   输出:无
   说明:
   时间:20120917
 */

extern void Reg_rxPktApi_LinkOam(unsigned char (*ftp)(unsigned short sys_port, unsigned char *p, unsigned short len));

/*
   作者:张珠玲
   功能:针对Lacp的cpu收包后协议处理接口
   输入:函数指针
   输出:无
   说明:
   时间:20120917
 */

extern void Reg_rxPktApi_Lacp(void (*ftp)(unsigned short sys_port, unsigned char *p, unsigned short len));

/*
   作者:张珠玲
   功能:针对IGMP的cpu收包后协议处理接口
   输入:函数指针
   输出:无
   说明:
   时间:20120917
 */
extern void Reg_rxPktApi_Igmp(void (*ftp)(unsigned short sys_port, unsigned char *p, unsigned short len));

/*
   作者:张珠玲
   功能:临时接口，用于解析对端设备sa da
   输入:函数指针
   输出:无
   说明:
   时间:20131118
 */
extern void Reg_Mac_parse(void (*ftp)(unsigned char *p));

/*
   作者:张珠玲
   功能:cpu发包
   输入:包长pkts_len、目的端口sys_port、指向包内容的指针、vpn,service 无效为保持接口一致，
   输出:返回为0则成功，否则为失败
   说明:目的端口为sys-port，此接口只适用于非LM DM帧的发送
   时间:20120917
 */
extern int api_pp_cpu_tx(int pkts_len, int sys_port, unsigned char *pkts, int vpn_id, int service);

/*
   作者:张珠玲
   功能:cpu发包
   输入:包长pkts_len、目的端口sys_port、指向包内容的指针、
     vpn-id为mep所属的vpn、service表明业务类型，1:vpws 0:vpls 2:lsr
   输出:返回为0则成功，否则为失败
   说明:目的端口为sys-port，此接口只适用于LM DM帧的发送
   时间:20130906
 */
extern int api_pp_cpu_LmDm_tx(int pkts_len, int sys_port, unsigned char *pkts, int vpn_id, int service, int is_upmep);

/*
   作者:throng
   功能:cpu发包
   输入:包长pkts_len、is_upmep=1,sys_port=源端口；is_upmep=0,sys_port=目的端口、指向包内容的指针、
   输出:返回为0则成功，否则为失败
   说明:
   时间:
 */
extern int fhdrv_psn_cpu_tx_packet (int unit, int pkts_len, int sys_port, unsigned char *pkts, int count_id, int is_upmep);




/*
   作者:张珠玲
   功能:删除保护id
   输入:保护id
   输出:返回为0则成功，否则为失败
   说明:无
   时间:20121010
 */

extern int api_pp_delete_failover_id(int failover_id);

/*
   作者:张珠玲
   功能:创建保护id
   输入:保护id
   输出:返回为0则成功，否则为失败
   说明:用户创建1:1保护业务时，需先调此函数创建，
                相同触发条件的保护条目最好共用一个failover_id
   时间:20121010
 */

extern int api_pp_create_failover_id(int failover_id);

/*
   作者:张珠玲
   功能:删除tunnel-eep
   输入:tunnel-eep
   输出:返回为0则成功，否则为失败
   说明:同一个tunnel封装建议配置相同的tunnel-eep，
                删除该tunnel-eep应基于独立的lsp概念，与api_pp_add_tunnel_pop类似
   时间:20121010
 */

extern int api_pp_delete_tunnel_eep(int unit, int tunnel_eep);

/*cpu 收包样例函数*/

/////////////////////////////////////////////////////////////////////////////////////////
/*
   作者:张珠玲
   功能:实现基于单层vlan的p2p业务
   输入:outer_valn1为port1的vlan，outer_valn2为port2的vlan值
   输出:无
   说明:
   示例:DbgVsiP2p_MD_2 105,106,5,5,2,2,2
 */

extern int DbgVsiP2p_match_vlan(int sys_port1,
    int sys_port2,
    int outer_valn1,
    int outer_valn2,
    int port1_id,
    int port2_id,
    int vpn_id);

/*
   作者:张珠玲
   功能:实现基于端口的p2p业务
   输入:只需输入有效端口和port-id、vpn-id
   输出:无
   说明:只为硬件调测者提供基于端口的端到端的通道
   示例:DbgVsiP2p_MD_2 105,106,0,0,2,2,2
 */

extern void DbgVsiP2p_match_port_(int sys_port1,
    int sys_port2,
    int outer_valn1,
    int outer_valn2,
    int port1_id,
    int port2_id,
    int vpn_id);

///////////////////////////////////////////////////////////////////////////////////////////
/*
   作者:张珠玲
   功能:初始化pp参数
   输入:无
   输出:返回为0则成功，否则为失败
   说明:芯片初始化后调用，只执行一次
   示例:DbgVsiP2p_MD_2 105,106,0,0,2,3,1
   时间:20121018
 */

extern int api_pp_init_cfg();

/*
   作者:张珠玲
   功能:设置cw值
   输入:cw
   输出:返回为0则成功，否则为失败
   说明:
   时间:20121018
 */
extern int api_pp_set_PweCw(int cw);

#if 0
/*
   作者:张珠玲
   功能:
   输入:
   输出:返回为0则成功，否则为失败
   说明:
 */
extern int api_pp_cfg_pipe_mode(int enb);

#endif

/*
   作者:张珠玲
   功能:配置处理模型为pipe or uniform
   输入:is_pipe=1 表明为pipe模型is_pipe=0表明为uniform模型
   输出:无
   说明:所有业务都使用一种处理模型，
            在创建业务前设置后续不允许更改，一般是初始化时调用
   时间:20120724

 */
extern void api_pp_setPipeUniform(unsigned char isPipe);

/*
   作者:张珠玲
   功能:设置静态单播
   输入:需单播端口的port-id; 静态单播mac地址；所属vpn
   输出:无
   说明:
   时间:20121112

 */
int api_pp_l2_add_static_unicast(int unit,struct muticast_id *port_id, unsigned char *mac, int vpn_id);

/*
   作者:张珠玲
   功能:删除静态单播
   输入:需单播端口的port-id; 静态单播mac地址；所属vpn
   输出:无
   说明:
   时间:20121211

 */
extern int api_pp_l2_delete_static_unicast(int unit, unsigned char *mac, int vpn_id);

/*
   作者:张珠玲
   功能:设置静态组播
   输入:指向组播端口port-id的指针; 静态组播mac地址；
            所属vpn_id；静态组播的端口数目port_count；

   输出:无
   说明:
   时间:20121112
   修改记录:20121114 去掉接口中的dest_mc_id参数，

 */
extern int api_pp_l2_add_static_muticast(int unit, unsigned char *mac, 
                                        int vpn_id, struct muticast_id *port_id_array, int port_count);

/*
   作者:张珠玲
   功能:删除静态组播
   输入:指向组播端口port-id的指针; 静态组播mac地址；
            所属vpn_id；静态组播的端口数目port_count；

   输出:无
   说明:
   时间:20121211


 */
extern int api_pp_l2_delete_static_muticast(int unit,
    unsigned char *mac,
    int vpn_id,
    int *port_id_array,
    int port_count);

/*
   作者:张珠玲
   功能:设置老化时间，秒为单位
   输入:老化时间

   输出:无
   说明:ageTime=0时表明不使能老化
   时间:20121112

 */
extern int api_pp_age_timer_set(int ageTime);

/*
   作者:张珠玲
   功能:设置vlan domain
   输入:起止的local-port端口号

   输出:无
   说明:示例api_pp_setPortVlanDomain 36 ,37,36
            表明设置36、37端口的vlan-domain为36；
            输入参数均为local-port；
   时间:20121112

 */

extern void api_pp_setPortVlanDomain(int start , int end, int share_vlan_domain);

/*
   作者:张珠玲
   功能:设置hash类型
   输入:local-port；hash_type

   输出:无
   说明:hash_type    为0  表是基于pwe后的dmac进行hash；
             为1  表是基于pwe后的smac进行hash；
             为2  表是基于pwe的dmac和smac进行hash；
            为3  表是基于ac port的dmac进行hash；
            为4  表是基于ac port的smac进行hash；
            为5  表是基于ac port的dmac和smac进行hash；
            为6  表是基于pwe label 进行hash；
   创建时间:20121112
   修改记录:20121129 增加hash的类别

 */

extern void api_pp_hash_cfg(int local_port, int hash_type);

/*
   作者:张珠玲
   功能:设置基于ac dmac 的trap，
   输入:端口号；力量值

   输出:无
   说明:此函数配合张皓的pmf使用
   时间:20121129

 */

extern int api_pp_prog_trap_DA_set(int sysPort, int trapStrength);

/*
   作者:张珠玲
   功能:删除api_pp_prog_trap_DA_set创建的trap
   输入:无

   输出:无
   说明:
   时间:20121129

 */

extern int api_pp_prog_trap_DA_delte(void);

/*
   作者:张珠玲
   功能:使能llp_trap的端口属性
   输入:local-port，trap_enable_mask=0x30

   输出:无
   说明:基于0x8902和基于dmac的trap需使能入端口相应属性
   时间:20121130

 */
extern int api_pp_ppd_llp_trap_port_info_set(int local_port, int trap_enable_mask);

/*
   作者:张珠玲
   功能:基于port+smac的分类
   输入:local-port，pvid，mac地址指针

   输出:无
   说明:主播地址无效
   时间:20121213

 */
extern int api_pp_vid_base_mac(int local_port, int pvid, unsigned char *mac);

/*
   作者:张珠玲
   功能:基于port+sip的分类
   输入:local-port；pvid；ip地址；entry_ndx取0-15  ；mask为掩码 ，
   输出:无
   说明:如ip为192.168.1.0 ， mask =24 表示需匹配192.168.1.x  ；
            不同的匹配信息应使用不同的entry_ndx，不然匹配信息会相互覆盖；

   时间:20121213

 */
int api_pp_vid_base_ip(unsigned int entry_ndx, unsigned int mask, int vid, unsigned int *ip, int local_port);

/*
   作者:张珠玲
   功能:删除基于port+smac的分类
   输入:local-port，mac地址指针

   输出:无
   说明:
   时间:20121213

 */
extern int api_pp_delete_vid_base_mac(unsigned char *mac, int local_port);

/*
   作者:张珠玲
   功能:离线从为port_id的uni口进入的业务；
   输入:vpn-id，serviceType，port-id

   输出:无
   说明:port-id是入需匹配的lif-id
           同vpn-id下可从重复调用，不同的vpn-id 要确保之前vpn的业务全部on-line
   时间:20121221

 */
extern int api_pp_offLine_vpn_portId(/*int unit,*/int vpn_id, char serviceType, int port_id);

/*
   作者:张珠玲
   功能:on-line 之前offline 的vpn_id的业务
   输入:无

   输出:无
   说明:
   时间:20121221

 */
extern int api_pp_onLine_vpn_portId(/*int unit*/void);

/*
   作者:张珠玲
   功能:获取lag-info信息并存储
   输入:无

   输出:无
   说明:此函数在lag创建完成后调用，以保证存储下初始时的数据
   时间:20121221

 */
extern int api_pp_lag_get(/*int unit,*/int tid);

/*
   作者:张珠玲
   功能:设置lag-info
   输入:无

   输出:无
   说明:经过删除添加lag操作后的lag-info的值
            需按照api_pp_lag_get获得的初始值进行设置，
            以保证cpu收包能正确识别lag端口
   时间:20121221

 */
extern int api_pp_lag_set(int tid);

/*
   作者:张珠玲
   功能:创建oam group
   输入:无

   输出:无
   说明:

   时间:20130814

 */
extern int api_pp_create_oam_group(int group_id);

/*
   作者:张珠玲
   功能:创建oam mep属性
   输入:无

   输出:无
   说明:

   时间:20130814

 */
extern int api_pp_create_mep(int unit, int vpn, int service, struct mep_info_s *mep_info);

/*
   作者:张珠玲
   功能:删除oam mep
   输入:mep-info ,vpn-id 业务类型

   输出:无
   说明:

   时间:20130814

 */
extern int api_pp_delete_mep(struct mep_info_s *mep_info , int vpn, int service);

/*
   作者:张珠玲
   功能:删除oam group
   输入:group-id

   输出:无
   说明:

   时间:20130814

 */
extern int api_pp_delete_oam_group(int group_id);

/*
   作者:张珠玲
   功能:获取loss状态
   输入:同api_pp_create_mep输入

   输出:无
   说明:获取loss参数存放在mep_info中

   时间:20140516

 */
void api_pp_loss_get(int unit, int vpn, int service,struct mep_info_s *mep_info);

/*
   作者:张珠玲
   功能:获取vpls mc信息，用于后续eth 1to1 切换
   输入:vpn_id ,pro_lif备用lif，work_lif主用lif，
   pro_port备用端口(sysport),work_port主用端口(sysport)

   输出:无
   说明:创建业务结束后立刻调用，获取主备信息并实现备用口的阻塞

   时间:20130826

 */
extern int api_pp_mc_info_get(int vpn, int pro_lif, int work_lif, int pro_port, int work_port);

/*
   作者:张珠玲
   功能:eth 1to1 切换
   输入:vpn-id is_switch_pro

   输出:无
   说明:is_switch_pro为1表明切换到备用,为0表明切换到主用

   时间:20130826

 */
extern void api_pp_eth_1to1_switch(int vpn, int is_switch_pro);

/*
   作者:张珠玲
   功能:基于vpn限制学习的mact条目
   输入:vpn值、mac_limit限制学习的条目数

   输出:无
   说明:只实现基于vpn的mac条目限制,mac=-1表示无限制

   时间:20130926

 */
extern int api_pp_mact_limit_set(int vpn, int mac_limit);

/*
   作者:张珠玲
   功能:获取限制学习的mact条目(基于vpn)
   输入:vpn值

   输出:无
   说明:用于验证api_pp_mact_limit_set是否配置成功

   时间:20130926

 */
extern int api_pp_mact_limit_get(int vpn);

/*
   另外分配新的map-id，临时测试基于业务的qos映射，
 */
extern int api_pp_create_map_base_lif(void);

/*
   作者:张珠玲
   功能:获取从指定lif学习到的mac(目前均为egress学习)
   输入:unit=0、lif-id

   输出:将学习的mac放入全局learn_mac[10][6]中
   说明:同一个lif学习多个mac后，learn_mac[0]存放最新学习的mac

   时间:20131113

 */
extern int api_pp_l2_print_mact(int unit, int lif);

/*
   作者:张珠玲
   功能:查看输入的sysport是否被业务占用
   输入:sysport
   输出:返回值为2表明此端口被业务占用，为0表明未被占用   
   说明:目前对vpn_id=1~2000进行查找

   时间:20140126

 */
extern int api_pp_chk_portUsed(int sysPort);

/*
   作者:张珠玲
   功能:设置localport 的mtu
   输入:localPort， mtu为BYTE
   输出:  
   说明:设置localport的mtu后，从此端口入口的包进行mtu检测
   
	输入 mtu ∈[(mtu-mtu%16),(mtu-mtu%16)+15] 在底层16个字节一跳

	最后实际可通过的数据帧为mtu-mtu%16+8 ，可通过的数据帧也是16个字节一跳，

	例如：mtu 设置范围在 9600-9615 实际可通过最大数据帧为9610

	     mtu 设置范围在 9616-9631 通过最大数据帧为9626
	精确到每个字节

   时间:20160415

 */
extern int api_pp_set_mtu_ingress(int unit, int localPort, int mtu);

/*
   作者:张珠玲
   功能:设置localport 的mtu
   输入:localPort， mtu为BYTE
   输出:  
   说明:设置localport的mtu后，从此端口出口的包进行mtu检测

   时间:20160309

 */

extern void api_pp_set_mtu(int unit, int localPort, int mtu);

/*
   作者:张珠玲
   功能:创建p2p基于端口的业务
   输入:sys_port1 sys_port2为系统端口
   输出:
   说明:此为400G需要的简化版接口，lif-id与sys-port绑定，故只支持一个端口建一条业务

   时间:20140418

 */
extern int DbgVsiP2p_match_port(int unit,int sys_port1,int sys_port2);

/*
   作者:张珠玲
   功能:删除p2p基于端口的业务
   输入:sys_port1 sys_port2为系统端口
   输出:
   说明:此为400G需要的简化版接口，与DbgVsiP2p_match_port配套的删除

   时间:20140418

 */
extern int DbgVsiP2p_match_port_dele(int unit,int sys_port1,int sys_port2);

/*extern int create_vpls_vpn_(int unit, int vpn, int is_uni);*/
extern int create_vpls_vpn(int unit, int vpn);

extern int create_vpls_tracffic(int unit, int vpn, int sysport, int is_uni);
extern int dele_vpls_traffic(int unit, int vpn, int sysport, int is_uni);
extern int dele_vpls_vpn(int unit,int vpn);
extern int add_mc_member(int unit, int vpn, int sysport);
extern int dele_mc_member(int unit, int vpn, int sysport);
extern int create_ingress_block(int unit, int vpn, int sysport);
extern int dele_ingress_block(int unit, int vpn, int sysport);


/*
   作者:张珠玲
   功能:创建TP oam
   输入:mep_info 见结构体说明
   输出:
   说明:

   时间:20141113 

 */
extern int fhdrv_fap_oam_create_mep(int unit, struct mep_info_s *mep_info);


extern void fhdrv_fap_oam_get_state(int unit,int mep_index,struct oam_state *state);


/*
   作者:张珠玲
   功能:根据mep_index获取loc状态
   输入:mep_index
   输出:返回1表明loc=1 返回0表明loc=0
   说明:

   时间:20150113

 */
extern int fhdrv_fap_oam_get_loc_state(int unit,int mep_index);

/*
   作者:张珠玲
   功能:根据mep_index获取rdi状态
   输入:mep_index
   输出:返回1表明rdi=1或mep不存在 返回0表明rdi=0
   说明:

   时间:20150113

 */
extern int fhdrv_fap_oam_get_rdi_state(int unit,int mep_index);

/*
   作者:张珠玲
   功能:
   输入:
   输出:返回loc状态的指针及长度
   说明:

   时间:20150113

 */
extern int fhnw_fap_oam_handle(int unit,int **p_mep_loc,int **p_len);/*5毫秒realGather调用*/

/*
   作者:张珠玲
   功能:针对TP oam 的LM dm的处理函数
   输入:函数指针
   输出:
   说明:counter 为RxFcb，LMR的rx计数

   时间:20150128

 */
extern void fhdrv_fap_oam_register_tpoam(unsigned int (*ftp)(unsigned short sys_port, unsigned char *p, 
       unsigned short len,unsigned int counter));

/*
   作者:张珠玲
   功能:cpu 发包
   输入:pkts_len:包长/ sys_port:目的端口的系统端口 /pkts:指向包内容的指针/ mep_index:mep index
   
   输出:
   说明:

   时间:20150128

 */
extern int fhdrv_fap_cpu_send(int pkts_len, int sys_port, unsigned char *pkts, unsigned int mep_index);

/*
   作者:张珠玲
   功能:获取tp oam失配状态
   输入:unit=0,mep-index;
   
   输出:p_oam_state指针，分别获取is_mis_rx,mismatch_meg,mismatch_mep,mismatch_period，
   说明:获取的值为1表明为相应类型的失配，is_mis_rx=1表明未收到包

   时间:20150210

 */
extern int fhdrv_fap_oam_get_oam_state(int unit,int mep_id,struct oam_state *p_oam_state);

/*
   作者:张珠玲
   功能:逐条倒换和分组倒换
   输入:failover_single_id，failover_group_id，is_group_switch，switch2Protect
   
   输出:
   说明:is_group_switch=1表明为组倒，为0表明为逐条倒换；
        switch2Protect=1表明切换到备用，为0切换到主用

   时间:20150210

 */
extern int fhdrv_fap_state_set_switch(unsigned int failover_single_id,unsigned int failover_group_id,
	                    unsigned char is_group_switch,unsigned char switch2Protect);

extern int fhdrv_fap_counter_get_byte_cnt(int unit,int is_ingress_cnt,
	unsigned char is_uni_lif,int lif_id);
extern int fhdrv_fap_counter_get_pkt_cnt(int unit,unsigned char is_ingress_cnt, 
	unsigned char is_uni_lif,int lif_id);
extern int fhdrv_fap_counter_create_lif(int unit);

/*************************** 新版本OAM接口函数  ********************************************************************/
/*
   作者:黄力
   功能:modify the default value of the sys_port
   输入:
   输出:0/1  成功/失败
   说明:    
   		该端口属性值由上层自己调用传入，放弃之前驱动自己调试用的默认值1514
   		
   时间:20151207

 */

extern int fhdrv_fap_set_fpga_port(int unit,int sys_port);



/*
   作者:黄力
   功能:创建MPLS_TP_MEP的新函数
   输入:配置MEP的结构体指针
   
   输出:0/1  成功/失败
   说明:    
   		原先的函数已无效；
   		用户要获取 mep_info->mep_index作为MEP的操作句柄。

   时间:20151125

 */
extern 	int fhdrv_fap_oam_create_mep_new(int unit, struct mep_info_s *mep_info);


/*
   作者:张珠玲
   功能:创建MEG 
   输入:meg_id指针 ，12byte可配
   输出:
   说明:

   时间:20141113 

 */

extern int fhdrv_fap_oam_create_group(int unit,int group_id,unsigned char *meg_id);


/*
   作者:张珠玲
   功能:删除mep
   输入:mep_index 即创建mep时mep_info.mep_index
   输出:
   说明:

   时间:20141113 

 */
extern int fhdrv_fap_oam_delete_mep(int unit,int mep_index);

/*
   作者:张珠玲
   功能:删除MEG
   输入:group_id
   输出:
   说明:

   时间:20141113 

 */
extern int fhdrv_fap_oam_delete_group(int unit,int group_id);





/**************************************** F6K OAM 接口函数  **************************************************/

/*
   作者:张珠玲
   功能:创建MEG 
   输入:meg_id指针 ，12byte可配
   输出:
   说明:

   时间:20141113 

 */
extern int fhdrv_psn_tp_oam_create_group(int unit,int group_id,unsigned char *meg_id);


/*
   作者:黄力
   功能:创建MPLS_TP_MEP的新函数
   输入:配置MEP的结构体指针
   
   输出:0/1  成功/失败
   说明:    
   		原先的函数已无效；
   		用户要获取 mep_info->mep_index作为MEP的操作句柄。

   时间:20151125

 */
extern 	int fhdrv_psn_tp_oam_create_mep(int unit, struct mep_info_s *mep_info);



/*****************************************************************************
   函 数 名  : fhdrv_psn_tp_oam_get_count(int unit, int fpga_sysport, int oam_type, char *create_pmf_flag)

   功能描述  :   
   输入参数  :
   修改历史  :
   1.日    期  : 2015年01月15日
   作    者  : throng(throng@fiberhome.com.cn)
*****************************************************************************/
extern int fhdrv_psn_tp_oam_get_count(int unit, int fpga_sysport, int oam_type, char *create_pmf_flag);


/*
   作者:张珠玲
   功能:删除mep
   输入:mep_index 即创建mep时mep_info.mep_index
   输出:
   说明:

   时间:20141113 

 */
extern int fhdrv_psn_tp_oam_delete_mep(int unit,int group_id);

/*
   作者:张珠玲
   功能:删除MEG
   输入:group_id
   输出:
   说明:

   时间:20141113 

 */
extern int fhdrv_psn_tp_oam_delete_group(int unit,int group_id);






/*
   作者:throng
   功能:eth_oam创建group处理接口
   输入:unit芯片号；group_id对应meg_id的编号；*meg_id指针
   输出:
   说明:
   时间:20151225
 */
extern 	int fhdrv_psn_eth_oam_create_group(int unit,int group_id,unsigned char *meg_id); 

/*
   作者:throng
   功能:eth_oam创建mep处理接口
   输入:unit芯片号；group_id对应meg_id的编号；*meg_id指针
   输出:返回mep_index用来删除mep
   说明:
   时间:20151225
 */
 
extern 	int fhdrv_psn_eth_oam_create_mep(int unit, struct mep_info_s *mep_info);

/*
   作者:throng
   功能:删除mep接口
   输入:mep_index
   输出:
   说明:
   时间:20151225
 */
 
extern 	int fhdrv_psn_eth_oam_delete_mep(int unit,int mep_index);

/*
   作者:throng
   功能:删除group接口
   输入:group_id
   输出:
   说明:
   时间:20151225
 */
 
extern 	int fhdrv_psn_eth_oam_delete_group(int unit,int group_id);



/*
   作者:张珠玲
   功能:芯片自动发包使能
   输入:enable =1 使能芯片自动发CCM ; enable = 0 关闭自动发ccm
   输出:
   说明:

   时间:20141113 

 */
extern void fhdrv_fap_oam_enable_tx(int unit,unsigned char enable);

/*
   作者:黄力
   功能:配置双端LM模式
   输入:创建mep时mep_info.mep_index
   
   输出:0/1  成功/失败
   说明:    
			此时LM/CCM帧都会读取COUNT
   时间:20151125

 */
extern int  fhdrv_fap_oam_del_dual_lm(int mep_id);


/*
   作者:黄力
   功能:清除双端LM模式，即回到默认的单端模式
   输入:创建mep时mep_info.mep_index
   
   输出:0/1  成功/失败
   说明:    
			此时只有会读取COUNT
   时间:20151125

 */
extern int   fhdrv_fap_oam_set_dual_lm(int mep_id);

/*
   作者:黄力
   功能:LAG增删成员刷新函数申明
   输入:lag ID
   
   输出:
   说明:    
			
   时间:20151217

 */

extern void api_pp_lag_refresh_after_chg_mem(int tid);

/*
   作者:黄力
   功能:AC 侧ingress 与 egress QOS map id 动态设置函数
   输入:ac lif id，ingress 跟 egress profile值
   
   输出:
   说明:    
			
   时间:20160113

 */

extern void  fhdrv_fap_qos_map_id_l2_in_egress_mode_set(int unit,int ac_lif_id,int ingress_profile,int egress_profile);

/*
   作者:黄力
   功能:AC侧 读取当前ingress/egress侧挂载的profile值
   输入:unit，AC lif id 值
   
   输出:
   说明:    
			
   时间:20160130

 */

extern void fhdrv_fap_qos_map_id_l2_in_egress_mode_get(int unit,int ac_lif_id,int *ingress_profile,int *egress_profile);

/*
   作者:黄力
   功能:PWE 侧 读取当前ingress侧挂载的profile值
   输入:unit，pwe lif id 值
   
   输出:
   说明:    
			
   时间:20160130

 */
extern void fhdrv_fap_qos_map_id_mpls_ingress_mode_get(int unit,int pwe_lif_id,int *ingress_profile);

/*
   作者:黄力
   功能:PWE 侧 ingress QOS map id动态设置函数
   输入:ac lif id，ingress 值
   
   输出:
   说明:    
			
   时间:20160113

 */

extern void fhdrv_fap_qos_map_id_mpls_ingress_mode_set(int unit,int pwe_lif_id,int ingress_profile);

/*
   作者:黄力
   功能:未知帧处理函数
   输入:unit, vpn id , 未知帧丢弃使能flag
   
   输出: 0/1-->执行成功/失败
   说明:    
			
   时间:20160125

 */

extern int api_pp_drop_unknow_unicast_cfg(int unit,int vpn_id,int enb);

/*
   作者:黄力
   功能:tunnel egress profile id fadeback read
   输入:unit, tunnel g_egress_intf_fec_id;
   
   输出: 
   说明:    
			
   时间:20160304

 */


extern void tunnel_egress_profile_id_read(int unit,int g_egress_intf_fec_id,int *egress_profile);

/*
   作者:黄力
   功能:tunnel egress profile id fadeback read
   输入: local_intl_id map_id;
   
   输出: 
   说明:    
			
   时间:20160426

 */
extern int dymnic_tunnel_egress_qos_map_set(int local_intf_id,int map_id );

/*
   作者:黄力
   功能:NEw tunnel egress profile id fadeback read
   输入: sysport local_intl_id map_id;
   
   输出: sysport为sysport 或者0x8000|lag_id
   说明:    
			
   时间:20160912

 */
extern int fhdrv_psn_l2_tunnel_egress_qos_map_set(int sys_port,int local_intf_id,int map_id );

/*
   作者:黄力
   功能:tunnel egress profile id set
   输入:profile id
   
   输出: 
   说明:    
			
   时间:20160304

 */

extern void  fhdrv_fap_qos_map_id_tunnel_egress_set(unsigned egress_profile);

/*************************************************************************
* 函数名  ： init_1588_reg
* 负责人  ：hmliu
* 创建日期： 20160325
* 函数功能： 设置ARAD的1588的主从特性，以同步到FPGA
* 输入参数：
		unit 	单芯片则固定为0
* 输出参数：无
* 返回值：
* 调用关系：
* 其    它：针对一个单盘只调用一次
*************************************************************************/
extern int init_1588_reg(int unit);

/*************************************************************************
* 函数名  ： ieee_1588_trap
* 负责人  ：hmliu
* 创建日期： 20160325
* 函数功能： 设置面板口进的包送到的目的端口
* 输入参数：
		unit 	单芯片则固定为0
	   dest_sys_port   一般就设置为本单盘的FPGA接口的系统端口号
* 输出参数：无
* 返回值：
* 调用关系：
* 其    它：针对一个单盘只调用一次，所有端口共用
*************************************************************************/
extern int ieee_1588_trap(int unit, int fpga_sys_port); 

/*************************************************************************
* 函数名  ： ieee_1588_port_get
* 负责人  ：hmliu
* 创建日期： 20160325
* 函数功能： 获取某端口开关1588功能的状态
* 输入参数：
		port	本地某端口
		enable  0/1   
* 输出参数：无
* 返回值：
* 调用关系：
* 其    它：针对配置，获取本地某端口硬件状态
*************************************************************************/
extern int ieee_1588_port_get(int unit, int  local_port, int *enabled);

/*************************************************************************
* 函数名  ： ieee_1588_port_set
* 负责人  ：hmliu
* 创建日期： 20160325
* 函数功能： 配置某端口开关1588功能
* 输入参数：
		port	本地某端口
		enable  0/1   
* 输出参数：无
* 返回值：
* 调用关系：可后期动态更改
* 其    它：每个端口分别设置
*************************************************************************/
extern int ieee_1588_port_set(int unit, int local_port, int enable);

extern int api_pp_lag_add_member(int unit, int tid,  int modid, int port, int add_exit_mem);

extern int lag_info_add(int lag_id);

extern int update_lag_pp_match_info_lag_remove(int tid);

extern int fhdrv_arad_clk_src_set(int unit,int localPort);

/*************************************************************************
* 函数名  ： fhdrv_psn_port_set_mymac_dynamic
* 负责人  ：huangli
* 创建日期： 20160802
* 函数功能： 动态设置nni侧my mac smac低12bit
* 输入参数：
		my_mac[6]	my mac  
* 输出参数：无
* 返回值：
* 调用关系
* 其    它：
*************************************************************************/
extern void fhdrv_psn_port_set_mymac_low12bits_dynamic(int unit,unsigned short port,unsigned char * my_mac);

/*************************************************************************
* 函数名  ： fhdrv_psn_port_set_mymac_dynamic
* 负责人  ：huangli
* 创建日期： 20160802
* 函数功能： 动态设置nni侧my mac smac高36bit
* 输入参数：
		my_mac[6]	my mac  
* 输出参数：无
* 返回值：
* 调用关系
* 其    它：
*************************************************************************/
extern void fhdrv_psn_set_mymac_high36_dynamic(int unit,unsigned char * my_mac);

/*************************************************************************
* 函数名  ： fhdrv_psn_port_set_mymac_dynamic
* 负责人  ：huangli
* 创建日期： 20160802
* 函数功能： 动态设置nni侧my mac吓一跳dmac
* 输入参数：
		my_mac[6]	my mac  
* 输出参数：无
* 返回值：
* 调用关系
* 其    它：
*************************************************************************/
extern void fhdrv_psn_port_set_mymac_nexthop_dynamic(int unit,unsigned short sys_port,unsigned char * my_mac);

/*************************************************************************
* 函数名  ： fhdrv_psn_lag_trunk_member_flag
* 负责人  ：huangli
* 创建日期： 20160830
* 函数功能： lag id成员删除类型判断nni端口属性设置
* 输入参数：
		aps_lag_flag	0:保护倒换 1:真删 
* 输出参数：无
* 返回值：
* 调用关系
* 其    它：
*************************************************************************/
extern void fhdrv_psn_lag_trunk_member_flag(unsigned short sys_port, unsigned short lag_id, unsigned char aps_lag_flag);

/*************************************************************************
* 函数名  ： fhdrv_psn_trunk_member_update
* 负责人  ：huangli
* 创建日期： 20160903
* 函数功能： lag成员保护删除/添加接口
* 输入参数：
		aps_add	1:保护增加 0:保护删除 
* 输出参数：无
* 返回值：
* 调用关系
* 其    它：之前的lag成员删除增加函数用作实际网管配置的增加删除用
				该函数用作lag成员保护倒换删除添加用
*************************************************************************/
extern int fhdrv_psn_trunk_member_update( int unit, int tid,  int modid, int port ,int update_flag);

/*************************************************************************
* 函数名  ：create_1plus1_protect_id
* 负责人  ：陈舸
* 创建日期：2015.12.18
* 函数功能：创建1+1保护模式下的failover
* 输入参数：unit - 芯片单元; vpn  - vpn id号
			  val - failover_id index
* 输出参数：
* 返回值：  0表示成功, 非0表示失败
* 调用关系：
* 其    它：
*************************************************************************/
extern int create_1plus1_protect_id(int unit, int val);

extern void fhdrv_psn_port_hup_set(int unit,int local_port,int enb);

#ifdef    __cplusplus
}
#endif    /* __cplusplus */

#endif

