#include <iostream>

using namespace std;

int main()
{
    char **list;
    int i;
    
    list = new char *[32];
    for(i = 0; i < 32; i++){
        list[i] = new char [32];
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    for(i = 0; i < 32; i++){
        delete []list[i];
    }
    delete [] list;
    return 0;
}
