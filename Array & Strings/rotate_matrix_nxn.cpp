#include<iostream>
using namespace std;

const int MATRIX_SIZE = 3;

void PrintMatrix(int m[][MATRIX_SIZE]){
	for(int i=0;i<MATRIX_SIZE;i++){
		for(int j=0;j<MATRIX_SIZE;j++){
			cout<<m[i][j];
			if(m[i][j]<10)
				cout<<"     ";
			else if(m[i][j]<100)
				cout<<"    ";
			else
			 	cout<<"   ";

		}
		cout<<endl;
	}
	cout<<"-------------------------------------\n";
}

void Swap(int& i, int& j){
	int temp = i;
	i = j;
	j = temp;
}

int main(){
	int m[MATRIX_SIZE][MATRIX_SIZE];
	int count = 0;
	int level = 0;
	int last = MATRIX_SIZE-1;
	int totNumOfLevels = MATRIX_SIZE/2;

	for(int i=0;i<MATRIX_SIZE;i++){
		for(int j=0;j<MATRIX_SIZE;j++){
			m[i][j] = count++;
		}
	}
	cout<<"---------- Original Matrix ----------\n";
	PrintMatrix(m);

	while(level<totNumOfLevels){
		// //clock
		// for(int i=last;i<level;i++){
		// 	Swap(m[level][i],m[i][last]);
		// 	Swap(m[level][i],m[last][last-i+level]);
		// 	Swap(m[level][i],m[last-i+level][level]);
		// }
		//Anticlock
		for(int i=last;i>level;i--){
			Swap(m[level][i],m[last-i+level][level]);
			Swap(m[level][i],m[last][last-i+level]);
			Swap(m[level][i],m[i][last]);
		}
		++level;
		--last;
	}
	cout<<"---------- Rotated Matrix ----------\n";
	PrintMatrix(m);

}
