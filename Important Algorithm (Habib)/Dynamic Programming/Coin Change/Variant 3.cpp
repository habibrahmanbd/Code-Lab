///O(n^2) memory
dp[0][0]=1;
for(j=1 ; j<=k; j++)
    for(i=1; i<=n; i++)
        if(dp[j-1][i]|| (i>=coin[j] && dp[j-1][i-coin[j]))
            dp[j][i]=1;
///O(n) memory
dp[0]=1;
for(j=1 ; j<=k; j++)
    for(i=n; i>=1; i--)
        if(i>=coin[j] && dp[i-coin[j])
            dp[i]=1;
