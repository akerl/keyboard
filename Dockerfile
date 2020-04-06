FROM docker.pkg.github.com/dock0/pkgforge/pkgforge:latest
RUN pacman -S --noconfirm --needed arduino arduino-avr-core
