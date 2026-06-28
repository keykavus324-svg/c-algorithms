#include "calgorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*sort_fn)(int *, size_t);

static int passed = 0;
static int failed = 0;

#define ASSERT(cond, msg) do { \
    if (cond) { passed++; printf("  \xE2\x9C\x93 %s\n", msg); } \
    else      { failed++; printf("  \xE2\x9C\x97 %s\n", msg); } \
} while (0)

static void test_sort(sort_fn fn, const char *name) {
    int empty[1] = {0};
    fn(empty, 0);  /* should not crash */

    int single[] = {42};
    fn(single, 1);
    ASSERT(single[0] == 42, "single-element array stays");

    int sorted[] = {1, 2, 3, 4, 5};
    fn(sorted, 5);
    ASSERT(calgo_is_sorted(sorted, 5), "already sorted");

    int reverse[] = {9, 7, 5, 3, 1};
    fn(reverse, 5);
    ASSERT(calgo_is_sorted(reverse, 5), "reverse sorted");

    int random[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    size_t n = sizeof(random) / sizeof(random[0]);
    fn(random, n);
    ASSERT(calgo_is_sorted(random, n), "random array");

    int dupes[] = {5, 5, 5, 5, 5};
    fn(dupes, 5);
    ASSERT(calgo_is_sorted(dupes, 5), "all duplicates");

    int neg[] = {-3, -1, -4, -1, -5, -9, -2, -6};
    size_t nn = sizeof(neg) / sizeof(neg[0]);
    fn(neg, nn);
    ASSERT(calgo_is_sorted(neg, nn), "negative numbers");
    (void)name;
}

int main(void) {
    printf("Running c-algorithms tests...\n\n");

    printf("[sort.c]\n");
    test_sort(calgo_bubble_sort,    "bubble");
    test_sort(calgo_selection_sort, "selection");
    test_sort(calgo_insertion_sort, "insertion");
    test_sort(calgo_merge_sort,     "merge");
    test_sort(calgo_quick_sort,     "quick");
    test_sort(calgo_heap_sort,      "heap");

    printf("\n[search.c]\n");
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    ASSERT(calgo_binary_search(arr, n, 7) == 3,  "binary: found middle");
    ASSERT(calgo_binary_search(arr, n, 1) == 0,  "binary: found first");
    ASSERT(calgo_binary_search(arr, n, 15) == 7, "binary: found last");
    ASSERT(calgo_binary_search(arr, n, 8) == -1, "binary: missing");
    ASSERT(calgo_linear_search(arr, n, 11) == 5, "linear: found");
    ASSERT(calgo_linear_search(arr, n, 100) == -1, "linear: missing");

    printf("\n=== %d passed, %d failed ===\n", passed, failed);
    return failed == 0 ? 0 : 1;
}