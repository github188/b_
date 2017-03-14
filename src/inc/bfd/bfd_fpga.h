/***********************************************************************************

 * 文 件 名   : bfd_fpga.h
 * 负 责 人   : jiangbo,蒋博
 * 创建日期   : 2016年11月1日
 * 版 本 号   : 
 * 文件描述   : bfd_fpga.c 的头文件
 * 版权说明   : Copyright (C) 2000-2016   烽火通信科技股份有限公司
 * 其    他   : 
 * 修改日志   : 

***********************************************************************************/

#ifndef __BFD_FPGA_H__
#define __BFD_FPGA_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */

/* FPGA单盘通用寄存器 */
#define BFD_FPGA_GENERAL_BASE       (0)

/* FPGA中BFD模块基地址 */
#define BFD_FPGA_BFD_MODEL_BASE     (0x2900000)

/* FPGA中BFD适配模块基地址 */
#define BFD_FPGA_BFD_ADAPT_BASE     (0x2b00000)

/* ETH_ANALYSER模块 */
#define BFD_FPGA_BFD_ETH_ANALYSER_BASE     (0x2f00000)

/* FPGA最大的基地址范围 */
#define BFD_FPGA_BFD_ETH_MAX_BASE      (0x3400000)


#define BFD_FPGA_REV_BASE        (0x10000)         /* BFD收向报文头部解析模块 */
#define BFD_FPGA_SESSION_BASE    (0x20000)         /* 接收会话状态基地址 */
#define BFD_FPGA_SEND_BASE       (0x40000)         /* BFD发送模块基地址 */

/* bit15~bit0：抓包端口选择寄存器，选定了抓包端口后，每个端口抓什么包可以在抓包模块内部设置。
   bit[7:0]：
   0x00: 背板收方向抓包（GMII输出）
   0x01: 背板发方向抓包（发送控制输出）
   0x02: 第1个APS背板发方向抓包
   0x04: SSM背板发方向抓包
   0x05: FRR背板发方向抓包
   0x06: MCC背板发方向抓包
   0x07: 第1个PTP_OTN背板发方向抓包
   0x09: 第1个PTP_PTN背板发方向抓包
   0x0b: 测试包模块背板发方向抓包
   0x0c: 第1个PTP_PTN的MGMT_GE侧输出抓包（经过发送控制后，tst_frm_gen包）
   0x0e: 第1个PTP_PTN的MGMT_GE侧输出抓包（经过流控模块后）
   0x10: 第1个PTP_PTN的MGMT_GE侧输入抓包
   0x12: 第1个OHP的HO_GE输入抓包
   0x13: 第2个OHP的HO_GE输入抓包
   0x16: 第1个OHP的HO_GE输出抓包
   0x17: 第2个OHP的HO_GE输出抓包
   0x1a: 第1个OHP的LO1_GE输入抓包
   0x1b: 第2个OHP的LO1_GE输入抓包
   0x1e: 第1个OHP的LO1_GE输出抓包
   0x1f: 第2个OHP的LO1_GE输出抓包
   0x22: 第1个OHP的LO2_GE输入抓包
   0x23: 第2个OHP的LO2_GE输入抓包
   0x26: 第1个OHP的LO2_GE输出抓包
   0x27: 第2个OHP的LO2_GE输出抓包
   0x2a: 第1个DIRCP的GE输入抓包
   0x2b: 第2个DIRCP的GE输入抓包
   0x2e: 第1个ARAD的GE接口输入抓包
   0x2f: 第2个ARAD的GE接口输入抓包
   0x30: 第3个ARAD的GE接口输入抓包
   0x31: 第1个ARAD的GE接口输出抓包
   0x32: 第2个ARAD的GE接口输出抓包
   0x33: 第3个ARAD的GE接口输出抓包
   其它：抓包模块的输入为全0
   注意：
   1、最后3个ARAD芯片GE接口输入输出方向是相对于GE接口侧，其他输入输出的描述均是相对于模块侧。 */
#define BFD_FPGA_PACKET_CAPTURE_CHOOSE                (0x18f)
#define BFD_FPGA_PACKET_CAPTURE_CHOOSE_BFD_RX         (0x3f)
#define BFD_FPGA_PACKET_CAPTURE_CHOOSE_BFD_ADAPT_TX   (0x2e)
#define BFD_FPGA_PACKET_CAPTURE_CHOOSE_GE_TX          (0x31)

/* FPGA中BFD适配模块D10~D0：第N条帧SMAC[42:32] */ /* 属性 R/W */
#define BFD_FGAP_BFD_ADAPT_SMAC     (0x1000)

/* D15~D0：表示第N条主动帧ITMH中的DstSysPort字段 */ /* 属性 R/W */
#define BFD_FGAP_BFD_ADAPT_SYSPORT     (0x2000)

/* 比特[0]：BFD报文流内环，0/1=取消环回/环回 */ /* 属性 R/W */
#define BFD_FPGA_RCV_LOOP       (BFD_FPGA_REV_BASE + 0)

/* 会话二叉树查找表 
   共0x7fe条，每条定义:
   比特[63：48]：条目索引号；
   比特[35:24]：MYID高12位比特；
   比特[19:0]：MYID低20位比特。 */ /* 属性 R/W */
#define BFD_FGPA_RCV_SESSION_TREE  (BFD_FPGA_REV_BASE + 0x4000)

