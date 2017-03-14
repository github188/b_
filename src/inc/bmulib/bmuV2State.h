
/****************************************************************
** �� �� ����bmuV2State.h
** ��    ��: bmu��������״̬���ݽṹ����صĺ�������

** ����  �ߣ�yuanf
** �ա�  �ڣ�2012.3.14
** ��	 �ģ�����

** ��    ����1.0

** �����б�	 
****************************************************************/
#ifndef	INC_BMUV2STATE_H
#define	INC_BMUV2STATE_H

#ifdef	__cplusplus
extern  "C"{
#endif	/* __cplusplus */

/*״̬�ֿ�ID��*/
#define	REVERSE_ID			0x00	/*����						*/
#define	HARD_INFO_ID		0x01	/*����Ӳ����Ϣ״̬��ID		*/
#define	CONFIG_DOWN_TIME_ID	0x02	/*������������ʱ��״̬��ID	*/
#define	BOARD_NO_ID			0x03	/*�̺�״̬��ID				*/
#define	PCB_NO_ID			0x04	/*PCB���״̬��ID			*/
#define PCB_TIME_ID			0x05	/*PCB�ư�ʱ��״̬��ID		*/
#define SOFT_VER_ID			0x06	/*����汾��״̬��ID		*/
#define SOFT_BUILD_TIME_ID	0x07	/*�������ʱ��״̬��ID		*/
#define BOARD_ACTIVE_ID		0x08	/*�̼���״̬��ID			*/
#define ASON_BOARD_INFO_ID	0x09	/*ASON*/

/*****************************************************
��������RegNewBoardState()
RegNewBoardState(){}
�� �ܣ�	�򹫹�������״̬���ݿ���Ϣ

�� �룺	uiID		����״̬���ID
		ucLabCode	״̬���ʶ��(���ܷ����״̬����ţ�01�̶�Ϊ��������ʱ���)
		buffer		����״̬���ݴ�ŵĵ�ַ
		len			����״̬���ݳ���
		uiShowType	״̬����ʾ����
		pName		״̬������
		ucBackup	����(��0)
		
�� ����	OK:		�ɹ���¼����״̬������Ϣ
		ERROR:	����Ĳ����Ƿ�
		ԭ��	1 bufferΪ��ָ��
				2 �ڴ�ռ䲻��
				3 ״̬���ʶ��С��2

�� ����	������ͨ�����������ȡ����ÿ��״̬���ݿ����ݵ�
		��ŵ�ַ�����ݳ��ȣ�״̬���ݿ�ID�ţ���ʾ���͡�
		uiID ������Э����䣬����0x00Ϊ�����ţ����ܷ����״̬�顣
		״̬��ID��Ϊ0x02��0x09ʱ���Ա�ʶ�롣
			0x0000xxxx ������ ���е��̶�����ʹ�õ�ͨ�����ԡ�
			0x0001xxxx ������ ������ʹ�á�
			0x0002xxxx ʱ���� ʱ����ʹ�á�
			0x0003xxxx �ӿ��� �ӿ���ʹ�á�
			0x8000xxxx �Զ����� �κ�������Э��ʱ����ָ��������״̬,��������ݸ�ʽ����,���ܽ����������Լ���ĵ���Э����ʾ��������.
			
			����uiIDֵ��ʾ�̶���״̬���ݿ�
			0x00����
			0x01��ʾӲ����Ϣ
			0x02��������ʱ��(�����⴦��Ӧ�ó����ò���)
			0x03��ʾ�̺�
			0x04��ʾ���
			0x05��ʾ����ʱ��
			0x06��ʾBMU����汾��
			0x07��ʾBMU�������ʱ��
			0x08��ʾ����
			0x09��ʾASON�豸����״̬������Ϣ(�����⴦��Ӧ�ó����ò���)
			0x0A-0x0f����
						
		uiShowType��ʾ״̬���������ܽ����ϵ���ʾ��ʽ��
			0x00������������ ���ܰ�16������ʾһ���ٰ�ASICC��ʾһ��
			0x01��ʾ��2������
			0x02��ʾ��16��������ʾ
			0x03��ʾ��ASCII��ʾ
			0x04��ʾ��ʾ��������ʱ��
			0x05��ʾ��ʾASON�豸����״̬������Ϣ
			other:δ��(������Э��ָ��)
			
		pName��ʾ��������ʾ��״̬���ݿ��������ȱ���С��9���ַ�������ΪNULL��  
		
		����
		unsigned char CrossData[200];
		RegNewBoardState(0x10003,0x02,crossData,200,0x0,"Cross",0);
		
		ע�����������RegBoardState()��������ע�ᵥ��״̬���ݣ���ͬһ������
		�У����е�״̬��ֻ��ȫ����RegNewBoardState()��ȫ����RegBoardState()
		ע�ᣬ�������߻��á�
		
		ֻ��ʹ��NMU_BMUͨ��Э��ĳ��������������Ч��ʹ��EMU_BCT����ͨ��
		Э��ĳ��������RegBoardState()ע��״̬���ݡ�
		
		��غ�����	ChangeStateBlockValidLen()
					SetStateBlockValidFlag()
					PrintState() 
�� �ߣ�	yuanf	
�� �ģ� ����
ʱ �䣺 2012.3.14			
*****************************************************/ 
extern int RegNewBoardState
(
	unsigned int	uiID,		/*״̬��ID��*/
	unsigned char 	ucLabCode,	/*״̬���ʶ��*/
	char 			*buffer,	/*״̬�����ݴ�ŵ�ַ*/
	unsigned int 	len,		/*״̬��������󳤶�*/
	unsigned int 	uiShowType,	/*״̬��������ʾ����*/
	char 			*pName,		/*״̬��������(ASCII�ַ�)*/
	unsigned char ucBackup		/*�����ֽ���0*/
);

/*****************************************************
��������ChangeStateBlockValidLen()
ChangeStateBlockValidLen(){}
�� �ܣ�	����������Զ�̬���޸���RegNewBoardState()ע���״̬�����ݵ���Ч���ȡ�

�� �룺	ucLabCode	ָ��״̬���ݿ�ı�ʶ��
		uiValidLen	״̬���ݿ����Ч����
�� ����	OK		�޸ĳɹ�
		ERROR	�޸�ʧ��
				ԭ��
				1 ���������״̬��
				2 ��Ч���ȳ�����󳤶�
				3 �޸ı�ʶ��Ϊ0x01��״̬��

�� ����	�޸��¸�ʽ״̬���ϱ���������Ч���ȡ�û���޸�ǰ��״̬�����Ч���ݳ���
		Ϊע���������ݿ鳤�ȡ�
				
		����
			ChangeStateBlockValidLen(0x02,100);
			
		��غ�����	RegNewBoardState()
					SetStateBlockValidFlag()
					PrintState() 
�� �ߣ�	yuanf	
�� �ģ� ����
ʱ �䣺 2012.3.14				
*****************************************************/ 
extern int ChangeStateBlockValidLen
(
	unsigned char ucLabCode,	/*״̬���ʶ��*/
	unsigned int uiValidLen	/*״̬�����ݵ���Ч����*/
);

/*****************************************************
��������SetStateBlockValidFlag()
SetStateBlockValidFlag(){}
�� �ܣ�	�޸�ָ��״̬���������Ч���ȡ�

�� �룺	ucLabCode	ָ��״̬���ݿ�ı�ʶ��
		ucFlag		״̬���ݿ���Ч��־
					1	״̬���ݿ���Ч
					0	״̬���ݿ���Ч
					other ����
�� ����	OK		�޸ĳɹ�
		ERROR	�޸�ʧ��
		ԭ��	1 ע���״̬�鲻���¸�ʽ��״̬��
				2 ������ָ����״̬��

�� ����	����������������޸��¸�ʽ״̬���Ƿ���Ч�ı�־��Ĭ�������
		�¸�ʽ״̬�����������Ч�����ϣ��ĳ��״̬�鲻�ϱ������ܣ�
		�����������������״̬����Ч��־��Ϊ��Ч���������Ͻ������
		�����״̬�飻Ҳ���Խ���Ч��״̬���Ϊ��Ч�ģ�����������ʾ
		���״̬�顣
		
		����������Զ�̬���޸���RegNewBoardState()ע���״̬������
		����Ч��־��
		
		����:
		�޸�״̬��Ϊ��Ч״̬��:
		SetStateBlockValidFlag(0x02,0);
		
		�޸�״̬��Ϊ��Ч״̬��:
		SetStateBlockValidFlag(0x02,1);
		
		��غ���:	RegNewBoardState()
					ChangeStateBlockValidLen()
					PrintState()
�� �ߣ�	yuanf	
�� �ģ� ����
ʱ �䣺 2012.3.14				
*****************************************************/ 
extern int SetStateBlockValidFlag	/*yuanf070116*/
(
	unsigned char ucLabCode,		/*״̬���ʶ��*/
	unsigned char ucFlag			/*״̬�����ݵ���Ч��־*/
);


/*****************************************************
��������PrintState() 
PrintState(){}

�� �ܣ�	��ӡ״̬������Ϣ
	
�� �룺	��
	
�� ����	��

�� ����	����ʱ��ͨ����������鿴����״̬�����������Ϣ��

		��غ���:	RegBoardState()
					SetAlmPmOffset()
					RegNewBoardState()
					ChangeStateBlockValidLen()
					SetStateBlockValidFlag()
					
�� �ߣ�	yuanf	
�� �ģ� ����
ʱ �䣺 2012.3.14	
*****************************************************/
extern void PrintState(void);



#ifdef	__cplusplus
}
#endif	/* __cplusplus */

#endif	/*INC_BMUV2STATE_H*/

/***************************************************************/
/*************************End bmuV2State.h************************/
/***************************************************************/

