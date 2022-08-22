#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int queryResponse(const vector<int>& numbers,const vector<unsigned long long>&periodic, const pair<int,int>& input){
    auto it = upper_bound(numbers.begin(),numbers.end(),input.second);
    int startIndex = it - numbers.begin() -1;
    if(startIndex == -1){
        return 0;
    }
    if(startIndex == numbers.size()){
        startIndex--;
    }
    if(periodic[startIndex] <= input.first){
        return startIndex + 1;
    }

    uint64_t minFind = periodic[startIndex] - input.first;
    auto left = upper_bound(periodic.begin(),periodic.end(),minFind);
    int endIndex = left - periodic.begin();
    if(periodic[endIndex - 1] == minFind){
        endIndex--;
    }
    return startIndex - endIndex;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;

    vector<int> numbers;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        numbers.push_back(tmp);
    }

    sort(numbers.begin(),numbers.end());

    vector<unsigned long long > sums;
    uint64_t tmpVal = 0;
    for (int i = 0; i < n; ++i) {
        tmpVal += numbers[i];
        sums.push_back(tmpVal);
    }

    vector<pair<int,int>> queries;
    for(int i=0;i<q;i++){
        pair<int,int> tmp;
        cin>>tmp.first>>tmp.second;
        queries.push_back(tmp);
    }

    for(int i=0;i<q;i++){
        printf("%d \n",queryResponse(numbers,sums,queries[i]));
    }

    return 0;
}