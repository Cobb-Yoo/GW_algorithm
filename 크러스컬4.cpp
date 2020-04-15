#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> q;

void init_set(int *arr, int n){
	for(int i=0;i<n;i++) arr[i] = -1;
}

bool cmp(vector<int> a, vector<int> b){
	return a[2] < b[2];
}

int find(int n, int *arr){
	if(arr[n] < 0) {
		while(!q.empty()){
			arr[q.front()] = n;
			q.pop();
		}
		return n;
	}
	else {
		q.push(n);
		return n = find(arr[n], arr);
	}
}

void unioon(int a, int b, int arr[], int *answer, int cost){
	if(arr[a] > arr[b]) a^=b^=a^=b;
			
	arr[a] += arr[b];
	arr[b] = a;
			
	*answer += cost;
}

int main(){
	int answer = 0;// �ּҷ� ����Ǵ� ����� �� 
	vector<vector<int>> v; // x, y, cost
	int n = 9;
	v.push_back({0,1,4}); // 0�� 1�� �����̰� 4�� ��� 
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
	
	sort(v.begin(), v.end(), cmp); // ��뿡 ���� ������������ ��sort 
	
	int len = v.size();
	int parent[n];// ���� �ֻ����� �ִ� �θ��带 �˷��ִ� �迭
	
	init_set(parent, n);
	
	for(int i=0;i<len;i++){
		int a_parent = find(v[i][0], parent);
		int b_parent = find(v[i][1], parent);
		int cost = v[i][2];
		
		if(a_parent != b_parent) unioon(a_parent, b_parent, parent, &answer, cost);
	}
	
	cout << answer << endl;
	
	for(int i=0;i<n;i++){
		cout << parent[i] << " ";
	}
	cout << endl;
	
}
