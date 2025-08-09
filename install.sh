#!/bin/bash

# Exit on error
set -e

# Colors
GREEN="\e[32m"
RESET="\e[0m"

echo -e "${GREEN}[+] Checking dependencies...${RESET}"
if command -v apt >/dev/null 2>&1; then
    sudo apt update
    sudo apt install -y g++
elif command -v brew >/dev/null 2>&1; then
    brew install gcc
else
    echo "Please install g++ manually."
fi

echo -e "${GREEN}[+] Creating build directory...${RESET}"
mkdir -p build

echo -e "${GREEN}[+] Compiling source files (without OpenSSL)...${RESET}"
g++ src/main.cpp src/attacks/*.cpp \
    -I include -o build/pwcracker

echo -e "${GREEN}[+] Build complete!${RESET}"
echo -e "Run with: ./build/pwcracker --help"

# Optional: Install globally
read -p "Do you want to install pwcracker globally? (y/n): " yn
if [[ "$yn" =~ ^[Yy]$ ]]; then
    sudo cp build/pwcracker /usr/local/bin/
    echo -e "${GREEN}Installed globally! Run 'pwcracker --help' from anywhere.${RESET}"
fi
