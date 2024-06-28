#include <bits/stdc++.h>
using namespace std;
struct node
{
    node* v[26];
    bool f=false;

    bool containskey(char ch){
        return v[ch-'a']!=NULL;
    }

    void insertkey(char ch){
        v[ch-'a']=new node();
    }
};

class trie{
    public:
    node* root;
    trie(){
        root=new node();
    }

    void insert(string& word){
        node* n=root;
        for(int i=0;i<word.size();i++){
            if(n->containskey(word[i])==false){
                n->insertkey(word[i]);
            }
            n=n->v[word[i]-'a'];
        }
        n->f=true;
    }

    bool search(string& word){
        node* n=root;
        for(int i=0;i<word.size();i++){
            if(n->containskey(word[i])==false){
                return false;
            }
            n=n->v[word[i]-'a'];
        }
        if(n->f)return true;
        return false;
    }
};

int main(){
    trie t;
    string s="rinshi";
    t.insert(s);
    s="rin";
    cout<<t.search(s);
}