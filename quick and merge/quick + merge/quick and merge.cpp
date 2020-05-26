#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

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

void merge(vector<int> &v, int low, int middle, int high){
	int n1=low, n2=middle+1, s = low;
	int sorted[MAX];
	
	while(n1 <= middle && n2 <= high){
		if(v[n1] < v[n2]) sorted[s++] = v[n1++];
		else sorted[s++] = v[n2++];
	}
	if(n1 > middle) while(n2 <= high) sorted[s++] = v[n2++];
	else while(n1 <= middle) sorted[s++] = v[n1++];
	
	for(int i=low;i<=high;i++) v[i] = sorted[i];
}

void mergesort(vector<int> &v, int low, int high){
	/*
	3. ���� 1������ ������ �ʾƵ� �ɵ� ��2~3������ ������ �ɵ�. 
	*/
	
	if(low < high){
		// Ȥ�ó� (high+low) ���� �����÷ο찡 �߻��� �� �ֱ� ������
		//���� �����̳� ���������� ������ ä�� 
		int middle = low + (high - low) / 2;
		mergesort(v, low, middle);
		mergesort(v, middle+1, high);
		merge(v, low, middle, high);
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
	vector<int> q = v;
	vector<int> m = v;
	
	
	float s1 = clock();
	quicksort(q,0,howManyNumber-1);
	float f1 = clock();
	
	
	float s2 = clock();
	mergesort(m,0,howManyNumber-1);
	float f2 = clock();

	cout << (float)(f1-s1)/CLOCKS_PER_SEC << "�� �ɷȽ��ϴ�. "<< endl;
	cout << (float)(f2-s2)/CLOCKS_PER_SEC << "�� �ɷȽ��ϴ�. "<< endl;
}
