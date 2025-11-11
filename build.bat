REM Original g++ direct command
REM g++ -std=c++17 src/VaultManager.cpp src/CredentialManager.cpp src/CLI.cpp src/main.cpp -I include -o ./build/PasswordManager.exe

REM Cmake Build commands
REM cmake -G "MinGW Makefiles" -S . -B build

cmake -G Ninja -S . -B build
cmake --build build

REM run application
.\build\PasswordManager.exe