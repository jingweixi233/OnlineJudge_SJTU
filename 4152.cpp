#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>

using namespace std;

const int N = 1005;
int base = 1000000000;
int power = 9;
char n[N];

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


hugeInt divideTwo(const hugeInt &p){
    char num2[3] = {'2'};
    hugeInt x;
    long long int i, r = 0;
    x.length = p.length;
    if(hugeInt(num2) > p){
        return p;
    }
    for(i = p.length - 1; i >= 0; i --){
        r = r * base + p.a[i];
        x.a[i] = r >> 1;
        r %= 2;
        
    }
    while(x.length > 1 && !x.a[x.length - 1]){
        x.length --;
    }
    return x;
}






int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char num1[3] = {'1'};
    char num2[3] = {'2'};
    
    
    cin >> n;
    
    hugeInt s, ziFen, muFen, nn(n), l, r, numOne(num1), numTwo(num2);
    l = hugeInt(num1);
    r = nn;

    if(nn.length == 1 && nn.a[0] == 1){
        cout << '1' << '/' << '1';
        return 0;
    }
    int flag = 0;
    s = divideTwo(l + r);
    
    
    while(true){

        
        if((s + numOne)*s > numTwo * nn   ){
            r = s - numOne;
        }
        else{
            if(!(numTwo * nn > (s + numOne) * (s + numTwo)) &&( numTwo * nn > (s + numOne)*s)){
                break;
            }
            else{
                l = s + numOne;
            }
        }
        s = divideTwo(l + r);
    }
    if(s.a[0] % 2 == 1){
        ziFen = nn - divideTwo((s + numOne )*s);
        muFen = s + numOne - (nn - divideTwo((s + numOne )*s)) + numOne;
        ziFen.printNum();
        cout << '/' ;
        muFen.printNum();
    }
    else{
        ziFen =s + numOne - (nn - divideTwo((s + numOne )*s)) + numOne;
        muFen = nn - divideTwo((s + numOne )*s);
        ziFen.printNum();
        cout << '/' ;
        muFen.printNum();
    }
}






