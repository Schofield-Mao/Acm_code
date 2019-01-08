
#include<iostream>
#include<cstring>
using namespace std;
int c[40][40];
int bi[40];
int coun;
void init() {
	memset(c, 0, sizeof(c));
	//C(n+1,i)=C(n,i)+C(n,i-1)
	c[0][0] = 1;
	for (int i = 1;i<40;i++) {
		c[i][0] = 1;
		c[i][i] = 1;
		for (int j = 1;j <= i;j++) {
			c[i + 1][j] = c[i][j - 1] + c[i][j];
		}
	}
}

void convert(int i) {
	coun = 0;
	while (i != 0) {
		bi[coun++] = i & 1;
		i = i >> 1;
	}
}
//1110
int cal(int n) {
	int sum = 0;
	convert(n);
	for (int i = coun - 2;i >= 1;i--) {
		for (int j = i / 2 + 1;j <= i;j++) {
			sum += c[i][j];
		}
	}
	int N1 = 1;
	int N0 = 0;
	for (int i = coun - 2;i >= 0;i--) {
		if (bi[i] == 1) {
			N1++;
			for (int j = i;j + N0 + 1 >= N1 - 1 + i - j;j--) {
				sum += c[i][j];
			}
		}
		else
		{
			N0++;
		}
	}
	return sum;
}
int main() {
	int n, m, ans;
	init();
	while (cin >> n >> m) {
		ans = cal(m+1) - cal(n);
		cout << ans << endl;
	}
}

