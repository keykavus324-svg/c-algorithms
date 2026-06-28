#include "calgorithms.h"
#include <stdio.h>

/* Linear search: scan array left to right. O(n). */
int calgo_linear_search(const int *arr, size_t n, int target) {
    if (!arr) return -1;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] == target) return (int)i;
    }
    return -1;
}

/* Binary search: divide sorted array in half repeatedly. O(log n). */
int calgo_binary_search(const int *arr, size_t n, int target) {
    if (!arr || n == 0) return -1;
    size_t left = 0, right = n - 1;
    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] == target) return (int)mid;
        if (arr[mid] < target) left = mid + 1;
        else if (mid > 0) right = mid - 1;
        else break;
    }
    return -1;
}

void calgo_print_array(const int *arr, size_t n) {
    if (!arr) { printf("NULL\n"); return; }
    printf("[");
    for (size_t i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int calgo_is_sorted(const int *arr, size_t n) {
    if (!arr || n < 2) return 1;
    for (size_t i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) return 0;
    }
    return 1;
}