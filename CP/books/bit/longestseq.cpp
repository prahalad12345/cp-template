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
    lli n;
    cin>>n;
    string bit="";
    while(n!=0){
        char val=48+(n%2);
        
        bit=bit+val;
        n/=2;
    }
    reverse(bit.begin(),bit.end());
    cout<<bit<<endl;
    vector<lli> ones;
    lli sum=0;
    for(lli i=0;i<bit.length();i++){
        if(bit[i]=='1'){
            sum++;
        }
        else{
            ones.push_back(sum);
            sum=0;
        }
    }
    ones.push_back(sum);

    sort(ones.begin(),ones.end());
    cout<<ones[ones.size()-1]+ones[ones.size()-2]+1<<endl;;
    return 0;
}