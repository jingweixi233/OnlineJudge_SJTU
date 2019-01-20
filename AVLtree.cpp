#include <iostream>

using namespace std;

template <class elemType>
class AvlTree{
private:
    
    struct node{
        elemType data;
        node *left;
        node *right;
        int height;
        
        node(const elemType &x, node *ln, node *rn, int h = 1):data(x), left(ln), right(rn), height(h){}
    };
    
    node *root;
    
public:
    
    AvlTree(){
        root = NULL;
    }

    ~AvlTree(){
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
    
    elemType *find(const elemType &x){
        node *t = root;
        while(t != NULL && t -> data != x){
            if(t -> data > x){
                t = t -> right;
            }
            else{
                t = t -> left;
            }
        }
        
        if(t == NULL){
            return NULL;
        }
        else{
            return &(t -> data);
        }
    }
    
    void insert(const elemType &x){
        insert(x, root);
    }
    
    void insert(const elemType &x, node *&t){
        if(t == NULL){
            t = new node(x, NULL, NULL);
        }
        else{
            if(x < t -> data){
                insert(x, t -> left);
                if(high(t -> left) - high(t -> right) == 2){
                    if(x < t -> left -> data){
                        LL(t);
                    }
                    else{
                        LR(t);
                    }
                }
            }
            else{
                if(x == t -> data){
                    cout << "The node has existed" << endl;
                    return;
                }
                else{
                    insert(x, t -> right);
                    if(high(t -> right) - high(t -> left) == 2){
                        if(x > t -> right -> data){
                            RR(t);
                        }
                        else{
                            RL(t);
                        }
                    }
                }
            }
        }
        t -> height = max(high(t -> left), high(t -> right)) + 1;
    }
    
    void remove(const elemType &x){
        remove(x, root);
    }
    
    void remove(const elemType &x, node *&t){
        if(t == NULL){
            return;
        }
        if(x < t -> data){
            remove(x, t -> left);
            if(high(t -> right) - high(t -> left) == 2 ){
                if(t -> right -> left != NULL && high(t -> right -> left) > high(t -> right -> right)){
                    RL(t);
                }
                else{
                    RR(t);
                }
            }
        }
        else{
            if(x > t -> data){
                remove(x, t -> right);
                if(high(t -> left) - high(t -> right) == 2 ){
                    if(t -> left -> right != NULL && high(t -> left -> right) > high(t -> left -> left)){
                        LR(t);
                    }
                    else{
                        LL(t);
                    }
                }
                
            }
            else{   //==
                if(t -> left != NULL && t -> right != NULL){
                    node *tmp = t -> right;
                    while(tmp -> left != NULL){
                        tmp = tmp -> left;
                    }
                    t -> data = tmp -> data;
                    remove(t -> data, t -> right);
                    if(high(t -> left) - high(t -> right) == 2 ){
                        if(t -> left -> right != NULL && high(t -> left -> right) > high(t -> left -> left)){
                            LR(t);
                        }
                        else{
                            LL(t);
                        }
                    }
                }
                else{
                    node *old = t;
                    if(t -> left == NULL && t -> right == NULL){
                        delete old;
                    }
                    else{
                        if(t -> left!= NULL){
                            t = t -> left;
                        }
                        else{
                            t = t -> right;
                        }
                        delete old;
                    }
                }
            }
        }
        t -> height = max(high(t -> left), high(t -> right)) + 1;
    }
    
    int high(node *t){
        if(t == NULL){
            return 0;
        }
        else{
            return t -> height;
        }
    }
    
    void LL(node *t){
        node *t1 = t -> left;
        t -> left = t1 -> right;
        t1 -> right = t;
        t -> height = max(high(t -> left), high(t -> right)) + 1;
        t1 -> height = max(high(t1 -> left), high(t1 -> right)) + 1;
        t = t1;
    }
    
    void LR(node *t){
        RR(t -> left);
        LL(t);
    }
    
    void RR(node *t){
        node *t1 = t -> right;
        t -> right = t1 -> left;
        t1 -> left = t;
        t -> height = max(high(t -> left), high(t -> right)) + 1;
        t1 -> height = max(high(t1 -> left), high(t1 -> right)) + 1;
        t = t1;
        
    }
    
    void RL(node *t){
        LL(t -> right);
        RR(t);
    }
    
    int max(int a, int b){
        if(a > b){
            return a;
        }
        else{
            return b;
        }
    }
    
    void midOrder(){
        midOrder(root);
    }
    void midOrder(node *p){
        if(p == NULL){
            return;
        }
        midOrder(p -> left);
        cout << p -> data << ' ';
        midOrder(p -> right);
    }

    
};

int main(){
    AvlTree<int> tree;
    tree.insert(50);
    tree.insert(40);
    tree.insert(60);
    tree.insert(45);
    tree.insert(80);
    tree.remove(50);
    tree.midOrder();
}
