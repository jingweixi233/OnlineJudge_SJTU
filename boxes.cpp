#include <iostream>
#include <cstdio>
using namespace std;

const int N = 2005;

struct node{
    int x;
    int y;
};

int box[N][N];
int size[N];
node boxad[N];

int main()
{
    freopen("boxes.in", "r", stdin);
    freopen("boxes.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int boxNum, oprNum;
    int opr, a, b;

    cin >> boxNum >> oprNum;

    for(i = 1; i <= boxNum; i++){
        box[i][1] = i;
        boxad[i].x = i;
        boxad[i].y = 1;
        size[i] = 1;
    }

    for(i = 1; i <= oprNum; i++){
        cin >> opr >> a >> b;
        if(boxad[a].x == boxad[b].x){
            continue;
        }
        if(opr == 1){
            int rowa = boxad[a].x;
            int rowb = boxad[b].x;
            for(j = boxad[a].y + 1; j <= size[rowa]; j++){
                box[box[rowa][j]][1] = box[rowa][j];
                boxad[box[rowa][j]].x = box[rowa][j];
                boxad[box[rowa][j]].y = 1;
            }
            size[rowa] = boxad[a].y - 1;
            box[rowb][size[rowb] + 1] = a;
            size[rowb]++;
            boxad[a].x = rowb;
            boxad[a].y = size[rowb];
        }

        if(opr == 2){
            int rowa = boxad[a].x;
            int rowb = boxad[b].x;
            for(j = boxad[a].y + 1; j <= size[rowa]; j++){
                box[box[rowa][j]][1] = box[rowa][j];
                boxad[box[rowa][j]].x = box[rowa][j];
                boxad[box[rowa][j]].y = 1;
            }
            size[rowa] = boxad[a].y - 1;

            for(j = boxad[b].y + 1; j <= size[rowb]; j++){
                box[box[rowb][j]][1] = box[rowb][j];
                boxad[box[rowb][j]].x = box[rowb][j];
                boxad[box[rowb][j]].y = 1;
            }
            size[rowb] = boxad[b].y;

            box[rowb][size[rowb] + 1] = a;
            size[rowb]++;
            boxad[a].x = rowb;
            boxad[a].y = size[rowb];
        }

        if(opr == 3){

            int rowa = boxad[a].x;
            int rowb = boxad[b].x;
            int higha = boxad[a].y;
            int highb = boxad[b].y;
            int num = size[rowa] - higha;
            for(j = 0; j <= num; j++){

                box[rowb][size[rowb] + j + 1]= box[rowa][higha + j];
                boxad[box[rowa][higha + j]].x = rowb;
                boxad[box[rowa][higha + j]].y = size[rowb] + j + 1;

            }
            size[rowa] = higha - 1;
            size[rowb] = size[rowb] + num + 1;


        }

        if(opr == 4){
            int rowa = boxad[a].x;
            int rowb = boxad[b].x;

            for(j = boxad[b].y + 1; j <= size[rowb]; j++){
                box[box[rowb][j]][1] = box[rowb][j];
                boxad[box[rowb][j]].x = box[rowb][j];
                boxad[box[rowb][j]].y = 1;
            }
            size[rowb] = boxad[b].y;

            int higha = boxad[a].y;
            int highb = boxad[b].y;
            int num = size[rowa] - higha;
            for(j = 0; j <= num; j++){

                box[rowb][highb + j + 1]= box[rowa][higha + j];
                boxad[box[rowa][higha + j]].x = rowb;
                boxad[box[rowa][higha + j]].y = size[rowb] + j + 1;

            }
            size[rowa] = higha - 1;
            size[rowb] = size[rowb] + num + 1;
        }
    }

    for(i = 1; i <= boxNum; i++){
        cout << size[i] << ' ';
        for(j = 1; j <= size[i]; j++){
            cout << box[i][j] << " ";
        }
        cout << '\n';
    }




    cout << flush;
    fclose(stdin);
    fclose(stdout);

}
