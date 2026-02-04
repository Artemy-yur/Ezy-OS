@echo off
echo Building Ezy_OS project with GCC...

REM Список всех исходных файлов C в проекте
set SRCS=main.c^
 file/workfiles.c^
 additions/calculator.c^
 additions/timenow.c^
 additions/wearth/getWearth.c^
 interface/interface.c^
 additions/help/help.c^
 additions/infos.c

REM Добавляем пути для заголовочных файлов
set INCLUDES=-I. -Ilibraru

REM Команда компиляции с флагами
echo Compiling with GCC...
gcc %SRCS% %INCLUDES% -o Ezy_OS.exe -lws2_32 -Wall -Wextra -g

REM Проверка на успешное завершение команды (errorlevel 0)
if %ERRORLEVEL% equ 0 (
    echo.
    echo --- Build successful! ---
    echo Executable created: Ezy_OS.exe
    
    REM Копируем Python файлы для help
    if exist "additions\help\help.py" (
        copy "additions\help\help.py" ".\" >nul
        echo Copied help.py
    )
    
    echo.
    echo To run: Ezy_OS.exe
) else (
    echo.
    echo --- Build FAILED! ---
    echo Check for compilation errors above.
)

pause