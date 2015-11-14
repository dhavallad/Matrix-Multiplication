/* Author : Dhaval Lad */
#include "header.h"

/* Allocate memory to the array */
float **getMemory(int size){
	int i;
	float **temp;
	temp = malloc(size*sizeof(float*));
	for(i = 0 ; i < size ; i++)
	temp[i] = malloc(size*sizeof(float) );
	// if (!temp)
	// printf("malloc allocation failed");
	return temp;
}

/* Function to get array from the file */
void GetArray(){
	const char filename[] = "inputMatrix.csv";
	int lineCount = 0;
	int i, j, k;
	char buffer[BUFSIZ], *ptr;
	FILE *file = fopen(filename, "r");
	if ( file ){
		for ( i = 0; fgets(buffer, sizeof buffer, file); ++i )
		{
			if(lineCount == 0){ // When line 1 will read.
				/* Store first value as inputMatrix size. */
				ArraySize = atol(buffer);
				/* Dynmically allocated memmory to inputMatrix */
				inputMatrix = getMemory(ArraySize);
				// double **arr = (double **)malloc(size * sizeof(double *) + (size * size * sizeof(double)));
			}
			else{
				/* Parse the comma-separated values from each line into 'array' */
				for ( j = 0, ptr = buffer; j < ArraySize; ++j, ++ptr )
				{
					// inputMatrix[i-1][j] = 0;
					inputMatrix[i-1][j] = strtof(ptr,&ptr);
					// inputMatrix[i-1][j] = atof(ptr);
				}
			}	
			lineCount++;
		}
		fclose(file);
		/* Print the data in 'array' */
		/* for ( j = 0; j < i-1; ++j )
		{
		printf("Row[%lu]: ", (long unsigned)j);
		for ( k = 0; k < ArraySize; ++k )
		{
		printf("\ninputMatrix[%d][%d] %f ",j,k,inputMatrix[j][k]);
		}
		putchar('\n');
		} */
	}
	else 
	{
		//
		perror(filename);
	}
	// free(inputMatrix);
}


/* Function to start timer. */
void start()
{
	gettimeofday(&tm1, NULL);
}

/* Function to stop timer. */
void stop(){
	gettimeofday(&tm2, NULL);
	unsigned long long t = ((tm2.tv_sec - tm1.tv_sec) * 1000000)
	+ (tm2.tv_usec - tm1.tv_usec);
	printf("\nExecution Time : %llu microseconds\n",t);
}

void write_output(char a[]){
	int i,j;
	FILE *out = fopen(a,"w");
	fprintf(out,"%d\n",ArraySize);
	for(i=0;i<ArraySize;i++)
	{
		for(j=0;j<ArraySize;j++)
		{
			j==ArraySize-1 ? fprintf(out, "%f",outputMatrix[i][j]) :  fprintf(out, "%f,",outputMatrix[i][j]);
		}
		fprintf(out, "\n");
	}
	fclose(out);
	printf("Please check output file : %s\n",a);
}

