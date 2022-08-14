#include <iostream>
#include <vector>
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"

using namespace std;


int main() {

    vector<int> numbers;
    int n;
    cin>>n;

    int digit;
    for(int i=0;i<n;i++){
        cin>>digit;
        numbers.push_back(digit);
    }



    /*insertionSort(numbers);
    for(int i=0;i<n;i++){
        cout<<numbers[i]<<" ";
    }
    cout<<endl;*/


    quickSort(numbers, 0, numbers.size()-1);
    for(int i=0;i<n;i++){
        cout<<numbers[i]<<" ";
    }
    cout<<endl;

    return 0;
}