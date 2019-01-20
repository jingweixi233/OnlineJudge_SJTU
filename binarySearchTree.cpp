#include <iostream>

using namespace std;

template<class elemType>
class binarySearchTree
{
private:
    struct node{
        elemType data;
        node *left;
        node *right;
        
        node(const elemType &d, node *ln = NULL, node *rn = NULL):data(d), left(ln), right(rn){}
    };
    
    node *root;
    
    
public:
    binarySearchTree(){
        root = NULL;
    }
    ~binarySearchTree(){
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
        return find(x, root);
    }
    
    elemType *find(const elemType &x, node *t){
        if(t == NULL){
            cout << "Can not find" << endl;
            return 0;
        }
        if(t -> data == x){
            cout << "haha" << endl;
            return &(t -> data);
        }
        if(x < t -> data){
            return find(x, t -> left);
        }
        else{
            return find(x, t -> right);
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
            }
            else{
                if(x == t -> data){
                    cout << "The node has existed" << endl;
                    return;
                }
                else{
                    insert(x, t -> right);
                }
            }
        }
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
        }
        else{
            if(x > t -> data){
                remove(x, t -> right);
            }
            else{   //==
                if(t -> left != NULL && t -> right != NULL){
                    node *tmp = t -> right;
                    while(tmp -> left != NULL){
                        tmp = tmp -> left;
                    }
                    t -> data = tmp -> data;
                    remove(t -> data, t -> right);
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





int main()
{
    binarySearchTree<int> tree;
    tree.insert(50);
    tree.insert(40);
    tree.insert(60);
    tree.insert(45);
    tree.insert(80);
    tree.remove(50);
    tree.midOrder();
}
