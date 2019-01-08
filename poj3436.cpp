
#include<iomanip>
#include<iostream>
#include<math.h>
#include<cstring>
#include<queue>
using namespace std;

int p, n, a;
int in[52][10];
int out[52][10];
int w[52];
int r[102][102]; //残留网络，初始化为原图
const int inf = 0x7fffffff;
bool visit[150];
int pre[150];
int T[200][3];
int Flist[52];
int root;
void buildG() {
	memset(r, 0, sizeof(r));
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			bool flag = true;
			for (int k = 0;k<p;k++) {
				if (out[i][k] != in[j][k] && in[j][k] != 2) {
					flag = false;
					break;
				}
			}
			if (flag) {
				r[i +n][j] = inf;
			}
		}
	}
	root = 0;
	for (int i = 1;i <= n;i++) {
			bool flag = true;
			for (int k = 0;k<p;k++) {
				if (in[i][k] == 1) {
					flag = false;
					break;
				}
			}
			if (flag) {
				r[0][i] = inf;
				Flist[root++] = i;
			}
		
	}
	for (int i = 1;i <= n;i++) {
		bool flag = true;
		for (int k = 0;k<p;k++) {
			if (out[i][k] != 1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			r[i+n][2*n+1] = inf;
		}

	}
	for (int i = 1;i <= n;i++) {

		r[i][i+n] = w[i];
	}

}
bool bfs(int s, int t)  //寻找一条从s到t的增广路，若找到返回true
{
	int p;
	queue<int > q;
	memset(pre, -1, sizeof(pre));
	memset(visit, false, sizeof(visit));
	pre[s] = s;
	visit[s] = true;
	q.push(s);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		for (int i = s;i <= t;i++)
		{
			if (r[p][i]>0 && !visit[i])
			{
				pre[i] = p;
				visit[i] = true;
				if (i == t) return true;
				q.push(i);
			}
		}
	}
	return false;
}
int EdmondsKarp(int s, int t)
{
	int flow = 0, d, i;
	while (bfs(s, t))
	{
		d = inf;
		for (i = t;i != s;i = pre[i])
			d = d<r[pre[i]][i] ? d : r[pre[i]][i];
		for (i = t;i != s;i = pre[i])
		{
			r[pre[i]][i] -= d;
			r[i][pre[i]] += d;
		}
		flow += d;
	}
	return flow;
}


int main() {
	while (cin >> p >> n) {
		for (int i = 1;i <= n;i++) {
			cin >> w[i];
			for (int j = 0;j < p;j++) {
				cin >> in[i][j];
			}
			for (int j = 0;j < p;j++) {
				cin >> out[i][j];
			}
		}

		w[0] = w[n + 1] = inf;
		for (int i = 0;i < 10;i++) {
			in[0][i] = 4;
			out[0][i] = 0;
			in[n + 1][i] = 1;
			out[n + 1][i] = 4;
		}
		buildG();
		


		int ans = EdmondsKarp(0, 2 * n + 1);

		int c = 0;

		//memset(T, 0, sizeof(T));
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				bool flag = true;
				for (int k = 0;k < p;k++) {
					if (out[i][k] != in[j][k] && in[j][k] != 2) {
						flag = false;
						break;
					}
				}
				if (flag) {
					//r[i + n][j] = inf;
					if (inf - r[i + n][j] > 0) {
						T[c][0] = i;
						T[c][1] = j;
						T[c++][2] = inf - r[i + n][j];
					}
				}
			}
		}
		if (c != 0) {
		cout << ans << " " << c<< endl;
		//dfs();
		for (int i = 0;i < c;i++) {
			cout << T[i][0] << " " << T[i][1] << " " << T[i][2] << endl;
		}
	}
		else {
			cout << ans << " " << 0 << endl;
		}
		
	}

}

/*
Sample input 1
3 4
15  0 0 0  0 1 0
10  0 0 0  0 1 1
30  0 1 2  1 1 1
3   0 2 1  1 1 1
Sample input 2
3 5
5   0 0 0  0 1 0
100 0 1 0  1 0 1
3   0 1 0  1 1 0
1   1 0 1  1 1 0
300 1 1 2  1 1 1
Sample input 3
2 2
100  0 0  1 0
200  0 1  1 1

Sample output 1
25 2
1 3 15
2 3 10
Sample output 2
4 5
1 3 3
3 5 3
1 2 1
2 4 1
4 5 1
Sample output 3
0 0

int vis[100];
memset(vis, 0, sizeof(vis));
for (int i = 0;i < root+1;i++) {
for (int j = i;j < c-1;j++) {
int cur;
if (j == i || (T[j][0] == T[cur][1]&&!vis[j])) {
cout << T[j][0] << " " << T[j][1] << " " << T[j][2] << endl;
cur = j;
vis[j] = 1;
}
}
}
*/
