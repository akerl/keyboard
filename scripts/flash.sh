#!/usr/bin/env bash

set -euo pipefail

binfile="$1"

if [[ ! -f "$binfile" ]] ; then
    echo "File does not exist: $binfile"
    exit 1
fi

./scripts/setup.sh

device="$(arduino-cli board list | awk '/usbmodem/ { print $1 }')"

if [[ -z "$device" ]] ; then
    echo "Keyboard not found"
    exit 1
fi

echo 'Start holding the PROG key (top left) and then hit enter. Keep holding PROG until the script completes'
read

arduino-cli upload -i "$binfile" -p "$device"