/* FPGA学习到的MYID，在删除会话时写全零,2*N+0x0=高16bit,2*N+0x1=低16bit */ /* 属性 R/W */
#define BFD_FPGA_RCV_MYID    (BFD_FPGA_REV_BASE + 0x8000)  

/* Bit15：每一条BFD报文发送使能。‘1’发送报文。
   Bit14：强制将发送报文周期设为1秒钟的使能，‘1’打开使能，‘0’关闭使能。
   Bit13：为‘0’表示对PW层BFD,ACH=0x10000007；
   为‘1’表示对MPLS-TP协议LSP/PW层BFD，ACH=0x10000022。
   Bit12：VLAN插入使能。‘0’插入一层或二层VLAN值，‘1’不插入VLAN值。在设置为‘1’时，bit6无效。
   Bit10：BFD控制报文中C字段为‘1’表示BFD的实现是独立于控制平面的。
   Bit9-8：表明每一条BFD报文发帧类型。
   0x0：发送格式为DA+SA+（0X8100+VLAN 1）+（0X8100+VLAN2）+0X0800/0x86DD+ IP header +UDP header +BFD PDU；
   0x1：发送格式为DA+SA+（0X8100+VLAN 1）+（0X8100+VLAN2）+0X8847+LABEL1 + IP header +UDP header +BFD PDU；
   0x2：发送格式为DA+SA+（0X8100+VLAN 1）+（0X8100+VLAN2）+0X8847+LABEL1
   +LABEL2+ACH+ BFD PDU，其中ACH=0x10000007/0x10000022；
   0x3：发送格式为DA+SA+（0X8100+VLAN 1）+（0X8100+VLAN2）+0X8847+LABEL1
   +LABEL2+ LABEL3+ IP header +UDP header +BFD PDU。
   Bit6：插入VLAN层数选择，‘0’表示插入一层VLAN，‘1’表示插入两层VLAN。
   Bit5：IP报文头选择，‘0’表示BFD报文中IP头为IPV4；‘1’表示BFD报文中IP头为IPV6。
   Bit1-0：‘00’表示UDP宿端口值为3784，‘01’表示UDP宿端口值为4784, ‘10’表示UDP宿端口值为6784 */
#define BFD_FPGA_SEND_FUNCTION   (BFD_FPGA_SEND_BASE + 0x1000) /* 属性 R/W */

/* 宿MAC（DMAC）地址; 4*N+0x1=MAC地址bit48-33, 4*N+0x2=MAC地址bit32-17, 4*N+0x3=MAC地址bit16-1 */
#define BFD_FPGA_SEND_DMAC   (BFD_FPGA_SEND_BASE + 0x2000) /* 属性 R/W */

/* 源MAC（SMAC）地址; 4*N+0x1=MAC地址bit48-33, 4*N+0x2=MAC地址bit32-17, 4*N+0x3=MAC地址bit16-1 */
#define BFD_FPGA_SEND_SMAC   (BFD_FPGA_SEND_BASE + 0x12000) /* 属性 R/W */

/* Bit15-13：VLAN1优先级值（PRI1）,0-7；Bit12：保留位（CF1）；Bit11-0：VLAN1值（VID1），表示报文出口 */
#define BFD_FPGA_SEND_SVLAN    (BFD_FPGA_SEND_BASE + 0x14000) /* 属性 R/W */

/* Bit15-13：VLAN2优先级值（PRI2）,0-7；Bit12：保留位（CF2）；Bit11-0：VLAN2值（VID2），表示包内容中的VLAN ID值 */
#define BFD_FPGA_SEND_CVLAN    (BFD_FPGA_SEND_BASE + 0x15000) /* 属性 R/W */

/* IPV4或IPv6中第1个和第2个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPv4_TOS   (BFD_FPGA_SEND_BASE + 0x4000)  /* 4bit version，4bit header length，8bit TOS */
#define BFD_FPGA_SEND_IPV6_TC_FL (BFD_FPGA_SEND_BASE + 0x4000) /* 4bit version,8 bit traffic calss,
                                                                  4bit flow label高4位 */

/* IPV4或IPv6中第3个和第4个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV4_TOTAL_LEN    (BFD_FPGA_SEND_BASE + 0x5000)   /* total length */
#define BFD_FPGA_SEND_IPV6_FLOW_LABEL   (BFD_FPGA_SEND_BASE + 0x5000)   /* flow label低16位 */

/* IPV4或IPv6中第5个和第6个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV4_IDENTIFIER   (BFD_FPGA_SEND_BASE + 0x6000)   /* identifier */
#define BFD_FPGA_SEND_IPV6_PAYLOAD_LEN   (BFD_FPGA_SEND_BASE + 0x6000)  /* payload length */

/* IPV4或IPv6中第7个和第8个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV4_FLAG_FRAMOFF         (BFD_FPGA_SEND_BASE + 0x7000)   /* 3 bit flag,13 bit fragment offset */
#define BFD_FPGA_SEND_IPV6_NEXTHEAD_HOPLIMIT    (BFD_FPGA_SEND_BASE + 0x7000)   /* 8 bit next header,8 bit hop limit */

/* IPV4或IPv6中第9个和第10个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV4_TTL_PROTOCOL     (BFD_FPGA_SEND_BASE + 0x16000)  /* 8 bit TTL,8 bit protocal */
#define BFD_FPGA_SEND_IPV6_SRC1TO2          (BFD_FPGA_SEND_BASE + 0x16000)  /* 源MAC，从高到底，1-2字节 */

