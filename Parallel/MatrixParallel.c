/* Author : Dhaval Lad */
#include "header.h"
#include <omp.h>

void main()
{
	// inintilizillig the matrics
	int i,j,k,tid;
	double sum = 0;
	GetArray();
	inputMatrix_T = getMemory(ArraySize);
	outputMatrix = getMemory(ArraySize);
	
	/* Loop for the generate transpose of matrix */
	#pragma omp parallel for num_threads(NUM_THREADS) shared(inputMatrix,inputMatrix_T) private(i,j)
	for(i=0;i<ArraySize;i++) { 
		for(j=0;j<ArraySize;j++){ 
			inputMatrix_T[i][j] = inputMatrix[j][i]; 
		} 
	}
	
	/* Timer Start */
	start();
	/* Matrix Multipication loop */
	#pragma omp parallel for num_threads(NUM_THREADS) \
	shared(inputMatrix,inputMatrix_T,outputMatrix,ArraySize) \
	private(i,j,k) reduction(+:sum)
	for (i=0;i<ArraySize;i++)	{
		for (j=0;j<ArraySize;j++)
		{
			//#pragma omp parallel private(i) num_threads(4)
			sum = 0; // outputMatrix[i][j]=0;
			for (k=0;k<ArraySize;k++)
			{
				sum += inputMatrix[i][k]*inputMatrix_T[j][k];
			}
			outputMatrix[i][j] = sum;
			//printf("outputMatrix[%d][%d] %d \n",i,j,outputMatrix[i][j]);
		}
	}
	/* Timer Stop */
	stop();
	write_output("parallel_output.csv");
	free(outputMatrix);
	free(inputMatrix);
	free(inputMatrix_T);
}
