/*
 * Discription:Program to implement Quick sort
 * Author:Nooras Fatima-16co01
 * Created on:Sep 28,2017
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

int split(int arr[],int lower,int upper)
{
	int pivot=lower,temp;
	int a=pivot+1,b=upper;
	while(b>=a)
	{
		while(arr[a]<arr[pivot])
			a++;
		while(arr[b]>arr[pivot])
			b--;
		if(b>a)
		{
			temp=arr[a];
			arr[a]=arr[b];
			arr[b]=temp;
		}
	}
	temp=arr[b];
	arr[b]=arr[pivot];
	arr[pivot]=temp;
	return b;
}

void Quick_sort(int a[],int lower,int upper)
{
	int i;
	if(upper>lower)
	{
		i=split(a,lower,upper);
		Quick_sort(a,lower,i-1);
		Quick_sort(a,i+1,upper);
	}
}

int main()
{
	int a[MAXSIZE],n,i=0;
	printf("ENTER THE NO OF ELEMENTS :: ");
	scanf("%d",&n);
	printf("ENTER THE ELEMENTS OF AN ARRAY :: \n");
	while(i<n)
		scanf("%d",&a[i++]);
	Quick_sort(a,0,n-1);
	printf("\nTHE ELEMENTS OF AN SORTED ARRAY IS ::\n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
	return 0;
}
/*

OUTPUTS:
----------------------------------------------------------
ENTER THE NO OF ELEMENTS :: 5
ENTER THE ELEMENTS OF AN ARRAY :: 
12
16
5
4
32

THE ELEMENTS OF AN SORTED ARRAY IS ::
4
5
12
16
32


------------------
(program exited with code: 0)
Press return to continue

----------------------------------------------------------
*/
