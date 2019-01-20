#include <iostream>

using namespace std;

const int MIN = -2147483647;
const int DIF = -20000;
const int N = 40000;

int arr[N] = {0};
int arrOpe[N] = {0};
int tmp[200];

int main(){
    int n, i, m, j, num, k;
    char s;
    
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> s;
        if(s == '+'){
            cin >> m;
            for(j = 0; j < m; j++){
                cin >> num;
                arr[num] = 1;
            }
            for(j = 0; j < N; j++){
                if(arr[j] == 1){
                    cout << j << ' ';
                }
            }
            cout << '\n';
        }
        if(s == '-'){
            cin >> m;
            for(j = 0; j < m; j++){
                cin >> num;
                arr[num] = 0;
            }
            for(j = 0; j < N; j++){
                if(arr[j] == 1){
                    cout << j << ' ';
                }
            }
            cout << '\n';
        }
        if(s == '*'){
            cin >> m;
            k = 0;
            for(j = 0; j < m; j++){
                cin >> num;
                if(arr[num] == 1){
                    tmp[k] = num;
                    k = k + 1;
                }
            }
            for(j = 0; j < N; j++){
                arr[j] = 0;
            }
            for(j = 0; j < k; j++){
                arr[tmp[j]] = 1;
            }
            for(j = 0; j < N; j++){
                if(arr[j] == 1){
                    cout << j << ' ';
                }
            }
            cout << '\n';
            
        }
    }
}












