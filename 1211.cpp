#include <iostream>

using namespace std;

template<class elemType>
class queue {
public:
    virtual bool isEmpty() = 0;
    virtual void enQueue(const elemType &x) = 0;
    virtual elemType deQueue() = 0;
    virtual elemType getHead() = 0;
    virtual ~queue(){};
};

template<class elemType>
class linkQueue: public queue<elemType>
{
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
    
    node *front , *rear;
    
public:
    linkQueue(){
        front = rear = NULL;
        
    }
    ~linkQueue(){
        node *tmp;
        while(front != NULL){
            tmp = front;
            front = front -> next;
            delete tmp;
        }
    }
    bool isEmpty(){
        return front == NULL;
    }
    
    void enQueue(const elemType &x){
        if(rear == NULL){
            front = rear = new node(x);
        }
        else{
            rear -> next = new node(x);
            rear = rear -> next;
        }
    }
    
    elemType deQueue(){
        node *tmp = front;
        elemType value = front -> data;
        front = front -> next;
        if(front == NULL){
            rear = NULL;
        }
        delete tmp;
        return value;
    }
    
    elemType getHead()
    {
        return front-> data;
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
    struct Node{
        Node *left, *right, *parent;
        T data, leftNum, rightNum;
        
        Node():left(NULL), right(NULL), parent(NULL){}
        Node(T item, Node *L = NULL, Node *R = NULL):data(item), left(L), right(R){}
        ~Node(){};
    };
    
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
    
    Node *find(T x, Node *t)const{
        Node *tmp;
        if(t == NULL){
            return t;
            
        }
        if(t -> data == x){
            return t;
        }
        if(tmp == find(x, t -> left)){
            return tmp;
        }
        else{
            return (find(x, t -> right));
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
        linkQueue<Node *>que;
        Node *tmp;
        
        que.enQueue(root);
        while(!que.isEmpty()){
            tmp = que.deQueue();
            cout << tmp -> data << ' ';
            if(tmp -> left){
                que.enQueue(tmp -> left);
                
            }
            if(tmp -> right){
                que.enQueue(tmp -> right);
            }
            
        }
        
    }
    
    void creatTree(T flag){
        linkQueue<Node *>que;
        Node *tmp;
        T x, ldata, rdata;
        cin >> x;
        root = new Node(x);
        que.enQueue(root);
        
        while(!que.isEmpty()){
            tmp = que.deQueue();
            cin >> ldata >> rdata;
            if(!ldata != flag){
                que.enQueue(tmp -> left == new Node(ldata));
            }
            if(!rdata != flag){
                que.enQueue(tmp -> left == new Node(rdata));
            }
        }
        
    }
    
    T parent(T x, T flag)const{
        return flag;
    }
    
    
    void isCBT(){
        int i, N, lCh, rCh;
        cin >> N;
        Node* treeNode[100005];
        for(i = 1; i <= N; i++){
            cin >> lCh;
            cin >> rCh;
            Node *tmp = new Node;
            tmp -> leftNum = lCh;
            tmp -> rightNum = rCh;
            treeNode[i] = tmp;

            
        }
        for(i = 1; i <= N; i++){
            Node *tmp = treeNode[i];

            if(tmp -> leftNum != 0){
                tmp -> left = treeNode[tmp -> leftNum];
                treeNode[tmp -> leftNum] -> parent = tmp;
            }
            if(tmp -> rightNum != 0){
                tmp -> right = treeNode[tmp -> rightNum];
                treeNode[tmp -> rightNum] -> parent = tmp;
            }
        }
        
        for(i = 1; i <= N; i++){
            if(treeNode[i] -> parent == NULL){
                root = treeNode[i];
                break;
            }
        }
        
        linkQueue<Node *> que;
        int lastId = 1, nodeCount = 1;
        root -> data = 1;
        Node *tmpNode, *son;
        if(root == NULL){
            cout << 'Y';
            return;
        }
        
        que.enQueue(root);
        while(!que.isEmpty()){
            tmpNode = que.deQueue();
            if(tmpNode -> left != NULL){
                nodeCount = nodeCount + 1;
                son = tmpNode -> left;
                son -> data = (tmpNode -> data) * 2;
                lastId = son -> data;
                que.enQueue(son);
                
            }
            if(tmpNode -> right != NULL){
                nodeCount = nodeCount + 1;
                son = tmpNode -> right;
                son -> data = (tmpNode -> data) * 2 + 1;
                lastId = son -> data;
                que.enQueue(son);
                
            }
        }
        if(nodeCount == lastId){
            cout << 'Y';
        }
        else{
            cout << 'N';
        }
        
    }
    
};



int main(){
    binaryTree<int> aTree;
    aTree.isCBT();
    cout << aTree.find()
}

