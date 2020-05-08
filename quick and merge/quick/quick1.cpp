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
	int howManyNumber; // 배열의 크기
	cout << "배열의 크기를 설정하세요. : ";
	cin >>  howManyNumber;
	
	
	vector<int> v(howManyNumber);
	
	for(int i=0;i<howManyNumber;i++) v[i] = i+1;
	
	for(int i=0;i<MAX;i++){ // 시간은 걸리더라도 최대한 잘 섞이도록 많이 섞음. 
		int x = rand() % howManyNumber;
		int y = rand() % howManyNumber;
		
		if(x != y) v[x] ^= v[y] ^= v[x] ^= v[y];
		
		if(i == 1000000 || i == 2000000 || i == 3000000 || i == 400000 || i == 5000000 || i == 6000000 || i == 7000000  || i == 8000000  || i == 9000000  || i == 10000000){
			system("cls");
			cout << i/100000 << "% 섞기 완료되었습니다.\n";
		}
	}
	
	// 지금 소스에서는 피벗의 값을 맨 왼쪽으로 고정함.
	// 배열의 요소의 갯수가 임계값 보다 작은 경우도 생각하지 않음. 
	
	cout << " 정렬 전 입니다.\n";
	for(int i=0;i<howManyNumber;i++) cout << v[i] << " ";
	cout << endl;
	float s = clock();
	quicksort(v,0,howManyNumber);
	float f = clock();
	
	cout << " 정렬 후 입니다.\n";
	for(int i=0;i<howManyNumber;i++) cout << v[i] << " ";
	cout << endl;
	
	cout << (float)(f-s)/CLOCKS_PER_SEC << "초 걸렸습니다. "<< endl;
}
