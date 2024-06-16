#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long fact(long n)
{
      if(n==0)
      return 1;
    long res = 1;
    for (long i = 2; i <= n; i++)
        res = res * i;
    return res;
}

long nCr(long n, long r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        unsigned long long int sum = 0;
        for(long i=0;i<=x;i++){
            sum += long(pow(y, x-i))*nCr(x, i);
        }
        cout<<sum<<endl;
    }
    return 0;
}
