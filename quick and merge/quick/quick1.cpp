#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#define ll long long
using namespace std;

vector<long long> quick_v;

void swap(ll &a, ll &b) { // swap�Լ��� ����ϴ� ������ ���ϰ� �ڵ带 ¥�� ���ؼ� ������ ���.
	ll tmp = a;
	a = b;
	b = tmp;
}

long long partition(long long left, long long right) { // pivot�� ���� return�ϴ� �Լ�
	long long pivot_index = rand() % (right + 1 - left) + left; //�Լ��� ���� �� �ϳ��� ����
	long long pivot_value = quick_v[pivot_index]; // �� ������ ���� ������ ���ʿ� ��ġ ��Ŵ

	swap(quick_v[pivot_index], quick_v[right]); // �Ʒ� �ݺ����� ����ȵǰ� ���� ����

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
	long long pivot = partition(low, high); // pivot�� �����ϴ� �Լ�
	if(low < pivot-1) quicksort(low,pivot-1); //pivot�� �������� ���� ������ ����
	if(pivot+1 < high)  quicksort(pivot+1,high); //pivot�� �������� ������ ������ ����
}

int main(){
	srand((unsigned)time(NULL));
	long long n; // �迭�� ũ��
	cout << "�迭�� ũ�⸦ �����ϼ���. : ";
	cin >>  n;
	
	for(long long i=0;i<n;i++) quick_v.push_back(i+1);
	
	cout << "test 1\n";
	for(long long i=0;i<n;i++){ // �ð��� �ɸ����� �ִ��� �� ���̵��� ���� ����. 
		long long x = rand() % (n-i) + i;
		
		swap(quick_v[x],quick_v[i]);
	}
	
	cout << "test 2\n";
	// ���� �ҽ������� �ǹ��� ���� �� �������� ������.
	// �迭�� ����� ������ �Ӱ谪 ���� ���� ��쵵 �������� ����. 
	float s = clock();
	quicksort(0,n-1);
	float f = clock();
	
	cout << "test 3\n";
	
//	for(int i=0;i<n;i++) cout << v[i] << " ";
	cout << endl;
	
	cout << (float)(f-s)/CLOCKS_PER_SEC << "�� �ɷȽ��ϴ�. "<< endl;
}
