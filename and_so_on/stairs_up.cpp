#include <iostream>
#include <string>
using namespace std;

void right(int n, int cnt, string line);

void left(int n,int cnt, int stairs, string line){
	if(n < cnt) {
		
		return;
	}
	else if(n == cnt){
		line += "L"+to_string(stairs);
		cout << line << endl;
		return;
	}else{
		line += "L"+to_string(stairs)+" ";
	}
	
	right(n,cnt+1,line);
}

void right(int n, int cnt, string line){
	if(n < cnt) return;
	else if(n == cnt){
		line += "R1";
		cout << line << endl;
		return;
	}else{
		line += "R1 ";
	}
	
	for(int i=1;i<=3;i++){
		left(n,cnt+i,i,line);
	}
}

int main(){
	int n;
	cin >> n;
	
	for(int i=1;i<=3;i++){
		left(n,i,i,"");
	}
	right(n,1,"");
}
