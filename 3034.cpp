#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int prime(long long int num){
    int j;
    if(num == 2){
        return 1;
    }
    else{
        for (j = 2; j <= sqrt(num); j = j + 1) {
            if (num % j == 0){
                return 0;
            }
        }
        return 1;
    }
}
int main(){
    long long int num, num1, num2, gap;
    cin >> num;
    if(prime(num) == 1){
        cout << 0 << endl;
    }
    else{
        num1 = num + 1;
        num2 = num - 1;
        while(true){
            if(prime(num1) == 1){
                break;
            }
            else{
                num1 = num1 + 1;
            }
        }
        while(true){
            if(prime(num2) == 1){
                break;
            }
            else{
                num2 = num2 - 1;
            }
        }
        gap = num1 - num2;
        cout << gap << endl;
    }

}
