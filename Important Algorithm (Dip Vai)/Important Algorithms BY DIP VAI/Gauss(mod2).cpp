//#pragma warning (disable: 4786)
/*
Let us consider a set of fractions x/y, such that 0 <= x/y <= 1, y <= n and gcd (x, y) = 1.

For example, say n = 5. Then we have the following set in increasing order :

0⁄1, 1⁄5, 1⁄4, 1⁄3, 2⁄5, 1⁄2, 3⁄5, 2⁄3, 3⁄4, 4⁄5, 1⁄1

You are given n, a and b. The task is to find the rank of a/b in a set of fractions as stated above which is in increasing order.


Input

The first line of the input contains t (t <= 20), the number of testcases. Then t lines follow. In each of the t lines you are given n, a and b.  (n <= 100000)
Output

Print t lines. The ith line contains the rank of a fraction a/b for a given n, a and b in the (i + 1)th line of input. All answers fit within a signed integer.
Example

Input:
2
5 3 4
8 5 7


Output:
9
17
*/
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
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define csprnt printf("Case %d: ", ++cas);

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
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
//*************************************************My Code Starts Here*********************************************************************************
//a is the total matrix, last column is the constant matrix and other columns are coefficient matrix
//final ans is stored is ans matrix
//complexity (n^3)/64

long long gauss ( vector < vector < long long > > a, vector < long long > & ans,int sz) //sz=number of variables+1
{
	int n = ( int ) a. size ( ) ;
	int m = sz-1;
    //print2(n,m);
	vector < int > where ( m, - 1 ) ;
	for ( int col = 0 , row = 0 ; col < m && row < n ; ++ col ) {
		int sel = row ;
		//print1(a[row][col]);
		for ( int i = row ; i < n ; ++ i )
			if (((a[i][col/64])&(1LL<<(col%64)))  > ((a[sel][col/64])&(1LL<<(col%64))))
				sel = i ;
		if ( ((a[sel][col/64])&(1LL<<(col%64)))==0 )
			continue ;
		for ( int i = col/64 ; i <= m/64 ; ++ i )
			swap ( a [ sel ] [ i ] , a [ row ] [ i ] ) ;
		where [ col ] = row ;
		//print3(row,col,a[row][col]);

		for ( int i = 0 ; i < n ; ++ i )
			if ( i != row ) {
				if((a[i][col/64])&(1LL<<(col%64))) //if set
				for ( int j = col/64 ; j <= m/64 ; ++ j ){
					a [ i ][ j ] ^= a[row][j];

				}
			}
		++ row ;
	}

    ans. assign ( m, 0 ) ;
	for ( int i = 0 ; i < m ; ++ i )
		if ( where [ i ] != - 1 ) {
			ans [ i ] =  (a [ where [ i ] ] [ m/64 ]& (1LL<<(m%64)));
		    if(ans[i]) ans[i]=1;
		}

	for ( int i = 0 ; i < n ; ++ i ) {
		bool sum = 0 ;
		for ( int j = 0 ; j < m ; ++ j ) {
		    int gun=(a [ i ] [ j/64 ]& (1LL<<(j%64)));
		    if(gun) gun=1;
			sum += ans [ j ] *gun;
		}
		 if( sum!= (bool)(a[i][m/64]&(1LL<<(m%64)) ))
            return 0;
	}

	long long totalans=1;
	for ( int i = 0 ; i <= m ; ++ i )
		if ( where [ i ]== - 1 ) //use mod if necessary
			totalans=(totalans* 2)%1000000007;

	return totalans;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        mem(grid,0);
        int i,j;
        for(i=1;i<=m;i++)
        {
            int k;
            scanf("%d",&k);
            int light;
            while(k--)
            {
                scanf("%d",&light);
                grid[light][i]=1;
            }
        }

        int q;
        cin>>q;
        csprnt;
        while(q--)
        {
            vector<long long>ans;
            vector< vector<long long> > a;
            for(i=1;i<=n;i++)
            {
                int state;
                scanf("%d",&state);
                vector<long long>tem;
                long long temval=0;
                for(j=1;j<=m;j++)
                    temval+=((long long)grid[i][j]<<(j-1));
                temval+=(long long)state<<m;
                tem.pb(temval);
                a.pb(tem);
            }
            printf("%I64d\n",gauss(a,ans,m+1));
        }
    }
    return 0;
}

