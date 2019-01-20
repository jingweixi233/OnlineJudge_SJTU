#include<iostream>
using namespace std;

long long a[100050],b[100050],len[100050];

void quicksort(int begin,int end)
{
    if(begin < end)
    {
        long long int i=begin,j=end,x=a[i],y=b[i];
        while(i<j)
        {
            while(i<j&&a[j]>x)
                --j;
            if(i<j)
            {
                a[i]=a[j];b[i]=b[j];++i;
            }

            while(i<j&&a[i]<x)
                ++i;
            if(i<j)
            {
                a[j]=a[i];b[j]=b[i];--j;
            }
        }
        a[i]=x;
        b[i]=y;
        quicksort(begin,i-1);
        quicksort(i+1,end);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   int m,total=0;
   cin>>m;
   for(int i=0;i<m;++i)
   {
       cin>>a[i];
   }
  for(int i=0;i<m;++i)
   {
       cin>>b[i];
   }
    quicksort(0,m-1);
/*
    for(int i=0;i<m;++i)
   {
       cout<<a[i]<<" "<<b[i]<<endl;
   }
*/
    if(m==1||m==2)
        cout<<m;

    else
    {
        for(int i=1;i<m;++i)
        {
            len[i]=a[i]-a[i-1];
        }

        for(int i=1;i<m-1;++i)
        {
            if(len[i]>b[i])
                ++total;
            else if(len[i+1]>b[i])
            {
                ++total;
                len[i+1]-=b[i];
            }
        }

        cout<<total+2;
    }
    //cout<<flush;
    return 0;
}









