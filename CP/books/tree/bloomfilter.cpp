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
#define len(a) (lli)a.size()
using namespace std;

#define pb push_back 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int h1(string s,int arrsize){
    lli hash =0;
    for(int i=0;i<s.size();i++){
        hash=(hash+((int)s[i]));
        hash%=arrsize;
    }
    return hash;
}
int h2(string s,int arrsize){
    lli hash=1;
    for(int i=0;i<s.size();i++){
        hash=hash+pow(19,i)*s[i];
        hash%=arrsize;
    }
    return hash%arrsize;
}
int h3(string s , int arrsize){
    lli hash=7;
    for(int i=0;i<s.size();i++){
        hash=(hash*31*s[i])%arrsize;
    }
    hash%=arrsize;
    return hash;
}

int h4(string s, int arrSize)
{
    lli hash = 3;
    int p = 7;
    for (int i = 0; i < s.size(); i++) {
        hash += hash * 7 + s[0] * pow(p, i);
        hash = hash % arrSize;
    }
    return hash;
}

bool lookup(bool *bitarray,int arrsize,string s){
    int a = h1(s, arrsize);
    int b = h2(s, arrsize);
    int c = h3(s, arrsize);
    int d = h4(s, arrsize);
 
    if (bitarray[a] && bitarray[b] && bitarray
        && bitarray[d])
        return true;
    else
        return false;
}

void insert(bool* bitarray, int arrSize, string s)
{
    // check if the element in already present or not
    if (lookup(bitarray, arrSize, s))
        cout << s << " is Probably already present" << endl;
    else
    {
        int a = h1(s, arrSize);
        int b = h2(s, arrSize);
        //int c = h3(s, arrSize);
        //int d = h4(s, arrSize);
 
        bitarray[a] = true;
        bitarray[b] = true;
        //bitarray[c] = true;
        //bitarray[d] = true;
 
        cout << s << " inserted" << endl;
    }
}

int main()
{
    bool bitarray[1000] = { false };
    int arrSize = 1000;
    string sarray[33]
        = { "abound",   "abounds",       "abundance",
            "abundant", "accessable",    "bloom",
            "blossom",  "bolster",       "bonny",
            "bonus",    "bonuses",       "coherent",
            "cohesive", "colorful",      "comely",
            "comfort",  "gems",          "generosity",
            "generous", "generously",    "genial",
            "bluff",    "cheater",       "hate",
            "war",      "humanity",      "racism",
            "hurt",     "nuke",          "gloomy",
            "facebook", "geeksforgeeks", "twitter" };
    for (int i = 0; i < 33; i++) {
        insert(bitarray, arrSize, sarray[i]);
    }
    return 0;
}
 



