@echo off
echo ===================================
echo    C++ Maze Solver - Build Script
echo ===================================
echo.

:: Check if we're in the right directory
if not exist "main\main.cpp" (
    echo ERROR: Please run this script from the cpp directory
    echo Current directory should contain main\main.cpp
    pause
    exit /b 1
)

:: Try to compile with g++ if available
where g++ >nul 2>&1
if %errorlevel% == 0 (
    echo Found g++ compiler. Compiling...
    cd main
    g++ -std=c++11 -O2 main.cpp -o main.exe
    if %errorlevel% == 0 (
        echo.
        echo ✓ Compilation successful!
        echo Executable created: main\main.exe
        echo.
        echo Testing with a sample maze...
        if exist "..\mazes\maze_21x21_1.txt" (
            main.exe "..\mazes\maze_21x21_1.txt"
        ) else (
            echo Sample maze not found. You can test manually.
        )
    ) else (
        echo ✗ Compilation failed with g++
    )
    cd ..
) else (
    echo g++ compiler not found.
    echo.
    echo OPTION 1 - Visual Studio (Recommended):
    echo   1. Open main\main.sln in Visual Studio
    echo   2. Press Ctrl+Shift+B to build
    echo   3. The executable will be created automatically
    echo.
    echo OPTION 2 - Install MinGW:
    echo   1. Download from: https://www.mingw-w64.org/
    echo   2. Add to PATH environment variable
    echo   3. Run this script again
    echo.
    echo OPTION 3 - Use Online Compiler:
    echo   1. Copy main.cpp and Read.h to online C++ compiler
    echo   2. Compile and test there
    echo.
    echo NOTE: The Java GUI will work without compiling C++
    echo       (it just won't show solutions)
)

echo.
pause