/* IPV4或IPv6中第11个和第12个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV4_CHECKSUM     (BFD_FPGA_SEND_BASE + 0x17000)  /* header checksum */
#define BFD_FPGA_SEND_IPV6_SRC3TO4      (BFD_FPGA_SEND_BASE + 0x17000)  /* 源IP，从高到底，3-4字节 */

/* IPV4或IPv6中第13个和第14个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV4_SRC1TO2     (BFD_FPGA_SEND_BASE + 0x18000)  /* 源IP，从高到底，1-2字节 */
#define BFD_FPGA_SEND_IPV6_SRC5TO6     (BFD_FPGA_SEND_BASE + 0x18000)  /* 源IP，从高到底，5-6字节 */

/* IPV4或IPv6中第15个和第16个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV4_SRC3TO4     (BFD_FPGA_SEND_BASE + 0x19000)  /* 源IP，从高到底，3-4字节 */
#define BFD_FPGA_SEND_IPV6_SRC7TO8     (BFD_FPGA_SEND_BASE + 0x19000)  /* 源IP，从高到底，7-8字节 */

/* IPV4或IPv6中第17个和第18个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV4_DEC1TO2     (BFD_FPGA_SEND_BASE + 0x1a000)  /* 目的IP，从高到底，1-2字节 */
#define BFD_FPGA_SEND_IPV6_SRC9TO10    (BFD_FPGA_SEND_BASE + 0x1a000)  /* 源IP，从高到底，9-10字节 */

/* IPV4或IPv6中第19个和第20个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV4_DEC3TO4     (BFD_FPGA_SEND_BASE + 0x1b000)  /* 目的IP，从高到底，3-4字节 */
#define BFD_FPGA_SEND_IPV6_SRC11TO12   (BFD_FPGA_SEND_BASE + 0x1b000)  /* 源IP，从高到底，11-12字节 */

/* IPV6头中第21个和第22个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV6_SRC13TO14   (BFD_FPGA_SEND_BASE + 0x1c000)  /* 源IP，从高到底，13-14字节 */

/* IPV6头中第23个和第24个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV6_SRC15TO16   (BFD_FPGA_SEND_BASE + 0x1d000)  /* 源IP，从高到底，15-16字节 */

/* IPV6头中第25个和第26个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV6_DEC1TO2     (BFD_FPGA_SEND_BASE + 0x1e000)  /* 目的IP，从高到底，1-2字节 */

/* IPV6头中第27个和第28个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV6_DEC3TO4     (BFD_FPGA_SEND_BASE + 0x1f000)  /* 目的IP，从高到底，3-4字节 */

/* IPV6头中第29个和第30个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV6_DEC5TO6     (BFD_FPGA_SEND_BASE + 0x20000)  /* 目的IP，从高到底，5-6字节 */

/* IPV6头中第31个和第32个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV6_DEC7TO8     (BFD_FPGA_SEND_BASE + 0x21000)  /* 目的IP，从高到底，7-8字节 */

/* IPV6头中第33个和第34个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV6_DEC9TO10    (BFD_FPGA_SEND_BASE + 0x22000)  /* 目的IP，从高到底，9-10字节 */

/* IPV6头中第35个和第36个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV6_DEC11TO12   (BFD_FPGA_SEND_BASE + 0x23000)  /* 目的IP，从高到底，11-12字节 */

/* IPV6头中第37个和第38个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV6_DEC13TO14   (BFD_FPGA_SEND_BASE + 0x24000)  /* 目的IP，从高到底，13-14字节 */

/* IPV6头中第39个和第40个字节 */ /* 属性 R/W */
#define BFD_FPGA_SEND_IPV6_DEC15TO16   (BFD_FPGA_SEND_BASE + 0x25000)  /* 目的IP，从高到底，15-16字节 */

/* UDP源端口 */ /* 属性 R/W */
#define BFD_FPGA_SEND_UPD_SPORT   (BFD_FPGA_SEND_BASE + 0x8000)

/* UDP头和后续DATA的总长度 */ /* 属性 R/W */
#define BFD_FPGA_SEND_UPD_LEN   (BFD_FPGA_SEND_BASE + 0x9000)

/* BFD报文长度，默认值为24 */ /* 属性 R/W */
#define BFD_FPGA_SEND_BFD_LEN   (BFD_FPGA_SEND_BASE + 0xa000)

/* BFD报文本地会话标识符（My Discriminator）; 2*N+0x0=高16bit,2*N+0x1=低16bit */ /* 属性 R/W */
#define BFD_FPGA_SEND_MYID   (BFD_FPGA_SEND_BASE + 0xb000) 

/* BFD报文远端会话标识符（Your Discriminator）; 2*N+0x0=高16bit,2*N+0x1=低16bit */ /* 属性 R/W */
#define BFD_FPGA_SEND_YID    (BFD_FPGA_SEND_BASE + 0xc000) 

