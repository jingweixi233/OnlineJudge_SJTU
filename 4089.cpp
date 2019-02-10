
#include <stdio.h>
#include <iostream>

using namespace std;

class Joseph
{
private:
    int n;
    int m;
    int *people;
public:
    
    Joseph(int n0, int m0){
        int i;
        n = n0;
        m = m0;
        people = new int [n];
        for(i = 1; i <= n; i++){
            people[i - 1] = i;
        }
        
    }
    
    void simulate(){
        int i;
        int k;
        int num= n;
        i = 1;
        k = 1;
        while(num > 0){
            if(i >= n){
                i = 0;
            }
            if(people[i] == 0){
                i = i + 1;
                continue;
            }
            if(k % m == 0){
                cout << people[i] << " ";
                people[i] = 0;
                num = num - 1;
            }
            i = i + 1;
            k = k + 1;
        }
        
        
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Joseph obj(n, m);
    obj.simulate();
    
}
