/*
arr[]
blList[]
lcase[]
rcase[]
zuo 
*/

#include <iostream>

using namespace std;

const int N = 100004;

int arr[N];
int blList[N];
int lcase[N * 2];
int rcase[N * 2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num, midNum, mid;
    int answer = 0;
    int i;
    cin >> num >> mid;
    for(i = 1; i <= num; i++){
        cin >> arr[i];
        if(arr[i] > mid){
            blList[i] = 1;
        }
        else{
            if(arr[i] < mid){
                blList[i] = -1;
            }
            else{
                midNum = i;
                blList[i] = 0;
            }
        }
    }
    
    int s = num;
    for(i = midNum; i >= 1; i--){
        s += blList[i];
        lcase[s]++;
    }

    s = num;
    for(i = midNum; i <= num; i++){
        s += blList[i];
        rcase[s]++;
    }

    for(i = 1; i <= num; i++){
        answer = answer + lcase[num + i] * rcase[num - i];
        answer = answer + lcase[num - i] * rcase[num + i];
    }

    answer = answer + lcase[num] * rcase[num];

    cout << answer;
    
}