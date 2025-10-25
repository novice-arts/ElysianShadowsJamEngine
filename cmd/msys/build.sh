
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cmake --build $SCRIPT_DIR/../../build
cp $SCRIPT_DIR/../../build/deps/SDL/SDL3.dll $SCRIPT_DIR/../../build/SDL3.dll