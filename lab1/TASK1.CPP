#include<iostream.h>
#include<string.h>
#include<conio.h>
/*typedef struct
{
	char name[10];
	int code;
}emp;*/
class intcollections
{
	public:
		static int linearsearch(int*arr,int size,int num);
		static int binarysearch(int*arr,int size,int num);
		static int linear_stringsearch(char*arr[],int size,char* name);
		static int binary_string_search(char*arr[],int size,char* name);
};
int intcollections::linearsearch(int*arr,int size,int num)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]==num)
			return i;
	}
	return -1;
}
int intcollections::binarysearch(int*arr,int size,int num)
{
	int i,low=0,high=size-1,mid;
	mid=(low+high)/2;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(num>arr[mid])
		{
			low=mid+1;
		}
		else if(num<arr[mid])
			high=mid-1;
		else
			return mid;
	}
	return -1;

}
int intcollections::linear_stringsearch(char* arr[],int size,char*name)
{
	for(int i=0;i<size;i++)
	{
		if(strcmp(arr[i],name)==0)
			return i;
	}
	return -1;

}
int intcollections::binary_string_search(char* arr[],int size,char* name)
{
	int i,low=0,high=size-1,mid;
	mid=(low+high)/2;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(strcmp(arr[mid],name)<0)
		{
			low=mid+1;
		}
		else if(strcmp(arr[mid],name)>0)
			high=mid-1;
		else
			return mid;
	}
	return -1;

}
int main()
{
	intcollections p1;
	clrscr();
	int arr[]={1,4,6,8,10,15,20};
   //	emp arr1[]={{"ahmed",1},{"aliaa",2},{"hala",3},{"sara",4}};
	char* arr1[]={"ahmed","aliaa","hala","sara"};

	int num;
	cout<<"index of num 10 in arr is "<<p1.linearsearch(arr,7,10)<<endl;
	cout<<"enter number to search for"<<endl;
	cin>>num;
	if(num!= -1)
		cout<<"index is "<<p1.binarysearch(arr,7,num)<<endl;

	else
		cout<<"num not exist"<<endl;

	cout<<p1.linear_stringsearch(arr1,5,"aliaa")<<endl;
	cout<<p1.binary_string_search(arr1,5,"sara")<<endl;
	getch();
	return 0;
}