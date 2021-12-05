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
Node* deletemiddle(Node *head){
    Node* n=head;
    Node *alpha=head;
    lli count=0;
    while(n!=nullptr){
        count++;
        n=n->next;
    }
    lli i;
    if(count%2==0){
        i=2;
    }
    else 
        i=1;
    count/=2;
    
    while(alpha!=nullptr){
        
        if(i==count)
            alpha->next=alpha->next->next;
        else 
            alpha=alpha->next;
        i++;
    }

    //cout<<count<<endl;
    return head;
}


int main(){
    Node *limk=new Node(2);
    limk->appendToTail(4);
    limk->appendToTail(5);
    limk->appendToTail(3);
    limk->appendToTail(1);
    limk->appendToTail(1);
    limk->appendToTail(1);
    limk->appendToTail(2);
    /*Node *n=limk;
    while(n!=nullptr){
        cout<<n->data<<endl;
        n=n->next;
    }*/
    //lli k,i=0;
    //cin>>k;
    Node* elements=deletemiddle(limk);
    Node *m=elements;
    while(m!=nullptr){
        cout<<m->data<<endl;
        m=m->next;
    }
}