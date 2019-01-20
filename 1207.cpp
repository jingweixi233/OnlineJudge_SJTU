#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

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

int main(){
    ios::sync_with_stdio(false);
    int N;
    int i, type, carTime, carNum;
    int busNum, vanNum;
    int totalTime, timer;
    int ship, shipTotal;
    double busWaitTime, vanWaitTime;
    double busAver, vanAver;
    linkQueue<int> busQueue, vanQueue;
    
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> type;
        cin >> carTime;
        if(type == 0){
            busQueue.enQueue(carTime);
        }
        else{
            vanQueue.enQueue(carTime);
        }
    }
    
    busWaitTime = vanWaitTime = 0;
    busNum = vanNum = 0;
    timer = 0;
    carNum = 0;
    shipTotal = 0;
    while(true){
        for(ship = 0; ship < 8 && !busQueue.isEmpty() && busQueue.getHead() <= timer; ++ship){
            busWaitTime = busWaitTime + timer - busQueue.deQueue();
            busNum = busNum + 1;
        }
        
        for(;ship < 10 && !vanQueue.isEmpty() && vanQueue.getHead() <= timer; ++ship){
            vanWaitTime = vanWaitTime + timer - vanQueue.deQueue();
            vanNum = vanNum + 1;
        }
        
        for(;ship < 10 && !busQueue.isEmpty() && busQueue.getHead() <= timer; ++ship){
            busWaitTime = busWaitTime + timer - busQueue.deQueue();
            busNum = busNum + 1;
        }
        shipTotal = shipTotal + ship;
        if(shipTotal == N){
            break;
        }
        timer = timer + 10;
    }
    busAver = busWaitTime / busNum;
    vanAver = vanWaitTime / vanNum;
    
    cout << fixed << setprecision(3) << busAver << " ";
    cout << fixed << setprecision(3) << vanAver;
    
}




