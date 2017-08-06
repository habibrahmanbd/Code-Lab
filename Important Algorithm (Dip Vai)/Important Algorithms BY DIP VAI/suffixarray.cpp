//#pragma warning (disable: 4786)

#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
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
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define cntbit(mask) __builtin_popcountll(mask)
//0 based print
#define debug_array(a,n) for(int i=0;i<n;i++) cout<<a[i].in<<" "; cout<<endl;
#define debug_array2(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}

#define csprnt printf("Case %d: ", ++cas);
#define mod         1000000007
//*************************************************My Code Starts Here*********************************************************************************
#define lim 100010
//only input is the global string
struct element
{
    int in;
    bool bucketend;
};

//after sa only suffixarray and lcp is needed
int bucketno[lim],start[lim];//bucketno = 1 based, start=starting index of each bucket
int col[lim],candi[lim],pos[lim],candiin,placeend[lim];//candi=temporary putting the buckets placeend=new ends of the bucket
element suffixarray[lim]; //(0 based)keep the index
string s;//input string
int lcp[lim]; //(0 based)lcp with the previous indexed suffix


bool comp(element p,element q)
{
   if(s[p.in]!=s[q.in])
        return s[p.in]<s[q.in];
   return p.in<q.in;
}

void sa(int h,int totalbucket)
{
    //print2(totalbucket,s);
    if(totalbucket==SZ(s)) return;
    int i,j;
    candiin=0;
    pos[SZ(s)-h]=start[bucketno[SZ(s)-h]];
    placeend[start[bucketno[SZ(s)-h]]++]=h;
    //bucketsort here
    fr(i,0,SZ(s)-1)
    {
        if(suffixarray[i].in-h>=0)
        {
            pos[suffixarray[i].in-h]=start[bucketno[suffixarray[i].in-h]]++;
            if(col[bucketno[suffixarray[i].in-h]]!=h)
            {
                candi[candiin++]=bucketno[suffixarray[i].in-h];
                col[bucketno[suffixarray[i].in-h]]=h;
            }
        }

        if(suffixarray[i].bucketend)
        {
            fr(j,0,candiin-1)
            {
                placeend[start[candi[j]]-1]=h;
                col[candi[j]]=0;
            }
            candiin=0;
        }
    }


    //placing the new end
    fr(i,0,SZ(s)-1)
     if(placeend[i]==h)
        suffixarray[i].bucketend=true;

    //updating index of suffixarray
    fr(i,0,SZ(s)-h)
        suffixarray[pos[i]].in=i;
    int tembucket=1;
    col[tembucket]=0;
    bucketno[suffixarray[0].in]=tembucket;
    start[tembucket]=0;
    fr(i,1,SZ(s)-1)
    {
        if(!suffixarray[i-1].bucketend)
            bucketno[suffixarray[i].in]=tembucket;
        else
        {
            ++tembucket;
            col[tembucket]=0;
            bucketno[suffixarray[i].in]=tembucket;
            start[tembucket]=i;
        }
    }
    sa(2*h,tembucket);
}

void initialize()
{
    int i;
    fr(i,0,SZ(s)-1)
    {
        suffixarray[i].in=i;
        suffixarray[i].bucketend=false;
        placeend[i]=0;
    }

    sort(&suffixarray[0],&suffixarray[SZ(s)],comp);
    int tembucket=1;
    col[tembucket]=0;
    bucketno[suffixarray[0].in]=tembucket;
    start[tembucket]=0;
    fr(i,1,SZ(s)-1)
    {
        if(s[suffixarray[i].in]==s[suffixarray[i-1].in])
            bucketno[suffixarray[i].in]=tembucket;
        else
        {
            suffixarray[i-1].bucketend=true;
            ++tembucket;
            col[tembucket]=0;
            bucketno[suffixarray[i].in]=tembucket;
            start[tembucket]=i;
        }
    }
    suffixarray[i-1].bucketend=true;
    sa(1,tembucket);
}

void LCP()
{
    int len = 0;
    for(int i =0 ; i< SZ(s) ; i++)
    {
        int k = bucketno[i];
        if(k==1)
        {
            lcp[k-1] = 0;
            continue;
        }
        int j = suffixarray[k-2].in;
        while(s[i+len]==s[j+len]&&i+len<SZ(s)&&j+len<SZ(s)) len++;
        lcp[k-1] = len;
        if(len) len--;
    }
    return;
}

//call this and edit this
void performstringoperation()
{
    initialize();
    LCP();
    debug_array(suffixarray,SZ(s));
}


int main()
{
    //freopen("A.txt","r",stdin);
    //freopen("B.txt","w",stdout);
    while(cin>>s)
    {
        performstringoperation();
    }
    return 0;
}

/*
abaa
3 2 0 1
0 1 1 0
abcaab
3 4 0 5 1 2
0 1 2 0 1 0
baabcb
1 2 5 0 3 4
0 1 0 1 1 0
aabcaab
4 0 5 1 6 2 3
0 3 1 2 0 1 0
aaa
2 1 0
0 1 2
*/
