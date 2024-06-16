#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// use runtime 2 second
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long int t;
    cin>>t;
    while(t--){
        long x, y;
        cin>>x>>y;
        cout<<long(pow(y+1, x))<<endl;
    }
    return 0;
}
