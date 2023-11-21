#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class node
{
	public:
		int data;
		node* next;
		node* prev;
		node()
		{
			prev=next=NULL;
		}


};
class linkedlist
{
	node* start;
	node* end;
	int size;
	public:
		linkedlist();
		node* searchonnode(int key);
		void appendnode(node* appended);
		void insert(node* inserted);
		int deletenode(int key);
		int getsize();
		int isempty();
		void freelist();
		node* getfirst();
		node* getlast();
		node* peekfirst();
		node* peeklast();
};
node* linkedlist::searchonnode(int key)
{
	node* temp=start;
	if(start==NULL)
		return NULL;
	while(temp!=NULL && temp->data != key)
	{
		temp=temp->next;

	}
	return temp;

}
linkedlist::linkedlist()
{    size=0;
	start=end=NULL;
}
void linkedlist::appendnode(node*appended)
{
	if(start==NULL)
		start=end=appended;
	else
	{
		appended->prev=end;
		end->next=appended;
		end=appended;

	}
	size++;
}
void linkedlist::insert(node* inserted)
{
	node* temp=start;
	while(temp!=NULL && temp->data < inserted->data)
	{
		temp=temp->next;
	}
	if(temp==NULL)
		appendnode(inserted);
	if(temp==start)
	{
		start->prev=inserted;
		inserted->next=start;
		start=inserted;
		size++;
	}
	else
	{
		temp->prev->next=inserted;
		inserted->prev=temp->prev;
		temp->prev=inserted;
		inserted->next=temp;
		size++;
	}


}
int linkedlist::deletenode(int key)
{
	node*temp;
	if(start==NULL)
		return 0;
	temp=searchonnode(key);
	if(temp==NULL)
		return 0;
	if(temp==start && temp==end)
	{
		start=end=NULL;
		free(temp);
	}
	if(temp==start)
	{
		start=start->next;
		start->prev=NULL;
		free(temp);
	}
	if(temp==end)
	{
		end=end->prev;
		end->next=NULL;
		free(temp);
	}
	else
	{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);

	}
	size--;
	return 1;
}
void linkedlist::freelist()
{
	node*temp=start;
	while(temp!=NULL)
	{
		start=start->next;
		free(temp);
		temp=start;
	}
	end=NULL;
	size=0;
}
int linkedlist::getsize()
{
	return size;
}
int linkedlist::isempty()
{
	return start==NULL;
}
node* linkedlist::getfirst()
{
	if(isempty())
		return NULL;
	node*temp=start;
	start=start->next;
	if(temp!=NULL)
		start->prev=NULL;
	else
		end=NULL;
	temp->prev=temp->next=NULL;
	size--;
	return temp;

}
node* linkedlist::getlast()
{
	if(isempty())
		return NULL;
	node*temp=end;
	end=end->prev;
	if(end!=NULL)
		end->next=NULL;
	else
		start=NULL;
	temp->prev=temp->next=NULL;
	size--;
	return temp;
}
node* linkedlist::peekfirst()
{
	if(isempty())
		return NULL;
	node*temp=new node();

	temp->prev=temp->next=NULL;
	return temp;
}

node* linkedlist::peeklast()
{
	if(isempty())
		return NULL;
	node*temp=new node();
	temp->data=end->data;
	temp->prev=temp->next=NULL;
	return temp;

}
int main()
{
	clrscr();
	node*ptr2;
	linkedlist employees;

	node *  first = new node();

	first->data=1;

	employees.appendnode(first);

	node*second=new node();
	second->data=2;
	employees.appendnode(second);

	node*third=new node();
	third->data=4;
	employees.appendnode(third);
	node*ptr=first;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	/*****************/
	cout<<endl;
	node*fourth=new node();
	fourth->data=3;
	employees.insert(fourth);
	ptr=first;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	/*****************/
	ptr=first;
	employees.deletenode(3);
	cout<<endl;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	/**********************/
	cout<<endl;
	ptr2=employees.searchonnode(1);
	cout<<ptr2->data;
	/**********************/
	cout<<endl;
	ptr2=employees.getfirst();
	cout<<ptr2->data;
	/**********************/
	cout<<endl;
	ptr2=employees.getlast();
	cout<<ptr2->data;
	/**********************/
	cout<<endl;
	cout<<employees.getsize();
	getch();
	return 0;
}