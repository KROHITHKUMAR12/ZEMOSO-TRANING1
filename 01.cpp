#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Item 
{ 
	int weight; 
	int value; 
}Item; 
typedef struct Node 
{
	int level, profit, bound;
	int weight;
}Node;
Node queue[1000];
int front=0,rear=0;
void enqueue(Node u){
	queue[rear++] = u;
}
void dequeue(){
	front++;
}
bool empty(){
	return front==rear;
}
bool cmp(Item a, Item b) 
{ 
	double r1 = (double)a.value / a.weight; 
	double r2 = (double)b.value / b.weight; 
	return r1 > r2; 
} 
int bound(Node u, int n, int W, Item arr[]) 
{ 
	if (u.weight >= W) 
		return 0;  
	int profit_bound = u.profit;
	int j = u.level + 1; 
	int total_weight = u.weight;
	while ((j < n) && (total_weight + arr[j].weight <= W)) 
	{ 
		total_weight += arr[j].weight; 
		profit_bound += arr[j].value; 
		j++; 
	} 
	if (j < n)
		profit_bound += (W - total_weight) * arr[j].value/arr[j].weight; 
	return profit_bound; 
} 

int knapsack(int W, Item arr[], int n) 
{
	qsort(arr,n,sizeof(arr[0]),cmp);
	Node u, v;
	u.level = -1; 
	u.profit = u.weight = 0;  
	enqueue(u);
	int maxProfit = 0; 
	while (!empty()) 
	{ 
		u = queue[front];
		dequeue();
		if (u.level == -1) 
			v.level = 0;  
		if (u.level == n-1) 
			continue;
		v.level = u.level + 1;
		v.weight = u.weight + arr[v.level].weight;
		v.profit = u.profit + arr[v.level].value;
		if (v.weight <= W && v.profit > maxProfit){
			printf("%d ",v.profit-maxProfit); maxProfit = v.profit;}
		v.bound = bound(v, n, W, arr);
		if (v.bound > maxProfit)
			enqueue(v);
		v.weight = u.weight;
		v.profit = u.profit; 
		v.bound = bound(v, n, W, arr); 
		if (v.bound > maxProfit) 
			enqueue(v);
	} 
	return maxProfit; 
} 
int main() 
{
    int i,n,W;
    printf("enter the no of weights");
    scanf("%d",&n);
    Item arr[n];
    printf("enter the weights and values\n");
    for(i=0;i<n;i++)
        scanf("%d%d",&arr[i].weight,&arr[i].value);
    printf("enter the Knapsack capacity");
    scanf("%d",&W);
	printf("selected weights are ");
	printf("\nProfit is %d",knapsack(W, arr, n)); 
	return 0; 
}
