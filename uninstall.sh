
#!/bin/bash
printf "Uninstalling Driver...\n"
cd Buffer
make clean
python unload.py
cd ..
make clean
printf "Uninstalled\n"
