/*
int node[N];
node[N] = fu
for(i = node[x]; i >= 1; i = node[i]){
    for(j = node[y]; j >= 1; j++){
        if()flag = 1;
        break
    }

}
*/
#include <iostream>

using namespace std;
const int N = 100000;
int node[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num, nodeA, nodeB;
    int i, j, childL, childR;
    int flag = 0;
    for(i = 0; i < N; i++){
        node[i] = 0; 
    }
    cin >> num >> nodeA >> nodeB;
    for(i = 1; i <= num; i++){
        cin >> childL >> childR;
        node[childL] = i;
        node[childR] = i;
    }

    for(i = node[nodeA]; i > 0; i = node[i]){
        for(j = node[nodeB]; j > 0; j = node[j]){
            if(i == j){
                flag = 1;
            }
        }
        if(flag == 1){
            break;
        }
    }
    cout << i;
}
