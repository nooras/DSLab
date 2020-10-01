/*Description: Implementation of Binary Search Tree.
 Learner: Shaikh Mariyam Anis.
 */
 
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int binary_search(int a[],int n,int x)
{
	int mid=n/2;
	int high=n-1,low=0;
	while(high>=low)
	{
		if(a[mid]==x)
			return mid;
		if(x>a[mid])
			low=mid+1;
		else
			high=mid-1;
		mid=(low+high)/2;
	}
	return -1;
}

int main()
{
	int n,x,i,ans;
	int a[MAX_SIZE];
	printf("Enter the no. of element");
	scanf("%d",&n);
	printf("Enter the Element in ascending order\n");
	for(i=0;i<n;i++)
	{
      scanf("%d",&a[i]);
    }
    printf("Enter the Element to be search ");
    scanf("%d",&x);
    ans=binary_search(a,n,x);
    if(ans==-1)
     printf("Number is not found");
    else
     printf("Your number is on location=%d",ans);
     return 0;
 }
    
/*Output
 Enter the no. of element5
Enter the Element in ascending order
12
63
75
94
56
Enter the Element to be search 94
Your number is on location=3
------------------
(program exited with code: 0)
Press return to continue
*/	
	
