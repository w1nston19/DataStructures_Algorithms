#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

uint64_t binarySearch(const vector<uint64_t>& input, uint64_t searchFor, int left, int right){
    while(left<=right){
        int middle =left -  (left - right)/2;

        if(input[middle] == searchFor){
            return input[middle];
        }

        if(input[middle] > searchFor){
            right = middle - 1;
        }
        else{
            left = middle + 1;
        }
    }
    if(left>=input.size()){
        return input[input.size()-1];
    }
    if(right<0){
        return input[0];
    }
    int middle =(left+right)/2;
    uint64_t diffA,diffB;
    diffA = input[left] - searchFor;
    diffB = searchFor -input[right];
    if(diffA == diffB){
        return input[right];
    }
    else{
        return diffA>diffB?input[right]:input[left];
    }
}

int main(){
    int m,n;
    cin>>n>>m;
    vector<uint64_t> themes;
    vector<uint64_t> teams;
    for (int i = 0; i < n; ++i) {
        uint64_t tmp;
        cin>>tmp;
        themes.push_back(tmp);
    }
    for (int i = 0; i < m; ++i) {
        uint64_t tmp;
        cin>>tmp;
        teams.push_back(tmp);
    }
    std::sort(themes.begin(),themes.end());
    for (int i = 0; i < m; ++i) {
        cout<<binarySearch(themes,teams[i],0,n-1)<<endl;
    }
    return 0;
}