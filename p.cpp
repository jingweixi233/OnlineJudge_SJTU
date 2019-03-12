#include <iostream>

using namespace std;

void shell_sort(int numbers[], int count){  //numbers[] is the array
    int i, j, h, temp;
    h = count / 2;
    while(h > 0){   //h_sort
        for(i = h; i < count; i++){
            temp = numbers[i];
            j = i; 
            while(j >= h && numbers[j - h] > temp){
                numbers[j] = numbers[j - h];
                j = j - h;
            }
            numbers[j] = temp;    
        }
        h = h / 2;                          //move to next increment
    }
    for(i = 0; i < count; i++){
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int main()
{
    int num[8] = {3, 1, 4, 2, 5, 7, 6, 0};
    shell_sort(num, 8);
}
