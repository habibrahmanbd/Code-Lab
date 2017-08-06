using namespace std;
#include<bits/stdc++.h>
#define db          double
#define ll          long long
#define ull         unsigned long long
#define vi          vector<int>
#define vl          vector<long>
#define vll         vector<ll>
#define pi          pair<int,int>
#define pl          pair<long,long>
#define pll         pair<ll,ll>
#define pb          push_back
#define mp          make_pair
#define pf          printf
#define sf          scanf
#define mii         map<int,int>
#define mll         map<ll,ll>
#define II          ({int a; sf("%d",&a); a;})
#define IL          ({long a; sf("%ld",&a); a;})
#define ILL         ({ll a; sf("%lld",&a); a;})
#define ID          ({db a; sf("%lf",&a); a;})
#define IF          ({float a; sf("%f",&a); a;})
#define IC          ({char a; sf("%c",&a); a;})
#define FRI(a,b,c)  for(int i=a;   i<=b; i+=c)
#define FRL(a,b,c)  for(long i=a;  i<=b; i+=c)
#define FRLL(a,b,c) for(ll i=a;    i<=b; i+=c)
#define all(V)      V.begin(),V.end()
#define in          freopen("in.txt","r",stdin)
#define out         freopen("out.txt","w",stdout)
#define PI          acos(-1.0)
#define mod         3.14159654
#define INF         LLONG_MAX
#define endl	    '\n'
#define min(a,b)    a<b?a:b
template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}
//------------------------------------------------------

struct co
{
    int x;
    int y;
    int64_t dist(co p)
    {
        p.x -= x;
        p.y -= y;
        return p.x * p.x + p.y * p.y;
    }
} arr[100008],p0;
bool check(int x1, int y1, int x2, int y2, int x3, int y3 )
{
    int res = ((x2-x1)*(y3-y1))-((x3-x1)*(y2-y1));
    if(res>0)
        return true;
    else
        return false;

}
int orientation(co p, co q, co r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
int dist(co p1, co p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int compare(const void *vp1, const void *vp2)
{
    co *p1 = (co *)vp1;
    co *p2 = (co *)vp2;


    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;

    return (o == 2)? -1: 1;
}
struct cvector
{
    db x,y;
    cvector(db a,db b)
    {
        x=a;
        y=b;
    }
};
cvector operator-(co a,co b)
{
    return cvector(a.x-b.x,a.y-b.y);
}
db length(cvector t)
{
    return sqrt(t.x*t.x+t.y*t.y);
}
db dot(co a,co b,co p)
{
    return (a.x-p.x)*(b.x-p.x)+(a.y-p.y)*(b.y-p.y);
}
db get(co a,co b,co p)
{
    return acos(dot(a,b,p)/length(a-p)/length(b-p));
}
int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i].x;
            cin>>arr[i].y;
        }
        int ymin = arr[0].y, min = 0;
        for (int i = 1; i < n; i++)
        {
            int y = arr[i].y;
            if ((y < ymin) || (ymin == y && arr[i].x < arr[min].x))
                ymin = arr[i].y, min = i;
        }
        swap(arr[0], arr[min]);
        p0 = arr[0];
        qsort(&arr[1], n-1, sizeof(co), compare);
        stack<co>S;
        S.push(arr[0]);
        S.push(arr[1]);
        S.push(arr[2]);
        int i=3;
        while(true)
        {
            if(i>=n)
                break;
            co s1 = S.top();
            S.pop();
            co s2 = S.top();
            S.pop();
            S.push(s2);
            S.push(s1);
            if(check(s2.x,s2.y, s1.x,s1.y, arr[i].x,arr[i].y))
            {
                S.push(arr[i]);
                i++;
                continue;
            }
            else
            {
                S.pop();
                continue;
            }
        }
//        printf("So the Polygon Vertices: \n\n");
        vector<co>res;
        while(!S.empty())
        {
            res.pb(S.top());
            S.pop();
//            printf("%2d\t%2d\n",p.x,p.y);
        }
        db ans=INF+.0;
        ll sz = res.size();
//        for(ll i=0; i<sz;i++)
//            cout<<res[i].x<<" "<<res[i].y<<endl;
//
//        cout<<sz<<endl;
        if(n>=3)
        {
            for(ll i=0; i<sz; i++)
            {
                db alpha = get(res[i],res[(i+1)%sz],res[(i+2)%sz]);
//            cout<<alpha<<endl;
                ans = min(ans,alpha);
            }
            pf("Case %lld: %.10lf\n",cs,((ans/PI)*180.0000000));
        }
        else
            pf("Case %lld: 0.0000000000\n",cs);
//        pf("Case %lld: %.10lf\n",cs,((ans/PI)*180.0000000));
    }
    return 0;
}
