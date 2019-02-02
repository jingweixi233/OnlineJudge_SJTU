/*
num1[205]
num2[205]
sum[205]
traverse
jia
for(){
    sum[] = sum[] + num1[] + num2[] 
    if(sum[] > 10){
        sum[] = sum % 10;
        sum[+1] += 1;
    }
}
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 205;
char num1[N] = {0};
char num2[N] = {0};
int sum[N] = {0};

int maxx(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    int len1, len2, len1Half, len2Half;
    int i;
    cin >> num1;
    cin >> num2;
    len1 = strlen(num1);
    len2 = strlen(num2);
    len1Half = len1 / 2;
    len2Half = len2 / 2;
    for(i = 0; i < len1Half; i++){
        char temp = num1[i];
        num1[i] = num1[len1 - 1 - i];
        num1[len1 - 1 - i] = temp;

    }
    for(i = 0; i < len2Half; i++){
        char temp = num2[i];
        num2[i] = num2[len2 - 1 - i];
        num2[len2 - 1 - i] = temp;
    }
    int lenSum = maxx(len1, len2);
    sum[2] = -1;
    for(i = 0; i < lenSum; i++){
        if(i == 2){
            continue;
        }
        sum[i] = sum[i] + (num1[i] - '0') + (num2[i] - '0');
        if(sum[i] >= 10){
            sum[i] = sum[i] % 10;
            if(i == 1){
                sum[i + 2] = sum[i + 2] + 1;
            }
            else{
                sum[i + 1] = sum[i + 1] + 1;
            }
        }
    }
    
    if(sum[lenSum] == 1){
        lenSum = lenSum + 1;
    }
    for(i = 0; i < lenSum / 2; i++){
        char temp = sum[i];
        sum[i] = sum[lenSum - 1 - i];
        sum[lenSum - 1 - i] = temp;
    }

    for(i = 0; i < lenSum; i++){
        if(sum[i] == -1){
            cout << '.';
        }
        else{
            cout << sum[i];
        }
    }
    
}