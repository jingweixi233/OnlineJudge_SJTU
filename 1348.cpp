#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

void quickSort(long long int a[], long long int l, long long int r){
    long long int i, j, x;
    if(l < r){
        i = l;
        j = r;
        x = a[l];
        while(i < j){
            while(i < j && a[j] >= x){
                j = j - 1;
            }
            if(i < j){
                a[i] = a[j];
                i = i + 1;
            }
            while(i < j && a[i] < x){
                i = i + 1;
            }
            if(i < j){
                a[j] = a[i];
                j = j - 1;
            }
        }
        a[i] = x;
        quickSort(a, l, i -1);
        quickSort(a, i + 1, r);
    }
}

int main(){
    long long int sex, timeCom, time = 0, couple = 0, songK = 0;
    long long int N, M, boyTime = 0, girlTime = 0, boyNum = 0, girlNum = 0, i = 0;
    cin >> N;
    const long long int songNum = N;
    long long int songs[songNum];
    for(i = 0; i < songNum; i++){
        cin >> songs[i];
    }
    cin >> M;
    const long long int studentNum = M;
    long long int boy[studentNum];
    long long int girl[studentNum];
    for(i = 0; i < M; i++){
        cin >> sex >> timeCom;
        if(sex == 1){
            boy[boyNum] = timeCom;
            boyNum = boyNum + 1;
        }
        else{
            girl[girlNum] = timeCom;
            girlNum = girlNum + 1;
            }
    }
    quickSort(boy, 0, boyNum - 1);
    quickSort(girl, 0, girlNum - 1);
    
    
    while(true){
        while(true){
            if(couple <= boyNum - 1 && couple <= girlNum - 1 && boy[couple] <= time && girl[couple] <= time){
                boyTime = boyTime + time - boy[couple];
                girlTime = girlTime + time - girl[couple];
                couple = couple + 1;
            }
            else{
                break;
            }
        }
        time = time + songs[songK];
        songK = songK + 1;
        if(songK + 1 == songNum){
            break;
        }
    }
    
    for(i = couple; i < boyNum; i++){
        boyTime = boyTime + time - boy[i];
    }
    for(i = couple; i < girlNum; i++){
        girlTime = girlTime + time - girl[i];
    }

    double boyWait = (double)boyTime/boyNum;
    double girlWait = (double)girlTime/girlNum;
    cout << fixed << setprecision(2) << boyWait << ' ' << girlWait;
    
}
