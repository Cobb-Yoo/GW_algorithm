#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;

vector<ll> quick_v, merge_v;
const int sampling = 1;
const int index = 100;

void merge(ll low, ll middle, ll high){ // �� �迭�� �����ϴ� �Լ�
	ll n1=low, n2=middle+1, cnt = 0;
	vector<ll> sub_v; // �������� �迭�� ����� ���ؼ� vector�� ���
	
	while(n1 <= middle && n2 <= high){ // �� ���� ���������� ���ϸ鼭 ������� sub_v�� ����
		if(merge_v[n1] < merge_v[n2]) sub_v.push_back(merge_v[n1++]);
		else if(merge_v[n1] > merge_v[n2]) sub_v.push_back(merge_v[n2++]);
	}
	
	while(n1 <= middle) sub_v.push_back(merge_v[n1++]); // ���� ���� �ִ� �ݺ���
	while(n2 <= high) sub_v.push_back(merge_v[n2++]); // ���� ���� �ִ� �ݺ���
	
	for(ll i=low;i<=high;i++) merge_v[i] = sub_v[cnt++]; // ������ �迭�� ������ ����� ����
}

void mergesort(ll low, ll high){ 
	if(low < high){
		ll middle = low + (high - low) / 2; // (low+high)/2�� ������ �������� �� ������ ����� ŭ, �ڷ����� ���� �� �ִ� ������ Ŀ�� �� �ֱ� ������ �װ��� �����ϰ��� �ϴ� ����.
		mergesort(low, middle);
		mergesort(middle+1, high);
		merge(low, middle, high);
	}
}

void swap(ll &a, ll &b) { // swap�Լ��� ����ϴ� ������ ���ϰ� �ڵ带 ¥�� ���ؼ� ������ ���.
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

ll partition(ll left, ll right) { // pivot�� ���� return�ϴ� �Լ�
	ll pivot_index = rand() % (right + 1 - left) + left; //�Լ��� ���� �� �ϳ��� ����
	ll pivot_value = quick_v[pivot_index]; // �� ������ ���� ������ ���ʿ� ��ġ ��Ŵ

	swap(quick_v[pivot_index], quick_v[right]); // �Ʒ� �ݺ����� ����ȵǰ� ���� ����

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
	ll pivot = partition(low, high); // pivot�� �����ϴ� �Լ�
	if(low < pivot-1) {
		if(pivot-low <= index) insert_sort(low, pivot-1);
		else quicksort(low,pivot-1); //pivot�� �������� ���� ������ ����
	}
	if(pivot+1 < high) {
		if(high - pivot <= index) insert_sort(pivot+1,high);
		else quicksort(pivot+1,high); //pivot�� �������� ������ ������ ����
	}
}

int main(){
	srand((unsigned)time(NULL)); // rand�� �ұ�Ģ������ ����ϱ� ����.
	
	for(ll T = 1;T<=10000000;T*=10){
		vector<float> q_sec; // Quicksort�� ���ĵǴ� �ð��� �����ϴ� vector
		vector<float> m_sec; // mergesort�� ���ĵǴ� �ð��� �����ϴ� vector
		
		for(int N=0;N<sampling;N++){
			ll n = T; // �迭�� ũ��
			vector<ll> v;
	
			for(long long i=0;i<n;i++) v.push_back(i+1); // �迭�� �ʱ� ��.
	
			ll len = n * 100; // �迭�� ����� ���� �ϱ� ���� ��.
	
			for(ll i=0;i<=len;i++){ // �ð��� �ɸ����� �ִ��� �� ���̵��� ���� ����. 
				int x = rand() % n;
				int y = rand() % n;
		
				swap(v[x], v[y]);
			}

			// ������ �迭�� ������ �� �ɸ��� �ð��� �����ϱ� ���ϱ� ������
			// v���� merge_v�� quick_v�� ����

			merge_v = quick_v = v; 
		
			float s1 = clock();
			quicksort(0,n-1);
			float f1 = clock();
		
			float s2 = clock();
			mergesort(0,n-1);
			float f2 = clock();
	
			q_sec.push_back((f1-s1)/CLOCKS_PER_SEC); // ����� vector�� ����
			m_sec.push_back((f2-s2)/CLOCKS_PER_SEC);
		}
		
		
		double q_time = 0;
		double m_time = 0;
		
		for(int i=0;i<sampling;i++) q_time += q_sec[i];
		for(int i=0;i<sampling;i++) m_time += m_sec[i];
		q_time /= sampling;
		m_time /= sampling;
		
		// cout���� ����� ��� �� ���� �Ҽ����� ����ϴ� �ͺ��� printf�� �� ������.
		printf("%d\tQuicksort : %.10f",T,q_time);
		if(q_time > m_time) cout << "\t>\t";
		else if(q_time < m_time) cout << "\t<\t";
		else cout << "\t==\t";
		
		printf("mergesort : %.10f\n",m_time);
	}
}
