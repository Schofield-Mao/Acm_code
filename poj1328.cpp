#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn  1005
#define esp 1e-6
int n,T=1;
double d;
int pow(int a, int b){
	return a*a;
}

int dc(double d){
	if(abs(d) < esp )
		return 0;
	if(d<0)
		return -1;
	if(d > 0)
		return 1;
}
	
struct point{
	double x;
	double y;	
}P[maxn],interval[maxn];

bool operator < (struct point a, struct point b){
	if(a.x < b.x)
		return true;
	else if(a.x==b.x && a.y<b.y)
		return true;
	else
		return false;	
}

int insec(double &l, double &r, int i){
	if(dc(interval[i].x-r)>0 || dc(l-interval[i].y)>0){
		l = interval[i].x;
		r = interval[i].y;
		return 0;
	}
	else if(dc(r-interval[i].x)>=0 && dc(interval[i].y-r)>=0){
		l = interval[i].x;
		return 1;
	}
	else if(dc(l-interval[i].x)>=0 && dc(interval[i].y-l)>=0){
		r = interval[i].y;
		return 2;
	}else if(dc(interval[i].x-l)>=0 && dc(r-interval[i].y)>=0){
		l = interval[i].x;
		r = interval[i].y;
		return 3;
	}
}


bool computeT(){
	if(d<=0)
		return false;
	for(int i=0;i<n;i++){
	double x = sqrt(double(pow(d,2)-pow(P[i].y,2)));
		interval[i].x = -x + P[i].x;
		interval[i].y = x + P[i].x;
		if(P[i].y > d)
			return false;
	}
	sort(interval, interval+n);
	return true;
}

int greedy(){
	int counter = 1;
	double l,r;
	l = interval[0].x;
	r = interval[0].y;
	for(int i=1;i<n;i++){
		if(!insec(l,r,i)){
			l = interval[i].x;
			r = interval[i].y;
			counter++;
		}
			
	}
	return counter;	
}


int main(){

	while(cin >> n >> d){
		if(n==0 && d ==0)
			break;
		memset(P,0,sizeof(P));
		for(int i=0;i<n;i++){
			cin >> P[i].x >> P[i].y;
		}
		//sort(P,P+n);
		if(!computeT()) cout <<"Case "<<T++<<": " <<-1<<endl;
		else cout <<"Case "<<T++<<": " <<greedy()<<endl;
	}
} 
