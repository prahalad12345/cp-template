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

void bit(lli num){
    num=num | 1<<5;
    cout<<num<<endl;
    
}
int main(){
    lli num=20;
    bit(num);
}