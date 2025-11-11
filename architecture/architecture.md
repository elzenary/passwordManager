# 🧩 Password Manager Architecture

## Overview

This project implements a modular **Password Manager** in modern C++.  
It follows a **Layered Modular Service Architecture**, emphasizing separation of concerns, security, and future extensibility (CLI, GUI, API).

---

## Architecture Layers

| Layer | Responsibility |
|-------|----------------|
| **CLI Layer** | Handles user interaction and aggregates CredentialManager (`ICredentialService`). |
| **Service Layer** | CredentialManager implements `ICredentialService`, manages in-memory credentials, and aggregates VaultManager for persistence. |
| **Persistence Layer** | VaultManager handles secure storage and encryption. |
| **Data Layer** | Contains CredentialData and ServiceCredential, composed by CredentialManager. |

---

## UML Diagram

The full text-based UML diagram with classes, members, methods, and relationships is available in [`uml.txt`](./uml.txt)

---

## Key Design Choices

- **Interface abstraction:** `ICredentialService` decouples front-end from business logic.  
- **Aggregation:** CLI holds `shared_ptr` to CredentialManager; CredentialManager holds `shared_ptr` to VaultManager.  
- **Composition:** CredentialManager owns in-memory `CredentialData`; ServiceCredential contains CredentialData.  
- **Efficient storage:** `unordered_map` enables O(1) lookups by service.  
- **Single responsibility:** Each class handles one concern (CLI, logic, persistence, data).

---

## Summary

This architecture is **modular, secure, and extensible**.  
- CLI aggregates CredentialManager.  
- CredentialManager manages logic, aggregates VaultManager for persistence, and owns CredentialData (composition).  
- VaultManager handles storage and encryption.  

The design supports **future UI or database extensions** without changing core logic.

---

*Author: Ahmed Elzenary*  
*Version: 1.3*
