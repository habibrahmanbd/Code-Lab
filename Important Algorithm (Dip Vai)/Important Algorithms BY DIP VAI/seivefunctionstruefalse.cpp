#define s 10000000
int seive()
{
    long long i,j;
    memset(a,true,sizeof(a));
    a[1]=false;
    for(i=4;i<s;i+=2)
        a[i]=false;
    for(i=3;i<s;i+=2)
         if(a[i])
         {
            for(j=i*i;j<s;j+=2*i)
                    a[j]=false;
         }
    return 0;
}
