#include <iostream>
#include <string>
using namespace std;

void right(int n, int cnt, string line);

void left(int n,int cnt, int stairs, string line){
	if(n < cnt) {
		
		return;
	}
	else if(n == cnt){
		line += to_string(stairs)+"L";
		cout << line << endl;
		return;
	}else{
		line += to_string(stairs)+"L"+", ";
	}
	
	right(n,cnt+1,line);
}

void right(int n, int cnt, string line){
	if(n < cnt) return;
	else if(n == cnt){
		line += "1R";
		cout << line << endl;
		return;
	}else{
		line += "1R, ";
	}
	
	for(int i=3;i>=1;i--){
		left(n,cnt+i,i,line);
	}
}

int main(){
	int n;
	cout << "How many step do you want: ";
	cin >> n;
	
	for(int i=3;i>=1;i--){
		left(n,i,i,"");
	}
	right(n,1,"");
}
