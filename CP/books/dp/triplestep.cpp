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
#include<numeric>
#include<queue>
//read question properly(fixed is used to avoid exponential )
#define ld long double
#define ll long long 
#define lli long long int 
#define mods  1000000007
#define vpl vector < pair < lli,lli > > 
#define vli vector <lli>
using namespace std;
#define N 10000001
#define pb push_back 

lli dp(lli n){
    lli arr[n+1];
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(lli i=3;i<=n;i++)
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    return arr[n];
}
int main(){
    lli n;
    cin>>n;
    cout<<dp(n)<<endl;
}