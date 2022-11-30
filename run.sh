#!/bin/bash

# colors
YELLOW='\033[1;33m'
NONE='\033[0m'

OUTDIR='dist'

# Compile code
(
cd ./${OUTDIR} &&
echo -e "${YELLOW}Compiling${NONE}" &&
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 &&
make
)

# Run executable
echo -e "${YELLOW}Running code.${NONE}"
./${OUTDIR}/opengl