/* 2*N+0x0:Bit15-11：BFD报文诊断码（Diag），表明发送方最近一次会话down的原因。
   2*N+0x0:Bit10-9：BFD当前会话状态（Sta），0-AdminDown，1-Down，2-Init，3-Up。
   2*N+0x0:Bit7-0：检测时间倍数（Detect Mult）。默认值为3。
   2*N+0x1:Bit15-11：本端支持的最小发送间隔（Desired Min TX Interval），
   2*N+0x1:Bit10-6：本端支持的最小接收间隔（Required Min RX Interval）。
           用5位编码表示上述2个间隔,对应关系如下所示：
           0x01h：时间间隔为3.3ms；
           0x02h：时间间隔为10ms；
           0x03h：时间间隔为20ms；
           0x04h：时间间隔为30ms；
           0x05h：时间间隔为40ms；
           0x06h：时间间隔为50ms；
           0x07h：时间间隔为60ms；
           0x08h：时间间隔为70ms；
           0x09h：时间间隔为80ms；
           0x0ah：时间间隔为90ms；
           0x0bh：时间间隔为100ms；
           0x0ch：时间间隔为200ms；
           0x0dh：时间间隔为300ms；
           0x0eh：时间间隔为400ms；
           0x0fh：时间间隔为500ms；
           0x10h：发送间隔为150ms；
           0x11h：发送间隔为250ms；
           0x12h：发送间隔为350ms；
           0x13h：发送间隔为450ms；
           0x14h：时间间隔为 1s。 */ /* 属性 R/W */
#define BFD_FPGA_SEND_DIAG_STA_DM_INTERVAL    (BFD_FPGA_SEND_BASE + 0xd000)

/* Bit4-0：表明本端每一条BFD报文实际发送时间间隔。默认值为1s。可由软件读取。
   Bit4-0为0x01h：发送间隔为3.3ms；
           0x02h：发送间隔为10ms；
           0x03h：发送间隔为20ms；
           0x04h：发送间隔为30ms；
           0x05h：发送间隔为40ms；
           0x06h：发送间隔为50ms；
           0x07h：发送间隔为60ms；
           0x08h：发送间隔为70ms；
           0x09h：发送间隔为80ms；
           0x0ah：发送间隔为90ms；
           0x0bh：发送间隔为100ms；
           0x0ch：发送间隔为200ms；
           0x0dh：发送间隔为300ms；
           0x0eh：发送间隔为400ms；
           0x0fh：发送间隔为500ms；
           0x10h：发送间隔为150ms；
           0x11h：发送间隔为250ms；
           0x12h：发送间隔为350ms；
           0x13h：发送间隔为450ms；
           0x14h：发送间隔为 1s。 */ /* 属性 R */
#define BFD_FPGA_SEND_WORK_INTERVAL    (BFD_FPGA_SEND_BASE + 0xe000)

/* 发送BFD帧格式中，LABEL1; 2*N+0x0=高16bit,2*N+0x1=低16bit */ /* 属性 R/W */
#define BFD_FPGA_SEND_LSP_LABEL   (BFD_FPGA_SEND_BASE + 0x10000)

/* 发送BFD帧格式中，LABEL2; 2*N+0x0=高16bit,2*N+0x1=低16bit */ /* 属性 R/W */
#define BFD_FPGA_SEND_PW_LABEL   (BFD_FPGA_SEND_BASE + 0x11000)

/* 发送第四种BFD帧格式中，LABEL3，可配置成ACH=0x10000021(IPV4), ACH=0x10000057(IPV6)；2*N+0x0=高16bit,2*N+0x1=低16bit */
/* 属性 R/W */
#define BFD_FPGA_SEND_ACH_LABEL   (BFD_FPGA_SEND_BASE + 0x26000)

/* 收到接收模块超时down的个数 */ /* 属性 R */
#define BFD_FPGA_SEND_TIMER_DOWN_COUNT   (BFD_FPGA_SEND_BASE + 0x27000)

/* 收到接收模块对端down的个数 */ /* 属性 R */
#define BFD_FPGA_SEND_REMOTE_DOWN_COUNT   (BFD_FPGA_SEND_BASE + 0x28000)

/* Bit1-0：本端支持的最小发送间隔（Desired Min TX Interval）和本端支持的最小接收间隔（Required
   Min RX Interval）中任何一个需要被修改，由软件写‘0x11’，启动投票进程。由FPGA内部清零 */ /* 属性 R/W */
#define BFD_FPGA_SEND_INTERVAL_MODIFY   (BFD_FPGA_SEND_BASE + 0x2a000)

/* 发送帧计数 */ /* 属性 R */
#define BFD_FPGA_SEND_COUNT   (BFD_FPGA_SEND_BASE + 0xf000)

/* 比特[15]：条目N的BFD告警实时状态
   比特[14]:条目N的BFD告警变化指示，读清。
   比特[13]：条目N的STATE历史变化，为1表示有新包来，并且上一帧和新的一帧STATE不是都为UP。
   比特[8：7]：条目N的接收STATE值。
   比特[6：2：条目N的DIAG 值。
   比特[1：0]：COUNT自动累加翻转值。
   建议:如果条目N的BFD告警实时状态为"1"，则相应条目的比特[8:7]接收STATE值不可用，为寄存器历史残留数据，请根据超时告警迁
   移BFD状态机 */ /* 属性 R */
#define BFD_FPGA_SESSION_DIAG_STATE     (BFD_FPGA_SESSION_BASE + 0x800)

/* 收包实际工作周期值的比特[15：0]。（以MS 为单位） */ /* 属性 R */
#define BFD_FPGA_SESSION_WORK_INTERVAL_LOW  (BFD_FPGA_SESSION_BASE + 0x1000)

