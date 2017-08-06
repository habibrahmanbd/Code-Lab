using namespace std;
#include<bits/stdc++.h>

#define db          double
#define ll          long long
#define ull         unsigned long long

#define vi          vector<int>
#define vl          vector<long>
#define vll         vector<ll>

#define mii         map<int,int>
#define mll         map<ll,ll>

#define pi          pair<int,int>
#define pl          pair<long,long>
#define pll         pair<ll,ll>

#define pb          push_back
#define mp          make_pair
#define fs          first
#define sc          second

#define pf          printf
#define sf          scanf
#define II          ({int a; _in(a); a;})
#define IL          ({long a; _in(a); a;})
#define ILL         ({ll a; _in(a); a;})
#define ID          ({db a; sf("%lf",&a); a;})
#define IF          ({float a; sf("%f",&a); a;})
#define IC          ({char a; sf("%c",&a); a;})
#define IS          ({string a; _in_cin_string(a); a;})

#define repI(i,b,c)  for(int i=b;   i<=c; i++)
#define repL(i,b,c)  for(long i=b;  i<=c; i++)
#define repLL(i,b,c) for(ll i=b;    i<=c; i++)

#define all(V)      V.begin(),V.end()
#define clr(A,B)    memset(A,B,sizeof A)

#define _F_in       freopen("in.txt","r",stdin)
#define _F_out      freopen("out.txt","w",stdout)

#define PI          2*acos(0.0)
#define mod         1000000007
#define INF         LLONG_MAX
#define sqr(n)      (n*n)

#define endl	    '\n'

template <typename T>inline T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T>inline T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T>inline T Bigmod(T b,T p,T m){ if(p==0) return 1; else if (!(p&1)) return sqr(Bigmod(b,p/2,m)) % m;else return ((b % m) * Bigmod(b,p-1,m)) % m;}
template <typename T>inline T gcd(T a,T b){ if(b==0)return a; return gcd(b,a%b);}
template <typename T>inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T>inline T euclide(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T>inline T Dis(T x1,T y1,T x2, T y2){return sqrt( (sqr((x1-x2)) + sqr((y1-y2))) );}
template <typename T>inline T Angle(T x1,T y1,T x2, T y2){ return atan(double(y1-y2) / double(x1-x2));}
template <typename T>inline T DIFF(T a,T b) { T d = a-b;if(d<(T)0)return -d;else return d;}
template <typename T>inline T ABS(T a) {if(a<0)return -a;else return a;}
template <typename T>inline ll isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y); }

template <typename T>inline void _in(T &x){register int c = getchar();x = 0;bool neg = 0;for(;((c<48 | c>57) && c != '-');c = getchar()); if(c=='-') {neg=1;c=getchar();}for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}

template <typename T>inline bool isLeapYear(T N){ if (N%4) return 0; else if (N%100) return 1; else if (N%400) return 0; else return 1; }
template <typename T>inline T Set(T N,T pos){ T A = 1; return N=N | (A<<pos);}
template <typename T>inline T Reset(T N,T pos){ T A = 1; return N= N & ~(A<<pos);}
template <typename T>inline bool Check(T N,T pos){T A=1; return (bool)(N & (A<<pos));}
template <class T, class X>inline T togglebit(T a, X i) { T t=1;return (a^(t<<i)); }

template <class T, class X>inline T toInt(T &sm, X s) {stringstream ss(s); ss>>sm; return sm;}
template <typename T>inline int cdigittoint(T ch){return ch-'0';}
template <typename T>inline bool isVowel(T ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
template <typename T>inline bool isConst(T ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}


inline double DEG(double x) { return (180.0*x)/(PI);}
inline double RAD(double x) { return (x*(double)PI)/(180.0);}

//Knight Move
//ll dx[]= {-1, -2, -2, -1, +1, +2, +2, +1};
//ll dy[]= {-2, -1, +1, +2, +2, +1, -1, -2};

//8 Direction
//ll dx[]={-1, -1, -1, 0, +1, +1, +1, 0};
//ll dy[]={-1, 0, +1, +1, +1, 0, -1, -1};

//4 Direction
//ll dx[]={0, +1, 0, -1};
//ll dy[]={+1, 0, -1, 0};

///------------------------------------------------------///
const int mx = 10005;
vector<pair<ll, ll> > g[mx];

ll L[mx];
ll P[mx][22];
ll T[mx];
ll Cost[mx];

void dfs(ll from,ll u,ll dep)
{
    T[u]=from;
    L[u]=dep;
    for(ll i=0; i<g[u].size(); i++)
    {
        ll v=g[u][i].fs;
        if(v==from) continue;
        Cost[v] = Cost[u] + g[u][i].sc;
        dfs(u,v,dep+1);
    }
}

ll lca_query(ll N, ll p, ll q)
{
    ll tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log=1;
    while(1)
    {
        ll next=log+1;
        if((1LL<<next)>L[p])break;
        log++;

    }

    for (i = log; i >= 0; i--)
        if (L[p] - (1LL << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
}

void lca_init(ll N)
{
    memset (P,-1,sizeof(P));
    ll i, j;
    for (i = 0; i < N; i++)
        P[i][0] = T[i];

    for (j = 1; 1 << j < N; j++)
        for (i = 0; i < N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        //pf("Case %lld:\n",cs);
        ll n=ILL;
        for(ll i=1; i<n; i++)
        {

            ll u=ILL, v=ILL, cst = ILL;
            u--,v--;
            g[u].pb(mp(v, cst));
            g[v].pb(mp(u, cst));
        }
        Cost[0]=0;
        dfs(0, 0, 0);
        lca_init(n);
        string str;
        while(cin>>str)
        {
            if(str=="DIST")
            {
                ll u=ILL, v=ILL;
                u--, v--;
                ll lca = lca_query(n, u, v);
                ll Ans = Cost[u]+Cost[v] - 2*Cost[lca];
                pf("%lld\n",Ans);
            }
            else if(str=="KTH")
            {
                //Kth Element on Path of from U to V
                ll u=ILL, v=ILL, k=ILL;
                u--,v--;
                ll lca = lca_query(n, u, v);
                ll tot = L[u]+L[v] - 2*L[lca] + 1;
                if(L[u] - L[lca]+1>=k)
                {
                    k = L[u] - k + 1;
//                    cout<<k<<endl;
                    ll stp;
                    for(stp = 1; 1<<stp <= L[u]; stp++);
                        stp--;
                    for(ll i = stp; i >= 0; i--)
                        if(L[u] - (1<<i) >= k)
                            u = P[u][i];
                    pf("%lld\n",u+1);
                }
                else
                {
                    k = 2*L[lca] + k - L[u] - 1 ;
                    ll stp;
                    for(stp = 1; 1<<stp <= L[v]; stp++);
                        stp--;
                    for(ll i = stp; i >= 0; i--)
                        if(L[v] - (1<<i) >= k)
                            v = P[v][i];
                    pf("%lld\n",v+1);
                }
            }
            else
                break;
        }
        //all clr goes here
        for(ll i=0; i<mx; i++)
            g[i].clear();
        clr(L,0);
        clr(Cost,0);
        clr(T,-1);
        if(cs<t)
            pf("\n");
    }
    return 0;
}
