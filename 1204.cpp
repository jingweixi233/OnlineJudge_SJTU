#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

class edit{
public:
    char **file;
    int row;
    
    edit(){
        int i, j;
        file = new char*[105];
        for(i = 0; i < 105; i++){
            file[i] = new char[2100];
        }
        for(i = 0; i < 105; i++){
            for(j = 0; j < 2100; j++){
                file[i][j] = '\0';
            }
        }
    }
    
    ~edit(){
        int i;
        for(i = 0; i < 105; i++){
            delete []file[i];
        }
        delete []file;
        
    }
    
    void list(int n1, int n2){
        int i;
        if((n1 < 1) || (n1 > row) || (n2 < 1) || (n2 > row) || (n2 < n1)){
            cout << "Error!" << endl;
            return;
        }
        for(i = n1 - 1; i < n2; i++){
            cout << file[i] << endl;
        }
    }
    
    void ins(int ini, int inj, char *str, int len){
        int i, j;
        if((ini < 1) || (ini > row) || (inj < 1) || (inj > strlen(file[ini - 1]) + 1)){
            cout << "Error!" << endl;
            return;
        }
        
        for(i = strlen(file[ini - 1]) + len - 1; i >= inj + len - 1; i--){
            file[ini - 1][i] = file[ini - 1][i - len];
        }
        
        for(j = 0; j < len; j++){
            file[ini - 1][inj - 1 + j] = str[j];
        }
    }
    
    void del(int di, int dj, int num){
        int i, j, length;
        if((di < 1) || (di > row) || (dj < 1) || (dj > strlen(file[di - 1])) || (dj + num > strlen(file[di - 1]) + 1)){
            cout << "Error!" << endl;
            return;
        }
        length = strlen(file[di - 1]);
        for(i = dj - 1; i < length; i++){
            file[di - 1][i] = file[di - 1][i + num];
        }
    }
    
    void quit()
    {
        int i;
        for(i = 0; i < row; i++){
            cout << file[i] << endl;
        }
    }
    
};
int main(){
    int i, k, lineLen, insStrLen;
    int listN1, listN2;
    int insI, insJ;
    int delI, delJ, delNum;
    char insStr[100];
    char cinLine[2100], cinType[5];
    edit ed;
    
    for(i = 0; i < 100; i++){
        insStr[i] = '\0';
    }
    for(i = 0; i < 2100; i++){
        cinLine[i] = '\0';
    }
    for(i = 0; i < 5; i++){
        cinType[i] = '\0';
    }
    k = 0;
    cin.getline(cinLine, 2005, '\n');
    lineLen = strlen(cinLine);
    while(strcmp(cinLine, "******") != 0){
        for(i = 0; i < lineLen + 5; i++){
            ed.file[k][i] = cinLine[i];
            cinLine[i] = '\0';
        }
        cin.getline(cinLine, 2005, '\n');
        lineLen = strlen(cinLine);
        k = k + 1;
    }
    
    ed.row = k;
    while(true){
        cin.getline(cinType, 5, ' ');
        
        if(strcmp(cinType,"list") == 0){
            cin >> listN1;
            cin >> listN2;
            ed.list(listN1, listN2);
            cin.ignore();
        }
        
        if(strcmp(cinType,"ins") == 0){
            cin >> insI;
            cin >> insJ;
            cin.ignore();
            cin.getline(insStr, 100, '\n');
            insStrLen = strlen(insStr);
            ed.ins(insI, insJ, insStr, insStrLen);
        }
        
        if(strcmp(cinType,"del") == 0){
            cin >> delI;
            cin >> delJ;
            cin >> delNum;
            ed.del(delI, delJ, delNum);
            cin.ignore();
        }
        
        if(strcmp(cinType,"quit") == 0){
            ed.quit();
            break;
        }
    }
}
