#include <iostream>

using namespace std;


const int N = 20005;
const int M = 100000;
const int INF = 1e9;

struct node{
    int id;
    int w;
    node *next;
    node(int i, int ww, node *n = NULL){
        id = i;
        w = ww; 
        next = n;
    }
};

node* list[N];

int que[M];
int st = 0, ed = -1;
int curSize = 0;

int dis1[N] = {0};
int dis2[N] = {0};
int dis3[N] = {0};
void push(int x){
    ed++;
    que[ed] = x;
    curSize++;
}

int pop(){
    int ans = que[st];
    st++;
    curSize--;
    return ans;
}

void spfa(int *dis, int start){
    int vis[N] = {0};
    int i;
    st = 0, ed = -1;
    curSize = 0;
    push(start);
    vis[start] = 1;
    dis[start] = 0;
    while(curSize!= 0){
        int tmp = pop();
        node *p = list[tmp];
        vis[tmp] = 0;
        while(p != NULL){
            if(dis[tmp] + p -> w < dis[p -> id]){
                dis[p -> id] = dis[tmp] + p -> w;
                if(vis[p -> id] == 0){
                    vis[p -> id] = 1;
                    push(p -> id);
                }
            }
            p = p -> next;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int nodeNum, wayNum, start, end;
    int i, j;
    int x, y, wei;
    int st1, st2, st3;
    cin >> nodeNum >> st1 >> st2 >> st3;
    for(i = 0; i <= nodeNum; i++){
        dis1[i] = INF;
        dis2[i] = INF;
        dis3[i] = INF;
    }
    wayNum = nodeNum - 1;
    for(i = 0; i < wayNum; i++){
        cin >> x >> y >> wei;
        node *p = list[x];
        node *q = new node(y, wei, NULL);
        q -> next = p;
        list[x] = q;
        
        p = list[y];
        q = new node(x, wei, NULL);
        q -> next = p;
        list[y] = q;


    }

    spfa(dis1, st1);
    spfa(dis2, st2);
    spfa(dis3, st3);
    long int room, sum = INF;
    for(i = 1; i <= nodeNum; i++){
        if(dis1[i] + dis2[i] + dis3[i] < sum){
            sum = dis1[i] + dis2[i] + dis3[i];
            room = i;
        }
    }
    cout << room << '\n';
    cout << sum << '\n';
}