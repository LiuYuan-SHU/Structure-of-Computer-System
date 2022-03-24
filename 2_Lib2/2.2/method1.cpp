#include <cstdio>  
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <fstream>
#include <omp.h>

#define MAX_SIZE 10000

using namespace std;

int A[MAX_SIZE][MAX_SIZE];
int B[MAX_SIZE][MAX_SIZE];

int main(int argc, char** argv)
{
	unsigned long int N;
	string filename;
	if(argc >= 2)
	{
		N = atoi(argv[1]);
		if(N > MAX_SIZE)
		{
			N = MAX_SIZE;
		}
	}
	else
	{
		N = 1000;
	}

	if(argc >= 3)
	{
		filename = string(argv[2]);
	}

	// debug
	// cout << "N: " << N << endl;
	// cout << "N*N: " << N * N << endl;

    clock_t start, end;
    int i, j;
    // 随机初始化矩阵A
    for (i =0; i < N; i++){
        for (j = 0; j < N; j++){
            A[i][j] = rand()%10;
        }
    }

    int col, row;
    start = clock();
// 方法一
#pragma omp parallel for num_threads(4) private(i, col, row)
    for (i = 0; i < N*N; i++){
        col = i/N;
        row = i%N;

        if (col > 0 && col < N && row > 0 && row < N){
            B[col][row] = (A[col-1][row]
                + A[col+1][row]
                + A[col][row-1]
                + A[col][row+1])/4;
        } else {
            B[col][row] = 0;
        }
    }
#pragma omp barrier
    end = clock();

	// debug
	// cout << "start" << (start * 1.0 / CLOCKS_PER_SEC) << endl;
	// cout << "end" << (end * 1.0 / CLOCKS_PER_SEC) << endl;
    
    // Output result
	/*
    for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
		    printf("%d ", B[i][j]);
		printf("\n");
    }
	*/
    float elaps_time = (end-start)*1.0/CLOCKS_PER_SEC;
	if (filename.size() == 0)
	{
		printf("Elapsed time: %f (s)\n", elaps_time);
	}
	else
	{
		ofstream out(filename,ofstream::app);
		out << N << '\t' << elaps_time << endl;
		out.close();
	}

    return 0;
} 
