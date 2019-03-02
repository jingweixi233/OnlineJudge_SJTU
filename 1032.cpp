#include <iostream>

using namespace std;

int Ackerman(int m, int n){
    if(m == 0){
        return n + 1;
    }
    if(m != 0 && n == 0){
        return Ackerman(m - 1, 1);
    }
    else{
        return Ackerman(m - 1, Ackerman(m, n - 1));
    }
}

int main(){
    int mm, nn;
    cin >> mm >> nn;
    cout << Ackerman(mm, nn);
}