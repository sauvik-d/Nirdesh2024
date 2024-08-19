#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<time.h>
//#include<debugger.h>
#define loop(i, n) for(unsigned long long int i=0;i<n;i++)
#define ULLI unsigned long long int
using namespace std;
ULLI max(ULLI a, ULLI b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}
ULLI func(vector<char> mainarray, vector<char> priorarray, vector<ULLI> priority, ULLI k){ // function to solve the actual task of the problem
	vector<char> v1;
	map<char, ULLI> mp;
	for(ULLI i=0;i<priority.size();i++){
		mp[priorarray[i]] = priority[i];
	}
	ULLI sum = 0;
	loop(i, mainarray.size()){
		if(find(v1.begin(), v1.end(), mainarray[i]) != v1.end()){ // if the element is present in array
			sum += 3;
		}
		else{ // if the element is not present in array
			if(v1.size() < k){ // if array is not full then insert
				v1.push_back(mainarray[i]);
				sum += 5;
			}
			else{ // if the array is full then omit the element with least priority
				ULLI mx = 0;
				loop(j, v1.size()){
					mx = max(mx, mp[v1[j]]);
				}
				// delete the value from v1[] and replace it with the incoming value
				for (auto& it : mp) {
        			if (it.second == mx) {
            			loop(z, v1.size()){
            				if(v1[z] == it.first){
            					v1[z] = mainarray[i];
            				}
            			}
        			}
    			}
				sum += 5;
			}
		}
	}
	cout<<endl;
	cout<<"The total cost is: "<<sum<<endl;
	//myfile2<<to_string(sum)+"\n";
	return sum;
}
int main(){
	srand(time(0));
	ofstream myfile1("input01.txt");
	ofstream myfile2("output01.txt");
	ULLI input;
	//cin>>input;
	ULLI test = (rand() % (1-1+1)) + 1;
	//cout<<test<<endl;
	//ULLI n = (rand() % (10-1+1))+1;
	//ULLI k = rand() % n + 1;
	ULLI n = (rand() % 10000) + 1;
	ULLI k = (rand() % n) + 1;
	cout<<"Size of the frame is: "<<k<<endl;
	vector<char> alphabets(26);
	//= {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	ULLI l = 97;
	loop(i, 26){
		alphabets[i] = char(l); l++;
		if(l == 123) break;
	}
	/*
	loop(i, 26){
		cout<<alphabets[i]<<" ";
	}
	*/
	//cout<<endl;
	vector<char> mainarray(n);
	for(ULLI i=0;i<n;i++){
		ULLI random = rand() % 26;
		mainarray[i] = alphabets[random];
	}
	cout<<"Original Main Array is:"<<endl;
	loop(i, n) cout<<mainarray[i]<<" "; // prints the given sequence of input
	cout<<endl;



	for (char ch : mainarray) {
        myfile1<<ch<<" ";
    }
    myfile1<<"\n";

	vector<char> dupliarray(n);
	loop(i, n) dupliarray[i] = mainarray[i];
	sort(dupliarray.begin(), dupliarray.end());
	vector<char> priorarray; // contains the elements of the priority list
	cout<<"Sorted Duplicate Array is:"<<endl;
	loop(i, n) cout<<dupliarray[i]<<" ";
	cout<<endl;
	loop(i, n-1){ // extracting the unique characters from the given input sequence
		if(dupliarray[i] != dupliarray[i+1]){
			priorarray.push_back(dupliarray[i]);
		}
	}
	priorarray.push_back(dupliarray[n-1]);
	cout<<"Array with unique elements is:"<<endl;
	loop(i, priorarray.size()) cout<<priorarray[i]<<" "; 
	cout<<endl;
	srand(time(0));
	vector<ULLI> priority; //contains the priorities of different elements
	while(priority.size() != priorarray.size()){
		ULLI random2 = rand() % priorarray.size() + 1;
		if(find(priority.begin(), priority.end(), random2) == priority.end()){
			priority.push_back(random2);
		}
	}
	loop(i, priority.size()) cout<<priority[i]<<" ";



	for(char ch: priorarray){
		myfile1<<ch<<" ";
	}
	myfile1<<"\n";
	loop(i, priority.size()) myfile1<<to_string(priority[i])+" ";
	myfile1<<"\n";



	ULLI sum = func(mainarray, priorarray, priority, k);
	cout<<endl;
	myfile2<<to_string(sum)+"\n";
	return 0;
}