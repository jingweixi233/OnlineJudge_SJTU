/*
string strList[N];
int *strHash[N];
strHash[i] = new []
p = 33;
strHash[i][k] = strHash[i][k - 1] * p + int(str[i][k]);
int bSearch(int l, int r){}
*/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 100005;
const int base = 1e9;
string strList[N];
int *strHash[N];
int *strHashNi[N];
const int p = 131;

int bSearch(int strId1, int strId2, int l, int r){
    int mid = (l + r) / 2;
    while(l <= r){
        if(strHash[strId1][mid] == strHash[strId2][mid] && strHash[strId1][mid + 1] != strHash[strId2][mid + 1]){
            return mid;
        }
        else{
            if(strHash[strId1][mid] == strHash[strId2][mid]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        mid = (l + r) / 2;
    }
    return -1;
}

int bSearchNi(int strId1, int strId2, int l, int r){
    int mid = (l + r) / 2;
    while(l <= r){
        if(strHashNi[strId1][mid] == strHashNi[strId2][mid] && strHashNi[strId1][mid + 1] != strHashNi[strId2][mid + 1]){
            return mid;
        }
        else{
            if(strHashNi[strId1][mid] == strHashNi[strId2][mid]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        mid = (l + r) / 2;
    }
    return -1;
}


int minn(int a, int b){
    if(a > b){
        return b;
    }
    else{
        return a;
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int nameNum;
    int i, j;
    int oprNum, oprType;
    int oprX, oprY;
    cin >> nameNum;
    for(i = 1; i <= nameNum; i++){
        cin >> strList[i];
    }
    for(i = 1; i <= nameNum; i++){
        int len = strList[i].length();
        strHash[i] = new int[len + 5];
        strHashNi[i] = new int[len + 5];
        strHash[i][0] = 0;
        strHashNi[i][0] = 0;
        for(j = 1; j <= len; j++){
            strHash[i][j] = (strHash[i][j - 1] * p + int(strList[i][j - 1])) % (base);
            strHashNi[i][j] = (strHashNi[i][j - 1] * p + int(strList[i][len - j])) % (base);
        }
        strHash[i][0] = len;
        strHashNi[i][0] = len;
    }
    cin >> oprNum;
    for(i = 0; i < oprNum; i++){
        cin >> oprType;
        if(oprType == 1){
            cin >> oprX;
            int flag = 0;
            for(j = 1; j < oprX; j++){
                if(strHash[j][strHash[j][0]] == strHash[oprX][strHash[oprX][0]]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                cout << "yes" << '\n';
            }
            else{
                cout << "no" << '\n';
            }
        }
        if(oprType == 2){
            cin >> oprX >> oprY;
            int len1 = strHash[oprX][0];
            int len2 = strHash[oprY][0];
            int minLen = minn(len1, len2);
            int num = bSearch(oprX, oprY, 1, minLen);
            cout << num << '\n';
        }
        if(oprType == 3){
            cin >> oprX >> oprY;
            int len1 = strHash[oprX][0];
            int len2 = strHash[oprY][0];
            int minLen = minn(len1, len2);
            int num = bSearchNi(oprX, oprY, 1, minLen);
            cout << num << '\n';
        }
    }
    /*
    for(i = 1; i <= nameNum; i++){
        cout << strHash[i][strHash[i][0]] << endl;;
    }
    */
    for(i = 1; i <= nameNum; i++){
        delete []strHash[i];
        delete []strHashNi[i];
    }
    
}

