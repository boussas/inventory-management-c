# Inventory Management System in C

A simple C program to manage an inventory of products.

## Features

* Add products
* Display products
* Search products by name
* Update stock
* Modify price or apply percentage reduction
* Change product supplier
* Sort products by price

## Files

* `main.c` — Basic inventory operations and sorting
* `switch.c` — Menu version for interactive operations
* `fcts.h` / `fcts.c` — Functions for product management

## How to Compile and Run

```bash
gcc main.c fcts.c -o main
./main
```
or
```bash
gcc switch.c fcts.c -o switch
./switch
```

## Usage

1. Enter the number of products.
2. Add product details (name, price, stock, supplier).
3. Use menu options (in `switch`) to manage products.
