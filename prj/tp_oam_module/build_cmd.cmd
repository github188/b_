
@echo off
pushd ..\
call envvars_vxworks.bat VxWorks6_9
popd

pushd PPC603gnu
copy Makefile.auto Makefile.me /y
make.exe -f Makefile.me all
echo build ret=%errorlevel%
popd
::pause