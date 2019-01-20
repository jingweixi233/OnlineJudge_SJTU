#include <stdio.h>
#include <iostream>
#include <cstring>
#include <limits.h>

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
class sLinkList:public list<elemType>{
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
    
    node *head;
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
    
    void insert(int i, const elemType &x){
        node *p = move(i - 1);
        p = new node(x, p -> next);
        currentLength = currentLength + 1;
    }
    
    void remove(int i){
        node *p = move(i - 1);
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
};





















