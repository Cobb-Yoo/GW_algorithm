#include <iostream>
#include <vector>

using namespace std;
int ks_DP1(int n, int M); //������ȹ�� 1
int ks_DP2(int n, int M); //������ȹ�� 2
float ks_DP3(int n, int M); //������ȹ�� 3
int W[] = { 2, 4, 5, 8, 3 }; // ����
int P[] = { 4, 6, 8, 9, 6 }; // ����ġ
int max(int L, int R); // ��

int main() {
	int P;
    float F;
	P = ks_DP1(5,13); 
	cout << "�ִ� �賶ũ�� 13�϶� ������ : " << P<<endl;
	P = ks_DP2(5, 13);
	cout << "�ִ� �賶ũ�� 13�϶� ������ : " << P << endl;
	F = ks_DP3(5, 13);
	cout << "�ִ� �賶ũ�� 13�϶� ������ : " << F << endl;
	return 0;
}

int ks_DP1(int n, int M) {
	int **K = new int*[7]; 
	//2���� ���� �迭 ����

	for (int i = 0; i <= 6; i++) {
		K[i] = new int[15];
	}
	int i, w;
	cout << "������ȹ��1"<<endl;
	for (w = 0; w <= M; w++) K[0][w] = 0; //���԰� 0�϶� 0���� �ʱ�ȭ
	for (i = 0; i <= n; i++) K[i][0] = 0; //�ƹ��͵� �ȳ־����� 0���� �ʱ�ȭ
	for (i = 1; i <= n; i++) {
		for (w = 1; w <= M; w++) {//���Ը� 1���ø���
			if (w < W[i-1]) K[i][w] = K[i - 1][w];  //�������ִ� ���Ժ��� ������ ���԰� ũ�� ���� �־��� ���ǰ�
			else K[i][w] = max(K[i - 1][w], (K[i - 1][w - W[i-1]] + P[i-1])); //���Ӱ� ���� ���ǰ� ���Ͽ� �� ����ġ�ִ� ���Ǽ���
		}
	}
	for (int i = 0; i <= n; i++) { //��¹�
		for (int j = 0; j <= M; j++) {
			if (K[i][j] < 0) {
				K[i][j] = 0;
			}
			cout << K[i][j] << " ";
		}
		cout#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100;

int dp[MAX][MAX];

int w[] = {0,3,5,4};
int p[] = {0,1,4,6};
int n=3, m=8;

void init(){
	int tmp;
	//w.push_back(0);
	//p.push_back(0);
	for(int i=0;i<n;i++){
		cin >> tmp;
	//	w.push_back(tmp);
	}
	for(int i=0;i<n;i++){
		cin >> tmp;
	//	p.push_back(tmp);
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
	cout << endl;
}

int dp_2_f(int a, int b){
	if(a == 1){
		if(b >= w[1]) return p[1];
		else return 1-p[2]; // ����� ����.... 
	}
	return max(dp_2_f(a-1, b), dp_2_f(a-1,b-w[a]) + p[a]);
}

void dp_2(){
	memset(dp,0,sizeof(dp));
	cout << dp_2_f(n,m) << endl;
}

int main(){
	//cin >> n >> m;
	
	//init();
	
	dp_1(); // O(nM)
	dp_2(); // seta(2^n)
	//dp_3();
} << endl;
	}
	return K[n][M];
}

int ks_DP2(int n, int M) {
	//�ٽ��ڵ�
	while (K[n][M]<0) { //���ϴ� ������ ������ ������ ���� �ǹ��ִ� ���϶� ���� �����Ⱚ�̸� �ݺ�
		if (i >= 0 && w >= 0) {
			if (w < W[i - 1]) {
				if (K[i - 1][w] >= 0) { //�������ִ� ���Ժ��� ������ ���԰� ũ�� ���� �־��� ���ǰ�
					K[i][w] = K[i - 1][w];
					cout << "i=" << i << "w=" << w << "value=" << K[i][w] << endl;
					i = n, w = M; //i, w�� �ٽ� n�� M���� �ʱ�ȭ�ϴ� ������ �ٽ� ���������� ������������
				}
			}
			if ((K[i - 1][w] >= 0) && (K[i - 1][w - W[i - 1]] >= 0)) { //���ϴ� �ΰ��� �ǹ��ִ� ���� ����ִٸ� ����
				K[i][w] = max(K[i - 1][w], K[i - 1][w - W[i - 1]] + P[i - 1]); //���Ӱ� ���� ���ǰ� ���Ͽ� �� ����ġ�ִ� ���Ǽ���
				cout << "i=" << i << "w=" << w << "value=" << K[i][w] << endl;
				i = n, w = M;  //i, w�� �ٽ� n�� M���� �ʱ�ȭ�ϴ� ������ �ٽ� ���������� ������������
			}
			if (K[i - 1][w] < 0) { //�ǹ��ִ� ���� �ƴ϶�� i�� 1�� �ٿ��ش�
				i = i - 1; continue; //�ٽ� while�� ó������
			}
			if (K[i - 1][w - W[i - 1]] < 0) { //�ǹ��ִ� ���� �ƴ϶�� w�� w-W[i-1]��, i�� 1�� �ٿ��ش�
				w = w - W[i - 1], i = i - 1; continue; //�ٽ� while�� ó������
			}
		}
	}
	
	return K[n][M];
}

int max(int L, int R) {
	if (L >= R) return L;
 	else return R;
}
float ks_DP3(int n, int M) {
	float Sx[6][20], Sy[6][20], SPx[6][20], SPy[6][20]; 
	//(Sx[���ǰ���][���ǹ���], Sy[���ǰ���][���ǹ���]) = S(x,y) Ki-1(W)
	//(SPx[][], SPy[][]) = SP(x,y) Ki-1(w-w[i])+P[i]
	float high = 0,hold=0;
	cout << "������ȹ��3" << endl;
	for (int i = 0; i <= n; i++) {
		if (i == 0) { //i�� 0�϶� �ʱ�ȭ 
			Sx[i][i] = 0; Sy[i][i] = 0;
			SPx[i][i] = W[i]; SPy[i][i] = P[i];
		}
		else {
			for (int j = 0;; j++) { 
				// 0�� �ƴ϶�� ���� S[i-1]���� S[i]�� ����
				if ((Sx[i - 1][j] >= 0) && (Sy[i-1][j] >=0)) { // ��ȿ�� �����ִ��� �˻�
					Sx[i][j] = Sx[i - 1][j]; Sy[i][j] = Sy[i - 1][j];
				}
				else break; // ��ȿ�� ���� ���ٸ� for�� Ż��
			}
			for (int j = 0;;j++) { 
				if ((SPx[i - 1][j] >= 0) && (SPy[i - 1][j] >= 0)) { 
					// SPi-1�� ��ȿ�Ѱ��� ����ִٸ�
					for (int k = 0; k <= 19; k++) { 
						if ((Sx[i][k] <= SPx[i - 1][j]) && (Sy[i][k] >= SPy[i - 1][j])) break; 
						//(x2>=x1 && y2<=y1)
						if ((Sx[i][k] >= SPx[i - 1][j]) && (Sy[i][k] <= SPy[i - 1][j])) { 
						//(x1>=x2 && y1<=y2)
							Sx[i][k] = SPx[i - 1][j]; Sy[i][k] = SPy[i - 1][j]; 
							//S(x,y)������ SP(x-1,y-1)�� �ٲ��ش�.
							break; 
						} 
						if (Sx[i][k] < 0) { 
							//S(x,y)��κп� SP(x,y)ä���
							Sx[i][k] = SPx[i - 1][j]; Sy[i][k] = SPy[i - 1][j]; 
							break; 
						}
					}
				}
				else break;
			}
			if (i != n) { //SP�� S���� ����� 1�۴�
				for (int j = 0;; j++) {
					if (Sx[i][j] >= 0) {
						//SP(x,y)=S(x+W[i],y+P[i]) ����
						SPx[i][j] = Sx[i][j] + W[i]; SPy[i][j] = Sy[i][j] + P[i];
					}
					else break;
				}
			}
		}
	}
	for (int i = 0; i < 6; i++) { //������� ����
		for (int loop = 0; loop < 20; loop++) {
			for (int j = 0; j < 20 - loop; j++) {
				if (Sx[i][j + 1] >= 0) {
					if (Sx[i][j] > Sx[i][j + 1]) {
						hold = Sx[i][j];
						Sx[i][j] = Sx[i][j + 1];
						Sx[i][j + 1] = hold;
						hold = Sy[i][j];
						Sy[i][j] = Sy[i][j + 1];
						Sy[i][j + 1] = hold;
					}
				}
			}
		}
	}
	for (int i = 0; i < 6; i++) {  //����ó��
		for (int j = 0; j < 20; j++) {
			if (j < 19) {
				if (Sx[i][j] == Sx[i][j + 1]) {
					if (Sy[i][j] > Sy[i][j + 1]) {
						Sx[i][j + 1] = -1; Sy[i][j+1] = -1;
					}else
						Sx[i][j] = -1; Sy[i][j] = -1;
				}
					
			}
		}
	}
	for (int i = 0; i <= n; i++) { //���� ȿ�������� �ִ� ������ ��
		for (int j = 0; j < 20; j++) {
			if(Sx[i][j]<=M)
				if (Sy[i][j] >= high) {
					high = Sy[i][j];
				}
		}
	}
	for (int i = 0; i <= n; i++) { //��¹�
		cout << "Sx[" << i << "] : ";
		for (int j = 0; j < 20; j++) {
			if (Sx[i][j] >= 0)
			cout << Sx[i][j] << "  ";
		}
		cout << endl;
	}
	for (int i = 0; i <= n; i++) { //��¹�
		cout << "Sy[" << i << "] :";
		for (int j = 0; j < 20; j++) {
			if (Sy[i][j] >= 0)
			cout << Sy[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) { //��¹�
		cout << "SPx[" << i << "] :";
		for (int j = 0; j < 20; j++) {
			if (SPx[i][j] >= 0)
			cout << SPx[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) { //��¹�
		cout << "SPy[" << i << "] :";
		for (int j = 0; j < 20; j++) {
			if(SPy[i][j]>=0)
			cout << SPy[i][j]<<" ";
		}
		cout << endl;
	}
	return high; //�ִ밪
}
