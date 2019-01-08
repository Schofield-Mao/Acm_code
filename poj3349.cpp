
#include<iostream>
#include<cstring>
using namespace std;
#define prime 99991
#define MAXN 100001
int Htable[MAXN][10];
struct node {
	int No;
	int p[6];
}Node[MAXN];

bool check(node N1, node N2) {
	int i = 0;
	int j;
	int t;
	for (j = 0;j<6;j++) {
		if (N2.p[j] == N1.p[i]) {
			break;
		}
		if (j == 5) {
			return false;
		}
	}
	t = j;
	for (int k = 0;k<5;k++) {
		if (N1.p[i % 6] == N2.p[j % 6] && N1.p[(i + 1) % 6] == N2.p[(j + 1) % 6] && N1.p[(i + 2) % 6] == N2.p[(j + 2) % 6] &&
			N1.p[(i + 3) % 6] == N2.p[(j + 3) % 6] && N1.p[(i + 4) % 6] == N2.p[(j + 4) % 6] && N1.p[(i + 5) % 6] == N2.p[(j + 5) % 6]) {
			return true;
		}
		j++;
	}
	j = t;
	for (int k = 0;k<5;k++) {
		if (N1.p[i % 6] == N2.p[j % 6] && N1.p[(i + 1) % 6] == N2.p[(j + 5) % 6] && N1.p[(i + 2) % 6] == N2.p[(j + 4) % 6] &&
			N1.p[(i + 3) % 6] == N2.p[(j + 3) % 6] && N1.p[(i + 4) % 6] == N2.p[(j + 2) % 6] && N1.p[(i + 5) % 6] == N2.p[(j + 1) % 6]) {
			return true;
		}
		j++;
	}
	return false;
}


bool Hash(node s) {
	int sum = 0;
	for (int i = 0;i<6;i++) {
		sum += s.p[i];
	}
	for (int i = 0;i<10;i++) {
		if (Htable[sum%prime][i] == 0) {
			Htable[sum%prime][i] = s.No;
			break;
		}
		else {
			if (check(Node[Htable[sum%prime][i]], s))
				return true;
		}
	}
	return false;
}



int main() {
	int n;
	bool flag;
	cin >> n;
		flag = false;
		//memset(Htable, 0, sizeof(Htable));
		for (int i = 1;i <= n;i++) {
			Node[i].No = i;
			for (int j = 0;j<6;j++) {
				//cin >> 把Cin改成scanf就能过了 
				scanf("%d",&Node[i].p[j]);
			}
			if (flag == false) {
				if (Hash(Node[i])) {
					flag = true;
				}
			}
		}
		if (flag) {
			//cout << check(Node[1], Node[2]);
			cout <<"Twin snowflakes found."<<endl;
		}
		else {
			//cout << check(Node[1], Node[2]);
			cout << "No two snowflakes are alike."<<endl;
		}

}
/*
2
1 2 3 4 5 6
4 3 2 1 6 5
*/


