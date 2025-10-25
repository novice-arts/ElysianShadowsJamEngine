
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
kos-cmake -S . -B $SCRIPT_DIR/../../build_dreamcast -DCMAKE_BUILD_TYPE=Debug -DCOMPILE_FOR_DREAMCAST=ON -DSDL3_DIR=/opt/toolchains/dc/kos/addons/lib/dreamcast/cmake/SDL3
