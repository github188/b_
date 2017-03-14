#!/bin/bash

export LC_ALL=C
export LANG=zh_CN.GB2312

cd `dirname $0`

if [[ "$1" = "--help" ||  "$1" = "-h" ]] ; then
    echo " Usage: replace.sh [prjtype] ..."
    echo " [prjtype]  : all or 2ln4 or 20tp2 or 12tn2 or ..., default is all"
    echo " �ļ���֯Ŀ¼���£��뽫Ҫ�滻���ļ���ŵ�replaceĿ¼�� "
    echo " +bfd_prj "
    echo " |+script "
    echo " |+... "
    echo " +packet "
    echo " |+2LN4_F6K_V2R3_PACK "
    echo " |+12TN2_F6K_V2R3_PACK "
    echo " |+20TP2_F6K_V2R3_PACK "
    echo " |+replace "
    exit 1
fi

my_cur_dir=$(pwd)

prj_path="$my_cur_dir/.."


#����BFD��̬��·��
bfd_output_path="$prj_path/output"

#������·��
packet_path="$prj_path/../package"

#����������Ҫ�����Ŀ��ͷ�ļ�·��
replace_path="$packet_path/replace"
replace_so_path="$replace_path/so"
replace_so_inc="$replace_path/inc"


#�����·�������·��
typeset -u processing_name	#ת�ɴ�д
if [ "$1" = "" ];then
        processing_name=all	#Ĭ����all
else
        processing_name=$1
fi

if [ "${processing_name}" = "ALL" ] ; then
        boad_path=${packet_path}
else
	boad_path=`find ${packet_path} -type d -name ${processing_name}*`
fi

find_so_name=libtp_oam.so
so_full_name_list=`find $boad_path -name $find_so_name`

echo "***********************************************************"
echo "                    replace  ${processing_name}"
echo "***********************************************************"


#����BFD�⵽���·��
file_list=`find ${bfd_output_path}/ -name *.so`
if [ $? -eq 0 ];then
	for file in ${file_list}
	do
		for so_full_name in $so_full_name_list
		do
			packet_bfd_lib_path=`dirname $so_full_name`
			cp -v ${file} ${packet_bfd_lib_path}/
		done
	done
else
	echo WARNING: DO NOT FINE BFD OUTPUT SO!!!
fi

#�����ļ������·��
file_list=`find ${replace_path} -type f`
if [ $? -eq 0 ];then
	for file_long_name in ${file_list}
	do
		file=${file_long_name##*/}	#ȥ��·���������������ļ���
		board_file_list=`find ${boad_path} -path ${replace_path} -prune -o -name ${file} -print`	#��${boad_path}Ŀ¼�³���${replace_path}Ŀ¼����
		for board_file in ${board_file_list}
		do
			#cp -v -p ${file_long_name} ${board_dir}	#�����ļ�����
			cp -v ${file_long_name} ${board_file}
		done
	done
fi
