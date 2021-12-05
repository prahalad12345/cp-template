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
    int data;
    Node* left;
    Node* right;
};

void printcurrentlevel(Node *root,int level){
    if(root==NULL)
        return;
    if(level==1)
        cout<<root->data<<" ";
    else if(level>1){
        printcurrentlevel(root->left,level-1);
        printcurrentlevel(root->right,level-1);
    }
}

int height(Node *node){
    if(node==NULL)
        return 0;
    else{
        int lheight=height(node->left);
        int rheight=height(node->right);

        if(lheight>rheight){
            return lheight+1;
        }
        else 
            return rheight+1;
    }
}

void printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printcurrentlevel(root, i);
}


Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}

int main(){
    Node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->left->right->left=newNode(3);
    printLevelOrder(root);
    return 0;
}

