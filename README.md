# Parallel-Sorting

A C++ project for experimenting with and implementing parallelized versions of classic algorithms. The aim is to leverage the power of modern multicore processors to improve the performance of algorithms by executing them in parallel.

## Overview

Each algorithm is written in C++ and aims to utilize parallel programming paradigms (e.g., multithreading) for performance gains over their traditional sequential counterparts.


### Prerequisites

- C++17 or above compatible compiler (e.g., GCC, Clang, MSVC)
- CMake (optional, if you use provided build scripts)

### Building

Clone this repository:

```bash
git clone https://github.com/Heramb4270/Parallel-Sorting.git
cd Parallel-Sorting
```

To compile with g++ (simple example):

```bash
g++ -std=c++17 -pthread -o parallel_sort main.cpp
```

Or use provided CMake scripts (if available):


### Running

After building, run the executable:

```bash
./parallel_sort
```

## Example Usage

Example code for using parallel merge sort:

```cpp
#include "merge_sort.h"
#include <vector>

int main() {
    std::vector<int> arr = {5, 2, 8, 3, 1};
    parallel_merge_sort(arr, 0, arr.size() - 1);
    // arr is now sorted
    return 0;
}
```

## Contributing

Contributions are welcome! Feel free to open issues or pull requests for improvements, bug fixes, or adding new sorting algorithms.

## License

This project is licensed under the MIT License.

---

*Planned: More detailed documentation, performance benchmarks, and usage examples will be added later.*
