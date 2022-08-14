
#ifndef UNTITLED2_MERGESORT_H
#define UNTITLED2_MERGESORT_H

#include <vector>

void merge(std::vector<int> &data, int begin, int middle, int end) {
    std::vector<int> temp;

    int i = begin;
    int j = middle + 1;
    while (i <= middle && j <= end) {
        if (data[i] < data[j]) {
            temp.push_back(data[i]);
            ++i;
        } else {
            temp.push_back(data[j]);
            ++j;
        }
    }

    while (i <= middle) {
        temp.push_back(data[i]);
        ++i;
    }

    while (j <= end) {
        temp.push_back(data[j]);
        ++j;
    }

    for (int i = begin; i <= end; ++i) {
        data[i] = temp[i - begin];
    }
}

void mergeSort(std::vector<int> &data, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int middle = (begin + end) / 2;
    mergeSort(data, begin, middle);
    mergeSort(data, middle + 1, end);
    merge(data, begin, middle, end);
}

#endif
