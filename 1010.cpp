#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int month_cost[12];
    int month_save, left, save, k, i, money, bate;
    
    for(i = 0; i < 12; i++){
        cin >> month_cost[i];
    }
    left = 0;
    save = 0;
    k = 1;
    
    for(i = 0; i < 12; i++){
        month_save = 300 + left - month_cost[i];
        if(month_save < 0){
            cout << -(i + 1) << endl;
            return 0;
        }
        else{
            bate = month_save / 100;
            if(bate == 0){
                left = 300 + left - month_cost[i];
                continue;
            }
            if(bate > 0){
                save = save + bate * 100;
                left = 300 + left - month_cost[i] - bate*100;
            }
        }

    }
    money = left + save * 1.2;
    cout << money << endl;
}
