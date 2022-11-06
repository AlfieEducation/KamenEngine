#!/bin/bash
# Build script for vulkan engine
set echo on

mkdir -p ../bin

# Get a list of all the .c files
cFilenames=$(find . -type f -name "*.c")

# echo "Files:" $cFilenames

assembly="testbed"
compilerFlags="-g -shared -fdeclspec -fPIC"
# -fms-extensions
# - Wall -Werror
includeFlags="-Isrc -I../engine/src/"
linkerFlags="-L../bin/ -lengine -Wl,-rpath,."
# -L.usr/X11R6/lib
defines="-D_DEBUG -DKEXPORT"

echo "Building $assembly..."
echo clang $cFilenames $compilerFlags -o ../bin/$assembly $defines $includeFlags $linkerFlag
clang $cFilenames $compilerFlags -o ../bin/$assembly $defines $includeFlags $linkerFlags

