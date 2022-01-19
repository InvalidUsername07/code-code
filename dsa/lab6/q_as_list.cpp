#include <iostream>
#include <cstdlib>
using namespace std;
class EMPTY{};
class node{
    public:
        node* next;
        int key;
};
class Queue{
    private:
        node* head;
    public:
        Queue(){
            head=NULL;
        }
        node* search(int k){
            node* x=head;
            while(x!=NULL && x->key!=k){
                x=x->next;
            }
            return x;
        }
        
        void enqueue(int k){
            node* x=head;
            node *y=new node[1];
            y->key=k;
            y->next=NULL;
            if (x==NULL){
                head=y;
            }
            else{
                while(x->next!=NULL){
                    x=x->next;
                }
                x->next=y;
            }
        }
        
        
        int dequeue(){
            if(head==NULL){
                cout<<"underflow"<<endl;
                throw EMPTY();
            }
            int a=head->key;
            head=head->next;
            return a;
        }
        void show(){
            node* x=head;
            do{
                cout<<x->key<<"\t";
                x=x->next;
            }while(x!=NULL);
        }
};
void queue_as_list(){
    Queue q;
    for(int i=0;i<4;i++)q.enqueue(i);
    q.show();
    for(int i=0;i<5;i++)cout<<q.dequeue();
}
int main(){
    queue_as_list();
}