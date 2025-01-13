#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <filesystem>  // For filesystem support
#include "sorting.h"  // Include sorting header

using namespace std;
using namespace chrono;
namespace fs = std::filesystem;  // For current working directory

// Function to generate random unsorted data
void generateRandomData(vector<int>& arr, int size) {
    arr.clear();
    for (int i = 0; i < size; ++i) {
        arr.push_back(rand() % 1000000);
    }
}

// Function to generate sorted data
void generateSortedData(vector<int>& arr, int size) {
    arr.clear();
    for (int i = 0; i < size; ++i) {
        arr.push_back(i); // Sorted in increasing order
    }
}

// Function to write the results to CSV
void writeToCSV(const string& fileName, const string& algorithm, int dataSize, bool isSorted, int run, double cpuTime, int comparisons, int swaps) {
    string currentPath = fs::current_path().string();
    string fullFilePath = currentPath + "/" + fileName;

    // Print out the full file path for debugging
    cout << "Saving data to: " << fullFilePath << endl;

    ofstream file;
    file.open(fullFilePath, ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file: " << fullFilePath << endl;
        return;
    }

    file << algorithm << "," << dataSize << "," << (isSorted ? "sorted" : "unsorted") << "," << run << ","
         << fixed << setprecision(6) << cpuTime << "," << comparisons << "," << swaps << "\n";
    file.close();
}

int main() {
    srand(time(0));

    // Test file writing
    ofstream testFile("test_output.txt");
    if (testFile.is_open()) {
        testFile << "Test message: File write is working!\n";
        testFile.close();
        cout << "Test message written to test_output.txt\n";
    } else {
        cerr << "Error writing to test_output.txt\n";
    }

    // Data sizes: 1000, 10000, 100000
    int sizes[] = {1000, 10000, 100000};
    const string algorithms[] = {"InsertionSort", "SelectionSort", "QuickSort"};

    // Output files for CSV
    const string cpuTimeFile = "cpu_time.csv";
    const string comparisonsFile = "comparisons.csv";
    const string swapsFile = "swaps.csv";

    // Initialize CSV headers
    ofstream outFile;
    outFile.open(cpuTimeFile);
    outFile << "algorithm,data_size,sorted,run_number,cpu_time,comparisons,swaps\n";
    outFile.close();

    outFile.open(comparisonsFile);
    outFile << "algorithm,data_size,sorted,run_number,cpu_time,comparisons,swaps\n";
    outFile.close();

    outFile.open(swapsFile);
    outFile << "algorithm,data_size,sorted,run_number,cpu_time,comparisons,swaps\n";
    outFile.close();

    // Run the algorithms on both unsorted and sorted data
    for (int size : sizes) {
        for (bool isSorted : {false, true}) {
            vector<int> data;
            if (isSorted) {
                generateSortedData(data, size);
            } else {
                generateRandomData(data, size);
            }

            cout << "Processing data size: " << size << " (" << (isSorted ? "sorted" : "unsorted") << ")\n";

            for (int run = 1; run <= 10; ++run) {
                for (const string& algo : algorithms) {
                    vector<int> dataCopy = data;  // Copy data to preserve original
                    int comparisons = 0;
                    int swaps = 0;
                    double cpuTime = 0.0;

                    cout << "  Running " << algo << ", Run " << run << "...\n";

                    // Start sorting based on the algorithm
                    auto start = high_resolution_clock::now();
                    if (algo == "InsertionSort") {
                        insertionSort(dataCopy, comparisons, swaps);
                    } else if (algo == "SelectionSort") {
                        selectionSort(dataCopy, comparisons, swaps);
                    } else if (algo == "QuickSort") {
                        quickSort(dataCopy, 0, dataCopy.size() - 1, comparisons, swaps);
                    }
                    auto stop = high_resolution_clock::now();
                    duration<double> duration = stop - start;
                    cpuTime = duration.count();

                    // Save results to CSV
                    writeToCSV(cpuTimeFile, algo, size, isSorted, run, cpuTime, comparisons, swaps);
                    writeToCSV(comparisonsFile, algo, size, isSorted, run, cpuTime, comparisons, swaps);
                    writeToCSV(swapsFile, algo, size, isSorted, run, cpuTime, comparisons, swaps);
                }
            }
        }
    }

    cout << "Sorting performance tests completed!\n";
    return 0;
}
