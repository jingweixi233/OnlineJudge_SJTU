/*
N = 100005;
node [N]
int id[N];
node 
prev next data;
quick sort

*mid
shan
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100005;
struct node{
    int data;
    node *prev;
    node *next;
};
node nodeList[N];
int nodeNum[N];
int nodeId[N];
int nodeIdAddress[N];
int answer[N];
node *mid;

void quickSort(int l, int r){
    if(l < r){
        int i = l;
        int j = r;
        int x = nodeNum[l];
        int y = nodeIdAddress[l];
        while(i < j){
            while(i < j && nodeNum[j] > x){
                j--;
            }
            if(i < j){
                nodeNum[i] = nodeNum[j];
                nodeIdAddress[i] = nodeIdAddress[j];
                i++;
            }
            while(i < j && nodeNum[i] < x){
                i++;
            }
            if(i < j){
                nodeNum[j] = nodeNum[i];
                nodeIdAddress[j] = nodeIdAddress[i];
                j--;
            }
        }
        nodeNum[i] = x;
        nodeIdAddress[i] = y;
        quickSort(l, i - 1);
        quickSort(i + 1, r);
    }


}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int number;
    int i;
    cin >> number;
    for(i = 1; i <= number; i++){
        //cout << i << '\n';
        cin >> nodeNum[i];
    }

    for(i = 1; i <= number; i++){
        nodeIdAddress[i] = i;
    }

    
    if(number % 2 == 0){
        number = number - 1;
    }
    quickSort(1, number);

    for(i = 1; i <= number; i++){
        nodeId[nodeIdAddress[i]] = i;
    }
    /*
    for(i = 1; i <= number; i++){
        cout << nodeId[i] << " ";
    }
    */
    
    for(i = 1; i <= number; i++){
        nodeList[i].data = nodeNum[i];
        nodeList[i].prev = &nodeList[i - 1];
        nodeList[i].next = &nodeList[i + 1];
    }

    int midId = number / 2 + 1;
    mid = &nodeList[midId];
    int last = mid -> data;
    


    for(i = 0; i < midId - 1; i++){
        int id1 = number - 2 * i;
        int id2 = number - 2 * i - 1;
        int num1 = nodeNum[nodeId[id1]];
        int num2 = nodeNum[nodeId[id2]];
        
        
        if(num1 < mid -> data && num2 < mid -> data){

            nodeList[nodeId[id1]].prev -> next = nodeList[nodeId[id1]].next;
            nodeList[nodeId[id1]].next -> prev = nodeList[nodeId[id1]].prev;

            nodeList[nodeId[id2]].prev -> next = nodeList[nodeId[id2]].next;
            nodeList[nodeId[id2]].next -> prev = nodeList[nodeId[id2]].prev;
            mid = mid -> next;
        }
        else{
            if(num1 >= mid -> data && num2 >= mid -> data){
                mid = mid -> prev;

                nodeList[nodeId[id1]].prev -> next = nodeList[nodeId[id1]].next;
                nodeList[nodeId[id1]].next -> prev = nodeList[nodeId[id1]].prev;


                nodeList[nodeId[id2]].prev -> next = nodeList[nodeId[id2]].next;
                nodeList[nodeId[id2]].next -> prev = nodeList[nodeId[id2]].prev;
                
            }
            else{
                if(mid == &nodeList[nodeId[id1]]){
                    mid = mid -> next; 
                }
                nodeList[nodeId[id1]].prev -> next = nodeList[nodeId[id1]].next;
                nodeList[nodeId[id1]].next -> prev = nodeList[nodeId[id1]].prev;

                if(mid == &nodeList[nodeId[id2]]){
                    mid = mid -> next; 
                }
                nodeList[nodeId[id2]].prev -> next = nodeList[nodeId[id2]].next;
                nodeList[nodeId[id2]].next -> prev = nodeList[nodeId[id2]].prev;
            }
        }

        //cout << mid -> data << '\n';
        answer[i] = mid -> data;
    }

    for(i = midId - 2; i >= 0; i--){
        cout << answer[i] << '\n';
    }
    cout << last << '\n';

    
}