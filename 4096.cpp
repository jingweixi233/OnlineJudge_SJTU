#include <iostream>

using namespace std;

const int N = 30;
int box[N];
int tra[N];
char opr1Type[5];
char opr2Type[5];


int find(int x){
    while(box[x] > 0){
        x = box[x];
    }
    return x;
}

int main(){
    int boxNum;
    int opra, oprb;
    int i, j;
    cin >> boxNum;
    
    for(i = 1; i <= boxNum; i++){
        box[i] = -i;
    }

    while(true){
        
        cin >> opr1Type;
        if(opr1Type[0] == 'q'){
            break;
        }
        else{
            cin >> opra >> opr2Type >> oprb;
        }
        opra++;
        oprb++;
         
        int pa = find(opra);
        int pb = find(oprb);
        if(pa == pb){
            continue;
        }
        if(opr1Type[0] == 'm'){
            if(opr2Type[1] == 'v'){
                int belowA = box[opra];
                int exbox = -box[pa];
                while(box[exbox] >= 0 && exbox != opra){
                    int ex = exbox;
                    exbox = box[exbox];
                    box[ex] = -ex;
                }
                box[pa] = -belowA;
                box[opra] = -box[pb];
                box[pb] = -opra;  

            }
            else{
                int belowA = box[opra];
                int exbox = -box[pa];
                while(box[exbox] >= 0 && exbox != opra){
                    int ex = exbox;
                    exbox = box[exbox];
                    box[ex] = -ex;
                }

                exbox = -box[pb];
                while(box[exbox] >= 0 && exbox != oprb){
                    int ex = exbox;
                    exbox = box[exbox];
                    box[ex] = -ex;
                }
                box[pa] = -belowA;
                box[opra] = oprb;
                box[pb] = -opra;  
            }
        }
        else{
            if(opr2Type[1] == 'v'){
                int ceilA = -box[pa];
                int belowA = box[opra];
                box[pa] = -belowA;
                box[opra] = -box[pb];
                box[pb] = -ceilA;
            }
            else{
                int exbox = -box[pb];
                while(box[exbox] >= 0 && exbox != oprb){
                    int ex = exbox;
                    exbox = box[exbox];
                    box[ex] = -ex;
                }

                int ceilA = -box[pa];
                int belowA = box[opra];
                box[pa] = -belowA;
                box[opra] = oprb;
                box[pb] = -ceilA;        
            }
        }

        /*
        for(j = 1; j <= 10; j++){
            cout << box[j] << " ";
        }
        cout << endl;
        */

    }

    for(i = 1; i <= boxNum; i++ ){
        cout << i - 1 << ":" << ' ';
        if(box[i] > 0){
            cout << '\n';
        }
        else{
            int k = 0;
            int ceili = -box[i];
            while(box[ceili] > 0){
                tra[k] = ceili;
                ceili = box[ceili];
                k++;
            }
            tra[k] = i;
            for(j = k; j >= 0; j--){
                cout << tra[j] - 1 << ' ';
            }
            cout << '\n';
        }
    }

}