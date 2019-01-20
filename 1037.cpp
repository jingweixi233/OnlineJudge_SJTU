/*
buyGrass
giftGrass
quicksort
i -> buyGrass
j - > giftGrass
buyNum++
buyNum++
*/
#include <iostream>

using namespace std;

const int N = 10005;
int buyGrass[N];
int giftGrass[N];

void quickSort(int *arr, int l, int r){
    if(l < r){
        int i = l;
        int j = r;
        int x = arr[l];
        while(i < j){
            while(i < j && arr[j] > x){
                j--;
            }
            if(i < j){
                arr[i] = arr[j];
                i++;
            }
            while(i < j && arr[i] < x){
                i++;
            }
            if(i < j){
                arr[j] = arr[i];
                j--;
            }
        }
        arr[i] = x;
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, r);
    }
}

int main(){
    int buyGrassNum, giftGrassNum, giftNum;
    int i, j;
    cin >> buyGrassNum >> giftGrassNum;
    for(i = 0; i < buyGrassNum; i++){
        cin >> buyGrass[i];
    }
    for(i = 0; i < giftGrassNum; i++){
        cin >> giftGrass[i];
    }
    quickSort(buyGrass, 0, buyGrassNum - 1);
    quickSort(giftGrass, 0, giftGrassNum - 1);
    i = 0;
    j = 0;
    giftNum = 0;
    while(true){
        if(i == buyGrassNum || j == giftGrassNum){
            break;
        }
        if(buyGrass[i] > giftGrass[j]){
            i++;
            j++;
            giftNum++;
            continue;
        }
        i++;

    }
    int num = buyGrassNum + giftNum;
    cout << num;
    
}