#include<stdio.h>
#include<string.h>
#define s 1000000
int a[s],seq[s],dp[s];
int n,check,ma;

int LIS()
{
    int i,j;
    for(i=0;i<n-1;i++)
          for(j=i+1;j<n;j++)
              if(a[i]<a[j]  &&  dp[i]>=dp[j])
              {
                  dp[j]=dp[i]+1;
                  seq[j]=i;
              }
    for(i=0;i<n;i++)
          if(dp[i]>ma)
          {
              ma=dp[i];
              check=i;
          }
    return 0;
}


int main()
{
    int i,j;
    while(scanf("%d",&n)==1)
    {
        memset(dp,0,n*sizeof(int));
        ma=-1;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        LIS();
        printf("%d\n",ma+1);
    }
    return 0;
}
