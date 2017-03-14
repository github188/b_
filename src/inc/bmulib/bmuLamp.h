#ifndef BMU_LAMP_H
#define BMU_LAMP_H
#include "bmuType.h"

#ifdef  __cplusplus
extern  "C" {
#endif  /* __cplusplus */
/*****************************************************
��������RegLampOperate()

�� �ܣ�	ע����ƺ��̻Ƶƺ���

�� �룺	���Ƶƺ����ĵ�ַ
		
�� ����	OK��	ע��ɹ�
		
�� ����	�������֪ͨ��������β����졢�̡��Ƶơ�ע��
		�ĺ��������������������������밴����ķ�ʽ���롣
		����1��ָ�����Ƶĵ�����
				0 ��ʾ����green��
				1 ��ʾ����red��
				2 ��ʾ����yellow��
		����2��	��������	
				0 ��ʾ����
				1 ��ʾ����
				2 ��ʾ�Ʒ�ת(����Ϊ�����Ϊ��)		
		
		
		ֻ�е��̳����EMU�̳���ϲ�ʱ����Ҫ���������

		����
			int ControlLamp(int lampType ,int onoff)
			{
				if(	lampType == 0)		//green
				{
					if(onoff == 0)		//off
					{
						//do it in there
					}
					else if(onoff == 1)	//on
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
					else if(onoff == 1)	//on
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
					else if(onoff == 1)	//on
					{
						//do it in there
					}
					else				//reverse
					{
						//do it in there
					}
				}
			}
			RegLampOperate((VOIDFUNCPTR)ControlLamp);			

�� �ߣ�	yuanf			
�� �ģ� ����
ʱ �䣺 2007.4.2	
*****************************************************/
STATUS 	RegLampOperate(FUNCPTR pfunc);

/*****************************************************
   ��������CtrLamp()

   �� �ܣ�	���ƺ졢�̡��Ƶƣ�ÿһ�ֵƶ���ѡ�����ɹ�������ƣ�
                �����û������Լ�����������

   �� �룺	ucLamp,		�����Ƶĵ�0:�� 1:�� 2:��
                ucModel,	0:��������� 1:�û�����
                ucOnOFF		1:�� 0:�� 2:��˸
                unsigned int hold_time ����ʱ��

   �� ����	OK:		�����Ϸ�
                ERROR:	����Ĳ����Ƿ�

   �� ����	���̵ƵĿ������û���Ϊ������ʱ���̵Ƶĳ�ʼ״̬Ϊ
                ����

   �� �ߣ�	yuanf

   �� �ģ�

   ʱ �䣺
*****************************************************/
STATUS CtrlLamp(unsigned char ucLamp, unsigned char ucModel, unsigned char ucOnOFF, unsigned int hold_time);

/*****************************************************************************
 * �� �� ��  : set_lamp_flash_interval
 * �� �� ��  : zhaojzh
 * ��������  : 2015��5��27��
 * ��������  : ������˸״̬�任ʱ����
 * �������  : int interval  ÿ����˸�������������ʱ��������λ��΢��
 * �������  : ��
 * �� �� ֵ  : 
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
int set_lamp_flash_interval(int interval);

/*****************************************************************************
 * �� �� ��  : get_lamp_flash_interval
 * �� �� ��  : zhaojzh
 * ��������  : 2015��5��27��
 * ��������  : ��ȡ��˸״̬�仯ʱ��������λ:΢��
 * �������  : ��
 * �������  : ��
 * �� �� ֵ  : 
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
int get_lamp_flash_interval();

#ifdef  __cplusplus
}
#endif  /* __cplusplus */

#endif

