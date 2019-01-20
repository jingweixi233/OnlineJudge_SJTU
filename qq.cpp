#include <iostream>

using namespace std;

int bSearch(int a[], int n, int obj){
    int l = 0;
    int r = n - 1;
    int mid = (l + r) / 2;
    
    while(l <= r){
        if(obj <= a[mid]){
            if(obj == a[mid]){
                return mid;
            }
            else{
                r = mid - 1;
            }
        }
        else{
            l = mid + 1;
        }
        mid = (l + r) / 2;
    }
    return -1;
}







int main(){
    int i;
    int a[5] = {1, 8 ,2, 4 ,5};
    int s = bSearch(a, 5, 4);
    cout << s;
}
