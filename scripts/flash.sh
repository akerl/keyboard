#!/usr/bin/env bash

set -euo pipefail

SCRIPT_DIR="$(python -c 'import os, sys; print(os.path.dirname(os.path.realpath(sys.argv[1])))' "$BASH_SOURCE")"

cd "$(dirname "$SCRIPT_DIR")"

export HEX_FILE_PATH="${1:-pkg/keyboard.hex}"

if [[ ! -e "${HEX_FILE_PATH}" ]] ; then
    echo "Firmware file not found: ${HEX_FILE_PATH}"
    exit 1
fi

./board/libraries/Kaleidoscope/bin/kaleidoscope-builder flash

