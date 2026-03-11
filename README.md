# push_swap — Because swap_push doesn't sound as natural

> A sorting project from the 42 curriculum. The goal is simple: sort a stack of integers using a limited set of operations, with as few moves as possible. The challenge is everything in between.

---

## Table of Contents

- [Overview](#overview)
- [The Rules](#the-rules)
- [Installation & Compilation](#installation--compilation)
- [Usage](#usage)
- [Algorithms](#algorithms)
  - [Disorder Index](#disorder-index)
  - [Simple — O(n²)](#simple--on)
  - [Medium — O(n√n)](#medium--on)
  - [Complex — O(n log n)](#complex--on-log-n)
  - [Adaptive (default)](#adaptive-default)
- [Benchmark Mode](#benchmark-mode)
- [Error Handling](#error-handling)
- [Project Structure](#project-structure)

---

## Overview

`push_swap` receives a list of integers as arguments, loads them into **stack A**, and outputs the shortest sequence of operations needed to sort it in ascending order (smallest on top).

Two stacks are available — **A** and **B** — and the only tools at your disposal are eleven operations:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top of B to the top of A |
| `pb` | Push the top of A to the top of B |
| `ra` | Rotate A upward (first element becomes last) |
| `rb` | Rotate B upward (first element becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A (last element becomes first) |
| `rrb` | Reverse rotate B (last element becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

---

## The Rules

- No global variables.
- On error, print `Error` followed by a newline to **stderr** and exit.
- Operations are printed to **stdout**, one per line.
- The program must handle all four strategy flags, with **adaptive** as the default behaviour when no flag is specified.

---

## Installation & Compilation

Clone the repository and build:

```bash
git clone https://github.com/ChechiDev/42_push_swap.git
cd 42_push_swap
make
```

This compiles `libft` first and then links the binary. The Makefile supports the standard 42 targets:

```bash
make        # build push_swap
make clean  # remove object files
make fclean # remove objects + binary
make re     # fclean + build
make debug  # build with -ggdb3 instead of -O2
```

---

## Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] 
./push_swap [--bench] [--simple | --medium | --complex | --adaptive] 
```

**Basic sorting:**
```bash
./push_swap 4 67 3 87 23
```

**Force a specific algorithm:**
```bash
./push_swap --simple  5 4 3 2 1
./push_swap --medium  5 4 3 2 1
./push_swap --complex 5 4 3 2 1
```

**Verify the output is correct using an external checker:**
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
# OK
```

**Count operations on a large input:**
```bash
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l
```

---

## Algorithms

Rather than committing to a single sorting strategy, `push_swap` analyses the input before deciding how to sort it. The key metric driving that decision is the **disorder index**.

### Disorder Index

Before any move is made, the program calculates what fraction of element pairs are out of order:

```
disorder_index = (inverted_pairs / total_pairs) × 100
```

An *inverted pair* is any two positions `i < j` where `a[i] > a[j]`. The result is a percentage between `0%` (already sorted) and `100%` (fully reversed). It is computed once, before any operation runs, and is used by adaptive mode to route to the most suitable algorithm.

---

### Simple — O(n²)

**Flag:** `--simple`  
**When adaptive picks it:** disorder index < 20%

A selection-sort style approach. On each pass it finds the minimum element in stack A, rotates it to the top using the cheaper direction (from the top or from the bottom), and pushes it to B. Once only three elements remain in A, `sort_3` resolves them with at most two operations. Then everything is pulled back from B in order.

This is the brute-force baseline. It performs well on inputs that are already close to sorted, where only a handful of elements are out of place.

```
~8 ops    for 5 elements
~1380 ops for 100 elements (worst case)
```

---

### Medium — O(n√n)

**Flag:** `--medium`  
**When adaptive picks it:** disorder index between 20% and 50%

A chunk-based greedy algorithm. The sorted value range is divided into equal-sized chunks, and elements are pushed from A to B chunk by chunk. For each chunk, the element nearest to the top or bottom of A is selected to minimise rotations. Elements in the lower half of the chunk get an extra `rb` after being pushed, pre-organising B during the push phase. Once all elements are in B, `push_to_a` pulls them back by always bringing the current maximum to the top with the cheaper rotation direction.

The number of chunks scales with input size:

| Input size | Chunks |
|------------|--------|
| ≤ 5        | 1      |
| ≤ 50       | 2      |
| ≤ 100      | 6      |
| ≤ 500      | 9      |
| > 500      | 11     |

```
~650 ops  for 100 elements
~4500 ops for 500 elements
```

---

### Complex — O(n log n)

**Flag:** `--complex`  
**When adaptive picks it:** disorder index ≥ 50%

A Radix LSD (Least Significant Digit) sort operating on bit indices. The algorithm works in two phases:

**1. Indexing** — each element in A is assigned its rank (0 to n-1) relative to the sorted order. This normalises the values so the algorithm only cares about bit positions, regardless of the actual integer range or sign.

**2. Radix sort** — iterate bit by bit from LSB to MSB. On each pass, elements whose current bit is `0` are pushed to B (`pb`), elements with bit `1` stay in A by rotating (`ra`). After each pass everything comes back from B (`pa`). After `log₂(n)` passes the stack is sorted.

This is the most operation-efficient strategy for large, heavily shuffled inputs.

```
~1084 ops for 100 elements
~6784 ops for 500 elements
```

---

### Adaptive (default)

**Flag:** `--adaptive` *(or no flag at all)*

The default behaviour. The program computes the disorder index before touching the stacks, then routes to whichever algorithm fits best:

| Disorder index | Algorithm selected |
|----------------|--------------------|
| 0%             | Already sorted — no operations needed |
| < 20%          | Simple             |
| 20% – 49%      | Medium             |
| ≥ 50%          | Complex            |

The reasoning behind these thresholds: a nearly-sorted list benefits from a minimum-extraction pass with minimal overhead. As disorder grows, chunk-based sorting amortises rotation costs better. Fully scrambled inputs justify the O(n log n) overhead of Radix, which handles them in the fewest total operations.

---

## Benchmark Mode

Adding `--bench` outputs sorting statistics to **stderr** after the run, without interfering with the operation output on **stdout**. It can be combined with any strategy flag:

```bash
./push_swap --bench --complex 4 67 3 87 23 2>/dev/null
```

```
[BENCH] Disorder:  100.00%
[BENCH] Strategy:  Complex / O(n log n)
[BENCH] Total_ops:  25
[BENCH] sa:  0  sb:  0  ss:  0  pa:  10  pb:  10
[BENCH] ra:  5  rb:  0  rr:  0  rra:  0  rrb:  0  rrr:  0
```

Redirect operations to a checker while saving benchmark output separately:

```bash
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG > ops.txt 2> stats.txt
./checker $ARG < ops.txt
```

---

## Error Handling

The program prints `Error` to stderr and exits cleanly on any of the following:

- Non-integer arguments (e.g. `one`, `3.14`)
- Values outside the `int` range (`> 2147483647` or `< -2147483648`)
- Duplicate values
- Invalid or contradictory flags (e.g. `--simple --complex`)

```bash
./push_swap --adaptive 0 one 2 3    # Error
./push_swap --simple 3 2 3          # Error
./push_swap 2147483648              # Error
```

---

## Project Structure

```
push_swap/
├── push_swap.c                   # Entry point
├── include/
│   └── push_swap.h
├── libft/                        # Custom C library
│   ├── include/libft.h
│   └── src/
└── src/
    ├── algorithm/
    │   ├── simple.c              # O(n²) selection-sort
    │   ├── medium.c              # O(n√n) chunk-based
    │   ├── medium_chunks.c       # Chunk range helpers
    │   ├── complex.c             # O(n log n) Radix LSD
    │   ├── disorder.c            # disorder_meter (ratio)
    │   ├── get_disorder_index.c  # disorder_index (%)
    │   ├── get_algorithm.c       # Algorithm selector
    │   └── set_algorithm.c       # Sorting entry point
    ├── bench/                    # Benchmark counters & output
    ├── check/                    # Input validation
    ├── movement/                 # All 11 stack operations
    ├── parse/                    # Argument parsing
    └── utils/                    # Node helpers, free, print
```
