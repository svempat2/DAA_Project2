#include<stdio.h>
#include<stdlib.h>
#include<time.h>




//Function to validate the size of the matrix

int validateMatSize(int matSize)
{
    int size=matSize;

    while(size>1)
    {
        //printf("\n valida  %d",size);
        if(size%2!=0)
            return 0;

        size=size/2;
    }

    return 1;
}

//generating random values into the matrix
int** generateMat(int matSize)
{
    int i,j;
    int **mat=malloc(sizeof(int *)*matSize);

    for(i=0;i<matSize;i++)
        mat[i]=malloc(sizeof(int)*matSize);

    for(i=0;i<matSize;i++)
        for(j=0;j<matSize;j++)
            mat[i][j]=0;

    for(i=0;i<matSize;i++)
        for(j=0;j<matSize;j++)
            mat[i][j]=(rand()%10);

    return mat;
}


//Function to display the matrix 
void displayMat(int **mat,int size)
{

    int i,j;

    for(i=0;i<size;i++)
    {
        printf("\n");

        for(j=0;j<size;j++)
            printf(" %d",mat[i][j]);
    }
        printf("\n");
        printf("\n");
}



//Function to add two matrixes of same size
int** matAdd(int **matA,int **matB,int size)
{
    int i;
    int j;
    int **tmp=malloc(sizeof(int *)*size);


    for(i=0;i<size;i++)
        tmp[i]=malloc(sizeof(int)*size);

    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            tmp[i][j]=0;

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            tmp[i][j]=matA[i][j]+matB[i][j];
        }
    }

    return tmp;
}




//Function to subtract two matrices of same size

int** matSub(int **matA,int **matB,int size)
{
    int i;
    int j;
    int **tmp=malloc(sizeof(int *)*size);


    for(i=0;i<size;i++)
        tmp[i]=malloc(sizeof(int)*size);

    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            tmp[i][j]=0;

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            tmp[i][j]=matA[i][j]-matB[i][j];
        }
    }

    return tmp;
}



//This is the function to multiply two matrices of same size 
//Time Compexity for this is O of n cube
int** normalMatMul(int **matA,int **matB,int size)
{
    int i,j,k;

    int **tmp=malloc(sizeof(int *)*size);
    

    for(i=0;i<size;i++)
        tmp[i]=malloc(sizeof(int)*size);


    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            tmp[i][j]=0;

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            for(k=0;k<size;k++)
            {
                tmp[i][j]+=matA[i][k]*matB[k][j];
            }
        }
    }

    return tmp;
}




//This function divides the given matrix into the required sizes
int** matDiv(int **mat,int rS,int rE,int cS,int cE)
{
    int i,j,row,col;

    int size=(rE-rS)+1;

    int **tmp=(int **)malloc(sizeof(int *)*size);

    for(i=0;i<size;i++)
        tmp[i]=malloc(sizeof(int)*size);


    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            tmp[i][j]=0;

    row=0;col=0;

    for(i=rS;i<=rE;i++)
    {
        col=0;
        for(j=cS;j<=cE;j++)
        {
            tmp[row][col]=mat[i][j];
            col++;
        }
        row++;
    }


    return tmp;
}



//This matrix combines two matrices into one 
void matComb(int **matA,int **matC,int rS,int cS,int size)
{

    int row,col,tmpCol;
    row=0;
    col=0;
    tmpCol=cS;

    while(row<size)
    {
        col=0;
        cS=tmpCol;
        while(col<size)
        {
            matC[rS][cS]=matA[row][col];
            col++;
            cS++;
        }
        row++;
        rS++;
    }


}




