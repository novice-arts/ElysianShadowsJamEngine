
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cmake -S . -B $SCRIPT_DIR/../../build -DCMAKE_BUILD_TYPE=Debug
