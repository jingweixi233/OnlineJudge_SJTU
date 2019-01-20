#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int i, j, l, flag = 1, k;
    cin >> l;
    const int length = l;
    int map[length][length];
    for(i = 0; i < length; i++){
        for(j = 0; j < length; j++){
            cin >> map[i][j];
        }
    }
    k = 0;
    while(true){
        flag = 1;
        for(i = 0; i < length; i++){
            for(j = 0; j < length; j++){
                if(map[i][j] == 1){
                    if(i - 1 >= 0 && i <= length - 1 && j >= 0 && j <= length - 1 && map[i - 1][j] == 0){
                        map[i - 1][j] = -1;
                        flag = 0;
                    }
                    if(i >= 0 && i + 1 <= length - 1 && j >= 0 && j <= length - 1 && map[i + 1][j] == 0){
                        map[i + 1][j] = -1;
                        flag = 0;
                    }
                    if(i >= 0 && i <= length - 1 && j - 1 >= 0 && j <= length - 1 && map[i][j - 1] == 0){
                        map[i][j - 1] = -1;
                        flag = 0;
                    }
                    if(i >= 0 && i <= length - 1 && j >= 0 && j + 1 <= length - 1 && map[i][j + 1] == 0){
                        map[i][j + 1] = -1;
                        flag = 0;
                    }
                }
            }
        }
        
        for(i = 0; i < length; i++){
            for(j = 0; j < length; j++){
                if( map[i][j] == -1){
                    map[i][j] = 1;
                }
            }
        }
        k = k + 1;
        if(flag == 1){
            break;
        }
    }
    cout << k - 1 << endl;
}


