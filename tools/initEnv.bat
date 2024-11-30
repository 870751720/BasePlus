@echo off
%1 %2
ver|find "5.">nul&&goto :Admin
mshta vbscript:createobject("shell.application").shellexecute("%~s0","goto :Admin","","runas",1)(window.close)&goto :eof

:Admin
set /p VCPKG_PATH="请输入vcpkg的路径: "
setx VCPKG_HOME "%VCPKG_PATH%" /M
setx PATH "%PATH%;%VCPKG_PATH%" /M
