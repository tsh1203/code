@echo off 
set "folderPath=C:\git\code" 
if exist "%folderPath%" ( 
    del /s /q "%folderPath%\*.exe" 
    echo Successfully deleted exe file. 
) else ( 
    echo The specified folder does not exist. 
) 
pause 