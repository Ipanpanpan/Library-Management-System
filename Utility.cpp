#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
#include <functional> // For std::function
using namespace std;

// Function to merge two halves of the array
template <typename T>
void merge(vector<T>& arr, int left, int mid, int right, function<bool(T, T)> comp) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    vector<T> leftArr(n1);
    vector<T> rightArr(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (comp(leftArr[i], rightArr[j])) { // Use the custom comparator
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copy remaining elements of leftArr
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    // Copy remaining elements of rightArr
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Template function for merge sort
template <typename T>
void mergeSort(vector<T>& arr, int left, int right, function<bool(T, T)> comp) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, mid, comp);
        mergeSort(arr, mid + 1, right, comp);

        // Merge the sorted halves
        merge(arr, left, mid, right, comp);
    }
}

// Bubble Sort with custom comparator
template <typename T>
void bubbleSort(vector<T>& arr, function<bool(T, T)> comp) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {
            if (!comp(arr[j], arr[j + 1])) { // Use custom comparator
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped, the array is sorted
        if (!swapped) break;
    }
}

