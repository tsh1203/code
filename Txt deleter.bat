@echo off 
set "folderPath=%~dp0" 
if exist "%folderPath%" ( 
    del /s /q "%folderPath%\*.txt" 
    echo 删除txt文件成功. 
) else ( 
    echo 删除失败. 
) 
pause 