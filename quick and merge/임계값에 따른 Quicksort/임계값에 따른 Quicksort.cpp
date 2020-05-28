#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;

vector<ll> quick_v,insert_v;
ll index = 0;

void swap(ll &a, ll &b) { // swap함수를 사용하는 곳에서 편하게 코드를 짜기 위해서 참조를 사용.
	ll tmp = a;
	a = b;
	b = tmp;
}

void insert_sort(vector<ll> &arr, ll x, ll y){
	ll j;
	for(ll i= x;i <= y;i++){
		j = i;
		while(j > 0 && arr[j-1] > arr[j]){
			swap(arr[j], arr[j-1]);
			j--;
		}
	}
}

ll partition(vector<ll> &quick_v,ll left, ll right) { // pivot의 값을 return하는 함수
	ll pivot_index = rand() % (right + 1 - left) + left; //함수의 범위 중 하나를 선택
	ll pivot_value = quick_v[pivot_index]; // 이 값보다 작은 값들을 왼쪽에 위치 시킴

	swap(quick_v[pivot_index], quick_v[right]); // 아래 반복문에 적용안되게 값을 변경

	ll store_index = left;
	for (ll i = left; i < right; i++) {
		if (quick_v[i] < pivot_value) {
			swap(quick_v[i], quick_v[store_index]);
			store_index += 1;
		}
	}

	swap(quick_v[store_index], quick_v[right]);

	return store_index;
}

void quicksort(vector<ll> &quick_v, ll low, ll high){
	ll pivot = partition(quick_v,low, high); // pivot을 선택하는 함수
	if(low < pivot-1) {
		if(pivot-low <= index) insert_sort(quick_v,low, pivot-1);
		else quicksort(quick_v,low,pivot-1); //pivot을 기준으로 왼쪽 값들을 정렬
	}
	if(pivot+1 < high) {
		if(high - pivot <= index) insert_sort(quick_v,pivot+1,high);
		else quicksort(quick_v,pivot+1,high); //pivot을 기준으로 오른쪽 값들을 정렬
	}
}

int main(){
	srand((unsigned)time(NULL)); // rand를 불규칙적으로 사용하기 위함.
	
	ll len = 100000; // 배열의 크기
	vector<ll> v;
	
	for(long long i=0;i<len;i++) v.push_back(i+1); // 배열의 초기 값.
	
	for(ll i=0;i<len;i++){ // 시간은 걸리더라도 최대한 잘 섞이도록 많이 섞음. 
		ll x = rand() % (len-i) + i;
			
		swap(v[i], v[x]);
	}

	// 동일한 배열을 정렬할 때 걸리는 시간을 측정하기 위하기 때문에
	// v값을 merge_v와 quick_v에 복사
	
	for(index = 1;index <= 100000;index*=10){
		insert_v = quick_v = v; 
		
		float s1 = clock();
		quicksort(quick_v,0,len-1);
		float f1 = clock();
		
		float s2 = clock();
		insert_sort(insert_v,0,len-1);
		float f2 = clock();
				
		cout << (f1-s1)/CLOCKS_PER_SEC << "\t";
		cout << (f2-s2)/CLOCKS_PER_SEC << "\n";
	}
	
	cout << endl;		
}

