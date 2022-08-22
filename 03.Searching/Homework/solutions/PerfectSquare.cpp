#include <iostream>
using namespace std;
bool isPerfectCube(const uint64_t& n){
    uint64_t low = 0, high = n;
    while(low<=high){
        uint64_t mid =( low + high )/2;
        if(mid*mid*mid == n){
            return true;
        }
        if(mid*mid*mid < n){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}

uint64_t highestCost(const uint64_t& n){
    uint64_t i = 0;
    while(i*i*i<=n){
        i++;
    }
    return (i-1)*(i-1)*(i-1);
}

uint64_t numberOfPresents(uint64_t n){
    int result = 0;
    while(n>0){
        result++;
        n -= highestCost(n);
    }
    return result;
}

int main(){
    uint64_t n;
    cin>>n;
    cout<<numberOfPresents(n);
    return 0;
}