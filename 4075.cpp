/*
A[]
B[]
long int bKey = k << (b[i] % 3) + ...
for ... akey 
aKey == bKey
i
*/

#include <iostream>
#include <cstring>

using namespace std;

const int aN = 1000006;
const int bN = 100005;

char strA[aN] = {'\0'};
char strB[bN] = {'\0'};
int nextB[bN] = {0};

void makenextB(){
    int i, k = 0;
    nextB[0] = 0;
    int n = strlen(strB);
    for(i = 1; i < n; i++){
        while(k > 0 && strB[i] != strB[k]){
            k = nextB[k - 1];
        }
        if(strB[i] == strB[k]){
            k++;
        }
        nextB[i] = k;
    }

}

int calAdd(){
    int i = 0, k = 0;
    int m = strlen(strA);
    int n = strlen(strB);
    for(i = 0; i < m; i++){
        while(k > 0 && strB[k] != strA[i]){
            k = nextB[k - 1];
        }
        if(strB[k] == strA[i]){
            k++;
        }
        if(k == n){
            break;
        }
    }
    return (i - n + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i;
    cin >> strA;
    cin >> strB;
    makenextB();
    //cout << strlen(strB) << endl;
    /*
    for(i = 0; i < 4; i++){
        cout << nextB[i] << '\n';
    }
    */
    int add = calAdd();
    cout << add;

}