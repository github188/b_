
/****************************************************************
** �� �� ����bmuReportAlmPmToEmu.h
** ��    ��: bmu����������EMU�ϱ��澯�����ܵ����ݽṹ����صĺ�������

** ����  �ߣ�yuanf
** �ա�  �ڣ�2007.05.09

** ��    ����1.0

** �����б�RegReportAlm()
			 SetReportAlmValid()
			 PrintReportAlm()
			 RegReportPm()
			 SetReportPmValid()
			 PrintReportPm()			 
****************************************************************/
#ifndef	INC_BMUREPORTALMPMTOEMU_H
#define	INC_BMUREPORTALMPMTOEMU_H

#ifdef	__cplusplus
extern  "C"{
#endif	/* __cplusplus */


/********************************************/
/*        ��Դ���û���ĸ澯���ݽṹ        */
/********************************************/
struct ALM
{
	UINT8	ucAlmCode;	/*�澯����*/
	UINT8	ucAlmType;	/*�澯����
						0����Ҫ�澯
						2�������澯
						4����Ҫ�澯
						8����ʾ�澯
						*/
	UINT8	ucPri;		/*�澯���ȼ�
						bit7: 0 ����澯Ӱ������·�澯
							  1 ����澯��Ӱ�챾��·�ĸ澯�Ҳ�Ӱ������·�澯
							 
						bit6��bit0���澯���ȼ�1��127��ͬһ��·�����ȼ��澯���ε����ȼ��澯
									1Ϊ�����ȼ�127Ϊ�����ȼ�������·�澯��������·�澯��
						ucPri = 0��ʾ����澯���μӸ澯���ȼ��Ƚ�
						*/
						
	UINT8	ucState;	/*�澯״̬1���澯  0���澯��ʧ(����澯��������) 
									2���澯��ʧ(������澯��������)*/
};


/*****************************************************
��������RegReportAlm()

�� �ܣ�	ע��һ����Ҫ�ϱ���EMU�ĸ澯
	
�� �룺	usLineCode		�澯����·��
		pstuAlm			�澯�����ݽṹָ��
			
�� ����	OK:		ע��ɹ�
		ERROR:	ע��ʧ��

�� ����	�������ע��һ���ϱ���EMU�ĸ澯������澯ͨ����Ӱ��DCCͨ������״̬�ĸ澯��
		EMUͨ������澯�ж�DCCͨ���Ƿ��������Ƿ���Ҫ�л��������˿���ȥ��ע��ĸ澯
		�ڸ澯�����仯ʱ��ͨ������10 13 00�ϱ���EMU,ͬʱ��������̽��յ�EMU��ȡ�澯
		������ʱ��Ҳ��ͨ������10 13 00�ϱ���EMU.Ĭ�������ͨ���˺���ע��ĸ澯������
		Ч�ģ�����ͨ������SetReportAlmValid()�޸�����Ч��־��ͨ������PrintReportAlm()
		���Բ鿴�˺���ע��ĸ澯��

�� �ߣ�	yuanf	
�� �ģ�	����	
ʱ �䣺	2008.8.5			
*****************************************************/
extern int RegReportAlm(UINT16 usLineCode,	struct ALM *pstuAlm);

/*****************************************************
��������SetReportAlmValid()

�� �ܣ�	����ע����ϱ���EMU�ĸ澯�Ƿ���Ч

�� �룺	usLineCode	��Ҫ���õĸ澯����·��
		ucAlmCode	��Ҫ���õĸ澯�ĸ澯����
		ucValidFlag �澯��Ч��־
					 0 �澯��Ч
					 1 �澯��Ч		
�� ����	OK:		����ע��ĸ澯��Ч��־�ɹ�
		ERROR:	����ע��ĸ澯��Ч��־ʧ��

�� ����	���ע����ϱ���EMU�ĸ澯��Ч�����̽����Ὣ�˸澯�ϱ���EMU��

�� �ߣ�	yuanf	
�� �ģ�	����	
ʱ �䣺	2008.8.5			
*****************************************************/
extern int SetReportAlmValid(unsigned short usLineCode, unsigned char ucAlmCode,unsigned char ucValidFlag);

/*****************************************************
��������PrintReportAlm()

�� �ܣ�	��ʾע����ϱ���EMU�ĸ澯
	
�� �룺	��

�� ����	OK:		

�� ����	��ʾע����ϱ���EMU�ĸ澯���ڵ���ʱʹ����������ο�ע����ϱ���EMU�ĸ澯��

�� �ߣ�	yuanf	
�� �ģ�	����	
ʱ �䣺	2008.8.5			
*****************************************************/
extern int PrintReportAlm(void);

/*****************************************************
��������RegReportPm()

�� �ܣ�	ע��һ����Ҫ�ϱ���EMU������
	
�� �룺	usLineCode		���ܵ���·��
		pstuPm			���ܵ����ݽṹָ��
				
�� ����	OK:		ע��ɹ�
		ERROR:	ע��ʧ��

�� ����	�������ע��һ���ϱ���EMU�����ܣ���������ͨ����EMU��Ҫ֪�������ܣ����絥�̹����¶ȡ�
		���ע���������Ч���ڵ��̽��յ�EMU��ȡ�澯������ʱ��ͨ������10 13 00�������ϱ���EMU.
		Ĭ�������ͨ���˺���ע������ܶ�����Ч�ģ�����ͨ������SetReportPmValid()�޸�����Ч��־��
		ͨ������PrintReportPm()���Բ鿴�˺���ע������ܡ�
		�ϱ���EMU�ĵ����¶ȣ����ܴ���̶�Ϊ0x13���ϱ������ݸ�ʽΪfloat
		�ϱ���EMU�ĵ����¶����ޣ����ܴ���̶�Ϊ0x14���ϱ������ݸ�ʽΪfloat
		�ϱ���EMU�ĵ����¶����ޣ����ܴ���̶�Ϊ0x15���ϱ������ݸ�ʽΪfloat
		
		����
		�¶��ϱ�
		fValue = 15.5;
		g_stuTemperature.ucPmCode = 0x13;
		g_stuTemperature.ucFlag = 3;
		g_stuTemperature.uValue.fvalue = fValue;
		RegReportPm(0x0001,&g_stuTemperature);

		�¶�����
		fValue = 45.5;
		g_stuTemperatureDownLimit.ucPmCode = 0x14;
		g_stuTemperatureDownLimit.ucFlag = 3;
		g_stuTemperatureDownLimit.uValue.fvalue = fValue;
		RegReportPm(0x0001,&g_stuTemperatureDownLimit);

		�¶�����
		fValue = 65.5;
		g_stuTemperatureUpLimit.ucPmCode = 0x15;
		g_stuTemperatureUpLimit.ucFlag = 3;
		g_stuTemperatureUpLimit.uValue.fvalue = fValue;
		RegReportPm(0x0001,&g_stuTemperatureUpLimit);
		
�� �ߣ�	yuanf	
�� �ģ�	����	
ʱ �䣺	2008.8.5			
*****************************************************/
extern int RegReportPm(UINT16 usLineCode,	struct PM *pstuPm);

/*****************************************************
��������SetReportPmValid()

�� �ܣ�	����ע����ϱ���EMU�������Ƿ���Ч

�� �룺	usLineCode	��Ҫ���õ����ܵ���·��
		ucPmCode	��Ҫ���õ����ܵĸ澯����
		ucValidFlag �澯��Ч��־
					 0 ������Ч
					 1 ������Ч	
					 				
�� ����	OK:		����ע���������Ч��־�ɹ�
		ERROR:	����ע���������Ч��־ʧ��

�� ����	���ע����ϱ���EMU��������Ч�����̽����Ὣ�������ϱ���EMU��

�� �ߣ�	yuanf	
�� �ģ�	����	
ʱ �䣺	2008.8.5			
*****************************************************/
extern int SetReportPmValid(unsigned short usLineCode, unsigned char ucPmCode,unsigned char ucValidFlag);

/*****************************************************
��������PrintReportPm()

�� �ܣ�	��ʾע����ϱ���EMU������

�� �룺	��
	
�� ����	OK:		

�� ����	��ʾע����ϱ���EMU�����ܣ��ڵ���ʱʹ����������ο�ע����ϱ���EMU�����ܡ�

�� �ߣ�	yuanf	
�� �ģ�	����	
ʱ �䣺	2008.8.5			
*****************************************************/
extern int PrintReportPm(void);


#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif	/*INC_BMUREPORTALMPMTOEMU_H*/

/***************************************************************/
/*******************End bmuReportAlmPmToEmu.h*******************/
/***************************************************************/

