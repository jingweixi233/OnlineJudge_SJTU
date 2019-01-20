#include <iostream>

using namespace std;

const int N = 100000;

int num1[N];
int num2[N];
int arr[N];

int main(){
    int num1Len, num2Len;
    int i, j, k;
    cin >> num1Len >> num2Len;
    for(i = 1; i <= num1Len; i++){
        cin >> num1[i];
    }
    for(i = 1; i <= num2Len; i++){
        cin >> num2[i];
    }

    i = 1;
    j = 1;
    k = 1;
    while(i <= num1Len && j <= num2Len){
        if(num1[i] < num2[j]){
            arr[k] = num1[i];
            k++;
            i++;
        }
        else{
            arr[k] = num2[j];
            k++;
            j++;
        }
    }
    while(i <= num1Len){
        arr[k] = num1[i];
        k++;
        i++;
    }
    while(j <= num2Len){
        arr[k] = num2[j];
        k++;
        j++;
    }
    int sum = num1Len + num2Len;
    for(i = 1; i <= sum; i++){
        cout << arr[i] << " ";
    }

    
}

