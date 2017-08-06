#define mx 1000000
ll arr[mx];
struct info
{
    ll prop, sum;
} tree[mx*3];

void init(ll node, ll beg,ll en)
{
    if(beg==en)
    {
        tree[node].sum = arr[beg];
        //tree[node].prop=0;
        return;
    }
    ll left = node<<1;
    ll right = (node<<1) + 1;
    ll mid = (beg+en)>>1;
    init(left, beg, mid);
    init(right, mid+1, en);
    tree[node].sum=tree[left].sum+tree[right].sum;
    //tree[node].prop = tree[left].prop + tree[right].prop;
}

void update(ll node, ll beg, ll en, ll i, ll j, ll x)
{
    if(i>en||j<beg)
        return;
    if(beg>=i && en<=j)
    {
        tree[node].sum += (en-beg+1)*x;
        tree[node].prop += x;
        return;
    }
    ll left = (node<<1);
    ll right = (node<<1) + 1;
    ll mid = (beg+en)>>1;
    update(left, beg, mid, i,j, x);
    update(right, mid+1, en, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum + (en-beg+1)*tree[node].prop;
}
ll query(ll node, ll beg, ll en, ll i, ll j, ll carry)
{
    if(i>eb || j<beg)
        return 0;
    if(beg>=i && en<=j )
        return tree[node].sum + carry*(en-beg+1);

    ll left  = node<<1;
    ll right = (node<<1) +1;
    ll mid = (beg+en)>>1;
    ll p1 = query(left, beg,mid, i,j, carry+tree[node].prop);
    ll p2 = query(right, mid+1,en, i,j, carry+tree[node].prop);
    return p1+p2;
}
int main()
{
    ll n=IL;
    FOR(1,n,1)
    arr[i]=IL;
    init(1,1,n);
    ll i=IL, j= IL, x= IL;
    update(1,1, n, i, j, x);
    i=IL;
    j= IL;
    pf("%lld\n",query(1, 1,n, i,j,0));
    return 0;
}
