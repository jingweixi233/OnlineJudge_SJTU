#include <iostream>

using namespace std;

int main()
{
    int n, i, j, tmp, sum;
    int *time;
    cin >> n;
    time = new int[n];
    
    for(i = 0; i < n; i++){
        cin >> time[i];
    }
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n - i - 1; j++){
            if(time[j] > time[j + 1]){
                tmp = time[j];
                time[j] = time[j + 1];
                time[j + 1] = tmp;
            }
        }
    }
    sum = 0;
    if(n <= 3){
        if(n == 3){
            for(i = 0; i < n; i++){
                sum = sum + time[i];
            }
            
        }
        if(n == 1){
            sum = time[0];
        }
        if(n == 2){
            sum = time[1];
        }


    }
    else{
        if(n % 2 == 0){
            for(i = 3; i < n; i = i + 2){
                sum = sum + time[i] +  time[0] + 2 * time[1];
            
            }
            sum = sum + time[1];
        }
        
        if(n % 2 != 0){
            for(i = 4; i < n; i = i+ 2 ){
                sum = sum + time[i] + time[0] + 2 * time[1];
                
            }
            sum = sum + time[0] + time[1] + time[2];
        }
        
        
    }
    
    cout << sum;

    
    delete []time;
    
}
