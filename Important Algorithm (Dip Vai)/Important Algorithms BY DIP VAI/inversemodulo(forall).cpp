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

int extendedgcd ( int a, int b, int & x, int & y ) {
	if ( a == 0 ) {
		x = 0 ; y = 1 ;
		return b ;
	}
	int x1, y1 ;
	int d = extendedgcd( b % a, a, x1, y1 ) ;
	x = y1 - ( b / a ) * x1 ;
	y = x1 ;
	return d;
}

void findinverse(int a,int m)
{
   int x, y ;
   int g = extendedgcd( a, m, x, y );
   if ( g!=1 )
	cout << "no solution"<<endl;

   else {
    x = ( x % m + m ) % m ;
	cout << x <<endl;
    }
}

void inverseofall(int m)
{
    int r[m];
    r [ 1 ] = 1 ;
    for ( int i = 2 ; i < m ; ++ i )
        r [ i ] = ( m - ( m / i ) * r [ m % i ] % m ) % m ; //0 means no inverse modulo
    //for ( int i = 1 ; i < m ; ++ i )
        //print2(i,r[i]);
}


int main()
{
    int a,m;
    while(cin>>m)
    {
        //findinverse(a,m);
        inverseofall(m);
    }
    return 0;
}

