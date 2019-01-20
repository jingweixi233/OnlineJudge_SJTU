#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

int main(){
    long long int i, wait_time_tmp, wait_time1, last_time1, wait_time2, last_time2, min_time, max_time = 0, k, max_win = 0;
    long long int wait[3], last[3],time_press[3], N, num;
    long long int time[100010] = {0}, win1[33334] = {0}, win2[33334] = {0}, win3[33334] = {0}, win[3] = {0};
    
    cin >> N;
    num = N / 3 + 1;

    for(i = 1; i <= N; i++){
        cin >> time[i];
    }
    
    //1
    for(i = 0; i < num; i++){
        win1[i] = time[3 * i + 1];
        win2[i] = time[3 * i + 2];
        win3[i] = time[3 * i + 3];
    }
    
    for(i = 0; i < 3; i++){
        wait[i] = 0;
        last[i] = 0;
        time_press[i] = 0;
    }
    
    for(i = 0; i < num - 2; i++){
        time_press[0] = time_press[0] + win1[i];
        wait[0] = wait[0] + time_press[0];

        time_press[1] = time_press[1] + win2[i];
        wait[1] = wait[1] + time_press[1];

        time_press[2] = time_press[2] + win3[i];
        wait[2] = wait[2] + time_press[2];

    }
    if(win1[num - 1] != 0){
        time_press[0] = time_press[0] + win1[num - 2];
        
        wait[0] = wait[0] + time_press[0];
    }
    if(win2[num - 1] != 0){
        time_press[1] = time_press[1] + win2[num - 2];
        
        wait[1] = wait[1] + time_press[1];
    }
    if(win3[num - 1] != 0){
        time_press[2] = time_press[2] + win3[num - 2];
        
        wait[2] = wait[2] + time_press[2];
    }
    wait_time1 = 0;
    for(i = 0; i < 3; i++){
        wait_time1 = wait_time1 + wait[i];
    }
    for(i = 0; i < num; i++){
        last[0] = last[0] + win1[i];
        last[1] = last[1] + win2[i];
        last[2] = last[2] + win3[i];
    }
    for(i = 0; i < 3; i++){
        if(last[i] >= max_time){
            max_time = last[i];
        }
    }
    last_time1 = max_time;
    cout << wait_time1 << " " << last_time1 << endl;
    
    //2
    for(i = 0; i < 3; i++){
        win[i] =  0;
    }
    win[0] = time[1];
    win[1] = time[2];
    win[2] = time[3];
    max_win = 0;
    if(N <= 3){
        wait_time2 = 0;
        for(i = 0; i < 3; i++){
            if(win[i] >= max_win){
                max_win = win[i];
            }
        }
        last_time2 = max_win;
    }
    else{
        k = 3;
        wait_time2 = 0;
        last_time2 = 0;
        while(true){
            if(win[0] <= win[2]){
                if(win[0] <= win[1]){
                    min_time = win[0];
                }
                else{
                    min_time = win[1];
                }
            }
            else{
                if(win[2] <= win[1]){
                    min_time = win[2];
                }
                else{
                    min_time = win[1];
                }
            }
            for(i =0 ; i < 3; i++){
                win[i] = win[i] - min_time;
            }
            
            last_time2 = last_time2 + min_time;
            wait_time_tmp = last_time2;
            
            for(i = 0; i < 3 && k < N; i++){
                if(win[i] == 0){
                    k = k + 1;
                    win[i] = time[k];
                    wait_time2 = wait_time2 + wait_time_tmp;
                }
            }
            if(k == N){
                break;
            }
        }
        max_win = 0;
        for(i = 0; i < 3; i++){
            if(win[i] >= max_win){
                max_win = win[i];
            }
        }
        last_time2 = last_time2 + max_win;
        

    }
       cout << wait_time2 << " " << last_time2 << endl;

}
