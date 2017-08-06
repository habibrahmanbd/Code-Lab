LL getval(LL a,LL b,LL c,LL A,LL B)
{
    return abs(A-a)+abs(B-b)+abs(A*B-c);
}

//minimum function
LL ts(LL a,LL b,LL c,LL A,LL st,LL end)
{
    if(st==end) return st;
    LL mid1=(2*st+end)/3;
    LL mid2=(st+2*end)/3;
    if(end-st==1)
    {
        if(getval(a,b,c,A,st)>getval(a,b,c,A,end)) return end;
        return st;
    }
    //print2(mid1,mid2);
    if(getval(a,b,c,A,mid1)>getval(a,b,c,A,mid2)) return ts(a,b,c,A,mid1+1,end);//because of floor
    return ts(a,b,c,A,st,mid2-1);
}
