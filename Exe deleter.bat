@echo off 
set "folderPath=%~dp0" 
if exist "%folderPath%" ( 
    del /s /q "%folderPath%\*.exe" 
    echo 删除exe文件成功. 
) else ( 
    echo 删除失败. 
) 
pause 