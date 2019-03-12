/*
bTree[]
node[]

for(N){
    father, x, y
    bTree[node[father] * 2] = x;
    node[x] = node[father] * 2;
    bTree[node[father] * 2 + 1] = y;
    node[y] = node[father] * 2 + 1;
}
cout
backOrder(int id){
    if(bTree[id] == 0){
        return;
    }
    backOrder(id * 2);
    backOrder(id * 2 + 1);
    cout << bTree[id];    
}
*/

#include <iostream>

using namespace std;

const int N = 30005 * 4;
int bTree[N] = {0};
int node[N] = {0};

void backOrder(int id){
    if(bTree[id] == 0){
        return;
    }
    backOrder(id * 2);
    backOrder(id * 2 + 1);
    cout << bTree[id] << ' ';
}

int main(){
    int i, nodeNum;
    int parent, x, y;

    cin >> nodeNum;
    for(i = 0; i < nodeNum; i++){
        cin >> parent >> x >> y;
        if(i == 0){
            bTree[1] = parent;
            node[parent] = 1;
        }
        if(x != -1){
            bTree[node[parent] * 2] = x;
            node[x] = node[parent] * 2;
        }
        if(y != -1){
            bTree[node[parent] * 2 + 1] = y;
            node[y] = node[parent] * 2 + 1;
        }
    }

    for(i = 1; i <= nodeNum; i++){
        cout << node[i] << ' ';
    }
    cout << endl;
    backOrder(1);
}