#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int d;
        node* next;
    public:
    node(){
        d=-1;
        next=NULL;
    }
    node(int val){
        d=val;
        next=NULL;
    }

};

int main(){
    node* head=new node();
    node* tail=head;
    int t=12;
    int x;
    while(t--){
        cin>>x;
        tail->next=new node(x);
        tail=tail->next;
    }
    node* temp=head->next;
    
    
    node* temp2;
    
    node* dup;
    
 
    
    while (temp != NULL && temp->next != NULL) {
        temp2 = temp;
 
        
        while (temp2->next != NULL) {
            
            if (temp->d == temp2->next->d) {
                
                dup = temp2->next;
                temp2->next = temp2->next->next;
                delete (dup);
            }
            else 
                temp2 = temp2->next;
        }
        temp = temp->next;
    }
    temp=head->next;
    while(temp){
        cout<<temp->d<<endl;
        temp=temp->next;
    }

}
