   #include <iostream>
    #include<cmath>
    #include<vector>
    #include<string>
    #include<algorithm>
    #include<cstdlib>
    #include<set>
    #include<stack>
    #include <map>
    #include<climits>
    #include<iomanip>
    #include<numeric>
    #include<queue>
    #include <stdio.h>
    #include <stdlib.h>
    #include <cstring>
    #define ld long double
    #define ll long long 
    #define lli long long int 
    #define mods  1000000007
    #define mods2  998244353
    #define vpl vector < pair < lli,lli > > 
    #define vli vector <lli>
    using namespace std;
     
    #define pb push_back 
    #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
     
     
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
        int countoccurrences(int arr[], int n, int x)
        {
            int res = 0;
            for (int i=0; i<n; i++)
                if (x == arr[i])
                res++;
            return res;
        }
        
    }
    using namespace number_theory;
     
     
    void crossoff(bool* flag,lli prime,lli maxi){
        for(lli i=prime*prime;i<=maxi;i+=prime){
            flag[i]=false;
        }
    }
     
    lli getnextprime(bool* flag,lli prime,lli maxi){
        int next=prime+1;
        while(next<=maxi && !flag[next]){
            next++;
        }
        return next;
    }
     
    vli sieveoferatosthenes(lli maxi){
        bool flag[maxi+1];
        vli primenum;
        primenum.pb(2);
        flag[0]=false;
        flag[1]=false;
        
        for(lli i=2;i<=maxi;i++)
            flag[i]=true;
        int prime=2;
        while(prime<=sqrt(maxi)){
            crossoff(flag,prime,maxi);
            prime=getnextprime(flag,prime,maxi);
            primenum.pb(prime); 
        }
        return primenum;
    }
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
     
    map<lli,lli> xs,ys;
     
    lli calc(lli n){
        lli calculation=5*(binpow(2,n)-1);
        return calculation;
    }
    /*
    vector<lli> fillminfactor(lli n){
        vector<lli>  minfactors(n+1,-1);
        for(lli i=1;i<=n;i++){
            minfactors[i]=i;
        }
        for(lli i=2;i*i<=n;i++){
            if(minfactors[i]==i){
                for(lli j=i*i;j<=n;j+=i){
                    if(minfactors[j]==j)
                        minfactors[j]=i;
                }
            }
        }
        return minfactors;
    }
     
    void dfs(lli v,set<lli> nots) {
        visited[v] = true;
        countt++;
        for (int u : graph[v]) {
            if(nots.find(u)==nots.end()){
                if (!visited[u]){
                    dfs(u,nots);
                }
            }
     
        }
    }
    */
     
    string inttobit(lli n){
        string bit="";
        while(n!=0){
            char val=48+(n%2);  
            bit=bit+val;
            n/=2;
        }
        return bit;
    }
     
 
struct dsu {
    int siz;
    vector<int> par;
 
    dsu(int n){
        siz= n;
        par.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]= i;
        }     
    }
 
    int find(int i){
        // return parent
        return (par[i]==i)?i:(find(par[i]));
    }
 
    void merge(int a,int b){
        a= find(a);
        b= find(b);
        if(a!=b){
            par[b]=a;
        }
    }
 
};
 
    int main()
    {
        fast_io;
        lli n,m,o;
        cin>>n>>m>>o;
        dsu mocha(n+1),diana(n+1);
        for(int i=0;i<m;i++){
            lli a,b;
            cin>>a>>b;
            mocha.merge(a,b);
        }
        for(int j=0;j<o;j++){
            int a,b;
            cin>>a>>b;
            diana.merge(a,b);
        }
        vpl ans;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(mocha.find(i)==mocha.find(j) || diana.find(i)==diana.find(j)){
                    continue;
                }
                ans.pb(make_pair(i,j));
                mocha.merge(i,j);
                diana.merge(i,j);
            } 
        }
        cout<<ans.size()<<endl;
        for(lli i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    } 
