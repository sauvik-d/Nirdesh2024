#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<time.h>
#include<debugger.h>
#define loop(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	srand(time(0));
	ofstream myfile1("input1.txt");
	ofstream myfile2("output1.txt");
	int input;
	cin>>input;
	int test = (rand() % (1-1+1)) + 1;
	cout<<test<<endl;
	int n = (rand() % (50-5+1))+1;
	vector<char> alphabets(26);
	//= {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int l = 97;
	loop(i, 26){
		alphabets[i] = char(l); l++;
		if(l == 122) break;
	}
	vector<char> mainarray(n);
	for(int i=0;i<n;i++){
		int random = rand() % 26;
		mainarray[i] = alphabets[random];
	}
	cout<<"Original Main Array is: "<<endl;
	loop(i, n) cout<<mainarray[i]<<" ";
	cout<<endl;
	sort(mainarray.begin(), mainarray.end());
	vector<char> priorarray;
	cout<<"Sorted Main Array is: "<<endl;
	loop(i, n) cout<<mainarray[i]<<" ";
	cout<<endl;
	loop(i, n-1){
		if(mainarray[i] != mainarray[i+1]){
			priorarray.push_back(mainarray[i]);
		}
	}
	priorarray.push_back(mainarray[n-1]);
	cout<<"Array with unique elements is: "<<endl;
	loop(i, n) cout<<priorarray[i]<<" ";
	cout<<endl;
	srand(time(0));
	vector<int> priority;
	loop(i, priorarray.size()){
		int random2 = rand() % priorarray.size();
		priority.push_back(random2);
	}
	loop(i, priority.size()) cout<<priority[i]<<" ";
	cout<<endl;
	return 0;
}