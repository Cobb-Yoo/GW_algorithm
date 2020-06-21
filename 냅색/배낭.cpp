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
	cout << "dp_1" << endl;
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j < w[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+p[i]);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "dp_1의 최대효율 = " << dp[n][m] << endl;
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
	cout << "dp_2" << endl;
	memset(dp,0,sizeof(dp));
	
	int answer = dp_2_f(n,m);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
		
	cout << "dp_2의 최대효율 = " << answer << endl;
}

bool cmp(pair<float, float> a, pair<float, float> b){
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

void dp_3(){
	vector<pair<float, float>> s;
	s.push_back({0,0});
	
	for(int T=0;T<n;T++){
		vector<pair<float, float>> sp;
		vector<pair<float, float>> tmp;
		
		int len = s.size();
		for(int i=0;i<len;i++){ //평행이동. 
			sp.push_back({s[i].first + float_w[T], s[i].second + float_p[T]});
		}		
		
		int a,b;
		for(a=0,b=0;a < s.size();){
			if(s[a].first >= sp[b].first && s[a].second <= sp[b].second) a++;
			else tmp.push_back(s[a++]);
		}
		
		while(a < s.size()) tmp.push_back(s[a++]);
		while(b < sp.size()) tmp.push_back(sp[b++]);
		
		s = tmp;
				
		sort(s.begin(), s.end(), cmp);
	}
	
	int len = s.size();
	float answer = 0;
	for(int i=0;i<len;i++){
		if(s[i].first > m) break;
		answer = max(s[i].second, answer);
	}
	
	vector<pair<float, float>> tmp;
	for(int i=1;i<len;i++){
		if(s[i].first != s[i-1].first){
			if(i == len-1){
				tmp.push_back({s[i-1].first,s[i-1].second});
				tmp.push_back({s[i].first,s[i].second});
			}
			else tmp.push_back({s[i-1].first,s[i-1].second});
		}
	}
	
	s = tmp;
	
	for(int i=0;i<s.size();i++){
		cout << s[i].first << " " << s[i].second << endl;
	}
	cout << endl;
	
	cout << answer << endl;
}

int main(){	
	cin >> n >> m;
	
	init();
	
	dp_1();	
	dp_2();
	dp_3();
}

