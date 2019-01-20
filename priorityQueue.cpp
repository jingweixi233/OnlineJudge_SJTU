#include <iostream>

using namespace std;

const int N = 1000;
int item[N];

class priorityQueue{
private:
    int *arr;
    int curSize;
    int maxSize;

public:
    priorityQueue(int size = 1000){
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
        if(arr[child] > arr[child + 1]){
            child++;
        }

        while(true){
            if(hole * 2 > curSize || x < arr[child]){
                arr[hole] = x;
                break;
            }
            arr[hole] = arr[child];
            hole = child;
            child = hole * 2;
            if(child !=  curSize && arr[child] > arr[child + 1]){
                child++;
            }
        }
    }
    
    int deQueue(){
        int minn = arr[1];
        arr[1] = arr[curSize];
        curSize--;
        pDown(1);
        return minn;
    }
    
    void buildHeap(){
        int i;
        curSize = N;
        for(i = 1; i <= curSize; i++){
            arr[i] = item[i - 1];
        }
        
        for(i = curSize / 2; i >= 1; i--){
            pDown(i);
        }
    }
    
    void printHeap(){
        int i;
        for(i = 1; i <= curSize; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    priorityQueue tree;
    tree.buildHeap();
    tree.deQueue();
    tree.printHeap();
}
