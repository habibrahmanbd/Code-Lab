#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
#define ERR         1e-5
#define PRE         1e-8
#define SZ(a)       (int)a.size()
#define LL          long long
#define ULL         unsigned long long
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

#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define countbit(mask) __builtin_popcount(musk)
string man;
int lim;
VS a;
map<string,int>col;
struct pq
{
	int freq,left,right,in;
	bool operator<(const pq &b)const
	{
		return freq>b.freq;    // Min Priority Queue
	}
};
vector<pq>arr;


int huffman()//complexity nlgn
{
    priority_queue<pq>Q;
	int i;
	fr(i,0,lim-1)
	{
        pq tem;
	    tem.freq=col[a[i]];
	    tem.in=i;
	    tem.left=-1;
	    arr.pb(tem);
        Q.push(tem);
	}

	while(lim>1)
	{
	    pq tem,x,y;
	    x=Q.top();
	    Q.pop();
	    y=Q.top();
	    Q.pop();
	    tem.freq=x.freq+y.freq;
	    tem.in=SZ(arr);
	    tem.left=x.in;
	    tem.right=y.in;
	    arr.pb(tem);
        Q.push(tem);
        lim--;
	}
	return Q.top().in;
}

double getans(int in,int dep)
{
    //print2(in,SZ(arr[in].str));
    if(arr[in].left==-1)  return (1.0*arr[in].freq*dep)/lim;
    return getans(arr[in].left,dep+1)+getans(arr[in].right,dep+1);

}


class GuessTheSubstring
{
public:
	double solve(vector <string> pie)
	{
	    int i,j;
	    man.clear();
	    col.clear();
	    arr.clear();
	    a.clear();
	    lim=SZ(pie);
	    fr(i,0,lim-1) man+=pie[i];
	    lim=SZ(man);
	    fr(i,0,lim-1)
	    {
	        string tem;
	        fr(j,i,lim-1)
	        {
	            tem.pb(man[j]);
	            if(!col[tem]) a.pb(tem);
	            col[tem]++;
	        }
	    }

	    lim=SZ(a);
	    sorta(a);
	    int use=huffman();
	    print1("oi oi");
	    lim=SZ(man);
	    lim=(lim*(lim+1))/2;
	    return getans(use,0);
	}
};


template<typename T> void print( T a ) {
    cerr << a;
}

void print( long long a ) {
    cerr << a << "L";
}

void print( string a ) {
    cerr << '"' << a << '"';
}

template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}

template<typename T> void assert_eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

template<typename T> void assert_eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
void assert_eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

int main( int argc, char* argv[] )
{

	GuessTheSubstring objectGuessTheSubstring;

	//test case0
	vector <string> param00;
	param00.push_back("abc");
	double ret0 = objectGuessTheSubstring.solve(param00);
	double need0 = 2.6666666666666665;
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("a");
	param10.push_back("bc");
	double ret1 = objectGuessTheSubstring.solve(param10);
	double need1 = 2.6666666666666665;
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("aa");
	double ret2 = objectGuessTheSubstring.solve(param20);
	double need2 = 1.0;
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("a");
	param30.push_back("a");
	param30.push_back("a");
	param30.push_back("a");
	param30.push_back("a");
	double ret3 = objectGuessTheSubstring.solve(param30);
	double need3 = 2.1999999999999997;
	assert_eq(3,ret3,need3);

}
