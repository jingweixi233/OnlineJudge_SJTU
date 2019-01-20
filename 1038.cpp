#include <stdio.h>
#include <iostream>
#include <cstring>


using namespace std;

template<class elemType>
class circleLinkList{
private:
    struct node{
        elemType data;
        node *next;
        node *prev;
        node(const elemType &x, node *n = NULL){
            data = x;
            next = n;
        }
        
        node():next(NULL){}
        ~node(){}
    };
    
    node *head;
    node *tmp;
    int currentLength;
    
public:
    circleLinkList(){
        head = new node;
        head -> data = 0;
        head -> prev = head;
        head -> next = head;
        currentLength = 0;
        
    }
    circleLinkList(int n){
        int k = 1;
        head = new node;
        head -> data = k;
        head -> next = head;
        node *p, *q;
        p = head;
        k = 2;
        while(k <= n){
            q = new node(k);
            q -> next = head;
            head -> prev = q;
            p -> next = q;
            q -> prev = p;
            p = q;
            k = k + 1;
        }
        currentLength = n;

        
    }
    
    ~circleLinkList(){
        clear();
        delete head;
    }
    
    void clear(){
        node *p, *q;
        p = head;
        head -> next = NULL;
        while(p != head){
            q = p;
            p = p -> next;
            delete q;
        }
        currentLength = 0;
    }
    
    int length()const{
        return currentLength;
    }
    void remove(){
        node *q = tmp;
        if(q == head){
            head = head -> next;
        }
        q -> prev -> next = q -> next;
        q -> next -> prev = q -> prev;
        delete q;
        currentLength = currentLength - 1;
    }
    
    void loop(long long int num, long long int *kn){
        int i;
        long long int j, k;
        tmp = head;
        k = 0;
        for(i = 0; i < num - 1; i++){
            for(j = 0; j < kn[k] - 1; j++){
                tmp = tmp -> next;
            }
            remove();
            tmp = tmp -> next;
            k = k + 1;
        }
        cout << head -> data << '\n';
    }

};

int main(){
    ios::sync_with_stdio(false);
    int M, i;
    cin >> M;
    const int length = M;
    
    long long int knn[M - 1];
    for(i = 0; i < M - 1; i++){
        cin >> knn[i];
    }
    circleLinkList<int> money(M);
    money.loop(M, knn);
    
}




