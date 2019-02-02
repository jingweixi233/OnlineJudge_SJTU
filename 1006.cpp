/*
N = 1000005
stoneNum
stone[N]
sum[N]
*/

#include <iostream>

using namespace std;

const int N = 1000005;
int stone[N] = {0};
int sum[N] = {0};
int temp, maxx = -100000000;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int stoneNum, i, j;
    int flag = 0;
    cin >> stoneNum;
    for(i = 0; i < stoneNum; i++){
        cin >> stone[i];
    }
    if(stoneNum == 1){
        cout << "Game Over";
        return 0;
    }
    
    temp = stone[0];
    for(i = 1; i < stoneNum; i++){
        if(temp < 0){
            temp = stone[i];
            flag = 0;
        }
        else{
            temp = stone[i] + temp;
            flag = 1;
        }
        if(temp > maxx && flag == 1){
            maxx = temp;
        }
    }  
    
    if(maxx > 0){
        cout << maxx;
    }
    else{
        cout << "Game Over";
    }
}




