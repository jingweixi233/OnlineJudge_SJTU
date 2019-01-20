#include <iostream>

using namespace std;

class pQueue{
private:
    int curSize;
    long long int *arr;
    int maxSize;
public:
    pQueue(int cap = 100){
        arr = new long long int[cap];
        maxSize = cap;
        curSize = 0;
    }
    
    ~pQueue(){
        delete []arr;
    }
    
    int getHead(){
        return arr[1];
    }
    
    void enQueue(const long long int &x){
        if(curSize == maxSize - 1){
            doubleS();
        }
        
        int hole = ++curSize;
        for(; hole > 1 && x < arr[hole / 2] ; hole /= 2){
            arr[hole] = arr[hole / 2];
        }
        arr[hole] = x;
    }
    
    int deQueue(){
        int mins;
        mins = arr[1];
        arr[1] = arr[curSize];
        curSize--;
        perDown(1);
        return mins;
    }
    
    void perDown(long long int h){
        int ch;
        int tmp = arr[h];
        
        for(; h * 2 <= curSize; h = ch){
            ch = h * 2;
            if(ch != curSize && arr[ch + 1] < arr[ch]){
                ch++;
            }
            if(arr[ch] < tmp){
                arr[h] = arr[ch];
            }
            else{
                break;
            }
        }
        arr[h] = tmp;
        
    }
    
    

    void doubleS(){
        int i;
        long long int *tmp = arr;
        maxSize *= 2;
        arr = new long long int[maxSize];
        for(i = 0; i <= curSize; i++){
            arr[i] = tmp[i];
        }
        delete []tmp;
        
    }
};






int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long int M, i, num, root;
    char ope[10];
    pQueue berTree;
    cin >> M;
    for(i = 0; i < M; i++){
        cin >> ope;
        if(ope[0] == 'i'){
            cin >> num;
            berTree.enQueue(num);
        }
        if(ope[0] == 'd'){
            berTree.deQueue();
        }
        if(ope[0] == 'm'){
            root = berTree.getHead();
            cout << root << '\n';
        }
    }
    return 0;
}









