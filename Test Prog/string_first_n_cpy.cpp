#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char s1[] = {"west"};
	char s2[] = {"wd"};
	strncpy(s1,s2,3);
	cout<<s1;
}
//strncpy(dest, source,n);
