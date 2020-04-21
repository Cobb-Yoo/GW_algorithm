#include <iostream>
#include <algorithm>
using namespace std;

void init_set(int *arr, int n){
	for(int i=0;i<n;i++) arr[i] = i;
}
bool cmp(vector<int> a, vector<int> b){
	if(a[2] == b[2]) return a[0] < b[0];
	return a[2] < b[2];
}

int find(int n, int *arr){
	if(n == arr[n]) return n;
	else return n = find(arr[n], arr);
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
		int startPoint_parent = find(v[i][0], parent);
		int destination_parent = find(v[i][1], parent);
		int cost = v[i][2];
		if(startPoint_parent != destination_parent) { 
			parent[startPoint_parent] = destination_parent; // union();
			answer += cost; // cost
		}
	}
	
	for(int i=0;i<n;i++) cout << i << " ";
	cout << " ���� ��ȣ�Դϴ�.\n";
	for(int i=0;i<n;i++) cout << parent[i] << " ";
	cout << " ���� ���Դϴ�.\n";
	cout << "��� ��带 ������ �� �䱸�Ǵ� ���� ���� ����� "<<answer << " �Դϴ�.\n";
	
}
