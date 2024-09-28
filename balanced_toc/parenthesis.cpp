#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<time.h>
using namespace std;
int main(){
	ofstream myfile1("input00.txt");
	ofstream myfile2("output00.txt");
	int test = (rand() % (10-1+1)) + 1;
	myfile1<<to_string(test)<<"\n";
	char arr[2] = {'(', ')'};
	char lang[test];
	for(int i=0;i<test;i++){
		char[i] = arr[rand()%2];
	}

	return 0;
}