#include<iostream.h>
#include<conio.h>
#include<string.h>
typedef struct
{
	char name[10];
	int code;
}emp;
class intcollections
{
	public:

		static int linear_stringsearch(emp arr[],int size,char* name);
		static int linear_codesearch(emp arr[],int size,int code);
};
int intcollections::linear_stringsearch(emp arr[],int size,char* name)
{
	for(int i=0;i<size;i++)
	{
		if(strcmp(arr[i].name,name)==0)
			return i;
	}
	return -1;


}
int intcollections::linear_codesearch(emp arr[],int size,int code)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i].code==code)
			return i;
	}
	return -1;

}
int main()
{   int code;
	emp arr[10]={{"aliaa",1},{"hamada",2}};
	char ch[10];
	cout<<"enter name to search for"<<endl;
	cin>>ch;
	cout<<"index of name"<<intcollections::linear_stringsearch(arr,3,ch);

	cin>>code;
	cout<<"index of code"<<intcollections::linear_codesearch(arr,3,code);

	getch();
	return 0;
}