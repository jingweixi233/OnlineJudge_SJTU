#include <iostream>

using namespace std;

struct Node{
    Node *left, *right, *parent;
    int data;
    
    Node():left(NULL), right(NULL), parent(NULL){}
    Node(int item, Node *L = NULL, Node *R = NULL, Node *P = NULL):data(item), left(L), right(R), parent(P){}
    ~Node(){};
};

Node *nodeArr[1000000] = {NULL};

template<class elemType>
class stack{
public:
    virtual bool isEmpty()const = 0;
    virtual void push(const elemType &x) = 0;
    virtual elemType pop() = 0;
    virtual elemType top()const = 0;
    virtual ~stack(){}
};


template<class elemType>
class linkStack:public stack<elemType>{
private:
    struct node{
        elemType data;
        node *next;
        node(const elemType &x, node *N = NULL){
            data = x;
            next = N;
        }
        node():next(NULL){}
        ~node(){}
    };
    
    node *top_p;
    
public:
    linkStack(){
        top_p = NULL;
    }
    
    ~linkStack(){
        node *tmp;
        while(top_p != NULL){
            tmp = top_p;
            top_p = top_p -> next;
            delete tmp;
        }
    }
    
    bool isEmpty()const{
        return top_p == NULL;
    }
    
    void push(const elemType &x){
        top_p = new node(x, top_p);
        
    }
    
    elemType pop(){
        node *tmp = top_p;
        elemType x;
        x = tmp -> data;
        top_p = top_p -> next;
        delete tmp;
        return x;
    }
    
    elemType top()const{
        return top_p -> data;
    }
};



template<class T>

class bTree{
public:
    virtual void clear() = 0;
    virtual bool isEmpty()const = 0;
    virtual T Root(T flag)const = 0;
    virtual T parent(T x, T flag)const =0;
    virtual T lchild(T x, T flag)const = 0;
    virtual T rchild(T x, T flag)const = 0;
    virtual void delLeft(T x) = 0;
    virtual void delRight(T x) = 0;
    virtual void preOrder() const = 0;
    virtual void midOrder() const = 0;
    virtual void postOrder() const = 0;
    virtual void levelOrder() const = 0;
    
};


template<class T>
class binaryTree:public bTree<T>{
    friend void printTree(const binaryTree &t, T flag);
private:

    
    Node *root;
    
public:
    binaryTree():root(NULL){}
    
    binaryTree(T x){
        root = new Node(x);
    }
    
    ~binaryTree(){
        clear(root);
    }
    
    void clear(Node *t){
        if(t == NULL){
            return;
        }
        clear(t -> left);
        clear(t -> right);
        delete t;
        t = NULL;
    }
    
    void clear(){
        clear(root);
    }
    
    bool isEmpty()const{
        return root == NULL;
    }
    
    T Root(T flag)const{
        if(root == NULL){
            return flag;
        }
        else{
            return root->data;
        }
    }
    
    Node *find(T x, Node *t = NULL)const{
        Node *p = NULL;
        p = nodeArr[x];
        if(p == NULL){
            return NULL;
            
        }
        else{
            return p;
        }
    }
    
    T lparent(T x, T flag)const{
        
    }
    
    T lchild(T x, T flag)const{
        Node *tmp = find(x,  root);
        if(tmp == NULL || tmp -> left == NULL){
            return flag;
        }
        return tmp -> left -> data;
        
    }
    
    T rchild(T x, T flag)const{
        Node *tmp = find(x, root);
        if(tmp == NULL || tmp -> right == NULL){
            return flag;
        }
        return tmp -> right -> data;
    }
    
    
    
    void delLeft(T x){
        Node *tmp = find(x, root);
        if(tmp == NULL){
            return;
        }
        clear(tmp -> left);
        
    }
    
    void delRight(T x){
        Node *tmp = find(x, root);
        if(tmp == NULL){
            return;
        }
        clear(tmp -> right);
    }
    
    void preOrder(Node *t)const{
        if(t == NULL){
            return;
        }
        cout << t -> data << ' ';
        preOrder(t -> left);
        preOrder(t -> right);
    }
    
