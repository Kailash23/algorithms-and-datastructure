/*
   Program to check whether array is sorted or not.
 */

#include <iostream>
using namespace std;

bool is_sorted(int a[], int size){
	if(size == 0 || size == 1) {
		return true;
	}
	if(a[0] > a[1]) {
		return false;
	}
	return is_sorted(a + 1, size - 1);
}

int main(){
	int arr[] = {2,5,6,8,9,10,1};
	int n = sizeof(arr) / sizeof(arr[0]);
	bool is = is_sorted(arr, n);
	is ? cout << "Array is sorted! " : cout << "Array is not sorted" << endl;
}

/*
   Array is not sorted
 */

/*
    bool is_sorted(int a[], int size){
        if(size == 0 || size == 1) {
            return true;
        }
        bool isSmallerSorted = is_sorted(a + 1,size - 1);
        if(!isSmallerSorted) {
            return true;
        } else {
            return false;
        }
    }
 */
