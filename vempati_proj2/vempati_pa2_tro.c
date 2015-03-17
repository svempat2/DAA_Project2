#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int id=0;

void trominoTile(int **a, int xi, int yi, int length, int x, int y);

//Function to print the Tromino's Board to standard output
void printBoard(int **board,int len)
{
    printf("Printing the Board formed by Tromino's : \n");
    int i=0;
    int j=0;

    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            if(board[i][j]==88)
                printf("   %c",'X');
            else
                printf("   %d",board[i][j]);
        }
        printf("\n");
    }
}



//Function to calculate the power of a base
int calcPower(int base,int pow)							
{
	int result = 1;
	int k;
	for(k=1;k<=pow;k++)
	{
		result = result * base;
	}
	return result;
}



int main(int argc, char *argv[]) 
{
    int i,j;
    int len;
	int n;
	int x, y;   
	srand(time(NULL));


    //Validating the number of input arguments
    if(argc<2)
    {
        printf("\nPlease enter the length of the Board\n Please Try Again .....");
        printf("\nUsage : ./tro lengthOfTheBoard\n");
        return 1;
    }

	n = atoi(argv[1]);
	len=calcPower(2,n); 
	
    x=rand()%len;
	y=rand()%len;

    //Allocating memory for the Tromino's Board 
	int **board= malloc(sizeof(int *)*len);     

	for (i=0;i<len;i++)            
	{
		board[i]=malloc(sizeof(char)*len);
	}

	for (i = 0;i<len;i++)            
        for (j = 0; j<len;j++)
            board[i][j] = 0;

    //Indicating the hole in the Tromino's Board with X
	board[x][y]='X';            
	trominoTile(board,0,0,len,x,y);
    printBoard(board,len);

	return 0;
}

//Implementing the Tromino Tile algorithm 
void trominoTile(int** board, int xi, int yi, int length, int x, int y)
{
	int i = length / 2;
	if(i - 1 == 0)
	{
		if((x <= xi + i - 1)&& (y > yi + i - 1))   
        {
           id++; 
           board[xi+i][yi+i-1]=id;
           board[xi+i][yi+i]=id;
		   board[xi+i-1][yi+i-1]=id;
        }
		else if((x <= xi + i - 1 )&& (y <= yi + i - 1))
        {
           id++; 
		   board[xi+i-1][yi+i]=id;
           board[xi+i][yi+i]=id;
           board[xi+i][yi+i-1]=id;
        }
		else if((x > xi + i - 1)&&(y <= yi + i - 1))   
        {
            id++;
			board[xi+i-1][yi+i-1]=id; 
            board[xi+i-1][yi+i]=id;
            board[xi+i][yi+i]=id;;
        }
		else
        {
            id++;
			board[xi+i-1][yi+i-1]=id; 
            board[xi+i-1][yi+i]=id;
            board[xi+i][yi+i-1]=id;
        }
	}
	else
	{
		if((x <= xi + i - 1)&&(y>yi + i - 1))
		{
            id++;
			board[xi+i-1][yi+i-1] =id; 
            board[xi+i][yi+i-1]=id;
            board[xi+i][yi+i]=id;
			trominoTile(board,xi,yi+i,i,x,y);             
			trominoTile(board,xi,yi,i,xi+i-1,yi+i-1);          
			trominoTile(board, xi + i, yi, i, xi + i, yi + i - 1);       
			trominoTile(board, xi + i, yi + i, i, xi + i, yi + i);          
		}
		else if((x <= xi + i - 1)&&(y <= yi + i - 1))
		{
            id++;
			board[xi + i - 1][yi + i]=id; 
            board[xi + i][yi + i]=id;
            board[xi + i][yi + i - 1] =id;
			trominoTile(board, xi, yi + i, i, xi + i - 1, yi + i);         
			trominoTile(board, xi, yi, i, x, y);           
			trominoTile(board, xi + i, yi, i, xi + i, yi + i - 1);         
			trominoTile(board, xi + i, yi + i, i, xi + i, yi + i);            
		}
		else if((x>xi + i - 1)&&(y <= yi + i - 1))
		{
            id++;
			board[xi + i - 1][yi + i - 1]=id; 
            board[xi + i - 1][yi + i]=id;
            board[xi + i][yi + i]=id;
			trominoTile(board, xi, yi + i, i, xi + i - 1, yi + i);         
			trominoTile(board, xi, yi, i, xi + i - 1, yi + i - 1);        
			trominoTile(board, xi + i, yi, i, x, y);         
			trominoTile(board, xi + i, yi + i, i, xi + i, yi + i);          
		}
		else
		{
            id++;
			board[xi + i - 1][yi + i - 1]=id;
            board[xi + i - 1][yi + i]=id; 
            board[xi + i][yi + i - 1]=id;
			trominoTile(board, xi, yi + i, i, xi + i - 1, yi + i);         
			trominoTile(board, xi, yi, i, xi + i - 1, yi + i - 1);       
			trominoTile(board, xi + i, yi, i, xi + i, yi + i - 1);         
			trominoTile(board, xi + i, yi + i, i, x, y);            
		}
	}
}


