#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void merge(vector<int> &v, int low, int middle, int high){
	int n1=low, n2=middle+1, cnt = 0;
	vector<int> sub_v;
	
	while(n1 <= middle && n2 <= high){
		if(v[n1] < v[n2]) sub_v.push_back(v[n1++]);
		else if(v[n1] > v[n2]) sub_v.push_back(v[n2++]);
	}
	
	while(n1 <= middle) sub_v.push_back(v[n1++]);
	while(n2 <= high) sub_v.push_back(v[n2++]);
	
	for(int i=low;i<=high;i++) v[i] = sub_v[cnt++];
}

void mergesort(vector<int> &v, int low, int high){	
	if(low < high){
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
	
	for(int i=0;i<100000;i++){
		int x = rand() % n;
		int y = rand() % n;
		
		if(x != y){
			int tmp = v[x];
			v[x] = v[y];
			v[y] = tmp;
		}
	}
	
	float s = clock();
	mergesort(v,0,n-1);
	float f = clock();
	
	cout << (float)(f-s)/CLOCKS_PER_SEC << "초 걸렸습니다. "<< endl;
}
