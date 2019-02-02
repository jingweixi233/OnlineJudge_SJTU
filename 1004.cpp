/*
timeLimit
roadNum
timeUp
timeFlat
timeDown
time = 0
k = 0;
N = 100005;
road[N];

while(true){
    if(road[k] == 'u'){
        time = time + timeUp + timeDown;
    }
    if(road[k] == 'f'){
        time = time + timeFlat * 2;
    }
    if(road[k] == 'd'){
        time = time + timeUp + timeDown;
    }
    k = k + 1;
    if(time > timeLimit){
        break;
    } 
}
*/


#include <iostream>

using namespace std;

const int N = 100005;
char road[N];

int main(){
    int timeLimit, roadNum, timeUp, timeFlat, timeDown;
    int i, k = 0;
    int time = 0;

    cin >> timeLimit >> roadNum >> timeUp >> timeFlat >> timeDown;
    for(i = 0; i < roadNum; i++){
        cin >> road[i];
    }
    while(true){
        if(road[k] == 'u'){
            time = time + timeUp + timeDown;
        }
        if(road[k] == 'f'){
            time = time + timeFlat * 2;
        }
        if(road[k] == 'd'){
            time = time + timeUp + timeDown;
        }
        k = k + 1;
        if(time > timeLimit){
            break;
        } 
    }
    cout << k - 1;

}
