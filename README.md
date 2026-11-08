<div align="center">

# Programming Fundamentals
### A structured repository of procedural programming, algorithms, and practical lab problem solving in C.

[![Language](https://img.shields.io/badge/Language-C11-00599C?style=flat-square&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C11_(C_language_revision))
[![Compiler](https://img.shields.io/badge/Compiler-GCC-4B5563?style=flat-square&logo=gnu&logoColor=white)](https://gcc.gnu.org/)
[![Platform](https://img.shields.io/badge/Platform-Cross--Platform-1F2937?style=flat-square)](https://github.com/PopSharkkk/ProgrammingFundamentals)
[![Status](https://img.shields.io/badge/Coursework-Active-059669?style=flat-square)]()

</div>

---

## Overview

This repository houses a comprehensive collection of coursework, laboratory assignments, practical programming exams, competitive quizzes, and conceptual tutorials developed in the **C programming language**.

Engineered with an emphasis on low-level memory awareness, algorithmic efficiency, and clean code hygiene, this codebase covers fundamental topics including control flow, recursive problem solving, pointer mechanics, multi-dimensional structures, and search-and-sort paradigms.

---

## Core Pillars

<div align="center">

| Pillar | Focus | Concepts |
| :--- | :--- | :--- |
| **01. Foundations** | Syntax & Control Flow | Primitives, standard I/O streams, conditional evaluation, iterative loops |
| **02. Modularity & Recursion** | Procedural Abstraction | Stack frame allocation, pass-by-reference semantics, divide-and-conquer, recursive backtracking |
| **03. Memory & Pointers** | Low-Level Access | Pointer arithmetic, memory addressing, dereferencing, buffer boundaries |
| **04. Structured Data** | Collections & Records | Multi-dimensional arrays, matrix transformations, string tokenization, structs |
| **05. Algorithms** | Search, Sort & Graph Traversal | Sieve of Eratosthenes, prefix sums, binary search, DFS/maze traversal, dynamic programming |

</div>

---

## Repository Architecture

The project is organized into modular directories categorizing weekly coursework, thematic problem sets, practical lab exams, tutorials, and examination suites:

```text
ProgrammingFundamentals/
├── Assignment/
│   ├── 5025251024_... S_1 to S_7/     # Weekly laboratory assignments & terminal records
│   └── Tugas 1 to Tugas 8/            # Thematic problem sets (Algorithms, Recursion, Strings)
│
├── Practical Exam/
│   └── Modul 3/                       # Lab Practicum Module 3 (Recursive algorithms, sieve, grid DFS, etc.)
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

## Module Overview & Problem Catalog

### Practical Exam — Modul 3 (Recursion & Problem Solving)

| Problem | File | Paradigm / Method | Description |
| :--- | :--- | :--- | :--- |
| **01. Countdown Protocol** | [`01_Countdown_Protocol.c`](Practical%20Exam/Modul%203/01_Countdown_Protocol.c) | Tail Recursion / Divisibility | Recursive countdown from $N$ to 1 substituting multiples with BIP/BOP/BIPBOP |
| **02. The Empty Chair** | [`02_The_Empty_Chair.c`](Practical%20Exam/Modul%203/02_The_Empty_Chair.c) | Recursion / Combinatorics | Calculating permutation arrangements $N!$ with 64-bit integer precision |
| **03. Prime Seal** | [`03_Prime_Seal.c`](Practical%20Exam/Modul%203/03_Prime_Seal.c) | Recursive Primality Test | Validating primes with recursive trial division up to $\sqrt{N}$ |
| **04. The Prime Ledger** | [`04_The_Prime_Ledger.c`](Practical%20Exam/Modul%203/04_The_Prime_Ledger.c) | Sieve of Eratosthenes + Prefix Sums | Answering $O(1)$ range queries for prime counts up to $10^6$ |
| **05. Echo Sequence** | [`05_Echo_Sequence.c`](Practical%20Exam/Modul%203/05_Echo_Sequence.c) | Recurrence Relations | Computing Fibonacci sequence values via recursive definition |
| **06. Hall of Mirrors** | [`06_Hall_of_Mirrors.c`](Practical%20Exam/Modul%203/06_Hall_of_Mirrors.c) | State Transformation / Recursion | Simulating sequential alternating mirror transformations $A(x)$ and $B(x)$ |
| **07. Letter Lock** | [`07_Letter_Lock.c`](Practical%20Exam/Modul%203/07_Letter_Lock.c) | Recursive Backtracking | Lexicographic circular permutation generator without duplication |
| **08. Twin Signals** | [`08_Twin_Signals.c`](Practical%20Exam/Modul%203/08_Twin_Signals.c) | Euclidean Algorithm | Calculating GCD and LCM using 64-bit recursive Euclidean reduction |
| **09. Lantern Maze** | [`09_Lantern_Maze.c`](Practical%20Exam/Modul%203/09_Lantern_Maze.c) | Graph Traversal (DFS) | 2D grid pathfinding and reachability check from 'S' to 'E' |
| **10. Frog Crossing** | [`10_Frog_Crossing.c`](Practical%20Exam/Modul%203/10_Frog_Crossing.c) | Recursion + Memoization | Dynamic programming search for minimum cost frog river crossing |

---

## Toolchain & Build Guide

### Prerequisites

All implementations adhere to modern **C11 / POSIX** standards and are verified against **GCC (GNU Compiler Collection)**.

- **Compiler**: GCC 6.0+ / Clang 13.0+
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
