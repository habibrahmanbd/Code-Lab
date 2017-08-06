//#pragma warning (disable: 4786)

#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include  <time.h>
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2.0*acos(0.0))
#define ERR         1e-5
#define PRE         1e-8
#define SZ(s)       ((int)s.size())
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)
#define REP(i,n)    for(i=0;i<n;i++)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define typing(j,b) typeof((b).begin()) j=(b).begin();
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define mp          make_pair
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define cntbit(mask) __builtin_popcountll(mask)
//0 based print
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}

#define csprnt printf("Case %d: ", ++cas);

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void debug(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<"\t"<<e6<<endl;}
template<class T> void debug(vector< vector<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;} cout<<endl;}
template<class T> void debug(vector< basic_string<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j];cout<<endl;} cout<<endl;}
template<class T> void debug(T e[110][110],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
//*************************************************My Code Starts Here*********************************************************************************
//LJ 1419(Necklace)
//see emaxx for theory
#define s 1010000
bool col[s];
long long prime[s];

int seive()//1 indexed
{
    long long i,j,k;
    col[0]=true;
    col[1]=true;
    k=0;
    prime[++k]=2;
    for(j=4;j<s;j+=2)
        col[j]=true;
    for(i=3;i<s;i+=2)
         if(!col[i])
         {
                prime[++k]=i;
                for(j=i*i;j<s;j+=2*i)
                    col[j]=true;
         }
    return 0;
}

int relPrime(int n) //relative prime
{
    int i;
    int ans=n;
    for(i=1;prime[i]*prime[i]<=n;i++)
    if(n%prime[i]==0)
    {
        while(n%prime[i]==0) n/=prime[i];
        ans/=prime[i];
        ans*=(prime[i]-1);
    }

    if(n>1)
    {
        ans/=n;
        ans*=(n-1);
    }
    return ans;
}

long long bigmod(long long b,long long p,long long m)
{
    if(b==0) return 0;
    long long x,power;
    x=1;
    power=b%m;
    while(p)
    {
       if(p%2==1)
            x=(x*power)%m;
        power=(power*power)%m;
        p=p/2;
    }
    return x;
}

//most of the change were done here
LL lemmaFunction(int n,int d,int k,int m)
{
    LL ans=relPrime(n);
    ans*=bigmod(k,d,m);
    ans%=m;
    return ans;
}

//burnside lemma(from emaxx)
//n and mod should be relative prime
LL burnside(int n,int k,int m) //n=group size, k=number of color
{
    int i;
    LL ans=0;
    for(i=1;i*i<n;i++)
    if(n%i==0)
    {
        ans=(ans+lemmaFunction(n/i,i,k,m))%m;
        ans=(ans+lemmaFunction(i,n/i,k,m))%m;
    }

    if(n==i*i) ans=(ans+lemmaFunction(i,i,k,m))%m; //for ignoring double count
    ans=(ans*bigmod(n,m-2,m))%m;
    return ans;
}


int main()
{
    //srand(time(NULL));
    //freopen("A.txt","r",stdin);
    //freopen("B.txt","w",stdout);
    seive();
    int mod=1000000007;
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        csprnt;
        print1(burnside(n,k,mod));
    }
    return 0;
}
