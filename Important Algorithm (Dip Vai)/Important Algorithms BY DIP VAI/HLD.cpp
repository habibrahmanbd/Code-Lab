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
#define cntbit(mask) __builtin_popcount(mask)
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}

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
//1348 - Aladdin and the Return Journey
//Works in every based(0/1) index
//complexity n(logn)^2
#define MAXN 32000
#define step 17    // step=log(n)
//normally call dfs(1,1)
//normally call hld(1,1,1)

//used for LCA
int n,parent[MAXN][step+1],start[MAXN],finish[MAXN],T;// T = time
VI adj[MAXN];
//used for HLD
int child[MAXN],nodeId,firstNode[MAXN],currentIndex[MAXN];
//used for segment tree
//1 based index is used here
int tree[MAXN];
int MaxVal;//always should be set(size of the set len)

//cumulitive sum
int queryBIT(int idx){
    if(idx<=0) return 0;
	int sum = 0;
	idx =min(idx,MaxVal);
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void updateBIT(int idx ,int val){
    if(idx<=0) return;
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

void initialize(int n)
{
    int i;
    for(i=0;i<=n;i++)
        adj[i].clear();
    T=0;
    nodeId=0;
    MaxVal = n;
}

int dfs(int u,int p)
{
    int i,v;

    start[u]=T++;

    parent[u][0]=p;  //recursively defined
    for(i=1;i<=step;i++)
        parent[u][i]=parent[parent[u][i-1]][i-1];

    child[u]=1;
    fr(i,0,SZ(adj[u])-1)
    {
        v=adj[u][i];
        if(v==p) continue;
        child[u]+=dfs(v,u);
    }
    finish[u]=T++;
    return child[u];
}

bool isAnchestor(int u,int v) //Is u ancestor of v including himself
{
    if(start[u]<=start[v] && finish[u]>=finish[v]) return true;
    return false;
}

int lca_query(int u,int v)
{
    int w=-1,temp=u;

    if(isAnchestor(u,v)) w=u;
    if(isAnchestor(v,u)) w=v;

    if(w==-1)
    {
        for(int i=step;i>=0;i--)
            if(!isAnchestor(parent[temp][i],v))
                temp=parent[temp][i];
        w=parent[temp][0];
    }
    return w;
}

int hld(int u,int p,int lastNode)
{
    currentIndex[u] = (++nodeId);
    firstNode[u] = lastNode;

    int ind = -1,ma = -1;
    int i;
    fr(i,0,SZ(adj[u])-1)
    {
        int v=adj[u][i];
        if(v==p) continue;
        if(ma>=child[v]) continue;
        ma = child[v];
        ind = i;
    }

    if(ind >= 0) hld( adj[u][ind],u,lastNode ); //same segment

    fr(i,0,SZ(adj[u])-1)
    {
        int v=adj[u][i];
        if(v==p) continue;
        if(i==ind) continue;
        hld(v,u,v);
    }
}
int arr[MAXN];

//u should be upper node (close to root)
int query_up(int u, int v)
{
    int ans = 0;
    while(true)
    {
        int y = currentIndex[v];
        int x = currentIndex[firstNode[v]];
        int z = currentIndex[u];
        if(z>=x && z<=y)
        {
            x=z;
            ans+=queryBIT(y)-queryBIT(x-1);
            break;
        }
        ans+=queryBIT(y)-queryBIT(x-1);
        v = parent[firstNode[v]][0];
    }
    return ans;
}

int query(int u,int v)
{
    int lcanode=lca_query(u,v);
    return query_up(lcanode,u)+query_up(lcanode,v)-query_up(lcanode,lcanode);
}

void update(int u,int x)
{
    int curval = queryBIT(currentIndex[u])-queryBIT(currentIndex[u]-1);
    x-=curval;
    updateBIT(currentIndex[u],x);
}


int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        int i;
        int n;
        cin>>n;
        initialize(n);
        for(i=0;i<=n-1;i++)
        {
            scanf("%d",&arr[i]);
        }

        int a,b;
        for(i=1;i<=n-1;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].pb(b);
            adj[b].pb(a);
        }

        dfs(0,0);
        hld(0,0,0);
        MaxVal=nodeId+1;
        for(i=0;i<=n-1;i++)
            update(i,arr[i]);
        int q;
        cin>>q;
        int d;
        printf("Case %d:\n",++cas);
        fr(i,1,q)
        {
            scanf("%d",&d);
            if(d==0)
            {
                scanf("%d %d",&a,&b);
                printf("%d\n",query(a,b));
            }
            else
            {
                scanf("%d %d",&a,&b);
                update(a,b);
            }
        }
    }
    return 0;
}
/*
// Copyright (C) 2012, LamPhanViet
/* Test Cases:
3
4
10 20 30 40
0 1
1 2
1 3
6
0 2 3
1 1 100
0 2 3
0 0 3
0 3 0
0 0 2

7
0 1 2 3 4 5 6
0 6
0 1
1 5
1 2
2 3
3 4
4
0 0 4
0 4 6
0 5 6
0 3 4

11
0 1 2 3 4 5 6 7 8 9 10
0 1
1 3
1 2
2 4
2 5
5 6
6 7
6 8
6 9
6 10
1
0 4 6
// Answer:
// Case 1:
// 90
// 170
// 150
// 150
// 140
// Case 2:
// 10
// 16
// 12
// 7
// Case 3:
// 17
*/
