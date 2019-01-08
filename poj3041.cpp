#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 501
int n,k;
int v1,v2;
int G[MAXN][MAXN];
int vis[MAXN];
int link[MAXN];

bool dfs(int x){
	for(int y=1;y<=v2;y++){
		if(G[x][y] && !vis[y]){
			vis[y]=1;
			if(link[y]==0||dfs(link[y])){
				link[y]=x;
				return true;
			}	
		}
	}
	return false;
}

//algorithm
int search(){
	int result = 0;
	for(int x=1;x<=v1;x++){
		memset(vis,0,sizeof(vis));
		if(dfs(x))
			result++;
	}
	return result;
}

int main(){
	cin >> n >> k;
	{
			v1 = n, v2 = n;
			int x,y;
			memset(G,0,sizeof(G));
		for(int i=0;i<k;i++){
			cin >> x >> y;
			G[x][y] = 1;			
		}
				
		int ans = search();
		cout << ans << endl;		
	}
} 
