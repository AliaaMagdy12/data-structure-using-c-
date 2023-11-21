#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
class intcollections
{
	public:
		static void merge(int*a,int*l,int*r,int countleft,int countright);
		static void mergesort(int *a,int n);
};
void intcollections::merge(int*a,int*l,int*r,int countleft,int countright)
{
	int i=0,j=0,k=0;
	while(i<countleft && j<countright)
	{
		if(l[i] < r[j])
			a[k++]=l[i++];
		else
			a[k++]=r[j++];

	}
	while(i< countleft)
		a[k++]=l[i++];
	while(j<countright)
		a[k++]=r[j++];


}
void intcollections::mergesort(int *a,int n)
{
	int *l,*r,mid,i;
	if(n<2)
		return;
	mid=n/2;
	l=(int*)malloc(mid*sizeof(int));
	r=(int*)malloc((n-mid)*sizeof(int));
	for(i=0;i<mid;i++)
		l[i]=a[i];
	for(i=mid;i<n;i++)
		r[i-mid]=a[i];
	intcollections::mergesort(l,mid);
	intcollections::mergesort(r,n-mid);
	intcollections::merge(a,l,r,mid,n-mid);
	free(l);
	free(r);

}

int main()
{
	int arr[6]={4,2,6,9,1,7};
	intcollections::mergesort(arr,6);
	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<" ";
	}
	getch();
	return 0;
}