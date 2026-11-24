# Nonlinear equation - finding the roots of polynomial

This project compares the bisection, secant and Newton-Raphson methods for finding the roots of the polynomial f(x) = (x − 1)(x − 3)^6. The simple root x = 1 is found with all three methods, while the multiple root x = 3 (multiplicity 6) is found with the secant and Newton-Raphson methods only. The approximate solution and the difference between consecutive approximations are recorded in each iteration, which allows the convergence rate of the methods to be compared and shows how a root of higher multiplicity slows convergence down.

**Author:** Michal Sikora
**Subject:** Numerical Methods in Physics
**Major and Faculty:** Computer Physics, Faculty of Physics and Applied Computer Science, AGH

## Structure of the project:
- 'src/' - source code (main.cpp, root.hpp)
- 'data/' - solutions of the project
- 'plots/' - graphs and script for plotting the data (PNG, PDF)
- 'report/' - report of a project (PDF)

## Requirements:
- g++ with C++20 support (tested with GCC 15)
- Ubuntu/Debian: `sudo apt install liblapack-dev`
- Python 3.8+ (tested with 3.14)
- matplotlib: `sudo apt install python3-matplotlib` or `pip install matplotlib`
- numpy: `sudo apt install python3-numpy` or `pip install numpy`

## System
- OS: Ubuntu 26.04.1 LTS, Linux 7.0.0-38-generic (aarch64)
- Virtualization: QEMU virtual machine
- CPU: 4 cores, 1 thread per core, 64-bit ARM (aarch64), vendor ID reported as Apple
- RAM: 3.3 GiB (plus 3.8 GiB swap)
- Compiler: g++ (Ubuntu 15.2.0-16ubuntu1) 15.2.0
- Python: <3.14.4>
- matplotlib: <3.10.7+dfsg1>
- BLAS: OpenBLAS <0.3.32+ds-5>
- LAPACK: liblapack3 <3.12.1>

## Build and run

From the `src/` directory:

    g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o main -llapacke


The program writes the solution files to `../data/`, so run it from `src/`
and make sure the `data/` directory exists.

## Plots

From the project root:

    python3 plots/plots.py