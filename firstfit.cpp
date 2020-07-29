#include<iostream>
#include<stdlib.h>
using namespace std;
struct node2
{
	int ps;
	struct node2 *next2;
};struct node2 *head2=NULL;

struct node
{

int bs,sa,ea,bn;
struct node *next;
};
struct node *head1=NULL;

struct node3
{
int bs,sa,ea,bn,ps;
struct node3 *next3;
};
struct node3 *head3=NULL; 

void traverse(struct node *root)
{
struct node *d=root;



cout<<"Block No.\tBlock size\tStarting addr.\t Ending addr.\n";
while(d!=NULL)
{
d->ea=d->sa+d->bs;
cout<<d->bn<<"\t\t";
cout<<d->bs<<"\t\t";
cout<<d->sa<<"\t\t";
cout<<d->ea<<"\t\t";

d=d->next;
cout<<endl;
}
}
//extra in my code
void traverse2(struct node2 *root2)
{
struct node2 *e=root2;
cout<<"Process Size\n";
while(e!=NULL)
{
cout<<e->ps<<"\n";
e=e->next2;
}
}
struct node *insert(struct node *head,int a,int b,int i)
{
struct node *p;
p=(struct node *)malloc(sizeof(struct node));
p->bs=a;
p->sa=b;
p->ea=p->sa+p->bs;
p->bn=i;
p->next=NULL;
if(head==NULL)
head=p;
else
{
struct node *t;
for(t=head;t->next!=NULL;t=t->next);
t->next=p;
}
return head;
}

void traverse3(struct node3 *root)
{
struct node3 *d=root;
struct node *e=head1;
cout<<"\nBlock No.  Block Size    Starting Address   Ending Adress"<<endl;
while(d!=NULL && e!=NULL)
{
if(d->bs!=e->bs)
{
cout<<d->bn<<"\t\t"<<d->bs<<"\t\t"<<d->sa<<"\t\t"<<d->ea<<endl;
}
d=d->next3;
e=e->next;
}
}
struct node2 *insert2(struct node2 *head,int c)
{
struct node2 *q;
q=(struct node2 *)malloc(sizeof(struct node2));
q->ps=c;
q->next2=NULL;
if(head==NULL)
head=q;
else
{
struct node2 *s;
for(s=head;s->next2!=NULL;s=s->next2);
s->next2=q;
}
return head;
}

struct node *freelist(struct node *head,int n)
{
int i,a,b;
for(i=0;i<n;i++)
{
cout<<"\nEnter block size and starting adress of block "<<" "<<i+1<<":";
cin>>a>>b;
head=insert(head,a,b,i+1);
}
return head;
}



struct node3 *freelist(struct node3 *head,int a,int b,int c,int d)
{
struct node3 *n;
n=(struct node3 *)malloc(sizeof(struct node3));
n->bs=a;
n->sa=b;
n->ea=c;
n->bn=d;
n->ps=b;
n->next3=NULL;
if(head==NULL)
head=n;
else
{
struct node3 *s;
for(s=head;s->next3!=NULL;s=s->next3);
s->next3=n;
}
return head;
}




struct node *sort(struct node *head)
{
struct node *temp = head;
while (temp) {
struct node *min = temp;
struct node *r = temp->next;
while (r) {
if (min->sa > r->sa)
        min = r;
r = r->next;
}
int x = temp->bs;
int y = temp->sa;
temp->bs = min->bs;
temp->sa = min->sa;
min->bs = x;
min->sa = y;
temp = temp->next;
}
return head;
}

struct node3 *insert3(struct node3 *head,int a,int b)
{
struct node3 *p=head;
while(p!=NULL)
{
if(p->bn==b)
{
p->ps=p->ps+a;
p->ea=p->ps;
p->bs=p->ea-p->sa;
}
p=p->next3;
}
return head;
}


void firstfit(struct node *a,struct node2 *b)
{

bool spaceavail;
struct node2 *q = b;
struct node *p = a;

   for(q=b;q!=NULL;q=q->next2){

       spaceavail=false;
       cout<<"----| Requesting "<<q->ps<<"|----"<<endl;
        
        
        while (q!=NULL){
        	
        	 if(p->bs>=q->ps){
                spaceavail=true;
                break;   
            }
         p=p->next; 
         
        }
        if(spaceavail && q!=NULL)
           {
            p->bs=p->bs-q->ps;
            p->sa=p->sa+q->ps+1;
            
            head3=insert3(head3,q->ps,p->bn);
        	p=a;
           }
        
       
        else{
            cout<<"could not allocate"<<q->ps<<endl;
            q=q->next2;
        }
         cout<<"Free List:\n";
         traverse(head1);
        
    }

cout<<"\nFINAL Allocated LIST:"<<endl;
traverse3(head3);
}


struct node3 *allocated(struct node3 *head,int a,int b,int c,int d)
{
struct node3 *n;
n=(struct node3 *)malloc(sizeof(struct node3));
n->bs=a;
n->sa=b;
n->ea=c;
n->bn=d;
n->ps=b;
n->next3=NULL;
if(head==NULL)
head=n;
else
{
struct node3 *s;
for(s=head;s->next3!=NULL;s=s->next3);
s->next3=n;
}
return head;
}


int main()
{
int nb;
int np,psize;
cout<<"Enter number of blocks:";
cin>>nb;
head1=freelist(head1,nb);
head1=sort(head1);
traverse(head1);
struct node *h=head1;
for(h=head1;h!=NULL;h=h->next)
head3=allocated(head3,h->bs,h->sa,h->ea,h->bn);
cout<<"Enter number of process:";
cin>>np;
for(int i=0;i<np;i++)
{
	cout<<"Enter size of process"<<i+1<<": ";
	cin>>psize;
	head2=insert2(head2,psize);
	
}
traverse2(head2);
firstfit(head1,head2);


}
