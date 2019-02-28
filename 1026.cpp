#include <iostream>
#include <cstring>

using namespace std;

const int N = 20005;
char a[N] = {'\0'}, b[N] = {'\0'};

struct Int{
    int len;
    int num[N];
    Int(char *s){
        int i;
        len = strlen(s);
        for(i = len; i >= 1; i--){
            num[i] = s[len - i] - '0';
        }
    }
    Int(int l = 0){
        int i;
        len = l;
        for(i = 0; i <= len; i++){
            num[i] = 0;
        }
    }
};

bool lessThan(Int a, Int b){
    int i;
    if(a.len != b.len){
        return a.len < b.len;
    }
    for(i = a.len; i > 0; i--){
        if(a.num[i] != b.num[i]){
            return a.num[i] < b.num[i];
        }
    }
    return false;
}


Int multi(Int a, Int b) {
    Int ans(a.len + b.len);
    for(int i = 1; i <= a.len; i ++) {
        for(int j = 1; j <= b.len; j ++) {
            ans.num[i + j - 1] += a.num[i] * b.num[j];
            ans.num[i + j] += ans.num[i + j - 1] / 10;
            ans.num[i + j - 1] %= 10;
        }
    }
    while(!ans.num[ans.len] && ans.len > 1) ans.len --;
    //cout << ans.num[1] << ' ' <<  ans.num[2] << endl;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    cin >> a;
    cin >> b;
    Int num1(a), num2(b);
    if(lessThan(num1, num2)){
        cout << 0;
        return 0;
    }

    //cout << '*' << num1.num[1] << ' ' << num1.num[2] << endl;
    Int ans(num1.len - num2.len + 1);

    for(i = ans.len; i > 0; i--){
        for(j = 1; j <= 9; j++){
            //cout << i << endl;
            ans.num[i]++;
            if(lessThan(num1, multi(ans, num2))){
                ans.num[i]--;
                break;
            }
        }
    }

    while(ans.len > 1 && !ans.num[ans.len]){
        ans.len--;
    }

    for(i = ans.len; i > 0; i--){
        cout << ans.num[i];
    }
}







