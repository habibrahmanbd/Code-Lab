#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

typedef struct
{
    int a,b;
}student;

bool comb(student x,student y)
{
    if(x.a>y.a)
        return false;
    return true;
}

student c[100];

int main()
{
    int n,i,j;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%d %d",&c[i].a,&c[i].b);
        sort(&c[0],&c[n],comb);
        for(i=0;i<n;i++)
            printf("%d %d\n",c[i].a,c[i].b);
    }
    return 0;
}
