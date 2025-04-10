#include<stdio.h>
#include<math.h>
// use runtime 2 second
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long int t;
    scanf("%lld", &t);
    while(t--){
        long x, y;
        scanf("%ld %ld", &x, &y)
        printf("%ld", long(pow(y+1, x)));
    }
    return 0;
}
