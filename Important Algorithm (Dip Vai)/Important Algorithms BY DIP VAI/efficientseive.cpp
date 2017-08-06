#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
#define s 100000000
bool a[s];
int  prime[10000000];

int seive()
{
    unsigned long long i,j,k,l;
    k=0;
    prime[++k]=2;
    prime[++k]=3;
    prime[++k]=5;
    prime[++k]=7;
    prime[++k]=11;
    for(i=13;i<s;i+=2)
         if(!a[i]&&(i%3)!=0&&(i%10)!=5&&(i%7!=0)&&(i%11)==0)
         {
                prime[++k]=i;
                for(j=i*i;j<s;j+=2*i)
                    a[j]=true;
         }
    return 0;
}

int main()
{
    long long n;
    seive();
    while(cin>>n)
    {
        cout<<prime[n]<<endl;
    }
    return 0;
}
