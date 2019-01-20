#include <iostream>

using namespace std;

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
