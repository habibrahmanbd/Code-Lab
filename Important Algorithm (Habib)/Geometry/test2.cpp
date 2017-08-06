//大白p263
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <functional>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const double eps=1e-8;//精度
const int INF=1<<29;
const double PI=acos(-1.0);
int dcmp(double x){//判断double等于0或。。。
	if(fabs(x)<eps)return 0;else return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
typedef vector<Point> Polygon;
Vector operator+(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}//向量+向量=向量
Vector operator-(Point a,Point b){return Vector(a.x-b.x,a.y-b.y);}//点-点=向量
Vector operator*(Vector a,double p){return Vector(a.x*p,a.y*p);}//向量*实数=向量
Vector operator/(Vector a,double p){return Vector(a.x/p,a.y/p);}//向量/实数=向量
bool operator<( const Point& A,const Point& B ){return dcmp(A.x-B.x)<0||(dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)<0);}
bool operator==(const Point&a,const Point&b){return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;}
bool operator!=(const Point&a,const Point&b){return a==b?false:true;}
struct Segment{
	Point a,b;
	Segment(){}
	Segment(Point _a,Point _b){a=_a,b=_b;}
	bool friend operator<(const Segment& p,const Segment& q){return p.a<q.a||(p.a==q.a&&p.b<q.b);}
	bool friend operator==(const Segment& p,const Segment& q){return (p.a==q.a&&p.b==q.b)||(p.a==q.b&&p.b==q.a);}
};
struct Circle{
	Point c;
	double r;
	Circle(){}
	Circle(Point _c, double _r):c(_c),r(_r) {}
	Point point(double a)const{return Point(c.x+cos(a)*r,c.y+sin(a)*r);}
	bool friend operator<(const Circle& a,const Circle& b){return a.r<b.r;}
};
struct Line{
	Point p;
	Vector v;
	double ang;
	Line() {}
	Line(const Point &_p, const Vector &_v):p(_p),v(_v){ang = atan2(v.y, v.x);}
	bool operator<(const Line &L)const{return  ang < L.ang;}
};
double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}//|a|*|b|*cosθ 点积
double Length(Vector a){return sqrt(Dot(a,a));}//|a| 向量长度
double Angle(Vector a,Vector b){return acos(Dot(a,b)/Length(a)/Length(b));}//向量夹角θ
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}//叉积 向量围成的平行四边形的面积
double Area2(Point a,Point b,Point c){return Cross(b-a,c-a);}//同上 参数为三个点
double DegreeToRadius(double deg){return deg/180*PI;}
double GetRerotateAngle(Vector a,Vector b){//向量a顺时针旋转theta度得到向量b的方向
	double tempa=Angle(a,Vector(1,0));
	if(a.y<0) tempa=2*PI-tempa;
	double tempb=Angle(b,Vector(1,0));
	if(b.y<0) tempb=2*PI-tempb;
	if((tempa-tempb)>0) return tempa-tempb;
	else return tempa-tempb+2*PI;
}
double torad(double deg){return deg/180*PI;}//角度化为弧度
Vector Rotate(Vector a,double rad){//向量逆时针旋转rad弧度
	return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
Vector Normal(Vector a){//计算单位法线
	double L=Length(a);
	return Vector(-a.y/L,a.x/L);
}
Point GetLineProjection(Point p,Point a,Point b){//点在直线上的投影
	Vector v=b-a;
	return a+v*(Dot(v,p-a)/Dot(v,v));
}
Point GetLineIntersection(Point p,Vector v,Point q,Vector w){//求直线交点 有唯一交点时可用
	Vector u=p-q;
	double t=Cross(w,u)/Cross(v,w);
	return p+v*t;
}
int ConvexHull(Point* p,int n,Point* sol){//计算凸包
	sort(p,p+n);
	int m=0;
	for(int i=0;i<n;i++){
		while(m>1&&Cross(sol[m-1]-sol[m-2],p[i]-sol[m-2])<=0) m--;
		sol[m++]=p[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--){
		while(m>k&&Cross(sol[m-1]-sol[m-2],p[i]-sol[m-2])<=0) m--;
		sol[m++]=p[i];
	}
	if(n>0) m--;
	return m;
}
double Heron(double a,double b,double c){//海伦公式
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){//线段规范相交判定
	double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1);
	double c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
double CutConvex(const int n,Point* poly, const Point a,const Point b, vector<Point> result[3]){//有向直线a b 切割凸多边形
	vector<Point> points;
	Point p;
	Point p1=a,p2=b;
	int cur,pre;
	result[0].clear();
	result[1].clear();
	result[2].clear();
	if(n==0) return 0;
	double tempcross;
	tempcross=Cross(p2-p1,poly[0]-p1);
	if(dcmp(tempcross)==0) pre=cur=2;
	else if(tempcross>0) pre=cur=0;
	else pre=cur=1;
	for(int i=0;i<n;i++){
		tempcross=Cross(p2-p1,poly[(i+1)%n]-p1);
		if(dcmp(tempcross)==0) cur=2;
		else if(tempcross>0) cur=0;
		else cur=1;
		if(cur==pre){
			result[cur].push_back(poly[(i+1)%n]);
		}
		else{
			p1=poly[i];
			p2=poly[(i+1)%n];
			p=GetLineIntersection(p1,p2-p1,a,b-a);
			points.push_back(p);
			result[pre].push_back(p);
			result[cur].push_back(p);
			result[cur].push_back(poly[(i+1)%n]);
			pre=cur;
		}
	}
	sort(points.begin(),points.end());
	if(points.size()<2){
		return 0;
	}
	else{
		return Length(points.front()-points.back());
	}
}
double DistanceToSegment(Point p,Segment s){//点到线段的距离
	if(s.a==s.b) return Length(p-s.a);
	Vector v1=s.b-s.a,v2=p-s.a,v3=p-s.b;
	if(dcmp(Dot(v1,v2))<0) return Length(v2);
	else if(dcmp(Dot(v1,v3))>0) return Length(v3);
	else return fabs(Cross(v1,v2))/Length(v1);
}
bool isPointOnSegment(Point p,Segment s){
	return dcmp(Cross(s.a-p,s.b-p))==0&&dcmp(Dot(s.a-p,s.b-p))<0;
}
int isPointInPolygon(Point p, Point* poly,int n){//点与多边形的位置关系
	int wn=0;
	for(int i=0;i<n;i++){
		Point& p2=poly[(i+1)%n];
		if(isPointOnSegment(p,Segment(poly[i],p2))) return -1;//点在边界上
		int k=dcmp(Cross(p2-poly[i],p-poly[i]));
		int d1=dcmp(poly[i].y-p.y);
		int d2=dcmp(p2.y-p.y);
		if(k>0&&d1<=0&&d2>0)wn++;
		if(k<0&&d2<=0&&d1>0)wn--;
	}
	if(wn) return 1;//点在内部
	else return 0;//点在外部
}
double PolygonArea(vector<Point> p){//多边形有向面积
	double area=0;
	int n=p.size();
	for(int i=1;i<n-1;i++)
		area+=Cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2;
}
int GetLineCircleIntersection(Line L,Circle C,Point& p1,Point& p2){//圆与直线交点 返回交点个数
	double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y-C.c.y;
	double e = a*a + c*c, f = 2*(a*b+c*d), g = b*b + d*d -C.r*C.r;
	double delta = f*f - 4*e*g;
	if(dcmp(delta) < 0)  return 0;//相离
	if(dcmp(delta) == 0) {//相切
		p1=p1=C.point(-f/(2*e));
		return 1;
	}//相交
	p1=(L.p+L.v*(-f-sqrt(delta))/(2*e));
	p2=(L.p+L.v*(-f+sqrt(delta))/(2*e));
	return 2;
}
double rotating_calipers(Point *ch,int n)//旋转卡壳
{
	int q=1;
	double ans=0;
	ch[n]=ch[0];
	for(int p=0;p<n;p++)
	{
		while(Cross(ch[q+1]-ch[p+1],ch[p]-ch[p+1])>Cross(ch[q]-ch[p+1],ch[p]-ch[p+1]))
			q=(q+1)%n;
		ans=max(ans,max(Length(ch[p]-ch[q]),Length(ch[p+1]-ch[q+1])));
	}
	return ans;
}
Polygon CutPolygon(Polygon poly,Point a,Point b){//用a->b切割多边形 返回左侧
	Polygon newpoly;
	int n=poly.size();
	for(int i=0;i<n;i++){
		Point c=poly[i];
		Point d=poly[(i+1)%n];
		if(dcmp(Cross(b-a,c-a))>=0) newpoly.push_back(c);
		if(dcmp(Cross(b-a,c-d))!=0){
			Point ip=GetLineIntersection(a,b-a,c,d-c);
			if(isPointOnSegment(ip,Segment(c,d))) newpoly.push_back(ip);
		}
	}
	return newpoly;
}
int GetCircleCircleIntersection(Circle c1,Circle c2,Point& p1,Point& p2){
	double d=Length(c1.c-c2.c);
	if(dcmp(d)==0){
		if(dcmp(c1.r-c2.r)==0) return -1;//两圆重合
		return 0;
	}
	if(dcmp(c1.r+c2.r-d)<0) return 0;
	if(dcmp(fabs(c1.r-c2.r)-d)>0) return 0;
	double a=Angle(c2.c-c1.c,Vector(1,0));
	double da=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
	p1=c1.point(a-da);p2=c1.point(a+da);
	if(p1==p2) return 1;
	return 2;
}
//--------------------------------------
//--------------------------------------
//--------------------------------------
//--------------------------------------
//--------------------------------------
Point poly1[200],poly2[200];
set<Point> ans;
int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF){
		if(n<3) break;
		for(int i=0;i<n;i++) scanf("%lf%lf",&poly1[i].x,&poly1[i].y);
		scanf("%d",&m);
		for(int i=0;i<m;i++) scanf("%lf%lf",&poly2[i].x,&poly2[i].y);
		ans.clear();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				Segment a(poly1[i],poly1[(i+1)%n]);
				Segment b(poly2[j],poly2[(j+1)%m]);
				Point p=GetLineIntersection(a.a,a.b-a.a,b.a,b.b-b.a);
				if(isPointOnSegment(p,a)&&isPointOnSegment(p,b))
					ans.insert(p);
			}
		}
		for(int i=0;i<n;i++)
			if(isPointInPolygon(poly1[i],poly2,m)!=0) ans.insert(poly1[i]);
		for(int i=0;i<m;i++)
			if(isPointInPolygon(poly2[i],poly1,n)!=0) ans.insert(poly2[i]);


		printf("%d\n",ans.size());
		for(set<Point>::iterator it=ans.begin();it!=ans.end();it++)
			printf("%.2lf %.2lf\n",it->x,it->y);
	}
	return 0;
}

/*
4
3 0
5 2
3 3
1 2
4
3 1
5 3
3 5
1 3
4
0 0
1 0
1 1
0 1
3
0 0
100 100
100 99
*/
