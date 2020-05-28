#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;

vector<ll> quick_v,insert_v;
ll index = 0;

void swap(ll &a, ll &b) { // swap�Լ��� ����ϴ� ������ ���ϰ� �ڵ带 ¥�� ���ؼ� ������ ���.
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

ll partition(vector<ll> &quick_v,ll left, ll right) { // pivot�� ���� return�ϴ� �Լ�
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

void quicksort(vector<ll> &quick_v, ll low, ll high){
	ll pivot = partition(quick_v,low, high); // pivot�� �����ϴ� �Լ�
	if(low < pivot-1) {
		if(pivot-low <= index) insert_sort(quick_v,low, pivot-1);
		else quicksort(quick_v,low,pivot-1); //pivot�� �������� ���� ������ ����
	}
	if(pivot+1 < high) {
		if(high - pivot <= index) insert_sort(quick_v,pivot+1,high);
		else quicksort(quick_v,pivot+1,high); //pivot�� �������� ������ ������ ����
	}
}

int main(){
	srand((unsigned)time(NULL)); // rand�� �ұ�Ģ������ ����ϱ� ����.
	
	ll len = 100000; // �迭�� ũ��
	vector<ll> v;
	
	for(long long i=0;i<len;i++) v.push_back(i+1); // �迭�� �ʱ� ��.
	
	for(ll i=0;i<len;i++){ // �ð��� �ɸ����� �ִ��� �� ���̵��� ���� ����. 
		ll x = rand() % (len-i) + i;
			
		swap(v[i], v[x]);
	}

	// ������ �迭�� ������ �� �ɸ��� �ð��� �����ϱ� ���ϱ� ������
	// v���� merge_v�� quick_v�� ����
	
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

