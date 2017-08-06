#include<stdio.h>
#include<string.h>
#define len 10
char str[len],per[len];//used for storing all permutations one by one/the answer string
bool used[len];

int cross_candidate(int can[])
{
    int cn=0,i;
    for(i=0;i<strlen(str);i++)
        if(used[i]==false)//storing available index serially
            can[cn++]=i;
    return cn;
}

int bt(int p)
{
    int i,can[strlen(str)],cn;
    if(p==strlen(str))
    {
        per[p]='\0';
        printf("%s\n",per);
        return 0;
    }
    cn=cross_candidate(can);//the number of available candidates
    for(i=0;i<cn;i++)
    {
        used[can[i]]=true;//if is is used or not
        per[p]=str[can[i]];//storing candidates in index
        bt(p+1);
        used[can[i]]=false;
    }
    return 0;
}


int main()
{
    while(gets(str))
         bt(0);
    return 0;
}
