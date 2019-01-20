/*
N = 100005;
long long mouAdd[N];
long long mouHigh[N];
quickSort  mouAdd;
mouTui = 1;
mouQian = 
for(i = 1; i < n){ 
    if{
        zuo
    }
    else{
        if(you)
        else
        butui
    }
}
*/
#include <iostream>

using namespace std;

const int N = 100005;
long long int mouAdd[N];
long long int mouHigh[N];

void quickSort(int l, int r){
    long long int i = l;
    long long int j = r;
    long long int x = mouAdd[l];
    long long int y = mouHigh[l];
    if(l < r){
        while(i < j){
            while(i < j && mouAdd[j] > x){
                j--;
            }
            if(i < j){
                mouAdd[i] = mouAdd[j];
                mouHigh[i] = mouHigh[j];
                i++;
            }
            while(i < j && mouAdd[i] < x){
                i++;
            }
            if(i < j){
                mouAdd[j] = mouAdd[i];
                mouHigh[j] = mouHigh[i];
                j--;
            }
        }
        mouAdd[i] = x;
        mouHigh[i] = y;
        quickSort(l, i - 1);
        quickSort(i + 1, r);
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int mouNum, mouTui, i;
    long long int mouQian;
    cin >> mouNum;
    for(i = 0; i < mouNum; i++){
        cin >> mouAdd[i];
    }
    for(i = 0; i < mouNum; i++){
        cin >> mouHigh[i];
    }

    quickSort(0, mouNum - 1);
    if(mouNum <= 2){
        cout << mouNum;
        return 0;
    }
    mouTui = 2;
    mouQian = mouAdd[0];
    for(i = 1; i < mouNum - 1; i++){
        if(mouQian < mouAdd[i] - mouHigh[i]){
            mouQian = mouAdd[i];
            mouTui++;
        }
        else{
            if(mouAdd[i + 1] > mouAdd[i] + mouHigh[i]){
                mouQian = mouAdd[i] + mouHigh[i];
                mouTui++;
            }
            else{
                mouQian = mouAdd[i];
            }
        }
    }  
    cout << mouTui;
}



















