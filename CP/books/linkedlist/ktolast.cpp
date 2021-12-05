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
Node deleteNode(Node *head,int d){
    Node* n=head;
    if(n->data==d){
        return *head->next;
    }
    while(n->next!=nullptr){
        if(n->next->data==d){
            n->next=n->next->next;
            return *head;
        }
        n=n->next;
    }
    return *head;
}
Node* ktolast(Node* head,lli k){
    Node *n=head;
    Node *p2=head;
    lli count=1;
    for(lli i=0;i<k;i++){
        if(n==NULL)
            return NULL;
        n=n->next;
    }
    while(n!=NULL){
        n=n->next;
        p2=p2->next;
    }
    return p2;
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
    lli k,i=0;
    cin>>k;
    Node* elements=ktolast(limk,k);
    Node *m=elements;
    while(m!=nullptr){
        cout<<m->data<<endl;
        m=m->next;
    }
}