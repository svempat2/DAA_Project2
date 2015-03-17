
/*
 * Program implementing the lcs algorithm to find the larest 
 * common subsequence between two strings
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>



void LCS(int a,int b);

int LengthLCS(char *L1,char*L2,int len1,int len2,int lenMax);

//Global input Strings
char *inp1,*inp2;                                
char **arrL,**sarray;


int main(int argc,char* argv[])		
{
	int inpLen1,inpLen2,lengthOfLCS;
	int lenMax;
  
    //Validation for input arguments 

    if(argc<3)
    {
        printf("\nYou have not entered two input Strings \n Please Try Again .....");
        printf("\nUsage : ./lcs string1 string2\n");
        return 1;
    }


	inp1 = argv[1];             
	inp2 = argv[2];


    //Calculating the length of the two strings
	inpLen1=strlen(inp1);                                    
	inpLen2=strlen(inp2);

	lenMax =inpLen1>inpLen2?inpLen1:inpLen2;
	
    printf("Given String1 ---->  %s \n",inp1);
	printf("Given String2 ---->  %s \n",inp2);

	printf("Lenth of first input string  : %d\n",inpLen1);
	printf("Length of second input string : %d\n",inpLen2);
	lengthOfLCS = LengthLCS(inp1,inp2,inpLen1,inpLen2,lenMax);      
	printf("\n\n Length of the Longest Common Subsequence(LCS) is :%d\n",lengthOfLCS);
	return 0;
}


void LCS(int a,int b)                 
{
	 if((a==0)||(b==0))                       
     {
		 return;
	 }
	 if(sarray[a][b]=='A')                   
	 {
		 LCS(a-1,b-1);
		 printf("%c",inp1[a-1]);
	 }
	 else if(sarray[a][b]=='X')             
	 {
		 LCS(a-1,b);
	 }
	 else                                  
	 {
		 LCS(a,b-1);
	 }
}


//Implementing the LCS algorithm
int LengthLCS(char *L1,char *L2,int len1,int len2,int lenMax)
{
	int i,j,b;
	arrL = (char **)malloc((len1+1)*sizeof(char *));         
	for(b=0;b<(len1+1);b++)
	{
		arrL[b] = (char *)malloc((len2+1)*sizeof(char));
	}
	sarray = (char **)malloc((len1+1)*sizeof(char *));        
	for(b=0;b<(len1+1);b++)
	{
		sarray[b] = (char *)malloc((len2+1)*sizeof(char));
	}
	for(i=0;i<len1;i++)                                    
	{
		arrL[i][0] = 0;
		sarray[i][0] = 'X';                               
	}
	for(j=0;j<len2;j++)                                 
	{
		arrL[0][j] = 0;
		sarray[0][j] = 'Y';                            
	}
	for(i=0;i<=len1;i++)
	{
		for(j=0;j<=len2;j++)
		{
			 if (j==0||i==0)
			 {
				arrL[i][j] = 0;
			 }
             else if (L1[i-1] == L2[j-1])                        
			 {
				arrL[i][j] = arrL[i-1][j-1] + 1;
				sarray[i][j]='A';                             
			 }
			 else if(arrL[i-1][j] >= arrL[i][j-1])         
			 {
				arrL[i][j]=arrL[i-1][j];
				sarray[i][j]='X';                        
			 }
			 else
			 {
				arrL[i][j]=arrL[i][j-1];
				sarray[i][j]='Y';                       
			 }
		}
	}
	printf("Longest common sub-sequence is :");
	LCS(len1,len2);                         
	return arrL[len1][len2];
}

