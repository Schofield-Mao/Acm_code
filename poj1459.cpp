#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define MAXN 105
#define INF 0xffffff

int n,sn,tn,en;
int C[MAXN][MAXN];
int S[MAXN];
int T[MAXN];
int F[MAXN][MAXN];
int pre[MAXN];
int a[MAXN];


void Canaugment(){
	memset( pre,0,sizeof(pre));
	memset( a,0,sizeof(a));
	queue<int> Q;
	Q.push(0);
	a[0] = INF;
	while(!Q.empty()){
		int temp = Q.front();
		Q.pop();
		for(int i=0;i<=n+1;i++){
			if(C[temp][i]-F[temp][i]>0 && !a[i]){
				pre[i] = temp;
				Q.push(i);
				a[i] = min(C[temp][i]-F[temp][i], a[temp]);
			}
		}	
	}	
}

int algorithm(){
	int mFlow = 0;
	Canaugment();
	while(a[n+1] != 0){
		for(int i=n+1;i!=0;i=pre[i]){
			F[pre[i]][i] += a[n+1];
			F[i][pre[i]] -= a[n+1];
		}
		mFlow += a[n+1];
		Canaugment();
	}	
	return mFlow;
}

int main(){
	while(cin>>n){
		cin>>sn>>tn>>en;
		int a,b,c;
		memset( F,0,sizeof(F));
		memset( C,0,sizeof(C));
		for(int i=0;i<en;i++){
			scanf(" (%d,%d)%d",&a,&b,&c);
			C[a+1][b+1] += c;
		}
		
		for(int i=0;i<sn;i++){
			scanf(" (%d)%d", &a,&b);
			C[0][a+1] += b; 
		}
		
		for(int i=0;i<tn;i++){
			scanf(" (%d)%d", &a,&b);
			C[a+1][n+1] += b;
		}
		
		int ans = algorithm();
		cout << ans << endl;
		
	}	
} 
