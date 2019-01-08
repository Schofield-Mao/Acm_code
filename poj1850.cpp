
#include<iostream>
#include<cstring>
using namespace std;

char str[11];
int c[27][27];
void play_table() {
	memset(c, 0, sizeof(c));
	for (int i = 1;i<27;i++) {
		for (int j = 0;j <= i;j++) {
			if (!j || i == j)
				c[i][j] = 1;
			else
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
}
int main() {
	while (cin >> str) {
		int l = strlen(str);
		long long sum = 0;

		for (int i = l - 1;i >= 1;i--) {
			if (str[i] <= str[i - 1]) {
				cout << 0 << endl;
				return 0;
			}
		}

		play_table();
		for (int i = 1;i<l;i++) {
			sum += c[26][i];
		}

		for (int i = 0;i<l;i++) {
			int ch = (!i) ? 'a' : str[i - 1] + 1;
			for (int j = ch;j<str[i];j++) {
				sum += c['z' - j][l - i - 1];
			}
		}
		cout << sum +1<< endl;

	}
}
