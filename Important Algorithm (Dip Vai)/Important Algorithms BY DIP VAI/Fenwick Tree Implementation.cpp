//#pragma warning (disable: 4786)
/* Uvalive 6443
Last year there was an alien ship abducting people on Earth and returning them in bizarre locations.
Some of them were returned in the middle of a desert, a jungle, an ocean, or a lake. Fortunately,
our brilliant scientist (with some help from last year ICPC contestants) was able to quickly locate the
positions in which the humans were returned and saved all the abducted humans. Nevertheless, the
Earth government is still afraid that the alien ship will come back and do it again this year, or maybe
even worse.
After analyzing last year report, our brilliant scientist now has a better knowledge on how the alien
transporter technology works. For simplicity, let’s assume our world is in one dimensional space (i.e.,
each person occupies space only in an interval of the x-axis). Depending on the person’s orientation
and posture, it requires different energy (at each integral point in the x-axis) to transport the person.
To be precise, to transport a person p who lies on position [x1, x2], it requires energy at each integral
x position according to some function fp(x) = ax3 + bx2 + cx + d.
Here is an example of 6 humans scattered on x-axis:
• Person #1 is at x = [1, 8] with f1(x) = x
2 − 8x + 17
• Person #2 is at x = [10, 16] with f2(x) = −x
2 + 28x − 179
• Person #3 is at x = [10, 16] with f3(x) = x
2 − 26x + 176
• Person #4 is at x = [17, 29] with f4(x) = 9
• Person #5 is at x = [14, 22] with f5(x) = 2x − 7
• Person #6 is at x = [24, 29] with f6(x) = x
3 − 80x
2 + 2125x − 18732
The graph below shows where on the x-axis each of the 6 person lies. The y-axis is the energy
required for the transporter to operate. Note that there is no energy required for non-integral value of
x. Each line (or curve) in the graph is a guideline that signifies a person.
When the alien ship performs the abduction on the human located at [x1, x2], it requires energy
equivalent to the total of energy at each integral x positions in between x1 and x2, inclusive. ForACM-ICPC Live Archive: 6443 – Alien Abduction Again 2/3
example, if the alien ship tries to transport human at x = [10, 25], it would require 353 energy (i.e. the
sum of the y-value of the black dots in the graph above). Observe that person #5 and person #6 are
“partially” transported.
Since the transporter is operating at high energy, it creates a space distortion every time after it
finished the abduction. The space distortion somehow equals to an imaginary human being registered
to the system at [min(r1, r2), max(r1, r2)] with some function fp(x) where r1 = (x1 · E) mod 106
, r2 =
(x2 ·E) mod 106
, and E is the energy required by the alien ship to perform the abduction to all humans
at [x1, x2] right before this imaginary human is registered. Note that this E is the non negative energy
result after modulo 1,000,000,007 (see the output section).
To prevent mankind from being transported in the future, the brilliant scientist suggests us to emit
negative energy with the same amount as soon as the transport operation is in progress.
Knowing this, the Earth government asks the brilliant scientist to build a device to disrupt the
alien ship transport operation. However, in order to build this device, the scientist must be able to
compute the total energy of a given range in the x-axis very quickly. Since the Earth is so large, even
the brilliant scientist cannot compute the total energy by hand, he needs to create a program for this.
Well... unsurprisingly, the brilliant scientist cannot program. Knowing that you are one of the best
programmers on Earth, the scientist asks for your help again!
Note that your program must be very-very efficient, otherwise it will be too late to counter the
transport operation and people will still be abducted!
Input
The first line of input contains an integer T (T ≤ 30) denoting the number of cases. Each case starts
with an integer N. Each of the next N lines contains one of the following command:
• p x1 x2 a b c d : a person is registered at position [x1, x2] with f(x) = ax3 + bx2 + cx + d.
• t x1 x2 a b c d : an abduction is in progress at position [x1, x2]. After the abduction, an imaginary
person is registered (due to the space distortion) which equals to the command:
p min(r1, r2) max(r1, r2) a b c d
where
* r1 = (x1 · E) mod 106
* r2 = (x2 · E) mod 106
* E is the non negative energy result after modulo 1,000,000,007.
The constraints are:
• 1 ≤ N ≤ 100, 000
• 0 ≤ x1 ≤ x2 < 1, 000, 000
• a, b, c, d are all signed 32-bit integers.
*/
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

