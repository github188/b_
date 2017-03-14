/***********************************************************************************

 * �� �� ��   : bfd_common.c
 * �� �� ��   : jiangbo,����
 * ��������   : 2016��12��2��
 * �� �� ��   : 
 * �ļ�����   : BFDͨ�ô���
 * ��Ȩ˵��   : Copyright (C) 2000-2016   ���ͨ�ſƼ��ɷ����޹�˾
 * ��    ��   : 
 * �޸���־   : 

***********************************************************************************/

#include "bfd.h"


/* BFDģ���������� */
const char * const result_str[] = {
    "CFG_OK",                 /* ���ӻ�ɾ����Ŀ�����ɹ� */
    "PARAM_ERROR",            /* �������� */
    "KEY_NOT_EQUAL_MYID",     /* keyֵ�����뱾������������� */
    "KEY_NOT_EXIST",          /* KEYֵ������ */
    "SET_DRIVE_ERROR",        /* д����ʧ�� */
    "ALLOC_ERROR",            /* �����ڴ�ռ�ʱʧ�� */
    "ADD_KEY_EXIST",          /* ��key�Ѵ��� */
    "CFG_FULL",               /* �������� */
    "FUC_NULL",               /* �ص�����δע�� */
    "INSERT_ERR",             /* �����������ӽڵ�ʧ�� */
    "FORCED_END",             /* ǿ���սᣬһ������ã���ִ�к���ʵ�֣�ֱ�ӷ��� */
    "FRAME_TYPE_ERR",         /* ��֡���ʹ����֧�� */
    "SET_ARAD",               /* дARAD���� */
    "FPGA_STORT_NULL",        /* δ����洢FPGA�����ݿռ� */
    "KEY_NOT_MATCH",          /* KEYֵ��ƥ�� */
    "FPGA_MYID_TREE",         /* ����FPGAʹ�õĶ�����ʧ�� */
    "IP_TYPE_ERR",            /* IP���ʹ��� */
    "FUNC_RET_ERR",           /* ���������ӿڷ��ش��� */
    "LIST_NULL",              /* ����Ϊ�� */
    "CFG_RESULT_MAX"};

const char * const g_bfd_state_str[BFD_STA_BUTT] = {"Admin", "Down", "Init", "Up"};
const char * const g_bfd_interval_str[BFD_TIME_BUTT] = {"None",      /* �շ��������ļ�¼��1��ʼ���˴��������0��λ */
                                "3.3ms", "10ms", "20ms", "30ms", "40ms", "50ms", "60ms", "70ms", "80ms", "90ms", "100ms",
                                "200ms", "300ms", "400ms", "500ms", "150ms", "250ms", "350ms", "450ms", "1000ms"};
const char * const g_bfd_action_str[BFD_ACTION_NONE + 1] = {"ADMIN", "DOWN", "INIT", "UP", "TIMEOUT", "NONE"};