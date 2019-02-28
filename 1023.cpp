/*
num[605][605];
for(){
    cin >> a >> b
    0{
        for(i){
            for(j){
                num[i][j] = num[i][a - i]
            }
            
        }
    }
    1{
        for(i){
            for(j){
                num[i][j] = num[a - i][j]
            }
            
        }
    }
    2{
        for(i){
            for(j){
                if(j > i){
                    num[i][j] = num[j][i];
                }
            }
        }
    }

}
*/
#include <iostream>

using namespace std;

const int N = 605;
int num[605][605];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int numData, i, j, k;
    int len, dir, lenBan, temp;
    cin >> numData;
    for(k = 0; k < numData; k++){
        cin >> len >> dir;
        lenBan = len / 2;

        for(i = 0; i < len; i++){
            for(j = 0; j < len; j++){
                cin >> num[i][j];
            }
        }

        if(dir == 0){
            for(i = 0; i < len; i++){
                for(j = 0; j < lenBan; j++){
                    temp = num[i][j];
                    num[i][j] = num[i][len - j - 1];
                    num[i][len - j - 1] = temp;
                }
            }
        }

        if(dir == 1){
            for(i = 0; i < lenBan; i++){
                for(j = 0; j < len; j++){
                    temp = num[i][j];
                    num[i][j] = num[len - i - 1][j];
                    num[len - i - 1][j] = temp;
                }
            }
        }

        if(dir == 2){
            for(i = 0; i < len; i++){
                for(j = 0; j < len; j++){
                    if(j > i){
                        temp = num[i][j];
                        num[i][j] = num[j][i];
                        num[j][i] = temp;
                    }
                }
            }
        }
        for(i = 0; i < len; i++){
            for(j = 0; j < len; j++){
                cout << num[i][j] << ' ';
            }
            cout << endl;
        }
        
    }


}