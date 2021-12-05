#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<stack>
#include <iostream>
#include <map>
#include<climits>
#include <queue>
//read question properly
#define ld long double
#define ll long long 
#define lli long long int 

using namespace std;

class Node{
    public:
        bool visited;
        vector<Node *> branch;
        lli num;
        Node(){
            visited=false;
            num=0;
        }
        Node(lli data){
            visited=false;
            num=data;
        }
};

void dfs(Node* root){
    if(root == NULL){
        
    }
}