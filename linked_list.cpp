#include"iostream"
using namespace std;

struct node
{
	int data;
	node *next;
};

class linked_list
{
	public:
	linked_list()
	{
		head=NULL;
		tail=NULL;
	}
	node *head;
	node *tail;	
	
	public :
	node* create(int n)
	{
	
		node *tmp=new node;
		tmp->data=n;
		tmp->next=NULL;

		if(head==NULL)
		{
			head=tmp;
			tail=tmp;
		}
		else
		{
			tail->next=tmp;
			tail=tail->next;
		}
		return head;		
	}
	void display(node *head)
	{
		node *q;
		q=head;
		while(q!=NULL)
		{
			cout<<q->data;
			cout<<"-->";
			q=q->next;
			
		}
		cout<<"NULL"<<endl;
	}
	node* reverse(node *head)
	{
		node *prev,*curr,*n;
		prev=NULL;
		curr=head;
		while(curr!=NULL)
		{
		n=curr->next;
		curr->next=prev;  //reverse pointer
		prev=curr;        //pointer jst moved forward
		curr=n;
		}
		head=prev;
		return head;
		
	}
	void middle(int n,node *head)
	{
		int count=n/2;
		node *q=head;
		for(int i=0;i<count;i++)
		{
			q=q->next;
		}
		cout<<"middle element is: "<<endl;
		cout<<q->data;
	}
	node* del(node *head)
	{
		node *t,*q;
		q=head;
		while(q->next!=NULL)
		{
			t=q;
			q=q->next;
			
		}
		delete(q);
		t->next=NULL;
		return head;
	}
	node* duplicate(node *head)
	{
		node *p,*q;
		p=head;
		while(p->next!=NULL)
		{
		if(p->data==p->next->data)
		{
			q=p->next->next;
			delete(p->next);
			p->next=q;
		
		}
		p=p->next;
		}
		return head;
	}
	node* rotate(int k,node *head)
	{
		node *p,*q,*r;
		p=head;
		for(int i=0;i<k-1;i++)
		{
			p=p->next;
			
		}
		q=head;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		
		q->next=head;
		head=p->next;
		p->next=NULL;
		
		return head;
	}
	node* merge(node* head1,node* head2)
	{
		node *p,*q,*next_a,*next_b;
		p=head1;
		q=head2;
		while(p->next!=NULL && q->next!=NULL)
		{
			next_a=p->next;          //store next pointers
			next_b=q->next;
			q->next=next_a;          
			p->next=q;               //merge 1st
			p=next_a;                //move pointer forward
			q=next_b;
		}
		p->next=q;//Final attcahment
		return head1;
	}
	
};
int main()
	{
		int n,n1,n2,val1,val2,val,k;
		linked_list l;
		node *head,*head1,*head2;
		cout<<"Enter number of elements";
		cin>>n;
		cout<<"Enter elements in list";
		for(int i=0;i<n;i++)
		{
		
		cin>>val;
		
		head=l.create(val);
		}
		cout<<"-------Rotate list---------"<<endl;
		cout<<"Enetr k to rotate"<<endl;
		cin>>k;
		head=l.rotate(k,head);
		l.display(head);
	
		
		head=l.reverse(head);
		cout<<"-------Reversed linked list----------"<<endl;
		l.display(head);
		l.middle(n,head);
		cout<<"--------Delete last element of list---------"<<endl;
		head=l.del(head);
		l.display(head);
		l.duplicate(head);
		cout<<"-----------Removing duplicate elements------------"<<endl;
		l.display(head);
		linked_list l1;
		linked_list l2;
		cout<<"Enter no of elements of list1"<<endl;
		cin>>n1;
		cout<<"Enter elements in list1"<<endl;
		for(int i=0;i<n1;i++)
		{
			cin>>val1;
			head1=l1.create(val1);
		}
		cout<<"Enter no of elements of list2"<<endl;
		cin>>n2;
		cout<<"Enter elements in list2"<<endl;
		for(int i=0;i<n2;i++)
		{
			cin>>val2;
			head2=l2.create(val2);
		}
		cout<<"---------Merged list----------"<<endl;
		head1=l1.merge(head1,head2);
		l1.display(head1);	
		
	}
