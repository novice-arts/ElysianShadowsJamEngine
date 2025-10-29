
set "CMAKE_BUILD_DIR=%~dp0"
set "CMAKE_BUILD_DIR=%CMAKE_BUILD_DIR:\=/%../../build"

cmake.exe --build %CMAKE_BUILD_DIR%
echo /F | xcopy %~dp0..\..\build\deps\SDL\SDL3.dll %~dp0..\..\build\. /Y 
echo /F | xcopy %~dp0..\..\build\deps\SDL_image\SDL3_image.dll %~dp0..\..\build\. /Y 