#include<stdio.h>
#include<algorithm>
using namespace std;
#define s 500
#define null 0
char edge[s],start,end,set[s],go;
struct vertices{
    int a;
    int weight;
    struct vertices *next;
};
typedef struct vertices ver;
ver node[s];
ver *address[s];
int minlen[s],edgeno[s],cont,cost,last,in[s],mina,k;

int shortestpath(ver *x,int y)
{
    //printf("%d\n",x->next);
    if(x->next!=null)
    {
        if(in[x->a]==0)
            if(minlen[x->a]==0 ||  minlen[x->a]>y+x->weight)
            {
                minlen[x->a]=y+x->weight;
                set[++k]=x->a;
            }
        return shortestpath(x->next,y);
    }
    return 0;
}

int main()
{
    int i,j;
    while(1==1)
    {
        memset(node,0,150*sizeof(ver));
        memset(address,0,150*sizeof(ver *));
        memset(set,0,150*sizeof(char));
        memset(minlen,0,150*sizeof(int));
        memset(edgeno,0,150*sizeof(int));
        memset(in,0,150*sizeof(int));
        cont=0;
        cost=0;
        k=-1;
        for(;;)
        {
            gets(edge);
            if(strcmp(edge,"deadend")==0)
                break;
            last=strlen(edge)-1;
            if(address[edge[0]]!=null)
                address[edge[0]]=address[edge[0]]->next;
            else
                address[edge[0]]=&node[edge[0]];
            if(address[edge[last]]!=null)
                address[edge[last]]=address[edge[last]]->next;
            else
                address[edge[last]]=&node[edge[last]];
            address[edge[0]]->a=edge[last];
            address[edge[0]]->weight=last+1;
            address[edge[last]]->a=edge[0];
            address[edge[last]]->weight=last+1;
            address[edge[0]]->next=(ver *)malloc(sizeof(ver));
            address[edge[last]]->next=(ver *)malloc(sizeof(ver));
            address[edge[0]]->next->next=null;
            address[edge[last]]->next->next=null;
            cost+=last+1;
            edgeno[edge[0]]++;
            edgeno[edge[last]]++;
        }
        for(i=97;i<=123;i++)
            if(edgeno[i]%2==1)
            {
                if(cont==0)
                {
                    start=i;
                    cont++;
                }
                else
                {
                    end=i;
                    break;
                }
            }
        if(cont==0)
        {
            printf("%d\n",cost);
            continue;
        }
        go=start;
        for(;;)
            if(go!=end)
            {
                in[go]=1;
                shortestpath(&node[go],minlen[go]);
                mina=0;
                for(i=0;i<=k;i++)
                    if(in[set[i]]==0  &&  (minlen[set[i]]<mina ||  mina==0))
                    {
                        mina=minlen[set[i]];
                        go=set[i];
                    }
            }
            else
                break;
        printf("%d\n",cost+minlen[end]);
    }
    return 0;
}
