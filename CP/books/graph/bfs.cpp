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
        lli num;
        vector<Node*> branch;
        bool visited=false;

        Node(){
            num=0;
        }
        Node(lli data){
            num=data;
        }
};


void bfs(Node* root){
    queue<Node*> qu;
    root->visited=true;
    qu.push(root);
    while(qu.size()!=0){
        Node *n=qu.front();
        qu.pop();
        cout<<n->num<<endl;
        for(Node *r : n->branch){
            if(r->visited==false)
                r->visited=true;
            qu.push(r);
        }
    }
}

int main(){
    Node *graph=new Node();
    graph->branch.push_back(new Node(3));
    graph->branch.push_back(new Node(2));
    graph->branch.push_back(new Node(1));
    graph->branch.push_back(new Node(4));
    graph->branch[0]->branch.push_back(new Node(8));
    graph->branch[0]->branch.push_back(new Node(5));
    graph->branch[0]->branch.push_back(new Node(6));
    graph->branch[1]->branch.push_back(new Node(7));
    bfs(graph); 
}