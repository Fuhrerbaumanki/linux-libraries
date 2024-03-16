#ifndef SORT_H
#define SORT_H

#ifdef __cplusplus
extern "C" {
#endif

void merge(int array[], int const left, int const mid, int const right);
void mergeSort(int array[], int const begin, int const end);
void printArray(int A[], int size);
int rand_int(int min, int max);

#ifdef __cplusplus
}
#endif

#endif // SORT_H
