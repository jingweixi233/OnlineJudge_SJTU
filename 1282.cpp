#include <iostream>
#include <cmath>

using namespace std;

const int maxx = 1000000001;
const int N = 2005;
int hi[N], hiSort[N], hiNiSort[N], po[N][N], poMin[N][N];

void quickSort(int a[], int l, int r){
    int i, j, x;
    if(l < r){
        i = l;
        j = r;
        x = a[l];
        while(i < j){
            while(i < j && a[j] >= x){
                j = j - 1;
            }
            if(i < j){
                a[i] = a[j];
                i = i + 1;
            }
            while(i < j && a[i] < x){
                i = i + 1;
            }
            if(i < j){
                a[j] = a[i];
                j = j - 1;
            }
        }
        a[i] = x;
        quickSort(a, l, i -1);
        quickSort(a, i + 1, r);
    }
}

int main(){
    int n, i, j, poSort = maxx, poNi = maxx;
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> hi[i];
        hiSort[i] = hi[i];
        
    }
    quickSort(hiSort, 1, n);
    for(i = 1; i <= n; i++){
        hiNiSort[n - i + 1] = hiSort[i];
    }
    
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            po[i][j] = poMin[i - 1][j] + abs(hi[i] - hiSort[j]);
            if(j == 1){
                poMin[i][j] = po[i][j];
            }
            else{
                if(po[i][j] < poMin[i][j - 1]){
                    poMin[i][j] = po[i][j];
                }
                else{
                    poMin[i][j] = poMin[i][j - 1];
                }
            }
        }
    }
    
    for(i = 1; i <= n; i++){
        if(po[n][i] <= poSort){
            poSort = po[n][i];
        }
    }
    
    
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            po[i][j] = poMin[i - 1][j] + abs(hi[i] - hiNiSort[j]);
            if(j == 1){
                poMin[i][j] = po[i][j];
            }
            else{
                if(po[i][j] < poMin[i][j - 1]){
                    poMin[i][j] = po[i][j];
                }
                else{
                    poMin[i][j] = poMin[i][j - 1];
                }
            }
        }
    }
    
    for(i = 1; i <= n; i++){
        if(po[n][i] <= poNi){
            poNi = po[n][i];
        }
    }
    
    if(poSort > poNi){
        cout << poNi;
    }
    else{
        cout << poSort;
    }
}


