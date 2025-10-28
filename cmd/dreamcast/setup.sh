
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
kos-cmake -S . -B $SCRIPT_DIR/../../build_dreamcast -DCOMPILE_FOR_DREAMCAST=ON -DSDL3_DIR=/opt/toolchains/dc/kos/addons/lib/dreamcast/cmake/SDL3 -DSDL3_image_DIR=/opt/toolchains/dc/kos/addons/lib/dreamcast/cmake/SDL3_image
