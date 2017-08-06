/**
POJ 1180
Batch Scheduling
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 2825		Accepted: 1277
Description

There is a sequence of N jobs to be processed on one machine. The jobs are numbered from 1 to N, so that the sequence is 1,2,..., N.
The sequence of jobs must be partitioned into one or more batches, where each batch consists of consecutive jobs in the sequence. The
processing starts at time 0. The batches are handled one by one starting from the first batch as follows. If a batch b contains jobs
with smaller numbers than batch c, then batch b is handled before batch c. The jobs in a batch are processed successively on the machine.
 Immediately after all the jobs in a batch are processed, the machine outputs the results of all the jobs in that batch. The output time
 of a job j is the time when the batch containing j finishes.

A setup time S is needed to set up the machine for each batch. For each job i, we know its cost factor Fi and the time Ti required to
process it. If a batch contains the jobs x, x+1,... , x+k, and starts at time t, then the output time of every job in that batch is
t + S + (Tx + Tx+1 + ... + Tx+k). Note that the machine outputs the results of all jobs in a batch at the same time. If the output
time of job i is Oi, its cost is Oi * Fi. For example, assume that there are 5 jobs, the setup time S = 1, (T1, T2, T3, T4, T5) =
(1, 3, 4, 2, 1), and (F1, F2, F3, F4, F5) = (3, 2, 3, 3, 4). If the jobs are partitioned into three batches {1, 2}, {3}, {4, 5},
then the output times (O1, O2, O3, O4, O5) = (5, 5, 10, 14, 14) and the costs of the jobs are (15, 10, 30, 42, 56), respectively.
The total cost for a partitioning is the sum of the costs of all jobs. The total cost for the example partitioning above is 153.

You are to write a program which, given the batch setup time and a sequence of jobs with their processing times and cost factors,
computes the minimum possible total cost.
Input

Your program reads from standard input. The first line contains the number of jobs N, 1 <= N <= 10000. The second line contains the
batch setup time S which is an integer, 0 <= S <= 50. The following N lines contain information about the jobs 1, 2,..., N in that
order as follows. First on each of these lines is an integer Ti, 1 <= Ti <= 100, the processing time of the job. Following that,
there is an integer Fi, 1 <= Fi <= 100, the cost factor of the job.
Output

Your program writes to standard output. The output contains one line, which contains one integer: the minimum possible total cost.
Sample Input

5
1
1 3
3 2
4 3
2 3
1 4
Sample Output

153
Source

IOI 2002
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
#define SIZE 110000

int tt[SIZE],ff[SIZE],T[SIZE],F[SIZE],dp[SIZE];
#define lim 110000
ll M[lim],C[lim]; //y=mx+c we need only m(slope) and c(constant)

//Returns true if either line l1 or line l3 is always better than line l2
bool bad(int l1,int l2,int l3)
{
	/*
	intersection(l1,l2) has x-coordinate (c1-c2)/(m2-m1)
	intersection(l1,l3) has x-coordinate (c1-c3)/(m3-m1)
	set the former greater than the latter, and cross-multiply to
	eliminate division
	*/
	return (C[l3]-C[l1])*(M[l1]-M[l2])<=(C[l2]-C[l1])*(M[l1]-M[l3]);
}

//Adding should be done serially
//If we want minimum y coordinate(value) then maximum valued m should be inserted first
//If we want maximum y coordinate(value) then minimum valued m should be inserted first
void add(long long m,long long c,int &last)
{
	//First, let's add it to the end
	M[last]=m;
	C[last++]=c;
	//If the penultimate is now made irrelevant between the antepenultimate
	//and the ultimate, remove it. Repeat as many times as necessary
	//in short convex hull main convex hull tecnique is applied here
	while(last>=3&&bad(last-3,last-2,last-1))
	{
		M[last-2]=M[last-1];
		C[last-2]=C[last-1];
		last--;
	}
}

//Returns the minimum y-coordinate of any intersection between a given vertical
//line(x) and the lower/upper envelope(pointer)
//This can only be applied if the query of vertical line(x) is already sorted
//works better if number of query is huge
long long query(long long x,int &pointer,int last)
{
	//If we removed what was the best line for the previous query, then the
	//newly inserted line is now the best for that query
	if (pointer>=last)
		pointer=last-1;
	//Any better line must be to the right, since query values are
	//non-decreasing
	while (pointer<last-1 && M[pointer+1]*x+C[pointer+1]<=M[pointer]*x+C[pointer])  // Min Value wanted... (reverse(> sign) for max value)
		pointer++;
	return M[pointer]*x+C[pointer];
}

//for any kind of query(sorted or not) it can be used
//it works because of the hill property
//works better if number of query is few
long long bs(int st,int end,long long x,int last)
{
    int mid=(st+end)/2;
    if(mid+1<last && M[mid+1]*x+C[mid+1]<M[mid]*x+C[mid]) return bs(mid+1,end,x,last); // Min Value wanted... (reverse(> sign) for max value)
    if(mid-1>=0 && M[mid-1]*x+C[mid-1]<M[mid]*x+C[mid]) return bs(st,mid-1,x,last); // Min Value wanted... (reverse(> sign) for max value)
    return M[mid]*x+C[mid];
}


int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);

    int i,j,k,test,Case=1,N,S,ans,Cost;

    while(scanf("%d %d",&N,&S)==2)
    {
        for(i=1;i<=N;i++) scanf("%d %d",&T[i],&F[i]);

        Clear(tt,0);
        Clear(ff,0);
        for(i=1;i<=N;i++) tt[i]=tt[i-1]+T[i];
        for(i=N;i>=1;i--) ff[i]=ff[i+1]+F[i];

        int last=0,pointer=0;
        dp[N+1]=0;
        add(tt[N],dp[N+1],last);

        for(i=N;i>=1;i--)
        {
            //Cost=query(ff[i]);
            Cost=query(ff[i],pointer,last);
            dp[i]=Cost-tt[i-1]*ff[i]+S*ff[i];
            add(tt[i-1],dp[i],last);
        }
        ans=dp[1];
        printf("%d\n",ans);
    }

    return 0;
}
