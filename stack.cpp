#include <bits/stdc++.h>
using namespace std;
class ll{
    public:
    int val;
    ll* next;

    ll(int d){
        val=d;
        next=NULL;
    }

};
class Stack{
    public:
    ll* tail;
    
    ll* head;
    int size;
    
    Stack(){
        tail=new ll(-1);
        head=tail;size=0;
    }
    Stack(int val){
        tail=new ll(val);
        head=tail;
        size=0;
    }
    void push(int val){
        tail->next=new ll(val);
        
        tail=tail->next;
        size++;
    }
    void pop(){
        ll* temp=head;

        while(temp->next->next){
            temp=temp->next;
        }
        
        delete(temp->next);
        tail=temp;
        tail->next=NULL;
        size--;
    }
    int top(){
        return tail->val;
    }
    bool isempty(){
        if(size==0)return true;
        else return false;
    }
};

int main(){
    Stack st(5);
    st.push(6);
    st.push(7);
    st.push(8);
    
    st.pop();
    
    st.pop();
    st.pop();
    
    if(st.isempty()) cout<<"stack is empty";
    else cout<<"stack is not empty";
}