
#!/bin/bash
printf "Uninstalling Driver...\n"
cd Buffer
make
python unload.py
cd ..
printf "Uninstalled\n"
