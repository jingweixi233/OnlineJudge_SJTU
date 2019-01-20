#include <iostream>

using namespace std;

const int N = 100005;
long long int arr[N];
long long int tmp[N];
long long int niCount = 0;

void merge(int l, int m, int r){
    int i = l;
    int j = m + 1;
    int k = l;
    while(i <= m && j <= r){
        if(arr[i] > arr[j]){
            tmp[k] = arr[j];
            k = k + 1;
            j = j + 1;
            niCount = niCount + m - i + 1;
        }
        else{
            tmp[k] = arr[i];
            k = k + 1;
            i = i + 1;
            
        }
    }
    while(i <= m){
        tmp[k] = arr[i];
        k = k + 1;
        i = i + 1;
    }
    while(j <= r){
        tmp[k] = arr[j];
        k = k + 1;
        j = j + 1;
        
    }
    for(i = l; i <= r; i++){
        arr[i] = tmp[i];
    }
}

void mergeSort(int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num, i;
    cin >> num;
    for(i = 0; i < num; i++){
        cin >> arr[i];
    }
    mergeSort(0, num - 1);
    cout << niCount << '\n';
    
    
}









