#include <iostream>

using namespace std;

struct ver{
    int id;
    int dis;
};
class priorityQueue{
private:
    ver *arr;
    int curSize;
    int maxSize;

public:
    priorityQueue(int size = 1000){
        arr = new ver[size];
        maxSize = size;
        curSize = 0;
    }
    
    ~priorityQueue(){
        delete []arr;
    }

    void doubleSpace(){
        int i;
        int *tmp = arr;
        arr = new ver[maxSize * 2];
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
    
};


const int N = 10005;
const int INF = 1e9;

struct node{
    int id;
    int w;
    node *next;
    node(int i, int ww, node *n = NULL){
        id = i;
        w = ww; 
        next = n;
    }
};

node* list[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int nodeNum, wayNum, start, end;
    int i, j;
    int x, y, wei;
    cin >> nodeNum >> wayNum >> start >> end;
    for(i = 0; i <= nodeNum; i++){
        dis[i] = INF;
    }
    for(i = 0; i < wayNum; i++){
        cin >> x >> y >> wei;
        node *p = list[x];
        node *q = new node(y, wei, NULL);
        q -> next = p;
        list[x] = q;
    }
}