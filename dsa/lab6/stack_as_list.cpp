#include <iostream>
#include <cstdlib>
using namespace std;
class EMPTY{};
class node{
    public:
        node* next;
        int key;
};
class Stack{
    private:
        node* head;
    public:
        Stack(){
            head=NULL;
        }
        void push(int k){
            node* x=new node[1];
            x->next=head;
            x->key=k;
            head=x;            
        }
        int pop(){
            node *x=head;
            if(x==NULL){
                cout<<"underflow";
                throw EMPTY();
            }
            else{
                head=x->next;               
                int a= x->key;
                delete []x;
                return a;
            }
        }
        void show(){
            node* x=head;
            do{
                cout<<x->key<<"\t";
                x=x->next;
            }while(x!=NULL);
        }
};
void stack_as_list(){
    Stack s;
    for(int i=0;i<4;i++)s.push(i);
    s.show();
    for(int i=0;i<5;i++)cout<<s.pop();
}
int main(){
    stack_as_list();
    
}