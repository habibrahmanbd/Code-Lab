//#pragma warning (disable: 4786)

#include <sstream>
#include <queue>
#include <stack>
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
#include <complex>
#include <list>
#include <string.h>
#include <assert.h>
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
#define cntbit(mask) __builtin_popcountll(mask)
//0 based print
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}

#define csprnt printf("Case %d: ", ++cas);
#define mod         1000000007

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
// complexity n(logk)^2 with significant constant factor
// whene there is a good amount(may be more than 1000) of k(distance) required then this should be used
#define s 50010
// k is the distance needed
typedef complex <double> base ;
void fft ( vector < base > & a, bool invert ) {  //invert=true means inverse FFT
	int n = ( int ) a. size ( ) ;

	for ( int i = 1 , j = 0 ; i < n ; ++ i ) {
		int bit = n >> 1 ;
		for ( ; j >= bit ; bit >>= 1 )
			j -= bit ;
		j += bit ;
		if ( i < j )
			swap ( a [ i ] , a [ j ] ) ;
	}

	for ( int len = 2 ; len <= n ; len <<= 1 ) {
		double ang = 2 * pi / len * ( invert ? - 1 : 1 ) ;
		base wlen ( cos ( ang ) , sin ( ang ) ) ;
		for ( int i = 0 ; i < n ; i += len ) {
			base w ( 1 ) ;
			for ( int j = 0 ; j < len / 2 ; ++ j ) {
				base u = a [ i + j ] ,  v = a [ i + j + len / 2 ] * w ;
				a [ i + j ] = u + v ;
				a [ i + j + len / 2 ] = u - v ;
				w *= wlen ;
			}
		}
	}
	if ( invert )
		for ( int i = 0 ; i < n ; ++ i )
			a [ i ]/= n ;
}

void multiply ( vector < int > & a, vector < int > & b, vector < int > & res ) {
	vector < base > fa ( a. begin ( ) , a. end ( ) ) ,  fb ( b. begin ( ) , b. end ( ) ) ;
	size_t n = 1 ;
	while ( n < max ( a. size ( ) , b. size ( ) ) )  n <<= 1 ; //making it a power of 2
	n <<= 1 ; //making double size(2*n)
	fa. resize ( n ) ,  fb. resize ( n ) ;

	fft ( fa, false ) ,  fft ( fb, false ) ;
	for ( size_t i = 0 ; i < n ; ++ i )
		fa [ i ] *= fb [ i ] ;
	fft ( fa, true ) ; //inverse fft

	res. resize ( n ) ;
	for ( size_t i = 0 ; i < n ; ++ i )
		res [ i ] = int ( fa [ i ] . real ( ) + 0.5 ) ;
}
VI adj[s];
int next[s],setcol[s]; //next node in the longest path
bool used[s];

void getoneend(int node,int par,int h,int &maxhei,int &ret) //any one of the two(maybe more) side nodes of the longest path
{
    //print3(node,maxhei,ret);
    if(maxhei<=h)
    {
        maxhei=h;
        ret=node;
    }
    int i;
    for(i=0;i<SZ(adj[node]);i++)
    {
        int tem=adj[node][i];
        if(tem==par||used[tem]) continue;
        getoneend(tem,node,h+1,maxhei,ret);
    }
}

int getlongestpath(int node,int par,int now)
{
    setcol[node]=now;
    int i;
    int ret=0;
    for(i=0;i<SZ(adj[node]);i++)
    {
        int tem=adj[node][i];
        if(tem==par||used[tem]) continue;
        int val=getlongestpath(tem,node,now)+1;
        if(ret<val)
        {
            ret=val;
            next[node]=tem;
        }
    }
    return ret;
}

int getcenteroftree(int node,int rem)
{
    if(rem==0) return node;
    return getcenteroftree(next[node],rem-1);
}
bool dofft;

int centeroftree(int node,int now,int k)
{
    int maxhei=0;
    int oneend;
    getoneend(node,-1,0,maxhei,oneend);
    maxhei=getlongestpath(oneend,-1,now);
    if(maxhei<k) dofft=false;
    else dofft=true;
    return getcenteroftree(oneend,maxhei/2);
}
LL ans;

void dfs(int node,int par,int h,VI &b,int k)
{
    if(SZ(b)>h) b[h]++;
    else b.pb(1);
    if(h>k) return;
    int i;
    for(i=0;i<SZ(adj[node]);i++)
    {
        int tem=adj[node][i];
        if(tem==par||used[tem]) continue;
        dfs(tem,node,h+1,b,k);
    }
}


void getans(int n,int K)
{
    mem(used,false);
    mem(setcol,0);
    ans=0;
    int cnt=n;
    int i,j,k,now=1;
    while(cnt)
    {
        fr(i,1,n)
        if(!used[i]&&setcol[i]!=now)
        {
            int node=centeroftree(i,now,K);
            used[node]=true;
            cnt--;
            if(!dofft) continue;
            VI a,b,ret;
            a.pb(1);
            //print2(i,node);
            fr(j,0,SZ(adj[node])-1)
            {
                int tem=adj[node][j];
                if(used[tem]) continue;
                b.clear();
                b.pb(0);
                dfs(tem,node,1,b,K);
                multiply(a,b,ret); //fft
                //debug_array(b,SZ(b));
                if(SZ(ret)>K) ans+=(LL)ret[K];
                for(i=0;i<a.size()&&i<b.size();i++)
                    a[i]+=b[i];
                for(;i<b.size();i++)
                    a.pb(b[i]);
            }
        }
        now++;
    }
}


int main()
{
    //freopen("A.txt","r",stdin);
    //freopen("C.txt","w",stdout);
    LL n,k;
    while(cin>>n>>k)
    {
          int i,a,b;
          fr(i,1,n)
            adj[i].clear();
          for(i=1;i<n;i++)
          {
            scanf("%d %d",&a,&b);
            adj[a].pb(b);
            adj[b].pb(a);
          }

          getans(n,k);
          print1(ans);
    }
    return 0;
}
/*
7 2
1 3
1 4
1 5
2 6
3 7
1 2


11 2
1 2
2 3
3 4
4 5
5 6
1 7
7 8
8 9
9 10
10 11
*/
