#include <iostream>
#include <cstdlib>
using namespace std;
class node{
    public:
        node* prev;
        node* next;
        int key;
};
class double_list{
    private:
        node* head;
        node* tail;
    public:
        double_list(){
            head=NULL;
        }
        bool empty(){return (head==NULL);}
        node* search(int k){
            node* x=head;
            while(x!=NULL && x->key!=k){
                x=x->next;
            }
            return x;
        }
        node* last_node(){
            node*x =head;
            while(x->next!=NULL){
                x=x->next;
            }
            return x;
        }
        //insertions
        void insert_beginning(int k){
            node* x=new node[1];
            x->next=head;
            x->key=k;
            if(head!=NULL){
                head->prev=x;
            }
            head=x;
            x->prev=NULL; 
        }
        void insert_end(int k){
            node* y=new node[1];
            y->key=k;
            node* x=last_node();
            x->next=y;
            y->prev=x;
            y->next=NULL;
        }
        void insert_after(int after,int k){
            node*x=search(after);
            node*y=new node[1];
            y->key=k;
            y->prev=x;
            y->next=x->next;
            if(x->next!=NULL)
                x->next->prev=y;
            x->next=y;
        }
        void insert_before(int before,int k){
            node* x=search(before);
            node*y=new node[1];
            y->key=k;
            y->prev=x->prev;
            y->next=x;
            if(x->prev!=NULL)
                x->prev->next=y;
            else
                head=y;
            x->prev=y;
        }
        void remove_beginning(){
            remove(head);
        }
        void remove_last(){
            remove(last_node());
        }
        void remove_after(int after){
            node*x=search(after);
            if(x->next!=NULL)
                remove(x->next);
            else cout<<"There is no node after "<<x->key<<endl;
        }
        void remove_before(int before){
            node *x=search(before);
            if(x->prev!=NULL)
                remove(x->prev);
            else cout<<"There is no node before "<<x->key<<endl;
        }
        void remove(node* x){//deletes  a node from the list for a provided key
            if(x==NULL)cout<<"not found";
            else{
            if (x->prev!=NULL)
                x->prev->next=x->next;
            else head=x->next;
            if(x->next!=NULL)
                x->next->prev=x->prev;
            cout<<"deleted=="<<x->key<<endl;
            delete []x;
            }
        }
        void show(){
            node* x=head;
            do{
                cout<<x->key<<"\t";
                x=x->next;
            }while(x!=NULL);
            cout<<endl;
        }
};
void example(){
    double_list d;
    d.insert_beginning(6);
    d.insert_beginning(3);
    d.insert_after(6,9);
    d.insert_before(3,1);
    d.insert_end(12);
    cout<<"list is:"<<endl;
    d.show();
    d.remove_beginning();
    d.remove_last();
    d.remove_after(3);
    d.remove_before(9);
    d.remove_before(9);
    d.remove_after(9);
    d.show();

}
int main(){
    example();
}
