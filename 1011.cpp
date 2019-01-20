#include <iostream>
#include <iomanip>

using namespace std;

class MyComplex
{
private:
    double x,y;
public:
    MyComplex(double xx = 0, double yy = 0){
        x = xx;
        y = yy;
    }
    
    
    friend MyComplex operator+(const MyComplex &a, const MyComplex &b){
        MyComplex c;
        c.x = a.x + b.x;
        c.y = a.y + b.y;
        return c;
    }
    
    friend MyComplex operator-(const MyComplex &a, const MyComplex &b){
        MyComplex c;
        c.x = a.x - b.x;
        c.y = a.y - b.y;
        return c;
    }
    
    friend MyComplex operator*(const MyComplex &a, const MyComplex &b){
        MyComplex c;
        c.x = (a.x * b.x) - (a.y * b.y);
        c.y = (a.y * b.x) + (a.x * b.y);
        return c;
    }
    
    friend MyComplex operator/(const MyComplex &a, const MyComplex &b){
        MyComplex c;
        c.x = ((a.x * b.x) + (a.y * b.y)) / (b.x * b.x + b.y * b.y);
        c.y = ((a.y * b.x) - (a.x * b.y)) / (b.x * b.x + b.y * b.y);
        return c;
    }
    
    MyComplex operator+=(const MyComplex &obj){
        x = x + obj.x;
        y = y + obj.y;
        return *this;
    }

    MyComplex operator-=(const MyComplex &obj){
        x = x - obj.x;
        y = y - obj.y;
        return *this;
    }
    
    MyComplex operator*=(const MyComplex &obj){
        double ax = x, ay = y, bx = obj.x, by = obj.y;
        x = (ax * bx) - (ay * by);
        y = (ay * bx) + (ax * by);
        return *this;
    }
    
    MyComplex operator/=(const MyComplex &obj){
        double ax = x, ay = y, bx = obj.x, by = obj.y;
        x = ((ax * bx) + (ay * by)) / (bx * bx + by * by);
        y = ((ay * bx) - (ax * by)) / (bx * bx + by * by);
        return *this;
    }
    friend istream &operator>>(istream &is, MyComplex &obj){
        is >> obj.x;
        is >> obj.y;
        return is;
    }
    
    friend ostream &operator<<(ostream &os, const MyComplex &obj){
        os << fixed << setprecision(2) << obj.x << ' ' << obj.y;
        return os;
    }
};

int main()
{
    MyComplex z1;
    MyComplex z2;
    
    cin >> z1 >> z2;
    
    
    cout << z1 + z2 <<endl;
    cout << z1 - z2 <<endl;
    cout << z1 * z2 <<endl;
    cout << z1 / z2 <<endl;
    cout << (z1 += z2) <<endl;
    cout << (z1 -= z2) <<endl;
    cout << (z1 *= z2) <<endl;
    cout << (z1 /= z2) <<endl;
    
    return 0;
}
