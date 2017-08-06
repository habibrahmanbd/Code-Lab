/*******************************
*   Bismillah hir Rohmanir Rahim *
*   Habibur Rahman Habib        *
*   Dept. of CSE, RUET          *
*   habib_cse_ruet@yahoo.com  *
********************************/

using namespace std;
//C headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//C++ headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
//type def
#define PI 2*acos (0.0)
typedef long long int64;
typedef unsigned long long int64u;
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
#define MAX(p,q) p>q?p:q
#define MIN(p,q) p<q?p:q
#define MOD 100000007
#define INF 1<<29
//Intput_Output
#define input freopen ("in.txt", "r", stdin);
#define output freopen ("output.txt", "w", stdout);
#define co cout
#define ci cin
#define II ({ int a; scanf("%d",&a); a;}) //Integer Input
#define IL ({ int64 a; scanf("%lld",&a);  a;})  //Long Integer Input
#define ID ({ db a; scanf("%lf",&a);  a;}) //Double input
#define IC ({ char a; scanf("%c",&a);  a;}) //Character Input
#define IS ({ string a; cin >> a;  a;}) //String input
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;}) //Char-Array Input
#define OC(cs) printf("Case %d:",cs);  //Case Input
//Loops.....
#define FOR(p, n, m) for(long int i=p; i<=n; i+=m)  //For Loop increment
#define FOR_R(p, n, m) for(long int j=p; j>=n; j-=m)  //For loop decrement
//Problem wise define.....
#define mx 10001
long arr[mx];
long tree[mx*3];
void init(int node, int b,int e)
{
    if(b==e){
        tree[node] = arr[b];
        return;
    }
    int left = node*2;
    int right = 2*node+1;
    int mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node]=tree[left]+tree[right];
}
int query(int node, int b, int e, int i, int j)
{
    if(i>e||j<b) return 0;
    else if(b>=i&&e<=j) return tree[node];
    int left = node*2;
    int right = 2*node+1;
    int mid = (b+e)/2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);
    return p1+p2;
}
void update(int node, int  b, int e, int i, int newvalue)
{
    if(i>e||i<b) return ;
    else if(b>=i&&e<=i) {
        tree[node] = newvalue;
        return;
    }
    int left = node*2;
    int right = 2*node+1;
    int mid = (b+e)/2;
    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);
    tree[node]  = tree[left] + tree[right];
}
int main()
{
    co<<"Enter your new array size";
    int n=II;
    FOR(1,n,1)
    arr[i]=II;
    init(1,1,n);
    co<<"Enter from positon to position Query\n";
    //query before update.....
    int p=II, data=II;
    int q_res = query(1,1,n, p,data);
    co<<"Query result : "<<q_res<<endl;

    //Updating.....
    co<<"Enter  positon to update new value\n";
    p=II, data=II;
    update(1, 1, n, p, data);

    //Updating after value

    co<<"Enter from positon to position Query\n";
    p=II, data=II;
    q_res = query(1,1,n, p,data);
    co<<"Query result : "<<q_res<<endl;
    return 0;
}
