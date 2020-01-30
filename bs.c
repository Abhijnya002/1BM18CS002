#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,n,k,a[10],i,first,last,mid,c,flag,b[10],j=0;
	printf("enter no of testcases=");
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		printf("enter no of elements  =");
		scanf("%d",&n);
		printf("enter  elements=\n");
		for(c=0;c<n;c++)
		{
			scanf("%d",&a[c]);
		}
			printf("enter key =");
			scanf("%d",&k);
			first=0;
			last=n-1;
			mid=(first+last)/2;
			while(first<=last)
			{
				if(a[mid]==k)
				{
					b[j]=1;
					j++;
					break;
				}
				else if(a[mid]<k)
				{
					last=mid-1;
				}
				else if(a[mid]>k)
				{
					first=mid+1;
				}
			}
			if(first>last)
			{
				b[j]=-1;
			}
	}
	
	for(i=0;i<=j;i++)
	{
		printf("%d\n",b[i]);
	}
}
