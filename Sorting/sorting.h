#ifndef SORTING_H
#define SORTING_H

#include <vector>

void insertionSort(std::vector<int>& arr, int& comparisons, int& swaps);
void selectionSort(std::vector<int>& arr, int& comparisons, int& swaps);
void quickSort(std::vector<int>& arr, int low, int high, int& comparisons, int& swaps);

#endif // SORTING_ALGORITHMS_H
