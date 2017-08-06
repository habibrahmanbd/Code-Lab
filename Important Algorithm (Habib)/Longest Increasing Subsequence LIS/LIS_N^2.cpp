using namespace std;
#include<bits/stdc++.h>
#define db          double
#define ll          long long
#define ull         unsigned long long
#define vi          vector<int>
#define vl          vector<long>
#define vll         vector<ll>
#define pi          pair<int,int>
#define pl          pair<long,long>
#define pll         pair<ll,ll>
#define pb          push_back
#define pf          printf
#define sf          scanf
#define mii         map<int,int>
#define mll         map<ll,ll>
#define II          ({int a; sf("%d",&a); a;})
#define IL          ({long a; sf("%ld",&a); a;})
#define ILL         ({ll a; sf("%lld",&a); a;})
#define ID          ({db a; sf("%lf",&a); a;})
#define IF          ({float a; sf("%f",&a); a;})
#define IC          ({char a; sf("%c",&a); a;})
#define FRI(a,b,c)  for(int i=a;   i<=b; i+=c)
#define FRL(a,b,c)  for(long i=a;  i<=b; i+=c)
#define FRLL(a,b,c) for(ll i=a;    i<=b; i+=c)
#define in          freopen("in.txt","r",stdin)
#define out         freopen("out.txt","w",stdout)
#define PI          2*acos(0.0)
#define mod         1000000007
#define INF         1<<29
int n; // the number of items in the sequence
int Sequence[32]; // the sequence of integers
int L[32]; // L[] as described in the algorithm

void takeInput()
{
    scanf("%d", &n); // how many numbers in the sequence ?

    // take the sequence
    for( int i = 0; i < n; i++ )
        scanf("%d", &Sequence[i]);
}

int LIS()   // which runs the LIS algorithm and returns the result
{
    int i, j; // auxilary variables for iteration

    // initialize L[] with 1
    for( i = 0; i < n; i++ )
        L[i] = 1;

    // start from the left most item and itetare right
    for( i = 0; i < n; i++ )
    {
        // for the ith item item find all items that are in right
        for( j = i + 1; j < n; j++ )
        {

            if( Sequence[j] > Sequence[i] )
            {
                // the item is greater than the ith item

                // so, L[j] = L[i] + 1, since jth item can be added after ith
                // item. if L[j] is already greater than or equal to L[i] + 1
                // then ignore it
                if( L[j] < L[i] + 1 )
                    L[j] = L[i] + 1;
            }
        }
    }
    // now find the item whose L[] value is maximum
    int maxLength = 0;
    for( i = 0; i < n; i++ )
    {
        if( maxLength < L[i]  )
            maxLength = L[i];
    }
    // return the result
    return maxLength;
}
int LisSequence[32]; // for storing the sequence

void findSequence( int maxLength )   // finds a valid sequence
{
    int i, j; // variable used for iteration

    // at first find the position of the item whose L[] is maximum
    i = 0;
    for( j = 1; j < n; j++ )
    {
        if( L[j] > L[i] )
            i = j;
    }

    // initialize the position in LisSequence where the items can be added.
    // observe that the data are saving from right to left!
    int top = L[i] - 1;

    // insert the item in i-th position to LisSequence
    LisSequence[top] = Sequence[i];
    top--; // is decreasing such that a new item can be added in a new place

    // now find the other valid numbers to form the sequence
    for( j = i - 1; j >= 0; j-- )
    {
        if( Sequence[j] < Sequence[i] && L[j] == L[i] - 1 )
        {
            // we have found a valid item so, we will save it
            i = j; // as in our algorithm
            LisSequence[top] = Sequence[i]; // stored
            top--; // decreased for new items
        }
    }

    // so, we have got the sequence, now we want to print it
    printf("LIS is");
    for( i = 0; i < maxLength; i++ )
    {
        printf(" %d", LisSequence[i]);
    }
    puts("");
}
int main()
{
    takeInput();
    int result = LIS();
    printf("The LIS length is %d\n", result);
    findSequence( result );
    return 0;
}
