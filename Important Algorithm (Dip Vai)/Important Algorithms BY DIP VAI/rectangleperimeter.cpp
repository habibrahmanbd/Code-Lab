#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>

#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 12010 //number of rectangles*2
#define ll long long
#define INF (1<<30)
#define pii pair<int, int>
#define MP make_pair

using namespace std;

struct cord1
{
	int x, y1, y2, val; //val for starting or ending
	cord1(int _x=0, int _y1=0, int _y2=0, int _val=0)
	{
		x=_x, y1=_y1, y2=_y2, val=_val;
	}
};

struct cord2
{
	int y, x1, x2, val; //val for starting or ending
	cord2(int _y=0, int _x1=0, int _x2=0, int _val=0)
	{
		y=_y, x1=_x1, x2=_x2, val=_val;
	}
};
cord1 pnt1[MAX];
cord2 pnt2[MAX];
int ans[4*MAX], upd[4*MAX];
vector<int>y,x;

bool cmp1(cord1 a, cord1 b)
{
	if(a.x==b.x) return (a.val > b.val);
	return (a.x < b.x);
}

bool cmp2(cord2 a, cord2 b)
{
	if(a.y==b.y) return (a.val > b.val);
	return (a.y < b.y);
}

int updatey(int node, int st, int end, int i, int j, int val)
{
	if(j<=y[st] || i>=y[end]) return ans[node];
	if(y[st]>=i && y[end]<=j)
	{
		upd[node]+=val;
		if(upd[node])
			return ans[node] = y[end]-y[st];
		else
		{
			if(end-st==1)
				return ans[node]=0;
			else
				return ans[node] = ans[2*node]+ans[2*node+1];
		}
	}
	int mid=(st+end)>>1, ret1, ret2;
	ret1 = updatey(2*node, st, mid, i, j, val);
	ret2 = updatey(2*node+1, mid, end, i, j, val); //special attention to mid
	if(upd[node]==0) ans[node] = ret1+ret2;
	else ans[node]=y[end]-y[st];
	return ans[node];
}

int updatex(int node, int st, int end, int i, int j, int val)
{
	if(j<=x[st] || i>=x[end]) return ans[node];
	if(x[st]>=i && x[end]<=j)
	{
		upd[node]+=val;
		if(upd[node])
			return ans[node] = x[end]-x[st];
		else
		{
			if(end-st==1)
				return ans[node]=0;
			else
				return ans[node] = ans[2*node]+ans[2*node+1];
		}
	}
	int mid=(st+end)>>1, ret1, ret2;
	ret1 = updatex(2*node, st, mid, i, j, val);
	ret2 = updatex(2*node+1, mid, end, i, j, val); //special attention to mid
	if(upd[node]==0) ans[node] = ret1+ret2;
	else ans[node]=x[end]-x[st];
	return ans[node];
}


int main()
{
    int n;
    while(scanf("%d", &n)==1)
    {
		y.clear();
		int i, j, x1, y1, x2, y2, cnt1=0, cnt2=0, n1, n2;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			pnt1[cnt1++] = cord1(x1, y1, y2, 1);
			pnt1[cnt1++] = cord1(x2, y1, y2, -1);
			pnt2[cnt2++] = cord2(y1, x1, x2, 1);
			pnt2[cnt2++] = cord2(y2, x1, x2, -1);
			y.pb(y1), y.pb(y2);
			x.pb(x1), x.pb(x2);
		}
		sort(y.begin(), y.end());
		y.resize(unique(y.begin(), y.end())-y.begin());
		n1 = SZ(y);
		sort(&pnt1[0], &pnt1[0]+cnt1, cmp1);
		sort(x.begin(), x.end());
		x.resize(unique(x.begin(), x.end())-x.begin());
		n2 = SZ(x);
		sort(&pnt2[0], &pnt2[0]+cnt2, cmp2);

		int sum=0,prev;
		memset(ans, 0, sizeof ans);
		memset(upd, 0, sizeof upd);
		prev=0;
		for(i=0;i<cnt1;i++)
		{
			updatey(1, 0, n1-1, pnt1[i].y1, pnt1[i].y2, pnt1[i].val);
			sum+=abs(ans[1]-prev);
			prev=ans[1];
		}

		memset(ans, 0, sizeof ans);
		memset(upd, 0, sizeof upd);
		prev=0;
		for(i=0;i<cnt2;i++)
		{
			updatex(1, 0, n2-1, pnt2[i].x1, pnt2[i].x2, pnt2[i].val);
			sum+=abs(ans[1]-prev);
			prev=ans[1];
		}
		printf("%d\n", sum);
    }
    return 0;
}

