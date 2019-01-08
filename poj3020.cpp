// ConsoleApplication10.cpp: 定义控制台应用程序的入口点。
//




#include<iostream>
#include<cstring>
using namespace std;
#define H 41
#define W 11
#define MAXN 500
int row[4]={0,0,-1,1};
int col[4]={-1,1,0,0};

bool G[MAXN][MAXN];
int m,v1,v2;
bool vis[MAXN];
int link[MAXN];
char map[41][11];




bool find(int x) {
	int j;
    for(j=1;j<=v2;j++)
    {
        if(G[x][j] && !vis[j])
        {
            vis[j]=true;
            if(link[j]==0 || find(link[j]))
            {
                link[j]=x;
                return true;
            }
        }
    }
    return false;
}



int main() {
	int n;
	int i,j,k;
    int r,c;
    int cnt;
    int result;
    char ch;
	cin >> n;
	while (n--) {
		result = 0;
		memset(link, 0, sizeof(link));
		memset(G, 0, sizeof(G));
		memset(map,0,sizeof(map));
		//cin >> h >> w;
		m = 1;
		char ch;

		int m = 1;
	scanf("%d%d",&r,&c);
        getchar();  //oooo!!!
		for (int i = 0;i<r;i++) {
			for (int j = 0;j<c;j++) {
				cin >> ch;
				if (ch == '*') {
					map[i][j] = m++;
				}
			}
		}
        v1 = v2 = m-1;
		
		for(i=0;i<r;i++)
		 for(j=0;j<c;j++)
                if(map[i][j]>0)
                {
                    int t1=map[i][j];
                    for(int k=0;k<4;k++)
                        if(i+row[k]<=40 && i+row[k]>=0 && j+col[k]>=0 && j+col[k]<=10 && map[i+row[k]][j+col[k]]>0)//注意范围的控制
                        {
                            int t2=map[i+row[k]][j+col[k]];
                            G[t1][t2]=true;
                        }
                }
		
		for(i=1;i<=v1;i++)
        {
            memset(vis,false,sizeof(vis));
            if(find(i))
                result++;
        }
		
		printf("%d\n",v1-result/2);
	}
}


/*
2
7 9
ooo**oooo
**oo*ooo*
o*oo**o**
ooooooooo
*******oo
o*o*oo*oo
*******oo

*/

