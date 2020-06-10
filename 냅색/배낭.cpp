#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> w;
vector<int> p;
vector<float> float_w;
vector<float> float_p;

int n,m;

int dp[100][100];
float dp3[100];

void init(){
	w.push_back(0);
	p.push_back(0);
	float_w.push_back(0);
	float_p.push_back(0);
	float tmp;
	for(int i=0;i<n;i++){
		cin >> tmp;
		w.push_back(tmp);
		float_w.push_back(tmp);
	}
	for(int i=0;i<n;i++){
		cin >> tmp;
		p.push_back(tmp);
		float_p.push_back(tmp);
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
	vector<float> dp_3_tmp_w;
	vector<float> dp_3_tmp_p;
	
	vector<float> tmp;
	
	dp_3_tmp_w.push_back(0);
	dp_3_tmp_p.push_back(0);
	
	for(int i=1;i<=n;i++){;
		tmp.clear();
		
		//for(int j=0;j<dp_3_tmp_w.size();j++){
		//	cout << dp_3_tmp_w[j] << " ";
		//}
		//cout << endl;
		
		for(int j=0;j<dp_3_tmp_w.size();j++){ // 평행이동 함. 
			tmp.push_back(dp_3_tmp_w[j] + float_w[i]);
		}
		
		cout << "tmp_w : ";
		for(int j=0;j<tmp.size();j++){
			cout << tmp[j] << " ";
		}
		cout << endl;
		
		int cnt = 0;
		for(;;){ // 기존의 값에 삽입할 정수 부분을 찾기. 
			if(tmp[0] >= dp_3_tmp_w[cnt]) {
				cnt++;
				if(cnt >= dp_3_tmp_w.size()) break;
			}
			else break;
		}
		
		cout << "cnt : " << cnt << endl;
		int len = tmp.size()+cnt+1;
		
		cout << "dp_3_tmp_w : ";
		for(int j=0;j<dp_3_tmp_w.size();j++){
			cout << dp_3_tmp_w[j] << " ";
		}
		cout << endl;
		
		for(int j = cnt;j<len;j++){ //두 배열을 합치기!!!!! 제발 
			if(j >= dp_3_tmp_w.size()-1) dp_3_tmp_w.push_back(tmp[j-cnt]);
			else dp_3_tmp_w[j] = tmp[j-cnt];
		}
		
		cout << "dp_3_tmp_w : ";
		for(int j=0;j<dp_3_tmp_w.size();j++){
			cout << dp_3_tmp_w[j] << " ";
		}
		cout << endl << endl;
		
		//=======================================w축 완료 
		tmp.clear();
		for(int j=0;j<dp_3_tmp_p.size();j++){ // 평행이동 함. 
			tmp.push_back(dp_3_tmp_p[j] + float_p[i]);
		}
		
		len = dp_3_tmp_p.size()+cnt;
		for(int j = cnt;j<len;j++){
			if(cnt > dp_3_tmp_p.size()) dp_3_tmp_p.push_back(tmp[j-cnt]);
			else dp_3_tmp_p[j] = max(dp_3_tmp_p[j], tmp[j-cnt]);
		}
	}
	
	float dp3_MAX = 0;
	for(int i=1;i<dp_3_tmp_w.size();i++){
		if(dp_3_tmp_w[i] <= m) dp3_MAX = max(dp3_MAX, dp_3_tmp_p[i]);
	}
	
	cout << dp3_MAX << endl;
	
	for(int i=0;i<dp_3_tmp_w.size();i++){
		cout << dp_3_tmp_w[i] << " ";
	}
	cout << endl;
	for(int i=0;i<dp_3_tmp_p.size();i++){
		cout << dp_3_tmp_p[i] << " ";
	}
	cout << endl;
}

int main(){	
	cin >> n >> m;
	
	init();
	
	dp_1();	
	dp_2();
	dp_3();
}

