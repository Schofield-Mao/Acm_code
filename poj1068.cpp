// ConsoleApplication12.cpp: 定义控制台应用程序的入口点。
//



#include<iostream>
using namespace std;
#define MAXN 1000
int n, t;
int P[MAXN];
int W[MAXN];
char str[MAXN];
int idx;

void print() {
	str[0] = 'S';
	idx = 1;
	int j = 1;
	for (int i = 1;i <= t;i++) {
		for (j;j < P[i] + 1;j++) {
			str[idx++] = '(';
		}
		str[idx++] = ')';
	}
	//cout << str << endl;
}

void ans() {
	int r;
	int counter;
	bool flag = true;
	for (int i = 1;i <= t;i++) {
		for (int k = 1;k < idx;k++) {
			if (str[k] == ')') {
				counter = 1;
				for (int j = k-1;j >= 0;j--) {
					if (str[j] == '(') {
							cout << counter;
							if (i != t)
								cout << " ";
							str[j] = '0';
							break;
					}
					else if(str[j] == ')'){
						counter++;
					}
				}
			}
		}

	}
}

int main() {
	cin >> n;
	while (n--) {
		cin >> t;
		for (int i = 1;i <= t;i++) {
			cin >> P[i];
		}
		print();
		ans();
		cout << endl;
	}
}
