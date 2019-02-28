/*
struct{
    int l, r;
}
car[]
quickSort(l)
for{
    if(car[i].r > car[i + 1].l){
        len = car[i + 1].l - car[i].r;
    }
    len = car[i].r - car[i].l;
    sum = sum + len;
}
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20005;

struct water{
    int l, r;
    water(int ll = 0, int rr = 0){
        l = ll;
        r = rr;
    }
};

water car[N];

void quickSort(int l, int r){
    int i = l, j = r;
    water x = car[l];
    if(l < r){
        while(i < j){
            while(i < j && car[j].l > x.l){
                j--;
            }
            if(i < j){
                car[i] = car[j];
                i++;
            }
            while(i < j && car[i].l < x.l){
                i++;
            }
            if(i < j){
                car[j] = car[i];
                j--;
            }
        }
        car[i] = x;
        quickSort(l, i - 1);
        quickSort(i + 1, r);
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num, i, sum = 0, len;
    cin >> num;
    for(i = 0; i < num; i++){
        cin >> car[i].l;
        cin >> car[i].r;
    }
    
    quickSort(0, num - 1);

    //idea1
    for(i = 0; i < num; i++){
        if(i !=  num - 1 && car[i + 1].r <= car[i].r){
            car[i + 1].r = car[i].r;
        }

        if(i !=  num - 1 && car[i].r > car[i + 1].l){
            len = car[i + 1].l - car[i].l;
        }
        else{
            len = car[i].r - car[i].l;
        }
        sum = sum + len;
    }
    cout << sum;
    

    /* //idea2
    for(i = 1; i < num; i++){
        if(car[i].r <= car[i - 1].r){
            car[i].l = car[i - 1].l;
            car[i].r = car[i - 1].r;
            continue;
        }

        if(car[i].l >= car[i - 1].r){
            sum += car[i - 1].r - car[i - 1].l;
            continue;
        }

        car[i].l = car[i - 1].l;
    }
    sum += car[num - 1].r - car[num - 1].l;
    cout << sum;
    */
}




