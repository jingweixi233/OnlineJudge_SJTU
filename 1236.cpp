#include <iostream>

using namespace std;


const int N = 15;
const int M = 10000;
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
int vis[N] = {0};
int dis[N] = {0};
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int nodeNum, wayNum, start, end;
    int i, j;
    int x, y, wei;
    cin >> nodeNum >> wayNum >> start >> end;
    for(i = 0; i <= nodeNum; i++){
        dis[i] = INF;
    }
    for(i = 0; i < wayNum; i++){
        cin >> x >> y >> wei;
        node *p = list[x];
        node *q = new node(y, wei, NULL);
        q -> next = p;
        list[x] = q;
    }
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

    cout << dis[end];
    
    
}