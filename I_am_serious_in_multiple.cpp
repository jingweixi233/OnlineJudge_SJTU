#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int power=9;
int base=1000000000;
struct bigint
{
    long long  m[1050];
    int idx;

    bigint(char *s)
    {
        memset(m,0,sizeof(m));

        int len=strlen(s),tot=0,mul=1;
        idx=0;
        for(int i=len-1;i>=0;--i)
        {
            if(tot==power)
            {
                ++idx;
                tot=0;
                mul=1;
            }
            m[idx]=m[idx]+(s[i]-'0')*mul;
            ++tot;
            mul*=10;
        }
    }

    bigint(){memset(m,0,sizeof(m));};

    bigint(const bigint &r)
    {
        for(int i=0;i<=r.idx;++i)
            m[i]=r.m[i];
        idx=r.idx;
    }

    bigint& operator=(const bigint &r)
    {
        if(this==&r)
            return *this;
        for(int i=0;i<=r.idx;++i)
            m[i]=r.m[i];
        idx=r.idx;
        return *this;
    }

    bool isEven()
    {
        return(m[0]%2==0);
    }

friend bigint operator+(const bigint &l,const bigint &r)
{
    int tmp_add=0;
    bigint p;

    p.idx=(l.idx>r.idx?l.idx:r.idx);


    for(int i=0;i<=p.idx;++i)
    {
        p.m[i]=l.m[i]+r.m[i]+tmp_add;
        tmp_add=p.m[i]/base;
        p.m[i+1]+=tmp_add;
        p.m[i]=p.m[i]%base;

    }

    if(p.m[p.idx+1]>0)
    {
        ++p.idx;
    }

    return p;
}

friend bigint operator-( const bigint &a, const bigint &b)
{

	int len1 = a.idx, len2 = b.idx;

	int minus = 0, i;
	bigint p;

	for (i = 0; i <= len2; ++i)
	{
		p.m[i] = a.m[i] - b.m[i] - minus;
		if (p.m[i] < 0)
		{
			p.m[i] +=base;
			minus =1;
		}
		else
			minus = 0;
	}

	while (i <= len1)
	{
		p.m[i] = a.m[i] - minus;
		if (p.m[i] < 0)
		{
			p.m[i] +=base;
			minus = 1;
		}
		else
			minus = 0;
		++i;
	}

	do
	{
		--i;
	} while (i > 0 && p.m[i] == 0);

	p.idx=i;
	return p;
}

friend bigint operator*(const bigint &l,const bigint &r)
{
    bigint p;
    int tmp_add;
    for(int j=0;j<=r.idx;++j)
    {

        for(int i=0;i<=l.idx;++i)
        {
                p.m[i+j]+=l.m[i]*r.m[j];
                p.m[i+j+1]+=p.m[i+j]/base;
                p.m[i+j]=p.m[i+j]%base;
        }

    }
    p.idx=l.idx+r.idx;

    if(p.m[p.idx+1]>0)
        ++p.idx;
return p;

}
};

void show(const bigint &r)
{

    cout<<r.m[r.idx];
    for(int i=r.idx-1;i>=0;--i)
    {
        int len=1000,mul=1;
        for(int j=0;j<8;++j)
        {
            if(r.m[i]*mul<100000000)
            {
                cout<<0;
                mul*=10;
            }
        }
        cout<<r.m[i];
    }
    /*
    for(int i=r.idx;i>=0;--i)
        cout<<r.m[i]<<" ";
   cout<<endl;*/
}

bool judge(const bigint &a, const bigint &b)
{
	int len1 = a.idx+1, len2 = b.idx+1;
	if (len1 > len2)
		return true;
	else
	{
		if (len1 < len2)
			return false;
	}

	for (int i = len1 - 1; i >= 0; --i)
	{
		if (a.m[i] > b.m[i])
			return true;
		else
		{
			if (a.m[i] < b.m[i])
				return false;
		}
	}

	return true;
}

bigint divideBy_2(const bigint &l)
{
   bigint p;
   p.idx=l.idx;
   for (int i=l.idx;i>0;--i)
   {
       p.m[i-1]+=(l.m[i]+p.m[i])%2*base;
       //cout<<p.m[i-1];
       p.m[i]=(l.m[i]+p.m[i])/2;
       //cout<<p.m[i];
   }
   p.m[0]=(l.m[0]+p.m[0])/2;

   for(int j=p.idx;j>=0;--j)
   {
       if(p.m[j]==0&&p.idx>0)
        --p.idx;
       else
       {
           break;
       }
   }
   return p;
}

bigint mySqrt(const bigint &t)
{
    char s[3]="0",s1[3]="1",s2[3]="2";
    bigint l(s),one(s1),two(s2),r=t,mid;
    while(true)
    {

        //show(l);cout<<"left"<<endl;
       // show(r);cout<<endl;

         mid=divideBy_2(l+r);
        // show(mid);cout<<endl;
        if( judge(mid*(mid+one) ,t) )
        {
            r=mid-one;
        }

        else if( !judge( mid * (mid-one),t) && judge((mid+one)*(mid+two),t) )
                             return mid;
        else
        {
            l=mid+one;

        }
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    char s0[10]="0",s1[10]="1",s2[10]="2",s3[1050];
    cin>>s3;
    bigint one(s1),two(s2),a3(s3),a4,a5,a6;
    a6=mySqrt(two*a3);
    //show(a6);

    a4=(a6+one)*a6;
    //show(a4);
    a5=divideBy_2(a4);
    //show(a5);
    //show(a3-a5);
    if(a6.isEven())
    {
        bigint x(s0),y=a6+two;
        y=y-(a3-a5);
        x=x+(a3-a5);
        show(y);
        cout<<'/';show(x);
    }

    else
    {
        bigint y(s0),x=a6+two;
        x=x-(a3-a5);
        y=y+(a3-a5);
         show(y);
         cout<<'/';
         show(x);
    }

    return 0;
}
