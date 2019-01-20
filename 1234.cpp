/*
const int N = 10005;
const int M = 100005;
line[N];
way{
    int st, end
    int w;

}
bin[N];
quick sort line
while(){
    find
}
*/

#include <iostream>

using namespace std;
const int N = 10005;
const int M = 100005;
struct way{
    int st, en, w;
    way(int s = 0, int e = 0, int ww = 0){
        st = s;
        en = e;
        w = ww;
    }
};
way line[M];
int bin[N];

void quickSort(int l, int r){
    if(l < r){
        int i = l;
        int j = r;
        way x = line[l];
        while(i < j){
            while(i < j && line[j].w > x.w){
                j--;
            }
            if(i < j){
                line[i] = line[j];
                i++;
            }
            while(i < j && line[i].w < x.w){
                i++;
            }
            if(i < j){
                line[j] = line[i];
                j--;
            }
        }
        line[i] = x;
        quickSort(l, i - 1);
        quickSort(i + 1, r);
    }
}

int find(int x){
    if(bin[x] < 0){
        return x;
    }
    return bin[x] = find(bin[x]);
}

int main(){
    int nodeNum, wayNum;
    int i, j, k = 0;
    int start, end, weight; 
    int wayAc = 0;
    int ans = 0;
    cin >> nodeNum >> wayNum;
    for(i = 0; i < wayNum; i++){
        cin >> start >> end >> weight;
        line[i].st = start;
        line[i].en = end;
        line[i].w = weight;
    }
    quickSort(0, wayNum - 1);
    for(i = 0; i <= nodeNum; i++){
        bin[i] = -1;
    }

    while(wayAc < nodeNum - 1){
        way test = line[k];
        k++;
        int px = find(test.st);
        int py = find(test.en);
        if(px != py){
            ans += test.w;
            wayAc++;
            bin[py] = px;    
        }
    }
    cout << ans;
    
}