    void preOrder()const{
        preOrder(root);
    }
    
    void preOrderSta(){
        linkStack<Node *> s;
        
        Node *current = NULL;
        s.push(root);
        while(!s.isEmpty()){
            current = s.pop();
            cout << current -> data << ' ';
            if(current -> right != NULL){
                s.push(current -> right);
                
            }
            if(current -> left != NULL){
                s.push(current -> left);
            }
        }
        
    }
    
    
    void midOrder(Node *t)const{
        if(t == NULL){
            return;
        }
        midOrder(t -> left);
        cout << t -> data << ' ';
        midOrder(t -> right);
    }
    void midOrder()const{
        midOrder(root);
    }
    
    void postOrder(Node *t) const{
        if(t == NULL){
            return;
        }
        postOrder(t -> left);
        postOrder(t -> right);
        cout << t -> data << ' ';
    }
    
    void postOrder()const{
        postOrder(root);
    }
    
    void levelOrder()const{

    }
    
    void creatTree(T flag){

    }
    
    T parent(T x, T flag)const{
        return flag;
    }
    
    void init(){
        root = new Node(1);
        nodeArr[1] = root;
    }
    
    void operation1(int rootNum, int leftNum, int rightNum){
        Node *rootNode = find(rootNum, root);
        if(leftNum == rightNum){
            cout << "Error!" << '\n';
            return;
        }
        if(rootNode == NULL){
            cout << "Error!" << '\n';
            return;
        }
        if(rootNode -> left != NULL || rootNode -> right != NULL){
            cout << "Error!" << '\n';
            return;
        }
        Node *leftNode = find(leftNum, root);
        Node *rightNode = find(rightNum, root);
        if(leftNode != NULL || rightNode != NULL){
            cout << "Error!" << '\n';
            return;
        }
        
        leftNode = new Node(leftNum);
        nodeArr[leftNum] = leftNode;
        rootNode -> left = leftNode;
        leftNode -> parent = rootNode;
        
        rightNode = new Node(rightNum);
        nodeArr[rightNum] = rightNode;
        rootNode -> right = rightNode;
        rightNode -> parent = rootNode;
        cout << "Ok!" << '\n';
    }
    
    void operation2(int nodeNum){
        Node *node = find(nodeNum, root);
        if(node == NULL){
            cout << "Error!" << '\n';
            return;
        }
        else{
            Node *F = node -> parent;
            Node *L = node -> left;
            Node *R = node -> right;
            
            if(F != NULL){
                cout << F -> data << ' ';
            }
            else{
                cout << 0 << ' ';
            }
            
            if(L != NULL){
                cout << L -> data << ' ';
            }
            else{
                cout << 0 << ' ';
            }
            
            if(R != NULL){
                cout << R -> data << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
    
    }
    
    
    void operation3(int nodeNum){
        Node *node = find(nodeNum, root);
        
        if(nodeNum == 1 || node == NULL){
            cout << "Error!" << '\n';
            return;
        }
        else{
            Node *p = node -> parent;
            if(node == p -> left){
                Node *tmp = p -> right;
                cout << tmp -> data << '\n';
                p -> right = node;
                p -> left = tmp;
            }
            else{
                Node *tmp = p -> left;
                cout << tmp -> data << '\n';
                p -> left = node;
                p -> right = tmp;
            }
        }

    }
    
    
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int type, m, i, rootNum = 0, lNum = 0, rNum = 0, Num = 0;
    cin >> m;
    binaryTree<int> aTree;
    aTree.init();
    for(i = 0; i < m; i++){
        cin >> type;
        if(type == 1){
            cin >> rootNum >> lNum >> rNum;
            aTree.operation1(rootNum, lNum, rNum);
        }
        if(type == 2){
            cin >> Num;
            aTree.operation2(Num);
        }
        if(type == 3){
            cin >> Num;
            aTree.operation3(Num);
        }
    }
    aTree.preOrderSta();
                        
}
