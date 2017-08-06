#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
struct co{
  int x;
  int y;
};
int n,col[100][100],check,kase;
queue<co>q;
char set[100][100];
int row[]={-1,-1,-1,0,0,1,1,1};
int clm[]={-1,0,1,-1,1,-1,0,1};

int bfsprocess(int i,int j)
{
    co tem;
    int a,b;
    int k;
    for(k=0;k<8;k++)
    {
        a=i+row[k];
        b=j+clm[k];
        if(!col[a][b]  &&  a>=0  &&  b>=0  &&  a<n  &&  b<n  &&  set[a][b]=='1')
        {
            tem.x=a;
            tem.y=b;
            q.push(tem);
            col[a][b]=true;
        }
    }
    return 0;
}

void bfs(int i,int j)
{
    col[i][j]=true;
    co tem;
    tem.x=i;
    tem.y=j;
    q.push(tem);
    while(!q.empty())
    {
        bfsprocess(q.front().x,q.front().y);
        q.pop();
    }
    check++;
}


int main()
{
    int i,j;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf(" %c",&set[i][j]);
        memset(col,false,sizeof(col));
        check=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(set[i][j]=='1'  &&  !col[i][j])
                    bfs(i,j);
        printf("Image number %d contains %d war eagles.\n",++kase,check);
    }
    return 0;
}
