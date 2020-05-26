#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#define ll long long
using namespace std;

vector<ll> quick_v;
const int sampling = 100;

void merge(vector<ll> &v, ll low, ll middle, ll high){
	ll n1=low, n2=middle+1, cnt = 0;
	vector<ll> sub_v;
	
	while(n1 <= middle && n2 <= high){
		if(v[n1] < v[n2]) sub_v.push_back(v[n1++]);
		else if(v[n1] > v[n2]) sub_v.push_back(v[n2++]);
	}
	
	while(n1 <= middle) sub_v.push_back(v[n1++]);
	while(n2 <= high) sub_v.push_back(v[n2++]);
	
	for(ll i=low;i<=high;i++) v[i] = sub_v[cnt++];
}

void mergesort(vector<ll> &v, ll low, ll high){	
	if(low < high){
		ll middle = low + (high - low) / 2;
		mergesort(v, low, middle);
		mergesort(v, middle+1, high);
		merge(v, low, middle, high);
	}
}

void swap(ll &a, ll &b) {
	ll tmp = a;
	a = b;
	b = tmp;
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
	srand((unsigned)time(NULL));
	
	ofstream out("data.txt");
	
	for(ll T = 1;T<=10000000;T*=10){
		vector<float> q_sec;
		vector<float> m_sec;
		
		for(int N=0;N<sampling;N++){
			ll n = T; // 배열의 크기
			vector<ll> v;
	
			for(long long i=0;i<n;i++) v.push_back(i+1);
	
			ll len = n * 3;
	
			for(ll i=0;i<=len;i++){ // 시간은 걸리더라도 최대한 잘 섞이도록 많이 섞음. 
				int x = rand() % n;
				int y = rand() % n;
		
				swap(v[x], v[y]);
			}
	
			vector<ll> merge_v = quick_v = v;
		
			float s1 = clock();
			quicksort(0,n-1);
			float f1 = clock();
		
			float s2 = clock();
			mergesort(merge_v,0,n-1);
			float f2 = clock();
	
			q_sec.push_back((f1-s1)/CLOCKS_PER_SEC);
			m_sec.push_back((f2-s2)/CLOCKS_PER_SEC);
		}
		
		for(int i=0;i<sampling;i++) out << q_sec[i] << " ";
		out << endl;
		for(int i=0;i<sampling;i++) out << m_sec[i] << " ";
		out << endl;
		
		cout << T << endl;
	}
}
