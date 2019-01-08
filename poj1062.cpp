#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
#define MAXN 105
#define INF 0xFFFFF
int n,m,p,l,x,t,v,cnt,Head[MAXN],obj[MAXN],dist[MAXN],vis[MAXN],LV[MAXN];
struct Edge{
	int u,v,w,next;	
}e[10*MAXN];

void Add(int ue, int ve, int w){
	e[cnt].u = ue;
	e[cnt].v = ve;
	e[cnt].w = w;
	e[cnt].next = Head[ue];
	Head[ue] = cnt++;
}

int Dijkatra(int s){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dist[i]=INF;
	dist[s] = obj[s];
	for(int i=1;i<=n;i++){
		int k = 0;
		int q;
		for(int j=1;j<=n;j++) if(!vis[j] && k<dist[j]) k=dist[q=j];
		vis[q]=1;
		for(int j=Head[q];j!=-1;j=e[j].next){
			bool flag = fabs(LV[e[j].v]-LV[q])<m;
			if(dist[e[j].v] > -dist[q]  + e[j].w + obj[e[j].v] && flag) {
				dist[e[j].v] = -dist[q] + e[j].w + obj[e[j].v];
			}
		}
	}
	int mini = INF;
	for(int i=1;i<n;i++)
		if(mini>dist[i]) mini = dist[i];
	return mini;
}

int main(){
	cnt = 1;
	while(cin >> m >> n){
		memset(Head,-1,sizeof(Head));
		for(int i=1;i<=n;i++){
			cin>>p>>l>>x;
			LV[i]=l;
			obj[i]=p;
			for(int j=0;j<x;j++){
				cin>>t>>v;
				Add(i,t,v);
			}
		}
		cout << Dijkatra(1) << endl;
	}
} 
