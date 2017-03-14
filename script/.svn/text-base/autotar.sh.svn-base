#!/bin/bash

export LC_ALL=C
export LANG=zh_CN.GB2312

cd `dirname $0`

if [[ "$1" = "--help" ||  "$1" = "-h" ]] ; then
    echo " Usage: autotar.sh [prjtype] ..."
    echo " [prjtype]  : all or 2ln4 or 20tp2 or 12tn2 or ..., default is all"
    exit 1
fi

my_cur_dir=$(pwd)

prj_path="$my_cur_dir/.."

packet_path="$prj_path/../package"

#定义打包路径
typeset -u processing_name	#转成大写
if [ "$1" = "" ];then
        processing_name=all	#默认是all
else
        processing_name=$1
fi

if [ "${processing_name}" = "ALL" ] ; then
        boad_path=${packet_path}
else
	boad_path=`find ${packet_path} -type d -name ${processing_name}*`
fi
packet_bash_name=autotar.sh

#打包
echo "***********************************************************"
echo "                    autotar  ${processing_name}"
echo "***********************************************************"
packet_pack_bash_name_list=`find ${boad_path} -name ${packet_bash_name}`
for packet_pack_bash_name in ${packet_pack_bash_name_list}
do
	packet_pack_bash_path=`dirname ${packet_pack_bash_name}`
	cd ${packet_pack_bash_path}
	
	echo "========================================================================================================"
	echo "   autotar in ${packet_pack_bash_path}"
	echo "========================================================================================================"

	bash ${packet_bash_name}
done
