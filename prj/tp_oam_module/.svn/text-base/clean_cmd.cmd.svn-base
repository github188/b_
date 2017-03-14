
@echo off
pushd ..\
call envvars_vxworks.bat VxWorks6_9
popd

pushd PPC603gnu
copy Makefile.auto Makefile.me /y
cmd.exe  /c "make.exe -f Makefile.me clean"
echo clean ret=%errorlevel%
popd

::pause