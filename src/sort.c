#include "calgorithms.h"
#include <stdlib.h>

void calgo_swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Bubble sort: repeatedly swap adjacent out-of-order pairs.
 * Best: O(n), Avg/Worst: O(n^2), Space: O(1), Stable. */
void calgo_bubble_sort(int *arr, size_t n) {
    if (!arr || n < 2) return;
    int swapped;
    for (size_t i = 0; i < n - 1; i++) {
        swapped = 0;
        for (size_t j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                calgo_swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break; /* already sorted */
    }
}

/* Selection sort: find the minimum and place it at the front.
 * Best/Avg/Worst: O(n^2), Space: O(1), Not stable. */
void calgo_selection_sort(int *arr, size_t n) {
    if (!arr || n < 2) return;
    for (size_t i = 0; i < n - 1; i++) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        if (min_idx != i) calgo_swap(&arr[i], &arr[min_idx]);
    }
}

/* Insertion sort: build sorted prefix by inserting each element.
 * Best: O(n), Avg/Worst: O(n^2), Space: O(1), Stable. */
void calgo_insertion_sort(int *arr, size_t n) {
    if (!arr || n < 2) return;
    for (size_t i = 1; i < n; i++) {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

/* Merge sort: divide and conquer, recursively.
 * Best/Avg/Worst: O(n log n), Space: O(n), Stable. */
static void merge(int *arr, size_t left, size_t mid, size_t right) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    if (!L || !R) { free(L); free(R); return; }

    for (size_t i = 0; i < n1; i++) L[i] = arr[left + i];
    for (size_t j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

static void merge_sort_rec(int *arr, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        merge_sort_rec(arr, left, mid);
        merge_sort_rec(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void calgo_merge_sort(int *arr, size_t n) {
    if (!arr || n < 2) return;
    merge_sort_rec(arr, 0, n - 1);
}

/* Quick sort: partition around a pivot.
 * Best/Avg: O(n log n), Worst: O(n^2), Space: O(log n), Not stable. */
static size_t partition(int *arr, size_t low, size_t high) {
    int pivot = arr[high];
    size_t i = low - 1;
    for (size_t j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            calgo_swap(&arr[i], &arr[j]);
        }
    }
    calgo_swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

static void quick_sort_rec(int *arr, size_t low, size_t high) {
    if (low < high) {
        size_t pi = partition(arr, low, high);
        if (pi > 0) quick_sort_rec(arr, low, pi - 1);
        quick_sort_rec(arr, pi + 1, high);
    }
}

void calgo_quick_sort(int *arr, size_t n) {
    if (!arr || n < 2) return;
    quick_sort_rec(arr, 0, n - 1);
}

/* Heap sort: build max-heap, then extract max repeatedly.
 * Best/Avg/Worst: O(n log n), Space: O(1), Not stable. */
static void heapify(int *arr, size_t n, size_t i) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        calgo_swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void calgo_heap_sort(int *arr, size_t n) {
    if (!arr || n < 2) return;
    for (size_t i = n / 2; i > 0; i--) heapify(arr, n, i - 1);
    for (size_t i = n - 1; i > 0; i--) {
        calgo_swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}