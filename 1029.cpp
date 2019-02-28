/*
num[N][N]
num[i][0] = bookNum;
int id;
for(){
    cin >> x >> y;
    for(){
    }
}
*/
#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;
int num[N][N] = {0};
int shell[N][N] = {0};
char str[1005];

int main(){
    int i, j, x, y;
    int line;
    int ans;
    cin >> line;
    cin.ignore();

    for(i = 1; i <= line; i++){
        shell[i][0] = 1;
        shell[i][1] = i;
    }

    for(i = 1; i <= line; i++){
        
        for(j = 0; j < 1005; j++){
            str[i] = '\0';
        }
        
        cin.getline(str, 1005);
        int len = strlen(str);
        int s = 0;
        int sum = 0;
        int k = 1;
        for(j = 0; j < len; j++){
            if(str[j] >= '0' && str[j] <= '9'){
                sum = sum * k + (str[j] - '0');
                k = 10;
            }
            else{
                s++;
                num[i][s] = sum;
                sum = 0;
                k = 1;
            }
        }
        s++;
        num[i][s] = sum;
        num[i][0] = s;
    }
    line--;
    for(i = 0; i < line; i++){
        cin >> x >> y;
        ans = y;
        int books = shell[y][0];
        for(j = 1; j <= shell[x][0]; j++){
            shell[y][books + j] = shell[x][j];
        }
        shell[y][0] = shell[y][0] + shell[x][0];
        shell[x][0] = 0;
    }

    line++;
    
    for(i = 1; i <= line; i++){
        for(j = 1; j <= num[shell[ans][i]][0]; j++){
            cout << num[shell[ans][i]][j] << ' ';
        }
    }
}
