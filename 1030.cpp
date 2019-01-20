/*
map[105][105]
timeInvade[][];

struct point
x y

queue
point arr[];
int pHead, ptail;
push
pop

bfs(){
    queue.push(Point xy);
    while(!queue.empty()){
        p = queue.pop;
        
        for(x){
            fot(y){
                xNow yNow
                if(== '.' && x> < y > < ){
                    map[x][y] = '*';
                    timeInvade[] = time[p. x] + 1
                }
            }
        }
    }
    for(i j){
        min
    }
}

int main(){
    cin >>
    bfs;
}
*/

#include <iostream>

using namespace std;

const int N = 10005;
const int mapSize = 105;
char map[mapSize][mapSize];
int timeInvade[mapSize][mapSize];
int mapLen, mapRow, mx, my;

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
    map[mx][my] = '*';
    timeInvade[mx][my] = 0;
    while(bfsQue.empty() != true){
        point p = bfsQue.pop();
        for(x = -1; x <= 1; x++){
            for(y = -1; y <= 1; y++){
                int xNow = p.x + x;
                int yNow = p.y + y;
                if(map[xNow][yNow] == '.' && xNow >= 1 && xNow <= mapLen && yNow >= 1 && yNow <= mapLen){
                    bfsQue.push(point(xNow, yNow));
                    map[xNow][yNow] = '*';
                    timeInvade[xNow][yNow] = timeInvade[p.x][p.y] + 1;
                }
            }
        }
    }
    for(i = 1; i <= mapRow; i++){
        for(j = 1; j <= mapLen; j++){
            if(timeInvade[i][j] > maxx){
                maxx = timeInvade[i][j];
            }
        }
    }
    cout << maxx;
    
}

int main(){
    int i, j;
    cin >> mapLen >> mapRow >> mx >> my;
    for(i = 1; i <= mapRow; i++){
        for(j = 1; j <= mapLen; j++){
            cin >> map[i][j];
        }
    }
    bfs();
    return 0;
}
