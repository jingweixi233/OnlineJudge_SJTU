#include <iostream>
#include <cstring>

using namespace std;

struct node{
    int id;
    int height;

    node(int idd = 0, int hi = 0){
        id = idd;
        height = hi;
    }
};

const int N = 100005;
node item[N];
int planeNum;

class priorityQueue{
private:
    node *arr;
    int curSize;
    int maxSize;

public:
    priorityQueue(int size = 4 * N){
        arr = new node[size];
        maxSize = size;
        curSize = 0;
    }
    
    ~priorityQueue(){
        delete []arr;
    }
    void enQueue(int idd, int high){
        curSize++;
        node newNode = node(idd, high);
        arr[curSize] = newNode;
        //push up
        int hole = curSize;
        while(true){
            if(hole == 1 || arr[hole / 2].height < high){
                arr[hole] = newNode;
                break;
            }
            
            arr[hole] = arr[hole / 2];
            hole = hole / 2;
        }
    }
    
    
    void pDown(int id){
        node x = arr[id];
        int hole = id;
        int child = hole * 2;
        if(arr[child].height > arr[child + 1].height){
            child++;
        }

        while(true){
            if(hole * 2 > curSize || x.height < arr[child].height || (x.height == arr[child].height && x.id < arr[child].id)){
                arr[hole] = x;
                break;
            }
            arr[hole] = arr[child];
            hole = child;
            child = hole * 2;
            if(child !=  curSize && arr[child].height > arr[child + 1].height){
                child++;
            }
        }
    }
    
    node deQueue(){
        node minn = arr[1];
        arr[1] = arr[curSize];
        curSize--;
        pDown(1);
        return minn;
    }
    
    void buildHeap(){
        int i;
        curSize = planeNum;
        for(i = 1; i <= curSize; i++){
            arr[i] = item[i];
        }
        
        for(i = curSize / 2; i >= 1; i--){
            pDown(i);
        }
    }

};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i;
    int x, y;
    string oprType;
    priorityQueue heap;

    cin >> planeNum;

    for(i = 1; i <= planeNum; i++){
        item[i].id = i;
        cin >> item[i].height;
    }

    while(cin >> oprType){
        if(oprType[0] == 'f'){
            cin >> x;
            heap.buildHeap();
            while(true){
                node minn = heap.deQueue();
                int minnId = minn.id;
                if(minn.height > x){
                    node temp = heap.deQueue();
                    while(temp.height == minn.height){
                        if(temp.id < minnId){
                            minnId = temp.id;
                        }
                        temp = heap.deQueue();
                    }
                    cout << minnId << endl;
                    break;
                } 
            }
        }
        else{
            cin >> x >> y;
            item[x].height = item[x].height - y;
        }
    }
}

    
    
