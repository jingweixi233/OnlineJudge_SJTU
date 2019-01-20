/*
dui da
int level[]
bool ques[]

dui
int curSize;
int dui[];

node{
    int id;
    int levelNum;
}
*/

#include <iostream>

using namespace std;

struct node{
    int id;
    int levelNum;
    node(int i = 0, int l = 0){
        id = i;
        levelNum = l;
    }
};
const int N = 1005;
int level[N];
bool inDui[N];

node dui[4 * N];
int friends[N][N];
int curSize = 0;

void pDown(){   
    int hole = 1;
    int child = hole * 2;
    if(child + 1 <= curSize && dui[child + 1].levelNum > dui[child].levelNum){
        child++;
    }
    int exId = dui[1].id;
    int exlev = dui[1].levelNum;
    while(child <= curSize && exlev < dui[child].levelNum){
        dui[hole] = dui[child];
        hole = child;
        child = hole * 2;
        if(child + 1 <= curSize && dui[child + 1].levelNum > dui[child].levelNum){
            child++;
        }
    }
    dui[hole].id = exId;
    dui[hole].levelNum = exlev;

}

void push(int idNode, int lev){
    int hole = curSize + 1;
    while(hole / 2 >= 1 && dui[hole / 2].levelNum < lev){
        dui[hole] = dui[hole / 2];
        hole = hole / 2;
    }
    dui[hole].id = idNode;
    dui[hole].levelNum = lev;
    curSize++;
}

int pop(){
    int x = dui[1].id;
    dui[1].id = dui[curSize].id;
    dui[1].levelNum = dui[curSize].levelNum;
    curSize--;
    pDown();
    return x;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int stuNum, inNum, inId;
    int i, j, k;
    
    cin >> stuNum >> inNum;
    for(i = 1; i <= stuNum; i++){
        cin >> level[i];
    }
    for(i = 1; i <= stuNum; i++){
        inDui[i] = false;
    }
    for(i = 1; i <= inNum; i++){
        cin >> inId;
        push(inId, level[inId]);
        inDui[inId] = true;
    }

    for(i = 1; i <= stuNum; i++){
        for(j = 1; j <= stuNum; j++){
            cin >> friends[i][j];
        }
    }
    
    for(i = 1; i <= stuNum; i++){
        /*
        cout << "********************" << '\n';
        for(k = 1; k <= 10; k++){
            cout << dui[k].id << " ";
        }
        cout << '\n';
        cout << "********************" << '\n';
        */
        int answer = pop();
        cout << answer << '\n';
        for(j = 1; j <= stuNum; j++){
            if(friends[answer][j] == 1 && inDui[j] == false){
                push(j, level[j]);
                inDui[j] = true;
            }
        }
    }
}