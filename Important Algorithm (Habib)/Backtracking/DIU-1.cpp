#include<stdio.h>
#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
struct item
{
	int x, y, z;
};

struct Queue
{
	int x[1000], y[1000],z[1000];
	int front=0, back=0;

	void push(struct  item it)
	{
		x[back] = it.x;
		y[back] = it.y;
		z[back] = it.z;
		back++;
	}
	void pop()
	{
		front++;
	}

	struct item top()
	{
		struct  item ret;
		ret.x = x[front];
		ret.y = y[front];
		ret.z = z[front];
		return ret;
	}

	int empty()
	{
		if(front>=back)
			return 1;
		else
			return 0;
	}
	~Queue(){}
};

int pos[21][21];
int vis[21][21];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int BFS(int x, int y)
{
	int i, j;
	for(i=0; i<21; i++)
		for(j=0; j<21; j++)
			vis[i][j]=0;
	
	int Ans=0;
	
	Queue Q;
	
	item a;
	
	a.x=x;
	a.y=y;
	a.z=0;
	
	Q.push(a);

	while(!Q.empty())
	{
		item cur = Q.top();
		vis[cur.x][cur.y]=1;
		Q.pop();
		for(i=0; i<4; i++)
		{
			if(!vis[cur.x+dx[i]][cur.y+dy[i]] && cur.x+dx[i]<=20 && cur.y+dy[i]<=20)
			{
				item v;
				v.x = cur.x+dx[i];
				v.y = cur.y+dy[i];
				v.z = cur.z+1;
				Q.push(v);
				if(pos[v.x][v.y]==1)
					Ans = max(Ans, v.z);
			}
		}
	}
	return Ans;
}


int main()
{
	int x, y, i, j, it=0;
	int cellLoc;
	scanf("%d",&cellLoc);

	int Arr[cellLoc][cellLoc];
	
	for(i=0; i<cellLoc; i++)
		for(j=0; j<cellLoc; j++)
			scanf("%d", &Arr[i][j]);
	
	int rare;
	scanf("%d",&rare);
	
	for(i=0; i<rare; i++){
		scanf("%d %d", &x, &y);
		pos[x][y]=1;
	}
	int Ans = 123456787;
	for(i=0; i<cellLoc; i++)
		for(j=0; j<cellLoc; j++)
			if(Arr[i][j]==1)
				Ans = min(Ans, BFS(i, j));
	printf("%d\n", Ans);
	return 0;
}