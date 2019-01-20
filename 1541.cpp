#include <iostream>

using namespace std;

const int N = 200005;
const long long int mins = -2147483647;

long long int nums[N];
long long int ans[N];

int main(){
    long long int winSize, k, n, i, j, maxx = mins;
    cin >> winSize;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    for(i = 0; i < winSize; i++){
        if(nums[i] > maxx){
            maxx = nums[i];
        }
    }
    ans[0] = maxx;
    k = 1;
    for(i = winSize; i < n; i++){
        if(nums[i] >= ans[k - 1]){
            ans[k] = nums[i];
        }
        else{
            if(ans[k - 1] == nums[i - winSize]){
                maxx = mins;
                for(j = i - winSize + 1; j <= i; j++){
                    if(nums[j] >= maxx){
                        maxx = nums[j];
                    }
                }
                ans[k] = maxx;
            }
            else{
                ans[k] = ans[k - 1];
            }
        }
        k = k + 1;
    }
    
    for(i = 0; i < n - winSize; i++){
        cout << ans[i] << ' ';
    }
    cout << ans[n - winSize];
}
