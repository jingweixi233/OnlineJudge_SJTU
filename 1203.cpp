#include <stdio.h>
#include <iostream>
#include <cstring>
#include <limits.h>

using namespace std;

template<class elemType>
class list
{
public:
    virtual void clear() = 0;            //clear all elements in list
    virtual int length()const = 0;       //get the length of list
    virtual void insert(int i, const elemType &x) = 0;  //insert an element in list
    virtual void remove(int i) = 0;       //remove an list in list
    virtual int search(const elemType &x)const = 0;     //search the element
    virtual elemType visit(int i)const = 0;             //visit the element
    virtual void traverse()const = 0;    //visit every element in list
    virtual ~list(){};
};


template <class elemType>
class seqList:public list<elemType>
{
private:
    elemType *data;                     //seqlist--data
    int currentLength;                  //current length of seqlist
    int maxSize;                        //max size of seqlist
    void doubleSpace(){
        int i;
        elemType *tmp = data;
        maxSize = maxSize * 2;
        data = new elemType[maxSize];
        for(i = 0; i < currentLength; i++){
            data[i] = tmp[i];
        }
        delete []tmp;
    }
    
public:
    seqList(int initSize = 10){
        maxSize = initSize;
        data = new elemType[maxSize];
        currentLength = 0;
    }
    
    seqList(const seqList &obj){
        int i;
        maxSize = obj.maxSize;
        data = new elemType[obj.maxSize];
        for(i = 0; i < obj.currentLength; i++){
            data[i] = obj.data[i];
        }
        currentLength = obj.currentLength;
    }
    
    ~seqList(){
        delete []data;
    }
    
    void clear(){
        currentLength = 0;
    }
    
    int length()const{
        return currentLength;
    }

    void insert(int i, const elemType &x){
        int j;
        if(currentLength == maxSize){
            doubleSpace();
        }
        else{
            for(j = currentLength; j > i; j--){
                data[j] = data[j - 1];
            }
            data[i] = x;
        }
        currentLength = currentLength + 1;
    }
    
    void remove(int i){
        int j;
        for(j = i; j < currentLength - 1; j++){
            data[j] = data[j + 1];
        }
        currentLength = currentLength - 1;
    }
    
    int search(const elemType &x)const{
        int i;
        for(i = 0; i < currentLength && data[i] != x; i++);
        if(i == currentLength){
            return -1;
        }
        else{
            return i;
        }
    }
    
    elemType visit(int i) const{
        return data[i];
    }
    
    void traverse() const{
        int i;
        for(i = 0; i < currentLength; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
    
    seqList<elemType> operator=(const seqList<elemType> &obj){
        int i;
        delete []data;
        maxSize = obj.maxSize;
        data = new elemType[obj.maxSize];
        for(i = 0; i < obj.currentLength; i++){
            data[i] = obj.data[i];
        }
        currentLength = obj.currentLength;
        return *this;
    }
    
    seqList<elemType> operator+(seqList<elemType> &obj){
        int i;
        this -> maxSize = this -> maxSize + obj.maxSize;
        int size = this -> currentLength;
        elemType *tmp = this -> data;
        data = new elemType[maxSize];
        for(i = 0; i < this -> currentLength; i++){
            data[i] = tmp[i];
        }
        for(i = 0; i < obj.currentLength; i++){
            data[i + size] = obj.data[i];
        }
        currentLength = currentLength + obj.currentLength;
        delete []tmp;
        return *this;
    }
};

int main(){
    int i, size1, size2, typeNum = 0;
    char type[10];
    string typeList[3] = {"int", "char" ,"double"};
    
    for(i = 0; i < 10; i++){
        type[i] = '\0';
    }
    cin.getline(type, 10, '\n');
    
    for(i = 0; i < 3; i++){
        if(type == typeList[i]){
            typeNum = i;
        }
    }
    cin >> size1;
    cin >> size2;
    switch(typeNum){
        case(0):{
            int element;
            seqList<int> a(size1);
            seqList<int> b(size2);
            seqList<int> c;
            for(i = 0; i < size1; i++){
                cin >> element;
                a.insert(i, element);
            }
            for(i = 0; i < size2; i++){
                cin >> element;
                b.insert(i, element);
            }
   
            c = a + b;
            c.traverse();
            break;}
        case(1):{
            char element;
            seqList<char> a(size1);
            seqList<char> b(size2);
            seqList<char> c;
            for(i = 0; i < size1; i++){
                cin >> element;
                a.insert(i, element);
            }
            for(i = 0; i < size2; i++){
                cin >> element;
                b.insert(i, element);
            }
            c = a + b;
            c.traverse();
            break;}
        case(2):{
            double element;
            seqList<double> a(size1);
            seqList<double> b(size2);
            seqList<double> c;
            for(i = 0; i < size1; i++){
                cin >> element;
                a.insert(i, element);
            }
            for(i = 0; i < size2; i++){
                cin >> element;
                b.insert(i, element);
            }
            c = a + b;
            c.traverse();
            break;}
    }
}


























