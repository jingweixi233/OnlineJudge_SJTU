#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int M, i;
    long long int kn, k, kn_i;
    cin >> M;
    const int length = M;
    int monkey[length];
    long long int k_call[length - 1];
    for(i = 0; i < M; i++){
        monkey[i] = i + 1;
    }
    for(i = 0; i < M - 1; i++){
        cin >> k_call[i];
    }
    
    k = 0;
    kn_i = 1;
    kn = 0;
    for(i = 0; i < M - 1; i++){
        while(true){
            if(k == M){
                k = 0;
                continue;
            }
            if(monkey[k] == 0){
                k = k + 1;
                continue;
            }
            if(kn_i == k_call[kn]){
                monkey[k] = 0;
                break;
            }
            k = k + 1;
            kn_i = kn_i + 1;
        }
        kn = kn + 1;
        k = k + 1;
        kn_i = 1;
    }
    for(i = 0; i < length; i++){
        if(monkey[i] != 0){
            cout << monkey[i] << '\n';
        }
    }
}