/* 收包实际工作周期值的比特[31：16]。（以MS 为单位） */ /* 属性 R */
#define BFD_FPGA_SESSION_WORK_INTERVAL_HIGH (BFD_FPGA_SESSION_BASE + 0x1800)

/* 接收的正确BFD报文计数 */ /* 属性 Rclear */
#define BFD_FPGA_SESSION_RECV_COUNT         (BFD_FPGA_SESSION_BASE + 0x2800)

/* [7：0]比特。主盘CPU向备盘传递的STATE—DIAG信息 */ /* 属性 R/W */
#define BFD_FPGA_SESSION_SEND_STATE_DIAG    (BFD_FPGA_SESSION_BASE + 0x3000)

/* [7：0]比特。备盘接收的主盘CPU发来的当前会话STATE—DIAG信息 */ /* 属性 R */
#define BFD_FPGA_SESSION_RECV_STATE_DIAG    (BFD_FPGA_SESSION_BASE + 0x3800)

/* 期望MYID，2*N+0x0=高16bit,2*N+0x1=低16bit */ /* 属性 R/W */
#define BFD_FPGA_SESSION_REQUIRED_MYID    (BFD_FPGA_SESSION_BASE + 0x4000)

/* 比特[0]:MID比较丢弃开关。“1”表示开 */ /* 属性 R/W */
#define BFD_FPGA_SESSION_REQUIRED_MYID_SWITCH    (BFD_FPGA_SESSION_BASE + 0x5000)

/* Bit[0]条目N的会话up到down检测开关, ‘1’使能打开，‘0’使能关闭。
   Bit[5:4]条目N的会话up到down检测开关打开时，该条目会话down原因，‘1’超时down，‘3’对端down。调试用，只读，读清。
   Bit[11:8]条目N的会话up到down检测开关打开时，收到对端down报文次数计数。调试用，只读，读清。
   Bit[15:12]条目N的会话up到down检测开关打开时，记录本端超时告警次数计数。调试用，只读，读清 */ /* 属性 R/W */
#define BFD_FPGA_SESSION_UP_TO_DOWN_STA (BFD_FPGA_SESSION_BASE + 0x5800)

/* bit[15]:BFD收向入端口信息校验使能，0/1=不使能/使能；
   bit[12:0] 入端口信息。Bit12~bit8槽位号，bit7 LAG标志，Bit6~bit5子卡号，Bit4~bit0端口号
   其余bit保留 */ /* 属性 R/W */
#define BFD_FPGA_SESSION_CHEKSUM    (BFD_FPGA_SESSION_BASE + 0x6000)

/* 入端口信息校验错误包计数 */ /* 属性 RC */
#define BFD_FPGA_SESSION_ERROR_COUNT    (BFD_FPGA_SESSION_BASE + 0x6800)

/* 收向RMRI与本端配置dmti不匹配告警 */ /* 属性 R */
#define BFD_FPGA_SESSION_INTERVAL_NOT_MATCH    (BFD_FPGA_SESSION_BASE + 0x7000)


#define BFD_FPGA_ULONG_HIGH(N)    (2 * (N) + 0x0)      /* FPGA中4字节参数的高16位 */
#define BFD_FPGA_ULONG_LOW(N)     (2 * (N) + 0x1)      /* FPGA中4字节参数的低16位 */
#define BFD_FPGA_MAC_HIGH(N)      (4 * (N) + 0x1)      /* FPGA中MAC地址参数的高16位 */
#define BFD_FPGA_MAC_MIDDLE(N)    (4 * (N) + 0x2)      /* FPGA中MAC地址参数的中间16位 */
#define BFD_FPGA_MAC_LOW(N)       (4 * (N) + 0x3)      /* FPGA中MAC地址参数的低16位 */

/* 两个2字节拼成一个4字节 */
#define BFD_GET_ULONG_FROM_TWO_USHORT(high, low)    (((high) << 16) | (low))

/* 2字节分拆成两个1字节 */
#define BFD_GET_UCHAR_FORM_USHORT(src, high, low)   \
do                                                  \
{                                                   \
    (high) = ((src) >> 8) & DRV_BYTE_INVALID;       \
    (low) = (src) & DRV_BYTE_INVALID;               \
}while(0);

/* 4字节分拆成两个2字节 */
#define BFD_GET_USHORT_FORM_ULONG(src, high, low)   \
do                                                  \
{                                                   \
    (high) = ((src) >> 16) & DRV_USHORT_INVALID;    \
    (low) = (src) & DRV_USHORT_INVALID;             \
}while(0);

/* 4字节分拆成四个1字节 */
#define BFD_GET_UCHAR_FORM_ULONG(src, higher, high, low, lower)     \
do                                                                  \
{                                                                   \
    (higher) = ((src) >> 24) & DRV_BYTE_INVALID;                    \
    (high) = ((src) >> 16) & DRV_BYTE_INVALID;                      \
    (low) = ((src) >> 8) & DRV_BYTE_INVALID;                        \
    (lower) = (src) & DRV_BYTE_INVALID;                             \
}while(0);

/* 比特[15]：条目N的BFD告警实时状态
   比特[14]:条目N的BFD告警变化指示，读清。
   比特[13]：条目N的STATE历史变化，为1表示有新包来，并且上一帧和新的一帧STATE不是都为UP。
   比特[8：7]：条目N的接收STATE值。
   比特[6：2：条目N的DIAG 值。
   比特[1：0]：COUNT自动累加翻转值。
   建议:如果条目N的BFD告警实时状态为"1"，则相应条目的比特[8:7]接收STATE值不可用，为寄存器历史残留数据，请根据超时告警迁
   移BFD状态机 */
