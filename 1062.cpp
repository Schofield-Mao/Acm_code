// ConsoleApplication3.cpp: 定义控制台应用程序的入口点。
//


#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define INF 0xfffff;
#define MAXN 105
#define mem(a) memset(a,0,sizeof(a))
#define min(a,b) a<b?a:b
int graph[MAXN][MAXN], level[MAXN], d[MAXN], vis[MAXN];
int m, n;
void init() {
	mem(vis);
	mem(level);
	for (int i = 0;i <= n;i++) {
		for (int j = 0;j <= n;j++) {
			graph[i][j] = INF;
		}
	}
}

int Dijkatra() {
	
	for (int i = 1;i <= n;i++)
		d[i] = graph[0][i];

	for (int i = 1;i <= n;i++) {
		int temp = INF;
		int q;
		for (int j = 1;j <= n;j++) {
			if (!vis[j] && temp>=d[j])
				temp = d[q = j];
		}
		vis[q] = 1;
		for (int y = 1;y <= n;y++) {
			if (d[y] > d[q] + graph[q][y] && !vis[y]) {
				d[y] = d[q] + graph[q][y];
			}
		}

	}
	return d[1];
}

int main() {
	while (cin >> m >> n) {
		init();
		int p, l, x, t, v, ans;
		ans = INF;
		for (int i = 1;i <= n;i++) {
			cin >> p >> l >> x;
			for (int j = 0;j<x;j++) {
				cin >> t >> v;
				graph[t][i] = v;
			}
			graph[0][i] = p;
			level[i] = l;
		}
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (level[i]>level[j] || level[j] - level[i] > m)
					vis[j] = 1;
				else
					vis[j] = 0;
			}
			int now = Dijkatra();
			ans = min(ans, now);
		}
		cout << ans << endl;
	}
}
