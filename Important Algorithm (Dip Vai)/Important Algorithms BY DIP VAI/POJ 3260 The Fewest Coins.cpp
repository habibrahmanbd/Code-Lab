#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
#define ERR        1e-5
#define PRE        1e-8
#define SZ(s)      (int)s.size()
#define LL           long long
#define ISS         istringstream
#define OSS        ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define typing(j,b) typeof((b).begin()) j=(b).begin();
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define cntbit(mask) __builtin_popcount(mask)
//number of ways
struct coin{
   int val;
   int freq;
};
#define lim 25100
coin arr[120];
int dp[lim],freq[lim],dpinf[lim];
int n,t;

int main()
{

    while(cin>>n>>t)
    {
        int i,j;
        fr(i,1,n)
            cin>>arr[i].val;
        fr(i,1,n)
            cin>>arr[i].freq;

        mem(dp,-1);
        dp[0]=0;
        fr(i,1,n)
        {
            for(j=arr[i].val;j<=25000;j++)
                if(dp[j-arr[i].val]!=-1&&freq[j-arr[i].val]<arr[i].freq)
                {
                    if(dp[j]==-1||dp[j]>dp[j-arr[i].val]+1)
                    {
                        dp[j]=dp[j-arr[i].val]+1;
                        freq[j]=freq[j-arr[i].val]+1;
                    }
                }
           for(j=arr[i].val;j<=25000;j++)
                freq[j]=0;
        }

        mem(dpinf,-1);
        dpinf[0]=0;
        fr(i,1,n)
        {
            for(j=arr[i].val;j<=25000;j++)
                if(dpinf[j-arr[i].val]!=-1&&(dpinf[j]==-1||dpinf[j]>dpinf[j-arr[i].val]+1))
                    dpinf[j]=dpinf[j-arr[i].val]+1;
        }

        int ans=-1;
        for(i=t;i<=25000;i++)
        if(dp[i]!=-1&&dpinf[i-t]!=-1)
        {
            if(ans==-1)
                ans=dp[i]+dpinf[i-t];
            else ans=min(ans,dp[i]+dpinf[i-t]);
        }
        print1(ans);
    }
    return 0;
}
