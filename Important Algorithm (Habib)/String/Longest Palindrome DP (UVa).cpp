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
#define mod         1000000007
#define INF         1<<29
//your are given a string, you can delete no, one or more char.
//not insert to get longest palindrome.
string S;
#define MAX_V 10000
ll Len[MAX_V][MAX_V]; //in c++ initially zero '0' is assigned
ll longest_palindrome(ll l, ll r) //l for left and r for right
{
    if(Len[l][r]!=0) return Len[l][r]; // previously calculate
    if(l==r) return Len[l][r]=1; //base case for length 1
    if(l+1==r) //base case for length 2
    {
        if(S[l]==S[r])
            return Len[l][r]=2; //if two character stay beside, and same then two
        return Len[l][r]=1;
    }
    if(S[l]==S[r])
        return Len[l][r]=2+longest_palindrome(l+1,r-1);
    return Len[l][r]=max(longest_palindrome(l,r-1),longest_palindrome(l+1,r));
}
int main()
{
    cin>>S;
    ll r= S.size()-1;
    cout<<longest_palindrome(0,r);
    return 0;
}
