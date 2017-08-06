possible[0]=1;
for(i =1 ; i<=n; i++)
    for(j=1; j<=k; j++)
        if(i>=coin[j])
            possible[i]|=possible[i-coin[j]];
