#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define MAXN 110
double cost[MAXN][MAXN];
double rate[MAXN][MAXN];
int N,M,S;
double V;
bool spfa(int s){
	queue<int> Q;
	Q.push(s);
	double d[MAXN];
	int visit[MAXN];
	int now;
	double temp;
	memset(d,0,sizeof(d));
	memset(visit,0,sizeof(visit));
	d[s] = V; visit[s] = 1;
	while(!Q.empty()){
		now = Q.front();Q.pop();visit[now] = 0;
		for(int i=0;i<=N;i++){
			temp = (d[now]-cost[now][i])*rate[now][i];
				if(d[i] < temp){
					d[i] =  temp;
					if(d[s]>V) return true;
					if(visit[i] == 0){
						Q.push(i);
						visit[i] = 1;
					} 
				}
		}
	}
	return false;	
}



int main(){
	int a,b;
	double rab,rba,cab,cba;
	while(cin >>N>> M>>S>>V){
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++){
			if(i == j)
				rate[i][j] = 1;
			else
				rate[i][j] = 0;
			cost[i][j] = 0;
		}	
		for(int i=0;i<M;i++){
			cin >> a >> b >> rab >> cab >> rba >> cba;
			rate[a][b] = rab;
			rate[b][a] = rba;
			cost[a][b] = cab;
			cost[b][a] = cba;
		}
		if(spfa(S))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;			
	} 
} 
