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
    Node *num2=new Node(6);
    num2->appendToTail(1);
    num2->appendToTail(7);
     Node *num1=new Node(2);
    num1->appendToTail(9);
    num1->appendToTail(5);
    Node *n=num1;
    Node *n2=num2;
    lli number1=0,number2=0;
    while(n!=nullptr){
        number1*=10;
        number1+=n->data;
        n=n->next;
    }
    while(n2!=nullptr){
        number2*=10;
        number2+=n2->data;
        n2=n2->next;
    }
    lli sum=number1+number2;
}