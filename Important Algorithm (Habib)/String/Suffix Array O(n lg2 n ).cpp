/*
Here you can see an extremely short implementation
for suffix arrays in O(n lg2 n).
*/
# include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAXN 65536
#define MAXLG 17
char A[MAXN] ;
struct entry
{
    int nr[2], p;
} L[MAXN];
int P[MAXLG] [MAXN],  N,  i ,  stp, cnt;
int cmp(struct entry a,  struct entry b)
{
    return a.nr[0] == b. nr[0] ? (a.nr[1]  < b.nr[1] ? 1 : 0) : (a.nr[0]  < b.nr[0] ? 1 : 0);
}
int main(void)
{
    gets(A);
    for (N = strlen(A) , i = 0; i < N;  i ++)
        P[0] [i] = A[i]  - 'a' ;
    for (stp = 1,  cnt = 1; cnt >> 1 < N;  stp ++,  cnt <<= 1)
    {
        for (i = 0;  i < N; i  ++)
        {
            L[i] .nr[0]  = P[stp - 1] [i];
            L[i] .nr[1]  = i + cnt < N ? P[stp - 1][i + cnt]  :  -1;
            L[i] .p = i ;
        }
        sort(L, L + N,  cmp);
        for (i = 0;  i < N; i  ++)
            P[stp][L[i ]. p] = i > 0 && L[i]. nr[0]  == L[i  - 1] .nr[0] && L[i].nr[1] == L[i - 1].nr[1] ?
                               P[stp][L[i  - 1]. p] : i ;
    }
    for(int it = 0; it<N; it++)
            printf("%d ",P[(int)ceil(log2(N))][it]);
        printf("\n");
    return 0;
}
/*
The suffix array will be found on the last row of matrix P. Searching the kth suffix is now
immediate, so we won’t return to this aspect. The quantity of memory used may be reduced, using only
the last two lines of the matrix P. It is a trade-off, as in this case the structure will not be able any more to
execute efficiently the following operation.
*/
