#include <iostream>
#include <stdio.h>
#include <cstring>

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
        if(top_p == NULL){
            return "-1";
        }
        else{
            return top_p -> data;
        }

    }
};

int main(){
    int flag, beginExist = 0;
    string str;
    linkStack<string> wordStack;
    while(cin >> str){
        flag = 0;
        if(str == "begin"){

            wordStack.push(str);

        }
        
        if(str == "if"){
            wordStack.push(str);
            continue;
        }
        
        if(str == "then"){
            if(wordStack.top() == "if"){
                wordStack.push(str);
                continue;
            }
            else{
                cout << "Error!" << endl;
                return 0;
            }
        }
        
        if(str == "else"){
            if(wordStack.top() == "then"){
                wordStack.pop();
                wordStack.pop();
                continue;
            }
            else{
                cout << "Error!" << endl;
                return 0;
            }
        }
        
        if(str == "end"){
            while(wordStack.top() != "-1"){
                if(wordStack.top() == "begin"){
                    flag = 1;
                    wordStack.pop();
                    break;
                }
                else{
                    wordStack.pop();
                }
            }
            if(flag == 0){
                cout << "Error!" << endl;
                return 0;
            }
            else{
                continue;
            }
        }
    }
    
    while(wordStack.top() != "-1"){
        if(wordStack.top() == "begin"){
            beginExist = 1;
            wordStack.pop();
            break;
        }
        else{
            wordStack.pop();
        }
    }
    if(beginExist == 0){
        cout << "Match!" << endl;
    }
    else{
        cout << "Error!" << endl;
    }
}
