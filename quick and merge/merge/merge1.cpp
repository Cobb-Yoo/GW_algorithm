#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

vector<int> mergesort(vector<int> &v, int low, int high){
	/*
	1. 마지막 까지 분열하고 재결합하는 방법 
	2. 어떤 기준으로 분열을 시킬 것인가 →middle
	3. 굳이 1개까지 나누지 않아도 될듯 →2~3개까지 나누면 될듯. 
	*/
	vector<int> c = v;
	// (high+low)/2는 오버플로우가 발생할 수 있기 때문에.
	// 연산의 결과가 동일한 low + (high - low) / 2을 채택. 
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
