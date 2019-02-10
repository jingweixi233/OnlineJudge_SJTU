#include <iostream>

using namespace std;

int main()
{
    int str[50];
    int k, i, j, num, tmp;
    double mid;
    
    for(i = 0 ; i < 50; i++){
        str[i] = -1;
    }
    
    while(true){
        k = 0;
        cin >> str[k];
        num = 1;
        if(cin.get() == EOF){
            break;
        }
        while(true){
            k = k + 1;
            cin >> str[k];
            num = num + 1;
            if(cin.get() == '\n'){
                break;
            }
            
        }
        for(i = 0; i < num; i++){
            for(j = 0; j < num - i - 1; j++){
                if(str[j] > str[j + 1]){
                    tmp = str[j];
                    str[j] = str[j + 1];
                    str[j + 1] = tmp;
                }
            }
        }
        if(num % 2 == 0){
            mid = (str[num / 2] + str[num / 2 - 1]) / 2.0;
        }
        else{
            mid = str[num / 2];
        }
        cout << mid << endl;
        
        
    }
    return 0;

}
