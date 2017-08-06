typedef long long ll;
typedef struct {ll x,y;void scan(){cin>>x>>y;}}P;

P MV(P a,P b){ P r; r.x = b.x-a.x; r.y = b.y-a.y; return r;}
ll CV(P a,P b){return a.x*b.y - a.y*b.x;}

bool onsegment(P a,P b,P c){
    return ( min(a.x,b.x)<=c.x && c.x<=max(a.x,b.x) && min(a.y,b.y)<=c.y && c.y<=max(a.y,b.y) ) ;
}
bool segment_intersect(P p1,P p2,P p3,P p4)
{
    ll d1,d2,d3,d4;

    d1 = CV(MV(p3,p4),MV(p3,p1));
    d2 = CV(MV(p3,p4),MV(p3,p2));
    d3 = CV(MV(p1,p2),MV(p1,p3));
    d4 = CV(MV(p1,p2),MV(p1,p4));

    if(d1*d2<0 && d3*d4<0)  return true;
    if(!d1 && onsegment(p3,p4,p1))  return true;
    if(!d2 && onsegment(p3,p4,p2))  return true;
    if(!d3 && onsegment(p1,p2,p3))  return true;
    if(!d4 && onsegment(p1,p2,p4))  return true;

    return false;
}
