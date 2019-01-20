#include <stdio.h>
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
        if(top_p == NULL){
            return 0;
        }
        else{
            return top_p -> data;
        }
        
    }
};


class Bracket{
    
public:
    char frontBracket[1000000];
    char rightBracket[1000000];
    char endBracket[1000000];
    int frontHead = 0, endHead = 0, frontTail = -1, endTail = -1, rightHead = 0, rightTail = 0;

    bool judge(){
        if(frontTail == -1 && endTail == -1){
            return true;
        }
        else{
            return false;
        }
    }
    
    void frontPush(char x){
        frontTail = frontTail + 1;
        frontBracket[frontTail] = x;
    }
    void frontPop(){
        frontBracket[frontTail] = '\0';
        frontTail = frontTail - 1;
    }
    void endPush(char x){
        endTail = endTail + 1;
        endBracket[endTail] = x;
    }
    void endPop(){
        endBracket[endTail] = '\0';
        endTail = endTail - 1;
    }
    void rightPush(char x){
        rightTail = rightTail + 1;
        rightBracket[rightTail] = x;
    }
    void rightPop(){
        rightBracket[rightTail] = '\0';
        rightTail = rightTail - 1;
    }
    
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long int lineNum, i;
    int select;
    char inputX, popX;
    linkStack<char> bracketAll;
    Bracket bBoth;
    
    cin >> lineNum;
    for(i = 0; i < lineNum; i++){
        cin >> select;
        if(select == 1){
            cin >> inputX;
            
            if(inputX == '(' || inputX == '[' || inputX == '{'){
                bracketAll.push(inputX);
                if(inputX == '('){
                    bBoth.frontPush(')');
                }
                if(inputX == '{'){
                    bBoth.frontPush('}');
                }
                if(inputX == '['){
                    bBoth.frontPush(']');
                }
                
            }
            else{
                if(bBoth.frontTail != -1 && inputX == bBoth.frontBracket[bBoth.frontTail]){
                    bracketAll.push(inputX);
                    bBoth.rightPush(bBoth.frontBracket[bBoth.frontTail]);
                    bBoth.frontPop();
                }
                else{
                    bracketAll.push(inputX + 1);
                    bBoth.endPush(inputX);
                }
            }
        }
        if(select == 2){
            if(bracketAll.top() != 0){
                popX = bracketAll.pop();
                if(popX == '(' || popX == '[' || popX == '{'){
                    bBoth.frontPop();

                }
                else{
                    if(popX == ')' || popX == ']' || popX == '}'){
                        bBoth.frontPush(bBoth.rightBracket[bBoth.rightTail]);
                        bBoth.rightPop();
                    }
                    else{
                        bBoth.endPop();
                    }
                }
            }

        }
        if(select == 3){
            if(bracketAll.top() != 0){
                if((bracketAll.top() == ')' + 1) || (bracketAll.top() == ']' + 1)|| (bracketAll.top() == '}' + 1)){
                    cout << (char)(bracketAll.top() - 1) << '\n';
                }
                else{
                    cout << bracketAll.top() << '\n';
                }
                
            }
        }
        if(select == 4){
            if(bracketAll.isEmpty()){
                cout << "YES" << '\n';
            }
            else{
                if(bBoth.judge() == true){
                    cout << "YES" << '\n';
                }
                else{
                    cout << "NO" << '\n';
                }
            }

        }

    }
    
}





