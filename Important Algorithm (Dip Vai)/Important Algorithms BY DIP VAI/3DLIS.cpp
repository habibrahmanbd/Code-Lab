/// Syed Shahriar Manjur (Dip)
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
#define mod         1000000007
#define eulerconstant 0.5772156649

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
//complexity n(logn)^2
const int MAXN = 300110;
struct node {
    int x,y,z;
}box[300111];

map <int, int> pos[MAXN];
map <int, int>::iterator it;

int m, n, A, B;

int C = ~(1<<31), M = (1<<16)-1;
int r() {
    A = 36969 * (A & M) + (A >> 16);
    B = 18000 * (B & M) + (B >> 16);
    return (C & ((A << 16) + B)) % 1000000;
}

int cmp(const node & a, const node & b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y > b.y;
    return 0;
}

bool check(int a, int b) {
    if(pos[a].empty()) return false;
    it = pos[a].lower_bound(box[b].y);
    if(it != pos[a].begin()) {
        it--;
        if(it->second < box[b].z) return true;
    }
    return false;
}

//y should be strictly increasing, and z should be strictly decreasing
void insert(int a, int b) {
    if(pos[a].empty()) {
        pos[a][box[b].y] = box[b].z;
        return ;
    }
    it = pos[a].lower_bound(box[b].y);
    if(it == pos[a].end()) {
        it--;
        if(it->second <= box[b].z) return ;
        pos[a][box[b].y] = box[b].z;
        return ;
    }
    if(it->first == box[b].y) {
        if(it->second <= box[b].z) {
            return ;
        }
    }
    if(it != pos[a].begin()) {
        if((--it)->second <= box[b].z) return ;
        it++;
    }
    while(it != pos[a].end() && it->second >= box[b].z) {
        pos[a].erase(it++);
    }
    pos[a][box[b].y] = box[b].z;
}

int main() {
    //freopen("pro.in", "r", stdin);
    while(scanf("%d%d%d%d", &m, &n, &A, &B)) {

        if(m == 0 && n == 0 && A == 0 && B == 0) break;

        for(int i = 1; i <= m; i++) {
            scanf("%d%d%d", &box[i].x, &box[i].y, &box[i].z);
        }

        for(int i = 0; i < MAXN; i++) pos[i].clear();

        for(int i = 1; i <= n; i++) {
            box[i + m].x = r();
            box[i + m].y = r();
            box[i + m].z = r();
        }

        n += m;

        int f_ans = 1;

        sort(box + 1, box + 1 + n, cmp);

        int mx = 0;
        for(int i = 1; i <= n; i++) {
            if(i > 1 && box[i].x == box[i - 1].x && box[i].y == box[i - 1].y && box[i].z == box[i - 1].z) continue;
            int l = 1, r = mx, mid, ans = 0;
            while(l <= r) {
                mid = (l + r) / 2;
                if(check(mid, i)) {
                    l = mid + 1;
                    ans = mid;
                } else {
                    r = mid - 1;
                }
            }
            f_ans = max(f_ans, ans + 1);
            insert(ans + 1, i);
            mx = f_ans;
        }
        printf("%d\n", f_ans);
    }
    return 0;
}
