#!/usr/bin/env bash

set -euo pipefail

mkdir -p pkg

header=""
if [[ -v GITHUB_TOKEN ]] ; then
    header="-HAuthorization: Bearer $GITHUB_TOKEN"
fi

url="$(curl -s "$header" 'https://api.github.com/repos/akerl/keyboard/releases/latest' | grep 'browser_download_url.*model100' | cut -d : -f 2,3 | tr -d \"\ )"

echo "Downloading ${url}"

curl -sLo pkg/model100.bin "${url}"

./scripts/flash.sh pkg/model100.bin

