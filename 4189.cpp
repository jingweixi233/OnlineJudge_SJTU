/*
N = 100005;
struct node
int parent 
next *
int size;
int id;

parent ++;
*/

#include <iostream>

using namespace std;

const int N = 100005;

struct node{
    int parent;
    int size;
    int id;
    node *next;
    node(int p = -1, int s = 1, int i = 0, node *n = NULL){
        parent  = p;
        size = s;
        id = i;
        next = n;
    }
};

node nodeList[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int townNum, i;
    int pId, sonId;
    cin >> townNum;
    for(i = 0; i < townNum - 1; i++){
        cin >> pId >> sonId;
        nodeList[sonId].parent = pId;
        int p = pId;
        while(p != -1){
            nodeList[p].size++;
            p = nodeList[p].parent;
        }

        node *tmp;
        tmp = &nodeList[pId];
        while(tmp -> next != NULL){
            tmp = tmp -> next;
        }
        node *q;
        q = new node(-1, 1, sonId, NULL);
        tmp -> next = q;
    }


    int val = townNum/2;
    for(i = 1; i <= townNum; i++){
        int flag = 1;
        node *p = nodeList[i].next;
        while(p != NULL){
            if(nodeList[p -> id].size > val){
                flag = 0;
                break;
            }
            p = p-> next;
        }
        if(flag == 0){
            continue;
        }
        int pNum = nodeList[i].parent;
        int rootNum = i;
        while(pNum != -1){
            rootNum = pNum;
            pNum = nodeList[pNum].parent;
        }
        
        int pNodeNum = nodeList[rootNum].size - nodeList[i].size;
        if(pNodeNum <= val && flag == 1){
            cout << i << '\n';
        }  
    }
    node *p, *q;
    for(i = 1; i <= townNum; i++){
        p = nodeList[i].next;
        while(p != NULL){
            q = p;
            p = p -> next;
            delete q;
        }
    }
}


