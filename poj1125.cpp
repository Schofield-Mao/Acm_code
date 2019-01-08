#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 105
#define INF 20
int n;
int d[MAXN][MAXN];
void floyd(){
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}
int main(){
	int a,b,c,t,s,sum,mini;
	while(cin >> n){
		if (n==0)
			break;
		memset(d,INF,sizeof(d));
		for(int i=0;i<=n;i++){
				d[i][i] = 0;
		}
		
		for(int i=1;i<=n;i++){
			cin >> a;
			for(int j=0;j<a;j++){
				cin >> b >> c;
				d[i][b] = c;
			}
		}
		
		floyd();
		mini = INF;
		s = 1;
		for(int i=1;i<=n;i++){
			t  = 0;
			for(int j=1;j<=n;j++){
				if(t < d[i][j])
				 t = d[i][j];
			}
				if(t < mini){
					mini = t;
					s = i;
				}
		}
		
		cout << s << " " << mini << endl;
	}
} 
