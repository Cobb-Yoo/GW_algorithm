#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;

vector<long long> quick_v;

void swap(ll &a, ll &b) { // swap함수를 사용하는 곳에서 편하게 코드를 짜기 위해서 참조를 사용.
	ll tmp = a;
	a = b;
	b = tmp;
}

long long partition(long long left, long long right) { // pivot의 값을 return하는 함수
	long long pivot_index = rand() % (right + 1 - left) + left; //함수의 범위 중 하나를 선택
	long long pivot_value = quick_v[pivot_index]; // 이 값보다 작은 값들을 왼쪽에 위치 시킴

	swap(quick_v[pivot_index], quick_v[right]); // 아래 반복문에 적용안되게 값을 변경

	long long store_index = left;
	for (long long i = left; i < right; i++) {
		if (quick_v[i] < pivot_value) {
			swap(quick_v[i], quick_v[store_index]);
			store_index += 1;
		}
	}

	swap(quick_v[store_index], quick_v[right]);

	return store_index;
}

void quicksort(long long low, long long high){
	long long pivot = partition(low, high); // pivot을 선택하는 함수
	if(low < pivot-1) quicksort(low,pivot-1); //pivot을 기준으로 왼쪽 값들을 정렬
	if(pivot+1 < high)  quicksort(pivot+1,high); //pivot을 기준으로 오른쪽 값들을 정렬
}

int main(){
	srand((unsigned)time(NULL));
	long long n; // 배열의 크기
	cout << "배열의 크기를 설정하세요. : ";
	cin >>  n;
	
	for(long long i=0;i<n;i++) quick_v.push_back(i+1);
	
	cout << "test 1\n";
	for(long long i=0;i<n;i++){ // 시간은 걸리더라도 최대한 잘 섞이도록 많이 섞음. 
		long long x = rand() % (n-i) + i;
		
		swap(quick_v[x],quick_v[i]);
	}
	
	cout << "test 2\n";
	// 지금 소스에서는 피벗의 값을 맨 왼쪽으로 고정함.
	// 배열의 요소의 갯수가 임계값 보다 작은 경우도 생각하지 않음. 
	float s = clock();
	quicksort(0,n-1);
	float f = clock();
	
	cout << "test 3\n";
	
//	for(int i=0;i<n;i++) cout << v[i] << " ";
	cout << endl;
	
	cout << (float)(f-s)/CLOCKS_PER_SEC << "초 걸렸습니다. "<< endl;
}
