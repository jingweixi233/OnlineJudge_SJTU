#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 30;
int maxId = 0;
char pre[N];
char mid[N];
char trees[1005];

void buildTree(char node, int id, int preStart, int preEnd, int midStart, int midEnd){
    

    int index = -1, i;
    if((preStart > preEnd) || (midStart > midEnd)){
        return;
    }
    else{
        if(id >= maxId){
            maxId = id;
        }
        trees[id] = node;
        for(i = midStart; i <= midEnd; i++){
            if(mid[i] == node){
                index = i;
                break;
            }
        }
        buildTree(pre[preStart + 1], id * 2 + 1, preStart + 1, preStart + (index - midStart), midStart, index - 1);
        buildTree(pre[preStart + (index - midStart) + 1], id * 2 + 2, preStart + (index - midStart) + 1, preEnd, index + 1, midEnd);
    }
}

int main(){
    
    int i;
    for(i =0 ; i < N; i++){
        pre[i] = '\0';
        mid[i] = '\0';
    }
    for(i = 0; i < 1005; i++){
        trees[i] = '0';
    }
    cin.getline(pre, N, '\n');
    cin.getline(mid, N, '\n');

    int preLength = strlen(pre);
    trees[0] = pre[0];
    buildTree(pre[0], 0, 0, preLength - 1, 0, preLength - 1);

    for(i = 0; i <= maxId; i++){
        if(trees[i] == '0'){
            cout << "NULL" << ' ';
        }
        else{
            cout << trees[i] << ' ';
        }
    }
}



