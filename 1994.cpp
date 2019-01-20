#include <iostream>

using namespace std;

const int N = 505;


int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int map[N][N];
int mapLen, mapRow;

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
        arr = new point[10000];

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

    void del(){
        pHead = 0;
        pTail = -1;
    }

    ~que(){
        delete []arr;
    }
  
};

void bfs(){
    int i, j, p, q, k;
    int answer = 0;
    que bfsQue;
    for(i = 1; i <= mapRow; i++){
        for(j = 1; j <= mapLen; j++){
            if(map[i][j] == 0){
                bfsQue.push(point(i, j));
                map[i][j] = 1;
                while(bfsQue.empty() != true){
                    point p = bfsQue.pop();
                    for(k = 0; k < 4; k++){
                        int xNow = p.x + dir[k][0];
                        int yNow = p.y + dir[k][1];
                        if(map[xNow][yNow] == 0 && xNow >= 1 && xNow <= mapRow && yNow >= 1 && yNow <= mapLen){
                            bfsQue.push(point(xNow, yNow));
                            map[xNow][yNow] = 1;
                        }
                    }
                    
                }
                bfsQue.del();
                answer++;

            }
            
        }
    }
    cout << answer;
}




int main(){
    int i, j;
    cin >> mapRow >> mapLen;
    for(i = 1; i <= mapRow; i++){
        for(j = 1; j <= mapLen; j++){
            cin >> map[i][j];
        }
    }
    bfs();
    return 0;
}