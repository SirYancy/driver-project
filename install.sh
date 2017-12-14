#!/bin/bash
printf "Installing Driver...\n"
cd Buffer
make
python unload.py
python load.py scull_size=20
cd ..
make
printf "Scull buffer device at: /dev/scullBuffer0\n"
