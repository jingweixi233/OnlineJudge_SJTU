#include <iostream>

using namespace std;

const int N = 100005;

int dui[N * 4];
int number[N];
int curSize;
void pdown(){
    int s = dui[1];
    int hole = 1;
    int child = hole * 2;
    if(child + 1 <= curSize && dui[child + 1] <= dui[child]){
        child++;
    }
    while(child <= curSize && dui[child] < s){
        dui[hole] = dui[child];
        hole = child;
        child = hole * 2;
        if(child + 1 <= curSize && dui[child + 1] < dui[child]){
            child++;
        }
    }
    dui[hole] = s;
}
void push(int x){
    int hole = curSize + 1;
    while(hole / 2 >= 1 && dui[hole / 2] > x){
        dui[hole] = dui[hole / 2];
        hole = hole / 2;
    }
    dui[hole] = x;
    curSize++;

}

int pop(){
    int ans = dui[1];
    dui[1] = dui[curSize];
    curSize--;
    pdown();
    return ans;
    

}



int main(){
    long long int sum = 0;
    int num, cha;
    cin >> num >> cha;
    int i;
    for(i = 1; i <= num; i++){
        cin >> number[i];
    }

    if((num - 1) % (cha - 1) != 0){
        int bu = (num - 1) % (cha - 1);
        for(i = 1; i <= bu; i++){
            push(0);
        }
    }

    for(i = 1; i <= num; i++){
        push(number[i]);
    }
    
    while(true){
        int lineSum = 0;
        for(i = 1; i <= cha; i++){
            int k = pop();
            //cout << k << " ";
            lineSum += k;
        }
        sum = sum + lineSum;
        //cout << endl;
        if(curSize == 0){
            break;
        }
        push(lineSum);
    }
    
    cout << sum;
}
