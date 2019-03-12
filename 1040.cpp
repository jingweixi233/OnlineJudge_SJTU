#include <iostream>

using namespace std;

const int N = 1000005;
int bTree[4 * N] = {0};
int que[4 * N];
int start = 0, endd = -1, num = 0;

void push(int x){
    endd++;
    que[endd] = x;
    num++;
}

int pop(){
    int ans = que[start];
    start++;
    num--;
    return ans;
}


int main(){
    int i, nodeNum, x;

    cin >> nodeNum;
    for(i = 1; i < nodeNum; i++){
        cin >> x;
        if(bTree[x * 2] == 0){
            bTree[x * 2] = i;
        }
        else{
            bTree[x * 2 + 1] = i;
        }
    }
    
    push(0);
    while(num != 0){
        int node = pop();
        cout << node << ' ';
        if(bTree[2 * node] > 0){
            push(bTree[2 * node]);
        }
        if(bTree[2 * node + 1] > 0){
            push(bTree[node * 2 + 1]);
        }
    }
}
