// ConsoleApplication9.cpp: 定义控制台应用程序的入口点。
//




#include<iostream>
#include<cstring>

using namespace std;
#define MAXN 30
int n, m;
char str[3];
bool T[MAXN][MAXN];
int indegreen[MAXN], indegreen2[MAXN], order[MAXN];

void init() {
	memset(indegreen, 0, sizeof(indegreen));
	memset(indegreen2, 0, sizeof(indegreen2));
	memset(order, 0, sizeof(order));
	memset(T, 0, sizeof(T));
}
bool floyd() {
	bool fake[MAXN][MAXN];
	memset(fake, 0, sizeof(fake));
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			fake[i][j] = T[i][j];

	for (int k = 0;k <= n;k++)
		for (int i = 0;i <= n;i++)
			for (int j = 0;j <= n;j++)
				fake[i][j] = fake[i][j] || (fake[i][k] && fake[k][j]);

	for (int i = 0;i <= n;i++)
		if (fake[i][i] == 1)
			return false;

	return true;
}

bool isDetermined() {
	int cnt = 0;
	for (int i = 0;i<n;i++) {
		if (indegreen2[i] == 0)
			cnt++;
	}
	if (cnt == 1)
		return true;
	else if (cnt > 1)
		return false;
}

bool Tsort() {
	int cnt = 0;
	if (!isDetermined())
		return false;
	int cur = 0;
	for (int i = 0;i<n;i++) {
		if (!isDetermined())
			return false;
		for (int j = 0;j<n;j++) {
			if (indegreen2[j] == 0) {
				cur = j;
				indegreen2[j]--;
				order[cnt++] = j;
				break;
			}
		}
		for (int j = 0;j<n;j++) {
			if (T[cur][j]) {
				indegreen2[j]--;
			}
		}
	}
	return true;
}

int main() {
	while (cin >> n) {
		init();
		cin >> m;
		if (n == 0 && m == 0)
			break;
		memset(T, 0, sizeof(T));
		int i;
		for (i = 0;i<m;i++) {
			cin >> str;
			if (T[str[0] - 'A'][str[2] - 'A'] == 0) {
				T[str[0] - 'A'][str[2] - 'A'] = 1;
				indegreen[str[2] - 'A']++;
			}
			if (!floyd()) {
				cout << "Inconsistency found after " << i + 1 << " relations." << endl;
				i++;
				for (i;i < m;i++)
					cin >> str;
				break;
			}
			memcpy(indegreen2, indegreen, sizeof(indegreen));
			if (Tsort()) {
				cout << "Sorted sequence determined after "<<i+1<<" relations: ";
				for (int j = 0;j < n;j++) {
					cout << (char)(order[j] + 'A');
				}
				cout <<"."<< endl;
				i++;
				for (i;i < m;i++) 
					cin >> str;
				break;
			}
			else if (i == m - 1) {
				cout << "Sorted sequence cannot be determined." << endl;
			}
		}
	}
}
