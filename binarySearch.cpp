#include <stdio.h>
#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int obj){
    int l = 0;
    int r = n - 1;
    int mid;
    mid = (l + r) / 2;
    while(l <= r){
        if(obj <= arr[mid]){
            if(obj == arr[mid]){
                return mid;
            }
            else{
                r = mid - 1;
            }
        }
        else{
            l = mid + 1;
        }
        mid = (r + l) / 2;
    }
    return -1;
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    int b = binarySearch(a, 5 , 2);
    cout << b << endl;
}
