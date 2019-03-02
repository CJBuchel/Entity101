
@echo off
SETLOCAL

CALL "%~dp0lib\greeterTest.exe" %*
EXIT /B %ERRORLEVEL%
ENDLOCAL
