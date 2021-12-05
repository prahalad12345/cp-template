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

class Interval{
    public:
    lli low,high;
};

class ITNode{
    public:
    Interval *i;
    lli max;
    ITNode *left,*right;
};

ITNode *newnode(Interval i){
    ITNode *temp = new ITNode();
    temp->i=new Interval(i);
    temp->max=i.high;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

ITNode *insert(ITNode* root,Interval i){
    if(root==NULL)
        return newnode(i);
    
    lli loww=root->i->low;
    if(i.low<loww){
        root->left=insert(root->left,i);
    }
    else{
        root->right=insert(root->right,i);
    }
    if(root->max<i.high)
        root->max=i.high;
    return root;
}

bool checkoverlap(Interval i1,Interval i2){
    if(i1.low<=i2.high && i2.low<=i1.high)
        return true;
    else 
        return false;
}

Interval *overlapsearch(ITNode* root,Interval i){
    if(root==NULL)
        return NULL;
    if(checkoverlap(*(root->i),i)){
        return root->i;
    }
    if(root->left!=NULL && root->left->max>=i.low){
            return overlapsearch(root->left,i);
    }
    else{
        return overlapsearch(root->right,i);
    }
}

void inorder(ITNode *root)
{
    if (root == NULL) return;
    inorder(root->left);
    cout << "[" << root->i->low << ", " << root->i->high << "]"
         << " max = " << root->max << endl;
    inorder(root->right);
}

int main(){
    Interval ints[] = {{15, 20}, {10, 30}, {17, 19}, {5, 20}, {12, 15}, {30, 40}};
    ITNode* root=NULL;
    for(lli i=0;i<sizeof(ints)/sizeof(ints[0]);i++){
        root=insert(root,ints[i]);
    }
    inorder(root);
    Interval x = {6, 7};
  
    cout << "\nSearching for interval [" << x.low << "," << x.high << "]";
    Interval *res = overlapsearch(root, x);
    if (res == NULL)
        cout << "\nNo Overlapping Interval";
    else
        cout << "\nOverlaps with [" << res->low << ", " << res->high << "]";
    return 0;
}

