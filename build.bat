@echo off
chcp 65001 >nul
setlocal EnableDelayedExpansion
title 2H3T - He Thong Quan Ly Nhan Su
color 0B

if not exist build mkdir build

cls
call :banner

call :loading "Dang khoi tao moi truong build" 10

where g++ >nul 2>&1
if errorlevel 1 (
    echo.
    echo [LOI] Khong tim thay g++.
    echo Hay cai MinGW/MSYS2 va them duong dan g++ vao PATH.
    echo Vi du PATH: C:\msys64\ucrt64\bin
    echo.
    pause
    exit /b
)

call :loading "Dang kiem tra cau truc project" 10

if not exist main.cpp (
    echo.
    echo [LOI] Khong tim thay file main.cpp.
    echo Ban can mo CMD dung tai thu muc project co file main.cpp va build.bat.
    echo.
    pause
    exit /b
)

if not exist src (
    echo.
    echo [LOI] Khong tim thay thu muc src.
    echo Hay kiem tra lai cau truc project.
    echo.
    pause
    exit /b
)

if not exist include (
    echo.
    echo [LOI] Khong tim thay thu muc include.
    echo Hay kiem tra lai cau truc project.
    echo.
    pause
    exit /b
)

echo.
echo [BUILD] Dang bien dich project...
echo.

if exist build\compile.log del build\compile.log
if exist build\QuanLyNhanSu.exe del build\QuanLyNhanSu.exe

g++ -std=c++11 -Iinclude main.cpp src\*.cpp -o build\QuanLyNhanSu.exe > build\compile.log 2>&1

if errorlevel 1 (
    echo.
    echo [LOI] Bien dich that bai.
    echo.
    echo Chi tiet loi:
    echo ------------------------------------------------------------
    type build\compile.log
    echo ------------------------------------------------------------
    echo.
    pause
    exit /b
)

echo [THANH CONG] Bien dich thanh cong!

call :loading "Dang mo chuong trinh" 10

cls
build\QuanLyNhanSu.exe

echo.
pause
exit /b


:banner
echo ========================================================================
echo.
echo                         2H3T BUILD SYSTEM
echo                   HE THONG QUAN LY NHAN SU - 2H3T
echo.
echo ========================================================================
echo.
exit /b


:loading
set "TEXT=%~1"
set "TOTAL=%~2"

if "%TOTAL%"=="" set "TOTAL=10"

echo.
echo %TEXT%
echo.

for /l %%A in (1,1,%TOTAL%) do (
    set "BAR="
    set "EMPTY="
    set /a PERCENT=%%A*100/%TOTAL%

    for /l %%B in (1,1,%%A) do (
        set "BAR=!BAR!#"
    )

    set /a SPACE=%TOTAL%-%%A

    if !SPACE! GTR 0 (
        for /l %%C in (1,1,!SPACE!) do (
            set "EMPTY=!EMPTY!."
        )
    )

    echo [!BAR!!EMPTY!] !PERCENT!%%

    ping 127.0.0.1 -n 1 -w 70 >nul
)

exit /b