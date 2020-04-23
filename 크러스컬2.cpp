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
	
	int datas[n][n] = {{0,4,0,0,0,0,0,8,0},
					{4,0,8,0,0,0,0,11,0},
					{8,0,0,7,0,4,0,0,2},
					{0,0,7,0,9,14,0,0,0},
					{0,0,0,9,0,10,0,0,0},
					{0,0,4,14,10,0,2,0,0},
					{0,0,0,0,0,2,0,1,0},
					{8,11,0,0,0,0,1,0,7},
					{0,0,2,0,0,0,0,7,0}};
					
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i == j || datas[i][j] == 0) continue;
			
			v.push_back({i,j,datas[i][j]});
			datas[i][j] = 0;
			datas[j][i] = 0;
		}
	}
	
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
