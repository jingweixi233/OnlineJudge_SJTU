#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

void quickSort(int a[], int l, int r){
    int i, j, x;
    if(l < r){
        i = l;
        j = r;
        x = a[l];
        while(i < j){
            while(i < j && a[j] > x){
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
        quickSort(a, l, i - 1);
        quickSort(a, i + 1, r);
    }
}

int main(){
    int a[100];
    int i;
    srand(time(NULL));
    for(i = 0; i < 100; i++){
        a[i] = rand() %100;
    }
    for(i = 0; i < 100; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    quickSort(a, 0, 99);
    for(i = 0; i < 100; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    
    
    
    
}
