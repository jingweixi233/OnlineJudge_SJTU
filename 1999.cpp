/*
const int N = 105
map[N][N]
int visit[N][N]
boxNum;
minWay;
point(){
    
}
bfs()
{
    push
    while(!= 0){
        chu
        4
        if(no visit ){
            push
            vist[] = 
            if(box){
                boxVi++;
            }
        }
    }
}
*/
#include <iostream>

using namespace std;

const int N = 105;
struct point{
    int x, y;
    point(int xx = 0, int yy = 0){
        x = xx;
        y = yy;
    }
};
int map[N][N];
int visit[N][N];
point que[100000];
int curSize = 0;
int st = 0, ed = -1;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int  list[6];
int  way[5 * 4 * 3 * 2 * 1][6];
point pointSt[7];
int dis[7][7];
int n = 0;
int row, col;

void swap(int *a ,int *b)
{
	int m ;
	m = *a;
	*a = *b;
	*b = m;
} 
 
void perm(int list[],int k, int m )
{
	int i;
	if(k > m)
	{
		for(i = 0 ; i <= m ; i++)
		{
			way[n][i] = list[i];
			 
		}
		n++;
	}
	else
	{
		for(i = k ; i <=m;i++)
		{
			swap(&list[k],&list[i]);
			perm(list,k+1,m);
			swap(&list[k],&list[i]);
		}
	}
}


void push(point x){
    ed++;
    que[ed] = x;
    curSize++;
}

point pop(){
    point ans = que[st];
    st++;
    curSize--;
    return ans;
}

int bfs(point a, point b){
    int i, j, k;
    for(i = 1; i <= row; i++){
        for(j = 1; j <= col; j++){
            visit[i][j] = -1;
        }
    }
    curSize = 0;
    st = 0;
    ed = -1;
    push(a);
    visit[a.x][a.y] = 0;
    while(curSize != 0){
        point temp = pop();
        for(k = 0; k < 4; k++){
            int xx = temp.x + dir[k][0];
            int yy = temp.y + dir[k][1];
            if(visit[xx][yy] == -1 && map[xx][yy] != -1 && xx >= 1 && xx <= row && yy >= 1 && yy <= col){
                push(point(xx, yy));
                visit[xx][yy] = visit[temp.x][temp.y] + 1;
                if(xx == b.x && yy == b.y){

                    return visit[xx][yy];
                    
                }
            }
        }
    }
    return -1;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int boxNum = 0;
    int minWay = 1000000;
    int boxVi = 0;
    cin >> row >> col;

    
    for(i = 1; i <= row; i++){
        for(j = 1; j <= col; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                pointSt[0] = point(i, j);
            }
            if(map[i][j] == 1){
                boxNum++;
                pointSt[boxNum] = point(i, j);
            }  
        }
    }
    for(i = 0; i < boxNum; i++){
        list[i] = i + 1;
    }
    perm(list, 0, boxNum - 1);
    
    for(i = 0; i <= boxNum; i++){
        for(j = i + 1; j <= boxNum; j++){
            dis[i][j] = bfs(pointSt[i], pointSt[j]);
            dis[j][i] = dis[i][j];
            if(dis[i][j] == -1){
                cout << -1;
                return 0;
            }
        }
    }

    
    int sum = 0;
    for(i = 0; i < n; i++){
        sum = 0;

        sum = sum + dis[0][way[i][0]];
        //cout << dis[0][way[i][0]] << endl;
        //cout << sum << endl;
        //cout << "way[i][0]" << way[i][0] << endl;
        for(j = 0; j < boxNum - 1; j++){
            sum = sum + dis[way[i][j]][way[i][j + 1]];
        }
        //cout << sum << endl;
        if(sum < minWay){
            minWay = sum;
        }

        
    }
    cout << minWay;
    


}