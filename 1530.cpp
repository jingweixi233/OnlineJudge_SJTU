//class linkQueue and binaryTree is copied from textbook
#include <iostream>
#include <cmath>

using namespace std;

const int N = 10000000;
char pre[N];
char trees[N];
int logs[1000005];
struct Node{
    Node *left, *right, *parent;
    int data;
    
    Node():left(NULL), right(NULL), parent(NULL){}
    Node(int item, Node *L = NULL, Node *R = NULL, Node *P = NULL):data(item), left(L), right(R), parent(P){}
    ~Node(){};
};

struct stNode{
    Node *node;
    int times;
    stNode(Node *N = NULL):node(N), times(0){}
};

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
    struct Node{
        Node *left, *right;
        T data;
        
        Node():left(NULL), right(NULL){}
        Node(T item, Node *L = NULL, Node *R = NULL):data(item), left(L), right(R){}
        ~Node(){};
    };
    
    struct stNode{
        Node *node;
        int times;
        stNode(Node *N = NULL):node(N), times(0){}
    };
    
    Node *root;
public:
    binaryTree():root(NULL){}
    
    binaryTree(T x){
        root = new Node(x);
    }
    
    ~binaryTree(){
       
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
        if(root == NULL){
            return;
        }
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
        Node *tmp = NULL;
        if(t == NULL){
            return t;
            
        }
        if(t -> data == x){
            return t;
        }
        tmp = find(x, t -> left);
        if(tmp){
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
        cout << t -> data;
        preOrder(t -> left);
        preOrder(t -> right);
    }
    void preOrder()const{
        preOrder(root);
        cout << '\n';
    }
    
    void preOrderSta(){
        linkStack<Node *> s;
        
        Node *current = NULL;
        s.push(root);
        while(!s.isEmpty()){
            current = s.pop();
            cout << current -> data;
            if(current -> right != NULL){
                s.push(current -> right);
                
            }
            if(current -> left != NULL){
                s.push(current -> left);
            }
        }
        cout << '\n';
    }
    
    void midOrder(Node *t)const{
        if(t == NULL){
            return;
        }
        midOrder(t -> left);
        cout << t -> data;
        midOrder(t -> right);
    }
    void midOrder()const{
        midOrder(root);
        cout << '\n';
    }
    
    void midOrderSta(){
        linkStack<stNode> s;
        
        stNode current(root);
        s.push(current);
        while(!s.isEmpty()){
            current = s.pop();
            if(++current.times == 2){
                cout << current.node -> data;
                if(current.node -> right != NULL){
                    s.push(stNode(current.node -> right));
                    
                }
            }
            else{
                s.push(current);
                if(current.node -> left != NULL){
                    s.push(stNode(current.node -> left));
                }
            }
        }
        cout << '\n';
    }
    
    
    void postOrder(Node *t) const{
        if(t == NULL){
            return;
        }
        postOrder(t -> left);
        postOrder(t -> right);
        cout << t -> data;
    }
    
    void postOrder()const{
        postOrder(root);
        cout << '\n';
    }
    
    
    void postOrderSta(){
        linkStack<stNode> s;
        
        stNode current(root);
        s.push(current);
        while(!s.isEmpty()){
            current = s.pop();
            if(++current.times == 3){
                cout << current.node -> data;
                continue;
            }
            s.push(current);
            if(current.times == 1){
                if(current.node -> left != NULL){
                    s.push(stNode(current.node -> left));
                }
            }
            else{
                if(current.node -> right != NULL){
                    s.push(stNode(current.node -> right));
                }
            }
        }
        cout << '\n';
        
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
        int k = 1;
        linkQueue<Node *>que;
        Node *tmp = NULL;
        T x, ldata, rdata;
        x = pre[0];
        root = new Node(x);
        que.enQueue(root);
        
        while(!que.isEmpty()){
            tmp = que.deQueue();
            tmp -> left = NULL;
            tmp -> right = NULL;
            ldata = pre[k];
            k = k + 1;
            if(ldata == '\0'){
                break;
            }
            if(ldata != flag){
                que.enQueue(tmp -> left = new Node(ldata));
            }
            rdata = pre[k];
            k = k + 1;
            if(rdata == '\0'){
                break;
            }

            if(rdata != flag){
                que.enQueue(tmp -> right = new Node(rdata));
            }

        }
        
    }
    
    T parent(T x, T flag)const{
        return flag;
    }
};

