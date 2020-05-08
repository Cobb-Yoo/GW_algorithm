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
			v[i] ^= v[j] ^= v[i] ^= v[j];
		}
	}
	v[low] ^= v[j] ^= v[low] ^= v[j];
	
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
	
	for(int i=0;i<MAX;i++){ // �ð��� �ɸ����� �ִ��� �� ���̵��� ���� ����. 
		int x = rand() % howManyNumber;
		int y = rand() % howManyNumber;
		
		if(x != y) v[x] ^= v[y] ^= v[x] ^= v[y];
		
		if(i == 1000000 || i == 2000000 || i == 3000000 || i == 400000 || i == 5000000 || i == 6000000 || i == 7000000  || i == 8000000  || i == 9000000  || i == 10000000){
			system("cls");
			cout << i/100000 << "% ���� �Ϸ�Ǿ����ϴ�.\n";
		}
	}
	
	// ���� �ҽ������� �ǹ��� ���� �� �������� ������.
	// �迭�� ����� ������ �Ӱ谪 ���� ���� ��쵵 �������� ����. 
	
	cout << " ���� �� �Դϴ�.\n";
	for(int i=0;i<howManyNumber;i++) cout << v[i] << " ";
	cout << endl;
	float s = clock();
	quicksort(v,0,howManyNumber);
	float f = clock();
	
	cout << " ���� �� �Դϴ�.\n";
	for(int i=0;i<howManyNumber;i++) cout << v[i] << " ";
	cout << endl;
	
	cout << (float)(f-s)/CLOCKS_PER_SEC << "�� �ɷȽ��ϴ�. "<< endl;
}
