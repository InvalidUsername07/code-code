#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
class EMPTY{};
class node{
    public:
        int coeff;
        int expo;//poly:: (coeff) x^a y^b z^c
        node* next;
    public:
        int abc(){
            return expo;
        }
};
class list{
    public:
        node* head;
    public:
        list(){
            head=new node[1];
            head->next=head;
            head->expo=-1;
            head->coeff=0;
        }       
        //insertions
        void insert_beginning(int co,int aa){
            node* x=new node[1];
            x->coeff=co;
            x->expo=aa;
            x->next=head->next;
            head->next=x;
        }
        void show(){
            node *x=head->next;
            while(x->expo!=-1){
                cout<<x->coeff<<"("<<x->expo<<")"<<"\t";
                x=x->next;
            }
            cout<<endl;
        }
};
class addition{
    private:
        list p,q;
        node* P;
        node* Q;
        node *Q1;
        node* Q2;
    public:
        void read(){
            int n,c,e;//order (descending ABC )
            cout<<"enter number of terms in polynomial p\n";cin>>n;
            for(int i=0;i<n;i++){
                cin>>c>>e;
                p.insert_beginning(c,e);
            }
            cout<<"enter number of terms in polynomial q\n";cin>>n;
            for(int i=0;i<n;i++){
                cin>>c>>e;
                q.insert_beginning(c,e);
            }
        } 
        void A1(){
            Q=q.head->next;
            P=p.head->next;
        }
        void A2(){
            if(P->abc()<Q->abc()){
                while(P->abc()<Q->abc()){
                    Q1=Q;
                    Q=Q->next;
                }
            }
            else if(P->abc()==Q->abc()){
                A3();
            }
            else if(P->abc()>Q->abc()){
                A5();
            }
        }
        void A3(){
            if(P->expo<0)//terminate();
            {
                show_result();
            }
            else{
                Q->coeff+=P->coeff;
                if(Q->coeff==0)
                {
                    A4();
                }
                else{
                    Q1=Q;
                    P=P->next;
                    Q=Q->next;
                    A2();
                }
            }
        }
        void A4(){
            Q2=Q;
            Q=Q->next;
            Q1->next=Q;
            P=P->next;
            A2();
        }
        void A5(){
            Q2=new node[1];
            Q2->coeff=P->coeff;
            Q2->expo=P->expo;
            Q2->next=Q;
            Q1->next=Q2;
            Q1=Q2;
            P=P->next;
            A2();
        }
        void show_result(){
            q.show();
        }
        void method(){
            read();
            A1();
            A2();
        }
        ~addition(){
            method();
        }   
};
int main(){
   
}