#define csprnt printf("Case #%d:\n", ++cas);
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
//for range query and range update in BIT (0 based)
#define lim 4010000
LL dataMul[4][lim];
LL dataAdd[4][lim];
LL cum[4][lim];

void internalUpdate(int in,int at, LL mul, LL add) {
    while (at < lim) {
        dataMul[in][at] += mul;
        dataMul[in][at] %= mod;
        dataAdd[in][at] += add;
        dataAdd[in][at] %= mod;
        at |= (at + 1);
    }
}

void update(int in,int left, int right, LL by) {
    if(left>right) return;
    if(left>0) internalUpdate(in,left, by, -by * cum[in][left-1]);
    else if(in>0) internalUpdate(in,left, by, 0);
    else internalUpdate(in,left, by, by);
    internalUpdate(in,right, -by, by * cum[in][right]);
}

LL query(int in,int at) {
    if(at<0) return 0;
    LL mul = 0;
    LL add = 0;
    int start = at;
    while (at >= 0) {
        mul += dataMul[in][at];
        mul %= mod;
        add += dataAdd[in][at];
        add %= mod;
        at = (at & (at + 1)) - 1;
    }

    LL ret = mul*cum[in][start] + add;
    ret %= mod;
    return ret;
}

LL query(int at)
{
    LL ret = query(0,at);
    ret += query(1,at);
    ret += query(2,at);
    ret += query(3,at);
    ret %= mod;
    return ret;
}


int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    LL i;
    fr(i,1,lim-1)
        cum[0][i]=cum[0][i-1]+1;
    fr(i,1,lim-1)
        cum[1][i]=(cum[1][i-1]+i)%mod;
    fr(i,1,lim-1)
        cum[2][i]=(cum[2][i-1]+i*i)%mod;
    fr(i,1,lim-1)
        cum[3][i]=(cum[3][i-1]+i*i*i)%mod;
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        csprnt;
        mem(dataAdd,0);
        mem(dataMul,0);
        int n;
        cin>>n;
        char cc;
        LL x1,x2,a,b,c,d;
        for(i=1;i<=n;i++)
        {
            scanf(" %c",&cc);
            if(cc=='p')
            {
                scanf("%lld %lld %lld %lld %lld %lld",&x1,&x2,&a,&b,&c,&d);
                update(0,x1,x2,d);
                update(1,x1,x2,c);
                update(2,x1,x2,b);
                update(3,x1,x2,a);
            }

            else
            {
                  scanf("%lld %lld %lld %lld %lld %lld",&x1,&x2,&a,&b,&c,&d);
                  LL ans = query(x2);
                  ans -= query(x1-1);
                  ans %= mod;
                  ans = (ans + mod)%mod;
                  printf("%lld\n",ans);
                  x1 = (x1 * ans) % 1000000;
                  x2 = (x2 * ans) % 1000000;
                  if(x1>x2) swap(x1,x2);
                  update(0,x1,x2,d);
                  update(1,x1,x2,c);
                  update(2,x1,x2,b);
                  update(3,x1,x2,a);
            }
        }
    }
    return 0;
}
/*
2
7
p 1 8 0 1 -8 17
p 10 16 0 -1 28 -179
p 10 16 0 1 -26 176
p 17 29 0 0 0 9
p 14 22 0 0 2 -27
p 24 29 1 -80 2125 -18732
t 10 25 0 0 0 0
6
p 4 10 3 4 5 -600
t 2 5 1 0 0 0
t 999000 999900 0 0 0 0
p 3 6 0 0 0 141
t 2 5 3 1 2 5
t 0 999999 0 0 1 2
*/

