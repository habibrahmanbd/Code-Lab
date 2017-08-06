#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define MIN(x,y,z) min(min((x),(y)),(z))
char A[20] = "TRAILS", B[20] = "ZEIL";
int n = (int)strlen(A), m = (int)strlen(B);
int i, j, table[20][20]; // Needleman Wunsnch's algorithm
int dif(int i,int j)
{
    if(A[i-1]!=B[j-1]) //minus -1 for 0 based string input
        return 1;// mismatch then 1 step needed
    return 0; //match then 0 step needed
}
int main()
{
    memset(table, 0, sizeof table);
    // insert/delete / Replace char. to change A into B
    for (i = 1; i <= n; i++)
        table[i][0] = i ; //Steps to make i  from i char.
    for (j = 1; j <= m; j++)
        table[0][j] = j; //Steps to make j from 0 char.

    for (j = 1; j <= m; j++)
        for (i = 1; i <= n; i++)
        {
            // minimum number of steps required for replace or match / delete / insert
            table[i][j] = MIN(table[i - 1][j - 1] + dif(i,j), table[i-1][j]+1, table[i][j-1]+1);// steps for match or mismatches
        }

    printf("DP table:\n");
    for (j = 0; j <= m; j++)
    {
        for (i = 0; i <= n; i++)
            printf("%3d", table[i][j]);
        printf("\n");
    }
    printf("Minimum Number of steps Needed: %d\n", table[n][m]);

    return 0;
}
