#include <iostream>

using namespace std;

class Time
{
    friend istream &operator>>(istream &is, Time &obj);
    friend ostream &operator<<(ostream &os, Time &obj);
protected:
    int hour;
    int minute;
    int second;
public:
    
    Time &operator+=(const Time &obj){
        hour = hour + obj.hour;
        minute = minute + obj.minute;
        second = second + obj.second;
        if(second >= 60){
            second = second - 60;
            minute = minute + 1;
        }
        if(minute >= 60){
            minute = minute - 60;
            hour = hour + 1;
        }
        if(hour >= 24){
            hour = hour - 24;
        }
        return *this;
    }
    
    Time &operator-=(const Time &obj){
        hour = hour - obj.hour;
        minute = minute - obj.minute;
        second = second - obj.second;
        if(second < 0)
        {
            second = second + 60;
            minute = minute - 1;
        }
        if(minute < 0){
            minute = minute + 60;
            hour = hour - 1;
        }
        if(hour < 0){
            hour = hour + 24;
        }
        return *this;
    }
    
    Time &operator++(){
        second = second + 1;
        if(second >= 60){
            second = second - 60;
            minute = minute + 1;
        }
        if(minute >= 60){
            minute = minute - 60;
            hour = hour + 1;
        }
        if(hour >= 24){
            hour = hour -24;
            
        }
        return *this;
    }
    
    Time operator++(int){
        Time tmp;
        tmp = *this;
        second = second + 1;
        if(second >= 60){
            second = second - 60;
            minute = minute + 1;
        }
        if(minute >= 60){
            minute = minute - 60;
            hour = hour + 1;
        }
        if(hour >= 24){
            hour = hour -24;
            
        }
        return tmp;
        
    }
    
    Time &operator--(){
        second = second - 1;
        if(second < 0){
            second = second + 60;
            minute = minute - 1;
        }
        if(minute < 0){
            minute = minute + 60;
            hour = hour - 1;
        }
        if(hour < 0){
            hour = hour + 24;
            
        }
        return *this;
    }
    
    Time operator--(int){
        Time tmp;
        tmp = *this;
        second = second - 1;
        if(second < 0){
            second = second + 60;
            minute = minute - 1;
        }
        if(minute < 0){
            minute = minute + 60;
            hour = hour - 1;
        }
        if(hour < 0){
            hour = hour + 24;
            
        }
        return tmp;
    }
    
};

istream &operator>>(istream &is, Time &obj){
    is >> obj.hour >> obj.minute >> obj.second;
    return is;
}

ostream &operator<<(ostream &os, Time &obj){
    if(obj.hour < 10){
        os << '0' << obj.hour << ":";
    }
    else{
        os << obj.hour << ":";
        
    }
    if(obj.minute < 10){
        os << '0' << obj.minute << ":";
        
    }
    else{
        os << obj.minute << ":";
    }
    if(obj.second < 10){
        os << '0' << obj.second ;
        
    }
    else{
        os << obj.second;
    }
    return os;
}

int main()
{
    Time time1;
    Time time2;
    cin >> time1;
    cin >> time2;
    time1 += (time2++);
    cout << time1 << endl;
    time1 -= time2;
    cout << time1 << endl;
    cout << (++time2) << endl;
    time2 += (time1--);
    cout << time2 << endl;
    cout << (--time1) << endl;
    time2 -= time1;
    cout << time2 << endl;
    
}
