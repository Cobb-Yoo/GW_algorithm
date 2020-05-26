#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define ll long long
using namespace std;

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

int main(){
	ll n;
	cin >> n;
	vector<ll> v(n);
	srand((unsigned ll)time(NULL));
	
	for(ll i=0;i<n;i++) v[i] = i+1;
	
	for(ll i=0;i<100000;i++){
		ll x = rand() % n;
		ll y = rand() % n;
		
		if(x != y){
			ll tmp = v[x];
			v[x] = v[y];
			v[y] = tmp;
		}
	}
	
	float s = clock();
	mergesort(v,0,n-1);
	float f = clock();
	
	cout << (float)(f-s)/CLOCKS_PER_SEC << "초 걸렸습니다. "<< endl;
}
