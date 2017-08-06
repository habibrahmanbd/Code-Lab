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
#define REV(i,n) for (i=n;i>=0;i--)
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
// POJ 1741 Tree (distance<=k)
// split the tree so that any subtree has maximum n/2(floor) nodes
// recursively traverse tree by center of tree approach reqires O(nlogn) time
#define lim 10010
VI adj[lim],cost[lim];
int next[lim]; //next node in the longest path
bool used[lim];
int K;

void getoneend(int node,int par,int h,int &maxhei,int &ret) //any one of the two(maybe more) side nodes of the longest path
{
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

int getlongestpath(int node,int par)
{
    int i;
    int ret=0;
    for(i=0;i<SZ(adj[node]);i++)
    {
        int tem=adj[node][i];
        if(tem==par||used[tem]) continue;
        int val=getlongestpath(tem,node)+1;
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

int centeroftree(int node)
{
    int maxhei=0;
    int oneend;
    getoneend(node,-1,0,maxhei,oneend);
    maxhei=getlongestpath(oneend,-1);
    return getcenteroftree(oneend,maxhei/2);
}
int arr[lim]; //distance from root
int in;

void dfs(int node,int par,int cst)
{
    arr[++in]=cst;
    int i;
    for(i=0;i<SZ(adj[node]);i++)
    {
        //print1(v);
        int v=adj[node][i];
        if(v==par||used[v]) continue;
        dfs(v,node,cst+cost[node][i]);
    }
}

bool comp(int a,int b)
{
    return a<b;
}

int temans(int l,int r)
{
    //print3("range",l,r);
    int j=r,ret=0;
    for(int i=l;i<=r;i++)
    {
        //print3("here",arr[i],arr[j]);
        while(arr[i]+arr[j]>K&&j>i) j--;
        ret+=(j-i);
        if(i==j) break;
    }
    return ret;
}


int getans(int n)
{
    int ans=0;
    mem(used,false);
    int cnt=n;
    while(cnt)
    {
        int i;
        fr(i,1,n)
        if(!used[i]) break;
        int center=centeroftree(i);
        cnt--;
        used[center]=true;
        in=0;
        for(i=0;i<SZ(adj[center]);i++)
        {
            int v=adj[center][i];
            if(used[v]) continue;
            int st=in+1;
            dfs(v,center,cost[center][i]);
            sort(arr+st,arr+in+1,comp);
            ans-=temans(st,in);
        }
        //print3("before",center,ans);
        arr[++in]=0;
        sort(arr+1,arr+in+1,comp);
        ans+=temans(1,in);
        //print3(center,ans,in);
    }
    return ans;
}


int main()
{
    //srand(time(NULL));
    //freopen("A.txt","r",stdin);
    //freopen("B.txt","w",stdout);
    int i,n;
    while(cin>>n>>K&&(n||K))
    {
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            cost[i].clear();
        }

        int a,b,c;
        for(i=1;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            adj[a].pb(b);
            adj[b].pb(a);
            cost[a].pb(c);
            cost[b].pb(c);
        }

        print1(getans(n));
    }
    return 0;
}
