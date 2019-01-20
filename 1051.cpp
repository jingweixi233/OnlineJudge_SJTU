#include <stdio.h>
#include <iostream>
#include <cstring>
#include <limits.h>

using namespace std;


template<class elemType>
class sLinkList{
private:
    struct node{
        elemType data;
        node *next;
        node(const elemType &x, node *n = NULL){
            data = x;
            next = n;
        }
        
        node():next(NULL){}
        ~node(){}
    };
    
    node *head, *tail;
    int currentLength;
    
    node *move(int i)const{
        node *p = head;
        while(i >= 0){
            p = p -> next;
            i = i - 1;
        }
        return p;
    }
public:
    sLinkList(){
        head = new node;
        tail = head;
        currentLength = 0;
        
    }
    
    ~sLinkList(){
        clear();
        delete head;
    }
    
    void clear(){
        node *p, *q;
        p = head -> next;
        head -> next = NULL;
        while(p != NULL){
            q = p;
            p = p -> next;
            delete q;
        }
        currentLength = 0;
    }
    
    int length()const{
        return currentLength;
    }
    
    void insertTail(const elemType &x){
        node *p = new node(x);
        tail ->next = p;
        tail = p;
        currentLength = currentLength + 1;
    }
    
    void insertHead(const elemType &x){
        node *p = new node(x, head -> next);
        head -> next = p;
        currentLength = currentLength + 1;
    }
    
    
    
    void remove(node *p){
        
        node *q = p -> next;
        p -> next = q -> next;
        delete q;
        currentLength = currentLength - 1;
    }
    
    elemType search(const elemType &x)const{
        int k = 0;
        node *p = head -> next;
        while(p != NULL){
            if(p -> data  == x){
                return k;
            }
            p = p -> next;
            k = k + 1;
        }
        
        return -1;
    }
    
    elemType visit(int i)const{
        return (move(i)) -> data;
    }
    
    void traverse()const{
        node *p = head -> next;
        while(p != NULL){
            cout << p -> data << " ";
            p = p -> next;
        }
        cout << endl;
    }
    
    int compareNum(int x){
        int sum = 0;
        node *p = head;
        while(p -> next != NULL){
            sum = sum + 1;
            if(p -> next -> data == x){
                insertHead(p -> next -> data);
                remove(p);
                break;
            }
            p =  p -> next;
        }
        return sum;
    }
};



int main(){
    int n, i, num, m, item, comSum = 0;
    sLinkList<int> tab;
    
    cin >> n;
    
    for(i = 0; i < n; i++){
        cin >> num;
        tab.insertTail(num);
    }
    
    cin >> m;
    for(i = 0; i < m; i++){
        cin >> item;
        comSum = comSum + tab.compareNum(item);
    }
    
    cout << comSum;
    
}
