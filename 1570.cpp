#include<iostream>
#include <stdio.h>

using namespace std;

long long int binarySearch(long long int *arr, long long int n, long long int num){
    long long int start = 0, end = n - 1, mid = (start + end) / 2;
    long long int res = -1;
    while(start <= end){
        if(arr[mid] < num){
            start = mid + 1;
            res = end;
        }
        else if(arr[mid] == num){
            res =  mid;
            break;
        }
        else{
            end = mid - 1;
            res = end;
        }
        mid = (start + end) / 2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    long long int i, N, T, key;
    cin >> N;
    cin >> T;
    const long long int numLength = N;
    const long long int loveNumLength = T;
    long long int num[numLength];
    long long int loveNum[loveNumLength];
    for(i = 0; i < numLength; i++){
        cin >> num[i];
    }
    for(i = 0; i < loveNumLength; i++){
        cin >> loveNum[i];
    }
    
    for(i = 0; i < loveNumLength; i++){
        key = binarySearch(num, numLength, loveNum[i]);
        cout << numLength - 1 - key << '\n';
    }
}

