#include <iostream>

using namespace std;

const int N = 1000005;

int bin[N];

int find(int x){
    if(bin[x] < 0){
        return x;
    }
    return bin[x] = find(bin[x]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i;
    int x, y;
    int ans = 0;
    int cityNum, wayNum, wayall = 0;
    cin >> cityNum >> wayNum;
    for(i = 0; i <= cityNum; i++){
        bin[i] = -1;
    }

    for(i = 0; i < wayNum; i++){
        cin >> x >> y;
        int px = find(x);
        int py = find(y);
        if(px == py){
            continue;
        }
        bin[px] += bin[py];
        bin[py] = px;
    }

    for(i = 0; i <= cityNum; i++){
        if(bin[i] < 0){
            wayall = wayall + bin[i] * (bin[i] + 1) / 2;
        }
    }

    ans = wayall - wayNum;
    cout << ans;
}


