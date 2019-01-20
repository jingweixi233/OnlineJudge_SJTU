#include <iostream>
#include <math.h>

using namespace std;

void swap(int &a, int &b)
{
    if (a == b)
        return;
    a = a + b;
    b = a - b;
    a = a - b;
}

long long int getPartion(int *array, long long int low, long long int high)
{
    int key = array[low];
    while (low < high)
    {
        while (low < high && key <= array[high]) //如果array[high]大于键值，那么本就应该在键值右边
            high--;  //因此将high下标向前移动，直至找到比键值小的值，此时交换这两个值
        swap(array[low], array[high]);
        
        while (low < high && key >= array[low])
            low++;
        swap(array[low], array[high]);
    }
    return low;//返回key值的下标
}



void QuitSort(int *buf,long long int low,long long int high)
{
    if (low < high)
    {
        long long int key = getPartion(buf, low, high);
        
        QuitSort(buf, low, key - 1);
        QuitSort(buf, key + 1, high);
    }
}


int main(){
    int address[100000];
    long long int i, j, N, dist;
    for(i = 0; i < 100000; i++){
        address[i] = 0;
    }
    cin >> N;
    ios::sync_with_stdio(false);
    for(i = 0; i < N; i++){
        cin >> address[i];
    }
    
    QuitSort(address, 0, N - 1);
    
    dist = 0;
    for(j = 0; j < N; j++){
        dist = dist + abs(address[N / 2] - address[j]);
    }
    cout << dist << endl;
}
