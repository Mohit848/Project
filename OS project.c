#include<stdio.h>

int main()
{
	int q,i,r,avail=0,sum_alloc=0,sum_max=0,sum_need=0,count=0;	//number of resources r and processes q nad available resources avail
	int alloc[100],max[100],need[100]; //allocation,need and max matrix
	printf("Enter the number of processes, then number of resources\n");
	scanf("%d%d",&q,&r);
	printf("Enter maximum resource that each process will need\n");
	for(i=0;i<q;i++)
	{
		printf("Enter number of resources for P%d--",i);
		scanf("%d",&max[i]);
	}
	for(i=0;i<q;i++)
	{
		printf("Enter number of allocated resources for P%d--",i);
		scanf("%d",&alloc[i]);
		//printf("P%d---%d\n",i,max[i]);
	}
	printf("Therefore the need for each process becomes...\n");
	printf("Process\t\tAllocation\tMax\tNeed\n");
	for(i=0;i<q;i++)
	{
		need[i]=max[i]-alloc[i];
		printf("  P%d  \t\t  %d  \t\t  %d  \t  %d  \n",i,alloc[i],max[i],need[i]);
	}
	for(i=0;i<q;i++)
	{
		sum_alloc=sum_alloc+alloc[i];
		sum_max=sum_max+max[i];
	}
	printf("Testing whether system is in safe state or not");
	for(i=0;i<5;i++)
	{
		sleep(1);
		printf(".");	
	}
	if(sum_alloc==r)
	{
		printf("\nSystem is not in safe state as sum of allocated resource=total resourses P\n");
	}
	else if(sum_max<(r+q))
	{	
		for(i=0;i<q;i++)
		{
			if((max[i]>=1) && (max[i]<r))
			{
				count++;	
			}
			
		}
		if(count==q)
		{
			printf("\nSystem is in safe state\n");
		}
		else if(count<q)
	{
		printf("\nSystem is not in safe state as need of each process is not satisfying the conditions\n");
	}
	}
	else
	{
		printf("\nUnsafe state sum of max needs>number of resources\n");
	}
	
	
	
}
