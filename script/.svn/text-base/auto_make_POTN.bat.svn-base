set NP_BATDIR=%CD%\..\prj
set NP_WORKDIR=%CD%\..\prj
echo %NP_BATDIR%
set "NP_BATDIR=%NP_BATDIR:\=/%"
echo %NP_BATDIR%

@rem make tp_oam.zb
pushd "%NP_WORKDIR%\tp_oam_module"
call clean_cmd.cmd
echo auto_clean_hard ret=%errorlevel%
::pause
@rem if %errorlevel% NEQ 0 goto errEnd
call build_cmd.cmd
echo auto_make_hard ret=%errorlevel%
@rem if %errorlevel% NEQ 0 goto errEnd
popd

FCCmdD.exe ..\prj\tp_oam_module\PPC603gnu\tp_oam_module\Debug\tp_oam_module.out ..\output\tp_oam.zb

goto goodEnd

:errEnd

date /T 
time /T

echo ************************************************
echo Failed to build
echo Welcome to Fiberhome SystemSoftware!
echo ************************************************
pause
exit/b 44
goto end

:goodEnd

date /T 
time /T

echo ************************************************
echo Build complete!
echo Welcome to Fiberhome SystemSoftware!
echo ************************************************


exit/b 0

:end
exit/b 0
echo %errorlevel%
