@echo off

pushd "%cd%/../../"
set workbenchDir=%CD%
popd

pushd "%cd%/../../../"
set npDir=%CD%
popd

set "workbenchDir=%workbenchDir:\=/%"
set "npDir=%npDir:\=/%"

echo %workbenchDir%

echo %npDir%


copy .\Makefile .\Makefiletmp

@echo off&setlocal
set f1="Makefiletmp"
set f2="Makefile.auto"
set creMake=$(PRJ_ROOT_DIR)/PPC603gnu/creatAutoMake.bat
set dstNpDir=$(PRJ_ROOT_DIR)/../..
set dstWbDir=$(NP_BATDIR)
set dstcreMake=@echo "creatAutoMake_NULL"


(for /f "usebackq delims=" %%a in (%f1%) do (
 set v=%%a
 setlocal enabledelayedexpansion
 set "v=!v:%workbenchDir%=%dstWbDir%!"
 set "v=!v:%npDir%=%dstNpDir%!"
 set "v=!v:%creMake%=%dstcreMake%!"
 echo.!v!
 endlocal
))>%f2%

del .\Makefiletmp
del .\Makefile