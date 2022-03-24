#include <cmath>
#include <ctime>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <omp.h>
#include <time.h>

using namespace std;

#define MAX_SIZE 10000
#define MY_NUM_OF_THREADS 8

int A[MAX_SIZE][MAX_SIZE];
int length = 0;

void init()
{
	for (int i = 1; i < length; i++)
	{
		for(int j = 1; j < length; j++)
		{
			A[i][j] = rand()%10;
		}
	}
}

double addRow_method1()
{
	int i = 0;
	clock_t start, end;
	start = clock();
#pragma omp parallel for num_threads(MY_NUM_OF_THREADS) private
	 
#pragma omp barrier
	end = clock();

	return (end - start) * 1.0 / CLOCKS_PER_SEC;
}

double addRow_method2()
{

}

int main()
{

}
