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


template <class T>
class Stack{
    public: 
        T data;
        Stack<T>* next;
        
        Stack(){
            data=0;
            next=nullptr;
        }
        Stack(T d){
            data=d;
            next=nullptr;
        }
        void push(T item){
            Stack<T>* end=new Stack<T>(item);
            Stack<T>* n=this;
            while(n->next!=NULL){
                n=n->next;
            }
            n->next=end;
        }
        void pop(){
            Stack<T>* n=this;
            while(n->next->next!=NULL){
                n=n->next;
            }
            n->next=nullptr;
        }
        void printelement(){
            Stack<T>* n=this;
            while(n!=NULL){
                cout<<n->data<<endl;
                n=n->next;
            }
        }
        void top(){
            Stack<T>* n=this;
            while(n->next!=NULL){
                n=n->next;
            } 
            cout<<n->data<<endl;
        }
};

int main(){
    Stack<lli>* arr[3];
    arr[0]=new Stack<lli>(4);
    arr[1]=new Stack<lli>(4);
    arr[2]=new Stack<lli>(4);
    arr[0]->push(10);
    arr[0]->push(5);
    arr[1]->push(10);
    arr[1]->push(6);
    arr[2]->push(10);
    arr[2]->push(7);
    arr[0]->printelement();
    
    return 0;
}