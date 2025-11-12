REM Original g++ direct command
REM g++ -std=c++17 src/VaultManager.cpp src/CredentialManager.cpp src/CLI.cpp src/main.cpp -I include -o ./build/PasswordManager.exe

REM Cmake Build commands
REM cmake -G "MinGW Makefiles" -S . -B build

REM APP Build
cmake -G Ninja -S . -B build
cmake --build build

Rem unit tests build
cmake -S tests -G Ninja -B build_tests
cmake --build build_tests

REM run application
.\build\PasswordManager.exe

REM run unit testing
cd build_tests
ctest --output-on-failure