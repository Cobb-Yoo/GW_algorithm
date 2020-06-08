#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> w;
vector<int> p;
vector<float> fw;
vector<float> fp;
int n,m;

int dp[100][100];
float dp3[100];

void init(){
	w.push_back(0);
	p.push_back(0);
	w_3.push_back(0);
	p_3.push_back(0);
	float tmp;
	for(int i=0;i<n;i++){
		cin >> tmp;
		w.push_back(tmp);
		w_3.push_back(tmp);
	}
	for(int i=0;i<n;i++){
		cin >> tmp;
		p.push_back(tmp);
		p_3.push_back(tmp);
	}
}

void dp_1(){
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j < w[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+p[i]);
		}
	}
	
	cout << dp[n][m] << endl;
}

int dp_2_f(int a, int b){
	if(a == 1){
		if(w[a] <= b) {
			dp[a][b] = p[1];
			return p[1];
		}
		else if(0 <= b) return 0;
		else return -p[2];
	}
	else if(b < 0) return -p[a+1];
	
	return dp[a][b] = max(dp_2_f(a-1,b),dp_2_f(a-1,b-w[a])+p[a]);
}

void dp_2(){
	memset(dp,0,sizeof(dp));
	
	cout << dp_2_f(n,m) << endl;
}

void dp_3(){
	vector<float> dp_w(n, 0);
	vector<float> dp_p(n, 0);
	
	vector<float> tmp;
	for(int i=0;i<=n;i++)tmp.push_back(0);
	
	
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++){
			tmp[j] = dp_w[j] + fp[i];
		}
		
		for(int j=i;j<=n;j++){
			dp_w[i] = tmp[i];
		}
	}
}

int main(){	
	cin >> n >> m;
	
	init();
	
	dp_1();	
	dp_2();
	dp_3();
}

