#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1005;
const int M = 10000;

int a[N][N];
bool visited[N] = {false};

int team[N][N] = {0};

int que[M];
int start = 0, end = -1;
int curSize = 0;
int num = 1;

void push(int x){
    end++;
    que[end] = x;
    curSize++;

}

int pop(){
    int ans = que[start];
    start++;
    curSize--;
    return ans;
}

void bfs(){
    int i , k;
    push(0);
    visited[0] = true;
    while(curSize != 0){
        int stu = pop();
        for(k = 1; k <= team[stu][0]; k++){

            int teamid = team[stu][k];
            if(teamid == 0){
                continue;
            }
            for(i = 1; i <= a[teamid][0]; i++){
                if(visited[a[teamid][i]]== false){
                    visited[a[teamid][i]] = true;
                    push(a[teamid][i]);
                    num++;
                }
            }
        }

    }
}



int main()
{
    freopen("song.in", "r", stdin);
    freopen("song.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, i, j;
    int stuNum, teamNum;
    cin >> t;
    cin >> stuNum >> teamNum;
    for(i = 1; i <= teamNum; i++){
        cin >> a[i][0];
        for(j = 1; j <= a[i][0]; j++){
            cin >> a[i][j];
            team[a[i][j]][0]++;
            int s = team[a[i][j]][0];
            team[a[i][j]][s] = i;
        }

    }

    bfs();
    cout << num;

    cout << flush;
    fclose(stdin);
    fclose(stdout);

}
