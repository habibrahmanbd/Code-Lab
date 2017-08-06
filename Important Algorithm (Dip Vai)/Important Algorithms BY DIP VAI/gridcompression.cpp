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
LL r,c;
vector<LL>x,y;
int grid[100][100];
map<LL,int>col1,col2;

void rapb(LL a1,LL b1,LL c1,LL d1)
{
   //debug(a1,b1,col[a1],col[b1]);
   int i,j;
   for(i=col1[a1];i<col1[b1];i++)
   for(j=col2[c1];j<col2[d1];j++)
      grid[i][j]++;
}

class HyperKnight
{
public:
	long long countCells(int a, int b, int R, int C, int k)
	{
	   if(k==0) return 0;
	   x.clear();
	   y.clear();
	   r=R;
	   c=C;

	   //starting grid
	   x.pb(1);
	   x.pb(a+1);
	   x.pb(b+1);
	   x.pb(r-a+1);//ending+1
	   x.pb(r-b+1);
	   x.pb(r+1);
	   sorta(x);

	   y.pb(1);
	   y.pb(a+1);
	   y.pb(b+1);
	   y.pb(c-a+1);
	   y.pb(c-b+1);
	   y.pb(c+1);
	   sorta(y);
	   int i,j;
	   col1.clear();
	   col2.clear();
	   fr(i,0,SZ(x)-1) col1[x[i]]=i;
	   fr(i,0,SZ(y)-1) col2[y[i]]=i;

	   mem(grid,0);
	   //ending+1
	   rapb(1,r-a+1,1,c-b+1);
	   rapb(1,r-a+1,b+1,c+1);
	   rapb(a+1,r+1,1,c-b+1);
	   rapb(a+1,r+1,b+1,c+1);
	   rapb(1,r-b+1,1,c-a+1);
	   rapb(1,r-b+1,a+1,c+1);
	   rapb(b+1,r+1,1,c-a+1);
	   rapb(b+1,r+1,a+1,c+1);

      fr(i,0,6)
      {
         fr(j,0,6)
            cout<<grid[i][j]<<" ";
         cout<<endl;
      }
	   LL ans=0;
	   for(i=0;i<=SZ(x)-1;i++)
	   for(j=0;j<=SZ(y)-1;j++)
	   if(grid[i][j]==k)
        ans+=(x[i+1]-x[i])*(y[j+1]-y[j]);
      return ans;
	}
};


template<typename T> void print( T a ) {
    cerr << a;
}

void print( long long a ) {
    cerr << a << "L";
}

void print( string a ) {
    cerr << '"' << a << '"';
}

template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}

template<typename T> void assert_eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

template<typename T> void assert_eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
void assert_eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

int main( int argc, char* argv[] )
{

	HyperKnight objectHyperKnight;

	//test case0
//	int param00 = 2;
//	int param01 = 1;
//	int param02 = 8;
//	int param03 = 8;
//	int param04 = 4;
//	long long ret0 = objectHyperKnight.countCells(param00,param01,param02,param03,param04);
//	long long need0 = 20;
//	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 3;
	int param11 = 2;
	int param12 = 8;
	int param13 = 8;
	int param14 = 2;
	long long ret1 = objectHyperKnight.countCells(param10,param11,param12,param13,param14);
	long long need1 = 16;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 1;
	int param21 = 3;
	int param22 = 7;
	int param23 = 11;
	int param24 = 0;
	long long ret2 = objectHyperKnight.countCells(param20,param21,param22,param23,param24);
	long long need2 = 0;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 3;
	int param31 = 2;
	int param32 = 10;
	int param33 = 20;
	int param34 = 8;
	long long ret3 = objectHyperKnight.countCells(param30,param31,param32,param33,param34);
	long long need3 = 56;
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 1;
	int param41 = 4;
	int param42 = 100;
	int param43 = 10;
	int param44 = 6;
	long long ret4 = objectHyperKnight.countCells(param40,param41,param42,param43,param44);
	long long need4 = 564;
	assert_eq(4,ret4,need4);

	//test case5
	int param50 = 2;
	int param51 = 3;
	int param52 = 1000000000;
	int param53 = 1000000000;
	int param54 = 8;
	long long ret5 = objectHyperKnight.countCells(param50,param51,param52,param53,param54);
	long long need5 = 999999988000000036LL;
	assert_eq(5,ret5,need5);

}
