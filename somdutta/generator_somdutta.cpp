#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<time.h>
using namespace std;
int main(){
	srand(time(0));
	ofstream myfile1("input8.txt");
	ofstream myfile2("output8.txt");
	long long int ub = 10000000, lb = 1000000;
	long long int ubx = 15, lbx = 1;
	long long int uby = 18, lby = 1;
	long long int t = (rand() % (ub - lb + 1)) + lb;
	myfile1<<to_string(t);
	myfile1<<"\n";
	while(t--){
		long long int x = (rand() % (ubx - lbx + 1)) + lbx;
		//long long int x = 18;
		long long int y = (rand() % (uby - lby + 1)) + lby;
		//long long int y = 15;
		myfile1<<to_string(x)+" "+to_string(y)<<endl;
		unsigned long long int z = 1;
		for(long long int i = 1; i<=x;i++){
			z *= (1+y);
		}
		myfile2<<to_string(z)<<endl;
	}
	return 0;
}