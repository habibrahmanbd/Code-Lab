//#pragma warning (disable: 4786)

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
#define SZ(s)      ((int)s.size())
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
#define REP(i,n)    for(i=0;i<n;i++)
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

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void debug(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<"\t"<<e6<<endl;}
template<class T> void debug(vector< vector<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;} cout<<endl;}
template<class T> void debug(vector< basic_string<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j];cout<<endl;} cout<<endl;}
template<class T> void debug(T e[110][110],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//*************************************************My Code Starts Here*********************************************************************************
#define paii pair<LL,LL>

//ax+by=1
paii egcd ( LL a, LL b )
{
	if (b == 1)
		return mp(0, 1);
	paii ret = egcd(b%a, a);
	int p = ret.second-(b/a)*ret.first, q = ret.first;
	p %= b; //for overflow

	//cout << a << "*" << p << " + " << b << "*" << q << " = 1\n";
	return mp(p, -(a*p-1LL)/b);
}

//ax+by=c
bool find_any_solution( LL a , LL b, LL c, LL &x0 , LL &y0 , LL &g)
{
    if( !a && !b ) return !c;
    g=__gcd(a,b);
    if( (c%g)!=0 )
        return false;
    a/=g;
    b/=g;
    c/=g;
    paii ret=egcd(abs(a), abs(b));
    x0=ret.first;
    y0=ret.second;

    x0 = (x0*(c%b))%b;
    y0 = (c-a*x0)/b;
    if( a<0 ) x0*= -1;
    if( b<0 ) y0*= -1;

    return true;
}

void shift_solution( LL &x , LL &y , LL a, LL b, LL cnt) {
    x+= cnt*b;
    y-= cnt*a;
}

// ax+by=c;
LL find_all_solutions (LL a, LL b, LL c, LL minx, LL maxx, LL miny, LL maxy) //mainly takes the range
{
    LL x, y, g;

    if (!find_any_solution (a, b, c, x, y, g))
        return 0;
    if(!a&&!b)
       return (maxx-minx+1)*(maxy-miny+1);

    if(a&&!b)
    {
       x=c/a;
       if(x<minx||x>maxx) return 0;
       return maxy-miny+1;
    }

    if(!a&&b)
    {
       y=c/b;
       if(y<miny||y>maxy) return 0;
       return maxx-minx+1;
    }

    a /= g; b /= g;

    LL sign_a = a> 0?  1: - 1;
    LL sign_b = b> 0?  1: - 1;

    shift_solution (x, y, a, b, (minx - x) / b);
    if (x <minx)
        shift_solution (x, y, a, b, sign_b);
    if (x> maxx)
        return 0LL;
    LL lx1 = x;

    shift_solution (x, y, a, b, (maxx - x) / b);
    if (x> maxx)
        shift_solution (x, y, a, b, - sign_b);
    LL rx1 = x;

    shift_solution (x, y, a, b, - (miny - y) / a);
    if (y <miny)
        shift_solution (x, y, a, b, - sign_a);
    if (y> maxy)
        return 0LL;
    LL lx2 = x;

    shift_solution (x, y, a, b, - (maxy - y) / a);
    if (y> maxy)
        shift_solution (x, y, a, b, sign_a);
    LL rx2 = x;

    if (lx2> rx2)
        swap (lx2, rx2);
    LL lx = max (lx1, lx2);
    LL rx = min (rx1, rx2);

    return max(0LL,(rx - lx) / abs (b) + 1);
}



int main()
{
    return 0;
}

