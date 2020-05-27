#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;

vector<ll> quick_v, merge_v;
const int sampling = 1;
const int index = 100;

void merge(ll low, ll middle, ll high){ // 두 배열을 병합하는 함수
	ll n1=low, n2=middle+1, cnt = 0;
	vector<ll> sub_v; // 동적으로 배열을 만들기 위해서 vector를 사용
	
	while(n1 <= middle && n2 <= high){ // 두 수를 지속적으로 비교하면서 순서대로 sub_v에 삽입
		if(merge_v[n1] < merge_v[n2]) sub_v.push_back(merge_v[n1++]);
		else if(merge_v[n1] > merge_v[n2]) sub_v.push_back(merge_v[n2++]);
	}
	
	while(n1 <= middle) sub_v.push_back(merge_v[n1++]); // 남은 값을 넣는 반복문
	while(n2 <= high) sub_v.push_back(merge_v[n2++]); // 남은 값을 넣는 반복문
	
	for(ll i=low;i<=high;i++) merge_v[i] = sub_v[cnt++]; // 기존의 배열에 합쳐진 결과를 적용
}

void mergesort(ll low, ll high){ 
	if(low < high){
		ll middle = low + (high - low) / 2; // (low+high)/2와 동일한 값이지만 각 값들이 충분히 큼, 자료형이 담을 수 있는 값보다 커질 수 있기 때문에 그것을 방지하고자 하는 연산.
		mergesort(low, middle);
		mergesort(middle+1, high);
		merge(low, middle, high);
	}
}

void swap(ll &a, ll &b) { // swap함수를 사용하는 곳에서 편하게 코드를 짜기 위해서 참조를 사용.
	ll tmp = a;
	a = b;
	b = tmp;
}

void insert_sort(ll x, ll y){
	ll j;
	for(ll i= x;i <= y;i++){
		j = i;
		while(j > 0 && quick_v[j-1] > quick_v[j]){
			swap(quick_v[j], quick_v[j-1]);
			j--;
		}
	}
}

ll partition(ll left, ll right) { // pivot의 값을 return하는 함수
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

void quicksort(ll low, ll high){
	ll pivot = partition(low, high); // pivot을 선택하는 함수
	if(low < pivot-1) {
		if(pivot-low <= index) insert_sort(low, pivot-1);
		else quicksort(low,pivot-1); //pivot을 기준으로 왼쪽 값들을 정렬
	}
	if(pivot+1 < high) {
		if(high - pivot <= index) insert_sort(pivot+1,high);
		else quicksort(pivot+1,high); //pivot을 기준으로 오른쪽 값들을 정렬
	}
}

int main(){
	srand((unsigned)time(NULL)); // rand를 불규칙적으로 사용하기 위함.
	
	for(ll T = 1;T<=10000000;T*=10){
		vector<float> q_sec; // Quicksort로 정렬되는 시간을 저장하는 vector
		vector<float> m_sec; // mergesort로 정렬되는 시간을 저장하는 vector
		
		for(int N=0;N<sampling;N++){
			ll n = T; // 배열의 크기
			vector<ll> v;
	
			for(long long i=0;i<n;i++) v.push_back(i+1); // 배열의 초기 값.
	
			ll len = n * 100; // 배열을 충분히 섞게 하기 위한 값.
	
			for(ll i=0;i<=len;i++){ // 시간은 걸리더라도 최대한 잘 섞이도록 많이 섞음. 
				int x = rand() % n;
				int y = rand() % n;
		
				swap(v[x], v[y]);
			}

			// 동일한 배열을 정렬할 때 걸리는 시간을 측정하기 위하기 때문에
			// v값을 merge_v와 quick_v에 복사

			merge_v = quick_v = v; 
		
			float s1 = clock();
			quicksort(0,n-1);
			float f1 = clock();
		
			float s2 = clock();
			mergesort(0,n-1);
			float f2 = clock();
	
			q_sec.push_back((f1-s1)/CLOCKS_PER_SEC); // 결과를 vector에 저장
			m_sec.push_back((f2-s2)/CLOCKS_PER_SEC);
		}
		
		
		double q_time = 0;
		double m_time = 0;
		
		for(int i=0;i<sampling;i++) q_time += q_sec[i];
		for(int i=0;i<sampling;i++) m_time += m_sec[i];
		q_time /= sampling;
		m_time /= sampling;
		
		// cout으로 출력할 경우 더 낮은 소수점을 출력하는 것보다 printf가 더 간단함.
		printf("%d\tQuicksort : %.10f",T,q_time);
		if(q_time > m_time) cout << "\t>\t";
		else if(q_time < m_time) cout << "\t<\t";
		else cout << "\t==\t";
		
		printf("mergesort : %.10f\n",m_time);
	}
}
