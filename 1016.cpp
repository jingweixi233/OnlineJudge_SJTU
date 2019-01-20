#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

char A[350] = {'\0'}, B[350] = {'\0'};

int lenA = 0, lenB = 0;

int res[350] = {0};

bool isGreater(){
    return strncmp(A, B, lenB) >= 0;
}

void sub(){
    int i, start = 0;
    while(A[start] == '0'){
        start = start + 1;
    }
    for(i = start; i < lenB; i++){
        A[i] = A[i] - B[i] + '0';
    }
    for(i = lenB - 1; i > 0; i--){
        if(A[i] < '0'){
            A[i] = A[i] + 10;
            A[i - 1] = A[i - 1] - 1;
        }
    }
}


int main(){
    
    int i, res_i, j;
    bool flag;
    cin.getline(A, 350, '\n');
    cin.getline(B, 350, '\n');
    if((int)B[0] - 48 == 0){
        return 0;
    }
    lenA = strlen(A);
    lenB = strlen(B);
    if((lenA < lenB) || ((lenA == lenB)&&!isGreater())){
        cout << 0 << endl;
        return 0;
    }
    
    res_i = 0;
    while(true){
        while(isGreater()){
            sub();
            res[res_i] = res[res_i] + 1;
        }
        res_i = res_i + 1;
        
        if(lenA == lenB){
            break;
        }
        
        for(j = lenB; j > 0; j--){
            B[j] = B[j -1];
        }
        lenB = lenB + 1;
        B[j] = '0';
        
    }
    
    flag = true;
    for(i = 0; i < res_i; i++){
        if(flag && (res[i] != 0)){
            flag = false;
        }
        if(res[i] == 0){
            if(!flag){
                cout << 0;
            }
        }
        else{
            cout << res[i];
        }
        
    }
    cout << endl;
    return 0;
}
