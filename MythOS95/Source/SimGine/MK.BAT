@echo off
echo 같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같
echo 같같같갚�                                                        껑같같�
echo 같같같갚�                S I M    G I N E                        껑같같�
echo 같같같갚�                                                        껑같같�
echo 같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같
cd obj
call nmake /nologo %1 %2 %3 %4 %5 %6 %7 %8 %9
cd ..
if ERRORLEVEL 1 goto error
echo 같같같굉 SimGine - Done 껑같같같같같같같같같같같같같같같같같같같같같같같
goto exit
:error
echo  E r r o r 
:exit
