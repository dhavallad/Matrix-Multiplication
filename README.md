# Matrix-Multiplication

Here I have implmented Matrix Multiplication using OpenMP library. Here you will find serial and parallel implentation. Matrix is read from text file(csv) and resultant matrix is stored in output csv file. With help of OpenMP library we can get more speedup than normal serial and parallel program.

# How you can test the programs
I have create C file in both folder. Now just compile program with gcc.
gcc -g GetArray.c MatrixParallel.c -o parallel -fopenmp
gcc -g GetArray.c MatrixSerial.c -o serial
then run file - ./parallel and ./serial
