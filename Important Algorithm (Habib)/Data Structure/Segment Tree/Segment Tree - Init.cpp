#define mx 10001
ll arr[mx];
ll tree[mx*3];
void init(ll node, ll b,ll e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }
    ll left = node*2;
    ll right = 2*node+1;
    ll mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node]=tree[left]+tree[right];
}
ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(i>e||j<b)
        return 0;
    if(b>=i&&e<=j)
        return tree[node];
    ll left = node*2;
    ll right = 2*node+1;
    ll mid = (b+e)/2;
    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid+1, e, i, j);
    return p1+p2;
}
void update(ll node, ll  b, ll e, ll i, ll newvalue)
{
    if(i>e||i<b) return ;
    else if(b>=i&&e<=i)
    {
        tree[node] = newvalue;
        return;
    }
    ll left = node*2;
    ll right = 2*node+1;
    ll mid = (b+e)/2;
    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);
    tree[node]  = tree[left] + tree[right];
}
int main()
{
    co<<"Enter your new array size";
    ll n=II;
    FOR(1,n,1)
    arr[i]=II;
    init(1,1,n);
    co<<"Enter from positon to position Query\n";
    //query before update.....
    ll p=II, data=II;
    ll q_res = query(1,1,n, p,data);
    co<<"Query result : "<<q_res<<endl;

    //Updating.....
    co<<"Enter  position to update new value\n";
    p=II, data=II;
    update(1, 1, n, p, data);

    //Updating after value

    co<<"Enter from positon to position Query\n";
    p=II, data=II;
    q_res = query(1,1,n, p,data);
    co<<"Query result : "<<q_res<<endl;
    return 0;
}
