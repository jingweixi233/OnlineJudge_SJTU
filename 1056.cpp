/*
dui box
bool sugarExist
int sugerBox
int sugar
C px = findP(x),py find(y)
if(sugarExist[])
sugar[]
*/
#include <iostream>

using namespace std;

const int N = 500005;

struct node{
    int size;
    int num;
    node *next;

    node(int s = 1, int nu = 1, node *n = NULL){
        size = s;
        num = nu;
        next = n;
    }
};

int sugar[N];


node *head;

int findP(int x){
    int r = x;
    while(sugar[r] > 0){
        r = sugar[r];
    }
    return r;
}

void reset(int minus1, int minus2, int add){
    node *p = head;
    while(p -> next -> size != minus1){
        p = p -> next;
    }
    (p -> next ->  num)--;
    if(p -> next -> num == 0){
        node *q = p -> next;
        p -> next = q -> next;
        delete q;
    }

    p = head;
    while(p -> next -> size != minus2){
        p = p -> next;
    }
    (p -> next ->  num)--;
    if(p -> next -> num == 0){
        node *q = p -> next;
        p -> next = q -> next;
        delete q;
    }

    p = head;
    while(add < p -> next -> size){
        p = p -> next;
    }
    if(add == p -> next -> size){
        (p -> next -> num)++;
    }
    else{
        node *q = new node(add, 1);
        q -> next = p -> next;
        p -> next = q;
    }
}

void del(int s){
    node *p = head;
    while(p -> next -> size != s){
        p = p -> next;
    }
    (p -> next ->  num)--;
    if(p -> next -> num == 0){
        node *q = p -> next;
        p -> next = q -> next;
        delete q;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sugarNum, oprNum;
    char oprType;
    int x, y;
    int i, j;
    cin >> sugarNum >> oprNum;
    head = new node;
    
    for(i = 1; i <= sugarNum; i++){
        sugar[i] = -1;
    }
    node *p = new node;
    p -> size = 1;
    p -> num = sugarNum;
    head -> next = p;

    for(i = 0; i < oprNum; i++){
        cin >> oprType;
        if(oprType == 'C'){
            cin >> x >> y;
            int px = findP(x);
            int py = findP(y);
            if(px == py || sugar[px] == 0 || sugar[py] == 0){
                continue;
            }
            int minusSize1 = -sugar[px];
            int minusSize2 = -sugar[py];
            sugar[py] = sugar[py] + sugar[px];
            sugar[px] = py;
            int addSize = -sugar[py];
            reset(minusSize1, minusSize2, addSize);

        
        }
        if(oprType == 'D'){
            cin >> x;
            int px = findP(x);
            if(sugar[px] == 0){
                continue;
            }
            int ps = -sugar[px];
            sugar[px] = 0;
            del(ps);
        }

        if(oprType == 'Q'){
            cin >> x;
            node *p = head -> next;
            while(true){
                if(x <= p -> num){
                    cout << p -> size << '\n';
                    break;
                }
                
                x = x - p -> num;
                p = p -> next;
            }

        }
        
    }

    p = head -> next;
    node *q;
    while(p != NULL){
        q = p;
        p = p -> next;
        delete q;
    }

}
