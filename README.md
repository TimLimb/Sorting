# Sorting

Overview

This program generates random datasets, applies sorting algorithms to them, and evaluates their performance. Key steps include:

    Generating 3 datasets of random numbers in varying sizes.
    Implementing 3 sorting algorithms to sort both unsorted and pre-sorted datasets.
    Measuring and saving key performance metrics for analysis.
    Visualizing results using graphs.

Number Sets

    Generate random integers (0 to 1,000,000) for datasets of sizes:
        1,000
        10,000
        100,000
    Save sorted copies of each dataset for testing sorted data performance.
    Process 6 datasets: 3 sizes × 2 categories (unsorted and sorted).

Sorting Algorithms

The program implements three sorting algorithms:

    Insertion Sort
    Selection Sort 
    Quick Sort

Each algorithm processes both unsorted and sorted datasets.
Data Analysis
Raw Measurements

    Each algorithm sorts each dataset 10 times, resulting in:
        20 runs per algorithm per dataset size.
        Metrics recorded for each run:
            CPU Time.
            Number of Comparisons.
            Number of Swaps.
    Save 180 total measurements to .csv files for analysis.


Deliverables

    Source code and a modular main driver.
    A makefile for building and running the program.
    .csv files with raw measurement data.
    
