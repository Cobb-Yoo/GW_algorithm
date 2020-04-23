#include <iostream>
#include <algorithm>
using namespace std;
 
void init_set(int *arr, int n){
	for(int i=0;i<n;i++) arr[i] = -1;
}

bool cmp(vector<int> a, vector<int> b){
	return a[2] < b[2];
}

int find(int n, int *arr){
	if(arr[n] < 0) return n;
	else return n = find(arr[n], arr);
}

void unioon(int a, int b, int arr[], int *answer, int cost){
	if(arr[a] > arr[b]) a^=b^=a^=b;
			
	arr[a] += arr[b];
	arr[b] = a;
			
	*answer += cost;
}

int main(){
	int answer = 0;// 최소로 연결되는 비용의 합 
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
	
	sort(v.begin(), v.end(), cmp); // 비용에 따른 오름차순으로 퀵sort 
	
	int len = v.size();
	int parent[n];// 가장 최상위에 있는 부모노드를 알려주는 배열
	
	init_set(parent, n);
	
	for(int i=0;i<len;i++){
		int a_parent = find(v[i][0], parent);
		int b_parent = find(v[i][1], parent);
		int cost = v[i][2];
		
		if(a_parent != b_parent) unioon(a_parent, b_parent, parent, &answer, cost);
	}
	
	for(int i=0;i<n;i++) cout << i << " ";
	cout << " 정점 번호입니다.\n";
	for(int i=0;i<n;i++) cout << parent[i] << " ";
	cout << " 정점 값입니다.\n";
	cout << "모든 노드를 연결할 때 요구되는 가장 작은 비용은 "<<answer << " 입니다.\n";
}
