
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n, i, j, x, y, k = 1, ii, jj;
    int **map;
    
    cin >> n;
    cin >> ii;
    cin >> jj;
    map = new int *[n + 2];
    for(i = 0; i < n + 2; i++){
        map[i] = new int[n + 2];
    }
    
    for(i = 0; i < n + 2; i++){
        for(j = 0; j < n + 2; j++){
            map[i][j] = 0;
        }
    }
    x = 1;
    y = 1;
    while(k <= n * n){
        map[x][y] = k;
        if(x == ii && y == jj){
            break;
        }
        if((x == 1 || map[x - 1][y] != 0) && (map[x][y + 1] == 0 ) && y < n){
            y = y + 1;
        }
        else{
            if((y == n || map[x][y + 1] != 0) && map[x + 1][y] == 0 && x < n){
                x = x + 1;
            }
            else{
                if((x == n || map[x + 1][y] != 0) && (map[x][y - 1] == 0) && y > 1){
                    y = y - 1;
                }
                else{
                    if((y == 1 || map[x][y - 1] != 0) && (map[x - 1][y] == 0) && x > 1){
                        x = x - 1;
                    }
                }
                
            }
        }
        
        k = k + 1;
    }
    cout << k - 1 << endl;
    for(i = 0; i < n+2; i++){
        delete []map[i];
        
    }
    delete []map;
    
    
}
