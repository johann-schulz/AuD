//
// Created by Timsken on 16/12/2023.
//

#ifndef SORT_H
#define SORT_H

int Partition(int *array, int lowerLimit, int upperLimit, int (*compfunction) (int *, int *));

void Qsort(int *array, int lowerLimit, int upperLimit, int (*compFunction) (int *, int *));

void IntQuickSort(int *array, int count, int (*compFunction) (int *, int *));

void SwapIntPointer(int *pointer1, int *pointer2);

int IncreasingDirection(int *pointer1, int *pointer2);

int DecreasingDirection(int *pointer1, int *pointer2);

#endif //AUD_SORT_H
