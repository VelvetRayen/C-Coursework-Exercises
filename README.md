# C-Coursework-Exercises

My C programming learning journey: small exercises and mini-projects, organized by topic.
Every program is a console application written in plain C.

## Contents

### 01-Loops
| File | What it does |
|------|--------------|
| `01-multiplication-table.c` | Reads an integer N and prints its multiplication table from 0 to 9. |
| `02-even-numbers-in-range.c` | Reads two integers and prints every even number between them. |
| `03-sum-of-digits.c` | Reads a number and adds up its digits using a `while` loop. |
| `04-reverse-number.c` | Asks for a strictly positive number (re-asking until valid) and prints it reversed. |
| `05-food-menu-switch.c` | Shows a small food menu and uses a `switch` to confirm the dish you picked. |

### 02-1D-Arrays
| File | What it does |
|------|--------------|
| `01-array-rotation.c` | Rotates the elements of an array to the right a given number of times. |
| `02-longest-consecutive-run.c` | Finds the longest run of a chosen value in an array and where it starts. |
| `03-bubble-sort.c` | Fills an array and sorts it in ascending order with bubble sort. |
| `04-temperature-humidity-stats.c` | Menu-driven program that stores temperature and humidity readings, edits them, and computes max/min, averages and standard deviation. |

### 03-2D-Arrays
| File | What it does |
|------|--------------|
| `01-matrix-search-occurrences.c` | Fills a 5x10 matrix, counts how many times a value appears, and finds its first position. |
| `02-matrix-sum.c` | Reads two matrices and sums their elements. |
| `03-saddle-points.c` | Finds the saddle points of a matrix (smallest in its row and largest in its column). |
| `04-stock-matrix-menu.c` | Stock manager using a shelves x products matrix: update quantities, total per product, prices, then sort and binary search. |

### 04-Strings
| File | What it does |
|------|--------------|
| `01-print-char-array.c` | Builds a string from a character array and prints it. |
| `02-string-length.c` | Reads a first name and computes its length without `strlen`. |
| `03-concat-string-halves.c` | Reads two strings and joins the first half of one with the first half of the other. |
| `04-string-menu.c` | Menu for string work: split a sentence into words, list the vowels of a word, build a sentence (work in progress). |

### 05-Structs
| File | What it does |
|------|--------------|
| `01-participants-management.c` | Event participant manager using a `struct`: add, compute a bill (lunch, dinner, hotel), filter by hotel category, and delete by CIN (national ID number). |
| `02-warehouse-management.c` | Warehouse manager using a `struct`: add warehouses and products per shelf, list by type, find the most stocked, change managers, count by city, and delete empty ones. |

## How to compile and run

```bash
gcc -Wall -Wextra 01-Loops/01-multiplication-table.c -o multiplication-table
./multiplication-table
```

The humidity program uses `sqrt()`, so on Linux/macOS add `-lm`:

```bash
gcc -Wall -Wextra 02-1D-Arrays/04-temperature-humidity-stats.c -o stats -lm
```
