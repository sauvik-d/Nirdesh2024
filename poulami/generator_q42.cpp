#include<bits/stdc++.h>
#include<vector>
#include<time.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
using namespace std;
int main(){
    srand(time(0));
    ofstream myfile1("input1.txt");
    ofstream myfile2("output1.txt");
    int test = rand() % 1 + 1;
    while(test--){
        int n = rand() % 10 + 1;
        int k = rand() % n + 1;
        myfile1<<to_string(n)+" "+to_string(k);
        //int n = 7;
        //int k = 3;
        vector<int> v1(n);
        for(int i=0;i<n;i++){
            v1[i] = rand() % 10 + 1;
        }
        myfile1<<"\n";
        for(int i=0;i<n;i++){
            myfile1<<to_string(v1[i])+"\n";
        }
        //int v1[7] = {1, 15, 7, 9, 2, 5, 10};
        vector<int> dp(7, -1);
        for(int i=0;i<n;i++){
            int cur = v1[i];
            for(int j=i;j>=(i-k+1) && ~j;j--) {
                cur = max(cur, v1[j]);
                if(j > 0){
                    dp[i] = max(dp[i], dp[j-1] + (cur*(i-j+1)));
                }
                else{
                    dp[i] = max(dp[i], cur*(i-j+1));
                }
            }
        }
        cout<<dp[n-1]<<endl;
        myfile2<<to_string(dp[n-1]);
    }
    return 0;
}