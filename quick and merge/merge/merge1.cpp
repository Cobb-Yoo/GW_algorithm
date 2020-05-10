#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

void merge(vector<int> &v, int low, int middle, int high){
	int n1=low, n2=middle+1, s = low;
	int sorted[MAX];
	
	while(n1 <= middle && n2 <= high){
		if(v[n1] < v[n2]) sorted[s++] = v[n1++];
		else sorted[s++] = v[n2++];
	}
	if(n1 > middle) while(n2 <= high) sorted[s++] = v[n2++];
	else while(n1 <= middle) sorted[s++] = v[n1++];
	
	for(int i=low;i<=high;i++) v[i] = sorted[i];
}

void mergesort(vector<int> &v, int low, int high){
	/*
	3. ���� 1������ ������ �ʾƵ� �ɵ� ��2~3������ ������ �ɵ�. 
	*/
	
	if(low < high){
		// Ȥ�ó� (high+low) ���� �����÷ο찡 �߻��� �� �ֱ� ������
		//���� �����̳� ���������� ������ ä�� 
		int middle = low + (high - low) / 2;
		mergesort(v, low, middle);
		mergesort(v, middle+1, high);
		merge(v, low, middle, high);
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	
	srand((unsigned int)time(NULL));
	
	for(int i=0;i<n;i++) v[i] = i+1;
	
	for(int i=0;i<1000;i++){
		int x = rand() % n + 1;
		int y = rand() % n + 1;
		
		if(x != y){
			int tmp = v[x];
			v[x] = v[y];
			v[y] = tmp;
		}
	}
	
	float s = clock();
	vector<int> result = mergesort(v,0,n-1);
	float f = clock();
	
	for(int i=0;i<n;i++) result[i] << " ";
	cout << endl;
	
	cout << (f-s) << endl;
}
