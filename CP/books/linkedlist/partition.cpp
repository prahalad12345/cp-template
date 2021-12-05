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

class Node{
    
    public:
        Node *next;
        int data;
        Node(){
            data=0;
            next=nullptr;
        }
        Node(int d){
            data=d;
            next=nullptr;
        }
    void appendToTail(lli d){
        Node* end =new Node(d);
        Node* n=this;
        lli count=0;
        while(n->next!=nullptr){
            n=n->next;
        }
        n->next=end;
    }
};

int main(){
    Node *limk=new Node(2);
    limk->appendToTail(4);
    limk->appendToTail(5);
    limk->appendToTail(3);
    limk->appendToTail(1);
    limk->appendToTail(1);
    limk->appendToTail(1);
    limk->appendToTail(2);
    
    string s="";
    Node *n=limk;
    while(n!=nullptr){
        s=s+(char)(n->data);
        n=n->next;
    }
    lli flag=1;
    lli l=0;
    lli r=s.length()-1;
    while(l<r){
        if(s[l]!=s[r]){
            flag=0;
        }
        l++,r--;
    }
    if(flag==0)
        cout<<"NOT A PALINDROME"<<endl;
    else 
        cout<<"PALInDROME"<<endl;
}
    
