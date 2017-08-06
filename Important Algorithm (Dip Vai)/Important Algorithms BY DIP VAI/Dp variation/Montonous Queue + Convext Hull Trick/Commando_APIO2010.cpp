/**
APIO 2010 Commando
You are the commander of a troop ofnsoldiers, numbered from 1 to n.
For the battle ahead, you plan to divide thesensoldiers into several com-mando units.
To promote unity and boost morale, each unit will
consist of
a contiguous sequence of soldiers of the form (i, i+1, . . . , i+k).
Each soldieri has a battle effectiveness ratingx
i
. Originally, the battle
effectivenessxof a commando unit (i, i+1, . . . , i+k) was computed by adding
up the individual battle effectiveness of the soldiers in the unit. In other
words,x=x
i +x
i+1+· · · +x
i+k
.
However, years of glorious victories have led you to conclude that the
battle effectiveness of a unit should be adjusted as follows: the adjusted
effectivenessx
0
is computed by using the equation x
0
=ax
2
+bx+c, where a,
b, care known coefficients(a <0),xis the original effectiveness of the unit.
Your task as commander is to divide your soldiers into commando units
in order to maximize the sum of the adjusted effectiveness of all the units.
For instance, suppose you have 4 soldiers,x
1
= 2, x
2
= 2, x
3
= 3, x
4
= 4.
Further, let the coefficients for the equation to adjust the battle effectiveness
of a unit bea=−1,b = 10,c=−20. In this case, the best solution is to
divide the soldiers into three commando units: The first unit contains soldiers
1 and 2, the second unit contains soldier 3, and the third unit contains soldier
4. The battle effectiveness of the three units are 4, 3, 4 respectively, and the
adjusted effectiveness are 4, 1, 4 respectively. The total adjusted effectiveness
for this grouping is 9 and it can be checked that no better solution is possible.
Input format
The input consists of three lines. The first line contains a positive integer
n, the total number of soldiers. The second line contains 3 integers a, b,
andc, the coefficients for the equation to adjust the battle effectiveness of
a commando unit. The last line containsnintegers x
1
, x
2
, . . . , x
n
, sepa-rated by spaces, representing the battle effectiveness of soldiers 1, 2, . . . ,n,
respectively.
Output format
A single line with an integer indicating the maximum adjusted effectiveness
achievable.
*/

//#pragma comment(linker, "/STACK:60000000")

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <assert.h>

using namespace std;

//Type Definition
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi>vvi;
typedef vector<string> vs;
typedef map<string,int> msi;
typedef map<int,int>mii;

#define ERR 1e-9
#define PI 3.141592653589793

#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)

#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define MP(a,b) make_pair(a,b)
#define Clear(x,with) memset(x,with,sizeof(x))
#define SZ(x) (int)x.size()
#define pb push_back
#define popcount(i) __builtin_popcount(i)
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define two(X) (1<<(X))
#define twoL(X) (((ll)(1))<<(X))
#define setBit(mask,i) (mask|two(i))
#define contain(S,X) (((S)&two(X))!=0)
#define fs first
#define sc second
#define CS c_str()
#define EQ(a,b) (fabs(a-b)<ERR)
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin());
#define Find(x,y) ((int)x.find(y))

//For debugging
#define debug_array(a,n) for(ll i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(ll i=0;i<row;i++) {for(ll j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define debug(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;

//Important Functions
template<class T> void setmax(T &a, T b) { if(a < b) a = b; }
template<class T> void setmin(T &a, T b) { if(b < a) a = b; }
template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} //For Positive Negative No.
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
ll toInt(string s){ll r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
ll Pow(ll B,ll P){	ll R=1;	while(P>0)	{if(P%2==1)	R=(R*B);P/=2;B=(B*B);}return R;}
ll BigMod(ll B,ll P,ll M){	ll R=1;	while(P>0)	{if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}	return R;}
void binprint(ll mask,ll n){ll i;string s="";do{s+=(mask%2+'0');mask/=2;}while(mask);Reverse(s);s=string(max(n-SZ(s),0LL),'0')+s;for(i=SZ(s)-n;i<SZ(s);i++) printf("%c",s[i]);printf("\n");}
//void ASCII_Chart(){ll i,j,k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}


//int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

//#include<conio.h> //for using getch();

//struct edge{ int cost,node; edge(int _cost=0,int _node=0){cost=_cost;node=_node;}bool operator<(const edge &b)const {return cost>b.cost;}}; // Min Priority Queue
//bool comp(edge a,edge b){ return a.cost < b.cost;} //Asc Sort by cost

#define INF (1<<28)
#define SIZE 1100000

ll dp[SIZE],arr[SIZE],sum[SIZE];
vector<ll>M,B;
int pointer;

//Returns true if either line l1 or line l3 is always better than line l2
bool bad(int l1,int l2,int l3)
{
	/*
	intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)
	intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1)
	set the former greater than the latter, and cross-multiply to
	eliminate division
	*/
	return (B[l3]-B[l1])*(M[l1]-M[l2])<(B[l2]-B[l1])*(M[l1]-M[l3]);
}

void add(long long m,long long b)
{
	//First, let's add it to the end
	M.push_back(m);
	B.push_back(b);
	//If the penultimate is now made irrelevant between the antepenultimate
	//and the ultimate, remove it. Repeat as many times as necessary
	while (M.size()>=3&&bad(M.size()-3,M.size()-2,M.size()-1))
	{
		M.erase(M.end()-2);
		B.erase(B.end()-2);
	}
}

//Returns the minimum y-coordinate of any intersection between a given vertical
//line and the lower envelope
long long query(long long x)
{
	//If we removed what was the best line for the previous query, then the
	//newly inserted line is now the best for that query
	if (pointer>=M.size())
		pointer=M.size()-1;
	//Any better line must be to the right, since query values are
	//non-decreasing
	while (pointer<M.size()-1 && M[pointer+1]*x+B[pointer+1]>M[pointer]*x+B[pointer])  // Max Value wanted...
		pointer++;
	return M[pointer]*x+B[pointer];
}

int main()
{
    freopen("commando10.in","r",stdin);
    freopen("commando10.out","w",stdout);

    int i,j,test,Case=1;
    ll N,a,b,c;

    while(scanf("%lld",&N)==1)
    {
        scanf("%lld %lld %lld",&a,&b,&c);

        for(i=1;i<=N;i++) scanf("%lld",&arr[i]);

        Clear(sum,0);
        for(i=1;i<=N;i++) sum[i]=sum[i-1]+arr[i];

        Clear(dp,0);

        dp[1]=a*sum[1]*sum[1]+b*sum[1]+c;
        add(-2*a*sum[1],dp[1]+a*sum[1]*sum[1]-b*sum[1]); //here a is negative

        for(i=2;i<=N;i++)
        {
            dp[i]=a*sum[i]*sum[i]+b*sum[i]+c;
            dp[i]=max(dp[i],query(sum[i])+a*sum[i]*sum[i]+b*sum[i]+c);
            add(-2*a*sum[i],dp[i]+a*sum[i]*sum[i]-b*sum[i]);
        }
        printf("%lld\n",dp[N]);
    }

    return 0;
}
