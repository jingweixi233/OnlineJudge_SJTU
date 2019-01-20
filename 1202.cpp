#include<iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

class linkList{
private:
    struct node{
        int data;
        node *next;
        node(int x, node *N = NULL){
            data = x;
            next = N;
        }
        node():next(NULL){}
        ~node(){}
    };
    
    node *top_p;
    
public:
    linkList(){
        top_p = NULL;
    }
    
    ~linkList(){
        node *tmp;
        while(top_p != NULL){
            tmp = top_p;
            top_p = top_p -> next;
            delete tmp;
        }
    }
    
    void push(const int x){
        top_p = new node(x, top_p);
        
    }
    
    int pop(){
        node *tmp = top_p;
        int x;
        x = tmp -> data;
        top_p = top_p -> next;
        delete tmp;
        return x;
    }
    
    bool isEmpty(){
        return top_p == NULL;
    }
};

int main(){
    long int i;
    char cin1, cin2;
    int ele_sum, adder;
    linkList st1;
    linkList st2;
    linkList sum;
    

    cin1 = cin.get();
    while(cin1 != '\n'){
        st1.push((int)cin1 - 48);
        cin1 = cin.get();
    }

    
    cin2 = cin.get();
    while(cin2 != '\n'){
        st2.push((int)cin2 - 48);
        cin2 = cin.get();
    }



    adder = 0;
    while(true){
        if(st1.isEmpty() && st2.isEmpty()){
            if(adder == 0){
                break;
            }
            else{
                sum.push(adder);
                break;
            }
        }
        
        if(st1.isEmpty() && !st2.isEmpty()){
            sum.push(st2.pop() + adder);
            adder = 0;
        }
        
        if(!st1.isEmpty() && st2.isEmpty()){
            sum.push(st1.pop() + adder);
            adder = 0;
        }
        
        if(!st1.isEmpty() && !st2.isEmpty()){
            ele_sum = adder + st1.pop() + st2.pop();
            if(ele_sum >= 10){
                adder = 1;
                sum.push(ele_sum - 10);
            }
            else{
                adder = 0;
                sum.push(ele_sum);
            }
        }
    }
    while(!sum.isEmpty()){
        cout << sum.pop();
    }
    cout << endl;
}
