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


class Trienode{
    public:
    class Trienode* children[26];
    bool endword;
    Trienode(){
        endword=false;
    }
};

Trienode* getNode(){
    Trienode* pnode=new Trienode();
    for(lli i=0;i<26;i++){
        pnode->children[i]=NULL;
    }
    return pnode;
}

void insert(Trienode *element,string key){
    Trienode *pcrawl=element;
    for(lli i=0;i<key.length();i++){
        lli id=key[i]-'a';
        if(pcrawl->children[id]==NULL){
            pcrawl->children[id]=getNode();
        }
        pcrawl=pcrawl->children[id];
    }
    pcrawl->endword=true;
}

bool search(Trienode* element,string searchword){
    Trienode* pcrawl = element;
    for(lli i=0;i<searchword.length();i++){
        if(pcrawl->children[searchword[i]-97]==NULL)
            return false;
        pcrawl= pcrawl->children[searchword[i]-97];
    }
    return (pcrawl->endword);
}

int main(){
    Trienode* node=getNode();
    insert(node,"hello");
    insert(node,"world");
    insert(node,"break");
    cout<<search(node,"wall")<<endl;
    cout<<search(node,"hello")<<endl;
    cout<<search(node,"break")<<endl;
    cout<<search(node,"brea")<<endl;
    return 0;
}