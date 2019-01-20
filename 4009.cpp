#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    
    int i, j, a, length, partNum, k, flag;
    char plaintext[100];
    char ciphetext[100];
    char trans[50][100];
    
    for(i = 0; i < 100; i++){
        plaintext[i] = '\0';
        ciphetext[i] = '\0';
    }
    cin.getline(plaintext, 100, '\n');
    cin.getline(ciphetext, 100, '\n');
    length = strlen(plaintext);
    for(a = 2; a <= length; a++){
        flag = 1;
        if(length % a == 0){
             partNum = length / a;
        }
        else{
            continue;
        }
        for(i = 0; i < a; i++){
            for(j = 0; j < partNum; j++){
                trans[i][j] = plaintext[j * a + i];
            }
        }
        k = 0;
        for(i = 0; i < a; i++){
            for(j = 0; j < partNum; j++){
                if(trans[i][j] != ciphetext[k]){
                    flag = 0;
                    break;
                }
                k = k + 1;
            }
            if(flag == 0){
                break;
            }
        }
        if(flag == 0){
            continue;
        }
        else{
            cout << a << endl;
            return 0;
        }
        
    }
    cout << "No Solution" << endl;
}
