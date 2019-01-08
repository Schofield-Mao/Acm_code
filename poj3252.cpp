#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
#define MAXN 200000
int N1[MAXN];
int N0[MAXN];
int order;
int convert(int t){
	int res;
	int i = 0;
	while(t!=0){
		res = res + t%2*pow((double)10,i++);
		t=t/2;
	}
	order = i-1;
	return res;	
}

int reconvert(int t){
	int ans = 0;
	int i = 0;
	while(t != 0){
		ans += t%10 * pow((double)2,i++);
		t = t / 10; 
	}
	return ans;
}
bool isRound(int i){
	int j = 0;
	j = convert(i);
	j = j%1;
	int res;
	if(i == 0)
		return true;
		
	while(i != 0){
		res = i%10;
		i = i/10;
		if(res == 1){
		
		}else if(res == 0){

		}
	}
	if(N0 >= N1 ){
		return true;
	}else{
		return false;
	}	
}

int main(){
	int s,f;
		cin >> s >> f;
		int count = 0;
		int j;
		memset(N1,0,sizeof(N1));
		memset(N0,0,sizeof(N0));
		for(int i=s;i <= f;i++){
			j = convert(i);
			cout << j << endl;
			cout  << j% (int)pow((double)10,order)<<endl;
		//	cout << i <<" " << j << endl;
		//cout <<j << endl;
		//cout << count << endl;
		//	if(isRound(j)){
		//		count ++;
		//	}
		}
		cout << count << endl;
	
} 
