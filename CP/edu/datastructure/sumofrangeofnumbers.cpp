#include <iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<stack>
#include <map>
#include<climits>
#include<iomanip>
//read question properly(ixed is used to avoid exponential )
#define ld long double
#define ll long long 
#define lli long long int 
 
using namespace std;

const long long N=228228;

vector<long long> tree[N];//tree


int isprime(lli a){
    for(int i=2;i*i<=a;i++){
        if(a%i==0)
            return 0;
    }
    return 1;
}

lli gcd (lli a, lli b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//array manuplation

int main() {
    long int n,q,a,b,sum,i,j,maximum=0,x=0;

    cin>>n>>q;
    long int *arr=new long int[N+1]();

    for(i=0;i<q;i++)
    {
        cin>>a>>b>>sum;
        arr[a]+=sum;
        if((b+1)<=n) arr[b+1]-=sum;
    }

    for(i=1;i<=n;i++)
    {
       x=x+arr[i];
       maximum=max(maximum,x);

    }

    cout<<maximum;
    return 0;
}
   