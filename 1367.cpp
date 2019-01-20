/*
a[N]
b[N];
node data left right
tmp[35]

cal(){
    
    tmp = []
    swap;
}

insert(node *t, int index, int num){
    if()
}

dfs(node *t, int index, )
*/

#include <iostream>

using namespace std;

const int N = 30005;
int a[N], b[N];
int tmp[35];

struct node{
    int data;
    node *left;
    node *right;
    node(int d = -1){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void calEr(int num){
    int i, p = 0, tempNum;

    for(i = 0; i < 35; i++){
        tmp[i] = 0;
    }
    while(num){
        tmp[p] = num % 2;
        num = num / 2;
        p++;
    }
    
    for(i = 0; i < 15; i++){
        tempNum = tmp[i];
        tmp[i] = tmp[30 - i];
        tmp[30 - i] = tempNum;
    }
}

void insert(node *&t, int index, int num){
    if(index + 1 == 31){
        t = new node(num);
        return;
    }
    if(t == NULL){
        t = new node;
    }
    if(tmp[index + 1] == 1){
        insert(t -> right, index + 1, num);
    }
    else{
        insert(t -> left, index + 1, num);
    }
}

int dfs(node *&t, int index){
    if(index + 1 == 31){
        return t -> data;
    }

    if(tmp[index + 1] == 0){
        if(t -> right){
            return dfs(t -> right, index + 1);
        }
        else{
            return dfs(t -> left, index + 1);
        }
    }
    else{
        if(t -> left){
            return dfs(t -> left, index + 1);
        }
        else{
            return dfs(t -> right, index + 1);
        }
    }
}

int main(){
    int i, aLen, bLen, maxx = 0;
    cin >> aLen >> bLen;
    for(i = 0; i < aLen; i++){
        cin >> a[i];
    }
    for(i = 0;  i < bLen; i++){
        cin >> b[i];
    }
    node *root = new node;
    
    for(i = 0; i < bLen; i++){
        calEr(b[i]);
        insert(root, -1, b[i]);
    }

    for(i = 0; i < aLen; i++){
        calEr(a[i]);
        int numNi = dfs(root, -1);
        if((a[i]^numNi) > maxx){
            maxx = (a[i]^numNi);
        }
    }
    cout << maxx;
}

