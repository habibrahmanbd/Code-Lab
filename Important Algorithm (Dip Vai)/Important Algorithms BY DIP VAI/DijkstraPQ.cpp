#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
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

#define SIZE 1001
#define INF 2000000000
#define white 0
#define black 1

struct pq
{
	int cost,node;
	bool operator<(const pq &b)const
	{
		return cost>b.cost;    // Min Priority Queue(b is curret)
	}
};

vector<pq>adj[SIZE];//need to clear
int Color[SIZE];//no need to clear

//0 based
vector<int> Dijkstra(int source,int nodes) //source starts from 0 and nodes is total node numbererd (0 to n)
{
	priority_queue<pq>Q;
	vector<int>dist;
	pq U,V;
	int i,u,v,cost;

    memset(Color,white,sizeof(Color)); //white and black
	for(i=0;i<=nodes;i++) //distance from source
	{
		dist.push_back(INF);
	}
	dist[source]=0;
	V.node=source;
	V.cost=dist[source];
	Q.push(V);
	while(!Q.empty())
	{
		U=Q.top();Q.pop(); //picking the top only(no use of U later)
		u=U.node;
		if(Color[u]==white)
		{
            for(i=0;i<adj[u].size();i++)
            {
                v=adj[u][i].node;
                cost=adj[u][i].cost;
                if(dist[u]+cost<dist[v])
                {
                    dist[v]=dist[u]+cost;
                    V.node=v;
                    V.cost=dist[v];
                    Q.push(V);
                }
            }
            Color[u]=black;
		}
	}
	return dist;
}


int main()
{
	int nodes,edges,i,u,v,cost,source,t,des;
	pq V;//for pushback
	vector<int>dist;
    scanf("%d",&t);
	while(t--)
	{
	    scanf("%d %d",&nodes,&edges);
	    scanf("%d %d",&source,&des);
		for(i=0;i<=nodes;i++)
		{
			adj[i].clear(); //clear adj vector
		}
		for(i=0;i<edges;i++)
		{
			scanf("%d %d %d",&u,&v,&cost);
			V.cost=cost;
			V.node=v;
			adj[u].push_back(V);
			V.node=u;				//For Bidirectional Edges
			adj[v].push_back(V);
		}
		//scanf("%d",&source);
		dist=Dijkstra(source,nodes);
		/*for(i=0;i<nodes;i++)
		{
			cout<<dist[i]<<" ";
		}
		cout<<endl;*/
		if(dist[des]!=INF)
		  printf("%d\n",dist[des]);
		 else
		 printf("-1\n");
	}

	return 0;
}

/*
Input:
6 9
0 1 4
0 2 2
1 2 1
1 3 5
2 3 8
2 4 10
3 5 6
3 4 2
4 5 3
0
Output:

Shortest Path All the Node Frome Source:0
0 3 2 8 10 13
*/
