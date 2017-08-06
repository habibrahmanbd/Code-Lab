#include <sstream>
#include <queue>
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
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
#define ERR         1e-5
#define PRE         1e-8
#define SZ(s)       (int)s.size()
#define LL           long long
#define ISS         istringstream
#define OSS        ostringstream
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
#define csprnt printf("Case %d: ", ++cas);
using namespace std;

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void debug(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
//*************************************************My Code Starts Here*********************************************************************************
//Testted by Spoj 8725
struct Point{
	LL x, y;
	int in;
};
//this are used for set compare (used when points are in double)
//int dcmp(double x){ //precise up to ERR
	//if(fabs(x)<ERR)return 0;else return x<0?-1:1;
//}
//bool operator<( const Point& A,const Point& B ){return dcmp(A.x-B.x)<0||(dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)<0);}
//bool operator==(const Point&a,const Point&b){return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;}
//bool operator!=(const Point&a,const Point&b){return a==b?false:true;}

bool closestPairCompareX(const Point &a,const Point &b) {
	return a.x <b.x || (a.x==b.x && a.y < b.y);
}

bool closestPairCompareY(const Point &a,const Point &b) {
	return a.y < b.y ;
}

void updClosestPair(Point &a,Point &b,int &p1,int &p2,LL &mindist) {
	LL dist =  ( a. x - b. x ) * ( a. x - b. x ) + ( a. y - b. y ) * ( a. y - b. y ) ;
	if(dist<mindist)
		mindist=dist,p1=a.in, p2=b.in;
}

//complexity nlogn
void recClosestPair(Point a[],int l, int r,int &p1,int &p2,LL &mindist,Point t[]) {
	if ( r - l <= 3 ) {
		for ( int i = l ; i <= r ; ++ i )
			for ( int j = i + 1 ; j <= r ; ++ j )
				updClosestPair( a [ i ] , a [ j ],p1,p2,mindist) ;
		sort ( a + l, a + r + 1 , &closestPairCompareY) ;
		return;
	}

	int m = ( l + r ) >> 1 ;
	LL midx = a[m].x ;
	recClosestPair(a, l, m,p1,p2,mindist,t);
    recClosestPair(a,m+1 ,r,p1,p2,mindist,t);
	merge(a+l, a+m+1, a+m+1 ,a+r+1 ,t, &closestPairCompareY);
	copy(t,t+r-l+1,a+l);

	int tsz = 0 ;
	for ( int i = l ; i <= r ; ++ i )
		if ( abs ( a [ i ].x - midx ) < mindist ) {
			for ( int j = tsz - 1 ; j >= 0 && a [ i ].y - t[ j ].y < mindist ; -- j )
				updClosestPair( a [ i ] , t [ j ],p1,p2,mindist) ;
			t[tsz++] = a [ i ] ;
		}
}

//1 based
//p1 and p2 are the index of the closest pair
double closestPair(Point a[],int n,int &p1,int &p2)
{
    if(n==1) return 0;
    sort( a+1,a+n, &closestPairCompareX) ;
    LL mindist=1E18;//square distance(for longer range there should be change here)
    Point t[n+10];
    recClosestPair(a,1, n,p1,p2,mindist,t) ;
    return sqrt(mindist*1.0);
}


int main()
{
    int n;
    Point arr[51000];
    while(cin>>n)
    {
       int i;
       for(i=1;i<=n;i++)
       {
            scanf("%lld %lld",&arr[i].x,&arr[i].y);
            arr[i].in=i;
       }

       int p1,p2;
       double ret=closestPair(arr,n,p1,p2);
       if(p1>p2) swap(p1,p2);
       printf("%d %d %.6lf\n",p1-1,p2-1,ret);
    }
    return 0;
}

/*
Input:
5
0 0
0 1
100 45
2 3
9 9

Output:
0 1 1.000000
Input:
5
0 0
-4 1
-7 -2
4 5
1 1

Output:
0 4 1.414214
*/
