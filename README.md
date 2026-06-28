# c-algorithms 📚

A clean, well-documented C library of classic sorting and searching algorithms.
Built for learning, teaching, and as a reference implementation.

![Language](https://img.shields.io/badge/C-C99-blue?logo=c)
![License](https://img.shields.io/badge/License-MIT-green)
![Build](https://img.shields.io/badge/build-passing-brightgreen)

## ✨ Features

### Sorting Algorithms (6)
- **Bubble sort** — simple, stable, O(n²)
- **Selection sort** — in-place, O(n²)
- **Insertion sort** — fast on small/nearly-sorted data, stable, O(n²)
- **Merge sort** — divide & conquer, stable, O(n log n)
- **Quick sort** — divide & conquer, in-place, average O(n log n)
- **Heap sort** — in-place, O(n log n), no recursion

### Searching Algorithms (2)
- **Linear search** — O(n), works on unsorted data
- **Binary search** — O(log n), requires sorted data

## 🚀 Quick Start

```bash
# Build the static library
make

# Run the demo
make run-demo

# Run tests
make test
```

## 📖 Usage Example

```c
#include "calgorithms.h"
#include <stdio.h>

int main(void) {
    int arr[] = {64, 25, 12, 22, 11};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    calgo_quick_sort(arr, n);
    calgo_print_array(arr, n);
    // Output: [11, 12, 22, 25, 64]

    int idx = calgo_binary_search(arr, n, 22);
    printf("Found 22 at index %d\n", idx);
    // Output: Found 22 at index 2

    return 0;
}
```

Compile with:
```bash
gcc -Iinclude my_program.c -L. -lcalgorithms -lm -o my_program
```

## 📂 Project Structure

```
c-algorithms/
├── include/
│   └── calgorithms.h     # public API
├── src/
│   ├── sort.c            # 6 sorting algorithms
│   └── search.c          # linear & binary search + utils
├── examples/
│   └── demo.c            # interactive demo + benchmark
├── tests/
│   └── test_calgorithms.c # unit tests
├── Makefile
├── LICENSE
└── README.md
```

## 📊 Complexity Reference

| Algorithm      | Best       | Average    | Worst      | Space   | Stable |
|----------------|------------|------------|------------|---------|--------|
| Bubble sort    | O(n)       | O(n²)      | O(n²)      | O(1)    | ✓      |
| Selection sort | O(n²)      | O(n²)      | O(n²)      | O(1)    | ✗      |
| Insertion sort | O(n)       | O(n²)      | O(n²)      | O(1)    | ✓      |
| Merge sort     | O(n log n) | O(n log n) | O(n log n) | O(n)    | ✓      |
| Quick sort     | O(n log n) | O(n log n) | O(n²)      | O(log n)| ✗      |
| Heap sort      | O(n log n) | O(n log n) | O(n log n) | O(1)    | ✗      |
| Linear search  | O(1)       | O(n)       | O(n)       | O(1)    | —      |
| Binary search  | O(1)       | O(log n)   | O(log n)   | O(1)    | —      |

## 🧪 Tests

```
make test
```

Covers:
- Empty arrays (no crash)
- Single-element arrays
- Already-sorted arrays
- Reverse-sorted arrays
- Random arrays
- All-duplicate arrays
- Negative numbers

## 📝 License

MIT — see [LICENSE](LICENSE).

## 👤 Author

**Muhammet TUĞRUL**
- GitHub: [@keykavus324-svg](https://github.com/keykavus324-svg)
- Website: [Personal page](https://jtjffqq1lzfn.space.minimax.io)