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

vector<long long> tree[N];//tree


namespace number_theory{
    
    int isprime(lli a){
        for(int i=2;i*i<=a;i++){
            if(a%i==0)
                return 0;
            }
        return 1;
    }
    lli binpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a ;
            a = a * a ;
            b >>= 1;
        }
        return res;
    }

    lli binmod(lli a, lli b, lli m) {
        a %= m;
        long long res = 1;
        while (b  > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    int powersimple(int a, int b){
        int res=1;
        while(b>0){
            if(b&1)
            {res=(res*a);
            b--;}
            a=(a*a);
            b>>=1;
        }
        return res;
    }
    
void SieveOfEratosthenes(lli n, bool prime[],
                         bool primesquare[], lli a[])
{

    for (lli i = 2; i <= n; i++)
        prime[i] = true;

    for (lli i = 0; i <= (n * n + 1); i++)
        primesquare[i] = false;
 
    // 1 is not a prime number
    prime[1] = false;
 
    for (lli p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then
        // it is a prime
        if (prime[p] == true) {
            // Update all multiples of p
            for (lli i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    lli j = 0;
    for (lli p = 2; p <= n; p++) {
        if (prime[p]) {

            a[j] = p;
            primesquare[p * p] = true;
            j++;
        }
    }
}
 

lli countDivisors(lli n)
{
    if (n == 1)
        return 1;
 
    bool prime[n + 1], primesquare[n * n + 1];
 
    lli a[n]; // for storing primes upto n

    SieveOfEratosthenes(n, prime, primesquare, a);
 

    lli ans = 1;
 
    // Loop for counting factors of n
    for (lli i = 0;; i++) {
        // a[i] is not less than cube root n
        if (a[i] * a[i] * a[i] > n)
            break;
 
        lli cnt = 1; 
        while (n % a[i] == 0) 
        {
            n = n / a[i];
            cnt = cnt + 1;
        }
 
        ans = ans * cnt;
    }
 
    // if a[i] is greater than cube root of n
 
    // First case
    if (prime[n])
        ans = ans * 2;
 
    // Second case
    else if (primesquare[n])
        ans = ans * 3;
 
    // Third case
    else if (n != 1)
        ans = ans * 4;
 
    return ans; // Total divisors
}
    lli ncr(lli n,lli k) {
        lli ans=1;
        if(k>n-k) {
            k=n-k;
        }
        for(int i=1;i<=k;i++) {
            ans*=(n-i+1),ans/=i;
        }
        return ans;
    }
   
    int power(int r,int y,int p) {
        int res = 1;
        r = r % p;
        while (y > 0) {
            if (y & 1)
                res = (res * r) % p;
            y = y >> 1;
            r = (r * r) % p;
        }
        return res;
    }
   
    int modInverse(int n, int p) {
        return power(n, p - 2, p);
    }
   lli divisionmodulo(lli a,lli b,lli mod){
       return (a* binpow(b,mod-2))%mod;
   }
   
    lli gcd (lli a, lli b) {
        if (b == 0)
            return a;
        else
            return gcd (b, a % b);
    }
    
}
using namespace number_theory;


lli pair_sum(lli arr[], lli size, lli x){
   lli arr_0 = 0;
   lli arr_1 = size-1;
   lli count = 0;
   while(arr_0 < arr_1){
      if (arr[arr_0] + arr[arr_1] <= x ){
         count = count + (arr_1 - arr_0);
         arr_0++;
      }
      else{
         arr_1--;
      }
   }
   return count;
}

map<lli,lli> element;

vector<vli> graph(26), dist(26, std::vector<lli> (26)), d(26, std::vector<lli> (26));
vector<lli> vis(26);
queue<lli> q;


void bfs(lli start,lli end){
    while(!q.empty())
        q.pop();
    q.push(start);
    vis[start]=1;
    while(!q.empty()){
        lli element1=q.front();
        q.pop();
        for(lli x : graph[element1]){
            if(!vis[x]){
                vis[x]=1;
                q.push(x);
                d[start][x]=d[start][element1]+1;
                if(x==end)
                    return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin>>t;
    lli copyt=t;
    while(t--){
        lli k;
        string s;
        cin>>s>>k;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                graph[i].clear();
                vis[i]=0;
                dist[i][j]=0;
                d[i][j]=0;
            }
        }
        for(lli i=0;i<k;i++){
            char x,y;
            cin>>x>>y;
            graph[x-'A'].pb(y-'A');
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                bfs(i,j);
                dist[i][j]=d[i][j];

                for(int k=0;k<=25;k++) {
                    for(int l=0;l<=25;l++) {
                        
                        vis[k]=0;
                        d[k][l]=0;
                    }
                }
            }
        }
        lli mini=1e12;
        for(lli i=0;i<26;i++){
            char x='A'+i;
            lli ans=0;
            lli flag=0;
            for(lli j=0;j<s.length();j++){
                if(x==s[j])
                    continue;
                if(dist[s[j]-'A'][x-'A'])
                    ans+=dist[s[j]-'A'][x-'A'];
                else {
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                mini=min(mini,ans);
            }
        }
        if(mini==1e12)
            mini=-1;
        cout<<"#Case "<<copyt-t<<": "<<mini<<endl;
    }
}
    