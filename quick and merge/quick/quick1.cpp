#include <iostream>
#include <vector>
#include <cstdlib> // rand()
#include <ctime>
using namespace std;

vector<int> v;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int left, int right) {
	int pivot_index = rand() % (right + 1 - left) + left;
	int pivot_value = v[pivot_index];

	swap(&v[pivot_index], &v[right]);

	// store_index를 기준으로
	// 왼쪽에 pivot_value보다 작은 값들 위치시킴
	int store_index = left;
	for (int i = left; i < right; i++) {
		if (v[i] < pivot_value) {
			swap(&v[i], &v[store_index]);
			store_index += 1;
		}
	}

	swap(&v[store_index], &v[right]);

	return store_index;

}

void quicksort(int low, int high){
	int pivot = partition(low, high);
	if(low < pivot-1) quicksort(low,pivot-1);
	if(pivot+1 < high) quicksort(pivot+1,high);
}

int main(){
	srand((unsigned)time(NULL));
	int n; // 배열의 크기
	cout << "배열의 크기를 설정하세요. : ";
	cin >>  n;
	
	for(int i=0;i<n;i++) v.push_back(i+1);
	
	for(int i=0;i<100000;i++){ // 시간은 걸리더라도 최대한 잘 섞이도록 많이 섞음. 
		int x = rand() % n;
		int y = rand() % n;
		
		if(x != y){
			int tmp = v[x];
			v[x] = v[y];
			v[y] = tmp;
		}
	}
	
	// 지금 소스에서는 피벗의 값을 맨 왼쪽으로 고정함.
	// 배열의 요소의 갯수가 임계값 보다 작은 경우도 생각하지 않음. 
	float s = clock();
	quicksort(0,n-1);
	float f = clock();
	
//	for(int i=0;i<n;i++) cout << v[i] << " ";
	cout << endl;
	
	cout << (float)(f-s)/CLOCKS_PER_SEC << "초 걸렸습니다. "<< endl;
}
