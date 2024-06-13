@echo off
SETLOCAL

:: 设置项目路径
SET project_path=%~dp0

:: 设置CMake的可执行文件路径，如果CMake不在系统路径中
:: SET cmake_executable=path\to\cmake.exe

:: 创建一个构建目录
IF NOT EXIST "%project_path%build" (
    mkdir "%project_path%build"
)

:: 切换到构建目录
cd /d "%project_path%build"

:: 运行CMake来配置项目
:: 注意：这里假设CMakeLists.txt位于项目根目录
:: 如果CMake的可执行文件路径已设置，请取消下面一行的注释并替换为cmake_executable
cmake .. -G "Visual Studio 17 2022" -A x64
:: %cmake_executable% .. -G "Visual Studio 16 2019" -A x64

:: 构建项目
cmake --build . --config Release

:: 完成
ENDLOCAL