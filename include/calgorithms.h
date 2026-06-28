#ifndef CALGORITHMS_H
#define CALGORITHMS_H

#include <stddef.h>

/* ============================================================
 *  SORTING ALGORITHMS
 *  All sort functions sort an int array in ascending order.
 * ============================================================ */

void calgo_bubble_sort(int *arr, size_t n);
void calgo_selection_sort(int *arr, size_t n);
void calgo_insertion_sort(int *arr, size_t n);
void calgo_merge_sort(int *arr, size_t n);
void calgo_quick_sort(int *arr, size_t n);
void calgo_heap_sort(int *arr, size_t n);

/* ============================================================
 *  SEARCHING ALGORITHMS
 * ============================================================ */

/* Linear search — returns index of `target` in arr, or -1 if not found.
 * Works on unsorted arrays. O(n). */
int calgo_linear_search(const int *arr, size_t n, int target);

/* Binary search — returns index of `target` in arr, or -1 if not found.
 * Requires sorted array. O(log n). */
int calgo_binary_search(const int *arr, size_t n, int target);

/* ============================================================
 *  UTILITIES
 * ============================================================ */

/* Print an int array to stdout. */
void calgo_print_array(const int *arr, size_t n);

/* Swap two ints (used internally but exposed). */
void calgo_swap(int *a, int *b);

/* Return true if the array is sorted ascending, false otherwise. */
int calgo_is_sorted(const int *arr, size_t n);

#endif /* CALGORITHMS_H */