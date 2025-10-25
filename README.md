# gimbal_project_template
A CMake project template for [libGimbal](https://github.com/gyrovorbis/libgimbal) and SDL3 for PC, Dreamcast, and Web

To compile the project, you can use the scripts in the `cmd` folder. Each subfolder represents the corresponding toolchain 
the project has been tested with. Currently the project has been tested from Windows and Linux (Linux via normal CMake commands).

In each folder, there's 4 scripts: `clean.sh`, `setup.sh`, `build.sh`, and `run.sh`. The scripts should be run in that order (omit `clean.sh` if you're building for the first time).

As of writing, upon compiling the project and running it, you should see a window with a blue background and a red square in the upper left corner.

## For MSVC

If you have a decent installation of Microsoft Visual Studio, you can run the batch scripts found in `cmd/msvc` directly to compile the project.

## For MinGW/MSYS

Presently the project is setup to use MSYS2 MINGW64 terminal, so use the `cmd/msys` folder accordingly. For other types of MinGW installation, 
try the `cmd/mingw` folder and see if that works.

## For Web
In order to compile this project for the web you will need Emscripten installed and the environment activated in your terminal session.
Visit here for more info: https://emscripten.org/docs/getting_started/downloads.html

The project is setup to work from the SDL3 package found in `deps/SDL` so that you have access to all needed source code.

Once you confirm Emscripten is working, the rest of the scripts in `cmd/emscripten_win` should work as expected.

## For Dreamcast
In order to compile this project for Dreamcast, you must first setup the KOS toolchain:
https://dreamcast.wiki/Getting_Started_with_Dreamcast_development

If on Windows 8, you can alternatively install the DreamSDK (which is what I used): https://dreamsdk.org/

Take the time to learn the toolchain before proceeding. Try compiling and running the examples if you're unfamiliar.

Make sure to install the libGL addon if you haven't.

Afterwards, you must manually install the Dreamcast SDL3 Port to the KOS addons folder.
You can check it out here: https://github.com/GPF/SDL/tree/dreamcastSDL3

Once checked out, in the repo, go to the `build-scripts` folder and run `./dreamcast.sh`. Then run 
```
cd dcbuild
make
make install
```

And from there it should install correctly. From that point on, the command scripts in `cmd/dreamsdk` should function as expected.

Note that the result will be a `.elf` file by itself. If you have flycast installed (and visible from your PATH variable), you can do `cmd/dreamsdk/run.sh` to run the file.

