
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cmake -G "MinGW Makefiles" -S . -B $SCRIPT_DIR/../../build -DCMAKE_BUILD_TYPE=Debug
