#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int N, Q, A, B;
    int i, j, k, max, water, max_left = 0, max_right = 0;
    int *h;
    
    cin >> N >> Q;
    h = new int[N + 1];
    for(i = 0; i < N + 1; i++)
    {
        h[i] = 0;
    }
    
    for(i = 1; i < N + 1; i++){
        cin >> h[i];
    }
    
    
    
    for(i = 0; i < Q; i++){
        water = 0;
        cin >> A >> B;
        
        if(A == B || A == B - 1){
            cout << 0 << endl;
        }
        else{
            j = A + 1;
            max_left = 0;
            max_right = 0;
            for(k = A; k < j; k++){
                if(h[k] > max_left){
                    max_left = h[k];
                }
            }
            
            for(k = j + 1; k <= B; k++){
                if(h[k] > max_right){
                    max_right = h[k];
                }
            }

            while(j < B){
                if(max_left <= h[j - 1]){
                    max_left = h[j - 1];
                }
                if(max_right == h[j]){
                    max_right = 0;
                    for(k = j + 1; k <= B; k++){
                        if(h[k] > max_right){
                            max_right = h[k];
                        }
                    }
                }
                if(max_left >= max_right){
                    max = max_right;
                }
                else{
                    max = max_left;
                }
                
                if(h[j] <= max){
                    water = water + max - h[j];
                }
                
                j = j + 1;
            }
            cout << water << endl;
            
        }
     
    }
    
  
    
    return 0;
    
}
