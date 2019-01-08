#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 510*510
#define INF 0xfffff

int p[MAXN];

int T,n,m;

struct Edge{
	int u;
	int v;
	int w;
}edge[MAXN];

bool cmp(Edge e1, Edge e2){
	return e1.w < e2.w;
}

int find(int x){
	return x == p[x]? x : p[x]=find(p[x]);
}

int krustral(){
	int ans = 0;
	sort(edge,edge+m,cmp);
	for(int i=0;i<=n;i++) p[i] = i;
	for(int i=0;i<m;i++){
		int u = find(edge[i].u);
		int v = find(edge[i].v);
		if(u != v){
			if(ans<edge[i].w)
				ans = edge[i].w;
			p[v] = u;
		}
	}
	return ans;
}

int main(){
	scanf("%d",&T); 
	while(T--){
		scanf("%d", &n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				edge[m].u = i;
				edge[m].v = j;
				scanf("%d", &edge[m++].w);
			}
				
		int ans = krustral();
		//int ans = prime();
		cout << ans << endl;
	}
} 
