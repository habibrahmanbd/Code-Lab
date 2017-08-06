#include<stdio.h>
#include<string.h>
#define len 20
char str[len],comb[len];//used for storing all combinations one by one/the answer string
bool used[len];

int cross_candidate(int can[],int k)
{
    int cn=0,i;
    for(i=0;i<strlen(str);i++)
            can[cn++]=i;
    return cn;
}

int bt(int p,int k)
{
    int i,can[strlen(str)],cn;
    if(k>strlen(str))
        return 0;
    comb[p]='\0';
    printf("%s\n",comb);
    cn=cross_candidate(can,k);//the number of available candidates
    for(i=0;i<cn;i++)
    {
        comb[p]=str[can[i]];//storing candidates in index
        bt(p+1,can[i]+1);//starting from the next
    }
    return 0;
}


int main()
{
    while(gets(str))
         bt(0,0);
    return 0;
}
