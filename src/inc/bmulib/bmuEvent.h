

/****************************************************************
** �� �� ����bmuEvent.h
** ��    ��: bmu�������¼�������غ���

** ����  �ߣ�yuanf
** �ա�  �ڣ�2010.12.09

** ��    ����1.0

** �����б�	SendEvent()		 
****************************************************************/
#ifndef	INC_BMUEVENT_H
#define	INC_BMUEVENT_H

/*#include <vxWorks.h>*/

#ifdef	__cplusplus
extern  "C"{
#endif	/* __cplusplus */

/*****************************************************
��������SendEvent()

��  �ܣ��ϱ������¼�

��  �룺eventId		�¼�ID��
		eventType	�¼�����	BIT0:�¼��Ƿ�Ϊ�����¼� ��0/1=�ǽ���/�����¼���
		eventState	�¼�״̬	1/2	����/��
		dspType		��������	0/1 ��buffer������ascii�ַ�/16��������Э������ 
		showType	��ʾ���� 	0/1�� ��̨/ǰ̨
		buffer		�¼�����	�¼���������
		len			�¼����ݳ��� buffer����Ч���ݳ���
		
��  ����OK

��  ����������������������ϱ�һ���¼����Խ����¼���Ҫ�����ϱ������������¼��洢���ȴ�������ѯ��

��  �ߣ�yuanf
��  �ģ�����	
ʱ  �䣺2010.11.2		
*****************************************************/ 
extern int SendEvent(unsigned int eventId,unsigned int eventType,unsigned int eventState,unsigned int dspType,unsigned short showType,char *buffer,int len);


#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif	/*INC_BMUEVENT_H*/

