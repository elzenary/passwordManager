# Password Manager

A secure, cross-platform **command-line interface (CLI)** utility for efficiently managing and securely storing your sensitive login credentials. Built with modern C++.

---

## Features

* **Strong Encryption:** All stored credentials are encrypted using **[TBD]** before being written to disk.
* **Command Line Interface (CLI):** Simple, fast, and lightweight interaction directly from your terminal.
* **Cross-Platform:** Easily buildable on Windows, macOS, and Linux using the **CMake** build system.

---

## Prerequisites

To build and run this project, you need the following dependencies installed on your system:

| Dependency           | Minimum Version| Notes|
| :---                 | :---           | :--- |
| **C++ Compiler**     | C++17 or later | GCC, Clang, or MSVC is required. |
| **CMake**            | 3.10 or later  | Used to generate the build files. |
| **[Ext Crypto Lib]** | [TBD]          | Specific library like OpenSSL or libsodium for crypto. |

---
## BUILDING

Execute these commands from the repository root:

1. Configure: cmake -S . -B build
2. Build: cmake --build build

The executable is in the ./build/ directory.

---

## Contributing

We welcome contributions! If you have suggestions for improvements, please feel free to **open an issue** or submit a **Pull Request (PR)**.

---

## License

This project is licensed under the **[MIT License]** - see the `LICENSE` file for details.
