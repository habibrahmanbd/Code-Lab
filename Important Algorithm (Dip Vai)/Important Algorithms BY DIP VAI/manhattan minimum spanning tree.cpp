//#pragma warning (disable: 4786)

#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include  <time.h>
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2.0*acos(0.0))
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
#define mp          make_pair
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define cntbit(mask) __builtin_popcountll(mask)
//0 based print
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}

#define csprnt printf("Case #%d: ", ++cas);

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
//Codechef Dragon Stone
#define INF 2000000000
int N;
int X[200010], Y[200010];
int Q;
int A[200010], B[200010];
#define mo          3000010
//1 based
//Just need to insert input in arredge.
//The vertices order is not important that means you just have to enter every edge only once.

typedef struct edges{
    int n1;
    int n2;
    int w;
}ed;
ed arredge[mo];
int p[mo];
int rank[mo];
int settree;

void makeset(int node)  //initialize
{
    p[node]=node;
}

void link(int x,int y)
{
    if(rank[x]>rank[y])
        p[y]=x;
    else
        p[x]=y;
    if(rank[x]==rank[y])
        rank[y]++;
}

int findset(int node)  //giving value recursively(once done then query O(1))
{
    if(node!=p[node])
        p[node]=findset(p[node]);
    return p[node];
}

bool comp(ed x,ed y)
{
    return x.w<y.w;
}

void initialize(int node)
{
    for(int i=1;i<=node;i++)//1 indexed node
            makeset(i);
    mem(rank,0);
}

int mst(int st,int end,int node)//look at the sort for information about the parameters
{
        if(st<=end)
        sort(&arredge[st],&arredge[end+1],comp);
        initialize(node);
        int in=st,i;
        settree=node;
        int edgecost=0;
        while(settree!=1)/*change in this can change mst*/
        {
            int c,d;
            c=findset(arredge[in].n1);
            d=findset(arredge[in].n2);
            if(c!=d)
            {
                settree--;
                link(c,d);
                edgecost+=arredge[in].w;
            }
            in++;
        }
        return edgecost;
}

void makeEdge(int u, int v,int &in)
{
    arredge[++in].n1=u+1;
    arredge[in].n2=v+1;
	arredge[in].w = abs(X[u] - X[v]) + abs(Y[u] - Y[v]);
}

bool cmpDivide(const int &u, const int &v) {
	return ((Y[u] != Y[v]) ? (Y[u] < Y[v]) : (X[u] < X[v]));
}
bool cmpConquer(const int &u, const int &v) {
	return (Y[u] - X[u] < Y[v] - X[v]);
}

Int bestVals[200010];
int bests[200010];
int ps[200010];

void solve(int S, int T) {
	if (T - S == 1) {
		return;
	}
	const int U = (S + T) / 2;
	solve(S, U);
	solve(U, T);
	int opt = INF;
	int vm = -1;
	for (int i = S, j = U; i < U; ++i) {
		for (; j < T && Y[ps[j]] - X[ps[j]] <= Y[ps[i]] - X[ps[i]]; ++j) {
			if (opt > X[ps[j]] + Y[ps[j]]) {
				opt = X[ps[j]] + Y[ps[j]];
				vm = ps[j];
			}
		}
		if (bestVals[ps[i]] > opt) {
			bestVals[ps[i]] = opt;
			bests[ps[i]] = vm;
		}
	}
	inplace_merge(ps + S, ps + U, ps + T, cmpConquer);
}

const int E = 20;
int V;
int ids[400010];
int P[E][400010];
int dep[400010];
Int ds[400010];

int main()
{
    int t;
    cin>>t;

	while(t--)
	{
		scanf("%d",&N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d",&X[i],&Y[i]);
		}

		scanf("%d",&N);
		for (int i = 0; i < Q; i++)
		{
			scanf("%d %d",&A[i],&B[i]);
		}

        int in=0;
        for (int phase = 0; phase < 8; ++phase) {

			fill(bestVals, bestVals + N, INF);
			fill(bests, bests + N, -1);
			iota(ps, ps + N, 0);
			sort(ps, ps + N, cmpDivide);
			solve(0, N);
// cout<<"bests : ";pv(bests,bests+N);
			for (int i = 0; i < N; ++i)
			if (~bests[i])
			{
			    makeEdge(i,bests[i],in);
			}

			if (phase % 2 == 0) {
				for (int i = 0; i < N; ++i) {
					swap(X[i], Y[i]);
				}
			} else {
				for (int i = 0; i < N; ++i) {
					X[i] *= -1;
				}
			}
		}

		    int ans=mst(1,in,N);
// cout<<"lca("<<A[q]<<", "<<B[q]<<") = "<<u<<endl;
			printf("%lld\n", ds[u]);
		}
	}

	return 0;
}

/*
Input:
2
4
0 0
0 1
1 0
1 1
2
1 2
1 4
4
0 0
0 2
0 9
0 12
2
1 4
3 4


Output:
1
1
7
3
*/
