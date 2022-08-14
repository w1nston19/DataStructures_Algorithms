#ifndef UNTITLED2_QUICKSORT_H
#define UNTITLED2_QUICKSORT_H

#include <vector>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (std::vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int> &data, int low, int high) {
    if(low >= high) {
        return;
    }
    int pi = partition(data,low, high);
    quickSort(data, low, pi -1 );
    quickSort(data, pi +1, high );
}

#endif
