//Let, Number of items, N = 1000 and Knapsack Capacity, C = 1000
//Complexity O(NC)
bool vis[1001][1001];
ll N, C;
ll dp[1001][1001];
ll Item_Value[1001];
ll Item_Weight[1001];
ll dp_rec(ll Pos, ll Capacity_Remain)
{
    // printf("%lld %lld\n", Pos, Capacity_Remain);
    if(Pos>N||Capacity_Remain==0)
        return 0;
    if(vis[Pos][Capacity_Remain]==1)
        return dp[Pos][Capacity_Remain];
    if(Capacity_Remain>=Item_Weight[Pos])
        dp[Pos][Capacity_Remain] = max(Item_Value[Pos]+dp_rec(Pos+1, Capacity_Remain-Item_Weight[Pos]), dp_rec(Pos+1, Capacity_Remain));
    else
        dp[Pos][Capacity_Remain] = dp_rec(Pos+1, Capacity_Remain);
    vis[Pos][Capacity_Remain]=1;
    return dp[Pos][Capacity_Remain];
}
