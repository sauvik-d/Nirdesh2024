//
// Created by sauvik on 14/6/24.
//
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<time.h>
#define ULLI unsigned long long int
#define loop(i, n) for(ULLI i=0;i<n;i++)
using namespace std;
ULLI trailZero(ULLI n){
    ULLI count=0;
    for(ULLI i=5; n/i>0; i*=5) count+=n/i;
    return count;
}
int main(){
    srand(time(0));
    ULLI test = rand() % 15 + 1;
    cout<<"Trailing zeros of factorial of the number "<<test<<" is: "<<trailZero(test);
    cout<<endl;
    return 0;
}