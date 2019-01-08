#include<iostream>
#include<map>
#include<cstring>
#include<string>
using namespace std;
char str[80];
 int main(){
 	while(cin >> str){
 		if(str[0] == '*'){
 			break;
		 }
 		int l = strlen(str);
 		if(l<=2){
 			cout <<str<<" is surprising."<<endl;
 			continue;
			 }
 		map<string,bool> flag;
 		flag.clear();
 		bool sign = true;
		 for(int d=0;d<=l-2;d++){
 			for(int i=0;i+d<l-1;i++){
 				char p[3] = {str[i],str[i+d+1],'\0'};
 				if(!flag[p]){
				 	flag[p] = true;
				 }else{
				 	sign = false;
					break;
				}
 			}
 			flag.clear();
		 }
		 if(sign)
 		cout <<str<<" is surprising."<<endl;
 		else{
 			cout <<str<<" is NOT surprising."<<endl;
		 }
	 }
 }
