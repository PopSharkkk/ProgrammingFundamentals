<div align="center">

# Programming Fundamentals
### A structured study of procedural programming and algorithmic problem solving in C.

[![Language](https://img.shields.io/badge/Language-C11-00599C?style=flat-square&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C11_(C_language_revision))
[![Compiler](https://img.shields.io/badge/Compiler-GCC-4B5563?style=flat-square&logo=gnu&logoColor=white)](https://gcc.gnu.org/)
[![Platform](https://img.shields.io/badge/Platform-Cross--Platform-1F2937?style=flat-square)](https://github.com/PopSharkkk/ProgrammingFundamentals)
[![Status](https://img.shields.io/badge/Coursework-Active-059669?style=flat-square)]()

</div>

---

## Overview

This repository represents a rigorous, comprehensive exploration of imperative systems programming and core computational problem solving using the **C programming language**. 

Engineered with an emphasis on memory consciousness, algorithmic precision, and clean code hygiene, the codebase spans from foundational control flow to pointer mechanics, multi-dimensional structures, recursion, and search-and-sort paradigms.

---

## Core Pillars

<div align="center">

| Pillar | Focus | Concepts |
| :--- | :--- | :--- |
| **01. Foundations** | Syntax & Control Flow | Primitives, I/O streams, branch prediction, iterative evaluation |
| **02. Modularity** | Procedural Abstraction | Stack frame allocation, pass-by-reference semantics, recursion |
| **03. Memory & Pointers** | Low-Level Access | Pointer arithmetic, memory addressing, dereferencing, buffer handling |
| **04. Structured Data** | Collections & Records | Vectorized arrays, matrix transformations, string tokenization, structs |
| **05. Algorithms** | Search & Sorting | Binary search, linear heuristics, insertion sort, asymptotic efficiency |

</div>

---

## Repository Architecture

The project is organized into dedicated, modular directories separating weekly coursework, thematic problem sets, laboratory tutorials, and examination suites.

```text
ProgrammingFundamentals/
├── Assignment/
│   ├── 5025251024_... S_1 to S_7/     # Weekly laboratory assignments & terminal records
│   └── Tugas 1 to Tugas 8/            # Thematic problem sets (Algorithms, Recursion, Strings)
│
├── tutorials/
│   ├── Tutorial/                      # Module 01: Core syntax & streams
│   ├── Tutorial 2/                    # Module 02: Conditional logic & expressions
│   ├── Tutorial 3/                    # Module 03: Iterations, nested loops & geometry
│   ├── Tutorial 4/                    # Module 04: Functions, scope & numerical arrays
│   └── Tutorial 5/                    # Module 05: String buffers & text manipulation
│
├── tests/
│   ├── EAS/                           # Final semester evaluations & practical solutions
│   ├── EAS Practice/                  # Advanced problem sets (Recurrences & math models)
│   └── Remidial ETS 1/                # Midterm evaluations & pattern optimization
│
├── Quiz/                              # Rapid competitive challenges & pointer quizzes
├── .gitignore                         # Environment & build artifact filters
└── README.md                          # Repository documentation & guide
```

---

## Toolchain & Build Guide

### Prerequisites

All implementations adhere to modern **C11 / POSIX** standards and are verified against **GCC (GNU Compiler Collection)**.

- **Compiler**: GCC 11.0+ or Clang 13.0+
- **Build Target**: Native binary executable (`.exe` on Windows, ELF binary on Linux/macOS)

### 1. Compilation
To build any module with standard optimization and math linking:
```bash
gcc -O2 -std=c11 <filename>.c -o <output_name> -lm
```
> [!NOTE]
> The `-lm` flag links the standard mathematical library (`<math.h>`) when trigonometric or exponential computations are evaluated.

### 2. Execution
- **macOS / Linux:**
  ```bash
  ./<output_name>
  ```
- **Windows (PowerShell / Command Prompt):**
  ```powershell
  .\<output_name>.exe
  ```

---

## Engineering Standards

- **Memory Hygiene**: Deterministic allocation, boundary enforcement on string buffers, and explicit cleanup.
- **Syntactic Restraint**: Idiomatic C with meaningful identifiers, defensive bounds checking, and predictable return codes.
- **Portability**: Source code designed to build deterministically across Windows, macOS, and Linux toolchains.

---

<div align="center">

<sub>Curated with care for academic excellence and foundational engineering mastery.</sub>

</div>
