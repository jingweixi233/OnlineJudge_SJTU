#include <iostream>

using namespace std;

struct node{
    int id;
    int love;
};

const int N = 2000005;
const int MIN = 1 << 31;

node nodeList[N];
int nodeId[N];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int nodeNum, oprNum;
    int nodeLove;
    int x, y, i;
    cin >> nodeNum >> oprNum;

    for(i = 1; i <= nodeNum; i++){
        cin >> nodeLove;
        nodeList[i].id = i;
        nodeList[i].love = nodeLove;
        nodeId[i] = i;
    }
    nodeList[0].love = MIN;
    nodeList[nodeNum + 1].love = MIN - 1;
    for(i = 0; i < oprNum; i++){
        cin >> x >> y;
        if(y > 0){
            int move = nodeId[x];
            nodeList[move].love++;
            while(nodeList[move].love > nodeList[move + 1].love){
                nodeId[nodeList[move].id] = move + 1;
                nodeId[nodeList[move + 1].id] = move;
                node tmp = nodeList[move];
                nodeList[move] = nodeList[move + 1];
                nodeList[move + 1] = tmp;
                move++;
            }
        }
        else{
            int move = nodeId[x];
            nodeList[move].love--;
            while(nodeList[move].love <= nodeList[move - 1].love){
                nodeId[nodeList[move].id] = move - 1;
                nodeId[nodeList[move - 1].id] = move;
                node tmp = nodeList[move];
                nodeList[move] = nodeList[move - 1];
                nodeList[move - 1] = tmp;
                move--;
            }
        }
        cout << nodeList[1].id << '\n';
    }
    
    
}