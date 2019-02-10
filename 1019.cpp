/*
stack sta[]
string line[]
for(linenum){
    flag = 1;
    for(){
        if("("){
            push 1
        }
        else{
            if(pop == 1 && sum != 0){
                continue;
            }
            else{
                flag = 0;
                break;

            }
        }
    }
    if(flag == 1){
        
    }
}
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000;
int stack[N];
int top = -1, sum = 0;
string line[55];

void push(int x){
    top++;
    stack[top] = x;
    sum++;
}
int pop(){
    int s = stack[top];
    top--;
    sum--;
    return s;
}

int main(){
    int i, j, lineNum, lineLen, flag;
    cin >> lineNum;
    for(i = 0; i < lineNum; i++){
        cin >> line[i];
    }
    for(i = 0; i < lineNum; i++){
        lineLen = line[i].length();
        flag = 1;
        for(j = 0; j < lineLen; j++){
            if(line[i][j] == '('){
                push(1);
            }
            else{
                if(sum == 0 ||  pop() != 1){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1 && sum == 0){
            cout << "YES" << endl;
        }   
        else{
            cout << "NO" << endl;
        }    
        sum = 0;
        top = -1; 
    }
}
