#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    long long int N, i, oldNum = 0, newNum = 0, Num = 0, sqrtNum;
    int flag = 0;
    cin >> N;
    cout << N << "=";
    for(i = 2; i <= N; i++){
        if(N % i == 0){
            if(flag == 0){
                Num = i;
                cout << Num;
                flag = 1;
            }
            if(i != Num){
                cout << "(" << newNum -oldNum << ")";
                cout << i;
                oldNum = newNum;
                Num = i;
            }
            N = N / i;
            i = i - 1;
            newNum = newNum + 1;
            if(N == 1){
                cout << "(" << newNum -oldNum << ")";
                break;
            }
        }
    }
}
