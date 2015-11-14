/* Author : Dhaval Lad */
#include "header.h"

void main()
{
	// double sum = 0;
	// inintilizillig the matrics
	int i,j,k;
	GetArray();
	outputMatrix = getMemory(ArraySize);
	start();
	for (i=0; i<ArraySize; i++)	{
		for (j=0; j<ArraySize; j++)
		{
			outputMatrix[i][j]=0;
			// sum = 0;
			for (k=0;k<ArraySize;k++)
			{
				outputMatrix[i][j] += inputMatrix[i][k]*inputMatrix[k][j];
			}
			// printf("OutputMatrix[%d][%d] %f \n",i,j,outputMatrix[i][j]);
		}	
	}
	stop();
	write_output("serial_output.csv");
	free(outputMatrix);
	free(inputMatrix);
}
