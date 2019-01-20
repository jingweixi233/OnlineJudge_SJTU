#include <cstring>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    char str1[105], str2[105];
    char strAdd[105];
    char temp;
    int add = 0, sum, i, max, min, maxStr;
    
    for(i = 0; i < 105; i++){
        str1[i] = '\0';
        str2[i] = '\0';
    }

    cin.getline(str1, 105, '\n');
    cin.getline(str2, 105, '\n');
    for(i = 0; i < strlen(str1) / 2; i++){
        temp = str1[i];
        str1[i] = str1[strlen(str1) - 1 - i];
        str1[strlen(str1) - 1 - i] = temp;
    }
    for(i = 0; i < strlen(str2) / 2; i++){
        temp = str2[i];
        str2[i] = str2[strlen(str2) - 1 - i];
        str2[strlen(str2) - 1 - i] = temp;
    }
    if(strlen(str1) > strlen(str2)){
        maxStr = 1;
        max = strlen(str1);
        min = strlen(str2);
    }
    else{
        maxStr = 2;
        max = strlen(str2);
        min = strlen(str1);
    }
    
    for(i = 0; i < min; i++){
        sum = (int)str1[i] - 97 + (int)str2[i] - 97 + add;
        if(sum > 25){
            add = 1;
            strAdd[i] = (char)(sum - 26 + 97);
        }
        else{
            add = 0;
            strAdd[i] = (char)(sum + 97);
        }
        
    }
    if(maxStr == 1){
        for(i = min; i < max; i++){
            sum = (int)str1[i] - 97 + add;
            if(sum > 25){
                add = 1;
                strAdd[i] = (char)(sum - 26 +97);
            }
            else{
                add = 0;
                strAdd[i] = (char)(sum + 97);
            }
        }
    }
    else{
        for(i = min; i < max; i++){
            sum = (int)str2[i] - 97 + add;
            if(sum > 25){
                add = 1;
                strAdd[i] = (char)(sum - 26 +97);
            }
            else{
                add = 0;
                strAdd[i] = (char)(sum + 97);
            }
        }
    }
    if(add == 1){
        strAdd[max] = 'b';
        strAdd[max + 1] = '\0';
    }
    else{
        strAdd[max] = '\0';
    }

    for(i = 0; i < strlen(strAdd); i++){
        cout << strAdd[strlen(strAdd) - 1 - i];
    }
    
    
}




