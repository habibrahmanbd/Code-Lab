#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#define LL long long
using namespace std;
#define s 10000010
bool col[s];
int prime[s];

int seive()//1 indexed
{
    long long i,j,k;
    col[0]=true;
    col[1]=true;
    k=0;
    prime[++k]=2;
    for(j=4;j<s;j+=2)
        col[j]=true;
    for(i=3;i<s;i+=2)
         if(!col[i])
         {
                prime[++k]=i;
                for(j=i*i;j<s;j+=2*i)
                    col[j]=true;
         }
    return 0;
}

int prim[s][9],freq[s][9],ind[s];
void factorize()
{
    seive();
    //print1(0);
    LL i,j,cnt=0;
    for(i=1;i<s;i++)
    if(!col[i])
    {
        for(j=i;j<s;j+=i,cnt++)
        {
            prim[j][ind[j]]=i;
            freq[j][ind[j]++]=1;
        }
        if(i>1000) continue;
        LL num=i*i;
        while(num<s)
        {
            for(j=num;j<s;j+=num,cnt++)
                freq[j][ind[j]-1]++;
            num*=i;
        }
    }
    //print1(cnt);
}


int main()
{
    long long n;
    seive();
    while(cin>>n)
        cout<<prime[n]<<endl;;
    return 0;
}






