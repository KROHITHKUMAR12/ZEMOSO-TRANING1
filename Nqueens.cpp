#include <stdio.h>

int n,board[100][100];

int is_attack(int i,int j)
{
    int k,l;
    for(k=0;k<n;k++)
        if((board[i][k] == 1) || (board[k][j] == 1))
            return 1;
    for(k=0;k<n;k++)
    {
        for(l=0;l<n;l++)
        {
            if(((k+l) == (i+j)) || ((k-l) == (i-j)))
            {
                if(board[k][l] == 1)
                    return 1;
            }
        }
    }
    return 0;
}

int N_queen(int q)
{
    int i,j;
    if(q==0)
        return 1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((!is_attack(i,j)) && (board[i][j]!=1))
            {
                board[i][j] = 1;
                if(N_queen(q-1)==1)
                    return 1;
                board[i][j] = 0;
            }
        }
    }
    return 0;
}

int main()
{
    printf("Enter the number of Queens\n");
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            board[i][j]=0;
    N_queen(n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        		printf("%d\t",board[i][j]);
        printf("\n");
    }
	return 0;
}
