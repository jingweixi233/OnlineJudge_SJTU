/*
const int N = 100005;
node{
    int id;
    node *next;
}
que[N]
node *adjList[N];
inDu[N];
int curSize;

int main(){
    make adjList;
    inDu 0 deq;
    bfs();
}
*/

#include <iostream>

using namespace std;

const int N = 100005;
struct node{
    int id;
    node *next;
    node(int i = 0){
        id = i;
        next = NULL;
    }
};

int que[N];
node *adjList[N] = {NULL};
int inDu[N] = {0};
int curSize = 0;
int start = 0, endd = -1;
int keTime[N];

void push(int x){
    endd++;
    que[endd] = x;
    curSize++;
}

int pop(){
    int ans = que[start];
    start++;
    curSize--;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int keNum, m;
    int i, j;
    int x, y;
    int du0;
    cin >> keNum >> m;
    if(m == 0){
        cout << 1;
        return 0;
    }
    for(i = 0; i < m; i++){
        cin >> x >> y;
        node *p = new node(y);
        p -> next = adjList[x];
        adjList[x] = p;
        inDu[y]++;
    }

    for(i = 1; i <= keNum; i++){
        if(inDu[i] == 0){
            push(i);
            keTime[i] = 1;  
        }
    }
    
    while(curSize != 0){
        int ke = pop();
        node *q = adjList[ke];
        while(q != NULL){
            int keid = q -> id;
            //cout << keid << endl;
            inDu[keid]--;
            if(inDu[keid] == 0){
                push(keid);
                keTime[keid] = keTime[ke] + 1;
            }
            q = q -> next;
        }
    }
    int max = 0;
    for(i = 1; i <= keNum; i++){
        //cout << keTime[i] << endl;
        if(keTime[i] > max){
            max = keTime[i];
        }
    }
    cout << max;
    
    
}