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

vpl bath;
lli  dp(lli r,lli c,vpl offlimit,lli x,lli y){
    if(binary_search(offlimit.begin(),offlimit.end(),make_pair(x,y)))
        return 1e15;
    if(x==r && y==c)
        return 0;
    if(x+1<=r && y+1<=c){
        bath.pb(make_pair(x,y));
        return min(dp(r,c,offlimit,x+1,y)+1 , dp(r,c,offlimit,x,y+1)+1);
    }
    else if(x+1<=r)
        return dp(r,c,offlimit,x+1,y)+1;
    else if(y+1<=c)
        return dp(r,c,offlimit,x,y+1)+1;    
}
int main(){
    lli r,c;
    cin>>r>>c;
    lli n;
    cin>>n;
    vpl offlimit;
    for(lli i=0;i<n;i++){
        lli x,y;
        cin>>x>>y;
        offlimit.pb(make_pair(x,y));
    }
    vpl path;
    lli count=dp(r,c,offlimit,1,1);
    cout<<count<<endl;
    //cout<<bath.size()<<endl;
}