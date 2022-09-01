FROM ghcr.io/dock0/pkgforge-golang:latest
RUN pacman -S --noconfirm --needed arduino arduino-avr-core
