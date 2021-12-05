#include <iostream>
#include <map>
#define lli long long int
using namespace std;

string urlify(string s){
    string result="";
    for(lli i=0;i<s.length();i++){
        if(s[i]==' ')
            result=result+"%20";
        else 
            result=result+s[i];
    }
    return result;
}

int main(){
    string s;
    getline(cin,s);
    cout<<urlify(s)<<endl;
}