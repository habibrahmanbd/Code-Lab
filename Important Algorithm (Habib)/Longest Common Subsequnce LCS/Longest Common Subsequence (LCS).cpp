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
#define in          freopen("in.txt","r",stdin)
#define out         freopen("out.txt","w",stdout)
#define PI          2*acos(0.0)
#define mod         10007
#define INF         1<<29
string a,b,ans_str;
ll len1,len2;
bool visit[mod][mod];
ll dp[mod][mod];
ll calLCS(ll i, ll j)
{
    if(a[i]=='\0'||b[j]=='\0')
        return 0;
    if(visit[i][j]==true)
        return dp[i][j];
    ll ans=0;
    if(a[i]==b[j])
        ans = 1 + calLCS(i+1,j+1);
    else
    {
        ll v1 = calLCS(i+1,j);
        ll v2 = calLCS(i,j+1);
        ans =max (v1,v2);
    }
    dp[i][j]=ans;
    visit[i][j]=true;
    return dp[i][j];
}
void printLCS(ll i, ll j)
{
    if(a[i]=='\0'||b[j]=='\0')
    {
        cout<<ans_str<<endl;
        return;
    }
    if(a[i]==b[j])
    {
        ans_str+=a[i];
        printLCS(i+1,j+1);
        ans_str.erase(ans_str.end()-1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1])
            printLCS(i+1,j);
        else if(dp[i+1][j]<dp[i][j+1])
            printLCS(i,j+1);
        else
        {
            printLCS(i,j+1);
            printLCS(i+1,j);
        }
    }
}
int main()
{
    cin>>a>>b;
    len1 = a.length();
    len2 = b.length();
    cout<<calLCS(0,0)<<"\n";
    printLCS(0,0);
    return 0;
}
