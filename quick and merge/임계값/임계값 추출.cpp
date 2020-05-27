#include <iostream>
#include <vector>
#include <cstdlib> // rand()
#include <ctime>
#include <algorithm>
#define ll long long
using namespace std;

vector<ll> insert_v, quick_v;
const int Test_case = 10000;

void swap(ll &a, ll &b){
	ll tmp = a;
	a = b;
	b = tmp;
}

void insert_sort(ll x, ll y){
	ll j;
	for(ll i= x;i <= y;i++){
		j = i;
		while(j > 0 && insert_v[j-1] > insert_v[j]){
			swap(insert_v[j], insert_v[j-1]);
			j--;
		}
	}
}

ll partition(ll left, ll right) {
	ll pivot_index = rand() % (right + 1 - left) + left;
	ll pivot_value = quick_v[pivot_index];

	swap(quick_v[pivot_index], quick_v[right]);

	// store_index를 기준으로
	// 왼쪽에 pivot_value보다 작은 값들 위치시킴
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

void quicksort(ll low, ll high){
	ll pivot = partition(low, high);
	if(low < pivot-1) quicksort(low,pivot-1);
	if(pivot+1 < high) quicksort(pivot+1,high);
}

int main(){
	ll min_index = 1000;
	ll max_index = 0;
	srand((unsigned)time(NULL));
	vector<int> index;
	
	for(int T=0;T<Test_case;T++){
		for(ll n=1;n<=1000;n++){
			vector<ll> v;
			for(ll i=0;i<n;i++) v.push_back(i+1);
		
			ll len = n * 100;
	
		#include <iostream>
#include <vector>
#include <cstdlib> // rand()
#include <ctime>
#define ll long long
using namespace std;

vector<ll> insert_v, quick_v; // 동일한 배열에 대해서 정렬의 속도를 비교해야하기 위함.
const int Test_case = 10000;

void swap(ll &a, ll &b){
	ll tmp = a;
	a = b;
	b = tmp;
}

void insert_sort(ll x, ll y){
	ll j;
	for(ll i= x;i <= y;i++){
		j = i;
		while(j > 0 && insert_v[j-1] > insert_v[j]){
			swap(insert_v[j], insert_v[j-1]);
			j--;
		}
	}
}

ll partition(ll left, ll right) { // mergesort vs Quicksort의 함수와 동일함
	ll pivot_index = rand() % (right + 1 - left) + left;
	ll pivot_value = quick_v[pivot_index];

	swap(quick_v[pivot_index], quick_v[right]);

	// store_index를 기준으로
	// 왼쪽에 pivot_value보다 작은 값들 위치시킴
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

void quicksort(ll low, ll high){ 
	ll pivot = partition(low, high);
	if(low < pivot-1) quicksort(low,pivot-1);
	if(pivot+1 < high) quicksort(pivot+1,high);
}

int main(){

	srand((unsigned)time(NULL));
	vector<int> index;
	
	for(int T=0;T<Test_case;T++){ // Test_case는 상수로 10,000
		for(ll n=1;n<=1000;n++){ // 1부터 1000까지 배열의 길이를 1씩 증가 시키면서 비교.
			vector<ll> v;
			for(ll i=0;i<n;i++) v.push_back(i+1);
		
			ll len = n * 100;
	
			for(ll i=0;i<len;i++){
				ll x = rand() % n;
				ll y = rand() % n;
		
				if(x != y) swap(v[x],v[y]);
			}
	
			quick_v = insert_v = v; // 동일한 배열을 복사
	
			float s = clock();
			insert_sort(0, n-1);
			float f = clock();
	
			float s2 = clock();
			quicksort(0, n-1);
			float f2 = clock();
	
			//  Quicksort의 속도가 더 빨라지는 배열의 길이 n-1을 찾아내는 조건문
			if((float)(f-s)/CLOCKS_PER_SEC > (float)(f2-s2)/CLOCKS_PER_SEC) {
				index.push_back(n-1);
				break;
			}
		}
	}
	
	ll tmp = 0;
	for(int i=0;i<Test_case;i++) tmp += index[i];
	cout << (float)tmp / Test_case << endl; // 평균값을 출력함.
}	for(ll i=0;i<len;i++){
				ll x = rand() % n;
				ll y = rand() % n;
		
				if(x != y) swap(v[x],v[y]);
			}
	
			quick_v = insert_v = v;
	
			float s = clock();
			insert_sort(0, n-1);
			float f = clock();
	
			float s2 = clock();
			quicksort(0, n-1);
			float f2 = clock();
	
			if((float)(f-s)/CLOCKS_PER_SEC > (float)(f2-s2)/CLOCKS_PER_SEC) {
				index.push_back(n-1);
				max_index = max(n-1, max_index);
				min_index = min(n-1, min_index);
				break;
			}
		}
	}
	
	ll tmp = 0;
	for(int i=0;i<Test_case;i++) tmp += index[i];
	cout << (float)tmp / Test_case << endl;
	cout << min_index << " " << max_index << endl;
}
