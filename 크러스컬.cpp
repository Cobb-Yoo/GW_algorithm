#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int set[], int x){
	if(set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a,int b){
	a = getParent(set, a);
	b = getParent(set, b);
	if(a < b) set[b] = a;
	else set[a] = b;
}

bool find(int set[], int a, int b){
	a = getParent(set,a);
	b = getParent(set,b);
	if(a==b) return 1;
	else return 0;
}

class edge {
	public:
		int node[2];
		int distance;
		edge(int a, int b, int distance){
			this->node[0] = a;
			this->node[1] = b;
			this->distance = distance;
		}
		bool operator <(edge &edge){
			return this->distance < edge.distance;
		}
};
int main(){
	int n = 9;
	int m = 14;
	
	vector<edge> v;
	
	v.push_back(edge(0,1,4));
	v.push_back(edge(0,7,8));
	v.push_back(edge(1,2,8));
	v.push_back(edge(1,7,11));
	v.push_back(edge(2,3,7));
	v.push_back(edge(2,5,4));
	v.push_back(edge(2,8,2));
	v.push_back(edge(3,4,9));
	v.push_back(edge(3,5,14));
	v.push_back(edge(4,5,10));
	v.push_back(edge(5,6,2));
	v.push_back(edge(6,7,1));
	v.push_back(edge(6,8,6));
	v.push_back(edge(7,8,7));
	
	sort(v.begin(),v.end());
	
	for(int i=0;i<v.size();i++){
		cout << v[i].node[0] << " " << v[i].node[1] << " " << v[i].distance << endl;
	}
	
	int set[n];
	for(int i=0;i<n;i++) set[i] = i;
	
	int sum = 0;
	int len = v.size();
	for(int i=0;i<len;i++){
		if(!find(set,v[i].node[0]-1, v[i].node[1]-1)){
			sum += v[i].distance;
			unionParent(set, v[i].node[0]-1,v[i].node[1]-1);
		}
	}
	
	cout << sum << endl;
}
