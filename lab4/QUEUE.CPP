#include<iostream.h>
#include<conio.h>
class queue
{
	private:
		int rear,size,*que;
	public:
		queue();
		queue(int s);
		~queue();
		int isfull();
		int isempty();
		int input(int ele);
		int output(int &ele);
		int peek(int &ele);
};
queue::queue()
{
	size=10;
	rear=0;
	que=new int[size];
}
queue::queue(int s)
{
	size=s;
	rear=0;
	que=new int[size];
}
queue::~queue()
{

}
int queue::isempty()
{
	return(rear==0);
}
int queue::isfull()
{
	return(rear==size);

}
int queue::input(int data)
{
	if(isfull())
		return 0;
	que[rear]=data;
	rear++;
	return 1;
}
int queue::output(int &data)
{
	if(isempty())
		return 0;
	data=que[0];
	for(int i=0;i<rear;i++)
	{
		que[i]=que[i+1];
	}
	rear--;
	return 1;
}
int queue::peek(int &data)
{
	if(isempty())
		return 0;
	data=que[0];
	return 1;
}
int main()
{
	queue q(10);
	q.input(1);
	q.input(3);
	q.input(4);
	q.input(6);

	int value;
	while(q.output(value))
	{
		cout<<value<<" ";
	}
	/*****************/
	cout<<endl;
	q.input(10);
	q.input(3);
	q.peek(value);
	cout<<value;
	getch();
	return 0;
}