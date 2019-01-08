

#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
#define max(a,b) (a<b?b:a)
#define MAXN 100002 
#define log2(x) log(x)/log(2)
#define pow2(x)  pow((double)2,x)
int cash, N;
int Dk;
int nk;
int dp[MAXN];
int w[MAXN];//v=w
int cnt;
int main() {
	while (scanf("%d %d", &cash, &N) != EOF) {
		memset(dp, 0, sizeof(dp));
		memset(w,0,sizeof(w));
		cnt = 0;
		for (int i = 0;i<N;i++) {
			cin >> nk >> Dk;
			int k;
			for(k=1;k<=nk;k<<=1){
				w[cnt++] = k*Dk;
				nk-=k;
			}
			if(nk>0)
			w[cnt++] = nk*Dk;
		}

		//dp[w[0]] = w[0];
		for (int i = 0;i<cnt;i++) {
			for (int v = cash;v >= w[i];v--) {
					dp[v] = max(dp[v], dp[v - w[i]] + w[i]);
			}
		}

		cout <<dp[cash] << endl;

	}
}

/*

735 3  4 125  6 5  3 350
633 4  500 30  6 100  1 5  0 1
735 0
0 3  10 100  10 50  10 10
*/


