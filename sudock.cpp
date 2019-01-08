#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
#define SLOT 0
#define ROW 1
#define COL 2
#define SUB 3

char P[16][20];

class DLX{
public:
	#define maxn 16*16*4
    #define maxnode  16*16*16*4
	int n, sz;
	int S[maxn];
	
	int row[maxnode], col[maxnode];
	int L[maxnode], R[maxnode], U[maxnode], D[maxnode];
	
	int ansd, ans[maxn];
	
	DLX(int n){
		this->n = n;
		for(int i = 0; i <= n; i++){
			U[i] = i; D[i] = i; L[i] = i-1; R[i] = i+1;
		}
		R[n] = 0; L[0] = n;
		
		sz = n+1;
		//memset(S, 0, sizeof(S));
	}
	
	void addRow(int r, vector<int> columns){
		int first = sz;
		for( unsigned int i = 0; i < columns.size(); i++){
			int c = columns[i]; 
			L[sz] = sz - 1; R[sz] = sz + 1; D[sz] = c; U[sz] = U[c];
			D[U[c]] = sz; U[c] = sz;
			row[sz] = r; col[sz] = c;
			S[c]++; sz++;
		}
		R[sz - 1] = first; L[first] = sz - 1;
	}
	
	

	void remove(int c){
		L[R[c]] = L[c];
		R[L[c]] = R[c];
		
		for(int i=D[c];i!=c;i=D[i])
			for(int j=R[i];j!=i;j=R[j]){
				U[D[j]] = U[j]; D[U[j]] = D[j]; --S[col[j]];
			}
	}
	
	void restore(int c){
		for(int i=U[c];i!=c;i=U[i])
			for(int j=L[i];j!=i;j=L[j]){
				 ++S[col[j]]; U[D[j]] = j; D[U[j]] = j;
			}
		
		L[R[c]] = c;
		R[L[c]] = c;
	}
	
	bool dfs(int d){
		if(R[0] == 0){
			ansd = d;
			return true;
		}
		
		int c = R[0];
		for(int i=R[0];i!=0;i=R[i])
			if(S[i] < S[c]) c = i;
			
		remove(c);
		for(int i=D[c];i!=c;i=D[i]){
			ans[d] = row[i];
			for(int j=R[i];j!=i;j=R[j])
				remove(col[j]);
			if(dfs(d+1))
				return true;
			for(int j=L[i];j!=i;j=L[j])
				restore(col[j]);
		}
		restore(c);

		return false;
	}
	
	bool solver(vector<int> &v){
		v.clear();
		if(!dfs(0)) return false;
		for(int i=0;i<ansd;i++){
			v.push_back(ans[i]);
		}
		return true;
	}
	
};
int encode(int a, int b, int c){
	return 256*a+16*b+c+1;
}

void decode(int code, int &a, int &b, int &c){
	--code;
	c = code%16;
	code/=16;
	b = code%16;
	code/=16;
	a = code;
}
bool read(){
	for(int i=0;i<16;i++){
		cin >> P[i];
	}
	return true;
}
int sub(int i, int j){
	return (i/4)*4+j/4;
}
int main(){
	int r,c,v;
	DLX solver(1024);
	read();
	
	for(int r=0;r<16;r++)
		for(int c=0;c<16;c++)
			for(int v=0;v<16;v++)
			if(P[r][c] == '-' || P[r][c] == 'A'+v){
				vector<int> column;
				column.push_back(encode(SLOT,r,c));
				column.push_back(encode(ROW,r,v));
				column.push_back(encode(COL,c,v));
				column.push_back(encode(SUB,sub(r,c),v));
				solver.addRow(encode(r,c,v),column);
			}
			vector<int> answer;
			solver.solver(answer);
			int ans;
			cout <<"----------------------------"<<endl;
			int L = answer.size();
			for(int i=0;i<L;i++){
				ans = answer.back();
				answer.pop_back();
				decode(ans,r,c,v);
				P[r][c] = 'A'+v;
			}
			for(int i=0;i<16;i++){
				cout << P[i] << endl;
			}
}


