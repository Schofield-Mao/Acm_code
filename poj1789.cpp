// ConsoleApplication6.cpp: 定义控制台应用程序的入口点。
//

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 2001
#define INF 0xfffff;
int n;
int w[MAXN][MAXN];
char code[MAXN][7];
bool Edge[MAXN][MAXN];

int dist(int l, int r) {
	int dis = 0;
	for (int i = 0;i<7;i++) {
		if (code[l][i] != code[r][i])
			dis++;
	}
	return dis;
}

bool isFinished(bool P[]) {
	for (int i = 0;i<n;i++) {
		if (P[i] == 0)
			return false;
	}
	return true;
}


int prim() {
	int s = 0;
	bool P[MAXN];
	memset(Edge,0,sizeof(Edge));
	memset(P, 0, sizeof(P));
	P[s] = 1;
	while (!isFinished(P)) {
		int u = 0;
		int v = 0;
		int m = INF;
		for (int i = 0;i<n;i++) {
			if (!P[i]) 
				continue;
			for (int j = 0;j<n;j++) {
				if (m > w[i][j] && !P[j] && !Edge[i][j]) {
					m = w[i][j];
					u = i;
					v = j;
				}
			}
		}

		Edge[u][v] = 1;
		P[v] = 1;
	}
	int sum = 0;
	for (int i = 0;i<n;i++)
		for (int j = 0;j<n;j++)
			if(Edge[i][j] == 1)
			sum += w[i][j];

	return sum;
}

int prime(){
	int vis[MAXN];
	int d[MAXN];
	int ans=0;
	for(int i=0;i<n;i++) d[i] = INF;
	d[0] = 0;
	memset(vis,0,sizeof(vis));
	
	for(int i=0;i<n;i++){
		int m = INF;
		int  x=-1;
		for(int j=0;j<n;j++) if(!vis[j]&&m>=d[j]) m = d[x=j];
		vis[x] = 1;ans += d[x];
		for(int j=0;j<n;j++)
		if(!vis[j])
		d[j] = min(d[j],w[x][j]);  
	} 
	return ans;	
}

int main() {
	while (cin >> n) {
		if (n == 0) break;
		for (int i = 0;i<n;i++) {
			scanf("%s", code[i]);   
		}
		//memset(w,0,sizeof(w));
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)
				w[j][i] = w[i][j] = dist(i,j);
		//cout << "The highest possible quality is 1/" << prim()<<"."<< endl;
		int ans = prime(); 
		printf("The highest possible quality is 1/%d.\n", ans);

	}

}

