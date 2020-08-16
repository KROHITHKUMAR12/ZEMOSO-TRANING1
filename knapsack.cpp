#include<stdio.h>
#define maxsize 10
int total_items;
float total_weight,profit[maxsize],weight[maxsize];
struct node
{
	int flag,id;
	float ub,cost;
};
void get_input()
{
	int i;
	printf("enter total no of items");
	scanf("%d",&total_items);
	printf("enter the profit");
	for(i=1;i<=total_items;i++)
	     scanf("%f",&profit[i]);
	printf("enter the weights");
	     scanf("%f",&weight[i]);
	printf("napsack weight");
	     scanf("%f",&total_weight);
	     
}
void  sort_input()
{
	float ratio[total_items];
	int i,j,temp;
	for(i=1;i<=total_items;i++)
	ratio[i]=profit[i]/weight[i];
	for(i=1;i<=total_items;i++)
	{
		for(j=i+1;j<=total_items;j++)
        {
        	if(ratio[j]>ratio[j-1])
        	{
        		temp=profit[j];
				profit[j]=profit[j-1];
				profit[j-1]=temp;
				temp=ratio[j];
				ratio[j]=ratio[j-1];
				ratio[j-1]=temp;
				temp=weight[j];
				weight[j]=weight[j-1];
				weight[j-1]=temp;	
			}
		}
	}
	printf("input is");
	printf("item \n profit\nweight\nratio\n");
	for(i=1;i<=total_items;i++)
	printf("%d\t%f\t%f\t%f\t",i,profit[i],weight[i],ratio[i]);
}

