#include <iostream>

using namespace std;

int main(){
    int check[100] = {0};
    int k = 0;
    int prime[100];
    int i, j;
    for(i = 2; i <= 100; i++){
        if(check[i] == 0){
            prime[k] = i;
            k = k + 1;
        }
        for(j = i + i; j <= 100; j = j + i){
            check[j] = 1;
        }
    }
    for(i = 0; i < k; i++){
        cout << prime[i] <<endl;
    }
}




