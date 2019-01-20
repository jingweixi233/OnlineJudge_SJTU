/*
mou[];
i = 0;
int water;
if(mou[i] == 0){
    i++;
}
if(mou[i] > 0){
    j = i + 2;
    if(j > n){
        break;

    }
    if(mou[j] >= mou[i]){
        int holeAll = mou[k] % mou[i];
        water += mou[i] * k - holeAll;
        i = j;
    }
    i++;
}
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1005;

int mou[N];
char mouChar[3 * N];
char number[6];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int mouNum, i, j, k, q, maxI, maxJ, mouId = 0;
    int water = 0;
    cin >> mouNum;
    cin >> mouChar;
    k = 0;
    for(i = 1; i < strlen(mouChar); i++){
        
        if('0' <= mouChar[i] && mouChar[i] <= '9'){
            number[k] = mouChar[i];
            //cout << number[k] << endl;
            k++;
        }
        else{
            k = 0;
            
            int add10 = 1;
            for(q = 0; q < strlen(number); q++){
                mou[mouId] += (int(number[strlen(number) - q - 1]) - 48 ) * add10;
                add10 *= 10;
            }
            mouId++;
         

            for(j = 0; j < 6; j++){
                number[j] = '\0';
            }
        }
    }
    i = 0;
    j = mouNum - 1;
    maxI = mou[i];
    maxJ = mou[j];
    while(i < j){
        if(maxI < maxJ){
            i++;
            if(mou[i] > maxI){
                maxI = mou[i];
            }
            else{
                water += maxI - mou[i];
            } 
        }
        else{
            j--;
            if(mou[j] > maxJ){
                maxJ = mou[j];
            }
            else{
                water += maxJ - mou[j];
            }
        }
    }
    cout << water;
}
