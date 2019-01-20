#include <iostream>

using namespace std;

const int N = 35;
int f[N][N], rootnum[N][N];
int score[N];

int calSco(int l, int r){
    int k;
    if(l > r){
        return 1;
    }
    if(l == r){
        return score[l];
    }
    if(f[l][r]){
        return f[l][r];
    }
    int maxSco = 0, tmp = 0;
    int rootAddr = 0;
    for(k = l; k <= r; k++){
        tmp = score[k] + calSco(l, k - 1) * calSco(k + 1, r);
        if(tmp > maxSco){
            maxSco = tmp;
            rootAddr = k;
        }
        
    }
    f[l][r] = maxSco;
    rootnum[l][r] = rootAddr;
    return maxSco;
}

void preOrder(int l, int r){
    int k;
    if(l > r){
        return;
    }
    if(l == r){
        cout << l << ' ';
        return;
    }
    k = rootnum[l][r];
    cout << k << ' ';
    preOrder(l, k - 1);
    preOrder(k + 1, r);
    
    
}

int main(){
    int n, i, maxScore;
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> score[i];
    }
    maxScore = calSco(1, n);
    cout << maxScore << '\n';
    preOrder(1 ,n);
}
