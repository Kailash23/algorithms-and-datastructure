/*
   Code : Print Intersection

   Given two random integer arrays, print their intersection. That is, print all
   the elements that are present in both the given arrays.
   Input arrays can contain duplicate elements.
   Note : Order of elements are not important

    Input  :
    6
    2 6 8 5 4 3
    4
    2 3 4 7
    Output  :
    2
    4
    3

    Input  :
    4
    2 6 1 2
    5
    1 2 3 4 2
    Output  :
    2
    2
    1

 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void intersection(int input1[], int input2[], int size1, int size2) {
    map<int, int> map;
    for (int i = 0; i < size1; i++) {
        map[input1[i]]++;
    }
    for (int i = 0; i < size2; i++) {
        if (map[input2[i]] > 0) {
            map[input2[i]]--;
            cout << input2[i] << endl;
        }
    }
}

int main() {
    int ar1[] = {2, 4, 6, 8, 0, 2};
    int ar2[] = {2, 5, 7, 9, 1, 0, 2};
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    intersection(ar1, ar2, n1, n2);
}
