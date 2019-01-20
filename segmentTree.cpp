#include <iostream>
#include <cmath>

using namespace std;

const int N = 1000000;
long long int sum[N], lazyT[N];
long long int a[N];

void pushUp(int id){
    sum[id] = sum[id * 2] + sum[id * 2 + 1];
}

void pushDown(int id, int leftTreeNum, int rightTreeNum){
    if(lazyT[id]){
        lazyT[id * 2] += lazyT[id];
        lazyT[id * 2 + 1] += lazyT[id];
        
        sum[id * 2] += lazyT[id] * leftTreeNum;
        sum[id * 2 + 1] += lazyT[id] * rightTreeNum;
        
        lazyT[id] = 0;
    }
}

void buildTree(int l, int r, int id){
    if(l == r){
        sum[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    
    buildTree(l, mid, id * 2);
    buildTree(mid + 1, r, id * 2 + 1);
    
    pushUp(id);
}

//change a node(a[idChange] += num)
void update(int idChange, int num, int l, int r, int id){
    if(l == r){
        sum[id] += num;
        return;
    }
    
    int mid = (l + r) / 2;
    if(idChange <= mid){
        update(idChange, num, l, mid, id * 2);
    }
    else{
        update(idChange, num, mid + 1, r, id * 2 + 1);
    }
    pushUp(id);
}

//change a [](a[idChangeLeft, a[idChangeRight]] += num)
void update(int idChangeLeft, int idChangeRight, int num, int l, int r, int id){
    if(idChangeLeft <= l && r <= idChangeRight){
        sum[id] += num * (r - l + 1);
        lazyT[id] += num;
        return;
    }
    
    int mid = (l + r) / 2;
    pushDown(id, mid - l + 1, r - mid);
    
    if(idChangeLeft <= mid){
        update(idChangeLeft, idChangeRight, num, l, mid, id * 2);
        
    }
    if(idChangeRight > mid){
        update(idChangeLeft, idChangeRight, num, mid + 1, r, id * 2 + 1);
    }
    pushUp(id);
}

long long int query(int queryLeft, int queryRight, int l, int r, int id){
    if(queryLeft <= l && r <= queryRight){
        return sum[id];
    }
    int mid = (l + r) / 2;
    pushDown(id, mid - l + 1, r - mid);
    long long int ans = 0;
    if(queryLeft <= mid){
        ans += query(queryLeft, queryRight, l, mid, id * 2);
    }
    if(queryRight > mid){
        ans += query(queryLeft, queryRight, mid + 1, r, id * 2 + 1);
    }
    return ans;
}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, i, ql, qr, cl, cr, c;
    char typeOpe;
    
    cin >> N;
    cin >> M;
    
    for(i = 1; i <= N; i++){
        cin >> a[i];
    }
    
    buildTree(1, N, 1);
    
    for(i = 0; i < M; i++){
        cin >> typeOpe;
        if(typeOpe == 'Q'){
            cin >> ql;
            cin >> qr;
            long long int ans = query(ql, qr, 1, N, 1);
            cout << ans << '\n';
        }
        else{
            cin >> cl;
            cin >> cr;
            cin >> c;
            update(cl, cr, c, 1, N, 1);
        }
    }
}



struct node{
    int lValue, rValue;
};

node strNode[100000];
const int K = 123;

void pushUp(int id, int leftTreeLength, int rightTreeLength){
    strNode[id].lValue = strNode[id * 2].lValue + strNode[id * 2 + 1].rValue * pow(K, leftTreeLength);
    strNode[id].rValue = strNode[id * 2 + 1].rValue + strNode[id * 2].lValue * pow(K, rightTreeLength);
    
}
