/// Syed Shahriar Manjur (Dip)
//#pragma warning (disable: 4786)
/*
UVALive 6745 	Traitor
According to an intelligence source, we’ve got a traitor in ACM Security Agency (ASA). ASA has
a hierarchical structure where each agent has a manager and there are also some (at least one) top
managers who are not managed by anyone. Our source doesn’t exactly know the traitor, but he has a
list of suspects. Therefore, all we know is that there is exactly one traitor in our agency and we have a
list of suspects. In order to find that traitor, we want to assign a watcher for each suspect, satisfying
the following three conditions:
1. Two suspects cannot watch each other.
2. Each suspect should be watched by either his manager or one of his direct employees.
3. Nobody can watch more than one suspect.
If we want to satisfy all above conditions, it may be impossible to watch all suspects. Therefore,
you should write a program that gets the structure of ASA and the list of suspects as the input and
finds the maximum number of suspects for whom the watcher assignment is possible. In the following
figure that illustrates the organizational structure of ASA with two top managers and eleven agents, the
suspects are indicated with gray color. One watcher assignment covering 7 out of 8 suspects is possible
in this case which is shown by arrows. An arrow from agent x to agent y, means agent x is supposed
to watch agent y. It can be shown that in this example there is no watcher assignment covering all
suspects.
Input
There are multiple test cases in the input. The first line of each test case contains two integers n
(1 ≤ n ≤ 10, 000) specifying the number of agents, and k (≤ k ≤ n) specifying the number of the
suspected agents. The agents are numbered from 1 to n. On the second line there are space-separated
integers, where the i-th number is the number of agent who is the manger of the agent i. A zero means
the agent i is a top manager. On the third line there are k positive integers s1, s2, . . . , sk, indicating
the numbers of the suspected agents. The input terminates with ‘0 0’ which should not be processed.
Output
For each test case, output in a line the maximum number of suspects for whom the watcher assignment
is possible.ACM-ICPC Live Archive: 6745 – Traitor 2/2
Sample Input
11 8
3 4 4 0 6 8 9 11 11 11 0
3 2 8 9 6 5 7 11
2 2
0 1
1 2
0 0
Sample Output
7
1
*/
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

#define csprnt printf("Case %d: ", ++cas);
#define mod         1000000007
#define eulerconstant 0.5772156649

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
#define lim 11000
#define INF 1000000000
VI adj[lim];
VI root;
bool suspect[lim];
int dp[lim][3][3];
int dp2[lim][4];
bool col[lim][4];
int nextsibling[lim];

int dprec(int node,int child,int bit)
{
    if(child==-1)
    {
        if(bit==3) return 0;
        return -INF;
    }

    int &ret=dp2[child][bit];
    if(col[child][bit]) return ret;
    col[child][bit]=true;
    ret=dprec(node,nextsibling[child],bit)+dp[child][0][0]; //taking the maximum of the child
    if(!(bit&2))
        ret=max(ret,max(dp[child][1][1],dp[child][1][2])+1+dprec(node,nextsibling[child],bit|2));

    if(!(bit&1) && suspect[child])
        ret=max(ret,max(dp[child][1][1],dp[child][2][1])+1+dprec(node,nextsibling[child],bit|1));
    return ret;
}

void dfs(int node)
{
    int i;
    int start=-1,prev;
    for(i=0;i<SZ(adj[node]);i++)
    {
        int tem = adj[node][i];
        dfs(tem);
        if(start==-1)
            start=tem;
        else nextsibling[prev]=tem;
        prev=tem;
    }

    //not guarding,not being guarded
    dp[node][1][1]=dprec(node,start,3);
    dp[node][0][0]=dp[node][1][1];
    //guarding,not being guarded
    dp[node][2][1]=dprec(node,start,2);
    dp[node][0][0]=max(dp[node][0][0],dp[node][2][1]);

    if(!suspect[node]) return;

    //not guarding,being guarded
    dp[node][1][2]=dprec(node,start,1);
    dp[node][0][0]=max(dp[node][0][0],dp[node][1][2]);
    //guarding,being guarded
    dp[node][2][2]=dprec(node,start,0);
    dp[node][0][0]=max(dp[node][0][0],dp[node][2][2]);
}


int main()
{
    //srand(time(NULL));
    //freopen("A.txt","r",stdin);
    //freopen("B.txt","w",stdout);
    int n,k;
    while(cin>>n>>k&&(n||k))
    {
        int i;
        for(i=1;i<=n;i++)
            adj[i].clear();
        root.clear();
        mem(suspect,false);
        mem(dp,0);
        mem(dp2,0);
        mem(col,false);
        mem(nextsibling,-1);

        int a;
        fr(i,1,n)
        {
            scanf("%d",&a);
            if(a==0) root.pb(i);
            else adj[a].pb(i);
        }

        fr(i,1,k)
        {
            scanf("%d",&a);
            suspect[a]=true;
        }

        int ans=0;
        for(i=0;i<SZ(root);i++)
        {
            dfs(root[i]);
            ans+=dp[root[i]][0][0];
        }
        print1(ans);
    }
    return 0;
}