//Function to maultiply two matrices using strassen's algorithm
int** straMatMul(int** matA,int** matB,int size)
{
    int **M1,**M2,**M3,**M4,**M5,**M6,**M7;

    int **A11,**A12,**A21,**A22;
    int **B11,**B12,**B21,**B22;

    int **C11,**C12,**C21,**C22;

    int i,j;

    if(size<=1)
    {

        int** result=malloc(sizeof(int*)*size);

        for(i=0;i<size;i++)
            result[i]=malloc(sizeof(int)*size);


        result[0][0]=0;
        result[0][0]=matA[0][0] * matB[0][0];

        //printf("\nAfter multipling :\n");
        //displayMat(result,size);

        return result;
    }
    else
    {
        size=size/2;

        //Dividing the matrixA into four parts

        A11=matDiv(matA,0,size-1,0,size-1);
        A12=matDiv(matA,0,size-1,size,(size*2)-1);
        A21=matDiv(matA,size,(size*2)-1,0,size-1);
        A22=matDiv(matA,size,(size*2)-1,size,(size*2)-1);


        //Divivding the matrix B into four parts
        B11=matDiv(matB,0,size-1,0,size-1);
        B12=matDiv(matB,0,size-1,size,(size*2)-1);
        B21=matDiv(matB,size,(size*2)-1,0,size-1);
        B22=matDiv(matB,size,(size*2)-1,size,(size*2)-1);


        //int **P11=matAdd(A11,A22,size);
        //int **P22=matAdd(B11,B22,size);
        
        //Seven calculations to perform the matrix multiplication 

        M1=straMatMul(matAdd(A11,A22,size),matAdd(B11,B22,size),size);
        M2=straMatMul(matAdd(A21,A22,size),B11,size);
        M3=straMatMul(A11,matSub(B12,B22,size),size);
        M4=straMatMul(A22,matSub(B21,B11,size),size);
        M5=straMatMul(matAdd(A11,A12,size),B22,size);
        M6=straMatMul(matSub(A21,A11,size),matAdd(B11,B12,size),size);
        M7=straMatMul(matSub(A12,A22,size),matAdd(B21,B22,size),size);

        C11 = matSub(matAdd(matAdd(M1,M4,size),M7,size),M5,size);
        C12 = matAdd(M3,M5,size);
        C21 = matAdd(M2,M4,size);
        C22 = matSub(matAdd(matAdd(M1,M3,size),M6,size),M2,size);

        int** resultMat=malloc(sizeof(int *)*size*2);

        for(i=0;i<(size*2);i++)
            resultMat[i]=malloc(sizeof(int)*size*2);

        for(i=0;i<(size*2);i++)
            for(j=0;j<(size*2);j++)
                resultMat[i][j]=0;

        //Combining the individual matrix into one 
        matComb(C11,resultMat,0,0,size);
        matComb(C12,resultMat,0,size,size);
        matComb(C21,resultMat,size,0,size);
        matComb(C22,resultMat,size,size,size);

        return resultMat;
    }
}




int main(int argc,char *argv[])
{

    int matSize;
    int **matA;
    int **matB;

    //printf("\nFile name: %s",argv[0]);
    //printf("\nFile name: %s",argv[1]);
    

    //Validation to check the number of input arguments

    if(argc<2)
    {
        printf("\nYou have not entered the size of the matrix.\n Please Try Again .....");
        printf("\nUsage : ./stra sizeOfMatrix \n");
        return 1;
    }
    
    //srand function to seed the rand function 
    srand(time(NULL));

    matSize=atoi(argv[1]);

    //Validating the matrix size
    if(!validateMatSize(matSize))
    {
        printf("\nThe size of the Matrix you have entered is wrong.");
        printf("\nSize of the matrix should be power of 2 . ");
        printf("\nTry again \n");
        return 1;
    }


    matA=generateMat(matSize);
    printf("\nDisplaying Matrix A:\n\n");

    displayMat(matA,matSize);

    matB=generateMat(matSize);
    printf("\nDisplaying Matrix B:\n\n");

    displayMat(matB,matSize);

    /*
    int **tmp=matAdd(matA,matB,matSize);

    printf("\nAdding the above 2 matrices :\n");

    displayMat(tmp,matSize);
    
    int **tmp2=matSub(matA,matB,matSize);

    printf("\nSubtracting the above 2 matrices :\n");

    displayMat(tmp2,matSize);
    */

    int **tmp3=normalMatMul(matA,matB,matSize);

    printf("\nNormal Multiply : Multiplying the above 2 matrices :\n");

    displayMat(tmp3,matSize);


    /*
    int **tmp4=matDiv(matA,matSize/2,matSize-1,matSize/2,matSize-1);

    printf("\ndisplaying the matrix after divding, showing the 4th part:\n");

    displayMat(tmp4,matSize/2);
    */

    int **matC=straMatMul(matA,matB,matSize);

    printf("\nStrasan's Matrix Multiplying the above 2 matrices :\n");

    displayMat(matC,matSize);





    return 0;

}


