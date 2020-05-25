#include <iostream>
#include <vector>
#include <cstdlib> // rand()
#include <ctime>
using namespace std;

vector<long long> v;

void swap(long long *a, long long *b) {
	long long tmp = *a;
	*a = *b;
	*b = tmp;
}

long long partition(long long left, long long right) {
	long long pivot_index = rand() % (right + 1 - left) + left;
	long long pivot_value = v[pivot_index];

	swap(&v[pivot_index], &v[right]);

	// store_index�� ��������
	// ���ʿ� pivot_value���� ���� ���� ��ġ��Ŵ
	long long store_index = left;
	for (long long i = left; i < right; i++) {
		if (v[i] < pivot_value) {
			swap(&v[i], &v[store_index]);
			store_index += 1;
		}
	}

	swap(&v[store_index], &v[right]);

	return store_index;

}

void quicksort(long long low, long long high){
	long long pivot = partition(low, high);
	if(low < pivot-1) quicksort(low,pivot-1);
	if(pivot+1 < high) quicksort(pivot+1,high);
}

int main(){
	srand((unsigned)time(NULL));
	long long n; // �迭�� ũ��
	cout << "�迭�� ũ�⸦ �����ϼ���. : ";
	cin >>  n;
	
	for(long long i=0;i<n;i++) v.push_back(i+1);
	
	for(int i=0;i<10000000;i++){ // �ð��� �ɸ����� �ִ��� �� ���̵��� ���� ����. 
		int x = rand() % n;
		int y = rand() % n;
		
		if(x != y){
			int tmp = v[x];
			v[x] = v[y];
			v[y] = tmp;
		}
	}
	
	// ���� �ҽ������� �ǹ��� ���� �� �������� ������.
	// �迭�� ����� ������ �Ӱ谪 ���� ���� ��쵵 �������� ����. 
	float s = clock();
	quicksort(0,n-1);
	float f = clock();
	
//	for(int i=0;i<n;i++) cout << v[i] << " ";
	cout << endl;
	
	cout << (float)(f-s)/CLOCKS_PER_SEC << "�� �ɷȽ��ϴ�. "<< endl;
}
