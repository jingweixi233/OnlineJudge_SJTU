/*
quick sort
shao
pai
*/
#include <iostream>

using namespace std;

const int N = 200005;

struct mouse{
    int power;
    int score;
    int id;

    mouse(int p = 0, int s = 0, int i = 0){
        power = p;
        score = s;
        id = i;
    }


	bool operator>(const mouse &obj)const
	{
		if (score != obj.score) return score > obj.score;
		else return id < obj.id;
	}

};

mouse list[N];

void quickSort(int l, int r){
    int i, j;
    mouse x;
    if(l < r){
        i = l;
        j = r;
        x = list[l];
        while(i < j){
            while(i < j && x > list[j]){
                j = j - 1;
            }
            if(i < j){
                list[i]= list[j];
                i = i + 1;
            }
            while(i < j && list[i] > x){
                i = i + 1;
            }
            if(i < j){
                list[j]= list[i];
                j = j - 1;
            }
        }
        list[i] = x;
        quickSort(l, i - 1);
        quickSort(i + 1, r);
    }
}

void set(int index){

	if (index == 1 || list[index - 1] > list[index]){
        return;
    } 
 
	mouse tmp = list[index];
	while (index > 1 && tmp > list[index - 1])
	{
		list[index] = list[index - 1];
		index--;
	}
	list[index] = tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int mouNum, race;
    int i, j;
    int moup, mous;

    cin >> mouNum >> race;
    mouNum = mouNum * 2;
    for(i = 1; i <= mouNum; i++){
        cin >> mous;
        list[i].score = mous;
        list[i].id = i;
    }
    for(i = 1; i <= mouNum; i++){
        cin >> moup;
        list[i].power = moup;
    }

    quickSort(1, mouNum);
    /*
    for(i = 1; i <= mouNum; i++){
        cout << list[i].id << " ";
    }
    */
    cout << endl;
    for(i = 0; i < race; i++){
        for(j = 1; j <= mouNum / 2; j++){
            if(list[2 * j - 1].power >  list[2 * j].power){
                list[2 * j - 1].score += 2;
                set(2 * j - 1);
            }
            else{
                if(list[2 * j - 1].power <  list[2 * j].power){
                    list[2 * j].score += 2;
                    set(2 * j);
                }
                else{
                    list[2 * j - 1].score += 1;
                    set(2 * j - 1);
                    list[2 * j].score += 1;
                    set(2 * j);
                }
            }
        }
    }
    for(i = 1; i <= mouNum; i++){
        cout << list[i].id << " ";
    }
    
}