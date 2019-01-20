#include <iostream>

using namespace std;


const int N = 10005;
const int mapSize = 105;
char map[mapSize][mapSize];
int way[mapSize][mapSize];
int mapLen, mapRow, mx, my, aimx, aimy;
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

struct point{
    int x, y;
    point(int xx = 0, int yy = 0){
        x = xx;
        y = yy;
    }
};

class que{
    public:
    point *arr;
    int pHead, pTail;

    que(){
        arr = new point[N];

        pHead = 0;
        pTail = -1;
    }
    
    void push(point obj){
        pTail++;
        arr[pTail] = obj;
    }
    point pop(){
        int p = pHead;
        pHead++;
        return arr[p];
    }

    bool empty(){
        if(pHead > pTail){
            return true;
        }
        else{
            return false;
        }
    }

    ~que(){
        delete []arr;
    }
  
};

void bfs(){
    int x, y, i ,j;
    int maxx = 0;
    que bfsQue;
    bfsQue.push(point(mx, my));
    way[mx][my] = 0;
    while(bfsQue.empty() != true){
        point p = bfsQue.pop();
        if(map[p.x][p.y] == '.'){
            for(i = 0; i < 4; i++){
                int xNow = p.x + dir[i][0];
                int yNow = p.y + dir[i][1];
                if(dir[i][0] == 0){
                    if(way[xNow][yNow] == -1 && map[xNow][yNow] != '*' && map[xNow][yNow] != '|' && xNow >= 1 && xNow <= mapRow && yNow >= 1 && yNow <= mapLen){
                        bfsQue.push(point(xNow, yNow));
                        way[xNow][yNow] = way[p.x][p.y] + 1;
                    }
                }
                else{
                    if(way[xNow][yNow] == -1 && map[xNow][yNow] != '*' && map[xNow][yNow] != '-' && xNow >= 1 && xNow <= mapRow && yNow >= 1 && yNow <= mapLen){
                        bfsQue.push(point(xNow, yNow));
                        way[xNow][yNow] = way[p.x][p.y] + 1;
                    }
                }

            }

        }

        if(map[p.x][p.y] == '|'){
            for(i = -1; i <= 1; i += 2){
                int xNow = p.x + i;
                int yNow = p.y;
                if(way[xNow][yNow] == -1 && map[xNow][yNow] != '*' && map[xNow][yNow] != '-' && xNow >= 1 && xNow <= mapRow && yNow >= 1 && yNow <= mapLen){
                    bfsQue.push(point(xNow, yNow));
                    way[xNow][yNow] = way[p.x][p.y] + 1;
                }
            }
        }

        if(map[p.x][p.y] == '-'){
            for(i = -1; i <= 1; i += 2){
                int xNow = p.x;
                int yNow = p.y + i;
                if(way[xNow][yNow] == -1 && map[xNow][yNow] != '*' && map[xNow][yNow] != '|' && xNow >= 1 && xNow <= mapRow && yNow >= 1 && yNow <= mapLen){
                    bfsQue.push(point(xNow, yNow));
                    way[xNow][yNow] = way[p.x][p.y] + 1;
                }
            }
        }
    }

    int answer = way[aimx][aimy];
    
    cout << answer;
    
}

int main(){
    int i, j;
    cin >> mapRow >> mapLen;
    cin >> mx >> my >> aimx >> aimy;
    for(i = 1; i <= mapRow; i++){
        for(j = 1; j <= mapLen; j++){
            cin >> map[i][j];
        }
    }

    for(i = 1; i <= mapRow; i++){
        for(j = 1; j <= mapLen; j++){
            way[i][j] = -1;
        }
    }


    bfs();

    return 0;
}
