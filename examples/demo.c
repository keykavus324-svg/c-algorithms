#include "calgorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef void (*sort_fn)(int *, size_t);

typedef struct {
    const char *name;
    sort_fn fn;
} sort_algo;

static const sort_algo ALGOS[] = {
    {"bubble sort",    calgo_bubble_sort},
    {"selection sort", calgo_selection_sort},
    {"insertion sort", calgo_insertion_sort},
    {"merge sort",     calgo_merge_sort},
    {"quick sort",     calgo_quick_sort},
    {"heap sort",      calgo_heap_sort},
};
static const size_t N_ALGOS = sizeof(ALGOS) / sizeof(ALGOS[0]);

static int *random_array(size_t n) {
    int *a = (int *)malloc(n * sizeof(int));
    if (!a) return NULL;
    for (size_t i = 0; i < n; i++) a[i] = rand() % 1000;
    return a;
}

static double benchmark(sort_fn fn, int *arr, size_t n) {
    clock_t start = clock();
    fn(arr, n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main(void) {
    srand((unsigned)time(NULL));

    printf("=== c-algorithms demo ===\n\n");

    /* Demo 1: sort a small array with each algorithm */
    int original[] = {64, 25, 12, 22, 11, 90, 5, 78, 1, 50};
    size_t n = sizeof(original) / sizeof(original[0]);

    printf("Original array: ");
    calgo_print_array(original, n);

    for (size_t i = 0; i < N_ALGOS; i++) {
        int arr[32];
        memcpy(arr, original, sizeof(original));
        printf("%-18s -> ", ALGOS[i].name);
        ALGOS[i].fn(arr, n);
        calgo_print_array(arr, n);
        if (!calgo_is_sorted(arr, n)) {
            fprintf(stderr, "ERROR: %s produced an unsorted array!\n", ALGOS[i].name);
            return 1;
        }
    }

    /* Demo 2: searching */
    int sorted[] = {1, 5, 11, 12, 22, 25, 50, 64, 78, 90};
    size_t ns = sizeof(sorted) / sizeof(sorted[0]);
    int target = 22;
    printf("\nSearching for %d in: ", target);
    calgo_print_array(sorted, ns);
    int idx = calgo_binary_search(sorted, ns, target);
    printf("Binary search: index %d (linear: index %d)\n",
           idx, calgo_linear_search(sorted, ns, target));
    printf("Searching for 999 (missing): linear=%d, binary=%d\n",
           calgo_linear_search(sorted, ns, 999),
           calgo_binary_search(sorted, ns, 999));

    /* Demo 3: performance benchmark */
    printf("\n=== Performance (10,000 random ints) ===\n");
    size_t big = 10000;
    printf("%-18s %10s\n", "Algorithm", "Time (s)");
    printf("------------------------------\n");
    for (size_t i = 0; i < N_ALGOS; i++) {
        int *a = random_array(big);
        if (!a) { fprintf(stderr, "malloc failed\n"); return 1; }
        double t = benchmark(ALGOS[i].fn, a, big);
        printf("%-18s %10.4f\n", ALGOS[i].name, t);
        free(a);
    }

    printf("\nAll sorts verified correct. Done!\n");
    return 0;
}