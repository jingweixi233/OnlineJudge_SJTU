/*
N = 1000005;
A[N]
B[N]
l[N]
quicksort A, B
class priQue

enQueue
Dequeue

for(i = num)
enQueue

for(i = 1; i <= num; i++){
    int id = deQueue();
    l[id]++;
    enQueue(id); 
}
*/
#include <iostream>

using namespace std;

const int N = 1000005;
int A[N];
int B[N];
int l[N];

void quickSort(int *arr, int l, int r){
    int i = l;
    int j = r;
    int x = arr[l];
    if(l < r){
        while(i < j){
            while(i < j && arr[j] > x){
                j--;
            }
            if(i < j){
                arr[i] = arr[j];
                i++;    
            }
            while(i < j && arr[i] < x){
                i++;
            }
            if(i < j){
                arr[j] = arr[i];
                j--;
            }
        }
        arr[i] = x;
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, r);
    }
}

class priQue{
    public:
    int *elem;
    int curLength;
    
    priQue(int size){
        elem = new int[size];
        curLength = 0;
    }

    void enQueue(int x){
        int hole = curLength + 1;
        for(;hole > 1 && A[elem[hole / 2]] + B[l[elem[hole / 2]]] > A[x] + B[l[x]]; hole /= 2){
            elem[hole] = elem[hole / 2];
        }
        elem[hole] = x;
        curLength++;
    }

    int deQueue(){
        int tmp = elem[1];
        elem[1] = elem[curLength];
        int x = elem[1];
        int hole = 1;
        int child = hole * 2;
        if( A[elem[child]] + B[l[elem[child]]] > A[elem[child + 1]] + B[l[elem[child + 1]]]){
            child++;
        }
        while(child <= curLength && A[elem[child]] + B[l[elem[child]]] < A[x] + B[l[x]]){
            elem[hole] = elem[child];
            hole = child;
            child = hole * 2;
            if( child + 1 <= curLength && A[elem[child]] + B[l[elem[child]]] > A[elem[child + 1]] + B[l[elem[child + 1]]]){
                child++;
            }
        }
        elem[hole] = x;
        curLength--;
        return tmp;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i, num;
    cin >> num;
    for(i = 1; i <= num; i++){
        cin >> A[i];
    }
    for(i = 1 ; i <= num; i++){
        cin >> B[i];
    }
    quickSort(A, 1, num);
    quickSort(B, 1, num);
    /*
    for(i = 1; i <= num; i++){
        cout << A[i] << endl;
    }
    */
    for(i = 1; i <= num; i++){
        l[i] = 1;
    }
    //cout << "one" << endl;
    priQue idTree(num + 10);
    for(i = 1; i <= num; i++){
        idTree.enQueue(i);
    }
    //cout << "two" << endl;
    for(i = 1; i <= num; i++){
        int id = idTree.deQueue();
        //cout << id << endl;
        cout << A[id] + B[l[id]] << " ";
        l[id]++;
        idTree.enQueue(id);
    }
}

















