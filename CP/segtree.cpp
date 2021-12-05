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
    #include <unordered_map>
    #define ld long double
    #define ll long long 
    #define lli long long int 
    #define mods  1000000007
    #define mods2  998244353
    #define inf  1e18
    #define vpl vector < pair < lli,lli > > 
    #define vli vector <lli>
    using namespace std;
     //memset(dp,(lli)1e17,k*n*sizeof(lli));
//values.erase(remove(values.begin(), values.end(), val), values.end());
      // above to remove based on value(all index)    
    /*std::cout << std::fixed;
    std::cout << std::setprecision(9);*/
    #define pb push_back 
    #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
     
     
     void usaco(string filename) {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
    namespace number_theory{
        
        int isprime(lli a){
            for(int i=2;i*i<=a;i++){
                if(a%i==0)
                    return 0;
                }
            return 1;
        }
        int countnum(lli x){
            lli count=0;
            for(int i=1;i*i<=(1+8*x);i++)
                count++;
            return count;
        }
        lli binpow(lli a, lli b) {
            lli res = 1;
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
            lli res = 1;
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
       
        lli modinverse(lli n, lli p) {
            return binmod(n, p - 2, p);
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
     
 
 bool secondval(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}

lli binarysearch(vli arr, int l, int r, int x)
{
     while (l <= r) {
        lli m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
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
        return (par[i]==i)?i:(par[i]=find(par[i]));
    }
 
    void merge(int a,int b){
        a= find(a);
        b= find(b);
        if(a!=b){
            par[b]=a;
        }
    }
};



struct node{
    lli arr[3];
};


void buildtree(vli &seg,string s,lli id,lli l,lli r){
    if(l==r){
        if(s[l]=='0')
            seg[id]=0;
        else 
            seg[id]=1;
        return;
    }
    lli mid=(l+r)/2;
    buildtree(seg,s,2*id,l,mid);
    buildtree(seg,s,2*id+1,mid+1,r);
    seg[id]=seg[2*id+1]+seg[2*id];
}
lli lazyquery(vector<node> &seg,vli &lazy,lli returnid,lli segstart,lli segend,lli qstart,lli qend){
    if(lazy[returnid]!=0){
        lli dx=lazy[returnid];
        lazy[returnid]=0;
        if(dx%3==1){
            swap(seg[returnid].arr[1],seg[returnid].arr[2]);
            swap(seg[returnid].arr[0],seg[returnid].arr[1]);
        }
        if(dx%3==2){
            swap(seg[returnid].arr[1],seg[returnid].arr[0]);
            swap(seg[returnid].arr[2],seg[returnid].arr[1]);
        }
        if(segstart!=segend){
            lazy[2*returnid]+=dx;
            lazy[2*returnid+1]+=dx;
        }

    }
    if(qstart>segend || qend<segstart){
        return 0;
    }
    if(segstart>=qstart && segend<=qend){
        return seg[returnid].arr[0];   
    }
    lli mid=(segstart+segend)/2;
    lli l=lazyquery(seg,lazy,2*returnid,segstart,mid,qstart,qend);
    lli r=lazyquery(seg,lazy,2*returnid+1,mid+1,segend,qstart,qend);
    return l+r;
}

void lazyupdate(vector<node> &seg,vli &lazy,lli returnid,lli segstart,lli segend,lli qstart,lli qend,lli val){
    if(lazy[returnid]!=0){
        lli dx=lazy[returnid];
        lazy[returnid]=0;
        if(dx%3==1){
            swap(seg[returnid].arr[1],seg[returnid].arr[2]);
            swap(seg[returnid].arr[0],seg[returnid].arr[1]);
        }
        if(dx%3==2){
            swap(seg[returnid].arr[1],seg[returnid].arr[0]);
            swap(seg[returnid].arr[2],seg[returnid].arr[1]);
        }
        if(segstart!=segend){
            lazy[2*returnid]+=dx;
            lazy[2*returnid+1]+=dx;
        }

    }
    if(qstart>segend || qend<segstart){
        return;
    }
    if(segstart>=qstart && segend<=qend){
        lli dx=val;
        if(dx%3==1){
            swap(seg[returnid].arr[1],seg[returnid].arr[2]);
            swap(seg[returnid].arr[0],seg[returnid].arr[1]);
        }
        if(dx%3==2){
            swap(seg[returnid].arr[1],seg[returnid].arr[0]);
            swap(seg[returnid].arr[2],seg[returnid].arr[1]);
        }
        if(segstart!=segend){
            lazy[2*returnid]+=dx;
            lazy[2*returnid+1]+=dx;
        }
        return;
    }
    lli mid=(segstart+segend)>>1;
    lazyupdate(seg,lazy,2*returnid,segstart,mid,qstart,qend,val);
    lazyupdate(seg,lazy,2*returnid+1,mid+1,segend,qstart,qend,val);
    seg[returnid].arr[0]=seg[2*returnid+1].arr[0]+seg[2*returnid].arr[0];
    seg[returnid].arr[1]=seg[2*returnid+1].arr[1]+seg[2*returnid].arr[1];
    seg[returnid].arr[2]=seg[2*returnid+1].arr[2]+seg[2*returnid].arr[2];
}

lli query(vli &seg,lli returnid,lli segstart,lli segend,lli qstart,lli qend){
    if(qstart>segend || qend<segstart){
        return 0;
    }
    if(segstart>=qstart && segend<=qend){
        return seg[returnid];   
    }
    lli mid=(segstart+segend)/2;
    lli l=query(seg,2*returnid,segstart,mid,qstart,qend);
    lli r=query(seg,2*returnid+1,mid+1,segend,qstart,qend);
    return l+r;
}

void update(vli &seg,lli returnid,lli segstart,lli segend,lli changeid,lli val){
    if(segstart==segend){
        seg[returnid]=1;
        return;
    }
    lli mid=(segstart+segend)>>1;
    if(changeid<=mid)
        update(seg,2*returnid,segstart,mid,changeid,val);
    else
        update(seg,2*returnid+1,mid+1,segend,changeid,val);
    //seg[returnid]=seg[2*returnid]+seg[2*returnid+1];
    if(seg[2*returnid]!=inf){
        seg[returnid]=seg[2*returnid];
    }
    if(seg[2*returnid+1]!=inf){
        if(seg[returnid]==inf)
            seg[returnid]=seg[2*returnid+1];
        else 
            seg[returnid]+=seg[2*returnid+1];
    }
}

int main()
{
    fast_io;
    lli n,q; 
    cin>>n>>q;
    string s;
    cin>>s;
    
    vli segtree(4*n,0);
    vli lazy(4*n,0);
    buildtree(segtree,s,1,0,n-1);
    while(q--){
        lli o;
        cin>>o;
        if(o==2){
            lli a;cin>>a;
            update(segtree,1,1,n,a,1);
        }
        else{
            cout<<segtree[1]<<endl;
        }
    }
    return 0;
}   
