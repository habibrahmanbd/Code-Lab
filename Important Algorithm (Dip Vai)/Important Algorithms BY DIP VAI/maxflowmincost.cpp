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
#define SZ(s)      (int)s.size()
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

#define mo          1000
#define inf         10000000
//only adj matrix and w matrix should be changed
//minimum capacity should be 0(initially given)
//complexity VE^2
struct pq
{
	int cost,node; //cost per unit
	bool operator<(const pq &b)const
	{
		return cost>b.cost;    // Min Priority Queue(b is own)
	}
};
vector<pq>adj[mo];//input(clear and have to fill)
int w[mo][mo];//input(clear and have to fill) (flow)
bool col[mo];
int par[mo];//par and col for parent and visited respectively
int totflow,flow,totcost;//flow related variables.(not needed normally)

bool augment_path(int source,int sink,int nodes) // return true if there is positive flow
{
    priority_queue<pq>Q;
    vector<int>dist;
	 pq U,V;
    int i,prev,next,cost;

    for(i=0;i<=nodes;i++) //distance\cost from source per unit
	 {
		dist.push_back(inf);
	 }
    dist[source]=0;
	 V.node=source;
	 V.cost=0;
	 Q.push(V);
    mem(par,-1);

    while(Q.size())
    {
        U=Q.top();Q.pop();
		  prev=U.node;
        //if(prev==sink) break; if all edges are non-negative then it can be kept
        if(U.cost>dist[prev]) continue; //for finding the latest

        for(i=0;i<SZ(adj[prev]);i++)
        {
            next=adj[prev][i].node;
            cost=adj[prev][i].cost;
            if(w[prev][next]>0&&dist[prev]+cost<dist[next]) //djkstra system so no color needed(shortest will not come back again)
            {
                dist[next]=dist[prev]+cost;
                V.node=next;
                V.cost=dist[next];
                Q.push(V);
                par[next]=prev;
            }
        }
    }

    next=sink;
    flow=inf;
    while(par[next]>-1)
    {
        prev=par[next];
        flow=min(flow,w[prev][next]);
        next=prev;
    }

    next=sink;
    while(par[next]>-1)
    {
        prev=par[next];
        w[prev][next]-=flow;
        w[next][prev]+=flow;
        next=prev;
    }

    if(flow>=inf) return false;//flow 0
    totcost+=flow*dist[sink];
    return true;//flow not 0
}

void maxflow(int source,int sink,int nodes) //nodes=total nodes-1 (0 based)
{
    totcost=0;
    totflow=0;
    while(augment_path(source,sink,nodes))
       totflow+=flow;
    return;
}

void makeedge(int a,int b,int fl,int cost)
{
   pq U,V;
   U.node=a;
   U.cost=-cost;
   V.node=b;
   V.cost=cost;
   adj[a].pb(V);
   adj[b].pb(U);
   w[a][b]=fl;
   w[b][a]=0;
}


int main()
{
    int n;
    int e;
    while(cin>>n>>e)
    {

    }
    return 0;
}

