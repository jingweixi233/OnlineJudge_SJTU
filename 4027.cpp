
#include<iostream>

using namespace std;

const int N = 100005;

int x[N], y[N], listZen[N], endd[N];

int maxx(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int binarySearch(int arr[], int len, int val){
    int l = 1;
    int r = len;
    int mid;
    if(arr[r] <= val){
        return r + 1;
    }
    while(l < r){
        mid = (l + r) / 2;
        if(arr[mid] <= val){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return r;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i;
    int num, id, len = 1;

    cin >> num;
    for(i = 0; i < num; i++){
        cin >> id;
        x[id] = i;
    }
    for(i = 0; i < num; i++){
        cin >> y[i];
        listZen[i] = x[y[i]];
    }
    endd[1] = listZen[0];
    for(i = 1; i < num; i++){
        int addId = binarySearch(endd, len, listZen[i]);
        endd[addId] = listZen[i];
        if(len < addId){
            len = addId;
        }
    }
    cout << len;
    
}