//
// Created by Timsken on 16/12/2023.
//

#ifndef AUD_SORT_H
#define AUD_SORT_H

int partition(int *Array, int lowerLimit, int obereGrenze, int (*cmpfct) (int *, int *));

void qsort(int *Array, int lowerLimit, int upperLimit, int (*cmpfct) (int *, int *));

void IntQuickSort(int *array, int count, int (*cmpfct) (int *, int *));

void swapIntPointer(int *pointer1, int *pointer2);

int IncreasingDirection(int *pointer1, int *pointer2);

int DecreasingDirection(int *pointer1, int *pointer2);

#endif //AUD_SORT_H
