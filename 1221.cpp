/*
bisearchTree{
    node{
        int data
        left
        right
    }

    insert(int x){
        if(NULL){
            new
        }
        if(x > ){
            inwert(right)
        }
        else{
            insert(left)
        }
    }

    erase(int x){
        if(x > ){
            erase right
        }
        else{
            if<
            erase left
            else{=
                if(NULL NULL){
                    shan
                }
                if(feiNULL feiNULL){
                    youzuixiao
                    tihuan
                    shan you zui xiao
                }
                else{
                    zuo NULL you feiNULL t = t -> left
                    
                }
            }
        }

    }
    

    find optMin(){
        paixu
        erfen cha zhao
    } 
}
*/
#include <iostream>
#include <cmath>

using namespace std;

const int N = 100005;
int arr[N];
int k = 0;
int bSearch(int *a, int num, int len){
    int l = 0;
    int r = len - 1;
    int mid = (l + r) / 2;
    while(l <= r){
        if(a[mid] <= num){
            if(a[mid] == num){
                return mid;
            }
            else{
                l = mid + 1;
            }
        }
        else{
            r = mid - 1;
        }
        mid = (l + r) / 2;
    }
    return r;
}


int Minn(int a, int b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }

}

class bisearchTree{
public:
    struct node{
        int data;
        node *left;
        node *right;
        node(int d = 0){
            data = d;
            left = NULL;
            right = NULL;
        }
    };
    
    node *root;
    int nodeNum;
    bisearchTree(){
        root = NULL;
        nodeNum = 0;
    }
    
    void insert(int x){
        insert(root, x);
        nodeNum++;
    }
    void insert(node *&t, int x){
        if(t == NULL){
            t = new node(x);
        }
        else{
            if(x > t -> data){
                insert(t -> right, x);
            }
            else{  
                insert(t -> left, x);
            }
        }
    }

    void erase(int x){
        erase(root, x);
        nodeNum--;
    }
    void erase(node *&t, int x){
        if(x > t -> data){
            erase(t -> right, x);
        }
        else{
            if(x < t -> data){
                erase(t -> left, x);
            }
            else{
                if(t -> right != NULL && t -> left != NULL){
                    node *tmp = t -> right;
                    while(tmp -> left != NULL){
                        tmp = tmp -> left;
                    }
                    t -> data = tmp -> data;
                    erase(t -> right, t -> data);
                }
                else{
                    if(t -> left != NULL && t -> right == NULL){
                        node *p = t;
                        t = t -> left;
                        delete p;
                    }
                    else{
                        if(t -> right != NULL && t -> left == NULL){
                            node *p = t;
                            t = t -> right;
                            delete p;
                        }
                        else{
                            delete t;
                        }
                    }
                }
            }
        }
    }
    void findMin(int a){
        int minn;
        midOrder();
        
        int id = bSearch(arr, a, nodeNum);
        if(id == -1){
            minn = abs(arr[0] - a);
        }
        if(id == nodeNum - 1){
           minn = abs(arr[id] - a);
        }
        else{
            minn = Minn(abs(arr[id] - a), abs(arr[id + 1] - a));
        }
        cout << minn << '\n';
    }

    void midOrder(){
        k = 0;
        midOrder(root);
    }
    void midOrder(node *t){
        if(t == NULL){
            return;
        }
        midOrder(t -> left);
        arr[k] = t -> data;
        k++;
        midOrder(t -> right);
    }
};

int main(){
    int M, i;
    int type, optNum;
    
    cin >> M;
    bisearchTree tree;
    for(i = 0;  i< M; i++){
        cin >> type >> optNum;
        if(type == 0){
            tree.findMin(optNum);
        }
        if(type == 1){
            tree.insert(optNum);
        }
        if(type == 2){
            tree.erase(optNum);
        }
    }

}
