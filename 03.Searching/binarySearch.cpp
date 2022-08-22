#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int>& numbers, const int& key){
    int left = 0;
    int right = numbers.size() -1;
    int mid;

    while(left <= right){
         mid = (left + right) /2;

        if(numbers[mid] == key){
            return mid;
        }

        if(numbers[mid] < key){
            left = mid +1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}


int main() {
    vector<int> numbers{2,4,8,9,1,6,45,78,12,15,86};
    sort(numbers.begin(), numbers.end());
    int key = 0;

    for(int i =0;i<numbers.size(); i++){
        cout<<i<<"  ";
    }
    cout<<endl;

    for(int i =0;i<numbers.size(); i++){
        cout<<numbers[i]<<"  ";
    }
    cout<<endl;

    while (key != -1){

        cout<<"Enter a key to search for (-1 for exit)"<<endl;
        cin>>key;

        int result = binarySearch(numbers, key);

        if (result == -1){
            cout<<"Not found";
        } else {
            printf("Key %d found at position %d\n", key, result);
        }

    }
    return 0;
}