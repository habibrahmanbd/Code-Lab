///O(n) memory
dp[0]=1;
for(j=1 ; j<=k; j++)
    for(i=n; i>=1; i--)
        if(i>=coin[j])
            dp[i]+=dp[i-coin[j]];
