#include <iostream>

using namespace std;

const int N = 200007;

int len[N];
long long int cnt[N] = {0}, times[N];

int main(){
    int left, right;
    cin >> left >> right;
    int i, j, tmp;
    int ans = 0;

    cnt[1] = right - left + 1;
    for(i = left; i <= right; i++){
        len[i] = 1;
        times[i] = 1;
    }

    for(i = left; i <= right; i++){
        for(j = 1; j <= 100; j++){
            if(i * j % 100 == 0){
                tmp = i + i * j / 100;
                if(tmp <= right){
                    if(len[i] + 1 > len[tmp]){
                        len[tmp] = len[i] + 1;
                        times[tmp] = times[i];
                    }
                    else{
                        if(len[i] + 1 == len[tmp]){
                            times[tmp] += times[i];
                        }
                    }

                    if(len[tmp] > ans){
                        ans = len[tmp];
                    }

                    cnt[len[i] + 1] += times[i];
                }



            }
        }
    }
    cout << ans << endl;
    cout << cnt[ans] << endl;
    
}