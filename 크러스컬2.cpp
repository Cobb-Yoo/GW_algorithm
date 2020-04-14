#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
	return a[2] < b[2];
}

int find(int n, int *arr){
	if(n == arr[n]) return n;
	else return n = find(arr[n], arr);
}

int main(){
	int answer = 0;
	vector<vector<int>> v; // x, y, cost
	
	v.push_back({0,1,4}); // 0과 1은 정점이고 4는 비용 
	v.push_back({0,7,8});
	v.push_back({1,2,8});
	v.push_back({1,7,11});
	v.push_back({2,3,7});
	v.push_back({2,5,4});
	v.push_back({2,8,2});
	v.push_back({3,4,9});
	v.push_back({3,5,14});
	v.push_back({4,5,10});
	v.push_back({5,6,2});
	v.push_back({6,7,1});
	v.push_back({6,8,6});
	v.push_back({7,8,7});
	
	int len = v.size();
	int arr[len];
	
	for(int i=0;i<len;i++) arr[i] = i; //init_set();
	
	sort(v.begin(), v.end(), cmp); // 비용에 따른 오름차순으로 퀵sort 
	
	for(int i=0;i<len;i++){
		int x = find(v[i][0], arr);
		int y = find(v[i][1], arr);
		
		if(x != y) { // union();
			arr[x] = y;
			answer += v[i][2]; // cost
		}
	}
	
	cout << answer << endl;
}
