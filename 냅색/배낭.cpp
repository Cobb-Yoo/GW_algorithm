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
	fw.push_back(0);
	fp.push_back(0);
	float tmp;
	for(int i=0;i<n;i++){
		cin >> tmp;
		w.push_back(tmp);
		fw.push_back(tmp);
	}
	for(int i=0;i<n;i++){
		cin >> tmp;
		p.push_back(tmp);
		fp.push_back(tmp);
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
	//값은 fw와 fp에 각각 저장되어있음.
	 
	vector<float> tmp; //축이동의 값을 저장할 vector
	vector<float> w3; //저장될 w의 값 
	vector<float> p3; //저장될 p의 값 
	
	w3.push_back(0);
	p3.push_back(0);
	
	for(int i=0;i<n;i++){ //갯수에 맞춰서 반복 
		tmp.clear();
		float changePoint = w3[0]+fw[i];
		
		for(int j=0;j<w3.size();j++){// 축이동 값을 tmp에 일단 저★장★ 
			tmp.push_back(w3[j]+fw[i]);
		}
		
		for(int t=0;;t++){
			if(w3[t] < changePoint) {
				// w3가 vector이기 때문에 w3[t++]보다는 push_back으로 하는게 맞음.
				// 지금 제일 문제 되는 부분은 p3나 w3가 float값이기 때문에 배열의 값으로 표현 못하는 한계를 해결해야함.
				// 줸장... 
				for(int j=0;j<tmp.size();j++){ 
					w3[t++] = tmp[j];
				}
				break;
			}
		}
		
		tmp.clear();
		for(int j=0;j<p3.size();j++){
			tmp.push_back(p3[j]+fp[i]);
		}
		
		for(int t=0;;t++){
			if(p3[t] < changePoint){
				for(int j=0;j<tmp.size();j++){
					p3[t++] = tmp[j];
				}
				break;
			}
		}
		// 이동한 값을 기존의 값에 대입해야하는데
		// 동일한 무게(w)에서는 더 큰 가치를 저장해야만 이 알고리즘이 성립이 가능함.
		 
	}
	//축이동
	//비교
	//합치기 (실수이기 때문에 곤란한 부분이 없진않음...) 
	
}

int main(){	
	cin >> n >> m;
	
	init();
	
	dp_1();	
	dp_2();
	dp_3();
}

