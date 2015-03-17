/*
 * Program Implemeting the Floyd's Algorithm by reading the input from the 
 * file and printing the shortest paths
 */


#include <stdio.h>
#include <stdlib.h>



//pathPrint function used to print the path
void pathPrint(int **p,int q, int r)
{
     if(p[q][r] != 0)
     {
         pathPrint(p, q, p[q][r]);
         printf("%d -> ", p[q][r]+1);
         pathPrint(p, p[q][r], r);
     }
}


//Function implementing the floyd algorithm
void floyd(int **w,int **p,int v)
{
    int k,i,j;

     for(k = 0; k < v; k++)
     {
         for(i = 0; i < v; i++)
         {
             for(j = 0; j < v; j++)
             {
                 if(w[i][j] > w[i][k] + w[k][j])
                 {
                     w[i][j] = w[i][k] + w[k][j];
                     p[i][j] = k;
                 }
             }
         }
     }
}


int main(int argc, char** argv)
{
     FILE *fp;
     int v, i, j;
     
    /*Scanning of the graph into the matrix w */

     fp=fopen(argv[1], "r");
        
     if(fp==NULL)
     {
         printf("Can't read file\n");
         exit(-1);
     }
     
     fscanf(fp, "%d", &v);
     
     int **w=malloc(sizeof(int*)*v);
     
     for(i = 0;i < v;i++)
     {
         w[i]=malloc(sizeof(int)*v);
     }

     //intitalising the array pointer w
     for(i = 0; i < v; i++)
     {
         for(j = 0; j < v; j++)
         {
             w[i][j] = 0;
         }
     }

           
     for(i = 0; i < v; i++)
     {
         for(j = 0; j < v; j++)
         {
             fscanf(fp, "%d", &w[i][j]);
         }
     }
            
     fclose(fp);

     /*Scanning of the graph into the mtrix*/
     
     int **p=malloc(sizeof(int*) * v);
     
     for(i = 0;i < v;i++)
     {
         p[i]=malloc(sizeof(int)*v);
     }

     //initialising the p
     for(i = 0; i < v; i++)
     {
         for(j = 0; j < v; j++)
         {
             p[i][j] = 0;
         }
     }


     //Calling the floyd algorithm to find the shortest paths between edges
    floyd(w,p,v);

    //Printing the reordered weighted graph

    printf("\n \nThe Weigthed Graph after finding the shortest path \n");

     for(i = 0; i < v; i++)
     {
         for(j = 0; j < v; j++)
         {
             printf("%d ", w[i][j]);
         }
         printf("\n");
     }


     printf("\n\nThe shortest paths are as follows: \n\n");
     for(i = 0; i < v; i++)
     {
         for(j = 0; j < v; j++)
         {
             if(i != j && w[i][j] < 500)
             {
                 printf("%d -> ", i+1);
                 pathPrint(p, i, j);
                 printf(" %d", j+1);
             }
             printf("\n");
         }
         printf("\n");
     }


     //Freeing the memory of matrix p
     for(i = 0; i < v; i++)
         free(p[i]);

     free(p);
    
    //Freeing the memory of w 
     for(i = 0; i < v; i++)
         free(w[i]);

     free(w);
     return 0;
}

