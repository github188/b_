set NP_BATDIR=%CD%\..\..\otn_app\script
set NP_WORKDIR=%CD%\..\..\otn_app\prj


@rem make hard.zb
pushd "%NP_WORKDIR%\32TN1_HARD"
call clean_cmd.cmd
echo auto_clean_hard ret=%errorlevel%
::pause
@rem if %errorlevel% NEQ 0 goto errEnd
call build_cmd.cmd
echo auto_make_hard ret=%errorlevel%
@rem if %errorlevel% NEQ 0 goto errEnd
popd

@rem make soft.zb
pushd "%NP_WORKDIR%\32TN1_SOFT"
call clean_cmd.cmd
echo auto_clean_soft ret=%errorlevel%
@rem pause
@rem if %errorlevel% NEQ 0 goto errEnd
call build_cmd.cmd
echo auto_make_soft ret=%errorlevel%
@rem if %errorlevel% NEQ 0 goto errEnd
popd

@rem make otn_comm2.zb
pushd "%NP_WORKDIR%\OTN_COMM2"
call clean_cmd.cmd
echo auto_clean_otn_comm2 ret=%errorlevel%
@rem pause
@rem if %errorlevel% NEQ 0 goto errEnd
call build_cmd.cmd
echo auto_make_otn_comm2 ret=%errorlevel%
exit /b
popd




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

date /T s
time /T

echo ************************************************
echo Build complete!
echo Welcome to Fiberhome SystemSoftware!
echo ************************************************

exit/b 0

:end
exit/b 0
echo %errorlevel%
