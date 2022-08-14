
#ifndef UNTITLED2_INSERTIONSORT_H
#define UNTITLED2_INSERTIONSORT_H

#include <vector>

typedef unsigned long long ull;

void insertionSort(std::vector<int>& input) {
    ull size = input.size();
    for(ull i=1; i<size;i++){
        int currentValue = input[i];
        long long  j = (long long ) i-1;
        while (j>=0 and input[j] > currentValue){
            input[j+1] = input[j];
            j--;
        }
        input[j+1] = currentValue;
    }

}

#endif