typedef struct bfd_fpga_reg_diag_state
{
    BITFIELDS7(
    NBB_USHORT timer_alarm:1,   /* BFD告警实时状态 */
    NBB_USHORT alarm_flag:1,    /* BFD告警变化指示，读清 */
    NBB_USHORT new_packet:1,    /* STATE历史变化，为1表示有新包来，并且上一帧和新的一帧STATE不是都为UP */
    NBB_USHORT usReserved:4,    /* 保留字节 */
    NBB_USHORT packet_state:2,  /* 接收STATE值 */
    NBB_USHORT diag:5,          /* DIAG 值 */
    NBB_USHORT count:2);         /* COUNT自动累加翻转值 */
}BFD_FPGA_REG_DIAG_STATE;

/* BFD状态和包间隔,按照寄存器定义 */
typedef struct bfd_fpga_reg_state_diag
{
    BITFIELDS4(
    NBB_USHORT usDiag:5,         /* BFD报文诊断码 */
    NBB_USHORT usSta:2,          /* BFD当前会话状态0-AdminDown，1-Down，2-Init，3-Up */
    NBB_USHORT usReserved: 1,
    NBB_USHORT usDectMult: 8);
}BFD_FPGA_REG_STATE_DIAG;

/* BFD收发包周期,按照寄存器定义 */
typedef struct bfd_fpga_reg_interval
{
    BITFIELDS4(
    NBB_USHORT usTxInterval:5,
    NBB_USHORT usRxInterval:5,
    NBB_USHORT usReserved:5,
    NBB_USHORT usModify:1);      /* 是否需要修改参数 */
}BFD_FPGA_REG_INTERVAL;

typedef struct bfd_fpga_reg_fuction
{
    BITFIELDS12(
    NBB_USHORT usSendFlag:1,   /* 发送使能标记位，1表示发送 */
    NBB_USHORT usSendIntval:1, /* 强制将发送报文周期设为1秒钟的使能，'1'打开使能，'0'关闭使能 */
    NBB_USHORT usPWtype:1,     /*  为'0'表示对PW层BFD,ACH=0x10000007；为'1'表示对MPLS-TP协议LSP/PW层BFD，ACH=0x10000022 */
    NBB_USHORT usVlanAble:1,   /* 内层VLAN插入使能。'1'不插入VLAN值 */
    NBB_USHORT usReserved1:1,  /* 保留 */
    NBB_USHORT usCtype:1,      /* BFD控制报文中C字段为'1'表示BFD的实现是独立于控制平面的 */
    NBB_USHORT usSendType:2,   /* 表明每一条BFD报文发帧类型,0x0：以BFD for IP帧格式发送，0x1：以BFD for LSP帧格式发送，
                                  0x2：以BFD for 无IP头有ACH头帧格式发送，0x3：以BFD for有LSP标签、PW标签 有ACH头有IP头帧格式发送 */
    NBB_USHORT usReserved2:1,  /* 保留 */                                    
    NBB_USHORT usVlanNum:1,    /* 插入VLAN层数选择，'0'表示插入一层VLAN，'1'表示插入两层VLAN */   
    NBB_USHORT usIpType:1,     /* ipv4 or ipv6头 */
    NBB_USHORT usReserved3:3,  /* 保留 */
    NBB_USHORT usUDPtype:2);   /* '0'表示UDP宿端口值为3784，'1'表示UDP宿端口值为4784，'2'表示UDP宿端口值为6784 */
}BFD_FPGA_REG_FUCTION;

typedef struct bfd_mpls_label
{
    BITFIELDS4(
    NBB_ULONG ulMplsLabel : 20,  /* 标签值 */
    NBB_ULONG ulExp       : 3,   /* 优先级 */
    NBB_ULONG ulStack     : 1,   /* 栈底标志 */
    NBB_ULONG ulTtl       : 8);  /* TTL值 */
}BFD_MPLS_LABEL;

typedef struct bfd_fpga_mpls_label
{
    BFD_MPLS_LABEL lsp_label;
    BFD_MPLS_LABEL pw_label;
    NBB_ULONG      ach;
}BFD_FPGA_MPLS_LABEL;

typedef struct bfd_fpga_reg_ip_head_ver_tos
{
    BITFIELDS4(
    NBB_USHORT version   : 4,  /* IP版本号 */
    NBB_USHORT head_len  : 4,  /* IP头长度，单位为DWORD,4字节 */
    NBB_USHORT recedence : 3,  /* 优先级 */
    NBB_USHORT tos       : 5); /* 服务类型 */
}BFD_FPGA_REG_IP_HEAD_VER_TOS;

typedef struct bfd_fpga_tree
{
    unsigned short level;           /* 会话二叉树的层数，每个业务盘FPGA支持2k会话，因此层数为11 */
    unsigned short lsp_no_max;      /* 会话最大条目号 */
    BFD_PUL_TREE_BASE tree_base;    /* 会话存储二叉树每一层的相对地址 */
    SPM_OAMTREE_SET  node_set;      /* 存储BFD会话二叉树的结点设置的内容，1kBFD会话 */
}BFD_FPGA_TREE;

