#include<iostream.h>
#include<string.h>
#include<conio.h>

class intcollections
{
	public:
		static void swap(int &num1,int &num2);
		static void swapstrings(char *ptr1,char*ptr2);
		static void  selection_sort(int *ptr,int size);
		static void  selection_sortstring(char ptr[][20],int size);

		static void bubble_sort(int *ptr,int size);

};

void intcollections::swap(int &num1,int &num2)
{
	int temp;
	temp=num1;
	num1=num2;
	num2=temp;

}
void intcollections::swapstrings(char*ptr1,char*ptr2)
{
	char*temp;
	strcpy(temp,ptr1);
	strcpy(ptr1,ptr2);
	strcpy(ptr2,temp);

	/*

	temp=ptr1;
	ptr1=ptr2;
	ptr2=temp;*/

}
void intcollections::selection_sort(int *arr,int size)
{
	int i,j;
	for(i=0;i<size-1;i++)
	{
		int index=i;
		for(j=i+1;j<size;j++)
		{
			if(arr[index] > arr[j])
			{
				index=j;
			}

		}
		intcollections::swap(arr[index],arr[i]);
	}
}
void intcollections::selection_sortstring(char ptr[][20],int size)
	{
	int i,j;
	for(i=0;i<size-1;i++)
	{
		int index=i;
		for(j=i+1;j<size;j++)
		{
			if(strcmp(ptr[index],ptr[j])>0)
			{
				index=j;
			}

		}
		intcollections::swapstrings(ptr[index],ptr[i]);
	}

}
void intcollections::bubble_sort(int*arr,int size)
{
	int i,j;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-1-i;j++)
		{
			if(arr[j]>arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}

}

int main()
{
	clrscr();
	int i;
	int arr[]={3,2,6,1,5,4};
	int arr2[]={10,2,6,1,2,7};
	char arr3[][20]={"sara","aliaa","omar"};
	intcollections::selection_sort(arr,6);
	for(i=0;i<6;i++)
	{
		cout<<arr[i]<<" ";
	}
	/********************************/
	cout<<endl;
	intcollections::bubble_sort(arr2,6);
	for(i=0;i<6;i++)
	{
		cout<<arr2[i]<<" ";
	}
	/********************************/
	intcollections::selection_sortstring(arr3,3);
	for(i=0;i<3;i++)
	{
		cout<<arr3[i]<<" ";
	}
	getch();
	return 0;
}
