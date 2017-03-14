#!/bin/bash

export LC_ALL=C
export LANG=zh_CN.GB2312

cd `dirname $0`

if [[ "$1" = "--help" ||  "$1" = "-h" ]] ; then
    echo " Usage: selfmake.sh [prjtype] ..."
    echo " [prjtype]  : all or 2ln4 or 20tp2 or 12tn2 or ..., default is all"
    echo " 文件组织目录如下，请将要替换的文件存放到replace目录下 "
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

#更新BFD的最新版本
echo "***********************************************************"
echo "*                     svn up bfd                          *"
echo "***********************************************************"

svn up $prj_path/src
svn up $prj_path/lib

#编译BFD动态库
bash ./build.sh

#拷贝库到打包路径
bash ./replace.sh $1

#打包
bash ./autotar.sh $1

#将打好的包拷贝到远程路径
bash ./cptar2somewhere.sh $1

#定义BFD动态库路径
#src_path="$prj_path/output"
#des_path=jiangbo@10.190.16.50:/home/jiangbo/F6K

#scp ${src_path}/* ${des_path}/

#cd ../output
#pwd

#svn status
#svn --username dinghao --password 000000 commit -m "TP_OAM module auto make and update by Jenkins, svn update username=dinghao" 


