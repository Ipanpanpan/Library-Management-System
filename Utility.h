#ifndef UTILITY_H
#define UTILITY_H

template <typename T>
void merge(vector<T>& arr, int left, int mid, int right, function<bool(T, T)> comp);

template <typename T>
void mergeSort(vector<T>& arr, int left, int right, function<bool(T, T)> comp);






#endif // UTILITY_H
