#include <iostream>

using namespace std;

struct node{
    int id;
    node *next;

    node(int ii = 0, node *n = NULL){
        id = ii;
        next = n;
    }
};

const int N = 15;
int M;
int path = 0;
node* eNode[N] = {NULL};
bool visited[N] = {false};

void dfs(int start, int dist){
    if(dist == M){
        path++;
        return;  
    }
    
    node *p = eNode[start];
    visited[start] = true;

    while(p != NULL){
        if(visited[p -> id] == false){
            dfs(p -> id, dist + 1);
        }
        p = p -> next;
    }
    visited[start] = false;

}

int main(){
    int nodeNum, lineNum, startNode;
    int i, x, y;
    node *p, *q;
    cin >> nodeNum >> lineNum >> startNode >> M;
    for(i = 0; i < lineNum; i++){
        cin >> x >> y;
        p = new node(y);
        p -> next = eNode[x];
        eNode[x] = p;
    }
    dfs(startNode, 0);
    cout << path;

    for(i = 0; i < N; i++){
        p = eNode[i];
        while(p != NULL){
            q = p;
            p = p -> next;
            delete q;
        }
    }
}