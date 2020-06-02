#include <iostream>
#include <vector>

using namespace std;
int ks_DP1(int n, int M); //동적계획법 1
int ks_DP2(int n, int M); //동적계획법 2
float ks_DP3(int n, int M); //동적계획법 3
int W[] = { 2, 4, 5, 8, 3 }; // 무게
int P[] = { 4, 6, 8, 9, 6 }; // 값어치
int max(int L, int R); // 비교

int main() {
	int P;
    float F;
	P = ks_DP1(5,13); 
	cout << "최대 배낭크기 13일때 최적해 : " << P<<endl;
	P = ks_DP2(5, 13);
	cout << "최대 배낭크기 13일때 최적해 : " << P << endl;
	F = ks_DP3(5, 13);
	cout << "최대 배낭크기 13일때 최적해 : " << F << endl;
	return 0;
}

int ks_DP1(int n, int M) {
	int **K = new int*[7]; 
	//2차원 동적 배열 생성

	for (int i = 0; i <= 6; i++) {
		K[i] = new int[15];
	}
	int i, w;
	cout << "동적계획법1"<<endl;
	for (w = 0; w <= M; w++) K[0][w] = 0; //무게가 0일때 0으로 초기화
	for (i = 0; i <= n; i++) K[i][0] = 0; //아무것도 안넣었을때 0으로 초기화
	for (i = 1; i <= n; i++) {
		for (w = 1; w <= M; w++) {//무게를 1씩늘린다
			if (w < W[i-1]) K[i][w] = K[i - 1][w];  //넣을수있는 무게보다 물건의 무게가 크면 전에 넣었던 물건값
			else K[i][w] = max(K[i - 1][w], (K[i - 1][w - W[i-1]] + P[i-1])); //새롭게 넣은 물건과 비교하여 더 값어치있는 물건선택
		}
	}
	for (int i = 0; i <= n; i++) { //출력문
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
		else return 1-p[2]; // 까리하지 않음.... 
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
	//핵심코드
	while (K[n][M]<0) { //원하는 물건의 갯수와 무게의 값이 의미있는 값일때 종료 쓰레기값이면 반복
		if (i >= 0 && w >= 0) {
			if (w < W[i - 1]) {
				if (K[i - 1][w] >= 0) { //넣을수있는 무게보다 물건의 무게가 크면 전에 넣었던 물건값
					K[i][w] = K[i - 1][w];
					cout << "i=" << i << "w=" << w << "value=" << K[i][w] << endl;
					i = n, w = M; //i, w를 다시 n과 M으로 초기화하는 이유는 다시 위에서부터 내려오기위해
				}
			}
			if ((K[i - 1][w] >= 0) && (K[i - 1][w - W[i - 1]] >= 0)) { //원하는 두값에 의미있는 값이 들어있다면 실행
				K[i][w] = max(K[i - 1][w], K[i - 1][w - W[i - 1]] + P[i - 1]); //새롭게 넣은 물건과 비교하여 더 값어치있는 물건선택
				cout << "i=" << i << "w=" << w << "value=" << K[i][w] << endl;
				i = n, w = M;  //i, w를 다시 n과 M으로 초기화하는 이유는 다시 위에서부터 내려오기위해
			}
			if (K[i - 1][w] < 0) { //의미있는 값이 아니라면 i를 1씩 줄여준다
				i = i - 1; continue; //다시 while문 처음으로
			}
			if (K[i - 1][w - W[i - 1]] < 0) { //의미있는 값이 아니라면 w를 w-W[i-1]씩, i를 1씩 줄여준다
				w = w - W[i - 1], i = i - 1; continue; //다시 while문 처음으로
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
	//(Sx[물건갯수][물건무게], Sy[물건갯수][물건무게]) = S(x,y) Ki-1(W)
	//(SPx[][], SPy[][]) = SP(x,y) Ki-1(w-w[i])+P[i]
	float high = 0,hold=0;
	cout << "동적계획법3" << endl;
	for (int i = 0; i <= n; i++) {
		if (i == 0) { //i가 0일때 초기화 
			Sx[i][i] = 0; Sy[i][i] = 0;
			SPx[i][i] = W[i]; SPy[i][i] = P[i];
		}
		else {
			for (int j = 0;; j++) { 
				// 0이 아니라면 기존 S[i-1]값들 S[i]로 복사
				if ((Sx[i - 1][j] >= 0) && (Sy[i-1][j] >=0)) { // 유효한 값이있는지 검사
					Sx[i][j] = Sx[i - 1][j]; Sy[i][j] = Sy[i - 1][j];
				}
				else break; // 유효한 값이 없다면 for문 탈출
			}
			for (int j = 0;;j++) { 
				if ((SPx[i - 1][j] >= 0) && (SPy[i - 1][j] >= 0)) { 
					// SPi-1에 유효한값이 들어있다면
					for (int k = 0; k <= 19; k++) { 
						if ((Sx[i][k] <= SPx[i - 1][j]) && (Sy[i][k] >= SPy[i - 1][j])) break; 
						//(x2>=x1 && y2<=y1)
						if ((Sx[i][k] >= SPx[i - 1][j]) && (Sy[i][k] <= SPy[i - 1][j])) { 
						//(x1>=x2 && y1<=y2)
							Sx[i][k] = SPx[i - 1][j]; Sy[i][k] = SPy[i - 1][j]; 
							//S(x,y)기존값 SP(x-1,y-1)로 바꿔준다.
							break; 
						} 
						if (Sx[i][k] < 0) { 
							//S(x,y)빈부분에 SP(x,y)채우기
							Sx[i][k] = SPx[i - 1][j]; Sy[i][k] = SPy[i - 1][j]; 
							break; 
						}
					}
				}
				else break;
			}
			if (i != n) { //SP는 S보다 사이즈가 1작다
				for (int j = 0;; j++) {
					if (Sx[i][j] >= 0) {
						//SP(x,y)=S(x+W[i],y+P[i]) 갱신
						SPx[i][j] = Sx[i][j] + W[i]; SPy[i][j] = Sy[i][j] + P[i];
					}
					else break;
				}
			}
		}
	}
	for (int i = 0; i < 6; i++) { //순서대로 정렬
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
	for (int i = 0; i < 6; i++) {  //예외처리
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
	for (int i = 0; i <= n; i++) { //가장 효율적으로 넣는 가방의 값
		for (int j = 0; j < 20; j++) {
			if(Sx[i][j]<=M)
				if (Sy[i][j] >= high) {
					high = Sy[i][j];
				}
		}
	}
	for (int i = 0; i <= n; i++) { //출력문
		cout << "Sx[" << i << "] : ";
		for (int j = 0; j < 20; j++) {
			if (Sx[i][j] >= 0)
			cout << Sx[i][j] << "  ";
		}
		cout << endl;
	}
	for (int i = 0; i <= n; i++) { //출력문
		cout << "Sy[" << i << "] :";
		for (int j = 0; j < 20; j++) {
			if (Sy[i][j] >= 0)
			cout << Sy[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) { //출력문
		cout << "SPx[" << i << "] :";
		for (int j = 0; j < 20; j++) {
			if (SPx[i][j] >= 0)
			cout << SPx[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) { //출력문
		cout << "SPy[" << i << "] :";
		for (int j = 0; j < 20; j++) {
			if(SPy[i][j]>=0)
			cout << SPy[i][j]<<" ";
		}
		cout << endl;
	}
	return high; //최대값
}
