#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Package
{
public:
    char name[21];
    char address[52];
    char postalcode[7];
    char telephone[15];
    double weight;
    double cost;
    int type;
    
    Package(){
        int i;
        for(i = 0; i < 21; i++){
            name[i] = '\0';
        }
        for(i = 0; i < 52; i++){
            address[i] = '\0';
        }
        for(i = 0; i < 7; i++){
            postalcode[i] = '\0';
        }
        for(i = 0; i < 15; i++){
            telephone[i] = '\0';
        }
        weight = 0;
        cost = 0;

    }
    
    double calculateCost(){
        double sum;
        sum = cost * weight;
        return sum;
    }
    virtual void display(){
        cout << name << " ";
        cout << address << " ";
        cout << postalcode << " ";
        cout << telephone << " ";
        

    
    }
    
};

class TwoDayPackage:public Package
{
public:
    double bonus;
    TwoDayPackage():Package()
    {
        bonus = 0;
    }
    double calculateCost(){
        double sum;
        sum = weight * cost + bonus;
        return sum;
    }
    void display(){
        cout << name << " ";
        cout << address << " ";
        cout << postalcode << " ";
        cout << telephone << " ";
        cout << "TwoDayPackage" << " ";
        
        
    }
};

class OvernightPackage:public Package
{
public:
    double bonus;
    OvernightPackage():Package()
    {
        bonus = 0;
    }
    double calculateCost(){
        double sum;
        sum = weight * (cost + bonus);
        return sum;
    }
    void display(){
        cout << name << " ";
        cout << address << " ";
        cout << postalcode << " ";
        cout << telephone << " ";
        cout << "OvernightPackage" << " ";
    }
};

int main()
{
    int n;
    char name0[21];
    char address0[52];
    char postalcode0[7];
    char telephone0[15];
    double weight0;
    double cost0;
    int type0;
    double bonus0;
    double sum;
    
    int i;
    for(i = 0; i < 21; i++){
        name0[i] = '\0';
    }
    for(i = 0; i < 52; i++){
        address0[i] = '\0';
    }
    for(i = 0; i < 7; i++){
        postalcode0[i] = '\0';
    }
    for(i = 0; i < 15; i++){
        telephone0[i] = '\0';
    }
    weight0 = 0;
    cost0 = 0;
    bonus0 = 0;
    type0 = 0;
    
    
    
    cin >> n;
    
    
    for(i = 0; i < n; i++){
        cin.ignore();
        cin.getline(name0, 21, ' ');
        cin.getline(address0, 52, ' ');
        cin.getline(postalcode0, 7, ' ');
        cin.getline(telephone0, 15, ' ');
        cin >> weight0;
        cin >> cost0;
        cin >> type0;
        cin >> bonus0;
        
        
        if(type0 == 1){
            TwoDayPackage *p;
            p = new TwoDayPackage;
            strcpy((*p).name, name0);
            strcpy((*p).address, address0);
            strcpy((*p).postalcode, postalcode0);
            strcpy((*p).telephone, telephone0);
            (*p).weight = weight0;
            (*p).cost = cost0;
            (*p).type = type0;
            (*p).bonus = bonus0;
            sum = (*p).calculateCost();
            (*p).display();
            cout <<fixed << setprecision(1) << sum << endl;
        }
        else{
            OvernightPackage *p;
            p = new OvernightPackage;
            strcpy((*p).name, name0);
            strcpy((*p).address, address0);
            strcpy((*p).postalcode, postalcode0);
            strcpy((*p).telephone, telephone0);
            (*p).weight = weight0;
            (*p).cost = cost0;
            (*p).type = type0;
            (*p).bonus = bonus0;
            sum = (*p).calculateCost();
            (*p).display();
            cout << fixed << setprecision(1) << sum << endl;
        }
        

        
    }
    return 0;
    
    
}
