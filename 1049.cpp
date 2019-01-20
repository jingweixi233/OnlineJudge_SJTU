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



int main(){
    int testNum, train, trainNum, stackNum, i, k, j, trainDif, flag;
    int trainArray[1000];
    linkStack<int> trainStack;
    
    cin >> testNum;
    for(k = 0; k < testNum; k++){
        cin >> trainNum;
        cin >> stackNum;
        for(i = 0; i < trainNum; i++){
            cin >> trainArray[i];
        }
        train = 0;
        flag = 1;
        for(j = 0; j < trainNum; j++){
            if(trainArray[j] == train){
                train = train + 1;
                continue;
            }
            if(trainStack.length() >= 1 && trainArray[j] == trainStack.top()){
                trainStack.pop();
                continue;
            }
            if(trainArray[j] >  train && ((trainArray[j] -  train) <= (stackNum - trainStack.length()))){
                trainDif = trainArray[j] -  train;
                for(i = 0; i < trainDif; i++){
                    trainStack.push(train);
                    train = train + 1;
                }
                train = train + 1;
                continue;
            }
            flag = 0;
            break;
        }
        if(flag == 0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
        trainStack.clear();
    }
}

