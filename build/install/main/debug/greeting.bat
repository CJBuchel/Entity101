
@echo off
SETLOCAL

CALL "%~dp0lib\greeting.exe" %*
EXIT /B %ERRORLEVEL%
ENDLOCAL
