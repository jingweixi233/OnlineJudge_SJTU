#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char date_old[10], year_o[5], month_o[3], day_o[3];
    int n, i, num, k;
    int year_old, month_old, day_old;
    int year, month, day;
    int run[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int pin[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for(i = 0; i < 10; i++){
        date_old[i] = '\0';
        
    }
    
    for(i = 0; i < 5; i++){
        year_o[i] = '\0';
    }
    
    for(i = 0; i < 3; i++){
        month_o[i] = '\0';
        day_o[i] = '\0';
    }
    
    cin.getline(date_old, 10, ' ');
    cin >> n;
    
    for(i = 0; i < 4; i++){
        year_o[i] = date_old[i];
    }
    sscanf(year_o, "%d", &year_old);
    
    for(i = 0; i < 2; i++){
        month_o[i] = date_old[4 + i];
    }
    sscanf(month_o, "%d", &month_old);
    
    for(i = 0; i < 2; i++){
        day_o[i] = date_old[6 + i];
    }
    sscanf(day_o, "%d", &day_old);
    
    //cout << year_old << endl << month_old << endl << day_old << endl;
    
    year = year_old;
    while(n >= 366){
        if(month_old <= 2){
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
                n = n - 366;
            }
            else{
                n = n - 365;
            }
            year = year + 1;
        }
        else{
            year = year + 1;
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
                n = n - 366;
            }
            else{
                n = n - 365;
            }
        }
    }
    
    month = month_old;
    while(n >= 31){
        if(month > 12){
            month = 1;
            year = year + 1;
        }
        if(month <= 2){
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
                n = n - run[month - 1];
                month = month + 1;
            }
            else{
                n = n - pin[month - 1];
                month = month + 1;
            }
            
        }
        else{
            n = n - pin[month - 1];
            month = month + 1;
        }
        
    }
    
    day = day_old;
    if(month == 2){
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
            if(n + day > 29){
                day = n + day - 28;
                month = month + 1;
            }
            else{
                day = day + n;
            }
        }
        else{
            if(n + day > 28){
                day = n + day - 29;
                month = month + 1;
            }
            else{
                day = day + n;
            }
        }
        
    }
    else{
        if(month == 12)
        {
            if(n + day > 31){
                day = n + day - 31;
                month = 1;
                year = year + 1;
            }
            else{
                day = n + day;
            }
        }
        else{
            if(n + day > pin[month - 1]){
                day = day + n - pin[month - 1];
                month = month + 1;
            }
            else{
                day = day + n;
            }
        }
        
        
    }
    
    if(year > 9999){
        cout << "out of limitation!";
    }
    else
    {
        cout << setfill('0') << setw(4) << year;
        cout << setfill('0') << setw(2) << month;
        cout << setfill('0') << setw(2) << day;
    
    }
    return 0;
    

}
