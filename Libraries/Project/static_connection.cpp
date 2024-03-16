#include "../StaticLib/sort.h"
#include <iostream>

int main() {
  int n = rand_int(5, 25);
  int *arr = new int[n];

  for (int i = 0; i < n; i++)
    *(arr + i) = rand_int(-100, 100);

  std::cout << "Исходный массив \n";
  printArray(arr, n);

  mergeSort(arr, 0, n - 1);

  std::cout << "\nОтсортированный массив: \n";
  printArray(arr, n);

  delete[] arr;
  return 0;
}
