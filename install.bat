@echo off
setlocal

echo [*] Checking for MinGW...
where g++ >nul 2>nul
if %errorlevel% neq 0 (
    echo [!] g++ not found. Please install MinGW and add it to PATH.
    exit /b 1
)

echo [*] Creating build directory...
if not exist build mkdir build

echo [*] Compiling source files (without OpenSSL)...
g++ src\main.cpp src\attacks\*.cpp ^
    -I include -o build\pwcracker.exe

if %errorlevel% neq 0 (
    echo [!] Compilation failed.
    exit /b 1
)

echo [*] Build complete!
echo Run with: build\pwcracker.exe --help

endlocal
