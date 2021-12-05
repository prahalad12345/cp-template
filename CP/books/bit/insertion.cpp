#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<stack>
#include <iostream>
#include <map>
#include<climits>
#include <queue>
//read question properly
#define ld long double
#define ll long long 
#define lli long long int 

using namespace std;

int main(){
    lli i,j,n,m;
    cin>>n>>m;
    cin>>i>>j;
    m=m<<i;
    n=n|m;
    cout<<n<<endl;
    return 0;
}