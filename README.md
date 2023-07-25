# Sorting Algorithms

## Description

This project contains implementations of various sorting algorithms in C. The following algorithms are included:

- Bubble sort for arrays
- Insertion sort for doubly linked lists
- Selection sort for arrays
- Quick sort with Lomuto partition scheme (always choosing the last element as the pivot)
- Shell sort using the Knuth sequence for arrays
- Count sort for arrays
- Merge sort for arrays
- Heap sort for arrays
- Radix sort for arrays
  
## How to Use

To use these sorting algorithms, you can simply include the relevant header file in your C program and call the appropriate function. The header files and function names for each algorithm are as follows:

- Bubble sort: `sort.h`, `bubble_sort(int *array, size_t size)`
- Insertion sort: `sort.h`, `insertion_sort_list(listint_t **list)`
- Selection sort: `sort.h`, `selection_sort(int *array, size_t size)`
- Quick sort: `sort.h`, `quick_sort(int *array, size_t size)`
- Shell sort: `sort.h`, `shell_sort(int *array, size_t size)`
- Count sort: `sort.h`, `counting_sort(int *array, size_t size)`
- Merge sort: `sort.h`, `merge_sort(int *array, size_t size)`
- Heap sort: `sort.h`, `heap_sort(int *array, size_t size)`
- Radix sort: `sort.h`, `radix_sort(int *array, size_t size)`

Each function takes an array or doubly linked list and its size as input, and sorts the array or list in ascending order. The implementations also print the array or list after each swapping operation, as required by the project specifications.

## How to Compile

To compile the sorting algorithms, simply run the following command in your terminal:

``` shell
gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 <Required C files> -o <Output filename>
```

## Example Usage

Each alorithm implementation is followed by a main file that contains a test case (for example 0-bubble_sort.c is followed by 0-main.c)

## Credits

This project was completed as part of the ALX software engineering program.
