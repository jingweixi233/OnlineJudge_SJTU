/*
highGe
highDen
numApp
numGet
for{
    if(cin <= highhe){
        numGet++;
    }
}
*/

#include <iostream>

using namespace std;

int main(){
    int highGe, highDen, numApp, high, highApp;
    int numGet = 0;
    int i;
    cin >> highGe >> highDen >> numApp;
    high = highGe + highDen;
    for(i = 0; i < numApp; i++){
        cin >> highApp;
        if(highApp <= high){
            numGet++;
        }
    }
    cout << numGet;
    return 0;
}