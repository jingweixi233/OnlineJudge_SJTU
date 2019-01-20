#include <stdio.h>
#include <iostream>

using namespace std;

bool isvalid(int listNum[9]){
    int i, j, tmp;
    int l[9];
    for(i = 0; i < 9; i++){
        l[i] = listNum[i];
    }
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9 - i - 1; j++){
            if(l[j] > l[j + 1]){
                tmp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = tmp;
            }
        }
    }
    for(i = 0; i < 9; i++){
        if(l[i] != i + 1){
            return false;
        }
    }
    return true;
}

int main(){
    int sodokuNum, i, j, k, filter_i, filter_j, f, flag;
    cin >> sodokuNum;
    int sodoku[9][9], filter[9];
    int col[9];
    
    for(k = 0; k < sodokuNum; k++){
        flag = 1;
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                cin >> sodoku[i][j];
            }
        }
        for(i = 0; i < 9; i++){
            if(isvalid(sodoku[i]) == false){
                flag = 0;
                break;
            }

        }
        if(flag == 0){
            cout << "Wrong" << endl;
            continue;
        }
        
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                col[j] = sodoku[j][i];
            }
            if(isvalid(col) == false){
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            cout << "Wrong" << endl;
            continue;
        }
        
        for(i =0; i < 3; i++){
            for(j = 0; j < 3; j++){
                f = 0;
                for(filter_i = 3 * i; filter_i < 3 * i + 3; filter_i ++){
                    for(filter_j = 3 * j; filter_j < 3 * j + 3; filter_j++){
                        filter[f] = sodoku[filter_i][filter_j];
                        f = f + 1;
                    }
                }
                if(isvalid(filter) == false){
                    flag = 0;
                    break;
                }
            }
            if(flag == 0){
                break;
            }
        }
        if(flag == 0){
            cout << "Wrong" << endl;
        }
        if(flag == 1){
            cout << "Right" << endl;
        }
    }
}


