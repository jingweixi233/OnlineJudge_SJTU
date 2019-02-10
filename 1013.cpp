/*
volumn[N]
value[N]
sum[N]
for(i = 0; i < ; i++){
    for(j = volumn[i]; j < ; j++){
        sum[j] = max(sum[j], sum[j - volumn[i]] + value[i]);
    }
}
*/
#include <iostream>

using namespace std;

const int N = 1005;
int volumn[N];
int value[N];
int sum[10005];

int maxx(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}
int main(){
    int i, j;
    int bagVol, boxNum;
    cin >> bagVol >> boxNum;
    for(i = 0; i < boxNum; i++){
        cin >> volumn[i];
        cin >> value[i];
    }

    for(i = 0; i < boxNum; i++){
        for(j = volumn[i]; j <= bagVol; j++){
            sum[j] = max(sum[j], sum[j - volumn[i]] + value[i]);
        }
    }

    cout << sum[bagVol];


}