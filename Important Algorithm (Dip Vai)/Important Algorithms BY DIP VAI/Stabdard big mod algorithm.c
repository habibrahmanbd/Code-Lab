#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;


long long bigmod(long long b,long long p,long long m)
{
    if(b==0) return 0;
    long long x,power;
    x=1;
    power=b%m;
    while(p)
    {
       if(p%2==1)
            x=(x*power)%m;
        power=(power*power)%m;
        p=p/2;
    }
    return x;
}

int main()
{
    long long  x,y,z,res;
    while(cin>>x>>y>>z)
    {
        res=bigmod(x,y,z);
        cout<<res<<endl;
    }
    return 0;
}
