
set "CMAKE_BUILD_DIR=%~dp0"
set "CMAKE_BUILD_DIR=%CMAKE_BUILD_DIR:\=/%../../build_web"

cmake --build %CMAKE_BUILD_DIR%
echo /F | xcopy %~dp0..\..\misc\index.html %~dp0..\..\build_web\. /Y 