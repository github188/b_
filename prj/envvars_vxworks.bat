set VXWORKS6_9_DIR=D:\WindRiver
echo VXWORKS6_9_DIR=%VXWORKS6_9_DIR%

%VXWORKS6_9_DIR%\wrenv.exe -p vxworks-6.9  -o print_vars -f bat >wrenv.bat
		
call wrenv.bat