#!/usr/bin/env bash

set -euo pipefail

arduino-cli core update-index
arduino-cli core install keyboardio:avr-tools-only arduino:avr keyboardio:gd32

ARDUINO_DATA="$(arduino-cli config dump | awk '/data/ { print $2 }')"
ARDUINO_VERSION="$(arduino-cli board details -b keyboardio:avr:model01 | awk '/Board version/ { print $3 }')"

make -C "${ARDUINO_DATA}/packages/keyboardio/hardware/avr/${ARDUINO_VERSION}/libraries/Kaleidoscope" setup

