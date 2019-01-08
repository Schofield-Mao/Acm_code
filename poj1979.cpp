#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string map[21];
int visit[21][21];
int w,h,x,y;
void find(){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(map[i][j] == '@'){
				x=j;y=i;
				visit[y][x] = 1;
				break;
			}
		}
	}	
}

void dfs(int currx, int curry, int &count){
	for(int i=0;i<4;i++){
		switch(i){
			case 0:
				if(currx+1<h && visit[currx+1][curry]==0 && map[currx+1][curry] == '.'){
					count++;
					visit[currx+1][curry]=1;
					dfs(currx+1, curry, count); 
				}
				break;
				
			case 1:
				if(currx-1>=0 && visit[currx-1][curry]==0 && map[currx-1][curry] == '.'){
					count++;
					visit[currx-1][curry]=1;
					dfs(currx-1, curry, count);
				}
				break;
				
			case 2:
				if(curry+1<w && visit[currx][curry+1]==0 && map[currx][curry+1] == '.'){
					count++;
					visit[currx][curry+1]=1;
					dfs(currx, curry+1, count);
				}
				break;
				
			case 3:
				if(curry-1>=0 && visit[currx][curry-1]==0 && map[currx][curry-1] == '.'){
					count++;
					visit[currx][curry-1]=1;
					dfs(currx, curry-1, count);
				}
				break;
				
				default:
					break;
		}
	}
}
int main(){
	while(cin >> w >> h){
		if(w == 0 && h==0)
			break;
		memset(visit, 0, sizeof(visit));
		for(int i=0;i<h;i++){
			cin >> map[i];
		}
		find();
		int ans = 1;
		dfs(y,x, ans);
		cout << ans << endl;
	}
} 
