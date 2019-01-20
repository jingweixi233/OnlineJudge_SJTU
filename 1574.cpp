#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;


long long int expMod(long long int n, long long int m){
    long long int exp, A;
    exp = 1;
    A = 10 % m;
    while(n > 0){
        if(n % 2 != 0){
            exp = (exp * A) % m;
        }
        A = (A * A) % m;
        n = n / 2;
    }
    return exp;
}

int main(){
    long long int n, m, x, k, i, num;
    cin >> n;
    cin >> m;
    cin >> k;
    cin >> x;
    num = expMod(k, n);
    if(num == 0){
        cout << x << endl;
    }
    else{
        for(i = 0; i < num; i++){
            if(x < n - m){
                x = x + m;
            }
            else{
                x = x - (n - m);
            }
        }
        cout << x << endl;
    }
}


