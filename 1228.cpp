#include <iostream>

using namespace std;

const int N = 405;
long long int num[N][N] = {0};
long long int calLine[N];
long long int cal0[N];
long long int n;
long long int odd = 0, even = 0;
void cal(){
    long long int i, j;
    int len = 0, num0 = 0;
    for(i = 0; i < n; i++){
        num0++;
        if(calLine[i] == 1){
            cal0[len] = num0;
            len++;
            num0 = 0;
        }
    }

    if(len == 0){
        return;
    }
    num0++;
    cal0[len] = num0;
    len++;
    
    for(i = 0; i < len; i++){
        for(j = i + 1; j < len; j+= 2){
            odd += (cal0[i] *  cal0[j]);
            //cout << odd << endl;
        }
    }
    len = 0;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int i, j, k, cinNum;
    cin >> n;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cin >> cinNum;
            num[i][j] = cinNum % 2;
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            calLine[j] = num[i][j];
        }
        cal();
        for(j = i + 1; j < n; j++){
            for(k = 0; k < n; k++){
                calLine[k] = (calLine[k] + num[j][k]) % 2;
            }
            cal();
        }

        for(j = 0; j < n; j++){
            calLine[j] = 0;
        }
    }

    even = n * n * (n + 1) * (n + 1) / 4 - odd;
    cout << odd << ' ' << even;
}