//#pragma warning (disable: 4786)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
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
#define ERR         1e-5
#define PRE         1e-8
#define SZ(s)       ((int)s.size())
#define LL          long long
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
#define REP(i,n)    for(i=0;i<n;i++)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#define typing(j,b) typeof((b).begin()) j=(b).begin();
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define csprnt printf("Case %d: ", ++cas);
#define lim  1000005
//0 based
int m[2*lim+1]; //length of the longest palindrome centered at the index

int manacher(string &s)
{
    int len = s.size();
    if(len == 0) return -1;
    mem(m,0);
    m[0] = 0;
    m[1] = 1;
    // "cur" is the current center
    // "r" is the right bound of the palindrome
    // that centered at current center
    int cur, r;
    r = 2;
    cur = 1;
    int ma=1;
    for(int p2=2; p2<2*len+1; p2++)
    {
        int p1 = cur- (p2-cur);
        //if p1 is negative, we need to
        //move "cur" forward
        while(p1 < 0)
        {
            cur++;
            r = m[cur] + cur;
            p1 = cur- (p2-cur);
        }
        //If the first character of t is
        //strictly on the right of the
        // first character of s
        if(m[p1] < r - p2)
            m[p2] = m[p1];
        //otherwise
        else
        {
            //reset "cur"
            cur = p2;
            int k = r-p2;
            if(k<0) k = 0;
            while(1)
            {
                if((p2+k+1)&1)
                {
                    if(p2+k+1 < 2*len+1 && p2-k-1 >=0 && s[(p2+k)/2] == s[(p2-k-2)/2])
                        k++;
                    else break;
                }
                else
                {
                    if(p2+k+1 < 2*len+1 && p2-k-1 >=0)
                        k++;
                    else break;
                }

            }
            r = p2+k;
            m[p2] = k;
            ma=max(ma,k);
        }
    }
    return ma;
}


int main()
{
    string s;
    while(cin>>s)
    {
        print1(manacher(s));
    }
    return 0;
}
