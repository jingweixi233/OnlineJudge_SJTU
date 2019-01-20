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
    
    void consume(){
        int i;

        
    }
    

};






int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long int n, i, apple1, apple2, appleSum, ans = 0;
    cin >> n;
    const long long int length = n;
    long long int apple[length];
    pQueue appleTree;
    
    for(i = 0; i < n; i++){
        cin >> apple[i];
    }
    
    for(i = 0; i < n; i++){
        appleTree.enQueue(apple[i]);
    }
    
    for(i = 1; i < n; i++){
        apple1 = appleTree.deQueue();
        apple2 = appleTree.deQueue();
        appleSum = apple1 + apple2;
        appleTree.enQueue(appleSum);
        ans = ans + appleSum;
    }
    
    cout << ans;
    


}






