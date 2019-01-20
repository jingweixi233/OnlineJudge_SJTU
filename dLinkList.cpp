#include <stdio.h>
#include <iostream>
#include <cstring>


using namespace std;

template<class elemType>
class list
{
public:
    virtual void clear() = 0;            //clear all elements in list
    virtual int length()const = 0;       //get the length of list
    virtual void insert(int i, const elemType &x) = 0;  //insert an element in list
    virtual void remove(int i) = 0;       //remove an list in list
    virtual int search(const elemType &x)const = 0;     //search the element
    virtual elemType visit(int i)const = 0;             //visit the element
    virtual void traverse()const = 0;    //visit every element in list
    virtual ~list(){};
};

template<class elemType>
class dLinkList:public list<elemType>{
private:
    struct node{
        elemType data;
        node *prev, *next;
        node(const elemType &x, node *p = NULL, node *n = NULL){
            data = x;
            next = n;
            prev = p;
        }
        
        node():next(NULL), prev(NULL){}
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
    dLinkList(){
        head = new node;
        tail = new node;
        head -> next = tail;
        tail -> prev = head;
        currentLength = 0;
        
    }
    
    ~dLinkList(){
        clear();
        delete head;
        delete tail;
    }
    
    void clear(){
        node *p, *q;
        p = head -> next;
        head -> next = tail;
        tail -> prev = head;
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
    
    void insert(int i, const elemType &x){
        node *p, *tmp;
        p = move(i);
        tmp = new node(x, p -> prev, p);
        p -> prev -> next = tmp;
        p -> prev = tmp;
        currentLength = currentLength + 1;
    }
    
    void remove(int i){
        node *p = move(i);
        p -> prev -> next = p -> next;
        p -> next -> prev = p -> prev;
        delete p;
        currentLength = currentLength - 1;
    }
    
    elemType search(const elemType &x)const{
        int k = 0;
        node *p = head -> next;
        while(p != tail){
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
        while(p != tail){
            cout << p -> data << " ";
            p = p -> next;
        }
        cout << endl;
    }
};




