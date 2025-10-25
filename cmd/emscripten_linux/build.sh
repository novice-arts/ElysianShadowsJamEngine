

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cmake --build $SCRIPT_DIR/../../build_web
cp $SCRIPT_DIR/../../misc/index.html $SCRIPT_DIR/../../build_web/index.html
