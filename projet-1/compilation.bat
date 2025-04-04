@echo off



echo %~dp0

gcc %~dp0src/*.c -I%~dp0../allegro/include -L%~dp0../allegro/lib -lmingw32 -lallegro_monolith.dll -o%~dp0/exe/programme.exe

%~dp0/exe/programme.exe
  
pause