/***********************************************************************************

 * �� �� ��   : bfd_demo.h
 * �� �� ��   : qyliu,��Ȩ��
 * ��������   : 2017��2��28��
 * �� �� ��   : 
 * �ļ�����   : bfd_demo.c ��ͷ�ļ�
 * ��Ȩ˵��   : Copyright (C) 2000-2017   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 

***********************************************************************************/

#ifndef __BFD_DEMO_H__
#define __BFD_DEMO_H__


#ifdef __cplusplus
#if __cplusplus
{
extern "C"
#endif
#endif /* __cplusplus */

extern RESULT_BFDCFG bfd_deleteloop_test(IN NBB_USHORT start_index, IN NBB_USHORT end_index);
extern RESULT_BFDCFG bfd_demo_add();
extern RESULT_BFDCFG bfd_demo_cfg_add();
extern RESULT_BFDCFG bfd_demo_del();
extern RESULT_BFDCFG bfd_init_test(IN NBB_USHORT start_index,
                                    IN NBB_USHORT end_index,
                                    IN NBB_BYTE send_type,
                                    IN NBB_BYTE loop_flag);
extern RESULT_BFDCFG bfd_unit_test_add_alarm();
extern RESULT_BFDCFG bfd_unit_test_add_fpga(unsigned short index);
extern RESULT_BFDCFG bfd_unit_test_cfg(IN OP_TYPE_T op,
             IN unsigned char send_type,
             IN unsigned short num,
             IN NBB_BOOL loop_flag);
extern RESULT_BFDCFG bfd_unit_test_del_alarm();
extern RESULT_BFDCFG bfd_unit_test_del_fpga(unsigned short index);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __BFD_DEMO_H__ */
