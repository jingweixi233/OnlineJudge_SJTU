#include<iostream>

using namespace std;




int main(){
    int M, i, k, result;
    cin >> M;
    const int length = M;
    long long int k_call[length - 1];
    for(i = 0; i < M - 1; i++){
        cin >> k_call[i];
    }

    int f[M+1];
    f[0] = f[1] = 0;        //f[0]其实用不到的
    k = M - 2;
    for(unsigned i = 2; i <= M; i++){
        f[i] = (f[i-1] + k_call[k]) % i;
        k = k - 1;
    }
    
    result = f[M];

    cout << result + 1 << endl;
}
