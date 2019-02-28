/*
struct point(){
    int x, y;
}
map[][]
visited[][]
maxx, minn;
high = maxx - minn
low = 0;
mid = low + high / 2
while(low <= high){
    for(i = minn; i <= maxx - mid; i++){
        if(bfs){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    mid = low + high / 2
}

bfs(int l, int h){
    que.push();
    while(num != 0){
        que.pop();
        for(4 * dir){
            if(meet request){
                if(destination){
                    return true
                }
                push
                1
            }
        }
    }
}
*/
#include <iostream>

using namespace std;

struct point{
    int x, y;
    point(int xx = 0, int yy = 0){
        x = xx;
        y = yy;
    }
};

const int N = 105;
int map[N][N];

int len;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

point que[10005];
int sta = 0, endd = -1, num = 0;

void push(int px, int py){
    endd++;
    que[endd].x = px;
    que[endd].y = py;
    num++;
}

point pop(){
    point ans = que[sta];
    sta++;
    num--;
    return ans;
}

bool bfs(int l, int h){
    num = 0;
    endd = -1;
    sta = 0;
    int visited[N][N] = {0};
    if(map[1][1] < l || map[1][1] > h || map[len][len] < l || map[len][len] > h){
        return false;
    }
    visited[1][1] = 1;
    push(1, 1);
    while(num != 0){
        int i;
        point p = pop();

        for(i = 0; i < 4; i++){
            int xx = p.x + dir[i][0];
            int yy = p.y + dir[i][1];
            if(xx >= 1 && xx <= len && yy >= 1 && yy <= len && map[xx][yy] >= l && map[xx][yy] <= h && visited[xx][yy] == 0){
                if(xx == len && yy == len){
                    return true;
                }
                visited[xx][yy] = 1;
                push(xx, yy);
            }
        }
    }
    return false;
}

int main(){
    int i, j, maxx = 0, minn = 205;
    int high, low, mid;
    cin >> len;
    for(i = 1; i <= len; i++){
        for(j = 1; j <= len; j++){
            cin >> map[i][j];
            if(map[i][j] > maxx){
                maxx = map[i][j];
            }
            if(map[i][j] < minn){
                minn = map[i][j];
            }
        }
    }
    high = maxx - minn;
    low = 0;
    mid = (low + high) / 2;
    while(low < high){
        int flag = 0;
        for(i = minn; i <= maxx - mid; i++){
            if(bfs(i, i + mid)){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            high = mid;
        }
        else{
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }    

    cout << high;

}












