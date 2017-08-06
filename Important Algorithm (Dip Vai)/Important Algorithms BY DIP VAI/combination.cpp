#include<stdio.h>
#include<iostream>
using namespace std;
#define mo 1010
unsigned long long comb[mo][mo];

void combination()
{
    int i,j;
    for(i=0;i<mo;i++)//let comb[0][0]=1
        comb[i][0]=1;
    comb[1][1]=1;
    for(i=2;i<mo;i++)
        for(j=1;j<mo;j++)
            comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
    return ;
}


int main()
{
    combination();
    int n,r;
    while(scanf("%d %d",&n,&r)==2)
        cout<<comb[n][r]<<endl;
    return 0;
}
