
#include<iomanip>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 10005
int t, n, m;
int P[105];
int B[105];
int dp[105][10005];
int M1;
int M;

int main() {
	cin >> t;
	while (t--) {
		M = 0;
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 0;i<n;i++) {
			cin >> m;
			for (int j = 0;j<m;j++) {
				cin >> B[j] >> P[j];
				M = M<B[j] ? B[j] : M;
			}
			
			if (i == 0) {
				for (int j = 0;j<m;j++) {
					dp[i][B[j]] = P[j];
				}
				continue;
			}
			for (int j = 0;j<m;j++) {
				for (int k = 0;k <= M;k++) {
					if (dp[i - 1][k] == 0)
						continue;
					if (k<B[j]) {
						if (dp[i][k] == 0)
							dp[i][k] = dp[i - 1][k] + P[j];
						else
						dp[i][k] = min(dp[i][k], dp[i - 1][k] + P[j]);
					}
					else {
						if (dp[i][B[j]] == 0 )
							dp[i][B[j]] = dp[i - 1][k] + P[j];
						else
						dp[i][B[j]] = min(dp[i][B[j]], dp[i - 1][k] + P[j]);
					}
				}
			}
		}
		double ans = 0;
		for (int i = 0;i <= M;i++) {
			if (dp[n - 1][i] != 0) {
				double temp = i*1.0 / (double)dp[n - 1][i];
				ans = (ans < temp) ? temp : ans;
			}
		}
		cout <<setprecision(3)<<fixed<< ans << endl;
	}
}

