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

void crossoff(bool* flag,int prime,lli maxi){
    for(lli i=prime*prime;i<=maxi;i+=prime){
        flag[i]=false;
    }
}

lli getnextprime(bool* flag,int prime,lli maxi){
    int next=prime+1;
    while(next<=maxi && !flag[next]){
        next++;
    }
    return next;
}

bool* sieveoferatosthenes(lli maxi){
    bool flag[maxi+1];
    flag[0]=false;
    flag[1]=false;
    
    for(lli i=2;i<=maxi;i++)
        flag[i]=true;
    int prime=2;
    while(prime<=sqrt(maxi)){
        crossoff(flag,prime,maxi);
        prime=getnextprime(flag,prime,maxi);
        cout<<prime<<endl;
        //cout<<flag[prime]<<endl;
    }
    cout<<flag[7]<<7<<endl;
    for(lli i=1;i<=maxi;i++){
        if(flag[i]==true)
           cout<<i<<endl;
    }
}


int main(){
  
    bool* mode=sieveoferatosthenes(100);
}