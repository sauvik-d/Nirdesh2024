#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<time.h>
#define ULLI unsigned long long int
#define loop(i, n) for(unsigned long long int i=0;i<n;i++)
using namespace std;
int main(){
	srand(time(0));
	//ofstream myfile1("input1.txt");
	//ofstream myfile2("output1.txt");
	ULLI test = 1; //rand() % 100 + 1; // no. of test cases
	while(test--){
		ULLI n = rand() % 10 + 1; // size of the input sequence
		vector<int> numbers(n);
		//int numbers[7] = {2, 6, 8, 3, 4, 5, 1};
		loop(i, numbers.size()) numbers[i] = rand() % 10 + 1;
		cout<<"The input sequence is:"<<endl;
		loop(i, numbers.size()) cout<<numbers[i]<<" ";
		cout<<endl;
		vector<ULLI, ULLI> LIS;
		loop(i, numbers.size()){
            if(LIS[i].empty() || LIS[i][LIS[i].size()-1] < numbers[i]){
                LIS[i].push_back(numbers[i]);
            }
            else{
                auto it = lower_bound(LIS[i].begin(), LIS[i].end(), numbers[i]);
                *it = numbers[i];
            }
            loop(j, LIS[i].size()) cout<<LIS[i][j]<<" "; // printing the longest increasing subsequences
            cout<<endl;
        }
        cout<<"The Longest Increasing Subsequences are: ";
        loop(i, LIS.size()){
        	loop(j, LIS[i].size()){
        		cout<<LIS[i][j]<<" ";
        	}
        	cout<<endl;
        }
        cout<<endl;
	}
	return 0;
}