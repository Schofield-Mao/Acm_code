#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define maxn 100000
#define INF 9999999999
class Point{
public:
	int lable;
	int x;
	int y;
}P[maxn];

bool operator < (Point a, Point b){
	return a.x<b.x;	
}

double distance(int mid){
	Point *a = &P[mid-1];
	Point *b = &P[mid];
	double d = (a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y);
	d = sqrt(d);
	return 1;
}

double LPD(int l, int r){
	int mid = (l+r)/2;
	if(r-l == 2)
		return distance(r-1);
	double lmin = LPD(l,mid);
	double rmin = LPD(mid,r);
	Point temp1 = P[mid-1];
	Point temp2 = P[mid];
	double m = 0;
	if(temp1.lable*temp2.lable == 0){
		m = distance(mid);
	}else
		m = INF;
		
		return min(m,min(lmin,rmin));
}

int main(){
	int T,n;
	while(cin >> T){
		for(int i=0;i<T;i++){
			cin >> n;
			for(int i=0;i<2*n;i++){
				cin>>P[i].x>>P[i].y;
				if(i<n)
				P[i].lable = 0;
				else
				P[i].lable = 1;
			}
			sort(P,P+n);
			cout << LPD(0,n) <<endl;			
		}
	}	
}
