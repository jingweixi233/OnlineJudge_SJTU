/*
node{
    int id;
    node *parent;
    node *left;
    node *right;
}
nodeList []
int root;
for{
    cin >> p, l, bro;
    if(l != 0){
        node[p] -> left = node[l];
        node[l] -> parent = node[p];
    }

    if(bro != 0){
        node[p] -> parent -> right = node[bro];
        node[bro] -> parent = node[p] -> parent;
    }

    if(node[p] -> parent == NULL){
        root = p;
    }
}
*/

#include <iostream>

using namespace std;

const int N = 12349;

struct node{
    int id;
    node *parent;
    node *left;
    node *right;

    node(){
        id = 0;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

node *nodeList[N];
node *que[N];
int root, start = 0, endd = -1, num = 0;

void push(node *x){
    endd++;
    que[endd] = x;
    num++;
}

node *pop(){
    node *ans = que[start];
    start++;
    num--;
    return ans;
}


void preOrder(node *t){
    if(t == NULL){
        return;
    }
    cout << t -> id << ' ';
    preOrder(t -> left);
    preOrder(t -> right);
}


void preOrder(){
    preOrder(nodeList[root]);
}


void postOrder(node *t){
    if(t == NULL){
        return;
    }
    postOrder(t -> left);
    cout << t -> id  << ' ';
    postOrder(t -> right);

}

void postOrder(){
    postOrder(nodeList[root]);
}

void levelOrder(){
    push(nodeList[root]);
    while(num != 0){
        node *p = pop();
        cout << p -> id << ' ';
        if(p -> left){
            p = p -> left;
            push(p);
            while(p -> right){
                p = p -> right;
                push(p);
            }
        }
    }
}



int main(){
    int i, nodeNum;
    int p, l, r;
   
    cin >> nodeNum;

    for(i = 0; i <= nodeNum; i++){
        nodeList[i] = new node();
        nodeList[i] -> id = i;
    }

    for(i = 0; i < nodeNum; i++){
        cin >> p >> l >> r;
        if(l != 0){
            nodeList[p] -> left = nodeList[l];
            nodeList[l] -> parent = nodeList[p];
        }

        if(r != 0){
            nodeList[p] -> right = nodeList[r];
            nodeList[r] -> parent = nodeList[p];
        }

        if(nodeList[p] -> parent == NULL){
            root = p;
        }
    }

    preOrder();
    cout << endl;
    postOrder();
    cout << endl;
    levelOrder();
}

