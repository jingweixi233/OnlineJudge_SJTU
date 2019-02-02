/*
N = 10005;
tradeTime[55]
tradeNum[55];
tradeType[]
valueTime[N]
value[]
sum= 0
for(){
    time answer
    sum+-
}
*/
#include <iostream>
#include <iomanip>

using namespace std;

const int N = 10005;
int tradeTime[55];
int tradeNum[55];
int tradeType[55];
int valueTime[N];
int value[N];

int main(){
    int trade, valNum;
    double sum = 0;
    int i, k = 0;
    cin >> trade;
    for(i = 0; i < trade; i++){
        cin >> tradeTime[i];
        cin >> tradeNum[i];
        cin >> tradeType[i];
    }

    cin >> valNum;
    for(i = 0; i < valNum; i++){
        cin >> valueTime[i];
        cin >> value[i];
    }

    for(i = 0; i < trade; i++){
        k = 0;
        while(tradeTime[i] >= valueTime[k + 1] && k < valNum - 1){
            k++;
        }
        
        if(tradeType[i] == 1){
            double employMoney = tradeNum[i] * value[k] * 0.2;
            double passMoney = tradeNum[i] * 0.1;
            double commuMoney = 1;
            if(employMoney <= 5){
                employMoney = 5;
            }
            sum = sum - tradeNum[i] * value[k] * 100 - employMoney - passMoney - commuMoney;
        }
        else{
            double employMoney = tradeNum[i] * value[k] * 0.2;
            double passMoney = tradeNum[i] * 0.1;
            double commuMoney = 1;
            double tax = tradeNum[i] * value[k] * 0.1;
            if(employMoney <= 5){
                employMoney = 5;
            }
            sum = sum + tradeNum[i] * value[k] * 100 - employMoney - passMoney - commuMoney - tax;
        }
    }
    
    cout << fixed << setprecision(2) << sum << endl;
}


