#include <iostream>
#include <map>
#include <cstdlib>
#define lli long long int

using namespace std;


void diff(string s1,string s2){
    if(s1.length()<s2.length()){
        string temp=s1;
        s1=s2;
        s2=temp;
    }
    map<char,lli> character1,character2;
    for(lli i=0;i<s1.length();i++){
        character1[s1[i]]++;
    }
    for(lli i=0;i<s2.length();i++){
        character2[s2[i]]++;
    }
    lli count=0;
    for(auto x:character1){
        if(character2[x.first]!=x.second){
            count+=abs(character2[x.first]-x.second);
        }
    }
    if(count<=1){
        cout<<"YES"<<endl;
    }
    else 
        cout<<"NO"<<endl;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    diff(s1,s2);
}