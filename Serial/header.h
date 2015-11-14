#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE(x)  (sizeof(x)/sizeof(*(x))) // To find Array size
#define NUM_THREADS 6 // Numbers of threads


// Global Variables
float **inputMatrix;
float **inputMatrix_T; // Transpose Matrix
float **outputMatrix;
int ArraySize;
struct timeval tm1, tm2;

//All functions
float **getMemory(int size); //Allocate memory
void GetArray(); // Read Data from file and save to inputMatrix
void write_output(char a[]); // Write Matrix Multiplication on csv file 
extern void start();
extern void stop();
