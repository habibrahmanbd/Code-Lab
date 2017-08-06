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
#include <time.h>
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
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}

#define csprnt printf("Case %d: ", ++cas);
#define mod         1000000007

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
//cartesian tree
//this is also called explicit treap
//pass root as starting node
//duplicate key can be possible
//can delete only one item(if it is present) of given key value (call erase everytime in case you want to delete all)
//cnt=number of nodes rooted at this node
typedef struct item * pitem;
struct item {
	 int key, prior,cnt; //cnt is not always needed
	 pitem l, r;
	 item () {}
	 item (int key, int prior): key (key), prior (prior), l (NULL), r (NULL), cnt (0) {}
	 item (int key): key (key), prior (rand()), l (NULL), r (NULL), cnt (0) {}
};

int cnt (pitem t) {
	 return t?  t->cnt:0;
}

void upd_cnt (pitem t) {
	 if (t)
		 t-> cnt = 1 + cnt (t-> l) + cnt (t-> r);
}

//spliting the treap into two treaps with one treap greater than key, and other smaller than or equals key
//l is the root of the treap of smaller or equals key,r is the root of the treap of greater key
void split (pitem t, int key, pitem & l, pitem & r) {
	 if (!t)
		 l = r = NULL;
	 else if (key <t-> key)
		 split (t-> l, key, l, t-> l), r = t;
	 else
		 split (t-> r, key, t-> r, r), l = t;
    upd_cnt(t); //not always needed
}

void insert (pitem & t, pitem it) {
	 if (!t)
		 t = it;
	 else if (it-> prior> t-> prior)
		 split (t, it-> key, it-> l, it-> r), t = it;
	 else
		 insert (it-> key <t-> key? t-> l: t-> r, it);
     upd_cnt(t); //not always needed
}

//merging two treaps where one treap key values are greater than other treap key values
//merge l and r making the root t
//l has smaller values and r has greater values
void merge (pitem & t, pitem l, pitem r) {
	 if (!l || !r)
		 t = l?  l: r;
	 else if (l-> prior> r-> prior)
		 merge (l-> r, l-> r, r), t = l;
	 else
		 merge (r-> l, l, r-> l), t = r;
     upd_cnt(t); //not always needed
}

void erase (pitem & t, int key) {
     if(!t) return;
	 if (t-> key == key)
		 merge (t, t-> l, t-> r);
	 else
		 erase (key <t-> key? t-> l: t-> r, key);
     upd_cnt(t); //not always needed
}

//t1 smaller than l, t2 between l and r inclusive, t3 greater than r
//l and r should be legal index
void erasesegment(pitem t, int l, int r) {
	if(l>r) return;
	pitem t1, t2, t3;
	split (t, l-1,t1, t2); //1 based
	split (t2, r-l+1,t2, t3);
	merge (t, t1, t3);
}

//O(M log (N / M))
//cnt is not implemented
pitem unite (pitem l, pitem r) {
	 if (!l || !r) return l?  l: r;
	 if (l-> prior <r-> prior) swap (l, r);
	 pitem lt, rt;
	 split (r, l-> key, lt, rt);
	 l-> l = unite (l-> l, lt);
	 l-> r = unite (l-> r, rt);
	 return l;
}

//returns the pointer of the node cotaining the key (null if it is not present)
pitem find(pitem &t, int key)
{
    if(!t) return t;
    if(key==t->key) return t;
    if(key<t->key) return find(t->l,key);
    return find(t->r,key);
}

void traverse(pitem &t)
{
    if(!t) { print1("nothing"); return; }
    print2(t->key,t->prior);
    printf("The left child is ");
    traverse(t->l);
    printf("The right child is ");
    traverse(t->r);
}
//normally needed this two to keep the treap/treaps
#define lim 110000
item arr[lim];
pitem root;

int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    srand(time(NULL));
    int i,n,q;
    cin>>n>>q;
    pitem root=NULL;
    int modd=20;
    for(i=1;i<=n;i++)
    {
        int a=rand()%modd;
        print1(a);
        arr[i]=item(a);
        insert(root,&arr[i]);
    }
    traverse(root);

    for(i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==1)
        {
            erase(root,b);
            traverse(root);
        }
        else
        {
            pitem tem=find(root,b);
            if(!tem) print1("Not found");
            else print1("Found");
        }

    }
    return 0;
}


