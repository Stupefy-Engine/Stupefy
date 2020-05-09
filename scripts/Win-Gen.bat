@echo off
pushd %~dp0\..\
call Stupefy\thirdparty\premake5\premake5.exe vs2019
popd
PAUSE