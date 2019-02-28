#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;
int sta[N];
string da[N];
int top = -1, num = 0;

void push(int x){
    top++;
    sta[top] = x;
    num++;
}

int pop(){
    int ans = sta[top];
    top--;
    num--;
    return ans;
}

int main(){
    int stringNum;
    int i;
    int flag = -1;
    cin >> stringNum;
    
    for(i = 0; i < stringNum; i++){
        cin >> da[i];
    }

    for(i = 0; i < stringNum; i++){
        if(da[i][0] == 'b'){
            if(flag == 1){
                flag = 2;
            }
            if(sta[top] == 3){
                cout << "NO";
                return 0;
            }
            push(1);
        }

        if(da[i][0] == 'e' && da[i][1] == 'n'){
            if(flag == 2){
                flag = 1;
            }
            if(num == 0 || pop() != 1){
                cout << "NO";
                return 0;
            }
        }

        if(da[i][0] == 'i'){
            push(3);
        }

        if(da[i][0] == 't'){
            if(sta[top] == 3){
                flag = 1;
                pop();
            }
            else{
                cout << "NO";
                return 0;
            }
        }

        if(da[i][0] == 'e' && da[i][1] == 'l'){
            if(flag != 1){
                cout << "NO";
                return 0;
            }
            else{
                flag = 0;
            }
        }
    }

    if(num == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }



}