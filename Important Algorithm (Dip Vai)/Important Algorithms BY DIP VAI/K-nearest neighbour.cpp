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

#define csprnt printf("Case #%d: ", ++cas);
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
//it can be viewed as multidimensional binary search tree
//dimension 0 based
//all distance are euclidian distance
#define dimension 3
#define lim 100010
struct co{
   LL x[dimension];
};
co arr[lim];

struct node{
   co now;
   //for left and right child
   int left;
   int right;
};
node bst[lim];
int axis;

bool comp(co p,co q)
{
    return p.x[axis]<q.x[axis]; //sort in terms of axis direction
}

//overall complexity n(logn)^2
void kdtree(co arr[],int st,int end,int depth,int &bstindex)
{
    if(st>end) return;
    axis=depth%dimension;
    sort(arr+st,arr+end+1,comp); //can be done in nlogn time by making optimizing here
    //debug_array(arr,9);
    int median=(st+end)/2;
    ++bstindex;
    int previndex=bstindex;
    bst[previndex].now=arr[median];

    if(median!=st) bst[previndex].left=bstindex+1;
    else bst[previndex].left=0;
    kdtree(arr,st,median-1,depth+1,bstindex);

    if(median!=end) bst[previndex].right=bstindex+1;
    else bst[previndex].right=0;
    kdtree(arr,median+1,end,depth+1,bstindex);
}

LL dist(co p,co q)  //taking square distance
{
    int i;
    LL ret=0;
    for(i=0;i<dimension;i++)
        ret+=(p.x[i]-q.x[i])*(p.x[i]-q.x[i]);
    return ret;
}

//normally k+logn complexity (not sure)
void KNN(int bstnode,int bstindex,int depth,co query,int k,priority_queue<LL> &Q) //kth nearest
{
    if(bstnode>bstindex) return;
    Q.push(dist(bst[bstnode].now,query));
    if(Q.size()>k) Q.pop();

    axis=depth%dimension;
    LL chc=bst[bstnode].now.x[axis]-query.x[axis];
    if(chc>=0) //go to left
    {
        KNN(bst[bstnode].left,bstindex,depth+1,query,k,Q);
        //special attention to > sign (sometimes >=)
        if(Q.top()>chc*chc || Q.size()<k)  //there is a chance of less
            KNN(bst[bstnode].right,bstindex,depth+1,query,k,Q);
        return;
    }

    //go to right
    KNN(bst[bstnode].right,bstindex,depth+1,query,k,Q);
    //special attention to > sign (sometimes >=)
    if(Q.top()>chc*chc || Q.size()<k)  //there is a chance of less
        KNN(bst[bstnode].left,bstindex,depth+1,query,k,Q);
    return;
}

//normally logn complexity
void KNN2(int bstnode,int bstindex,int depth,co &query,LL high,priority_queue<LL> &Q) //number of points with sqrt(high) distance
{
    if(!bstnode) return;
    //if(bstnode) debug(bst[bstnode].now.x[0],bst[bstnode].now.x[1],bst[bstnode].now.x[2]);
    if(bstnode>bstindex) return;
    Q.push(dist(bst[bstnode].now,query));
    if(Q.top()>=high) Q.pop();

    axis=depth%dimension;
    LL chc=bst[bstnode].now.x[axis]-query.x[axis];
    //print2(chc,query.x[0]);
    if(chc>=0) //go to left
    {
        KNN(bst[bstnode].left,bstindex,depth+1,query,high,Q);
        //special attention to > sign (sometimes >=)
        if(chc*chc<high)  //there is a chance of less
            KNN(bst[bstnode].right,bstindex,depth+1,query,high,Q);
        return;
    }

    //go to right
    KNN(bst[bstnode].right,bstindex,depth+1,query,high,Q);
    //special attention to > sign (sometimes >=)
    if(chc*chc<high)  //there is a chance of less
        KNN(bst[bstnode].left,bstindex,depth+1,query,high,Q);
    return;
}


int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    int n,k;
    while(cin>>n>>k &&(n||k))
    {
        int i;
        fr(i,1,n)
            scanf("%lld %lld %lld",&arr[i].x[0],&arr[i].x[1],&arr[i].x[2]);
        int bstindex=0;
        kdtree(arr,1,n,0,bstindex);
        int ans=0;
        for(i=1;i<=n;i++)
        {
            priority_queue<LL>q;
            KNN(1,bstindex,0,arr[i],(LL)k*(LL)k,q);
            ans+=q.size()-1;
        }
        ans/=2;
        printf("%d\n",ans);
    }
    return 0;
}
/*
Input :-
7 2
0 0 0
1 0 0
1 2 0
1 2 3
1000 1000 1000
1001 1001 1000
1001 999 1001
7 3
0 0 0
1 0 0
1 2 0
1 2 3
-1000 1000 -1000
-1001 1001 -1000
-1001 999 -1001
7 4
0 0 0
1 0 0
1 2 0
1 2 3
1000 -1000 1000
1001 -1001 1000
1001 -999 1001
Output :
3
6
9
*/

