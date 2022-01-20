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
        node* head, *tail; //adding tail does enqueue in constant time.
    public:
        Queue(){
            head=NULL; tail = NULL;
        }
        node* search(int k){
            node* x=head;
            while(x!=NULL && x->key!=k){
                x=x->next;
            }
            return x;
        }
        
        void enqueue(int k){
           
            if ( head == NULL  ) { //if empty
                tail = new node;
                tail->k = k;
                tail->next = NULL; 
                head = tail;

           } else {
                node* prevtail = tail;
                tail = new node;
                tail->key = k;
                prevtail->next = tail;
                tail->next = NULL;
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
