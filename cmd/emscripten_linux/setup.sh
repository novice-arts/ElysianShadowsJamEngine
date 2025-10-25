
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
emcmake cmake -S . -B $SCRIPT_DIR/../../build_web -DCOMPILE_FOR_WEB=ON
