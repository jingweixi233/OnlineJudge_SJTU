#include <iostream>

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
        cout << endl;
        for(i = 0; i < currentLength; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
