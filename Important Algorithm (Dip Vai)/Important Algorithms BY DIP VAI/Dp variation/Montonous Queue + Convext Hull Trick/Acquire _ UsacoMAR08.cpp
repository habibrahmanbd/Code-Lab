/**
Farmer John is considering buying more land for the farm and has
his eye on N (1 <= N <= 50,000) additional rectangular plots, each
with integer dimensions (1 <= width_i <= 1,000,000; 1 <= length_i
<= 1,000,000).

If FJ wants to buy a single piece of land, the cost is $1/square
unit, but savings are available for large purchases. He can buy
any number of plots of land for a price in dollars that is the width
of the widest plot times the length of the longest plot. Of course,
land plots cannot be rotated, i.e., if Farmer John buys a 3x5 plot
and a 5x3 plot in a group, he will pay 5x5=25.

FJ wants to grow his farm as much as possible and desires all the
plots of land. Being both clever and frugal, it dawns on him that
he can purchase the land in successive groups, cleverly minimizing
the total cost by grouping various plots that have advantageous
width or length values.

Given the number of plots for sale and the dimensions of each,
determine the minimum amount for which Farmer John can purchase all

PROBLEM NAME: acquire

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 describes plot i with two space-separated
        integers: width_i and length_i

SAMPLE INPUT (file acquire.in):

4
100 1
15 15
20 5
1 100

INPUT DETAILS:

There are four plots for sale with dimensions as shown.

OUTPUT FORMAT:

* Line 1: The minimum amount necessary to buy all the plots.

SAMPLE OUTPUT (file acquire.out):

500

OUTPUT DETAILS:

The first group contains a 100x1 plot and costs 100. The next group
contains a 1x100 plot and costs 100. The last group contains both the 20x5
plot and the 15x15 plot and costs 300. The total cost is 500, which is
minimal.
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
#define SIZE 55000

pii arr[SIZE],rect[SIZE];
ll dp[SIZE];
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
	if (pointer>M.size())
		pointer=M.size()-1;
	//Any better line must be to the right, since query values are
	//non-decreasing
	while (pointer<M.size()-1 && M[pointer+1]*x+B[pointer+1]<M[pointer]*x+B[pointer])   // Min Value wanted
		pointer++;
	return M[pointer]*x+B[pointer];
}


int main()
{
    freopen("acquire.1.in","r",stdin);
    freopen("acquire.1_.out","w",stdout);

    int i,j,test,Case=1,N,P,c;

    while(scanf("%d",&P)==1)
    {
        M.clear();
        B.clear();

        REP(i,P) scanf("%d %d",&arr[i].fs,&arr[i].sc);
        sort(arr,arr+P);


        //legal rectanle only stored in rect
        N=1;
        for(i=0;i<P;i++)
        {
            while(N>1 && rect[N-1].sc<=arr[i].sc)
                N--;
            rect[N++]=arr[i];
        }

        dp[0]=0;
        add(rect[1].sc,dp[0]);
        pointer=0;
        for(i=1;i<N;i++)
        {
            dp[i]=query(rect[i].fs);
            add(rect[i+1].sc,dp[i]);
        }
        printf("%lld\n",dp[N-1]);
    }

    return 0;
}
