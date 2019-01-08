// ConsoleApplication12.cpp: 定义控制台应用程序的入口点。
//



#include<iostream>
#include<string.h>
#include<math.h>
#include<cstring>
#define MAXN 10000 

using namespace std;
//string dic[MAXN];
//string Query[51];
char dic[MAXN][16];
char Query[51][16];
int diN[MAXN];
int QN[MAXN];
int cor[MAXN];

bool diff1(int i, int j) {
	bool flag = false;
	int d = 0;
	int idx = 0;
	for (int k = 0;k<diN[i];k++) {
		if (Query[j][idx++] != dic[i][k]) {
			d++;
			idx--;
			if (d == 2)
				return false;
		}
	}
	return true;
}

bool diff2(int i, int j) {
	bool flag = false;
	int d = 0;
	int idx = 0;
	for (int k = 0;k<QN[j];k++) {
		if (dic[i][idx++] != Query[j][k]) {
			d++;
			idx--;
			if (d == 2)
				return false;
		}
	}
	return true;
}

int diff3(int i, int j) {
	int d = 0;
	for (int k = 0;k<diN[i];k++) {
		if (Query[j][k] != dic[i][k]) {
			d++;
			if (d == 2)
				return 0;
		}
	}
	if (d == 1)
		return 1;
	if (d == 0);
	return 3;
}
int main() {
	int i = 0;
	int j = 0;
	int counter = 0;
	int F = 0;
	cin >> dic[i];
	diN[i] = strlen(dic[i]);
	i++;
	while (dic[i - 1][0] != '#') {
		cin >> dic[i]; diN[i] = strlen(dic[i]);
		i++;
	}

	cin >> Query[j];
	QN[j] = strlen(Query[j]);
	j++;
	while (Query[j - 1][0] != '#') {
		cin >> Query[j];
		QN[j] = strlen(Query[j]);
		j++;
	}

	for (int k = 0;k<j - 1;k++) {
		cout << Query[k];
		counter = 0;
		F = 0;
		int ql = QN[k];
		for (int s = 0;s<i - 1;s++) {
			int dl = diN[s];
			if (dl - ql == 1) {
				if (diff1(s, k)) {
					//cout <<dic[s]<<" ";
					cor[counter++] = s;
				}
			}
			if (ql - dl == 1) {
				if (diff2(s, k)) {
					cor[counter++] = s;
				}
			}
			if (ql == dl) {
				F = diff3(s, k);
				if (F) {
					if (F == 3) break;
					cor[counter++] = s;
				}
			}
		}
		if (F != 3){
			cout << ":";
			for (int p = 0;p<counter;p++)
				cout <<" "<<dic[cor[p]];
		
		}
		else
			cout << " is correct";
		cout << endl;
	}
}
