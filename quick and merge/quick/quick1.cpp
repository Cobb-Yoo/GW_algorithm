#include <iostream>
#include <vector>
#include <cstdlib> // rand()
#include <ctime>
using namespace std;

int MAX= 10000001;

int partition(vector<int> &v, int low, int high){
	int j = low;
	for(int i=low+1;i<=high;i++){
		if(v[i] < v[low]){
			j++;
			int tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
		}
	}
	int tmp = v[low];
	v[low] = v[j];
	v[j] = tmp;
	
	return j;
}

void quicksort(vector<int> &v, int low, int high){
	if(low < high){
		int pivot = partition(v, low, high);
		quicksort(v,low,pivot-1);
		quicksort(v,pivot+1,high);
	}
}

int main(){
	srand((unsigned)time(NULL));
	int howManyNumber; // �迭�� ũ��
	cout << "�迭�� ũ�⸦ �����ϼ���. : ";
	cin >>  howManyNumber;
	
	
	vector<int> v(howManyNumber);
	
	for(int i=0;i<howManyNumber;i++) v[i] = i+1;
	
	for(int i=0;i<1000;i++){ // �ð��� �ɸ����� �ִ��� �� ���̵��� ���� ����. 
		int x = rand() % howManyNumber;
		int y = rand() % howManyNumber;
		
		if(x != y){
			int tmp = v[x];
			v[x] = v[y];
			v[y] = tmp;
		}
	}
	
	// ���� �ҽ������� �ǹ��� ���� �� �������� ������.
	// �迭�� ����� ������ �Ӱ谪 ���� ���� ��쵵 �������� ����. 
	
	float s = clock();
	quicksort(v,0,howManyNumber-1);
	float f = clock();
	
	cout << (float)(f-s)/CLOCKS_PER_SEC << "�� �ɷȽ��ϴ�. "<< endl;
}
