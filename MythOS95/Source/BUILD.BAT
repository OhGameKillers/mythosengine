@echo off
if .%1==.tools goto tools
if .%1==.tests goto tests
rem ���� Ivory '95 ����������������������������������������������������������
cd ivory
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ���� Felix '95 ����������������������������������������������������������
cd felix
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ���� XFile '95 ����������������������������������������������������������
cd xfile
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ���� Chronos '95 ��������������������������������������������������������
cd chronos
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ���� Bozo '95 �����������������������������������������������������������
cd bozo
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ���� Max '95 ������������������������������������������������������������
cd max
call mk %1
if ERRORLEVEL 1 goto error
cd ..      
rem ���� Van Gogh '95 �������������������������������������������������������
cd vangogh
call mk %1
if ERRORLEVEL 1 goto error
cd ..      
rem ���� Escher '95 ���������������������������������������������������������
cd escher
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ���� Gutenberg '95 ������������������������������������������������������
cd gutenbrg
call mk %1
if ERRORLEVEL 1 goto error
cd ..      
rem ���� Turner '95 ���������������������������������������������������������
cd turner
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ���� Newton '95 ���������������������������������������������������������
cd newton
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ���� Bach '95 �����������������������������������������������������������
cd bach
call mk %1
if ERRORLEVEL 1 goto error
cd ..
rem ���� Profiler '95 �������������������������������������������������������
rem cd profiler
rem call mk %1
rem if ERRORLEVEL 1 goto error
rem cd ..
rem ���� Speilberg '95 ������������������������������������������������������
rem cd spielbrg
rem call mk %1
rem if ERRORLEVEL 1 goto error
rem cd ..
rem ���� System '95 ���������������������������������������������������������
cd system
call mk %1
if ERRORLEVEL 1 goto error
cd ..
goto exit
rem *************************************************************************
rem *************************** Tools ***************************************
rem *************************************************************************
:tools
rem ���� XFile '95 ����������������������������������������������������������
cd xfile
call mk tools
if ERRORLEVEL 1 goto error
cd ..
rem ���� Max '95 ������������������������������������������������������������
cd max
call mk tools
if ERRORLEVEL 1 goto error
cd ..      
rem ���� Van Gogh '95 �������������������������������������������������������
cd vangogh
call mk tools
if ERRORLEVEL 1 goto error
cd ..
rem ���� Escher '95 ���������������������������������������������������������
cd escher
call mk tools
if ERRORLEVEL 1 goto error
cd ..
rem ���� Gutenberg '95 ������������������������������������������������������
cd gutenbrg
call mk tools
if ERRORLEVEL 1 goto error
cd ..      
rem ���� Bach '95 ���������������������������������������������������������
rem ���� MythOS '95 ���������������������������������������������������������
cd util
call mk tools
if ERRORLEVEL 1 goto error
cd ..
goto exit
rem *************************************************************************
rem *************************** Tests ***************************************
rem *************************************************************************
:tests
rem ���� Ivory '95 ����������������������������������������������������������
cd ivory\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ���� Felix '95 ����������������������������������������������������������
cd felix\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ���� XFile '95 ����������������������������������������������������������
cd xfile\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ���� Chronos '95 ��������������������������������������������������������
cd chronos\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ���� Bozo '95 �����������������������������������������������������������
cd bozo\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ���� Max '95 ������������������������������������������������������������
cd max\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ���� Van Gogh '95 �������������������������������������������������������
rem ���� Escher '95 ���������������������������������������������������������
cd escher\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ���� Gutenberg '95 ������������������������������������������������������
cd gutenbrg\test
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..\..
rem ���� Turner '95 ���������������������������������������������������������
rem ���� Newton '95 ���������������������������������������������������������
rem ���� Bach '95 �����������������������������������������������������������
rem ���� Speilberg '95 ������������������������������������������������������
rem cd speilbrg\test
rem call mk clean
rem call mk
rem if ERRORLEVEL 1 goto error
rem cd ..\..
rem ���� Gameframe '95 ������������������������������������������������������
cd gameframe
call mk clean
call mk
if ERRORLEVEL 1 goto error
cd ..
:exit