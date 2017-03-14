###############################################################################
#(C) COPYRIGHT Fiberhome Telecommunicaiton Technology Co.,Ltd  2000-2012      # 
#                                                                             #
# filename:      build.sh                                                     #
# purpose:       ≤˙∆∑±‡“ÎshΩ≈±æ                                               #
# version:       1.0                                                          #
# mod history:   2012.6.28  created   dingyi                                  #
#                                                                             #
#                                                                             #
###############################################################################
#!/bin/sh

if [[ "$1" = "--help" ||  "$1" = "-h" ]] ; then
    echo " Usage: build.sh [prjtype] [clean] ..."
    echo " [prjtype]  : x86 or equipment or x86bmu, default is equipment"
    echo " [clean]  : clean or noclean, default is not clean"
    exit 1
fi

export LANG=zh_CN.UTF-8

cd `dirname $0`

if [ "$1" = "x86" ] ; then
  export POWERPCTG=0
  export USEBMULIB=0
elif [ "$1" = "x86bmu" ] ; then
  export POWERPCTG=0
  export USEBMULIB=1
else
  export POWERPCTG=1
  export USEBMULIB=0
fi

echo "***********************************************************"
echo "*                     build bfd                           *"
echo "***********************************************************"

if [ "$2" != "noclean" ] ; then
  make clean
fi
make

