//刘汝佳—算法竞赛入门经典竞赛指南 几何专题


#include<iostream>
#include<math.h>
using namespace std;
//point

struct Point{
	double x,y;
	Point(double x=0, double y=0)
	: x(x), y(y){}
}; 

typedef Point Vector;//从程序实现上，Vector只是Point的别名.

//向量+向量=向量；点+向量=点 
Vector operator + (Vector A, Vector B){
		return Vector(A.x+B.x, A.y+B.y);
} 

//点-点=向量 
Vector operator - (Point A, Point B){
	return Vector(A.x - B.x, A.y - B.y);
}

//向量*数 = 向量;

Vector operator * (Vector A, double P){
	return Vector(A.x*P, A.y*P);
}	

//向量/数=向量

Vector operator / (Vector A, double P){
	return Vector(A.x/P, A.y/P);
} 

bool operator < (const Point& a, const Point& b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

//双精度数据的误差处理 
const double eps = 1e-10;

int dcmp(double x){
	if(fabs(x) < eps)
		return 0;
	else
		return x < 0 ? -1 : 1;
}

bool operator == (const Point& a, const Point& b){
	return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}

double Dot(Vector A, Vector B){
	return A.x*B.x + A.y*B.y;
}

double Length(Vector A){
	return sqrt(Dot(A,A));
}

double Angle(Vector A, Vector B){
	return acos(Dot(A,B)/(Length(A)*Length(B)));
} 

double Cross(Vector A, Vector B){
	return A.x*B.y - A.y-B.x;
}

double Area2(Point A, Point B, Point C){
	return Cross(B-A, C-A);
}

//逆时针旋转rad，rad是弧度 
Vector rotate(Vector A, double rad){
	return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}

Vector Normal(Vector A){
	double L = Length(A);
	return Vector(-A.y/L, A.x/L);
}

double DistanceToLine(Point P, Point A, Point B){
	Vector v1 = B-A, v2 = P-A;
	return fabs(Cross(A,B))/Length(v1);
}

double DistanceToSegment(Point P, Point A, Point B){
	if ( A == B)
	return Length(P-A);
	Vector v1 = B-A, v2 = P-A, v3 = P-B;
	if(dcmp(Dot(v1,v2))<=0) return Length(v2);
	else if(dcmp(Dot(v1,v3))>=0) return Length(v3);
	else return fabs(Cross(v1,v2))/Length(v1);
}

//规范相交
bool SegmentIntersection(Point a1, Point a2, Point b1, Point b2){
	double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1),
		   c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0; 
} 

bool OnSegment(Point p, Point a1, Point a2){
	return dcmp(Cross(p-a1, p-a2))==0 && dcmp(Dot(a1-p, a2-p))<0;
}


//把多边形分成n-2个三角形 
double ConvexPolygonArea(Point* p, int n){
	double area = 0;
	for(int i=1; i<n-1; i++){
		area += Cross(p[i]-p[0], p[i+1]-p[0]);
	}
	return area/2;
}

//点在多边形内的判定1:射线法 
//if语句中说明了3个条件：CONDITION1&2:线段的两个端点在射线的两端（射线上和射线上方看成同一端）;CONDITION3:线段和射线的交点在测试点的右侧（严格右侧） 
//该实现中假设有一条水平向右穿过测试点的射线 

bool IsPointInPolygon_cn(Point *Poly, Point P, int n){
	int cnt = 0;
	for(int i=0; i<n+1 ;i++){
		
		bool isRight = dcmp(((P.y-Poly[i].y)*(((Poly[(i+1)%n].x-Poly[i].x)/(Poly[(i+1)%n].y-Poly[i].y)))+Poly[i].x) - P.x);//condition3
		bool condition1 = Poly[i].y < P.y && Poly[(i+1)%n].y >= P.y;
		bool condition2 = Poly[i].y >= P.y && Poly[(i+1)%n].y < P.y;
		if((condition2||condition1) && isRight)
		{
			cnt ++;
		}
	}
	return cnt&1;
}

//点在多边形内判定2:绕数法
bool IsPointInPolygon_wn(Point *Poly, Point P, int n){
	int wn = 0;
	for(int i=0; i<n+1 ;i++){
		int k = dcmp(Cross((Poly[(i+1)%n]-Poly[i]), (Poly[i]-P)));
		int a = dcmp(Poly[(i+1)%n].y-P.y);
		int b = dcmp(Poly[i].y-P.y);
		if(k>0 && a>=0 && b<0) wn++;
		if(k<0 && a<=0 && b>0) wn--;
	}
	if(wn != 0 ) return true;
	else return false;
} 

//凸包计算
bool Pcomp(Point P1, Point P2){
	if(P1.x < P2.x)
		return true;
	else if(P1.x == P2.x)
		return P1.y < P2.y;
	else
		return false;
} 

void swap(int &a, int &b ){
	int c = a;
	a = b;
	b = c;
}

//insertion sort
void sort(int *P, int n){
	for(int i=1;i<n;i++){
		for(int j=i;j>0;j--){
		if(P[j] < P[j-1])
			swap(P[j], P[j-1]);
		}
	}
}

void Pswap(Point &a, Point &b ){
	Point c = a;
	a = b;
	b = c;
}

void Psort(Point *P, int n){
	for(int i=1;i<n;i++){
		for(int j=i;j>0;j--){
		if(Pcomp(P[j],P[j-1]))
			Pswap(P[j], P[j-1]);
		}
	}
}

void ConvecHull(Point* Poly, Point *C){
	
}

int main()
{
	//Point Poly[10];
	int N,M;
	Point P;
	Point Poly[100];
	while(cin >> N){
	for(int i=0;i<N;i++){
		cin >> Poly[i].x >> Poly[i].y;
	}
	Psort(Poly, N);
	for(int i=0;i<N;i++){
		cout << Poly[i].x <<" "<< Poly[i].y<<endl;; 
	}
	}
}
 









