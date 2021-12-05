#include <iostream>
#include <map>
#define lli long long int
using namespace std;

void isunique(string s){
    if(s.length()>128){
        cout<<"No"<<endl;
    }
    else{
        map<char,lli>  ch;
        for(lli i=0;i<s.length();i++){
            ch[s[i]]++;
            if(ch[s[i]]>1){
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
    }
}

int main(){
    string s;
    cin>>s;
    isunique(s);
}