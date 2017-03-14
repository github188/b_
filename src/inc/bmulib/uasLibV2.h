/****************************************************************
** �� �� ����uasLibV2.h
** ��    ��: UAS�������V2�汾��
** ����  �ߣ�yuanf

** �� �� �ˣ�yuanf
** �ա�  �ڣ�2012.05.15	
** �޸�˵��������

** ��    ����1.0

****************************************************************/

#ifndef	INC_UASLIBV2_H
#define	INC_UASLIBV2_H
#include "bmuType.h"

#if	__cplusplus
extern "C"
{
#endif /*__cplusplus*/

struct USR_UAS_STRUCT
    {
		/* �û���������*/		
		unsigned long	ulSesLimit;				/*��·��������������*/
		unsigned long long ullErrorCounter;		/*�ɼ��������������(8�ֽ�)*/		
		unsigned char ucLofFlag;				/*��ǰ����·�ź�״̬�Ƿ���Lof�ı�־(1��LOF��0��LOF)*/		
		unsigned char ucDefectFlag;				/*��ǰ����·�ź�״̬�Ƿ�������ȱ�ݱ�־(1������ȱ�ݣ�0������ȱ��)*/

        /*UAS�������������*/       
		unsigned short usEscapeSecond;			/*15���������ŵ�ʱ�� ��λ����*/
        unsigned short usLofSecond;				/*15��������LOF(֡��ʧ)��ʱ��(��λ����)*/       
        unsigned short usEsSecond;				/*15��������Es(�����������������)��ʱ��(��λ����)*/        
        unsigned short usNoEsSecond;			/*15������û�������ʱ��(��λ����)*/       
        unsigned short usSesSecond;				/*15��������SES(��������)��ʱ��(��λ����)*/       
        unsigned short usCsSesSecond;			/*15������������SES(��������)��ʱ��(��λ����)*/      
        unsigned short usUasSecond;				/*15��������UAS(��������)��ʱ��(��λ����)*/       
        unsigned short usUsedSecond;			/*15����������ʹ��(��UAS)��ʱ��(��λ����)*/        
        unsigned long long ullCvs;				/*15����������(����UAS��ES)�������������(8���ֽ�)*/       
        unsigned long long ullBbe;				/*15�����ڱ����������������(8���ֽ�)*/             
        float fEsRate;							/*15�������������*/        
        float fSesRate;							/*15�����������������*/

        /*��ʱ�洢������*/        
        unsigned char ucNoUseFlag;				/*�źŲ����ñ�־*/       
        unsigned char ucEsTemp;					/*���ڲ�����״̬�µ���ES��ʱ��*/      
        unsigned char ucNoEsTemp;				/*���ڲ�����״̬�µ�������ʱ��*/       
        unsigned char ucSesTemp;				/*���ڿ���״̬�µĲ�����ʱ��*/       
        unsigned long long ullBbeTemp;			/*���ڲ�����״̬�µ��������*/
		struct USR_UAS_STRUCT *pstuNext;		/*��һ��UAS���ݽṹ*/
    }; 

/*****************************************************
    ��������UasLibInit()

    �� �ܣ�	UAS������ʼ������

    �� �룺	��

    �� ����	OK		��ʼ���ɹ�
    		ERROR	��ʼ��ʧ��

    �� ����	��ʼ��UAS������Ҫ�ı�����������Դ

    �� �ߣ�	yuanf

    �� �ģ� ����

    ʱ �䣺 2012.05.15
*****************************************************/
extern int UasLibInit(void);

/*****************************************************
    ��������RegUas()

    �� �ܣ�	ע��һ����Ҫ�����UAS��

    �� �룺	pstuUserUas		��Ҫ�����UAS���ݽṹ

    �� ����	OK		ע��ɹ�
    		ERROR	ע�����
    				ԭ��	1 �������ΪNULL
    						2 �����UAS���ݽṹ�Ѿ���ע��
    						3 û���㹻���ڴ�

    �� ����	���������UAS������һ��UAS���ݽṹ,�����ݴ˽ṹ�����������UASֵ����������ݽṹ��:
    	ucLofFlag,ucDefectFlag,ulSesLimit,ullErrorCounter���û���������ݣ���ΪUAS���������

    	ucLofFlag		��ǰ����·�ź�״̬�Ƿ���Lof�ı�־(1��LOF��0��LOF)
    	ucDefectFlag	��ǰ����·�ź�״̬�Ƿ�������ȱ�ݱ�־(1������ȱ�ݣ�0������ȱ��)  	
    	ulSesLimit		��·��������������
    	ullErrorCounter	�ɼ��������������(8�ֽ�)

		usEscapeSecond	15������ʱ��ֵ
    	usLofSecond		15������LOFֵ
    	usEsSecond		15������ESֵ
    	ucSesCode		15������SESֵ
    	ucCsSesCode		15������CSSESֵ
    	usCvsCode		15������CVSֵ
    	usBbeCode		15������BBEֵ
    	ucUasCode		15������UASֵ
    	ucNoEsCode		15������NOESֵ
    	ucUseCode		15������USEֵ
    	ucEsRate		15�������������
    	ucSesRate		15�����������������

    	NOES			ָ15������û��ES��UAS��ʱ��
    	USE				ָ15������û��UAS��ʱ��
    	�������		ָ15������ES/USE��ֵ
    	�����������	ָ15������SES/USE��ֵ
    	
    	����

    	struct USR_UAS_STRUCT g_stuVc4Uas[4];

		for(i = 0; i < 4; i++)
		{
			//������������
    		g_stuVc4Uas[i].ulSesLimit = 2500; 	
    		RegUas(&g_stuRsUas);
		}

    �� �ߣ�	yuanf

    �� �ģ� ����

    ʱ �䣺 2012.05.15
*****************************************************/  
extern int RegUas(struct USR_UAS_STRUCT *pstuUserUas);

/*****************************************************
    ��������DeleteUas()

    �� �ܣ�	ע��һ����Ҫ�����UAS��

    �� �룺	pstuUserUas		��Ҫɾ����UAS���ݽṹ

    �� ����	OK		ɾ���ɹ�
    		ERROR	ɾ������
    				ԭ��	1 û���ҵ�ָ����UAS���ݽṹ

    �� ����	ɾ��һ���Ѿ�ע���UAS���ݽṹ

    		����	DeleteUas(&g_stuVc4Uas[1]);
    �� �ߣ�	yuanf

    �� �ģ� ����

    ʱ �䣺 2012.05.15
*****************************************************/
extern int DeleteUas(struct USR_UAS_STRUCT *pstuUserUas);

/*****************************************************
    ��������RegUasGatherFunc()

    �� �ܣ�	ע��ɼ�����ĺ�����

    �� �룺	func		�ɼ�����ĺ���

    �� ����	OK		ע��ɹ�
    		ERROR	ע�����
    				ԭ��	1 �������ΪNULL  						
    						2 û��ע��UAS

    �� ����	�������ע������ɼ�������������ɼ�������Ӧ��UAS���ݽṹ�ĳ�Ա
    		ucLofFlag��ucDefectFlag��ulErrorCounter��ֵ�����ڼ���UAS.

    		ע�⣺��ִ���������ǰ����ִ��RegUas(),���UAS����ĳ�ʼ����

    		����
			struct USR_UAS_STRUCT g_stuVc4Uas[4];
    		int GatherError(void)
    		{
    			int i;
    			for(i = 0; i < 4; i++)
    			{
    				g_stuVc4Uas[i].ucLofFlag = 1;
    				g_stuVc4Uas[i].ucDefectFlag = 1;
    				g_stuVc4Uas[i].ullErrorCounter += 10000;
    			}

    			return OK;
    		}
    		
    		int UsrEntry(void)
    		{
				int i;

				for(i = 0; i < 4; i++)
				{	
					RegUas(&g_stuVc4Uas[i]);
				}

    			RegUasGatherFunc((FUNCPTR)GatherError);
    		}

    �� �ߣ�	yuanf

    �� �ģ� ����

    ʱ �䣺 2012.5.15
*****************************************************/
extern int RegUasGatherFunc(FUNCPTR func);

/*****************************************************
    ��������RegGetUasResultFunc()

    �� �ܣ�	ע��UAS��������ֵ�����ܵĺ�����

    �� �룺	func		UAS��������ֵ�����ܵĺ���

    �� ����	OK		ע��ɹ�
    		ERROR	ע�����
    				ԭ��	1 �������ΪNULL
    						2 û��ע��UAS

    �� ����	ͨ���˺���ע����û�����func(),��UAS��������(tUasCal)���㵱ǰ���UAS��
			����һ�Σ���UAS�������������ܡ�

    		ע�⣺��ִ���������ǰ����ִ��RegUas(),���UAS����ĳ�ʼ����

    		����int GetUasPmResult(void)
				{
					int i;

					for(i = 0; i < 4; i++)
					{
						for(i = 0; i < 4; i++)
						{
							SetPm(1,(char *)&lineCode[i],7,0,0,0,LOF_CODE,1,g_stuVc4Uas[i].usLofSecond);
							SetPm(1,(char *)&lineCode[i],7,0,0,0,ES_CODE,1,g_stuVc4Uas[i].usEsSecond);
							SetPm(1,(char *)&lineCode[i],7,0,0,0,SES_CODE,1,g_stuVc4Uas[i].usSesSecond);
							SetPm(1,(char *)&lineCode[i],7,0,0,0,CVS_CODE,1,g_stuVc4Uas[i].ullCvs);
						}
					}
				}

				RegGetUasResultFunc((FUNCPTR)GetUasPmResult);
    		
    �� �ߣ�	yuanf

    �� �ģ� ����

    ʱ �䣺 2012.05.15
*****************************************************/
extern int RegGetUasResultFunc(FUNCPTR func);	

/*****************************************************
    ��������RegUasTask1sProcFunc()

    �� �ܣ�	ע�������봦��������1sʱ�̵㴦������

    �� �룺	func		1sʱ�䵽ʱ�Ĵ�����

    �� ����	OK		ע��ɹ�
                ERROR	ע�����
                                ԭ��	1 �������ΪNULL
                                                2 û���㹻���ڴ�
                                                3 û��ע��UAS

    �� ����	ͨ���˺���ע����û�����func(),��UAS��������(tUasCal)ʱÿ��
                1���ӱ�ִ��һ�Ρ����Դ�����UAS��ص�һЩ��־���澯�����ܺ͵�
                �̵�����Ҫ��

                ע�⣺��ִ���������ǰ����ִ��RegUas(),���UAS����ĳ�ʼ����

                ����
                int ProcFunc1(void)
        {
                if(g_stuRsUas.ullErrorCounter > g_uiSdAlmLimit)
                {
                        //���ø澯��־
                        SetSdAlmFlag(ON);
                }
                else
                {
                        //�澯�Ѿ�������������澯��־
                        if(IsSdAlm() == OK)
                        {
                                //����澯��־
                                SetSdAlmFlag(OFF)
                        }
                }

                return OK;
        }

        int UsrEntry(void)
        {
                RegUasTask1sProcFunc((FUNCPTR)ProcFunc1);
        }

    �� �ߣ�	yuanf

    �� �ģ� ����

    ʱ �䣺 2009.12.05
*****************************************************/
extern int RegUasTask1sProcFunc(FUNCPTR func);

/*****************************************************
    ��������ActiveUasTask()

    �� �ܣ�	��������ɼ���UAS���������

    �� �룺	��

    �� ����	OK		����Ź���ʱ���ɹ���
    		ERROR	����Ź���ʱ��ʧ�ܻ�û��ע��UAS

    �� ����	�����������Ź��Ķ�ʱ������ʱ�䵽ʱ�ͷ��ź�����
    		��������ɼ���UAS��������(tUasCal)����ͬʱ������
    		�����Ź���ʱ����UASע�������ɼ�ע����ɺ󣬱���
    		ͨ�������������������������(tUasCal)������UAS��
    		����ִ������ɼ�������������㡣

    �� �ߣ�	yuanf

    �� �ģ� ����

    ʱ �䣺 2012.05.15
*****************************************************/
extern int ActiveUasTask(void);


/*****************************************************
    ��������ModifyUasGatherTime()

    �� �ܣ�	��������޸�ע�������ɼ�������ִ�м��ʱ�䡣

    �� �룺	ms		ÿ��ִ�вɼ����뺯����ʱ��������λms��ȡֵ��Χ5-1000ms

    �� ����	OK		�޸ĳɹ�
    		ERROR	û��ע��UAS

    �� ����	Ĭ�����������ɼ�����ÿ100msִ��һ�Σ�������������Լӿ�������
    		��ɼ�����ִ�е�Ƶ�ʡ�Ϊ��ֹоƬ�����������������Լӿ�����ɼ���
    		����ִ��Ƶ�ʡ�����msȡֵʱ�������ms*n = 1000,����nΪ������

    		����
    		ModifyUasGatherTime(500);
    		��
    		ModifyUasGatherTime(1000);

    �� �ߣ�	yuanf

    �� �ģ� ����

    ʱ �䣺 2012.05.15
*****************************************************/
extern int ModifyUasGatherTime(int ms);

/*****************************************************
    ��������ModifyUasTaskPriority()

    �� �ܣ�	��������޸�����ɼ���UAS��������tUasCal�����ȼ���

    �� �룺	newPriority		����tUasCal�������ȼ�

    �� ����	OK		�޸ĳɹ�
    		ERROR	����tUasCal������

    �� ����	Ĭ�����������tUasCal�����ȼ�Ϊ100��ͨ���������������ߺͽ�������tUasCal�����ȼ���

    		����
    		ModifyUasTaskPriority(150);

    �� �ߣ�	yuanf

    �� �ģ� ����

    ʱ �䣺 2012.05.15
*****************************************************/
extern int ModifyUasTaskPriority(int newPriority);

/*****************************************************
    ��������uasShow()

    �� �ܣ�	����������ն�����ʾUAS���ݽṹ������ֵ��

    �� �룺pstuUasNode	ָ����UAS���ݽṹ��ַ

    �� ����	OK		�ɹ�
    		ERROR	û��ע��UAS

    �� ����	����������ڵ���UAS����

    �� �ߣ�	yuanf

    �� �ģ� ����

    ʱ �䣺 2012.05.15
*****************************************************/
extern int uasShow(struct USR_UAS_STRUCT *pstuUasNode);


#if	__cplusplus
}
#endif /*__cplusplus*/

#endif	/*INC_UASLIBV2_H*/

/***************************************************************/
/**************************End uasLibV2.h***********************/
/***************************************************************/
