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

    /*Node* deleteNode(int d){
        Node *n=this;
        cout<<"hello";
        Node *element=new Node();
        while(n->next!=nullptr){
            if(n->data!=d){
                
                element->appendToTail(n->data);
            }
            n=n->next;
        }
        return element;
    }*/
};

int main(){
    lli n;
    Node *limk=new Node(2);
    limk->appendToTail(4);
    limk->appendToTail(5);
    limk->appendToTail(3);
    limk->appendToTail(1);
    while(limk!=nullptr){
        cout<<limk->data<<endl;
        limk=limk->next;
    }
   // Node *finale=limk->deleteNode(5);
    //cout<<"BELLO"<<endl;
   // while(finale!=nullptr){
    //    cout<<finale->data<<endl;
    //    finale=finale->next;
    //}
}
