
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 15005

int c, g;
int P[35];
int w[30];
int dp[21][MAXN];

int main() {
	while (cin >> c >> g) {
		memset(dp, 0, sizeof(dp));
		for (int i = 0;i<c;i++) {
			cin >> P[i];
		}
		for (int i = 0;i<g;i++) {
			cin >> w[i];
		}


		for (int j = 0;j<c;j++) {
			int temp = w[0] * P[j];
			int B = temp + 7500;
			dp[0][B] = 1 + dp[0][B];
		}


		for (int i = 1;i<g;i++) {
			for (int j = 0;j<c;j++) {
				for (int k = -7500;k<7501;k++) {
					if (dp[i - 1][k + 7500] == 0)
						continue;
					int temp = w[i] * P[j];
					int B = temp + k + 7500;
					if (B<0 || B>15000)
						break;
					else {
						dp[i][B] = dp[i - 1][k + 7500] + dp[i][B];
					}
				}
			}
		}

		cout << dp[g - 1][7500] << endl;
	}
}
