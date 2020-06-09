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
	//���� fw�� fp�� ���� ����Ǿ�����.
	 
	vector<float> tmp; //���̵��� ���� ������ vector
	vector<float> w3; //����� w�� �� 
	vector<float> p3; //����� p�� �� 
	
	w3.push_back(0);
	p3.push_back(0);
	
	for(int i=0;i<n;i++){ //������ ���缭 �ݺ� 
		tmp.clear();
		float changePoint = w3[0]+fw[i];
		
		for(int j=0;j<w3.size();j++){// ���̵� ���� tmp�� �ϴ� ������� 
			tmp.push_back(w3[j]+fw[i]);
		}
		
		for(int t=0;;t++){
			if(w3[t] < changePoint) {
				// w3�� vector�̱� ������ w3[t++]���ٴ� push_back���� �ϴ°� ����.
				// ���� ���� ���� �Ǵ� �κ��� p3�� w3�� float���̱� ������ �迭�� ������ ǥ�� ���ϴ� �Ѱ踦 �ذ��ؾ���.
				// �k��... 
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
		// �̵��� ���� ������ ���� �����ؾ��ϴµ�
		// ������ ����(w)������ �� ū ��ġ�� �����ؾ߸� �� �˰����� ������ ������.
		 
	}
	//���̵�
	//��
	//��ġ�� (�Ǽ��̱� ������ ����� �κ��� ��������...) 
	
}

int main(){	
	cin >> n >> m;
	
	init();
	
	dp_1();	
	dp_2();
	dp_3();
}

