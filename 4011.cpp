#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>

using namespace std;

const int N = 1005;
int base = 1000000000;
int power = 9;



struct hugeInt{
    long long int a[N];
    int length;
    hugeInt(){
        memset(a, 0, sizeof(a));
        length = 0;
    }
    hugeInt(char *s){
        int i, t, w = 1, numWei;
        length = 0;
        memset(a, 0, sizeof(a));
        int len = strlen(s);
        numWei = 0;
        for(i = len - 1, t = 0; i >= 0; w *= 10, i--){
            if(numWei == power){
                numWei = 0;
                t = t + 1;
                w = 1;
            }
            a[t] = a[t] +( s[i] - '0') * w;
            numWei = numWei + 1;
        }
        
        length = t + 1;
    }
    
    hugeInt(int k){
        int i, t, w = 1, numWei;
        length = 0;
        memset(a, 0, sizeof(a));

        a[0] = k;
        
        length = 1;
    }
    
    void printNum(){
        int i;
        cout << a[length - 1];
        for(i = length - 2; i >= 0; i--){
            cout << setfill('0') << setw(9) << a[i];
        }
    }
};

bool operator > (const hugeInt &p, const hugeInt &q){
    int i;
    if(p.length > q.length){
        return true;
    }
    
    if(p.length < q.length){
        return false;
    }
    
    for(i = p.length - 1; i >= 0; i--){
        if(p.a[i] != q.a[i]){
            return p.a[i] > q.a[i];
        }
    }
    return false;
    
}

hugeInt operator +(const hugeInt &p, const hugeInt &q){
    hugeInt numAdd;
    int i, maxLength;
    if(p.length > q.length){
        maxLength = p.length;
    }
    else{
        maxLength = q.length;
    }
    numAdd.length = maxLength;
    for(i = 0; i < maxLength; i++){
        numAdd.a[i] += p.a[i] + q.a[i];
        numAdd.a[i + 1] += numAdd.a[i] / base;
        numAdd.a[i] = numAdd.a[i] % base;
    }
    if(numAdd.a[numAdd.length]){
        numAdd.length++;
    }
    return numAdd;
    
}


hugeInt operator - ( const hugeInt &p, const hugeInt &q){
    hugeInt numMinus = p;
    int i;
    for(i = 0; i <= numMinus.length - 1; i++){
        numMinus.a[i] = numMinus.a[i] - q.a[i];
        if(numMinus.a[i] < 0){
            numMinus.a[i] = numMinus.a[i] + base;
            numMinus.a[i + 1] = numMinus.a[i + 1] - 1;
        }
    }
    while(numMinus.length > 0 && !numMinus.a[numMinus.length - 1]){
        numMinus.length--;
    }
    return numMinus;
}

hugeInt operator*(const hugeInt &p, const hugeInt &q){
    int i, j;
    hugeInt numMul;
    numMul.length = p.length + q.length - 1;
    for(i = 0; i < p.length; i++){
        for(j = 0; j < q.length; j++){
            numMul.a[i + j] += p.a[i] * q.a[j];
            numMul.a[i + j + 1] += numMul.a[i + j] /base;
            numMul.a[i + j] %= base;
        }
    }
    if(numMul.a[numMul.length]){
        numMul.length ++;
    }
    return numMul;
}


hugeInt kTree[60][60];

int main(){
    int kNum, h, i, j, k;
    cin >> kNum >> h;
   
    for(i = 0; i <= h; i++){
        for(j = 0 ; j <= kNum; j++){
            kTree[i][j] = hugeInt(0);
        }
        
    }
    kTree[1][1] = hugeInt(1);
    kTree[2][kNum] = hugeInt(1);
    for(i = 3; i <= h; i++){
        for(j = 1; j <= kNum; j++){
            for(k = 1; k <= j; k++){
                kTree[i][j] = kTree[i][j] + kTree[i - 1][kNum - k + 1];
            }
        }
    }
    
    hugeInt sum = hugeInt(0);
    for(i = 1; i <= kNum; i++){
        sum = sum + kTree[h][i] * hugeInt(i);
    }
    sum.printNum();

    
}
