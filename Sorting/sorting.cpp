#include "sorting.h"  // Include the header file

void insertionSort(std::vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        comparisons++;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
            ++swaps;
            comparisons++;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(std::vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            comparisons++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            std::swap(arr[i], arr[minIdx]);
            swaps++;
        }
    }
}

int partition(std::vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        comparisons++;
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
            swaps++;
        }
    }
    std::swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);
        quickSort(arr, low, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
}
