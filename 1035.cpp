/*
for(K){
    Q{
        build heap
        for(){
            list = dequeue();
            
        }
    }
    else{
        stock[]change
    }
}

*/

#include <iostream>

using namespace std;

const int N = 100000;
int stockNum;
int item[N];
int ansList[N];
int stock[N];

class priorityQueue{
private:
    int *arr;
    int curSize;
    int maxSize;

public:
    priorityQueue(int size = N){
        arr = new int[size];
        maxSize = size;
        curSize = 0;
    }
    
    ~priorityQueue(){
        delete []arr;
    }

    void doubleSpace(){
        int i;
        int *tmp = arr;
        arr = new int[maxSize * 2];
        maxSize = maxSize * 2;
        for(i = 1; i < maxSize; i++){
            arr[i] = tmp[i];
        }
        delete []tmp;
    }
    void enQueue(int x){
        if(curSize == maxSize - 1){
            doubleSpace();
        }
        curSize++;
        arr[curSize] = x;
        //push up
        int hole = curSize;
        while(true){
            if(hole == 1 || arr[hole / 2] <= x){
                arr[hole] = x;
                break;
            }
            
            arr[hole] = arr[hole / 2];
            hole = hole / 2;
        }
    }
    
    int getHead(){
        return arr[1];
    }
    
    void pDown(int id){
        int x = arr[id];
        int hole = id;
        int child = hole * 2;
        if(stock[arr[child]] <= stock[arr[child + 1]]){
            child++;
        }

        while(true){
            if(hole * 2 > curSize || stock[x] >= stock[arr[child]]){
                arr[hole] = x;
                break;
            }
            arr[hole] = arr[child];
            hole = child;
            child = hole * 2;
            if(child !=  curSize &&  stock[arr[child]] <= stock[arr[child + 1]]){
                child++;
            }
        }
    }
    
    int deQueue(){
        int maxx = arr[1];
        arr[1] = arr[curSize];
        curSize--;
        pDown(1);
        return maxx;
    }
    
    void buildHeap(){
        int i;
        curSize = stockNum;
        for(i = 1; i <= curSize; i++){
            arr[i] = item[i];
        }
        
        for(i = curSize / 2; i >= 1; i--){
            pDown(i);
        }
    }
    
    void printHeap(){
        int i;
        for(i = 1; i <= stockNum; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    int i, j;
    int oprNum;
    char oprType;
    int oprListNum;
    int ansNum;
    int changeId, changeMoney;

    cin >> stockNum;
    for(i = 1; i <= stockNum; i++){
        cin >> stock[i];
    }
    for(i = 0; i <= stockNum; i++){
        item[i] = i;
    }
    cin >> oprNum;

    priorityQueue tree;
    for(i = 0; i < oprNum; i++){
        cin >> oprType;
        if(oprType == 'Q'){
            tree.buildHeap();
            for(j = 0; j < stockNum; j++){
                ansList[j] = tree.deQueue();
            }
            cin >> oprListNum;
            for(j = 0; j < oprListNum; j++){
                cin >> ansNum;
                cout << ansList[ansNum - 1] << ' ';
            }
            cout << endl;
        }
        else{
            cin >> changeId >> changeMoney;
            stock[changeId] = changeMoney;
        }
    }
}