void preBuildTree(char node, int id, int pStart, int pEnd){
    int index, levelNum, lastNum, nn;
    if(pStart >= pEnd){
        trees[id] = node;
        return;
    }
    else{
        trees[id] = node;
        levelNum = (int)(log(pEnd - pStart + 1) / log(2)) + 1;
        nn = 1 << (levelNum - 2) ;
        lastNum = (pEnd - pStart) - (nn - 1) * 2;
        if(lastNum > nn){
            index = nn - 1 + nn;
        }
        else{
            index = nn - 1 + lastNum;
        }
        
        
        preBuildTree(pre[pStart + 1], id * 2 + 1, pStart + 1, pStart + index);
        preBuildTree(pre[pStart + index + 1], id * 2 + 2, pStart + index + 1, pEnd);
        
    }
}

void postBuildTree(char node, int id, int pStart, int pEnd){
    int index, levelNum, lastNum, nn;
    if(pStart >= pEnd){
        trees[id] = node;
        return;
    }
    else{
        trees[id] = node;
        levelNum = (int)(logs[pEnd - pStart + 1]) + 1;
        nn = 1 << (levelNum - 2);
        lastNum = (pEnd - pStart) - (nn - 1) * 2;
        if(lastNum > nn){
            index = nn - 1 + nn;
        }
        else{
            index = nn - 1 + lastNum;
        }
        
        postBuildTree(pre[pStart + index - 1], id * 2 + 1, pStart, pStart + index - 1);
        postBuildTree(pre[pEnd - 1], id * 2 + 2, pStart + index, pEnd - 1);
        
    }
}

void midBuildTree(char node, int addr, int id, int pStart, int pEnd){
    int index1, index2, levelNum1, levelNum2, lastNum1,lastNum2, i, lStart, lEnd, rStart, rEnd, nn1, nn2;
    if(pStart > pEnd){
        return;
        
    }
    if(pStart == pEnd){
        trees[id] = node;
        return;
    }
    else{
        trees[id] = node;

        
        lStart = pStart;
        lEnd = addr - 1;
        if(lStart <= lEnd){
            if(lStart == lEnd){
                index1 = 0;
            }
            else{
                levelNum1 = (int)logs[lEnd - lStart + 1] + 1;
                nn1 = 1 << (levelNum1 - 2);
                lastNum1 = (lEnd - lStart + 1) - ((1 << (levelNum1 - 1)) - 1);
                if(lastNum1 > nn1){
                    index1 =nn1 - 1 + nn1;
                }
                else{
                    index1 = nn1 - 1 + lastNum1;
                }
            }

        }

    
        rStart = addr + 1;
        rEnd = pEnd;
        if(rStart <= rEnd){
            if(rStart == rEnd){
                index2 = 0;
            }
            else{
                levelNum2 = (int)logs[rEnd - rStart + 1] + 1;
                nn2 = 1 << (levelNum2 - 2);
                lastNum2 = (rEnd - rStart + 1) - ((1 << (levelNum2 - 1)) - 1);
                if(lastNum2 > nn2){
                    index2 = nn2 - 1 +nn2;
                }
                else{
                    index2 = nn2 - 1 + lastNum2;
                }
            }

        }
        else{
            index2 = 0;
        }

        
        midBuildTree(pre[lStart + index1], lStart + index1, id * 2 + 1, lStart, lEnd);
        midBuildTree(pre[rStart + index2], rStart + index2, id * 2 + 2, rStart, rEnd);
        
    }
}

int main(){


    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i, j, t, n;
    char inputType[10], transType[10];
    
    
    cin >> t;
    for(i = 1; i < 1000005; i++){
        logs[i] = log(i)/log(2);
    }
    for(i = 0; i < t; i++){
        binaryTree<char> aTree;
        cin >> n;
        cin >> inputType;
        cin >> transType;
        cin >> pre;
        pre[n] = '\0';
        if(transType[0] == 'E'){
            aTree.creatTree('\n');
            if(inputType[1] == 'R'){
                aTree.preOrderSta();
            }
            if(inputType[1] == 'N'){
                aTree.midOrderSta();
            }
            if(inputType[1] == 'O'){
                aTree.postOrderSta();
            }
        }
        else{
            if(inputType[1] == 'R'){
                preBuildTree(pre[0], 0, 0, n - 1);
                for(j = 0; j < n; j++){
                    cout << trees[j];
                }
                cout << '\n';
            }
            if(inputType[1] == 'N'){
                int index;
                int levelNum = (int)logs[n] + 1;
                int nns = 1 << (levelNum - 2);
                int lastNum = (n) - ((1<<(levelNum - 1)) - 1);
                if(lastNum > nns){
                    index = nns - 1 + nns;
                }
                else{
                    index = nns - 1 + lastNum;
                }
                midBuildTree(pre[index],index, 0, 0, n - 1);
                for(j = 0; j < n; j++){
                    cout << trees[j];
                }
                cout << '\n';
            }
    
            if(inputType[1] == 'O'){
                
                postBuildTree(pre[n - 1], 0, 0, n - 1);
                for(j = 0; j < n; j++){
                    cout << trees[j];
                }
                cout << '\n';
            }
        }
        
    }
    

}


