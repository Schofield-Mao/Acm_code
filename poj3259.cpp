#include"stdafx.h"
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

#define MAXN 5500
#define INF 99999999999
int cnt, Head[MAXN], num[MAXN], dist[MAXN], vis[ MAXN ];
int n, m, w;
struct Edge {
	int v;
	int w;
	int next;
}e[MAXN];

void Add(int u, int v, int w) {
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = Head[u];
	Head[u] = cnt++;
}

bool bellman_ford(int s) {
	memset(vis, 0, sizeof(vis));
	memset(num, 0, sizeof(num));
	queue<int> Q;
	Q.push(s);
	dist[s] = 0; vis[s] = 1;num[s] = 1;
	while (!Q.empty()) {
		int p = Q.front();Q.pop();vis[p] = 0;
		for (int i = Head[p] ;i != -1;i = e[i].next) {
			int q = e[i].v;
			if (dist[q] > dist[p] + e[i].w) {
				dist[q] = dist[p] + e[i].w;
				if (!vis[q]) {
					Q.push(q);
					vis[q] = 1;
					num[q]++;
					//cout << "log" << endl;
					if (num[q] > n)
						return true;	
				}
			}
		}
	}
	return false;
}

int main() {
	int T, a, b, c;
	while (cin >> T) {
		
		while(T--){
			memset(Head, -1, sizeof(Head));
			cnt = 0;
			cin >> n >> m >> w;
			for (int i = 1;i <= n;i++)
				dist[i] = INF;
			for (int j = 1;j<=m;j++) {
				cin >> a >> b >> c;
				Add(a, b, c);
				Add(b, a, c);
			}

			for (int j = 1;j<=w;j++) {
				cin >> a >> b >>c;
				Add(a, b, -c);
			}
			
			if (bellman_ford(1)) {
				cout << "YES" << endl;
			}
			else
				cout << "NO" << endl;
			
		}

	}
}
