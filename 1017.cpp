#include <iostream>

using namespace std;

long long int numMon[4] = {1, 0, 0, 0};

int main(){
    int a, b, c, i, month;
    long int sum = 0;
    cin >> a >> b >> c >> month;
    for(i = 0; i < month; i++){
        numMon[3] = numMon[3] + numMon[2];
        numMon[2] = numMon[1];
        numMon[1] = numMon[0];
        numMon[0] = numMon[1] * a + numMon[2] * b + numMon[3] * c;
    }
    for(i = 0; i < 4; i++){
        sum += numMon[i];
    }
    cout << sum;
}