#include <iostream>

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

    void findMin(int a){
        node *p = root;
        int minAll;
        int minn = 0;
        int maxx = MAX;
        /*
        cout <<  "**************" << endl;
        midOrder();
        cout << endl;
        cout <<  "**************" << endl;
        */
        while(p != NULL){
            if(a > p -> data){
                if(p -> data > minn){
                    minn = p -> data;
                }
                p = p -> right;
            }
            else{
                if(a == p -> data){
                    minAll = 0;
                    cout << minAll << '\n';
                    return;
                }
                if(p -> data < maxx){
                    maxx = p -> data;
                }
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
    binarySearchTree<int> tree;
    for(i = 0;  i< M; i++){
        cin >> type >> optNum;
        if(type == 0){
            tree.findMin(optNum);
        }
        if(type == 1){
            tree.insert(optNum);
        }
        if(type == 2){
            tree.remove(optNum);
        }
    }

}