typedef struct bfd_fpga_global
{
    unsigned int fpga_base_mcard;       /* FPGA映射到内存的基地址 */
    BFD_FPGA_TREE bfd_my_id_tree;       /* FPGA使用的BFD本地描述符二叉树 */
}BFD_FPGA_GLOBAL;

#define MAC_LENGTH  6
typedef struct bfd_eth_mac
{
    unsigned char des_mac[MAC_LENGTH];   /*目的mac地址*/
    unsigned char src_mac[MAC_LENGTH];   /*源mac地址*/
}BFD_ETH_MAC;

typedef struct bfd_state
{
    unsigned char diag;     /* 错误码 */
    unsigned char state;    /* BFD状态 */
}BFD_STATE;

typedef struct bfd_interval
{
    unsigned char required_min_rx_interval;
    unsigned char desired_min_tx_interval;
    unsigned char detect_mult;
}BFD_INTERVAL;

typedef struct bfd_ip_head
{
    unsigned char type;
    unsigned char tos;  /*服务类型*/
    unsigned short total_length;    /*IP头和后续DATA的总长度。高7bit固定为0*/
    unsigned long local_ip[ATG_DCI_IPV6_LEN];   /* 本地IP地址（IPv4地址取组后4字节） */
    unsigned long remote_ip[ATG_DCI_IPV6_LEN];  /* 远端IP地址（IPv4地址取组后4字节） */
}BFD_IP_HEAD;

typedef struct bfd_udp_head
{
    unsigned short src_port;
    unsigned short udp_len;
    unsigned short data_len;
}BFD_UDP_HEAD;

typedef struct bfd_discr
{
    unsigned long my_id;
    unsigned long peer_id;
}BFD_DISCR;

typedef struct bfd_label
{
    unsigned long lsp_label;
    unsigned long pw_label;
    unsigned long ach;
}BFD_LABEL;

typedef struct bfd_function
{
    unsigned char send_flag;                  /* 会话发送使能标记 */
    unsigned char detection_type;             /*检测类型0=单跳检测1=多跳检测*/
    unsigned short vlan_able;                 /* 内层VLAN插入使能。'1'不插入VLAN值 */
    unsigned short vlan_num;                  /* 插入VLAN层数选择，'0'表示插入一层VLAN，'1'表示插入两层VLAN */
    unsigned char pw_type;                    /* PW ACH封装格式,为‘0’表示对PW层BFD,ACH=0x10000007；
                                                 为'1'表示对MPLS-TP协议LSP/PW层BFD，ACH=0x10000022。 */
}BFD_FUNCTION;

typedef struct bfd_sysport
{
    unsigned short des_fapid;
    unsigned short local_sysport;
}BFD_SYSPORT;

typedef struct bfd_fpga_send_cfg
{
    unsigned char frame_type;       /*FPGA BFD报文发帧类型*/
    BFD_FUNCTION function;
    BFD_SYSPORT sysport;
    BFD_ETH_MAC eth_mac;
    BFD_LABEL   label;
    BFD_IP_HEAD ip;
    BFD_UDP_HEAD udp;
    BFD_DISCR   discr;
    BFD_STATE   state;
    BFD_INTERVAL interval;
}BFD_FPGA_SEND_CFG;

typedef struct bfd_fpga_session_info
{
    BFD_FPGA_REG_DIAG_STATE diag_state;
}BFD_FPGA_SESSION_INFO;

typedef struct bfd_fpga_info
{
    unsigned short index;                   /* 数组下标 */
    BFD_FPGA_SEND_CFG send_cfg;
    BFD_FPGA_SESSION_INFO session_info;
}BFD_FPGA_INFO;

extern BFD_FPGA_GLOBAL g_bfd_fpga_global;



extern RESULT_BFDCFG bfd_add_fpga_session_tree(IN unsigned short index, IN unsigned long my_sid);
extern RESULT_BFDCFG bfd_clear_fpga(IN unsigned short index);
extern RESULT_BFDCFG bfd_del_fpga(IN unsigned short index, IN unsigned long my_sid);
extern RESULT_BFDCFG bfd_del_fpga_session_tree(IN unsigned short index, IN unsigned long my_sid);
extern RESULT_BFDCFG bfd_get_fpga_bfd_discr(IN unsigned short index, OUT BFD_DISCR *discr);
extern RESULT_BFDCFG bfd_get_fpga_capture_choose(OUT unsigned short *cap_choose);
extern RESULT_BFDCFG bfd_get_fpga_function(IN unsigned short index, OUT BFD_FPGA_REG_FUCTION *fuction_info);
extern RESULT_BFDCFG bfd_get_fpga_info(IN unsigned short index, IN BFD_BASIC_DATA *cfg, IN TP_OAM_LSP_CFG *oam_traffic_info,
             OUT BFD_FPGA_INFO *fpga_info);
