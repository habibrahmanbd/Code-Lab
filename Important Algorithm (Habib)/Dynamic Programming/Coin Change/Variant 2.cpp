way[0]=1;
for(i =1 ; i<=n; i++)
    for(j=1; j<=k; j++)
        if(i>=coin[j])
            way[i] += way[i-coin[j]];
