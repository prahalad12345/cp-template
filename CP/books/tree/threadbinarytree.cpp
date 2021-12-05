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

using namespace std;

class Node{
    public:
        lli data;
        Node* left;
        Node* right;
        bool rightthread;
};

Node* leftnode(Node* n){
    if(n==NULL)
        return NULL;
    while(n->left!=NULL){
        n=n->left;
    }
    return n;
}

void inorder(Node* root){
    Node* cur=leftnode(root);
    while(cur!=NULL){
        cout<<cur->data<<endl;
        if(cur->rightthread)
            cur=cur->right;
        else 
            cur=leftnode(cur->right);
    }
}

int main(){

}
