#include <iostream>

using namespace std;

const int N = 10005;
int num[N];
void quickSort(int l, int r){
    int i = l, j = r;
    int x = num[i];
    if(i < j){  
        while(i < j){
            while(i < j && num[j] > x){
                j--;
            }
            if(i < j){
                num[i] = num[j];
                i++;
            }
            while(i < j && num[i] < x){
                i++;
            }
            if(i < j){
                num[j] = num[i];
                j--;
            }
        }
        num[i] = x;
        quickSort(l, i - 1);
        quickSort(i + 1, r);
    }
}

int main(){
    int n, i;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> num[i];
    }
    quickSort(0, n - 1);
    for(i = 0; i < n; i++){
        cout << num[i] << ' ';
    }
}