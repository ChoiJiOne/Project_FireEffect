@echo off

SET visualstudio=vs2022
SET project=FireEffect
SET script=Script\GenerateProjectFiles.bat

%script% %visualstudio% %project% On