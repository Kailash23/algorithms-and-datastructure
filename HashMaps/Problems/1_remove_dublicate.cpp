/*
   Remove Duplicates from an array
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicates(int *a, int size) {
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++) {
        if (seen.count(a[i]) > 0) {
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}

int main() {
    int a[] = {1, 2, 3, 3, 2, 1, 4, 3, 6, 5, 5};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> output = removeDuplicates(a, n);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
}
