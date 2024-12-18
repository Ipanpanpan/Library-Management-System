#ifndef UTILITY_H
#define UTILITY_H


#include <vector>
#include <functional>



template <typename T>
void merge(std::vector<T>& arr, int left, int mid, int right, std::function<bool(T, T)> comp);

template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right, std::function<bool(T, T)> comp);






#endif // UTILITY_H
