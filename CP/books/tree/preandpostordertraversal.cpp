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
        Node(lli d){
            data=d;
            left=nullptr;
            right=nullptr;
        }
        Node(){
            data=0;
            left=nullptr;
            right=nullptr;
        }
};

void preordertraversal(Node* node){
    if(node!=NULL){
        cout<<node->data<<endl;
        preordertraversal(node->left);
        preordertraversal(node->right);
    }
}

void postordertraversal(Node* node){
    if(node!=NULL){
        preordertraversal(node->left);
        preordertraversal(node->right);
        cout<<node->data<<endl;
    }
}

void append(Node* element,lli data){   
    if(element->data< data){
        if(element->right==nullptr){
            element->right=new Node(data);
        }
        else{
            append(element->right,data);
        }
    }
    else{
        if(element->left==nullptr){
            element->left=new Node(data);
        }
        else{
            append(element->left,data);
        }
    }
}

int main(){
    Node* tree=new Node(9);
    append(tree,10);
    append(tree,8);
    append(tree,7);
    append(tree,11);
    append(tree,100);
    cout<<tree->left->data<<endl;
    preordertraversal(tree);
    postordertraversal(tree);
}