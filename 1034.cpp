/*
minn = 
for(kernel){
    size
    kernelFirst
    kernelMax
    newAdd
    if(kenelFirst + size > MAx){
        Maxx 
        kenelFirst = i
        continue;
    }
    if(kenelFirst == kenelMax){
        for(j = ){
            kenelMax;
        }
        continue;
    }
    if(kenelFirst != kenelMax){
        newAdd vs kenelMax;
    }
    
}
*/

#include <iostream>

using namespace std;

const int N = 200005;
const int intMax = 2000000000;

int gold[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int numAll, size;
    int i, j;
    int minn = intMax;
    int kernelFirst = intMax;
    int kernelMax = intMax;
    cin >> numAll >> size;

    for(i = 0; i < numAll; i++){
        cin >> gold[i];
    }

    for(i = 0; i < numAll; i++){
        
        if(gold[i + size - 1] >= kernelMax){
            kernelMax = gold[i + size - 1];
            kernelFirst = gold[i];
        }
        else{
            if(kernelMax == kernelFirst){
                kernelMax = 0;
                for(j = i; j <= i + size - 1; j++){
                    int id = j % numAll;
                    if(gold[id] > kernelMax){
                        kernelMax = gold[id];
                    }
                }
                kernelFirst = gold[i];
            }
            else{
                kernelFirst = gold[i];
            }
        }
        if(kernelMax < minn){
            minn = kernelMax;
        }
    }

    cout << minn;

}