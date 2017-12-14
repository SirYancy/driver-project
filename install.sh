#!/bin/bash
printf "Installing Driver...\n"
cd Buffer
make
python unload.py
python load.py scull_size=512
cd ..
printf "Scull buffer device at: /dev/scullBuffer0\n"
