#include<iostream>

using namespace std;

int map[6][6];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
long long int minn = 2147483647;
int xStart, yStart, xFinal, yFinal;
int value[6][6] = {{0}};


void dfs(int x, int y, long long int power){
    long long int i, xc, yc, tmp;
    
    if(x == xFinal && y == yFinal){
        if(power <= minn){
            minn = power;
            
        }
        return;
    }
    
    
    for(i = 0; i < 4; i++){
        xc = x + dir[i][0];
        yc = y + dir[i][1];
        if((xc >= 0 && xc < 6) && (yc >= 0 && yc < 6)){
            if(value[xc][yc] == 0){
                tmp = value[x][y] * map[xc][yc];
                power = power + tmp;
                //cout << power << '\n';
                value[xc][yc] = (tmp % 4) + 1;
                dfs(xc, yc, power);
                power = power - tmp;
                value[xc][yc] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int testNum, i, j, k;
    /*
    cout << "***************" << endl;
    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            cout << value[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "****************" << endl;
     */
    cin >> testNum;
    for(k = 0; k < testNum; k++){
        minn = 2147483647;
        
        for(i = 0; i < 6; i++){
            for(j = 0; j < 6; j++){
                value[i][j] = 0;
            }
        }
        
        
        for(i = 0; i < 6; i++){
            for(j = 0; j < 6; j++){
                cin >> map[i][j];
            }
        }
        cin >> xStart >> yStart;
        cin >> xFinal >> yFinal;
        value[xStart][yStart] = 1;
        dfs(xStart, yStart, 0);
        cout << minn << '\n';
    }

}









