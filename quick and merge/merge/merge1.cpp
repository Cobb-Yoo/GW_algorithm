#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

vector<int> mergesort(vector<int> &v, int low, int high){
	/*
	1. ������ ���� �п��ϰ� ������ϴ� ��� 
	2. � �������� �п��� ��ų ���ΰ� ��middle
	3. ���� 1������ ������ �ʾƵ� �ɵ� ��2~3������ ������ �ɵ�. 
	*/
	vector<int> c = v;
	// (high+low)/2�� �����÷ο찡 �߻��� �� �ֱ� ������.
	// ������ ����� ������ low + (high - low) / 2�� ä��. 
	int middle = low + (high - low) / 2; 
	if(low < high){
		vector<int> a = mergesort();
		vector<int> b = mergesort();
		c = merge(a,b);
	}
	
	return v;
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