extern RESULT_BFDCFG bfd_get_fpga_ip(IN unsigned short index, OUT BFD_IP_HEAD *ip_head);
extern RESULT_BFDCFG bfd_get_fpga_ipv4(IN unsigned short index, OUT BFD_IP_HEAD *ip_head);
extern RESULT_BFDCFG bfd_get_fpga_ipv6(IN unsigned short index, OUT BFD_IP_HEAD *ip_head);
extern RESULT_BFDCFG bfd_get_fpga_label(IN unsigned short index, OUT BFD_FPGA_MPLS_LABEL *label);
extern RESULT_BFDCFG bfd_get_fpga_mac(IN unsigned short index, OUT BFD_ETH_MAC *eth_mac, OUT unsigned short *fpga_reg_index);
extern RESULT_BFDCFG bfd_get_fpga_send_count(IN unsigned short index, OUT unsigned short *sent_count);
extern RESULT_BFDCFG bfd_get_fpga_send_work_interval(IN unsigned short index, OUT unsigned short *send_interval);
extern RESULT_BFDCFG bfd_get_fpga_session_anti_attack(IN unsigned short index,
             OUT unsigned long *your_id,
             OUT unsigned short *enable);
extern RESULT_BFDCFG bfd_get_fpga_session_recv_count(IN unsigned short index, OUT unsigned short *recv_count);
extern RESULT_BFDCFG bfd_get_fpga_session_state(IN unsigned short index, OUT BFD_FPGA_REG_DIAG_STATE *diag_state);
extern RESULT_BFDCFG bfd_get_fpga_session_up_to_down_sta(IN unsigned short index, OUT SPM_BFD_UP_TO_DOWN_STA *up_to_down_state);
extern RESULT_BFDCFG bfd_get_fpga_session_work_interval(IN unsigned short index, OUT unsigned long *recv_interval);
extern RESULT_BFDCFG bfd_get_fpga_state_interval(IN unsigned short index, OUT BFD_FPGA_REG_STATE_DIAG *state_diag,
             OUT BFD_FPGA_REG_INTERVAL *interval);
extern RESULT_BFDCFG bfd_get_fpga_sysport(IN unsigned short index, OUT BFD_SYSPORT *sysport);
extern RESULT_BFDCFG bfd_get_fpga_udp(IN unsigned short index, OUT BFD_UDP_HEAD *udp);
extern RESULT_BFDCFG bfd_init_fpga();
extern RESULT_BFDCFG bfd_set_fpga(IN BFD_FPGA_INFO *fpga_info);
extern RESULT_BFDCFG bfd_set_fpga_bfd_discr(IN unsigned short index, IN BFD_DISCR *discr);
extern RESULT_BFDCFG bfd_set_fpga_function(IN unsigned short index, IN unsigned char frame_type,
             IN unsigned char ip_type, IN BFD_FUNCTION *function);
extern RESULT_BFDCFG bfd_set_fpga_ip(IN unsigned short index, IN BFD_IP_HEAD *ip);
extern RESULT_BFDCFG bfd_set_fpga_ipv4(IN unsigned short index, IN BFD_IP_HEAD *ip);
extern RESULT_BFDCFG bfd_set_fpga_ipv6(IN unsigned short index, IN BFD_IP_HEAD *ip);
extern RESULT_BFDCFG bfd_set_fpga_label(IN unsigned short index, IN unsigned char frame_type, IN BFD_LABEL *label);
extern RESULT_BFDCFG bfd_set_fpga_mac(IN unsigned short index, IN BFD_ETH_MAC *eth_mac);
extern RESULT_BFDCFG bfd_set_fpga_session_anti_attack(IN unsigned short index, IN unsigned long your_id, IN NBB_BOOL enable);
extern RESULT_BFDCFG bfd_set_fpga_session_up_to_down_sta(IN unsigned short index, IN NBB_BOOL enable);
extern RESULT_BFDCFG bfd_set_fpga_state_interval(IN unsigned short index, IN BFD_STATE *state,
             IN BFD_INTERVAL *interval, IN NBB_BOOL is_modify);
extern RESULT_BFDCFG bfd_set_fpga_sysport(IN unsigned short index, IN BFD_SYSPORT *sysport);
extern RESULT_BFDCFG bfd_set_fpga_udp(IN unsigned short index, IN BFD_UDP_HEAD *udp);
extern unsigned short oam_fpga_16bits_read(IN unsigned long fpga_base_addr, IN unsigned long fpga_offset);
extern int oam_fpga_16bits_write(IN unsigned long fpga_base_addr, IN unsigned long fpga_offset, IN unsigned short data);
extern unsigned long oam_fpga_32bits_read(IN unsigned long fpga_base_addr, IN unsigned long fpga_offset);
extern int oam_fpga_32bits_write(unsigned long fpga_base_addr, unsigned long fpga_offset, unsigned long data);
extern RESULT_BFDCFG read_fpga_mmap(IN unsigned long base_offset, IN unsigned long offset, OUT unsigned short *data);
extern RESULT_BFDCFG read_fpga_mmap_32b(IN unsigned long base_offset, IN unsigned long offset, OUT unsigned long *data);
extern NBB_VOID spm_bfd_rebuild_session_tree_fpgareg();
extern NBB_INT spm_bfd_tree_get_fpga_data(IN SPM_OAMTREE_NODE* oamTreeNode,
             OUT SPM_FPGATREE_DATA *fpgaTreeDate);
extern NBB_INT spm_bfd_tree_set_data(IN NBB_USHORT index,
             IN NBB_ULONG ulDrim,
             OUT SPM_OAMTREE_NODE *pstBfdTreeNode);
extern RESULT_BFDCFG write_fpga_mmap(IN unsigned long base_offset, IN unsigned int offset, IN unsigned short data);
extern RESULT_BFDCFG write_fpga_mmap_32b(IN unsigned long base_offset, IN unsigned int offset, IN unsigned long data);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BFD_FPGA_H__ */
