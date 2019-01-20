#include <iostream>
#include <stdio.h>

using namespace std;

template<class elemType>
class stack{
public:
    virtual bool isEmpty()const = 0;
    virtual void push(const elemType &x) = 0;
    virtual void pop() = 0;
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
    int currentLength;
    
public:
    linkStack(){
        top_p = NULL;
        currentLength = 0;
    }
    
    
    ~linkStack(){
        node *tmp;
        while(top_p != NULL){
            tmp = top_p;
            top_p = top_p -> next;
            delete tmp;
        }
    }
    
    void clear(){
        node *tmp;
        while(top_p != NULL){
            tmp = top_p;
            top_p = top_p -> next;
            delete tmp;
        }
        currentLength = 0;
    }
    bool isEmpty()const{
        return top_p == NULL;
    }
    
    void push(const elemType &x){
        top_p = new node(x, top_p);
        currentLength = currentLength + 1;
    }
    
    void pop(){
        node *tmp = top_p;
        elemType x;
        x = tmp -> data;
        top_p = top_p -> next;
        delete tmp;
        currentLength = currentLength - 1;
    }
    
    elemType top()const{
        return top_p -> data;
    }
    elemType length(){
        return currentLength;
    }
};

int numArray[1000000];

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int testNum, numI, numberNum, i, k, j, numDif, flag;

    linkStack<int> numStack;
    
    cin >> testNum;
    for(k = 0; k < testNum; k++){
        cin >> numberNum;
        for(i = 0; i < numberNum; i++){
            cin >> numArray[i];
        }
        numI = 1;
        flag = 1;
        for(j = 0; j < numberNum; j++){
            if(numArray[j] == numI){
                numI = numI + 1;
                continue;
            }
            if(numStack.length() >= 1 && numArray[j] == numStack.top()){
                numStack.pop();
                continue;
            }
            if(numArray[j] > numI){
                numDif = numArray[j] -  numI;
                for(i = 0; i < numDif; i++){
                    numStack.push(numI);
                    numI = numI + 1;
                }
                numI = numI + 1;
                continue;
            }
            flag = 0;
            break;
        }
        if(flag == 0){
            cout << "No" << '\n';
        }
        else{
            cout << "Yes" << '\n';
        }
        numStack.clear();
    }
}
