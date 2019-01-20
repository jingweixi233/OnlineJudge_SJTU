//aLen[0] = 1
//aLen[k] = MAX{aLen[i] ,0 <= i < k且a[i] < a[k]} + 1


#include <iostream>

using namespace std;

const int N = 1000005;
long long int nums[N];
long long int numLast[N];

int binarySearch(int n, int obj){
    int l = 0;
    int r = n - 1;
    int mid;
    mid = (l + r) / 2;
    while(l < r){
        if(obj <= numLast[mid]){
            if(obj == numLast[mid]){
                return mid;
            }
            else{
                r = mid;
            }
        }
        else{
            l = mid + 1;
        }
        mid = (r + l) / 2;
    }
    return l;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, end = 0, hole;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    numLast[0] = nums[0];
    
    for(i = 1; i < n; i++){
        if(nums[i] >= numLast[end]){
            end = end + 1;
            numLast[end] = nums[i];
            continue;
        }
        hole = binarySearch(end + 1, nums[i]);
        numLast[hole] = nums[i];
    }
    
    cout << end + 1;

}
