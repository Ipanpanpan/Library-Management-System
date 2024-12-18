#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <functional>

template <typename T>
void merge(std::vector<T>& arr, int left, int mid, int right, std::function<bool(const T&, const T&)> comp);

template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right, std::function<bool(const T&, const T&)> comp);

template <typename T>
void bubbleSort(std::vector<T>& arr, std::function<bool(const T&, const T&)> comp);


template <typename T>
void merge(std::vector<T>& arr, int left, int mid, int right, std::function<bool(const T&, const T&)> comp) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> leftArr(n1);
    std::vector<T> rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (comp(leftArr[i], rightArr[j])) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right, std::function<bool(const T&, const T&)> comp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comp);
        mergeSort(arr, mid + 1, right, comp);
        merge(arr, left, mid, right, comp);
    }
}

template <typename T>
void bubbleSort(std::vector<T>& arr, std::function<bool(const T&, const T&)> comp) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (!comp(arr[j], arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}



#endif // UTILITY_H
