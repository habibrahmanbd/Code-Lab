#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char m[200],n[200],sm,sn;
int dp[200][200];

int LCS()
{
    int i,j;
    for(i=0;i<sm;i++)
        {
            if(m[i]==n[0])
                dp[i][0]=1;
            else if(i)
                dp[i][0]=dp[i-1][0];
            else
                dp[0][0]=0;
        }
        for(j=1;j<sn;j++)
        {
            if(m[0]==n[j])
                dp[0][j]=1;
            else
                dp[0][j]=dp[0][j-1];
        }
        for(i=1;i<sm;i++)
            for(j=1;j<sn;j++)
            {
                if(m[i]==n[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
       return 0;
}

int main()
{
    int i,j;
    while(gets(m)&&gets(n))
    {
        if(m[0]=='#')
            break;
        sm=strlen(m);
        sn=strlen(n);
        LCS();
        printf("%d\n",dp[sm-1][sn-1]);
    }
    return 0;
}
