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
class Queue{
    public: 
        T data;
        Queue<T>* next;
        
        Queue(){
            data=0;
            next=nullptr;
        }
        Queue(T d){
            data=d;
            next=nullptr;
        }
        void push(T item){
            Queue<T>* end=new Queue<T>(item);
            Queue<T>* n=this;
            while(n->next!=NULL){
                n=n->next;
            }
            n->next=end;
        }
        
        void printelement(){
            Queue<int>* n=this;
            while(n!=NULL){
                cout<<n->data<<endl;
                n=n->next;
            }
        }
        Queue<T>* pop(){
            Queue<T> *result=this->next;
            return result;
        }
        void top(){
            Queue<T>* n=this;
            cout<<n->data<<endl;
        }
};

int main(){
    Queue<int>* element=new Queue<int>(15);
    element->push(4);
    element->push(23);
    element->push(90);
    element->top();
    element->printelement();
    
    element=element->pop();
    
    element->printelement();
    element->top();
    element->printelement();
    return 0;
}
