#ifndef BMU_LIB_V3_H
#define BMU_LIB_V3_H

#ifdef  __cplusplus
extern  "C" {
#endif  /* __cplusplus */

/*****************************************************************************
* 函 数 名  : reg_board
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月17日
* 函数功能  : 在应用层注册一个单盘
* 输入参数  : UINT16 addr  单盘地址一般等于槽位号
               UINT32 code  板子代码，例如0x03000387
* 输出参数  : 无
* 返 回 值  :
* 调用关系  :
* 其    它  :

*****************************************************************************/
unsigned int reg_board(UINT16 addr, UINT32 code);

/*****************************************************************************
* 函 数 名  : del_all_boards
* 负 责 人  : zhaojzh
* 创建日期  : 2014年1月2日
* 函数功能  : 删除所有单盘
* 输入参数  : 无
* 输出参数  : 无
* 返 回 值  : 删除的所有单盘个数
* 调用关系  :
* 其    它  :

*****************************************************************************/
unsigned int del_all_boards();

/*****************************************************************************
* 函 数 名  : del_board
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月31日
* 函数功能  : 删除单盘
* 输入参数  : unsigned int board_index  盘索引，reb_board()的返回值
* 输出参数  : 无
* 返 回 值  : OK成功 ERROR失败
* 调用关系  :
* 其    它  :

*****************************************************************************/

STATUS del_board(unsigned int board_index);

/*****************************************************************************
* 函 数 名  : reg_line
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月19日
* 函数功能  :   注册一条新线路
* 输入参数  :   board_index    单盘代码，reg_board()返回值
                                        tag			线路tag值
                                        num			线路值
                                        num_len			线路值长度
                                        key_word			线路业务关键字
                                        key_name			线路业务关键字名称
                                        key_name_len			线路业务关键字名称长度
* 输出参数  : 无
* 返 回 值  : 线路索引
* 调用关系  :
* 其    它  :

*****************************************************************************/
unsigned int reg_line(unsigned int board_index,
    unsigned int tag,
    unsigned char *num,
    unsigned int num_len,
    unsigned int key_word,
    unsigned char *key_name,
    unsigned char key_name_len);

/*****************************************************************************
* 函 数 名  : del_board_line
* 负 责 人  : zhaojzh
* 创建日期  : 2014年1月2日
* 函数功能  : 从单盘上删除一条线路
* 输入参数  : unsigned int board_index  单盘索引
                                 可以传入一个reg_board()的返回值，
                                 如果不确定要删除的这条线路属于哪个单盘，
                                 可以传入0,这样会扫描所有单盘查找这条线路
               unsigned int line_index   线路索引
* 输出参数  : 无
* 返 回 值  :
* 调用关系  :
* 其    它  :

*****************************************************************************/
STATUS del_board_line(unsigned int board_index, unsigned int line_index);

/*****************************************************************************
* 函 数 名  : del_board_all_lines
* 负 责 人  : zhaojzh
* 创建日期  : 2014年1月2日
* 函数功能  : 删除单盘下所有线路
* 输入参数  : unsigned int board_index  待删除线路的单盘索引，reb_board()返回值
* 输出参数  : 无
* 返 回 值  : 删除的线路个数
* 调用关系  :
* 其    它  :

*****************************************************************************/
unsigned int del_board_all_lines(unsigned int board_index);

/*****************************************************************************
* 函 数 名  : reg_alm
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月19日
* 函数功能  : 注册告警代码。
* 输入参数  : unsigned int code       告警代码
               unsigned int type       告警类型
               char *name              1
               unsigned char name_len  1
* 输出参数  : 无
* 返 回 值  : 告警代码的索引
* 调用关系  :
* 其    它  :

*****************************************************************************/
unsigned int reg_alm(unsigned int code, unsigned int type, char *name, unsigned char name_len);

/*****************************************************************************
* 函 数 名  : set_alm
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月19日
* 函数功能  : 设置告警。
* 输入参数  : unsigned int line_index  告警从属的线路索引
               unsigned int alm_index   告警代码索引
               unsigned int alm_state   告警状态
                                        1：告警发生
                                        0：告警消失
* 输出参数  : 无
* 返 回 值  : OK成功 ERROR失败
* 调用关系  :
* 其    它  :

*****************************************************************************/
STATUS set_alm(unsigned int line_index, unsigned int alm_index, unsigned int alm_state);

/*****************************************************************************
* 函 数 名  : del_line_alm
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月19日
* 函数功能  : 从一条线路上移除一个告警。
* 输入参数  : unsigned int line_index  告警从属的线路索引
               unsigned int alm_index   告警代码索引
* 输出参数  : 无
* 返 回 值  : OK成功 ERROR失败
* 调用关系  :
* 其    它  :

*****************************************************************************/

STATUS del_line_alm(unsigned int line_index, unsigned int alm_index);

/*****************************************************************************
* 函 数 名  : del_line_all_alms
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月19日
* 函数功能  : 从一条线路上移除所有告警。
* 输入参数  : unsigned int line_index  告警从属的线路索引
* 输出参数  : 无
* 返 回 值  : OK成功 ERROR失败
* 调用关系  :
* 其    它  :

*****************************************************************************/

unsigned int del_line_all_alms(unsigned int line_index);

/*****************************************************************************
* 函 数 名  : reg_pm
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月21日
* 函数功能  : 注册性能代码
* 输入参数  :   code		性能代码
                                        type		性能类型        		 0：普通性能
                                                                        1：累计性能
                                                                        2：计算最大最小值性能
                                                                        3：平均值性能

                                        value_type		性能值类型	0：2字节整数
                                                                        1：4字节整数
                                                                        2: 8字节整数
                                                                        3：4字节浮点数
                                                                        4: 8字节浮点数
                                        name			性能名
                                        name_len      性能名长度
* 输出参数  : 无
* 返 回 值  : 性能代码索引
* 调用关系  :
* 其    它  :

*****************************************************************************/
unsigned int reg_pm(unsigned int code,
    unsigned char type,
    unsigned char value_type,
    char *name,
    unsigned char name_len);

/*****************************************************************************
* 函 数 名  : set_pm
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月21日
* 函数功能  : 设置性能。
* 输入参数  :   line_index	性能从属的线路索引
                                        index		性能代码索引
                                        value		性能值存放地址
* 输出参数  : 无
* 返 回 值  : OK成功 ERROR失败
* 调用关系  :
* 其    它  :

*****************************************************************************/
STATUS set_pm(unsigned int line_index, unsigned int index, unsigned char *value);

/*****************************************************************************
* 函 数 名  : del_line_pm
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月19日
* 函数功能  : 从一条线路上移除一个性能。
* 输入参数  : unsigned int line_index  性能从属的线路索引
               unsigned int pm_index   性能代码索引
* 输出参数  : 无
* 返 回 值  : OK成功 ERROR失败
* 调用关系  :
* 其    它  :

*****************************************************************************/

STATUS del_line_pm(unsigned int line_index, unsigned int pm_index);

/*****************************************************************************
* 函 数 名  : del_line_all_pms
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月19日
* 函数功能  : 从一条线路上移除所有性能。
* 输入参数  : unsigned int line_index  性能从属的线路索引
* 输出参数  : 无
* 返 回 值  : OK成功 ERROR失败
* 调用关系  :
* 其    它  :

*****************************************************************************/

unsigned int del_line_all_pms(unsigned int line_index);

/*****************************************************************************
* 函 数 名  : reg_board_state
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月21日
* 函数功能  : 向公共库某个单盘输入状态数据块信息
* 输入参数  : unsigned int board_index  状态块所在单盘索引，reg_board的返回值
               UINT32 id                 单盘状态块的ID
               UINT8 lab_code            状态块标识码(网管分配的状态块序号，01固定为配置下载时间块)
               INT8 *buffer              单盘状态数据存放的地址
               UINT32 buffer_len         单盘状态数据长度
               UINT32 show_type          状态块显示类型
               INT8 *name                状态块名称
               UINT8 name_len            状态块名称长度
               UINT8 backup              备用(填0)
* 输出参数  : 无
* 返 回 值  : OK成功 ERROR失败
* 调用关系  :
* 其    它  : 公共库通过这个函数获取单盘每个状态数据块数据的
                存放地址，数据长度，状态数据块ID号，显示类型。
                id 由网管协议分配，其中0x00为保留号，不能分配给状态块。
                状态块ID号为0x02到0x09时忽略标识码。
                        0x0000xxxx 公共类 所有单盘都可以使用的通用属性。
                        0x0001xxxx 交叉类 交叉盘使用。
                        0x0002xxxx 时钟类 时钟盘使用。
                        0x0003xxxx 接口盘 接口盘使用。
                        0x8000xxxx 自定义类
                          任何盘申请协议时必须指明的特殊状态,该类的数据格式不定,网管界面根据事先约定的单盘协议显示数据内容.

                        以下id值表示固定的状态数据块
                        0x00保留
                        0x01表示硬件信息
                        0x02配置下载时间(公共库处理，应用程序不用操作)
                        0x03表示盘号
                        0x04表示板号
                        0x05表示制盘时间
                        0x06表示BMU软件版本号
                        0x07表示BMU软件生成时间
                        0x08表示激活
                        0x09表示ASON设备单盘状态基本信息(公共库处理，应用程序不用操作)
                        0x0A-0x0f保留

                show_type表示状态数据在网管界面上的显示方式。
                        0x00保留数据类型 网管按16进制显示一遍再按ASICC显示一遍
                        0x01表示按2进制数
                        0x02表示按16进制数显示
                        0x03表示按ASCII显示
                        0x04表示显示配置下载时间
                        0x05表示显示ASON设备单盘状态基本信息
                        other:未定(由网管协议指定)

                name表示网管上显示的状态数据块名，长度必须小于9个字符，可以为NULL。

*****************************************************************************/
STATUS reg_board_state(unsigned int board_index,
    unsigned int id,
    unsigned char lab_code,
    char *buffer,
    unsigned int buffer_len,
    unsigned int show_type,
    char *name,
    unsigned char name_len,
    unsigned char backup);

/*****************************************************************************
* 函 数 名  : reg_config_time_state_handle
* 负 责 人  : zhaojzh
* 创建日期  : 2014年1月20日
* 函数功能  : 注册配置下载时间状态块
* 输入参数  : unsigned int board_index  单盘索引
* 输出参数  : 无
* 返 回 值  : OK成功；ERROR失败
* 调用关系  :
* 其    它  : 该函数调用reg_board_state注册一个配置下载时间的状态块，
                                该状态块的内容处理由公共库内部完成，在注册全量配置的
                                配置块完成后，调用该函数，新注册的状态块将保存之前已经注册的
                                配置块下载时间。

*****************************************************************************/
STATUS reg_config_time_state_handle(unsigned int board_index);

/*****************************************************************************
* 函 数 名  : del_board_state
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月21日
* 函数功能  : 向公共库某个单盘删除状态数据块信息
* 输入参数  : unsigned int board_index  状态块所在单盘索引，reg_board的返回值
               unsigned int id                 单盘状态块的ID

* 输出参数  : 无
* 返 回 值  : OK成功 ERROR失败
* 调用关系  :
* 其    它  :
*****************************************************************************/
STATUS del_board_state(unsigned int board_index, unsigned int id);

/*****************************************************************************
* 函 数 名  : del_board_all_state
* 负 责 人  : zhaojzh
* 创建日期  : 2014年1月2日
* 函数功能  : 删除单盘下所有状态块
* 输入参数  : unsigned int board_index  待删除配置块的单盘索引
* 输出参数  : 无
* 返 回 值  : 删除的所有单盘下状态块个数
* 调用关系  :
* 其    它  :

*****************************************************************************/
unsigned int del_board_all_state(unsigned int board_index);

struct usr_conf_block
{
    unsigned int len;           /*当前配置数据块的有效长度*/
    unsigned char flag;                         /*配置数据改变标志
                                                                        0：配置数据已执行过
                                                                        1：配置数据有新的变化
                                                                        2：网管请求强制执行
                                                                        3：接收到配置数据，但内容没有改变
                                                                        4: 配置数据CRC校验错
                                                 */
    unsigned char *buffer;                /*配置数据存放地址*/
};

/*****************************************************************************
* 函 数 名  : reg_board_conf_block
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月21日
* 函数功能  : 向公共库输入一个配置数据块结构
* 输入参数  : unsigned int board_index        状态块所在单盘索引，reg_board的返回值
               UINT8    id                      配置数据块的标识
               UINT32	buffer_len              配置数据存放缓冲区的大小
               struct UsrConfBlock *pstuConf  配置块数据结构
* 输出参数  : 无
* 返 回 值  : OK成功 ERROR失败
* 调用关系  :
* 其    它  :

*****************************************************************************/
STATUS reg_board_conf_block(unsigned int board_index,
    unsigned char id,
    unsigned int buffer_len,
    struct usr_conf_block *pstuConf);

/*****************************************************************************
* 函 数 名  : del_board_conf_block
* 负 责 人  : zhaojzh
* 创建日期  : 2014年1月2日
* 函数功能  : 删除单盘上一个配置块
* 输入参数  : unsigned int board_index  单盘索引
               unsigned char id          配置块ID
* 输出参数  : 无
* 返 回 值  :
* 调用关系  :
* 其    它  :

*****************************************************************************/
STATUS del_board_conf_block(unsigned int board_index, unsigned char id);

/*****************************************************************************
* 函 数 名  : del_board_all_config_blocks
* 负 责 人  : zhaojzh
* 创建日期  : 2014年1月2日
* 函数功能  : 删除单盘下所有配置块
* 输入参数  : struct board *board_from  待删除配置块的单盘索引
* 输出参数  : 无
* 返 回 值  : 删除的所有单盘下配置块个数
* 调用关系  :
* 其    它  :

*****************************************************************************/
unsigned int del_board_all_config_blocks(unsigned int board_index);

typedef int (*FUNCPTR)();

/*****************************************************************************
* 函 数 名  : reg_usr_cmd
* 负 责 人  : zhaojzh
* 创建日期  : 2014年1月8日
* 函数功能  : 用户注册处理控制命令函数
* 输入参数  : unsigned int board_index  单盘索引，使用reg_board()返回值
               FUNCPTR usr_cmd_func      用户处理命令的回调函数
* 输出参数  : 无
* 返 回 值  :
* 调用关系  :
* 其    它  :

*****************************************************************************/
STATUS reg_usr_cmd(unsigned int board_index, FUNCPTR usr_cmd_func);

/*****************************************************
函数名：reg_global_id_to_line_index_func()

功 能：	注册通过global id获取线路索引的函数。

输 入：unsigned int board_index  单盘索引，使用reg_board()返回值
		func		通过global id获取线路索引的函数 


输 出：	无

返回值：OK			注册成功

描 述：	注册通过global id获取线路索引的函数。
		函数func()的原型必须如下：

		int FromGlobalIdGetLineIndex(int idType,int idLen,char *id,int *pLineNum,char *lineIndex);

		其中参数idType为global 	id的类型
								0：物理端口
								1：OTN业务
								2：LSP层
								3：PW层
								4：VPWS
								5：VPLS
						idLen	表示id的长度
						id		存放global id的buffer,为端口号的ascii码表示，
								例如端口为123则id的内容为"/123"，对应的ascii码为2F 31 32 33
						pLineNum	表示线路索引的个数存放地址
						lineIndex 	表示存放线路索引的buffer，最大不超过64个字节

		此函数被公共库调用，用于告警抑制。

作 者： yuanf
	
修 改：创建

时 间：2013.01.08			
*****************************************************/ 
int reg_global_id_to_line_index_func(unsigned int board_index,FUNCPTR func);
/*****************************************************************************
 * 函 数 名  : reg_board_lamp_ctrl
 * 负 责 人  : zhaojzh
 * 创建日期  : 2014年2月13日
 * 函数功能  : 注册单盘灯控制
 * 输入参数  : unsigned int board_index  单盘索引
               FUNCPTR func              灯控制函数
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 
	这个函数通知公共库如何操作红、绿、黄灯。注册
	的函数必须有两个参数，参数必须按下面的方式输入。
	参数1：指明控制的灯类型
			0 表示控制green灯
			1 表示控制red灯
			2 表示控制yellow灯
	参数2： 操做方法	
			0 表示灯灭
			1 表示灯亮
			2 表示灯反转(亮变为灭，灭变为亮)		
	
	
	只有单盘程序和EMU盘程序合并时才需要这个函数。

	例：
		int ControlLamp(int lampType ,int onoff)
		{
			if( lampType == 0)		//green
			{
				if(onoff == 0)		//off
				{
					//do it in there
				}
				else if(onoff == 1) //on
				{
					//do it in there
				}
				else				//reverse
				{
					//do it in there
				}
			}
			else if(lampType == 1)	//red
			{
				if(onoff == 0)		//off
				{
					//do it in there
				}
				else if(onoff == 1) //on
				{
					//do it in there
				}
				else				//reverse
				{
					//do it in there
				}
			}
			else					//yellow
			{
				if(onoff == 0)		//off
				{
					//do it in there
				}
				else if(onoff == 1) //on
				{
					//do it in there
				}
				else				//reverse
				{
					//do it in there
				}
			}
		}		

*****************************************************************************/
STATUS reg_board_lamp_ctrl(unsigned int board_index,FUNCPTR func);

/*****************************************************************************
* 函 数 名	: set_board_exist
* 负 责 人	: zhaojzh
* 创建日期	: 2013年12月19日
* 函数功能	: 获取单盘性能
* 输入参数	: unsigned int board_addr			  单盘地址
             flag     0:虚拟盘不在位
                         1:虚拟盘在位
* 输出参数	: 无
* 返 回 值	: OK		设置操作正确
                ERROR	没找到指定的虚拟盘
* 调用关系	:
* 其	它	:

*****************************************************************************/
int set_board_exist(unsigned int board_addr, unsigned int flag);

/*****************************************************************************
 * 函 数 名  : reg_pm_clear_func
 * 负 责 人  : zhaojzh
 * 创建日期  : 2014年3月13日
 * 函数功能  : 注册网管下发性能清零回调函数
 * 输入参数  : FUNCPTR func  清零单盘性能回调函数
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 
                函数func()的原型必须如下：

                int clear_pm(int board_index);
                board_index:公共库输出的单盘索引，对应reg_board的
                返回值，回调函数被调用时清除该单盘的性能。

*****************************************************************************/
STATUS reg_pm_clear_func(FUNCPTR func);

/*****************************************************************************
 * 函 数 名  : reg_quarter_func
 * 负 责 人  : zhaojzh
 * 创建日期  : 2014年3月13日
 * 函数功能  : 注册15分钟到应用回调函数
 * 输入参数  : FUNCPTR func  15分钟到应用回调函数
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 
 
					函数func()的原型必须如下：

					int quarter_handle(int board_index);
					board_index:公共库输出的单盘索引，对应reg_board的
					返回值，回调函数用于通知应用15分钟到，应用可以在
					回调函数里进行累计性能清零的操作。

*****************************************************************************/
STATUS reg_quarter_func(FUNCPTR func);

/*****************************************************************************
* 函 数 名  : show_alm_code
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月26日
* 函数功能  : 显示当前注册的报警
* 输入参数  : 无
* 输出参数  : 无
* 返 回 值  :
* 调用关系  :
* 其    它  :

*****************************************************************************/
void show_alm_code();

/*****************************************************************************
* 函 数 名  : show_boards
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月26日
* 函数功能  : 显示注册的单盘信息
* 输入参数  : 无
* 输出参数  : 无
* 返 回 值  :
* 调用关系  :
* 其    它  :

*****************************************************************************/
void show_boards();

/*****************************************************************************
* 函 数 名  : show_lines
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月26日
* 函数功能  : 显示单盘下线路信息
* 输入参数  : unsigned int board_addr  单盘地址
* 输出参数  : 无
* 返 回 值  :
* 调用关系  :
* 其    它  :

*****************************************************************************/
void show_lines(unsigned int board_addr);

/*****************************************************************************
* 函 数 名  : show_state
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月26日
* 函数功能  : 显示单盘下状态块信息
* 输入参数  : unsigned int board_addr 单盘地址
* 输出参数  : 无
* 返 回 值  :
* 调用关系  :
* 其    它  :

*****************************************************************************/
void show_state(unsigned int board_addr);

/*****************************************************************************
* 函 数 名  : show_config_blocks
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月26日
* 函数功能  : 显示单盘下注册的配置块信息
* 输入参数  : unsigned int board_addr  单盘地址
* 输出参数  : 无
* 返 回 值  :
* 调用关系  :
* 其    它  :

*****************************************************************************/
void show_config_blocks(unsigned int board_addr);

/*****************************************************************************
* 函 数 名  : show_line_pms
* 负 责 人  : zhaojzh
* 创建日期  : 2014年1月2日
* 函数功能  : 显示线路下性能信息
* 输入参数  : unsigned int line_index  线路索引，reg_line()返回值
* 输出参数  : 无
* 返 回 值  :
* 调用关系  :
* 其    它  :

*****************************************************************************/
void show_line_pms(unsigned int line_index);

/*****************************************************************************
* 函 数 名  : show_line_alms
* 负 责 人  : zhaojzh
* 创建日期  : 2014年1月2日
* 函数功能  : 显示线路下告警信息
* 输入参数  : unsigned int line_index  线路索引，reg_line()返回值
* 输出参数  : 无
* 返 回 值  :
* 调用关系  :
* 其    它  :

*****************************************************************************/
void show_line_alms(unsigned int line_index);

/*****************************************************************************
* 函 数 名  : show_pm_code
* 负 责 人  : zhaojzh
* 创建日期  : 2013年12月26日
* 函数功能  : 显示当前注册的性能
* 输入参数  : 无
* 输出参数  : 无
* 返 回 值  :
* 调用关系  :
* 其    它  :

*****************************************************************************/
void show_pm_code();

/*****************************************************************************
* 函 数 名	: show_board_pms
* 负 责 人	: zhaojzh
* 创建日期	: 2014年1月2日
* 函数功能	: 显示单盘下性能信息
* 输入参数	: unsigned int board_addr 单盘地址
* 输出参数	: 无
* 返 回 值	:
* 调用关系	:
* 其	它	:

*****************************************************************************/
void show_board_pms(unsigned int board_addr);

/*****************************************************************************
* 函 数 名	: show_board_alms
* 负 责 人	: zhaojzh
* 创建日期	: 2014年1月2日
* 函数功能	: 显示单盘下报警信息
* 输入参数	: unsigned int board_addr 单盘地址
* 输出参数	: 无
* 返 回 值	:
* 调用关系	:
* 其	它	:

*****************************************************************************/
void show_board_alms(unsigned int board_addr);

#ifdef  __cplusplus
}
#endif  /* __cplusplus */
#endif
