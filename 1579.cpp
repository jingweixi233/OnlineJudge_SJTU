#include <iostream>

using namespace std;

const int N = 1005;
char x[N];
char y[N];
int zi[N][N];

int maxx(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}
int main(){
    int n, m, i, j;
    cin >> n >> m;
    cin >> x;
    cin >> y;
    for(i = 0; i <= n; i++){
        for(j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                zi[i][j] = 0;
                continue;
            }
            if(i > 0 && j > 0 && x[i - 1] == y[j - 1]){
                zi[i][j] = zi[i - 1][j - 1] + 1;
            }
            else{
                zi[i][j] = max(zi[i][j - 1], zi[i - 1][j]);
            }
            
        }
    }
    cout << zi[n][m];
}
