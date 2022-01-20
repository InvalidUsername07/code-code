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
        node* front;
        node* rear;
        node* head;
    public:
        Queue(){
            head=new node[1];
            front=rear=head;
            head->next=NULL;
        }
        void enqueue(int k){
            rear->key=k;
            node *x=new node[1];
            rear->next=x;
            rear=x;
            rear->next=NULL;
        }        
        int dequeue(){
            if(front==rear){
                cout<<"underflow"<<endl;
                throw EMPTY();
            }
            int a=front->key;
            front=front->next;
            return a;
        }
        void show(){
            node* x=front;
            do{
                cout<<x->key<<"\t";
                x=x->next;
            }while(x!=rear);
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
