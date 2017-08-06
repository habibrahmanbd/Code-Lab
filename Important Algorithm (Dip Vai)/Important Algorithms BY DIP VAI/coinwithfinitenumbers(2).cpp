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
//minimum coin required
#define s 50010
bool col[s];
long long prime[s];

int seive()//1 indexed
{
    long long i,j,k;
    col[0]=true;
    col[1]=true;
    k=0;
    prime[++k]=2;
    for(j=4;j<s;j+=2)
        col[j]=true;
    for(i=3;i<s;i+=2)
         if(!col[i])
         {
                prime[++k]=i;
                for(j=i*i;j<s;j+=2*i)
                    col[j]=true;
         }
    return 0;
}
int parent[s][74],mark[s],t,countt[s],maxhei[s],prev[s];
VI adj[s];

void dfs1(int node,int par,int h)
{
    int i;
    parent[node][0]=par;
    for(i=0;i<=71;i++)
        parent[node][i+1]=parent[par][i];
    for(i=0;i<SZ(adj[node]);i++)
    {
        int tem=adj[node][i];
        if(tem==par) continue;
        dfs1(tem,node,h+1);
        maxhei[node]=max(maxhei[node],maxhei[tem]+1);
    }
}

bool comp(int p,int q)
{
    return maxhei[p]<maxhei[q];
}

void dfs(int node,int par,int h)
{
    int i;
    for(i=0;i<SZ(adj[node]);i++)
    {
        int tem=adj[node][i];
        if(tem==par) continue;
        dfs(tem,node,h+1);
    }
    mark[node]=(++t);
    countt[t]=(++prev[h]);
}
int ans,last[s];

void dfs2(int node,int par,int h,int in,int ses)
{
    int i,st=prime[in]-prime[in-1];
    int add=last[parent[node][st-1]];
    if(h<st) st=h;
    st--;
    for(i=st;i>=0;i--) //count for this node
    {
        int tem=parent[node][i];
        int need=prime[in]-i-1;
        if(maxhei[tem]<need) break;
        if(need==0) add++;
        else if(ses==tem) break; //same height
        else if(i>0)
        {
            add+=countt[mark[tem]-need];
            int tem2=parent[node][i-1];
            if(maxhei[tem2] >= need-1)add-=countt[mark[tem2]-need+1];
        }
        else
        {
            add+=countt[mark[tem]-need];
            //print3(node,i,add);
            if(maxhei[node] >= need-1) add-=countt[mark[node]-need+1];
        }
    }

    for(i=0;i<SZ(adj[node]);i++)
    {
        int tem=adj[node][i];
        if(tem==par) continue;
        if(i==SZ(adj[node])-1) dfs2(tem,node,h+1,in,node);
        else dfs2(tem,node,h+1,in,ses);
    }
    ans+=add;
    last[node]=add;
    //if(in==2) print2(node,add);
}


int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    seive();
    int n;
    cin>>n;
    int i,a,b;
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs1(1,0,0);
    fr(i,1,n)
        sort(BE(adj[i]),comp);
    dfs(1,0,0);
    int prevans=0;
    for(i=1;prime[i];i++){
        dfs2(1,0,0,i,0);
        if(ans==prevans) break;
        prevans=ans;
        //print2(i,ans);
    }
    int tot=(n*(n-1))/2;
    printf("%.12lf\n",(1.0*ans)/tot);
    return 0;
}
/*
7
1 2
1 3
1 4
1 5
2 6
3 7
*/
