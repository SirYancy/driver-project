#!/bin/bash
printf "Installing Driver...\n"
cd Buffer
make
python unload.py
<<<<<<< HEAD
python load.py scull_size=10
=======
python load.py scull_size=20
>>>>>>> aa1d13fa174ffed49878b81bd8c40c85a8abe306
cd ..
make
printf "Scull buffer device at: /dev/scullBuffer0\n"
