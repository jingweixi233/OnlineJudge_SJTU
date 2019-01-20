#include<iostream>

using namespace std;

const int mod=99999997;
const int maxn=100010;

struct node
{
    long long int id;
    long long int sum;
};

node a[maxn],b[maxn];
long long int la[maxn],lb[maxn];
long long int n,ans,c[maxn],x[maxn];

bool compare(node x,node y)
{
    return x.sum<y.sum;
}

int lowbit(long long int x)
{
    return x&(-x);
}

void add(long long int x)
{
    long long int i;
    for(i = x;i <= n; i += lowbit(i))
        c[i]++;
}

long long int getsum(int x)
{
    long long int ans=0;
    while(x>0)
    {
        ans = (ans + c[x] ) % mod;
        x-=lowbit(x);
    }
    return ans % mod;
}

void quick_sort(node s[], long long int l, long long int r)
{
    if (l < r)
    {
        long long int i = l, j = r;
        node x = s[l];
        while (i < j)
        {
            while(i < j && s[j].sum >= x.sum)
                j--;
            if(i < j)
                s[i++] = s[j];
            
            while(i < j && s[i].sum < x.sum)
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1);
        quick_sort(s, i + 1, r);
    }
}

int main()
{   int i;
    cin >> n;
    for(i=1;i<=n;i++){
        cin>>a[i].sum;
        a[i].id=i;
    }
    
    for(i=1;i<=n;i++){
        cin>>b[i].sum;
        b[i].id=i;
    }
    quick_sort(a, 1, n);
    quick_sort(b, 1, n);
    
    for(i=1;i<=n;i++){
        x[a[i].id]=b[i].id;
    }

    for(i=n;i>=1;i--)
    {
        add(x[i]);
        ans=(ans+getsum(x[i]-1))%mod;
    }
    cout<< ans % mod << endl;
    return 0;
}
