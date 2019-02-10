#include <iostream>
#include <cstring>

using namespace std;

const int N = 100005;
char a[N];
char b[N];
int num1[N] = {0};
int num2[N] = {0};
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
    int lenA, lenB, lenSum, i, j, flag = 0;
    cin >> a;
    cin >> b;
    lenA = strlen(a);
    lenB = strlen(b);
    lenSum = maxx(lenA, lenB);
    for(i = 0; i < lenA; i++){
        num1[i] = a[lenA - 1 - i] - '0';
    }
    for(i = 0; i < lenB; i++){
        num2[i] = b[lenB - 1 - i] - '0';
    }

    for(i = 0; i <= lenSum; i++){
        sum[i] = sum[i] + num1[i] + num2[i];
        if(sum[i] >= 10){
            sum[i] = sum[i] % 10;
            sum[i + 1]++;
            if(i == lenSum - 1){
                flag = 1;
            }
        }
    }
    if(flag == 1){
        lenSum++;
    }
    for(i = 0; i < lenSum; i++){
        cout << sum[lenSum - 1 - i];
    }
    
    
}