#include <dlfcn.h>
#include <iostream>
#include <ostream>

typedef int (*RandIntFunc)(int, int);
typedef void (*PrintArrayFunc)(int[], int);
typedef void (*MergeSortFunc)(int[], int, int);

int main(int argc, char *argv[]) {
  RandIntFunc randint;
  PrintArrayFunc print_arr;
  MergeSortFunc merge_s;

  void *ext_library = dlopen("../DynamicLib/libsort.so", RTLD_LAZY);
  if (!ext_library) {
    std::cerr << "Ошибка загрузки библиотеки: " << dlerror() << std::endl;
    return 1;
  }

  randint = (RandIntFunc)dlsym(ext_library, "rand_int");
  print_arr = (PrintArrayFunc)dlsym(ext_library, "printArray");
  merge_s = (MergeSortFunc)dlsym(ext_library, "mergeSort");

  if (!print_arr || !merge_s || !randint) {
    std::cerr << "Ошибка загрузки функий: " << dlerror() << std::endl;
    dlclose(ext_library);
    return 1;
  }

  int n = randint(5, 25);
  int *arr = new int[n];

  for (int i = 0; i < n; i++)
    arr[i] = randint(-100, 100);

  std::cout << "Исходный массив: " << std::endl;
  print_arr(arr, n);
  merge_s(arr, 0, n - 1);
  std::cout << "\nОтсортированный масиив: " << std::endl;
  print_arr(arr, n);

  delete[] arr;
  dlclose(ext_library);

  return 0;
}
