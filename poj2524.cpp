#include<iostream>
#include<cstring>
using namespace std;
#define maxn 50005
int set[maxn];

int find(int b){
	return b == set[b]? b:set[b] = find(set[b]);
}

void swap(int &a, int &b){
	if(a>b){
		int c= a;
		a = b;
		b = c;
	}
}

int main(){
	int n,m,a,b,counter;
	int T=1;
	while(cin >> n >> m){
		if(n==0 && m==0)
			break;
			
		memset(set, 0, sizeof(set));
			for(int i=1;i<n+1;i++){
				set[i]=i;
			}
			
		for(int i=0;i<m;i++){
			cin >> a >> b;
			//scanf("%d%d",a,b);
			
			a = find(a);
			b = find(b);
			swap(a,b);
			set[b] = a;
		}
		
		counter = 0;
		for(int i=1;i<n+1;i++){
			if(set[i] == i)
			counter++;	
		}
		cout <<"Case "<<T++<<": "<< counter<<endl;
		
	}	
	
	return 0;
} 
