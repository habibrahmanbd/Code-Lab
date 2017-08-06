#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
#define ERR         1e-5
#define PRE         1e-8
#define SZ(a)       (int)a.size()
#define LL          long long
#define ULL         unsigned long long
#define ISS         istringstream
#define OSS         ostringstream
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
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define countbit(mask) __builtin_popcount(mask)
#define mo         1100000
#define inf        1100000000
int par[mo];// where ans is stored

bool KMP(string str,int l)
{
    par[0]=0;
    int len=0;
    int i;
    for(i=1;i<SZ(str);i++)
    {
        while(len>0&&str[len]!=str[i])
            len=par[len-1]; //len=1 based
        if(str[len]==str[i]) len++;
        par[i]=len;
        if(l==len) return true;
    }

    return false;
}
string s[10];
int dp[1<<5][5];
int edge[5][5];

int dprec(int bit,int last)
{
   int &ret=dp[bit][last];
   if(ret!=-1) return ret;
   if(countbit(bit)>3) return ret=0;
   ret=inf;
   int i;
   for(i=1;i<=3;i++)
   if(bit&(1<<i))
      continue;
   else {

      if(edge[last][i]==SZ(s[i])) //substr
         ret=min(ret,dprec(bit|(1<<i),last));
      else ret=min(ret,dprec(bit|(1<<i),i)+SZ(s[i])-edge[last][i]);
   }
   return ret;
}


int main()
{
    while(getline(cin,s[1]))
    {
        getline(cin,s[2]);
        getline(cin,s[3]);

        int i,j;
        for(i=1;i<=3;i++)
         for(j=i+1;j<=3;j++)
        {
           if(KMP(s[i]+"#"+s[j],SZ(s[i])))
             edge[j][i]=SZ(s[i]);
           else edge[j][i]=par[SZ(s[i])+SZ(s[j])];
           if(KMP(s[j]+"#"+s[i],SZ(s[j])))
             edge[i][j]=SZ(s[j]);
           else edge[i][j]=par[SZ(s[j])+SZ(s[i])];
        }

        mem(dp,-1);
        print1(dprec(1,0));
    }
    return 0;
}

/*
xufuzdlsjxmevrtessfbwlnzzclcqwevnnucxyvhngnxhcbdfwq
wlwobhnmmgtfolfaeckbrnnglylydxtgtvrlmeeszoiuatzzzxufuzdlsjxmevrt
brnnglylydxtgtvrlmeeszoiuatzzzx
*/
