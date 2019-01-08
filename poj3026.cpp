// ConsoleApplication8.cpp: 定义控制台应用程序的入口点。
//

#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>

#include<queue>
#define MAXN 150
int n, w, h, k, m;
char maze[60][60];
int G[60][60];
int pa[MAXN];
int direction[4][2] = { { 0,1 },{ 1,0 },{ -1,0 },{ 0,-1 } };
void init(){
	memset(maze,0,sizeof(maze));
	memset(G,0,sizeof(G));
	memset(pa,0,sizeof(pa)); 
	m=0;
	k=0;
}
using namespace std;
class Point {
public:
	Point() {
		x = 0;
		y = 0;
		dist = 0;
		num = 0;
	}
	int x, y, dist, num;
}P[MAXN];

class Edge {
public:
	Edge() {
		u = 0;
		v = 0;
		w = 0;
	}
	int u, v, w;
}edge[MAXN*MAXN];

void bfs(Point s) {
	bool vis[MAXN][MAXN];
	memset(vis, 0, sizeof(vis));
	queue<Point> Q;
	Q.push(s);
	vis[s.y][s.x] = 1;
	while (!Q.empty()) {
		Point temp = Q.front();Q.pop();
		Point temp2;

		for (int i = 0;i<4;i++) {
			temp2.x = temp.x + direction[i][0];
			temp2.y = temp.y + direction[i][1];
			temp2.num = G[temp2.y][temp2.x] - 1;
			if (temp2.x < 0 || temp2.y < 0 || temp2.x > w || temp2.y > h || vis[temp2.y][temp2.x] == 1)
				continue;
			vis[temp2.y][temp2.x] = 1;
			if (G[temp2.y][temp2.x] == -1)
				continue;
			else if (G[temp2.y][temp2.x] > 0) {
				edge[k].u = s.num;
				edge[k].v = temp2.num;
				temp2.dist = temp.dist + 1;
				edge[k++].w = temp2.dist;
				Q.push(temp2);
				continue;
			}
			else if (G[temp2.y][temp2.x] == 0) {
				temp2.dist = temp.dist + 1;
				Q.push(temp2);
			}
		}
	}
}
bool cmp(Edge &a, Edge &b) {
	return a.w < b.w;
}
int find(int x) {
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}
int kruskal() {
	sort(edge, edge + k, cmp);
	for (int i = 0;i <= m;i++)
		pa[i] = i;
	int ans = 0;
	for (int i = 0;i<k;i++) {
		int u = find(edge[i].u);
		int v = find(edge[i].v);
		if (u != v) {
			ans += edge[i].w;
			pa[v] = u;
		}
	}
	return ans;
}

int main() {
	cin >> n;
	char fake[60];
	while (n--) {
		init();
		cin >> w >> h;
		gets(fake);
		for (int i = 0;i<h;i++) {
			//gets(maze[i]);
			for (int j = 0;j<w;j++) {
				scanf("%c", &maze[i][j]);
				if (maze[i][j] == 'A' || maze[i][j] == 'S') {
					Point temp1;
					temp1.x = j;
					temp1.y = i;
					temp1.num = m;
					P[m++] = temp1;
					G[i][j] = m;
				}
				else if (maze[i][j] == '#')
					G[i][j] = -1;
				else if (maze[i][j] == ' ')
					G[i][j] = 0;
			}
			getchar();
		}
		for (int i = 0;i<m;i++) {
			bfs(P[i]);
		}
		int answer = kruskal();
		cout << answer << endl;
	}
}

