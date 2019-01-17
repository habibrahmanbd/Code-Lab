#include<stdio.h>
#define n 8

int isSafe(int board[n][n], int row, int col)
{
	int i, j;
	for(i=0; i<col; i++)
		if(board[row][i]==1)
			return 0;

	for(i=row, j=col; i>=0 && j>=0; i--, j--)
		if(board[i][j]==1)
			return 0;
	
	for(i=row, j=col; j>=0 && i<n; i++, j--)
		if(board[i][j]==1)
			return 0;
	
	return 1;
}

int NQCheck(int board[n][n], int col)
{
	if(col>=n){
		int  j,k;

		for(k=0; k<n; k++){
			for(j=0; j<n; j++){
				printf(" %d ", board[k][j]);
			}
			printf("\n");
		}

		return 1;
	}
	int i;
	for(i=0; i<n; i++)
	{
		if(isSafe(board, i, col)==1)
		{
			board[i][col]=1;
			if(NQCheck(board, col+1)==1)
				return 1;
			board[i][col]=0;
		}
	}
	return 0;
}

int main()
{
	int board[8][8] = {{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0}};
	if(NQCheck(board, 0)==1){
		printf("Solution Exists\n");
	}
	else
		printf("No Solution\n");
	return 0;
}