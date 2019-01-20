
#include <stdio.h>
#include <iostream>

using namespace std;

class point{
public:
    
    int x;
    int y;


    point(int xx = 0, int yy = 0){
        x = xx;
        y = yy;
    }
    bool operator==(const point obj){
        if(x == obj.x && y == obj.y){
            return true;
        }
        else{
            return false;
        }
    }
};

template<class elemType>
class queue {
public:
    virtual bool isEmpty() = 0;
    virtual void enQueue(const elemType &x) = 0;
    virtual elemType deQueue() = 0;
    virtual elemType getHead() = 0;
    virtual ~queue(){};
};

template<class elemType>
class linkQueue: public queue<elemType>
{
private:
    struct node{
        elemType data;
        node *next;
        node(const elemType &x, node *N = NULL){
            data = x;
            next = N;
        }
        node():next(NULL){}
        ~node(){}
    };
    
    node *front , *rear;
    
public:
    linkQueue(){
        front = rear = NULL;
        
    }
    ~linkQueue(){
        node *tmp;
        while(front != NULL){
            tmp = front;
            front = front -> next;
            delete tmp;
        }
    }
    bool isEmpty(){
        return front == NULL;
    }
    
    void enQueue(const elemType &x){
        if(rear == NULL){
            front = rear = new node(x);
        }
        else{
            rear -> next = new node(x);
            rear = rear -> next;
        }
    }
    
    elemType deQueue(){
        node *tmp = front;
        elemType value = front -> data;
        front = front -> next;
        if(front == NULL){
            rear = NULL;
        }
        delete tmp;
        return value;
    }
    
    elemType getHead()
    {
        return front-> data;
    }
    
    
};
int map[1005][1005];
int distHomeToUm[1005][1005];
int distSkyToUm[1005][1005];
void distSkyToAll(point& Vs,int m, int n){
    linkQueue<point> Q;
    point Vn, Vw;
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            distSkyToUm[i][j] = -1;
        }
    }
    
    //四个方向
    int dir[][2] = {
        {0, 1}, {1, 0},
        {0, -1}, {-1, 0}
    };
    

    Q.enQueue(Vs);
    distSkyToUm[Vs.x][Vs.y] = 0;
    
    while (!Q.isEmpty()){//队列不为空，继续搜索！
   
        
        Vn = Q.getHead();
        Q.deQueue();
        
        
        for(i = 0; i < 4; ++i){
            if((Vn.x+dir[i][0] <= m) && (Vn.x+dir[i][0] >= 0) && (Vn.y+dir[i][1] >= 0) && (Vn.y+dir[i][1] <= n)){
                Vw = point(Vn.x+dir[i][0], Vn.y+dir[i][1]);//计算相邻节点
                
                if (map[Vw.x][Vw.y] != 1 && distSkyToUm[Vw.x][Vw.y] == -1){
                    distSkyToUm[Vw.x][Vw.y] = distSkyToUm[Vn.x][Vn.y] + 1;
                    Q.enQueue(Vw);
                }
            }

        }
    }
}
void distHomeToAll(point& Vs,int m, int n){
    linkQueue<point> Q;
    point Vn, Vw;
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            distHomeToUm[i][j] = -1;
        }
    }
    
    //四个方向
    int dir[][2] = {
        {0, 1}, {1, 0},
        {0, -1}, {-1, 0}
    };
    
    
    Q.enQueue(Vs);
    distHomeToUm[Vs.x][Vs.y] = 0;
    
    while (!Q.isEmpty()){//队列不为空，继续搜索！
        
        
        Vn = Q.getHead();
        Q.deQueue();
        
        
        for(i = 0; i < 4; ++i){
            if((Vn.x+dir[i][0] <= m) && (Vn.x+dir[i][0] >= 0) && (Vn.y+dir[i][1] >= 0) && (Vn.y+dir[i][1] <= n)){
                Vw = point(Vn.x+dir[i][0], Vn.y+dir[i][1]);//计算相邻节点
                
                if (map[Vw.x][Vw.y] != 1 && distHomeToUm[Vw.x][Vw.y] == -1){
                    distHomeToUm[Vw.x][Vw.y] = distHomeToUm[Vn.x][Vn.y] + 1;
                    Q.enQueue(Vw);
                }
            }
            
        }
    }
}
int ss[10];
void sss(){
    cout << ss[0] << endl;
}
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n, i, j, umNum = 0;
    intmin = 100000;
    linkQueue<point> umbralla;
    point sky, home, umAddr;
    
    cin >> n;
    cin >> m;


    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                sky = point(i, j);
            }
            if(map[i][j] == 3){
                home = point(i, j);
            }
            if(map[i][j] == 4){
                umbralla.enQueue(point(i, j));
                umNum = umNum + 1;
            }
        }
    }
    const int um = umNum;
    int distUm[um];
    distSkyToAll(sky, m ,n);
    distHomeToAll(home, m, n);
    for(i = 0; i < umNum; i++){
        umAddr = umbralla.deQueue();
        if(distSkyToUm[umAddr.x][umAddr.y] != -1 &&  distHomeToUm[umAddr.x][umAddr.y] != -1){
            distUm[i] = distSkyToUm[umAddr.x][umAddr.y] + distHomeToUm[umAddr.x][umAddr.y];
        }
        else{
            distUm[i] = 100000;
        }
    }
    for(i = 0; i < umNum; i++){
        if(distUm[i] <= min){
            min = distUm[i];
        }
    }
    cout << min << '\n';

}
