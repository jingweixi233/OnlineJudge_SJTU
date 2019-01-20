#include <iostream>

using namespace std;

const int nodeN = 10005;
const int Len = 100005;

struct node{
    int x;
    int y;
    int val;
    node(int xx, int yy, int value){
        x = xx;
        y = yy;
        val = value;
    }
};

int xId[Len];
int yId[Len];
node *nodeList[nodeN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i, j, pointx, pointy, num;
    int nodeNum, oprNum, oprType;
    for(i = 0; i < Len; i++){
        xId[i] = i;
        yId[i] = i;
    }
    cin >> nodeNum;
    for(i = 0; i < nodeNum; i++){
        cin >> pointx >> pointy >> num;
        nodeList[i] = new node(pointx, pointy, num);
    }
    cin >> oprNum;
    for(i = 0; i < oprNum; i++){
        cin >> oprType >> pointx >> pointy;
        if(oprType == 0){
            int tmp = xId[pointx];
            xId[pointx] = xId[pointy];
            xId[pointy] = tmp;
        }
        if(oprType == 1){
            int tmp = yId[pointx];
            yId[pointx] = yId[pointy];
            yId[pointy] = tmp;
        }
        if(oprType == 2){
            int flag = 0;
            int pointxId = xId[pointx];
            int pointyId = yId[pointy];
            for(j = 0; j < nodeNum; j++){
                if(nodeList[j] -> x == pointxId){
                    if(nodeList[j] -> y == pointyId){
                        cout << nodeList[j] -> val << '\n';
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 0){
                cout << 0 << '\n';
            }
        }
        
    }
    for(i = 0; i < nodeNum; i++){
        delete nodeList[i];
    }
}













