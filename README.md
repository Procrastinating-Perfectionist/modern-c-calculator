# Modern CLI Calculator (C-Based)

A robust, feature-rich Command Line Interface (CLI) calculator designed for efficiency and reliability. This application handles basic arithmetic and advanced operations while maintaining a persistent history of all calculations.



## 🚀 Key Features
* **Comprehensive Arithmetic:** Supports Addition, Subtraction, Multiplication, and Division.
* **Power Functionality:** Advanced calculation support for exponents ($x^y$).
* **Persistent Logging:** Automatically records every calculation in `history.txt` for future reference.
* **Smart History Management:** Integrated tools to view, search, or clear the calculation log.
* **Robust Error Handling:** Built-in protection against division-by-zero and non-numeric input crashes.
* **Enhanced UX:** Uses ANSI color-coded outputs to differentiate between inputs, results, and system errors.

## 🛠️ Technical Implementation
* **Language:** C (Standard C89/C90 compatible for maximum portability).
* **Library Usage:** Utilizes `math.h` for complex operations and `stdio.h` for file I/O.
* **Memory Management:** Static allocation for high speed and low overhead.



## 💻 How to Run
### Prerequisites
You will need a C compiler (GCC, Clang, or an IDE like Dev-C++).

### Compilation
If using **GCC** via terminal:
```bash
gcc calculator.c -o calculator -lm
