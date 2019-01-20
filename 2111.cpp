#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 1e9;


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
    ~bisearchTree(){
        clear(root);
    }
    
    void clear(node *t){
        if(t == NULL){
            return;
        }
        clear(t -> left);
        clear(t -> right);
        delete t;
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
        if(t == NULL){
            return;
        }
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
                            node *p = t;
                            t = NULL;
                            delete p;
                        }
                    }
                }
            }
        }
    }
    void findMin(int a){
        node *p = root;
        int minAll;
        int minn = root -> data;
        int maxx = root -> data;
        /*
        cout <<  "**************" << endl;
        midOrder();
        cout << endl;
        cout <<  "**************" << endl;
        */
        while(p != NULL){
            if(a > p -> data){
                
                minn = p -> data;
                
                p = p -> right;
            }
            else{
                if(a == p -> data){
                    minAll = 0;
                    cout << minAll << '\n';
                    return;
                }
                
                maxx = p -> data;
                
                p = p -> left;
            }
        }
        minAll = Minn(abs(minn - a), abs(maxx - a));
        cout << minAll << '\n';

    }

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
