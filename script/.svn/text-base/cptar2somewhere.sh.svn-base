#!/bin/bash

export LC_ALL=C
export LANG=zh_CN.GB2312

cd `dirname $0`

if [[ "$1" = "--help" ||  "$1" = "-h" ]] ; then
    echo " Usage: cptar2somewhere.sh [prjtype] ..."
    echo " [prjtype]  : all or 2ln4 or 20tp2 or 12tn2 or ..., default is all"
    exit 1
fi

my_cur_dir=$(pwd)

prj_path="$my_cur_dir/.."

#定义打包路径
packet_path="$prj_path/../package"

#定义远程路径
remote_path="/home/lldeng/mnt/pots_14/F6K-ETH/bfd"

#定义库路径、打包路径
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

find_tar_name="\(*.tar"
tar_list=`find ${boad_path} -name ${find_tar_name}`

echo "***********************************************************"
echo "           cp  ${processing_name} tar to somewhere"
echo "***********************************************************"

#拷贝文件到指定
for tar_name in ${tar_list}
do
	cp -v -p ${tar_name} ${remote_path} #保留文件属性
done
