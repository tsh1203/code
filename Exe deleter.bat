 @echo off 
set "folderPath=C:\git\code" 
if exist "%folderPath%" ( 
    del /s /q "%folderPath%\*.exe" 
    echo 删除exe文件成功. 
) else ( 
    echo 删除失败. 
) 
pause 