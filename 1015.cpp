#include <iostream>
#include <cstring>

using namespace std;

const int N = 1005;
char a[N];
char b[N];
int num1[2 * N] = {0};
int num2[2 * N] = {0};
int sum[2 * N] = {0};

int maxx(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}
int main(){
    int lenA, lenB, lenSum = 0, i, j, flag = 0;
    cin >> a;
    cin >> b;
    lenA = strlen(a);
    lenB = strlen(b);
    for(i = 0; i < lenA; i++){
        num1[i] = a[lenA - 1 - i] - '0';
    }
    for(i = 0; i < lenB; i++){
        num2[i] = b[lenB - 1 - i] - '0';
    }

    int len = lenA + lenB;
    for(i = 0; i < lenA; i++){
        int s = 0;
        for(j = 0; j < lenB; j++){
            sum[i + j] += num1[i] * num2[j] + s;
            s = sum[i + j] / 10;
            sum[i + j] %= 10;
        }
        sum[i + lenB] = s;
    }

    while(sum[len - 1] == 0 && (len != 1)) {
        len--;
    }

    for(i = 0; i < len; i++){
        cout << sum[len - 1 - i];
    }

}