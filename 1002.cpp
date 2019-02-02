/*
mapRow
mapCol
kelRow
kelCol
x y
N = 1005;
map[N][N]
sum[N][N]

sum[x][y] = map[x][y] + sum[x - 1][y] + sum[x][y - 1] - sum[x - 1][y - 1];

maxx = 0
for(i = kelRow; i <= mapRow; i++){
    for(j = kelCol; j <= mapCol; j++){
        temp = sum[i][j] - sum[i - l][j] - sum[i][j-w] + sum[i-l][j-w];
    }
    if(temp > max){
        maxx = temp;
    }
}
*/
#include <iostream>

using namespace std;

const int N = 1005;

int map[N][N] = {0};
int sum[N][N] = {0};

int main(){
    int i, j;
    int mapRow, mapCol, kelRow, kelCol;
    int maxx = 0, temp = 0;
    cin >> mapRow >> mapCol;

    for(i = 1; i <= mapRow; i++){
        for(j = 1; j <= mapCol; j++){
            cin >> map[i][j];
        }
    }

    cin >> kelRow >> kelCol;

    for(i = 1; i <= mapRow; i++){
        for(j = 1; j <= mapCol; j++){
            sum[i][j] = map[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    for(i = kelRow; i <= mapRow; i++){
        for(j = kelCol; j <= mapCol; j++){
            temp = sum[i][j] - sum[i - kelRow][j] - sum[i][j - kelCol] + sum[i - kelRow][j - kelCol];
            if(temp > maxx){
                maxx = temp;
            }
        }

    }

    cout << maxx;

}



