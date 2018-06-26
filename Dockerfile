FROM dock0/pkgforge
RUN pacman -S --noconfirm --needed arduino arduino-avr-core
