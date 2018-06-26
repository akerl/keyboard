#!/usr/bin/env bash

set -euo pipefail

SCRIPT_DIR="$(python -c 'import os, sys; print(os.path.dirname(os.path.realpath(sys.argv[1])))' "$BASH_SOURCE")"

cd "$(dirname "$SCRIPT_DIR")"

if [[ -z "${1:-}" ]] ; then
    echo 'Must provide path to .hex file'
    exit 1
fi

export HEX_FILE_PATH="$1"

./board/libraries/Kaleidoscope/bin/kaleidoscope-builder flash

