#include<iostream>
using namespace std;

void getFail(string pattern, int *fail){
	fail[0] = 0;
	fail[1] = 0;
	int l = pattern.length();
	int j;
	for(int i=1;i<l;i++){
		j = fail[i];
		while(j && pattern[i]!=pattern[j])
			j = fail[j];
		fail[i+1] = pattern[i] == pattern[j] ? j+1:0;
	}
}

int kmp(int *fail, string str, string pattern){
	getFail(pattern,fail);
	int j = 0;
	int l = str.length();
	int m = pattern.length();
	for(int i=0;i<l;i++){
		while(j&&str[i]!=pattern[j]) j = fail[j];
		if(str[i] == pattern[j])j++;
		if(j == m)
			return i-m+1;
	}
	return 0;
}

int main(){
	int fail[100];
	string str;
	string pattern;
	int p = 0;
	while(cin >> str>>pattern){
		//getFail(pattern, fail);
		p = kmp(fail,str,pattern);
		cout <<p<<endl;
	}
} 
